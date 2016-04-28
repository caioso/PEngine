#ifndef __BOARD__
#define __BOARD__

// Engine includes
#include "../../engine/engine.hpp"

// Required includes
#include "types/panel.hpp"
#include "types/logic_panel.hpp"
#include "types/changes.hpp"
#include "cursor.hpp"
#include "rules/rules_interface.hpp"
#include "sprite_manager.hpp"
#include "board_constants.hpp"

// Board class centers everything regarding rules and board presentation.
// Animations are also defined in this class.
class Board
{
    // Graphics Elements
    private: Panel *** _boardGraphics;
    private: Panel ** _nextRowGraphics;
    private: LogicPanel *** _boardLogic;
    private: LogicPanel ** _nextRowLogic;
    private: Dim2D _dimensions;
    private: Point2D _position;
    private: Cursor * _cursor;
    private: RulesInterface * _rules;
    private: vector<Change> _changes;
    private: vector<LogicPanel **> _garbageList;
    private: Sprite * _boardContainer;
    private: Sprite * _nextRowContainer;
    private: unsigned int _cursorFrame;
    private: bool _changeCursorFrame;
    private: SpriteManager * _spriteManager;
    
    // Control Elements
    private: Point2D _cursorPosition;

    // Default Constructor, Builds a random set of panels, based on the
    // dimension provided as argument. The board origin point is determined
    // by pos argument.
    // @param dim: the number of rows and columns in the board.
    // @param pos: the origin point used as reference for the board
    // coordinate system.
    // @param cur_pos: Initial cursor position.
    public: Board(RulesInterface * _rules, Dim2D dim, Point2D pos, Point2D cur_pos, int initial_height);

    // Updates cursor position and graphics position based on a point.
    // This method also update sthe cursor animation frames.
    // @param pos: relative position object, each unity in pos object
    // actually represents a columna and a row, which will be converted
    // to actual pixel values, in the function.
    public: void UpdateCursorPosition(Point2D pos);
    
    // Swap two panels based on the rules specification.
    public: void Swap();
    
    // Update Board Graphics once at each frame. Uses change operation language to
    // parse each change the rules have commited and update the frame
    // accordingly.
    public: void InterpretOperations();
    
    // Detect combos in the board and promp the related panels to be broken.
    public: void Detect();

    // Update panel position (vertically) to make the ilusion of gravity.
    public: void Fall();
    
    // Update board update movement (Slide up/down depending on the rule).
    public: void Slide();
    
    // Increases slide speed on key pressed
    public: void SpeedUp();
    
    // Reduces slide speed on key released.
    public: void SlowDown();
    
    // Decodes a type and returns the buffer related to the type.
    // @param type: panel type to be decode.
    // @param style: panel image type.
    // @return Texture reference.
    private: GRRLIB_texImg * DecodeType (unsigned int type, unsigned int style = PANEL_NORMAL_SPRITE);

    // Returns current cursor position.
    // @return Point2D: current cursor position.
    public: Point2D getCursorPosition() { return _cursorPosition; }
    
    // Create new garbages of given size on a given position.
    // @param width: Garbage width. This will stack up rows as the garbage size dont fit the row.
    // @param height: Garbage height.
    // @param position: initial garbage position.
    public: void MakeGargabe (unsigned int width, unsigned int height, unsigned int position);
    
    public: void FallGarbage ();

    // Debug function to drop garbage in the board.
    public: void DEBUGGarbage ();
    
    // Instantates System matrices.
    private: void InstantiateMatrices ();
    
    // Return a panel type different from a previous type.
    // Note: The number of types is meant to change in the future, as other dificulty modes are added.
    // @param previous: previous type. The return type is guaranteed to be different from previous.
    // @param above: above type. The return type is guaranteed to be different from panel above.
    // @param mode: Number of panels to be considered in the random selection.
    // @return random type without repetition.
    private: char GetNextTypeWithoutRepetition (char previous, char above = PANEL_VOID_TYPE, int mode = EASY_MODE_PANEL_NUM);
    
    // Instantiates the main game matrices (board and next row) and intializes their logic and graphics.
    // @param initial_height: Initial board height. Only this amount of rows are initialized.
    private: void InstantiateAndIntializeGameMatrices(int initial_height);
    
    // Initializes cursor objects and set its correct position on screen.
    private: void InitializeCursor ();
    
    // Implements Swap Operation.
    // @param change: Change operation binary code.
    private: void SwapOperation(Change change);
    
    // Implements Destroy Operation
    // @param change: Change operation binary code.
    private: void DestroyOperation(Change change);
    
    // Implements Fall Operation
    // @param change: Change operation binary code.
    private: void FallOperation (Change change);
    
    // Implements Panel Graphics Style
    // @param change: Change operation binary code.
    private: void PanelGraphicsStyleOperation(Change change);
    
    // Implements Transport Operation
    private: void TransportOperation ();
    
    // Implements Garbage Operation
    // @param change: Change operation binary code.
    private: void GarbageOperation(Change change);

    // Implements Transform Garbage Operation
    // @param change: Change operation binary code.
    private: void TransformGarbageOperation(Change change);
    
    private: void MakeConcreteGargabe ();
    
    // Helper function: Ignore garbage only information in a logic panel object.
    // @param panel: target logic panel.
    private: void ClearGarbageData (LogicPanel * panel);
    
    // Default Constructor
    public: ~Board ();
};

#endif // __BOARD__
