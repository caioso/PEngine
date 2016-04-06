#ifndef __NORMAL_RULES__
#define __NORMAL_RULES__

#include "rules_interface.hpp"
#include "../types/changes.hpp"
#include "../types/logic_panel.hpp"


typedef struct WorkPanel_t
{
    int _type;
    int _state;
    int _positionX;
    int _positionY;
    int _sourceX;
    int _sourceY;
    int _width;
    int _height;
}
WorkPanel;

class NormalRules : public RulesInterface
{
    enum Direction {up, down, left, right};
    
    std::vector<Point2D> _foundVertical;
    std::vector<Point2D> _foundHorizontal;
    bool ** __checkBoard;
    WorkPanel ** __fallCheckBoard;
    int _boardVerticalPosition;
    int _targetDelay;
    int _currentDelay;
    
    public: NormalRules (Dim2D boardDim)
    {
        __checkBoard = new bool * [boardDim.getHeight()];
        __fallCheckBoard = new WorkPanel * [boardDim.getHeight()];
        for (unsigned int i = 0; i < boardDim.getHeight(); i++)
        {
            __checkBoard[i] = new bool[boardDim.getWidth()];
            __fallCheckBoard[i] = new WorkPanel[boardDim.getWidth()];
        }
        
        _boardVerticalPosition = 0;
        _targetDelay = 20;
        _currentDelay = 0;
    }

    // Implements Swap logic.
    // @param changes: Reference to changes array.
    // @param cursorPosition: Refence to current cursor position.
    public: void Swap (LogicPanel *** _boardLogic, int boardW, int boardH, std::vector<Change> &changes, Point2D *cursorPosition)
    {
        if (_boardLogic[cursorPosition->getY()][cursorPosition->getX()]->_type == 5 ||
            _boardLogic[cursorPosition->getY()][cursorPosition->getX() + 1]->_type == 5)
            return;
        if (_boardLogic[cursorPosition->getY()][cursorPosition->getX()]->_state == 3 ||
            _boardLogic[cursorPosition->getY()][cursorPosition->getX() + 1]->_state == 3)
            return;

        Change __swap = 0;
        __swap = AddChangeType(__swap, SWAP_OPERATION);
        __swap = AddTargetPanelX(__swap, cursorPosition->getX());
        __swap = AddTargetPanelY(__swap, cursorPosition->getY());
        __swap = AddDestinationPanelX(__swap, (cursorPosition->getX() + 1));
        __swap = AddDestinationPanelY(__swap, (cursorPosition->getY()));
        changes.push_back(__swap);
        return;
    };
    
    public: void Detect (LogicPanel *** boardLogic, int boardW, int boardH, vector<Change> &changes)
    {
        // Valid Panel list (those in more groups with more than 3 panels).
        std::vector<Point2D> __validVertical;
        std::vector<Point2D> __validHorizontal;
        
        // Panel checkboard
        for (int i = 0; i < boardH; i++)
        {
            for (int j = 0; j < boardW; j++)
                __checkBoard[i][j] = false;
        }
        
        for (int i = 0; i < boardH; i++)
        {
            for (int j = 0; j < boardW; j++)
            {
                DetectVertical(boardLogic, boardLogic[i][j]->_type, i, j, down, boardW, boardH);
                DetectHorizontal(boardLogic, boardLogic[i][j]->_type, i, j, right, boardW, boardH);
                
                if (_foundVertical.size() >= 3)
                {
                    for (unsigned int k = 0; k < _foundVertical.size(); k++)
                        __checkBoard[_foundVertical[k].getX()][_foundVertical[k].getY()] = true;
                }
                
                if (_foundHorizontal.size() >= 3)
                {
                    for (unsigned int k = 0; k < _foundHorizontal.size(); k++)
                        __checkBoard[_foundHorizontal[k].getX()][_foundHorizontal[k].getY()] = true;
                }
                
                _foundVertical.clear();
                _foundHorizontal.clear();
            }
        }
        
        for (int i = 0; i < boardH; i++)
            for (int j = 0; j < boardW; j++)
                if (boardLogic[i][j]->_state == 3)
                {
                    if (boardLogic[i][j]->_wait == 0)
                    {
                        Change __change = 0;
                        __change = AddChangeType(__change, DESTROY_OPERATION);
                        __change = AddTargetPanelX(__change, j);
                        __change = AddTargetPanelY(__change, i);
                        changes.push_back(__change);
                    }
                    else
                    {
                        boardLogic[i][j]->_wait--;
                        Change __change = 0;
                        __change = AddChangeType(__change, PANEL_GRAPHICS_STYLE_OPERATION);
                        if (boardLogic[i][j]->_wait%6 >= 3)
                            __change = AddPanelImageStyle(__change, PANEL_NORMAL_SPRITE);
                        else
                            __change = AddPanelImageStyle(__change, PANEL_BRIGHT_SPRITE);
                        __change = AddTargetPanelX(__change, j);
                        __change = AddTargetPanelY(__change, i);
                        changes.push_back(__change);
                    }
                }
        
        for (int i = 0; i < boardH; i++)
            for (int j = 0; j < boardW; j++)
                if (__checkBoard[i][j])
                {
                    boardLogic[i][j]->_state = 3;
                    boardLogic[i][j]->_wait = 20;
                }
    }
    
    // Detect combinations in vertical direction.
    // @param i: row index.
    // @param j: column index.
    private: void DetectVertical (LogicPanel *** boardLogic, int type, int i, int j, Direction dir, int boardW, int boardH)
    {
        if (boardLogic[i][j]->_state == 3)
            return;
        if (i != boardH - 1 && boardLogic[i + 1][j]->_type == -1)
            return;
        if (boardLogic[i][j]->_type != type || boardLogic[i][j]->_type == -1 || boardLogic[i][j]->_type == 5 || boardLogic[i][j]->_state == 1)
        {
            return;
        }
        else
        {
            Point2D _point(i, j);
            _foundVertical.push_back(_point);
            if (dir != up && i != boardH - 1)
                DetectVertical(boardLogic, type, i + 1, j, down, boardW, boardH);
            if (dir != down && i != 0)
                DetectVertical(boardLogic, type, i - 1,j, up, boardW, boardH);
            return;

        }
    }
    
    // Detect combinations in vertical direction.
    // @param i: row index.
    // @param j: column index.
    private: void DetectHorizontal (LogicPanel *** boardLogic, int type, int i, int j, Direction dir, int boardW, int boardH)
    {
        if (boardLogic[i][j]->_state == 3)
            return;
        if (i != boardH - 1 && boardLogic[i + 1][j]->_type == -1)
            return;
        if (boardLogic[i][j]->_type != type || boardLogic[i][j]->_type == -1 || boardLogic[i][j]->_type == 5 || boardLogic[i][j]->_state == 1)
        {
            return;
        }
        else
        {
            Point2D _point(i, j);
            _foundHorizontal.push_back(_point);
            if (dir != left && j != boardW - 1)
                DetectHorizontal(boardLogic, type, i, j + 1, right, boardW, boardH);
            if (dir != right && j != 0)
                DetectHorizontal(boardLogic, type, i, j - 1, left, boardW, boardH);
            return;
            
        }
    }
    
    // Implements fall logic. Sweeps the board for panels in falling condition and update those
    // already falling.
    // @param _boardLogic: Pointer to logic board.
    // @param boardW: Board Width.
    // @param boardH: Board Height.
    // @param changes: change array.
    public: void Fall (LogicPanel *** _boardLogic, int boardW, int boardH, vector<Change> &changes)
    {
        for (int i = 0; i < boardH; i++)
            for (int j = 0; j < boardW; j++)
            {
                __fallCheckBoard[i][j]._type = _boardLogic[i][j]->_type;
                __fallCheckBoard[i][j]._state = _boardLogic[i][j]->_state;
                __fallCheckBoard[i][j]._positionX = _boardLogic[i][j]->_positionX;
                __fallCheckBoard[i][j]._positionY = _boardLogic[i][j]->_positionY;
                __fallCheckBoard[i][j]._sourceX = _boardLogic[i][j]->_sourceX;
                __fallCheckBoard[i][j]._sourceY = _boardLogic[i][j]->_sourceY;
                __fallCheckBoard[i][j]._width = _boardLogic[i][j]->_width;
                __fallCheckBoard[i][j]._height = _boardLogic[i][j]->_height;
            }
        
        // Detect Potential falls
        for (int i = boardH - 1; i >= 0; i--)
        {
            for (int j = 0; j < boardW; j++)
            {
                if (i != boardH - 1)
                {
                    // Start fall
                    if (__fallCheckBoard[i][j]._type != -1 && __fallCheckBoard[i][j]._state == 0 && __fallCheckBoard[i + 1][j]._type == -1)
                    {
                        if (__fallCheckBoard[i][j]._type != 5)
                        {
                            Change __fall = 0;
                            __fall = AddChangeType(__fall, FALL_OPERATION);
                            __fall = AddTargetPanelX(__fall, j);
                            __fall = AddTargetPanelY(__fall, i);
                            changes.push_back(__fall);
                            
                            // Update local work boards
                            __fallCheckBoard[i + 1][j]._type= __fallCheckBoard[i][j]._type;
                            __fallCheckBoard[i + 1][j]._state = __fallCheckBoard[i][j]._state;
                            __fallCheckBoard[i + 1][j]._positionX = __fallCheckBoard[i][j]._positionX;
                            __fallCheckBoard[i + 1][j]._positionY = __fallCheckBoard[i][j]._positionY;
                            __fallCheckBoard[i + 1][j]._sourceX = __fallCheckBoard[i][j]._sourceX;
                            __fallCheckBoard[i + 1][j]._sourceY = __fallCheckBoard[i][j]._sourceY;
                            __fallCheckBoard[i + 1][j]._width = __fallCheckBoard[i][j]._width;
                            __fallCheckBoard[i + 1][j]._height = __fallCheckBoard[i][j]._height;
                            
                            __fallCheckBoard[i][j]._type = -1;
                            __fallCheckBoard[i][j]._state = -1;
                            __fallCheckBoard[i][j]._positionX = -1;
                            __fallCheckBoard[i][j]._positionY = -1;
                            __fallCheckBoard[i][j]._sourceX = -1;
                            __fallCheckBoard[i][j]._sourceY = -1;
                            __fallCheckBoard[i][j]._width = -1;
                            __fallCheckBoard[i][j]._height = -1;

                        }
                        else
                        {
                            bool __canFall = CanGarbageFall (i, j);
                            int __width = __fallCheckBoard[i][j]._width;
                            if (__canFall)
                                FallGarbage(i, j, changes);

                            //j += __width - 1;
                        }
                    }
                    // Update fall
                    else if (__fallCheckBoard[i][j]._type != -1 && __fallCheckBoard[i][j]._state == 1 && __fallCheckBoard[i + 1][j]._type == -1)
                    {
                        if (__fallCheckBoard[i][j]._type != 5)
                        {
                            Change __fall = 0;
                            __fall = AddChangeType(__fall, FALL_OPERATION);
                            __fall = AddTargetPanelX(__fall, j);
                            __fall = AddTargetPanelY(__fall, i);
                            changes.push_back(__fall);
                            
                            // Update local work boards
                            __fallCheckBoard[i + 1][j]._type= __fallCheckBoard[i][j]._type;
                            __fallCheckBoard[i + 1][j]._state = __fallCheckBoard[i][j]._state;
                            __fallCheckBoard[i + 1][j]._positionX = __fallCheckBoard[i][j]._positionX;
                            __fallCheckBoard[i + 1][j]._positionY = __fallCheckBoard[i][j]._positionY;
                            __fallCheckBoard[i + 1][j]._sourceX = __fallCheckBoard[i][j]._sourceX;
                            __fallCheckBoard[i + 1][j]._sourceY = __fallCheckBoard[i][j]._sourceY;
                            __fallCheckBoard[i + 1][j]._width = __fallCheckBoard[i][j]._width;
                            __fallCheckBoard[i + 1][j]._height = __fallCheckBoard[i][j]._height;
                            
                            __fallCheckBoard[i][j]._type = -1;
                            __fallCheckBoard[i][j]._state = -1;
                            __fallCheckBoard[i][j]._positionX = -1;
                            __fallCheckBoard[i][j]._positionY = -1;
                            __fallCheckBoard[i][j]._sourceX = -1;
                            __fallCheckBoard[i][j]._sourceY = -1;
                            __fallCheckBoard[i][j]._width = -1;
                            __fallCheckBoard[i][j]._height = -1;
                        }
                        else
                        {
                            bool __canFall = CanGarbageFall (i, j);
                            int __width = __fallCheckBoard[i][j]._width;
                            if (__canFall)
                                FallGarbage(i, j, changes);
                            
                            //j += __width - 1;
                        }
                    }
                    // Stop fall
                    else if (__fallCheckBoard[i][j]._type != -1 && __fallCheckBoard[i][j]._state == 1 && __fallCheckBoard[i + 1][j]._type != -1)
                    {
                        _boardLogic[i][j]->_state = 0;
                        __fallCheckBoard[i][j]._state = 0;
                    }
                }
                else
                {
                    // Stop fall hit the last line
                    if (__fallCheckBoard[i][j]._state == 1)
                    {
                        _boardLogic[i][j]->_state = 0;
                        __fallCheckBoard[i][j]._state = 0;
                    }
                }
            }
        }
    }
    
    private: void CopyLogicPanel (LogicPanel * target, LogicPanel * source)
    {
        target->_type = source->_type;
        target->_state = source->_state;
        target->_wait = source->_wait;
        target->_positionX = source->_positionX;
        target->_positionY = source->_positionY;
        target->_sourceX = source->_sourceX;
        target->_sourceY = source->_sourceY;
        target->_width = source->_width;
        target->_height = source->_height;
    }
    
    private: void ClearLogicPanel (LogicPanel * target)
    {
        target->_type = -1;
        target->_state = 0;
        target->_wait = 0;
        target->_positionX = 0;
        target->_positionY = 0;
        target->_sourceX = 0;
        target->_sourceY = 0;
        target->_width = 0;
        target->_height = 0;
    }
    
    private: bool CanGarbageFall (int i, int j)
    {
        for (int k = __fallCheckBoard[i][j]._sourceX; k < __fallCheckBoard[i][j]._sourceX + __fallCheckBoard[i][j]._width; k++)
        {
            if (__fallCheckBoard[i + 1][k]._type != -1)
            {
                return false;
            }
        }
        return true;
    }
    
    private: void FallGarbage (int i, int j, vector<Change> &changes)
    {
        int __initialIndex = __fallCheckBoard[i][j]._sourceX;
        int __lastIndex = __fallCheckBoard[i][j]._sourceX + __fallCheckBoard[i][j]._width;
        for (int k = __initialIndex; k < __lastIndex; k++)
        {
            Change __fall = 0;
            __fall = AddChangeType(__fall, FALL_OPERATION);
            __fall = AddTargetPanelX(__fall, k);
            __fall = AddTargetPanelY(__fall, i);
            changes.push_back(__fall);
            
            __fallCheckBoard[i + 1][k]._type= __fallCheckBoard[i][k]._type;
            __fallCheckBoard[i + 1][k]._state = __fallCheckBoard[i][k]._state;
            __fallCheckBoard[i + 1][k]._positionX = __fallCheckBoard[i][k]._positionX;
            __fallCheckBoard[i + 1][k]._positionY = __fallCheckBoard[i][k]._positionY;
            __fallCheckBoard[i + 1][k]._sourceX = __fallCheckBoard[i][k]._sourceX;
            __fallCheckBoard[i + 1][k]._sourceY = __fallCheckBoard[i][k]._sourceY + 1;
            __fallCheckBoard[i + 1][k]._width = __fallCheckBoard[i][k]._width;
            __fallCheckBoard[i + 1][k]._height = __fallCheckBoard[i][k]._height;
            
            __fallCheckBoard[i][k]._type = -1;
            __fallCheckBoard[i][k]._state = -1;
            __fallCheckBoard[i][k]._positionX = -1;
            __fallCheckBoard[i][k]._positionY = -1;
            __fallCheckBoard[i][k]._sourceX = -1;
            __fallCheckBoard[i][k]._sourceY = -1;
            __fallCheckBoard[i][k]._width = -1;
            __fallCheckBoard[i][k]._height = -1;
        }
    }
    
    /*private: void FallGarbage (LogicPanel *** _boardLogic, int i, int j, int boardW, int boardH, bool shouldFall)
    {
        if (__fallCheckBoard[i][j] || _boardLogic[i][j]->_type != 5)
            return;
        else
        {
            __fallCheckBoard[i][j] = true;
            if (shouldFall)
            {
                _boardLogic[i][j]->_state = 1;
                _boardLogic[i][j]->_wait = 0;
            }
            else
            {
                _boardLogic[i][j]->_state = 0;
                _boardLogic[i][j]->_wait = 0;
            }
            
            if (_boardLogic[i][j]->_right != NULL)
                FallGarbage (_boardLogic, i, j + 1, boardW, boardH, shouldFall);
            if (_boardLogic[i][j]->_up != NULL)
                FallGarbage (_boardLogic, i - 1, j, boardW, boardH, shouldFall);
            if (_boardLogic[i][j]->_left != NULL)
                FallGarbage (_boardLogic, i, j - 1, boardW, boardH, shouldFall);
            if (_boardLogic[i][j]->_down != NULL)
                FallGarbage (_boardLogic, i + 1, j, boardW, boardH, shouldFall);
        }
    }*/
    
    public: void SpeedUp()
    {
        _targetDelay = 1;
    }
    
    public: void SlowDown()
    {
        _targetDelay = 20;
    }
    
    public: void Slide (LogicPanel *** _boardLogic, int boardW, int boardH, std::vector<Change> &changes, Sprite * board)
    {
         if (_currentDelay >= _targetDelay)
         {
             _currentDelay = 0;
             _boardVerticalPosition++;
             if (_boardVerticalPosition == 28)
             {
                 _boardVerticalPosition = 0;
                 
                 Change __change = 0;
                 __change = AddChangeType(__change, TRANSPORT_OPERATION);
                 changes.push_back(__change);
             }
             else
                 board->_y--;
         }
        else
        {
            _currentDelay++;
        }
    }
    
    public: ~NormalRules () {};
};

#endif // __NORMAL_RULES__
