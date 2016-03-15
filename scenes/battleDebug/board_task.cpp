#include "board_task.hpp"

#define WII 0
#define MAC 1

BoardTask::BoardTask (std::string board_name,
                      Dim2D board_dim,
                      Point2D board_pos,
                      Point2D cursor_pos,
                      char player_number)
{
    // For Now, We'll include normal rules
    NormalRules * _rules = new NormalRules(board_dim);
    _board_name = board_name;
    _board = new Board(dynamic_cast<RulesInterface*>(_rules), board_dim, board_pos, cursor_pos);

    // Configure Wiimotes
    _remote = new Controller(player_number);
    // Register Controller
    InputManager::RegisterController(_remote);
}

void BoardTask::Start ()
{
    srand(time(0));
    //Debug::LogWarning("Board Started.");
}

void BoardTask::Update ()
{
    Point2D _cursor_position = _board->getCursorPosition();
#if MAC
    if (_remote->CheckKeysOR(PPL_KEY_DOWN, 1, PPL_BUTTON_B))
        _board->SpeedUp();
    else
    {
        if (_remote->CheckKeysOR(PPL_KEY_DOWN, 1, PPL_BUTTON_LEFT))
          _cursor_position.setX(_cursor_position.getX() - 1);
        else if (_remote->CheckKeysOR(PPL_KEY_DOWN, 1, PPL_BUTTON_RIGHT))
          _cursor_position.setX(_cursor_position.getX() + 1);

        if (_remote->CheckKeysOR(PPL_KEY_DOWN, 1, PPL_BUTTON_UP))
          _cursor_position.setY(_cursor_position.getY() - 1);
        else if (_remote->CheckKeysOR(PPL_KEY_DOWN, 1, PPL_BUTTON_DOWN))
          _cursor_position.setY(_cursor_position.getY() + 1);
        
        if (_remote->CheckKeysOR(PPL_KEY_DOWN, 1, PPL_BUTTON_A))
            _board->Swap();
    }
    
    if (_remote->CheckKeysOR(PPL_KEY_UP, 1, PPL_BUTTON_B))
        _board->SlowDown();
    
#endif
#if WII
    if (_remote->CheckKeysOR(PPL_KEY_DOWN, 1, PPL_BUTTON_1))
        _board->SpeedUp();
    else
    {
        if (_remote->CheckKeysOR(PPL_KEY_DOWN, 1, PPL_BUTTON_UP ))
            _cursor_position.setX(_cursor_position.getX() - 1);
        else if (_remote->CheckKeysOR(PPL_KEY_DOWN, 1, PPL_BUTTON_DOWN))
            _cursor_position.setX(_cursor_position.getX() + 1);
        
        if (_remote->CheckKeysOR(PPL_KEY_DOWN, 1, PPL_BUTTON_RIGHT))
            _cursor_position.setY(_cursor_position.getY() - 1);
        else if (_remote->CheckKeysOR(PPL_KEY_DOWN, 1, PPL_BUTTON_LEFT))
            _cursor_position.setY(_cursor_position.getY() + 1);
        
        if (_remote->CheckKeysOR(PPL_KEY_DOWN, 1, PPL_BUTTON_2))
            _board->Swap();
    }
    
    if (_remote->CheckKeysOR(PPL_KEY_UP, 1, PPL_BUTTON_1))
        _board->SlowDown();
#endif

    _board->UpdateCursorPosition(_cursor_position);
    _board->BindLogic();
    _board->Detect();
    _board->BindLogic();
    _board->Fall();
    _board->BindLogic();
    _board->Slide();
    _board->BindLogic();
}

void BoardTask::End ()
{
    Debug::LogWarning("Board Finished.");
}
