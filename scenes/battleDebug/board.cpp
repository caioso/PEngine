#include "board.hpp"

Board::Board (RulesInterface * _rules, Dim2D dim, Point2D pos, Point2D cur_pos, int initial_height) :
                                        _dimensions(dim),
                                        _position(pos),
                                        _cursorPosition(cur_pos)
{
    // Initializes Sprite manager.
    // Load basic texture objects on demand.
    _spriteManager = new SpriteManager();
    
    // save reference of board rules.
    this->_rules = _rules;
    
    // Create base container for board.
    _boardContainer = new Sprite();
    _boardContainer->_x = (int)_position.getX();
    _boardContainer->_y = (int)_position.getY();
    
    // Incoming row container sprite.
    _nextRowContainer = new Sprite();
    _nextRowContainer->_x = 0;
    _nextRowContainer->_y = (PANEL_IMAGE_SIZE + PANEL_IMAGE_SPACE) * _dimensions.getHeight();

    // Instantiates main matrices and arrays.
    InstantiateMatrices();
    
    // Creates the initial board and next-row.
    InstantiateAndIntializeGameMatrices(initial_height);
    
    // Initialize Cursor.
    InitializeCursor();
}

void Board::InstantiateMatrices ()
{
    // Board Logic and Graphics Matrices instantiation.
    _boardGraphics = new Panel ** [_dimensions.getHeight()];
    _boardLogic = new LogicPanel ** [_dimensions.getHeight()];
    for (unsigned int i = 0; i < _dimensions.getHeight(); i++)
    {
        _boardGraphics[i] = new Panel * [_dimensions.getWidth()];
        _boardLogic[i] = new LogicPanel * [_dimensions.getWidth()];
    }
    
    // Next Row Logic and graphics array instantiation.
    _nextRowLogic = new LogicPanel * [_dimensions.getWidth()];
    _nextRowGraphics = new Panel * [_dimensions.getWidth()];
}

void Board::InstantiateAndIntializeGameMatrices(int initial_height)
{
    char __previous_type = PANEL_VOID_TYPE;
    for (unsigned int i = 0; i < _dimensions.getWidth(); i++)
    {
        // Make sure the current panel is different from the previous.
        char __random_type = GetNextTypeWithoutRepetition(__previous_type);
        __previous_type = __random_type;
        
        // Instantiate Next-Row Panel Graphics
        _nextRowGraphics[i] = new Panel(DecodeType(__random_type), PANEL_IMAGE_SIZE, PANEL_IMAGE_SIZE);
        
        // Adjust panel position.
        _nextRowGraphics[i]->_x = (PANEL_IMAGE_SIZE + PANEL_IMAGE_SPACE) * i;
        
        // Load panel on screen.
        _nextRowContainer->AddChild(_nextRowGraphics[i]);
        
        // Instantiate Next-Row Panel Logic
        _nextRowLogic[i] = new LogicPanel();
        _nextRowLogic[i]->_type = __random_type;
    }
    
    __previous_type = PANEL_VOID_TYPE;
    char __type_above = PANEL_VOID_TYPE;
    for (unsigned int i = 0; i < _dimensions.getHeight(); i++)
        for (unsigned int j = 0; j < _dimensions.getWidth(); j++)
        {
            // Make sure the current panel is different from the previous and the one above..
            __type_above = _boardLogic[i - 1][j]->_type;
            char __random_type = GetNextTypeWithoutRepetition(__previous_type, i==0?PANEL_VOID_TYPE:__type_above);
            __previous_type = __random_type;
            
            // Instantiate and initialize new Logic Panel
            _boardLogic[i][j] = new LogicPanel();
            _boardLogic[i][j]->_type = (int)__random_type;
            _boardLogic[i][j]->_state = 0;
            _boardLogic[i][j]->_wait = 0;
            
            // Intantiate new Panel Sprite.
            _boardGraphics[i][j] = new Panel (DecodeType(_boardLogic[i][j]->_type), PANEL_IMAGE_SIZE, PANEL_IMAGE_SIZE);
            
            // Adjust Panel position on screen.
            _boardGraphics[i][j]->_x = (PANEL_IMAGE_SIZE + PANEL_IMAGE_SPACE) * j;
            _boardGraphics[i][j]->_y = (PANEL_IMAGE_SIZE + PANEL_IMAGE_SPACE) * i;
            
            // Show panel on screen.
            _boardContainer->AddChild(_boardGraphics[i][j]);
            
            // If the panel is not to be displayed (empty row), hide it.
            if (i <= (unsigned int)initial_height)
            {
                _boardLogic[i][j]->_type = PANEL_VOID_TYPE;
                _boardGraphics[i][j]->_visibility = hidden;
            }
            
        }
    
    // Show board and next-row on screen.
    _boardContainer->AddChild(_nextRowContainer);
    GraphicEngine::_stage->AddChild(_boardContainer);
}

void Board::InitializeCursor ()
{
    // Intialize Cursor control variables.
    _cursorFrame = 0;
    _changeCursorFrame = false;
    
    // Instantiate Cursor Sprite.
    _cursor = new Cursor(_spriteManager->_cursor, CURSOR_WIDTH, CURSOR_HEIGHT);
    
    // Display Cursor on Screen.
    _boardContainer->AddChild(_cursor);
    
    // Update cursor position.
    UpdateCursorPosition (_cursorPosition);
}

char Board::GetNextTypeWithoutRepetition (char previous, char above, int mode)
{
    // Get a random type.
    char __random_type = previous;
    while (__random_type == previous || __random_type == above)
        __random_type = rand()%mode;
    return __random_type;
}

void Board::UpdateCursorPosition (Point2D pos)
{
    // Check board corners to make sure the cursor is correctly displayed onscreen.
    if (pos.getX() < 0 || pos.getX() >= _dimensions.getWidth() - 1)
        return;
    if (pos.getY() < 0 || pos.getY() >= _dimensions.getHeight())
        return;
    
    // Update Cursor Animation.
    _cursorFrame++;
    if (_cursorFrame == CURSOR_ANIMATION_LENGTH/2 && !_changeCursorFrame)
    {
        _cursor->SetAsset(_spriteManager->_cursor, CURSOR_WIDTH, CURSOR_HEIGHT);
        _changeCursorFrame = true;
    }
    else if (_cursorFrame == CURSOR_ANIMATION_LENGTH && _changeCursorFrame)
    {
        _cursor->SetAsset(_spriteManager->_cursor1, CURSOR_WIDTH, CURSOR_HEIGHT);
        _changeCursorFrame = false;
        _cursorFrame = 0;
    }
    
    // Update cursor position on screen.
    _cursorPosition = pos;
    _cursor->_x = _cursorPosition.getX() * (PANEL_IMAGE_SIZE + PANEL_IMAGE_SPACE);
    _cursor->_y = _cursorPosition.getY() * (PANEL_IMAGE_SIZE + PANEL_IMAGE_SPACE);
}

// ----------------------------------------------------
// OPERATION INTERPRETER
// ----------------------------------------------------
void Board::InterpretOperations ()
{
    // For each change in change array, commit it by removing from the list.
    for (size_t i = 0; i < _changes.size(); i++)
    {
        // Extract instruction operand and values.
        unsigned int __type = ExtractOperation(_changes[i]);
        
        // Remember to change the panel index to row and column.
        switch (__type)
        {
            // SWAP OPERATION
            // format: [TYPE][DEST_Y][DEST_X][TARG_Y][TARG_X]
            // Swaps two panels.
            case SWAP_OPERATION:
            {
                SwapOperation(_changes[i]);
                break;
            }
            // DESTROY OPERATION
            // format: [TYPE][XXXX][XXXX][TARG_Y][TARG_X]
            // Destroy a target panel.
            case DESTROY_OPERATION:
            {
                DestroyOperation(_changes[i]);
                break;
            }
            // FALL OPERATION
            // format: [TYPE][XXXX][XXXX][TARG_Y][TARG_X]
            // Move panel to the row below it.
            case FALL_OPERATION:
            {
                FallOperation(_changes[i]);
                break;
            }
            // PANEL GRAPHICS STYLE OPERATION
            // format: [TYPE][XXXX][STYLE][TARG_Y][TARG_X]
            // Change target panel sprite to a given mode.
            case PANEL_GRAPHICS_STYLE_OPERATION:
            {
                PanelGraphicsStyleOperation(_changes[i]);
                break;
            }
            // TRANSPORT OPERATION
            // format: [TYPE][XXXX][XXXX][XXXX][XXXX]
            // Update board when a new row is fully displayed (next row).
            case TRANSPORT_OPERATION:
            {
                TransportOperation();
                break;
            }
            // TRANSPORT OPERATION
            // format: [TYPE][XXXX][XXXX][POSITION][SIZE]
            // Update board when a new row is fully displayed (next row).
            case GARBAGE_OPERATION:
            {
                GarbageOperation(_changes[i]);
                break;
            }
        }
    }
    _changes.clear();
}

void Board::SwapOperation(Change change)
{
    // Extract Operation Operands
    unsigned int __targetX = ExtractTargetPanelX(change);
    unsigned int __targetY = ExtractTargetPanelY(change);
    unsigned int __destinationX = ExtractDestinationPanelX(change);
    unsigned int __destinationY = ExtractDestinationPanelY(change);
    
    // Extract derived and useful information
    int __targetType = _boardLogic[__targetY][__targetX]->_type;
    int __destinationType = _boardLogic[__destinationY][__destinationX]->_type;
    int __targetState = _boardLogic[__targetY][__targetX]->_state;
    int __targetWait = _boardLogic[__targetY][__targetX]->_wait;
    
    if (__destinationType != PANEL_VOID_TYPE)
    {
        // If the destination type is not null, Change the target texture based on destination.
        _boardGraphics[__targetY][__targetX]->SetAsset(DecodeType(__destinationType), PANEL_IMAGE_SIZE, PANEL_IMAGE_SIZE);
        // Make panel sprite visible.
        _boardGraphics[__targetY][__targetX]->_visibility = visible;
    }
    else
    {
        // Hide panel sprite.
        _boardGraphics[__targetY][__targetX]->_visibility = hidden;
    }
    
    if (__targetType != PANEL_VOID_TYPE)
    {
        // If the target type is not null, Change the destination texture based on target.
        _boardGraphics[__destinationY][__destinationX]->SetAsset(DecodeType(__targetType), PANEL_IMAGE_SIZE, PANEL_IMAGE_SIZE);
        // Make panel sprite visible.
        _boardGraphics[__destinationY][__destinationX]->_visibility = visible;
    }
    else
    {
        // Hide panel sprite.
        _boardGraphics[__destinationY][__destinationX]->_visibility = hidden;
    }
    
    // Update target logic data.
    _boardLogic[__targetY][__targetX]->_type = __destinationType;
    _boardLogic[__targetY][__targetX]->_state = _boardLogic[__destinationY][__destinationX]->_state;
    _boardLogic[__targetY][__targetX]->_wait = _boardLogic[__destinationY][__destinationX]->_wait;
    
    // Update destination logic data.
    _boardLogic[__destinationY][__destinationX]->_type = __targetType;
    _boardLogic[__destinationY][__destinationX]->_state = __targetState;
    _boardLogic[__destinationY][__destinationX]->_wait = __targetWait;
}

void Board::DestroyOperation(Change change)
{
    // Extract Operation Operands
    unsigned int __targetX = ExtractTargetPanelX(change);
    unsigned int __targetY = ExtractTargetPanelY(change);
    
    // Hide target panel graphics
    _boardGraphics[__targetY][__targetX]->_visibility = hidden;
    
    // Update target logic data.
    _boardLogic[__targetY][__targetX]->_type = PANEL_VOID_TYPE;
    _boardLogic[__targetY][__targetX]->_state = 0;
    _boardLogic[__targetY][__targetX]->_wait = 0;
}

void Board::FallOperation (Change change)
{
    // Extract Operation Operands
    unsigned int __targetX = ExtractTargetPanelX(change);
    unsigned int __targetY = ExtractTargetPanelY(change);
    
    // Extract extra derived information
    int __targetType = _boardLogic[__targetY][__targetX]->_type;
    
    // Update Panel below graphics
    _boardGraphics[__targetY + 1][__targetX]->_visibility = visible;
    _boardGraphics[__targetY + 1][__targetX]->SetAsset(DecodeType(__targetType), PANEL_IMAGE_SIZE, PANEL_IMAGE_SIZE);
    
    // Hide panel above
    _boardGraphics[__targetY][__targetX]->_visibility = hidden;
    
    // If garbage, maintain its structure
    if (__targetType == PANEL_GARBAGE_TYPE)
    {
        if (_boardLogic[__targetY][__targetX]->_left != NULL)
        {
            _boardLogic[__targetY + 1][__targetX]->_left = _boardLogic[__targetY + 1][__targetX - 1];
            _boardLogic[__targetY][__targetX]->_left = NULL;
        }
        else
            _boardLogic[__targetY + 1][__targetX]->_left = NULL;
        
        if (_boardLogic[__targetY][__targetX]->_right != NULL)
        {
            _boardLogic[__targetY + 1][__targetX]->_right = _boardLogic[__targetY + 1][__targetX + 1];
            _boardLogic[__targetY][__targetX]->_right = NULL;
        }
        else
            _boardLogic[__targetY + 1][__targetX]->_right = NULL;
        
        if (_boardLogic[__targetY][__targetX]->_up != NULL)
        {
            _boardLogic[__targetY + 1][__targetX]->_up = _boardLogic[__targetY][__targetX];
            _boardLogic[__targetY][__targetX]->_up = NULL;
        }
        else
            _boardLogic[__targetY + 1][__targetX]->_up = NULL;
        
        if (_boardLogic[__targetY][__targetX]->_down != NULL)
        {
            _boardLogic[__targetY + 1][__targetX]->_down = _boardLogic[__targetY + 2][__targetX];
            _boardLogic[__targetY][__targetX]->_down = NULL;
        }
        else
            _boardLogic[__targetY + 1][__targetX]->_down = NULL;
    }
    
    // Update panel below logics
    _boardLogic[__targetY + 1][__targetX]->_type = __targetType;
    _boardLogic[__targetY + 1][__targetX]->_state = 1;
    
    // Update panel above logics
    _boardLogic[__targetY][__targetX]->_type = PANEL_VOID_TYPE;
    _boardLogic[__targetY][__targetX]->_state = 0;
}

void Board::PanelGraphicsStyleOperation(Change change)
{
    // Extract Operation Operands
    unsigned int __targetX = ExtractTargetPanelX(change);
    unsigned int __targetY = ExtractTargetPanelY(change);
    unsigned int __imageStyle = ExtractPanelImageStyle(change);
    
    // Extract extra derived information
    int __targetType = _boardLogic[__targetY][__targetX]->_type;
    
    // Update target panel graphcis according to the intended style.
    _boardGraphics[__targetY][__targetX]->SetAsset(DecodeType(__targetType, __imageStyle), PANEL_IMAGE_SIZE, PANEL_IMAGE_SIZE);
}

void Board::TransportOperation ()
{
    for (unsigned int k = 0; k < _dimensions.getWidth(); k++)
        for (unsigned int j = 0; j < _dimensions.getHeight() - 1; j++)
        {
            // Update row above with previosu row logic.
            _boardLogic[j][k]->_type = _boardLogic[j + 1][k]->_type;
            _boardLogic[j][k]->_state = _boardLogic[j + 1][k]->_state;
            _boardLogic[j][k]->_wait = _boardLogic[j + 1][k]->_wait;
            
            // Update graphics accordingly
            if (_boardLogic[j][k]->_type != PANEL_VOID_TYPE)
            {
                _boardGraphics[j][k]->_visibility = visible;
                _boardGraphics[j][k]->SetAsset(DecodeType(_boardLogic[j][k]->_type), PANEL_IMAGE_SIZE, PANEL_IMAGE_SIZE);
            }
            else
                _boardGraphics[j][k]->_visibility = hidden;
            
            // If garbage, maintain its structure
            if (_boardLogic[j][k]->_type == PANEL_GARBAGE_TYPE)
            {
                _boardLogic[j][k]->_left = _boardLogic[j + 1][k]->_left;
                _boardLogic[j][k]->_right = _boardLogic[j + 1][k]->_right;
                _boardLogic[j][k]->_up = _boardLogic[j + 1][k]->_up;
                _boardLogic[j][k]->_down = _boardLogic[j + 1][k]->_down;
            }
            else
            {
                _boardLogic[j][k]->_left = NULL;
                _boardLogic[j][k]->_right = NULL;;
                _boardLogic[j][k]->_up = NULL;
                _boardLogic[j][k]->_down  = NULL;
            }
        }
    
    // Fill the first row with the next row and create a new nextRow with random types.
    char __previous_type = PANEL_VOID_TYPE;
    for (unsigned int k = 0; k < _dimensions.getWidth(); k++)
    {
        // Update first row with nextRow content.
        _boardLogic[_dimensions.getHeight() - 1][k]->_type = _nextRowLogic[k]->_type;
        _boardLogic[_dimensions.getHeight() - 1][k]->_wait = 0;
        _boardLogic[_dimensions.getHeight() - 1][k]->_state = 0;
        _boardGraphics[_dimensions.getHeight() - 1][k]->SetAsset(DecodeType(_nextRowLogic[k]->_type), PANEL_IMAGE_SIZE, PANEL_IMAGE_SIZE);
        _boardGraphics[_dimensions.getHeight() - 1][k]->_visibility = visible;
        
        // Make sure the current panel is different from the previous.
        char __random_type = GetNextTypeWithoutRepetition(__previous_type);
        __previous_type = __random_type;
        
        // Create next row graphics and update logics.
        _nextRowGraphics[k]->SetAsset(DecodeType(__random_type), PANEL_IMAGE_SIZE, PANEL_IMAGE_SIZE);
        _nextRowLogic[k]->_type = __random_type;
    }
    
    // Update cursor position if in the first row (topmost)
    if (_cursorPosition.getY() != 0)
    {
        _cursorPosition.setY(_cursorPosition.getY()-1);
        UpdateCursorPosition(_cursorPosition);
    }
    
    // Update board container and next row position.
    _boardContainer->_y += PANEL_IMAGE_SIZE - 1;
    _nextRowContainer->_y = (PANEL_IMAGE_SIZE+1) * _dimensions.getHeight();
}

void Board::GarbageOperation(Change change)
{
    // Extract Operation Operands
    unsigned int __garbageSize = ExtractGarbageSize(change);
    unsigned int __garbagePosition = ExtractGarbagePosition(change);
    
    // Build new garbage object.
    DropGargabe(__garbageSize, __garbagePosition);

}

// ----------------------------------------------------

void Board::DEBUGGarbage ()
{
    Change __change = 0;
    __change = AddChangeType(__change, GARBAGE_OPERATION);
    __change = AddGarbageSize(__change, PANEL_GARBAGE_TYPE);
    __change = AddGarbagePosition(__change, 1);
    
    _changes.push_back(__change);
}

void Board::DropGargabe (unsigned int size, unsigned int position)
{
    // The garbage will overflow in terms of columns.
    if (size + position > _dimensions.getWidth())
        return;
    
    unsigned int counter = 0;
    for (unsigned int i = position; i < position + size; i++)
    {
        _boardLogic[0][i]->_type = PANEL_GARBAGE_TYPE;
        
        // For now, no blocky garbage
        _boardLogic[0][i]->_up = NULL;
        _boardLogic[0][i]->_down = NULL;
        
        // Check the sides to connect the parts of the garbage
        if (counter > 0)
            _boardLogic[0][i]->_left = _boardLogic[0][i - 1];
        else
            _boardLogic[0][i]->_left = NULL;

        if (counter < size - 1)
            _boardLogic[0][i]->_right = _boardLogic[0][i + 1];
        else
            _boardLogic[0][i]->_right = NULL;
        
        counter++;
        _boardGraphics[0][i]->SetAsset(DecodeType(_boardLogic[0][i]->_type), PANEL_IMAGE_SIZE, PANEL_IMAGE_SIZE);
        _boardGraphics[0][i]->_visibility = visible;
        _boardLogic[0][i]->_state = 1;
    }
}

void Board::Slide()
{
    _rules->Slide(_boardLogic, _dimensions.getWidth(), _dimensions.getHeight(), _changes, _boardContainer);
}

GRRLIB_texImg * Board::DecodeType (unsigned int type, unsigned int style)
{
    // Identify the requested type. Style is used to determine which type
    // of sprite will be returned.
    switch (style)
    {
        case PANEL_NORMAL_SPRITE:
            switch (type)
            {
                case PANEL_RED_TYPE:     return _spriteManager->_dred; break;
                case PANEL_CYAN_TYPE:    return _spriteManager->_dblue; break;
                case PANEL_YELLOW_TYPE:  return _spriteManager->_dyellow; break;
                case PANEL_GREEN_TYPE:   return _spriteManager->_dgreen; break;
                case PANEL_PURPLE_TYPE:  return _spriteManager->_dpurple; break;
                case PANEL_GARBAGE_TYPE: return _spriteManager->_dgarbage; break;
            }
        break;
        case PANEL_BRIGHT_SPRITE:
            switch (type)
            {
                case PANEL_RED_TYPE:     return _spriteManager->_dred1; break;
                case PANEL_CYAN_TYPE:    return _spriteManager->_dblue1; break;
                case PANEL_YELLOW_TYPE:  return _spriteManager->_dyellow1; break;
                case PANEL_GREEN_TYPE:   return _spriteManager->_dgreen1; break;
                case PANEL_PURPLE_TYPE:  return _spriteManager->_dpurple1; break;
            }
        break;
    }
    return NULL;
}

void Board::Swap ()
{
    _rules->Swap(_boardLogic, _dimensions.getWidth(), _dimensions.getHeight(), _changes, &_cursorPosition);
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
