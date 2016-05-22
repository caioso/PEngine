#include "board.hpp"

Board::Board (RulesInterface * _rules, Dim2D dim, Point2D pos, Point2D cur_pos, int initial_height, SpriteManager *spriteManager, Controller * wiiremote) :
                                        _dimensions(dim),
                                        _position(pos),
                                        _cursorPosition(cur_pos),
                                        _wiiremote(wiiremote)
{
    // Fair randomization
    srand(time(NULL));
    
    // Initializes Sprite manager.
    // Load basic texture objects on demand.
    _spriteManager = spriteManager;
    
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
    
    __delay = 0;

    // Instantiates main matrices and arrays.
    InstantiateMatrices();
    
    // Creates the initial board and next-row.
    InstantiateAndIntializeGameMatrices(initial_height);
    
    // Initialize Swap Sprites
    InitializeSwapSprites();
}

void Board::InitializeSwapSprites ()
{
    // Swap Animation Sprite
    _leftSwap = new Panel(_spriteManager->_dred, PANEL_IMAGE_SIZE, PANEL_IMAGE_SIZE);
    _rightSwap = new Panel(_spriteManager->_dgreen, PANEL_IMAGE_SIZE, PANEL_IMAGE_SIZE);
    
    _leftSwap->_x = 0;
    _leftSwap->_y = 0;
    
    _rightSwap->_x = 0;
    _rightSwap->_y = 0;
    
    _leftState = 0;
    _rightState = 0;
    
    _boardContainer->AddChild(_leftSwap);
    _boardContainer->AddChild(_rightSwap);
    
    _rightSwap->_visibility = hidden;
    _leftSwap->_visibility = hidden;
    
    _isSwapping = false;
    _swapTarget = new Point2D();
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
        _nextRowGraphics[i] = new Panel(DecodeType(__random_type, PANEL_DARK_SPRITE), PANEL_IMAGE_SIZE, PANEL_IMAGE_SIZE);
        
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
    GraphicEngine::_stage->AddChildAt(_boardContainer, 0);
}

void Board::InitializeCursor ()
{
    // Instantiate Cursor Sprite.
    _cursor = new Cursor(_spriteManager->_cursor0001, CURSOR_WIDTH, CURSOR_HEIGHT);
    
    // Load Cursor Animation
    _cursor->RegisterFrame(_spriteManager->_cursor0001);
    _cursor->RegisterFrame(_spriteManager->_cursor0002);
    _cursor->RegisterFrame(_spriteManager->_cursor0003);
    _cursor->RegisterFrame(_spriteManager->_cursor0004);
    _cursor->RegisterFrame(_spriteManager->_cursor0005);
    _cursor->RegisterFrame(_spriteManager->_cursor0006);
    _cursor->RegisterFrame(_spriteManager->_cursor0007);
    _cursor->RegisterFrame(_spriteManager->_cursor0008);
    _cursor->RegisterFrame(_spriteManager->_cursor0009);
    _cursor->RegisterFrame(_spriteManager->_cursor0010);
    _cursor->RegisterFrame(_spriteManager->_cursor0011);
    _cursor->_animation_delay = 2;
    _cursor->Play();
    
    // Update Cursor Initial Position
    _cursor->_x = _boardContainer->_x;
    _cursor->_y = _boardContainer->_y;
    
    // Display Cursor on Screen.
    GraphicEngine::_stage->AddChild(_cursor);
    
    // Update cursor position.
    UpdateCursorPosition (_cursorPosition);
}

char Board::GetNextTypeWithoutRepetition (char previous, char above, int mode)
{
    // Get a random type.
    char __random_type = previous;
    //while (__random_type == previous || __random_type == above)
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
    
    // Update cursor position on screen.
    _cursorPosition = pos;
    _cursor->_x = _boardContainer->_x + (_cursorPosition.getX() * (PANEL_IMAGE_SIZE + PANEL_IMAGE_SPACE)) - 3;
    _cursor->_y = _boardContainer->_y + (_cursorPosition.getY() * (PANEL_IMAGE_SIZE + PANEL_IMAGE_SPACE)) - 4;
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
            // GARBAGE OPERATION
            // format: [TYPE][XXXX][POSITION][WIDTH][HEIGHT]
            // Update board when a new row is fully displayed (next row).
            case GARBAGE_OPERATION:
            {
                GarbageOperation(_changes[i]);
                break;
            }
            // TRANSFORM GARBAGE OPERATION
            // format: [TYPE][XXXX][XXXX][SRC_Y][SRC_X]
            // Breaks garbage objects into smaller parts.
            case TRANSFORM_GARBAGE_OPERATION:
            {
                TransformGarbageOperation(_changes[i]);
                break;
            }
            // CONCRETE GARBAGE OPERATION
            // format: [TYPE][XXXX][XXXX][XXXX][XXXX]
            // Update board when a new row is fully displayed (next row).
            case CONCRETE_GARBAGE_OPERATION:
            {
                MakeConcreteGargabe();
                break;
            }
            // RISE BOARD OPERATION
            // format: [TYPE][XXXX][XXXX][XXXX][XXXX]
            // Move the board a pixel upwards.
            case RISE_BOARD_OPERATION:
            {
                RiseBoardOperation();
                break;
            }
            // RUMBLE OPERATION
            // format: [TYPE][XXXX][XXXX][XXXX][XXXX]
            // Move the board a pixel upwards.
            case RUMBLE_OPERATION:
            {
                RumbleOperation(_changes[i]);
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
    _leftState = _boardLogic[__targetY][__targetX]->_state;
    _rightState = _boardLogic[__targetY][__targetX + 1]->_state;
    
    _boardLogic[__targetY][__targetX]->_state = 2;
    _boardLogic[__targetY][__targetX + 1]->_state = 2;
    
    if (__targetType == PANEL_VOID_TYPE)
    {
        _boardGraphics[__targetY][__targetX]->_visibility = hidden;
    }
    
    if (__destinationType == PANEL_VOID_TYPE)
        _boardGraphics[__destinationY][__destinationX]->_visibility = hidden;
    
    _swapTarget->setX(__targetX);
    _swapTarget->setY(__targetY);
    
    _isSwapping = true;
    
    AnimateSwap(__targetY, __targetX);
}

void Board::AnimateSwap (unsigned int i, unsigned int j)
{
    // Swap Animation Sprite
    _leftSwap->SetAsset(DecodeType(_boardLogic[i][j]->_type == PANEL_VOID_TYPE? PANEL_RED_TYPE : _boardLogic[i][j]->_type), PANEL_IMAGE_SIZE, PANEL_IMAGE_SIZE);
    
    if (_boardLogic[i][j]->_type != PANEL_VOID_TYPE)
        _leftSwap->_visibility = visible;
    else
        _leftSwap->_visibility = hidden;
    
    _leftSwap->_x = _boardGraphics[i][j]->_x;
    _leftSwap->_y = _boardGraphics[i][j]->_y;
    
    _boardGraphics[i][j]->_visibility = hidden;
    
    SpriteProperties __left_properties(_leftSwap);
    __left_properties.RegisterPropertyFinalValue(SpriteX, _leftSwap->_x + PANEL_IMAGE_SIZE + PANEL_IMAGE_SPACE);
    AnimationEngine::RegisterTween(_leftSwap, __left_properties, 85.0);
    
    
    _rightSwap->SetAsset(DecodeType(_boardLogic[i][j + 1]->_type == PANEL_VOID_TYPE? PANEL_RED_TYPE : _boardLogic[i][j + 1]->_type), PANEL_IMAGE_SIZE, PANEL_IMAGE_SIZE);
    
    if (_boardLogic[i][j + 1]->_type != PANEL_VOID_TYPE)
        _rightSwap->_visibility = visible;
    else
        _rightSwap->_visibility = hidden;
    
    _rightSwap->_x = _boardGraphics[i][j + 1]->_x;
    _rightSwap->_y = _boardGraphics[i][j + 1]->_y;
    
    _boardGraphics[i][j + 1]->_visibility = hidden;
    
    SpriteProperties __right_properties(_rightSwap);
    __right_properties.RegisterPropertyFinalValue(SpriteX, _rightSwap->_x - PANEL_IMAGE_SIZE - PANEL_IMAGE_SPACE);
    AnimationEngine::RegisterTween(_rightSwap, __right_properties, 85.0);
}

void Board::CompleteSwap ()
{
    if (!_isSwapping)
        return;
    
    if (_leftSwap->GetIsAnimating() || _rightSwap->GetIsAnimating())
        return;
    
    unsigned int __targetX = _swapTarget->getX();
    unsigned int __targetY = _swapTarget->getY();
    unsigned int __destinationX = __targetX + 1;
    unsigned int __destinationY = __targetY;
    
    // Extract derived and useful information
    int __targetType = _boardLogic[__targetY][__targetX]->_type;
    int __destinationType = _boardLogic[__destinationY][__destinationX]->_type;
    
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
    _boardLogic[__targetY][__targetX]->_state = 0;
    _boardLogic[__targetY][__targetX]->_wait = 0;//_boardLogic[__destinationY][__destinationX]->_wait;
    
    // Update destination logic data.
    _boardLogic[__destinationY][__destinationX]->_type = __targetType;
    _boardLogic[__destinationY][__destinationX]->_state = 0;
    _boardLogic[__destinationY][__destinationX]->_wait = 0;//__targetWait;
    
    // Ignore Garbage Part
    ClearGarbageData(_boardLogic[__targetY][__targetX]);
    ClearGarbageData(_boardLogic[__destinationY][__destinationX]);
    
    _leftSwap->_visibility = hidden;
    _rightSwap->_visibility = hidden;
    
    _isSwapping = false;
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
    
    // Ignore Garbage Part
    ClearGarbageData(_boardLogic[__targetY][__targetX]);
}

void Board::FallOperation (Change change)
{
    // Extract Operation Operands
    unsigned int __targetX = ExtractTargetPanelX(change);
    unsigned int __targetY = ExtractTargetPanelY(change);
    
    // Extract derived and useful information
    int __targetType = _boardLogic[__targetY][__targetX]->_type;
    
    _boardGraphics[__targetY + 1][__targetX]->_visibility = visible;
    _boardGraphics[__targetY + 1][__targetX]->SetAsset(DecodeType(__targetType), PANEL_IMAGE_SIZE, PANEL_IMAGE_SIZE);
    _boardGraphics[__targetY][__targetX]->_visibility = hidden;
    
    _boardLogic[__targetY + 1][__targetX]->_type = _boardLogic[__targetY][__targetX]->_type;
    _boardLogic[__targetY + 1][__targetX]->_state = 1;
    _boardLogic[__targetY + 1][__targetX]->_wait = _boardLogic[__targetY][__targetX]->_wait;
    _boardLogic[__targetY + 1][__targetX]->_positionX = _boardLogic[__targetY][__targetX]->_positionX;
    _boardLogic[__targetY + 1][__targetX]->_positionY = _boardLogic[__targetY][__targetX]->_positionY;
    _boardLogic[__targetY + 1][__targetX]->_sourceX = _boardLogic[__targetY][__targetX]->_sourceX;
    _boardLogic[__targetY + 1][__targetX]->_sourceY = _boardLogic[__targetY][__targetX]->_sourceY;
    _boardLogic[__targetY + 1][__targetX]->_width = _boardLogic[__targetY][__targetX]->_width;
    _boardLogic[__targetY + 1][__targetX]->_height = _boardLogic[__targetY][__targetX]->_height;

    if (__targetType == PANEL_GARBAGE_TYPE || __targetType == PANEL_CONCRETE_GARBAGE_TYPE)
        _boardLogic[__targetY + 1][__targetX]->_sourceY++;
    
    _boardLogic[__targetY][__targetX]->_type = -1;
    _boardLogic[__targetY][__targetX]->_state = 0;
    _boardLogic[__targetY][__targetX]->_wait = -1;
    _boardLogic[__targetY][__targetX]->_positionX = -1;
    _boardLogic[__targetY][__targetX]->_positionY = -1;
    _boardLogic[__targetY][__targetX]->_sourceX = -1;
    _boardLogic[__targetY][__targetX]->_sourceY = -1;
    _boardLogic[__targetY][__targetX]->_width = -1;
    _boardLogic[__targetY][__targetX]->_height = -1;

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
            if (_boardLogic[j][k]->_type == PANEL_GARBAGE_TYPE || _boardLogic[j][k]->_type == PANEL_CONCRETE_GARBAGE_TYPE)
            {
                _boardLogic[j][k]->_positionX = _boardLogic[j + 1][k]->_positionX;
                _boardLogic[j][k]->_positionY = _boardLogic[j + 1][k]->_positionY;
                _boardLogic[j][k]->_sourceX = _boardLogic[j + 1][k]->_sourceX;
                _boardLogic[j][k]->_sourceY = _boardLogic[j + 1][k]->_sourceY - 1;
                _boardLogic[j][k]->_width = _boardLogic[j + 1][k]->_width;
                _boardLogic[j][k]->_height = _boardLogic[j + 1][k]->_height;
                ClearGarbageData(_boardLogic[j + 1][k]);
            }
            else
            {
                // Ignore Garbage Part
                ClearGarbageData(_boardLogic[j][k]);
            }
        }
    
    // Fill the first row with the next row and create a new nextRow with random types.
    char __previous_type = PANEL_VOID_TYPE;
    char __type_above = PANEL_VOID_TYPE;
    for (unsigned int k = 0; k < _dimensions.getWidth(); k++)
    {
        // Update first row with nextRow content.
        _boardLogic[_dimensions.getHeight() - 1][k]->_type = _nextRowLogic[k]->_type;
        _boardLogic[_dimensions.getHeight() - 1][k]->_wait = 0;
        _boardLogic[_dimensions.getHeight() - 1][k]->_state = 0;
        _boardGraphics[_dimensions.getHeight() - 1][k]->SetAsset(DecodeType(_nextRowLogic[k]->_type), PANEL_IMAGE_SIZE, PANEL_IMAGE_SIZE);
        _boardGraphics[_dimensions.getHeight() - 1][k]->_visibility = visible;
        
        // Ignore Garbage Part
        ClearGarbageData(_boardLogic[_dimensions.getHeight() - 1][k]);

        // Make sure the current panel is different from the previous.
        __type_above = _boardLogic[_dimensions.getHeight() - 1][k]->_type;
        char __random_type = GetNextTypeWithoutRepetition(__previous_type, __type_above);
        __previous_type = __random_type;

        // Create next row graphics and update logics.
        _nextRowGraphics[k]->SetAsset(DecodeType(__random_type, PANEL_DARK_SPRITE), PANEL_IMAGE_SIZE, PANEL_IMAGE_SIZE);
        _nextRowLogic[k]->_type = __random_type;
    }
    
    // Update cursor position if in the first row (topmost)
    if (_cursorPosition.getY() != 0)
    {
        _cursorPosition.setY(_cursorPosition.getY()-1);
        UpdateCursorPosition(_cursorPosition);
    }

    // Update Swap Animation
    if (_isSwapping)
    {
        _swapTarget->setY(_swapTarget->getY() - 1);
        
        _boardGraphics[_swapTarget->getY()][_swapTarget->getX()]->_visibility = hidden;
        _boardGraphics[_swapTarget->getY()][_swapTarget->getX() + 1]->_visibility = hidden;
        
        _leftSwap->_y -= PANEL_IMAGE_SIZE;
        _rightSwap->_y -= PANEL_IMAGE_SIZE;
    }
    
    // Update board container and next row position.
    _boardContainer->_y += PANEL_IMAGE_SIZE + PANEL_IMAGE_SPACE;
    _cursor->_y += PANEL_IMAGE_SIZE + PANEL_IMAGE_SPACE;
    _nextRowContainer->_y = (PANEL_IMAGE_SIZE + PANEL_IMAGE_SPACE) * _dimensions.getHeight();
}

void Board::GarbageOperation(Change change)
{
    // Extract Operation Operands
    unsigned int __garbageWidth = ExtractGarbageWidth(change);
    unsigned int __garbageHeight = ExtractGarbageHeight(change);
    unsigned int __garbagePosition = ExtractGarbagePosition(change);
    
    // Build new garbage object.
    MakeGargabe(__garbageWidth, __garbageHeight, __garbagePosition);
}

void Board::RumbleOperation (Change change)
{
    unsigned int __rumbleLength = ExtractRumbleLength(change);
    _wiiremote->RumbleFor(__rumbleLength);
}

void Board::TransformGarbageOperation(Change change)
{
    // Extract Operation Operands
    unsigned int __garbageSourceX = ExtractTargetPanelX(change);
    unsigned int __garbageSourceY = ExtractTargetPanelY(change);
    
    // Build new garbage object.
    char __previous_type = -1;
    // Make sure the current panel is different from the previous.
    char __random_type = GetNextTypeWithoutRepetition(__previous_type);
    __previous_type = __random_type;
    
    // Create new panels in the place of the
    _boardLogic[__garbageSourceY][__garbageSourceX]->_type = __random_type;
    _boardLogic[__garbageSourceY][__garbageSourceX]->_wait = 0;
    _boardLogic[__garbageSourceY][__garbageSourceX]->_state = 0;
    _boardGraphics[__garbageSourceY][__garbageSourceX]->SetAsset(DecodeType(__random_type), PANEL_IMAGE_SIZE, PANEL_IMAGE_SIZE);
    _boardGraphics[__garbageSourceY][__garbageSourceX]->_visibility = visible;

    ClearGarbageData(_boardLogic[__garbageSourceY][__garbageSourceX]);
}


// ----------------------------------------------------

void Board::DEBUGGarbage ()
{
    
    Change __change = 0;
    __change = AddChangeType(__change, GARBAGE_OPERATION);
    __change = AddGarbageWidth(__change, 6);
    __change = AddGarbageHeight(__change, 3);
    __change = AddGarbagePosition(__change, 0);
    
    _changes.push_back(__change);
    
    __change = 0;
    __change = AddChangeType(__change, CONCRETE_GARBAGE_OPERATION);
    
    _changes.push_back(__change);
    
    __change = 0;
    __change = AddChangeType(__change, GARBAGE_OPERATION);
    __change = AddGarbageWidth(__change, 4);
    __change = AddGarbageHeight(__change, 1);
    __change = AddGarbagePosition(__change, 0);
    
    _changes.push_back(__change);
    
    __change = 0;
    __change = AddChangeType(__change, CONCRETE_GARBAGE_OPERATION);
    
    _changes.push_back(__change);
    
    __change = 0;
    __change = AddChangeType(__change, GARBAGE_OPERATION);
    __change = AddGarbageWidth(__change, 3);
    __change = AddGarbageHeight(__change, 1);
    __change = AddGarbagePosition(__change, 2);
    
    _changes.push_back(__change);
}

void Board::MakeGargabe (unsigned int width, unsigned int height, unsigned int position)
{
    // The garbage will overflow in terms of columns.
    if (width + position > _dimensions.getWidth())
        return;
    
    for (unsigned int j = 0; j < height; j++)
    {
        LogicPanel ** __garbageSlice  = new LogicPanel *[_dimensions.getWidth()];
        for (unsigned int i = 0; i < _dimensions.getWidth(); i++)
        {
            __garbageSlice[i]  = new LogicPanel();
            __garbageSlice[i]->_type = -1;
            __garbageSlice[i]->_sourceX = -1;
            __garbageSlice[i]->_sourceY = -1;
            __garbageSlice[i]->_width = 0;
            __garbageSlice[i]->_height = 0;
            __garbageSlice[i]->_positionX = -1;
            __garbageSlice[i]->_positionY = -1;
            __garbageSlice[i]->_wait = 0;
            __garbageSlice[i]->_state = 0;
        }
        
        for (unsigned int i = position; i < position + width; i++)
        {
            __garbageSlice[i]->_type = PANEL_GARBAGE_TYPE;
            __garbageSlice[i]->_sourceX = position;
            __garbageSlice[i]->_sourceY = 0;
            __garbageSlice[i]->_width = width;
            __garbageSlice[i]->_height = height;
            __garbageSlice[i]->_positionX = i;
            __garbageSlice[i]->_positionY = j;
            __garbageSlice[i]->_wait = 0;
            __garbageSlice[i]->_state = 0;
        }
        _garbageList.push_back(__garbageSlice);
    }
}

void Board::MakeConcreteGargabe ()
{
    
        LogicPanel ** __garbageSlice  = new LogicPanel *[_dimensions.getWidth()];
        for (unsigned int i = 0; i < _dimensions.getWidth(); i++)
        {
            __garbageSlice[i] = new LogicPanel();
            __garbageSlice[i]->_type = -1;
            __garbageSlice[i]->_sourceX = -1;
            __garbageSlice[i]->_sourceY = -1;
            __garbageSlice[i]->_width = 0;
            __garbageSlice[i]->_height = 0;
            __garbageSlice[i]->_positionX = -1;
            __garbageSlice[i]->_positionY = -1;
            __garbageSlice[i]->_wait = 0;
            __garbageSlice[i]->_state = 0;
        }
        
        for (unsigned int i = 0; i < _dimensions.getWidth(); i++)
        {
            __garbageSlice[i]->_type = PANEL_CONCRETE_GARBAGE_TYPE;
            __garbageSlice[i]->_sourceX = 0;
            __garbageSlice[i]->_sourceY = 0;
            __garbageSlice[i]->_width = _dimensions.getWidth();
            __garbageSlice[i]->_height = 1;
            __garbageSlice[i]->_positionX = i;
            __garbageSlice[i]->_positionY = 0;
            __garbageSlice[i]->_wait = 0;
            __garbageSlice[i]->_state = 0;
        }
        _garbageList.push_back(__garbageSlice);
}

void Board::FallGarbage ()
{
    if (_garbageList.size() == 0)
        return;
    
    for (unsigned int i = 0; i < _dimensions.getWidth(); i++)
    {
        // Check if the top most if free let garbage fall.
        if (_boardLogic[0][i]->_type != -1 && _garbageList[0][i]->_type == PANEL_GARBAGE_TYPE)
        {
            return;
        }
    }
    
    for (unsigned int i = 0; i < _dimensions.getWidth(); i++)
    {
        if (_garbageList[0][i]->_type  == PANEL_GARBAGE_TYPE || _garbageList[0][i]->_type == PANEL_CONCRETE_GARBAGE_TYPE)
        {
            _boardLogic[0][i]->_type = _garbageList[0][i]->_type;
            _boardLogic[0][i]->_sourceX = _garbageList[0][i]->_sourceX;
            _boardLogic[0][i]->_sourceY = _garbageList[0][i]->_sourceY;
            _boardLogic[0][i]->_width = _garbageList[0][i]->_width;
            _boardLogic[0][i]->_height = _garbageList[0][i]->_height;
            _boardLogic[0][i]->_positionX = _garbageList[0][i]->_positionX;
            _boardLogic[0][i]->_positionY = _garbageList[0][i]->_positionY;
            _boardLogic[0][i]->_wait = _garbageList[0][i]->_wait;
            _boardLogic[0][i]->_state = _garbageList[0][i]->_state;
            
            _boardGraphics[0][i]->SetAsset(DecodeType(_garbageList[0][i]->_type), PANEL_IMAGE_SIZE, PANEL_IMAGE_SIZE);
            _boardGraphics[0][i]->_visibility = visible;
        }
    }
    for (unsigned int i = 0; i < _dimensions.getWidth(); i++)
        delete _garbageList[0][i];
    delete[] _garbageList[0];
    _garbageList.erase (_garbageList.begin());
}

void Board::Slide()
{
    _rules->Slide(_dimensions.getWidth(), _dimensions.getHeight(), _changes);
}

void Board::RiseBoardOperation ()
{
    _boardContainer->_y--;
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
                case PANEL_RED_TYPE:              return _spriteManager->_dred; break;
                case PANEL_CYAN_TYPE:             return _spriteManager->_dblue; break;
                case PANEL_YELLOW_TYPE:           return _spriteManager->_dyellow; break;
                case PANEL_GREEN_TYPE:            return _spriteManager->_dgreen; break;
                case PANEL_PURPLE_TYPE:           return _spriteManager->_dpurple; break;
                case PANEL_GARBAGE_TYPE:          return _spriteManager->_dgarbage; break;
                case PANEL_CONCRETE_GARBAGE_TYPE: return _spriteManager->_concrete; break;
            }
        break;
        case PANEL_DARK_SPRITE:
            switch (type)
            {
                case PANEL_RED_TYPE:              return _spriteManager->_dRedblocked; break;
                case PANEL_CYAN_TYPE:             return _spriteManager->_dBlueblocked; break;
                case PANEL_YELLOW_TYPE:           return _spriteManager->_dYellowblocked; break;
                case PANEL_GREEN_TYPE:            return _spriteManager->_dGreenblocked; break;
                case PANEL_PURPLE_TYPE:           return _spriteManager->_dPurpleblocked; break;
                case PANEL_GARBAGE_TYPE:          return _spriteManager->_dGrayblocked; break;
                case PANEL_CONCRETE_GARBAGE_TYPE: return _spriteManager->_dGrayblocked; break;
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
        case PANEL_FALL_FRAME_1:
            switch (type)
            {
                case PANEL_RED_TYPE:     return _spriteManager->_dRedFalling0001; break;
                case PANEL_CYAN_TYPE:    return _spriteManager->_dBlueFalling0001; break;
                case PANEL_YELLOW_TYPE:  return _spriteManager->_dYellowFalling0001; break;
                case PANEL_GREEN_TYPE:   return _spriteManager->_dGreenFalling0001; break;
                case PANEL_PURPLE_TYPE:  return _spriteManager->_dPurpleFalling0001; break;
            }
        break;
        case PANEL_FALL_FRAME_2:
            switch (type)
            {
                case PANEL_RED_TYPE:     return _spriteManager->_dRedFalling0002; break;
                case PANEL_CYAN_TYPE:    return _spriteManager->_dBlueFalling0002; break;
                case PANEL_YELLOW_TYPE:  return _spriteManager->_dYellowFalling0002; break;
                case PANEL_GREEN_TYPE:   return _spriteManager->_dGreenFalling0002; break;
                case PANEL_PURPLE_TYPE:  return _spriteManager->_dPurpleFalling0002; break;
            }
        break;
        case PANEL_FALL_FRAME_3:
            switch (type)
            {
                case PANEL_RED_TYPE:     return _spriteManager->_dRedFalling0003; break;
                case PANEL_CYAN_TYPE:    return _spriteManager->_dBlueFalling0003; break;
                case PANEL_YELLOW_TYPE:  return _spriteManager->_dYellowFalling0003; break;
                case PANEL_GREEN_TYPE:   return _spriteManager->_dGreenFalling0003; break;
                case PANEL_PURPLE_TYPE:  return _spriteManager->_dPurpleFalling0003; break;
            }
        break;
        case PANEL_FALL_FRAME_4:
            switch (type)
            {
                case PANEL_RED_TYPE:     return _spriteManager->_dRedFalling0004; break;
                case PANEL_CYAN_TYPE:    return _spriteManager->_dBlueFalling0004; break;
                case PANEL_YELLOW_TYPE:  return _spriteManager->_dYellowFalling0004; break;
                case PANEL_GREEN_TYPE:   return _spriteManager->_dGreenFalling0004; break;
                case PANEL_PURPLE_TYPE:  return _spriteManager->_dPurpleFalling0004; break;
            }
        break;
        case PANEL_FALL_FRAME_5:
            switch (type)
            {
                case PANEL_RED_TYPE:     return _spriteManager->_dRedFalling0005; break;
                case PANEL_CYAN_TYPE:    return _spriteManager->_dBlueFalling0005; break;
                case PANEL_YELLOW_TYPE:  return _spriteManager->_dYellowFalling0005; break;
                case PANEL_GREEN_TYPE:   return _spriteManager->_dGreenFalling0005; break;
                case PANEL_PURPLE_TYPE:  return _spriteManager->_dPurpleFalling0005; break;
            }
        break;
        case PANEL_FALL_FRAME_6:
            switch (type)
            {
                case PANEL_RED_TYPE:     return _spriteManager->_dRedFalling0006; break;
                case PANEL_CYAN_TYPE:    return _spriteManager->_dBlueFalling0006; break;
                case PANEL_YELLOW_TYPE:  return _spriteManager->_dYellowFalling0006; break;
                case PANEL_GREEN_TYPE:   return _spriteManager->_dGreenFalling0006; break;
                case PANEL_PURPLE_TYPE:  return _spriteManager->_dPurpleFalling0006; break;
            }
        break;
        case PANEL_FALL_FRAME_7:
            switch (type)
            {
                case PANEL_RED_TYPE:     return _spriteManager->_dRedFalling0007; break;
                case PANEL_CYAN_TYPE:    return _spriteManager->_dBlueFalling0007; break;
                case PANEL_YELLOW_TYPE:  return _spriteManager->_dYellowFalling0007; break;
                case PANEL_GREEN_TYPE:   return _spriteManager->_dGreenFalling0007; break;
                case PANEL_PURPLE_TYPE:  return _spriteManager->_dPurpleFalling0007; break;
            }
        break;
        case PANEL_FALL_FRAME_8:
            switch (type)
            {
                case PANEL_RED_TYPE:     return _spriteManager->_dRedFalling0008; break;
                case PANEL_CYAN_TYPE:    return _spriteManager->_dBlueFalling0008; break;
                case PANEL_YELLOW_TYPE:  return _spriteManager->_dYellowFalling0008; break;
                case PANEL_GREEN_TYPE:   return _spriteManager->_dGreenFalling0008; break;
                case PANEL_PURPLE_TYPE:  return _spriteManager->_dPurpleFalling0008; break;
            }
        break;
        case PANEL_FALL_FRAME_9:
            switch (type)
            {
                case PANEL_RED_TYPE:     return _spriteManager->_dRedFalling0009; break;
                case PANEL_CYAN_TYPE:    return _spriteManager->_dBlueFalling0009; break;
                case PANEL_YELLOW_TYPE:  return _spriteManager->_dYellowFalling0009; break;
                case PANEL_GREEN_TYPE:   return _spriteManager->_dGreenFalling0009; break;
                case PANEL_PURPLE_TYPE:  return _spriteManager->_dPurpleFalling0009; break;
            }
        break;
        case PANEL_FALL_FRAME_10:
            switch (type)
            {
                case PANEL_RED_TYPE:     return _spriteManager->_dRedFalling0010; break;
                case PANEL_CYAN_TYPE:    return _spriteManager->_dBlueFalling0010; break;
                case PANEL_YELLOW_TYPE:  return _spriteManager->_dYellowFalling0010; break;
                case PANEL_GREEN_TYPE:   return _spriteManager->_dGreenFalling0010; break;
                case PANEL_PURPLE_TYPE:  return _spriteManager->_dPurpleFalling0010; break;
            }
        break;
    }
    return NULL;
}

void Board::Swap ()
{
    //stringstream ss;
    // ss<<_boardLogic[_cursorPosition.getY()][_cursorPosition.getX()]->_state<<" "<<_boardLogic[_cursorPosition.getY()][_cursorPosition.getX() + 1]->_state<<endl;
    //Debug::Log(ss.str());
    if (_isSwapping)
        return;
    
    _rules->Swap(_boardLogic, _dimensions.getWidth(), _dimensions.getHeight(), _changes, &_cursorPosition);
}

void Board::SpeedUp()
{
    _rules->SpeedUp();
}

void Board::Detect()
{
    _rules->Detect(_boardLogic, _dimensions.getWidth(), _dimensions.getHeight(), _changes, _garbageList);
}

void Board::Fall()
{
    _rules->Fall(_boardLogic, _dimensions.getWidth(), _dimensions.getHeight(), _changes, _garbageList);
}

void Board::UpdateGraphics ()
{
    CompleteSwap();
}

void Board::ClearGarbageData (LogicPanel * panel)
{
    panel->_sourceX = -1;
    panel->_sourceY = -1;
    panel->_width = 0;
    panel->_height = 0;
    panel->_positionX = -1;
    panel->_positionY = -1;
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
