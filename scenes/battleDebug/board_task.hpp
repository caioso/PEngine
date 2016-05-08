#ifndef __BOARD_TASK__
#define __BOARD_TASK__

#include "../../engine/engine.hpp"

// Custom Includes
#include "board.hpp"
#include "rules/normal_rules.hpp"

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
                       char player_number);

    // Required Methods
    // Initializes control variable
    public: void Start ();

    // Update Counter
    public: void Update ();

    // Prints finalization text
    public: void End ();
};

#endif // __BOARD_TASK__
