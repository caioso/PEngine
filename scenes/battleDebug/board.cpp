#include "board.hpp"

Board::Board (RulesInterface * _rules, Dim2D dim, Point2D pos, Point2D cur_pos, int initial_height) :
                                        _dimensions(dim),
                                        _position(pos),
                                        _cursorPosition(cur_pos)
{
    this->_rules = _rules;
    
    _boardContainer = new Sprite();
    _boardContainer->_x = (int)_position.getX();
    _boardContainer->_y = (int)_position.getY();
    
    _tmpContainer = new Sprite();
    _tmpContainer->_x = 0;
    _tmpContainer->_y = (32+1)*12;
    
    _boardGraphics = new Panel ** [dim.getHeight()];
    _tmpGraphics = new Panel * [dim.getWidth()];
    _boardLogic = new LogicPanel ** [dim.getHeight()];
    _tmpLogic = new LogicPanel * [dim.getWidth()];
    for (unsigned int i = 0; i < dim.getHeight(); i++)
    {
        _boardGraphics[i] = new Panel * [dim.getWidth()];
        _boardLogic[i] = new LogicPanel * [dim.getWidth()];
    }

    for (unsigned int i = 0; i < dim.getWidth(); i++)
    {
        char __random_type = rand()%5;
        _tmpGraphics[i] = new Panel(decodeType(__random_type), 32, 32);
        _tmpLogic[i] = new LogicPanel();
        _tmpLogic[i]->_type = __random_type;
        _tmpGraphics[i]->_x = (32+1)*i;
        _tmpContainer->AddChild(_tmpGraphics[i]);
    }
    
    for (unsigned int i = 0; i < dim.getHeight(); i++)
        for (unsigned int j = 0; j < dim.getWidth(); j++)
        {
            char __random_type = rand()%5;
            _boardLogic[i][j] = new LogicPanel();
            _boardLogic[i][j]->_type = (int)__random_type;
            _boardLogic[i][j]->_state = 0;
            _boardLogic[i][j]->_wait = 0;
          
            _boardGraphics[i][j] = new Panel (decodeType(_boardLogic[i][j]->_type), 32, 32);
            _boardGraphics[i][j]->_x = (32+1)*j;
            _boardGraphics[i][j]->_y = (32+1)*i;
            _boardContainer->AddChild(_boardGraphics[i][j]);
            
            if (i <= (unsigned int)initial_height)
            {
                _boardLogic[i][j]->_type = -1;
                _boardGraphics[i][j]->_visibility = hidden;
            }
    
        }
    _cursor = new Cursor(cursor, 65, 32);
    _cursor->_x = _cursorPosition.getX()*33 + 16;
    _cursor->_y = _cursorPosition.getY()*33;
    _boardContainer->AddChild(_cursor);
    _boardContainer->AddChild(_tmpContainer);

    GraphicEngine::_stage->AddChild(_boardContainer);
}

void Board::UpdateCursorPosition (Point2D pos)
{
    if (pos.getX() < 0 || pos.getX() >= _dimensions.getWidth() - 1)
        return;
    if (pos.getY() < 0 || pos.getY() >= _dimensions.getHeight())
        return;

    _cursorPosition = pos;
    _cursor->_x = _cursorPosition.getX()*33 + 16;
    _cursor->_y = _cursorPosition.getY()*33;
}

void Board::Swap ()
{
    _rules->Swap(_boardLogic, _dimensions.getWidth(), _dimensions.getHeight(), _changes, &_cursorPosition);
}

void Board::BindLogic ()
{
    // For each change in change array, commit it by removing from the list.
    for (size_t i = 0; i < _changes.size(); i++)
    {
        unsigned int __type = ExtractOperation(_changes[i]);
        unsigned int __targetX = ExtractTargetPanelX(_changes[i]);
        unsigned int __targetY = ExtractTargetPanelY(_changes[i]);
        unsigned int __destinationX = ExtractDestinationPanelX(_changes[i]);
        unsigned int __destinationY = ExtractDestinationPanelY(_changes[i]);
        int __targetType = _boardLogic[__targetY][__targetX]->_type;
        int __destinationType = _boardLogic[__destinationY][__destinationX]->_type;
        int __targetState = _boardLogic[__targetY][__targetX]->_state;
        int __targetWait = _boardLogic[__targetY][__targetX]->_wait;
        
        // Remember to change the panel index to row and column.
        switch (__type)
        {
            case SWAP_OPERATION:
                if (__destinationType != -1)
                {
                    _boardGraphics[__targetY][__targetX]->SetAsset(decodeType(__destinationType), 32, 32);
                }
                if (__targetType != -1)
                {
                    _boardGraphics[__destinationY][__destinationX]->SetAsset(decodeType(__targetType), 32, 32);
                }
                //BlockAbove(__targetX, __targetY);
                //BlockAbove(__destinationX, __destinationY);
                _boardLogic[__targetY][__targetX]->_type = __destinationType;
                _boardLogic[__destinationY][__destinationX]->_type = __targetType;
                if (__targetType == -1)
                    _boardGraphics[__destinationY][__destinationX]->_visibility = hidden;
                else
                    _boardGraphics[__destinationY][__destinationX]->_visibility = visible;
                
                if (__destinationType == -1)
                    _boardGraphics[__targetY][__targetX]->_visibility = hidden;
                else
                    _boardGraphics[__targetY][__targetX]->_visibility = visible;
                
                _boardLogic[__targetY][__targetX]->_state = _boardLogic[__destinationY][__destinationX]->_state;
                _boardLogic[__destinationY][__destinationX]->_state = __targetState;
                _boardLogic[__targetY][__targetX]->_wait = _boardLogic[__destinationY][__destinationX]->_wait;
                _boardLogic[__destinationY][__destinationX]->_wait = __targetWait;
                break;
            case DESTROY_OPERATION:
                _boardGraphics[__targetY][__targetX]->_visibility = hidden;
                _boardLogic[__targetY][__targetX]->_type = -1;
                _boardLogic[__targetY][__targetX]->_state = 0;
                _boardLogic[__targetY][__targetX]->_wait = 0;
                //BlockAbove(__targetX, __targetY);
                break;
            case FALL_OPERATION:
                _boardGraphics[__targetY + 1][__targetX]->_visibility = visible;
                _boardLogic[__targetY + 1][__targetX]->_type = __targetType;
                _boardGraphics[__targetY + 1][__targetX]->SetAsset(decodeType(__targetType), 32, 32);
                _boardGraphics[__targetY][__targetX]->_visibility = hidden;
                _boardLogic[__targetY][__targetX]->_type = -1;
                _boardLogic[__targetY][__targetX]->_state = 0;
                _boardLogic[__targetY + 1][__targetX]->_state = 1;
                break;
            case LIGHT_IMAGE:
                 _boardGraphics[__targetY][__targetX]->SetAsset(decodeLightType(__targetType), 32, 32);
                break;
            case NORMAL_IMAGE:
                _boardGraphics[__targetY][__targetX]->SetAsset(decodeType(__targetType), 32, 32);
                break;
            case TRANSPORT_OPERATION:
                for (unsigned int k = 0; k < _dimensions.getWidth(); k++)
                {
                    for (unsigned int j = 0; j < _dimensions.getHeight() - 1; j++)
                    {
                        _boardLogic[j][k]->_type = _boardLogic[j + 1][k]->_type;
                        _boardLogic[j][k]->_state = _boardLogic[j + 1][k]->_state;
                        _boardLogic[j][k]->_wait = _boardLogic[j + 1][k]->_wait;
                        if (_boardLogic[j][k]->_type != -1)
                        {
                            _boardGraphics[j][k]->_visibility = visible;
                            _boardGraphics[j][k]->SetAsset(decodeType(_boardLogic[j][k]->_type), 32, 32);
                        }
                        else
                        {
                            _boardGraphics[j][k]->_visibility = hidden;
                        }
                    }
                }
                for (unsigned int k = 0; k < _dimensions.getWidth(); k++)
                {
                    _boardLogic[_dimensions.getHeight() - 1][k]->_type = _tmpLogic[k]->_type;
                    _boardLogic[_dimensions.getHeight() - 1][k]->_wait = 0;
                    _boardLogic[_dimensions.getHeight() - 1][k]->_state = 0;
                    _boardGraphics[_dimensions.getHeight() - 1][k]->SetAsset(decodeType(_tmpLogic[k]->_type), 32, 32);
                    _boardGraphics[_dimensions.getHeight() - 1][k]->_visibility = visible;
                    char __random_type = rand()%5;
                    _tmpGraphics[k]->SetAsset(decodeType(__random_type), 32, 32);
                    _tmpLogic[k]->_type = __random_type;
                }
                
                if (_cursorPosition.getY() != 0)
                {
                    _cursorPosition.setY(_cursorPosition.getY()-1);
                    UpdateCursorPosition(_cursorPosition);
                }
                
                _boardContainer->_y += 31;
                _tmpContainer->_y = (32+1)*12;
                break;
            case GARBAGE_OPERATION:
                unsigned int __garbageSize = ExtractGarbageSize(_changes[i]);
                unsigned int __garbagePosition = ExtractGarbagePosition(_changes[i]);
                DropGargabe(__garbageSize, __garbagePosition);
                break;
        }
    }
    _changes.resize(0);
}

void Board::DEBUGGarbage ()
{
    Change __change = 0;
    __change = AddChangeType(__change, GARBAGE_OPERATION);
    __change = AddGarbageSize(__change, 3);
    __change = AddGarbagePosition(__change, 0);
    
    _changes.push_back(__change);
}

void Board::DropGargabe (unsigned int size, unsigned int position)
{
    // The garbage will overflow in terms of columns.
    if (size + position >= _dimensions.getWidth())
        return;
    
    for (unsigned int i = position; i < size; i++)
    {
        _boardLogic[0][i]->_type = 5;
        
        // For now, no blocky garbage
        _boardLogic[0][i]->_up = NULL;
        _boardLogic[0][i]->_down = NULL;
        
        // Check the sides to connect the parts of the garbage
        if (i > 0)
            _boardLogic[0][i]->_left = _boardLogic[0][i - 1];

        if (i < _dimensions.getWidth() - 1)
            _boardLogic[0][i]->_right = _boardLogic[0][i + 1];
        
        _boardGraphics[0][i]->SetAsset(decodeType(_boardLogic[0][i]->_type), 32, 32);
        _boardGraphics[0][i]->_visibility = visible;
    }
}

void Board::BlockAbove (unsigned int targetX, unsigned int targetY)
{
    for (int i = targetY - 1; i >= 0; i--)
    {
        if (_boardLogic[i][targetX]->_type == -1 && _boardLogic[i][targetX]->_type == 5)
            break;
        _boardLogic[i][targetX]->_wait = 12;
    }
}

void Board::SpeedUp()
{
    _rules->SpeedUp();
}

void Board::SlowDown()
{
    _rules->SlowDown();
}

void Board::Detect()
{
    _rules->Detect(_boardLogic, _dimensions.getWidth(), _dimensions.getHeight(), _changes);
}

void Board::Fall()
{
    _rules->Fall(_boardLogic, _dimensions.getWidth(), _dimensions.getHeight(), _changes);
}


void Board::Slide()
{
    _rules->Slide(_boardLogic, _dimensions.getWidth(), _dimensions.getHeight(), _changes, _boardContainer);
}

const unsigned char * Board::decodeType (unsigned int type)
{
    switch (type)
    {
        case 0: return dred; break;
        case 1: return dblue; break;
        case 2: return dyellow; break;
        case 3: return dgreen; break;
        case 4: return dpurple; break;
        case 5: return dgarbage; break;
    }
    return NULL;
}

const unsigned char * Board::decodeLightType (unsigned int type)
{
    switch (type)
    {
        case 0: return dred1; break;
        case 1: return dblue1; break;
        case 2: return dyellow1; break;
        case 3: return dgreen1; break;
        case 4: return dpurple1; break;
    }
    return NULL;
}


Board::~Board ()
{
  for (unsigned int i = 0; i < _dimensions.getHeight(); i++)
  {
     for (unsigned int j = 0; j < _dimensions.getWidth(); j++)
       delete [] _boardGraphics[i][j];
     delete [] _boardGraphics[i];
   }
   delete [] _boardGraphics;
   delete _cursor;
}
