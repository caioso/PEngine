#pragma once
#ifndef __BOARD_TASK__
#define __BOARD_TASK__

// Dev Constants
#define WII 1
#define MAC 0

#include "../../engine/engine.hpp"

// Custom Includes
#include "board.hpp"
#include "rules/normal_rules.hpp"
#include "sprite_manager.hpp"
#include "animation_manager.hpp"

// Debug Audio
#include "../../assets/audio/move.h"
#include "../../assets/audio/swapfx.h"


class BoardTask : public Runnable
{
    // Custom Attributes
    public: std::string _board_name;
    private: Board * _board;
    private: Controller * _remote;
    
    //Debug
    private: Sound * _move;
    private: Sound * _swap;

    // Custom Methods
    // Prepares the board objects for further initializaiton
    // @param board_name: Textual identifier for the board.
    // @param board_dim: Number of rows and columns in the board.
    // @param board_pos: Board coordinate system origin.
    // @param cursor_pos: Cursor initial position (in rows and columns);
    public: BoardTask (std::string board_name,
                       Dim2D board_dim,
                       Point2D board_pos,
                       Point2D cursor_pos,
                       char player_number,
                       SpriteManager * spriteManager,
                       AnimationManager * animationManager)
    {
        // Configure Wiimotes
        _remote = new Controller(player_number);
        // Register Controller
        InputManager::RegisterController(_remote);
        
        // For Now, We'll include normal rules
        NormalRules * _rules = new NormalRules(board_dim);
        _board_name = board_name;
        _board = new Board(dynamic_cast<RulesInterface*>(_rules), board_dim, board_pos, cursor_pos, 6, spriteManager, animationManager, _remote);
        
        // Register Sound Effects
        _swap = new Sound(swapfx, swapfx_size, 1, 48000);
        _move = new Sound(move, move_size, 1, 48000);
        
        // Initialize Cursor.
        _board->InitializeCursor();
    }

    // Required Methods
    // Initializes control variable
    public: void Start ()
    {
        //Debug::LogWarning("Board Started.");
    }

    // Update Counter
    public: void Update ()
    {
        Point2D _cursor_position = _board->getCursorPosition();
#if MAC
        ManageInputMac(&_cursor_position);
#endif
#if WII
        ManageInputWii(&_cursor_position);
#endif
        
        // Run Board Script loop;
        _board->UpdateGraphics();
        _board->UpdateCursorPosition(_cursor_position);
        _board->InterpretOperations();
        _board->Detect();
        _board->InterpretOperations();
        _board->Fall();
        _board->InterpretOperations();
        _board->FallGarbage();
        _board->Slide();
        _board->InterpretOperations();
    }

    // Prints finalization text
    public: void End ()
    {
        Debug::LogWarning("Board Finished.");
    }
    
    // Custom methods
#if MAC
    private: void ManageInputMac (Point2D *_cursor_position)
    {
        if (_remote->CheckKeysOR(PPL_KEY_DOWN, 1, PPL_BUTTON_LEFT))
        {
            _cursor_position->setX(_cursor_position->getX() - 1);
            AudioEngine::PlaySFX(_move);
        }
        else if (_remote->CheckKeysOR(PPL_KEY_DOWN, 1, PPL_BUTTON_RIGHT))
        {
            _cursor_position->setX(_cursor_position->getX() + 1);
            AudioEngine::PlaySFX(_move);
        }
        
        if (_remote->CheckKeysOR(PPL_KEY_DOWN, 1, PPL_BUTTON_UP))
        {
            _cursor_position->setY(_cursor_position->getY() - 1);
            AudioEngine::PlaySFX(_move);
        }
        else if (_remote->CheckKeysOR(PPL_KEY_DOWN, 1, PPL_BUTTON_DOWN))
        {
            _cursor_position->setY(_cursor_position->getY() + 1);
            AudioEngine::PlaySFX(_move);
        }
        
        if (_remote->CheckKeysOR(PPL_KEY_DOWN, 1, PPL_BUTTON_A))
        {
            _board->Swap();
            AudioEngine::PlaySFX(_swap);
        }
        
        if (_remote->CheckKeysOR(PPL_KEY_HELD, 1, PPL_BUTTON_B))
            _board->SpeedUp();
        
        if (_remote->CheckKeysOR(PPL_KEY_DOWN, 1, PPL_BUTTON_PLUS))
            _board->DEBUGGarbage();
    }
#endif
#if WII
    private: void ManageInputWii (Point2D *_cursor_position)
    {
        if (_remote->CheckKeysOR(PPL_KEY_DOWN, 1, PPL_BUTTON_UP ))
        {
            _cursor_position->setX(_cursor_position->getX() - 1);
            AudioEngine::PlaySFX(_move);
        }
        else if (_remote->CheckKeysOR(PPL_KEY_DOWN, 1, PPL_BUTTON_DOWN))
        {
            _cursor_position->setX(_cursor_position->getX() + 1);
            AudioEngine::PlaySFX(_move);
        }
        
        if (_remote->CheckKeysOR(PPL_KEY_DOWN, 1, PPL_BUTTON_RIGHT))
        {
            _cursor_position->setY(_cursor_position->getY() - 1);
            AudioEngine::PlaySFX(_move);
        }
        else if (_remote->CheckKeysOR(PPL_KEY_DOWN, 1, PPL_BUTTON_LEFT))
        {
            _cursor_position->setY(_cursor_position->getY() + 1);
            AudioEngine::PlaySFX(_move);
        }
        
        if (_remote->CheckKeysOR(PPL_KEY_DOWN, 1, PPL_BUTTON_2))
        {
            _board->Swap();
            AudioEngine::PlaySFX(_swap);
        }
        
        if (_remote->CheckKeysOR(PPL_KEY_HELD, 1, PPL_BUTTON_1))
            _board->SpeedUp();
        
        if (_remote->CheckKeysOR(PPL_KEY_DOWN, 1, WPAD_BUTTON_HOME))
            exit(0);
        
        if (_remote->CheckKeysOR(PPL_KEY_DOWN, 1, PPL_BUTTON_PLUS))
            _board->DEBUGGarbage();
    }
#endif
    
    // Returns the board object stored in the task.
    // return: Internal board reference.
    public: Board * GetBoard () { return _board; }
};

#endif // __BOARD_TASK__
