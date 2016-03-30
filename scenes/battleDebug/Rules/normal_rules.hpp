#ifndef __NORMAL_RULES__
#define __NORMAL_RULES__

#include "rules_interface.hpp"
#include "../types/changes.hpp"
#include "../types/logic_panel.hpp"

class NormalRules : public RulesInterface
{
    enum Direction {up, down, left, right};
    
    std::vector<Point2D> _foundVertical;
    std::vector<Point2D> _foundHorizontal;
    bool ** __checkBoard, ** __fallCheckBoard;
    int _boardVerticalPosition;
    int _targetDelay;
    int _currentDelay;
    
    public: NormalRules (Dim2D boardDim)
    {
        __checkBoard = new bool * [boardDim.getHeight()];
        __fallCheckBoard = new bool * [boardDim.getHeight()];
        for (unsigned int i = 0; i < boardDim.getHeight(); i++)
        {
            __checkBoard[i] = new bool[boardDim.getWidth()];
            __fallCheckBoard [i] = new bool[boardDim.getWidth()];
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
        
        // This is blocking the waiting panel to fall
        /*if ((int)cursorPosition->getY() < boardH - 1 &&
            _boardLogic[cursorPosition->getY()][cursorPosition->getX()]->_type != -1 &&
            _boardLogic[cursorPosition->getY() + 1][cursorPosition->getX()]->_type == -1)
            return;
        if ((int)cursorPosition->getY() < boardH - 1 &&
            _boardLogic[cursorPosition->getY()][cursorPosition->getX() + 1]->_type != -1 &&
            _boardLogic[cursorPosition->getY() + 1][cursorPosition->getX() + 1]->_type == -1)
            return;*/
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
                        if (boardLogic[i][j]->_wait%6 >= 3)
                            __change = AddChangeType(__change, LIGHT_IMAGE);
                        else
                            __change = AddChangeType(__change, NORMAL_IMAGE);
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
        // Falling Checkboard
        for (int i = 0; i < boardH; i++)
        {
            for (int j = 0; j < boardW; j++)
                __fallCheckBoard[i][j] = false;
        }
        
        // Detect Potential falls
        for (int j = 0; j < boardW; j++)
        {
            for (int i = boardH - 1; i >= 0; i--)
            {
                // If the panel is not in the last row and the block below it is empty, make it fall.
                if (_boardLogic[i][j]->_type == -1 && i > 0 && _boardLogic[i][j]->_state == 0)
                {
                    if (__fallCheckBoard[i][j])
                        continue;
                    
                    // Sweep from this panel above to make them all fall.
                    for (int k = i - 1; k >= 0; k--)
                    {
                        if (__fallCheckBoard[k][j])
                            continue;

                        if (_boardLogic[k][j]->_type == -1 || _boardLogic[k][j]->_state != 0)
                            break;
                        
                        if (_boardLogic[k][j]->_type == 5)
                        {
                            bool __shouldFall = CanGarbageFall(_boardLogic, k, j);
                            
                            // If the garbage can fall, make it wait
                            FallGarbage (_boardLogic, k, j, boardW, boardH, __shouldFall);
                        }
                        else
                        {
                            __fallCheckBoard[k][j] = true;
                            _boardLogic[k][j]->_state = 4;
                            _boardLogic[k][j]->_wait = 8;
                        }
                    }
                }
            }
        }
        
        for (int i = 0; i < boardH; i++)
        {
            for (int j = 0; j < boardW; j++)
                __fallCheckBoard[i][j] = false;
        }
        
        // Update Ongoing falls
        for (int j = 0; j < boardW; j++)
        {
            for (int i = boardH - 1; i >= 0; i--)
            {
                if (__fallCheckBoard[i][j])
                    continue;
                
                if (_boardLogic[i][j]->_state == 4)
                {
                    __fallCheckBoard[i][j] = true;
                    _boardLogic[i][j]->_wait--;
                    if (_boardLogic[i][j]->_wait == 0)
                    {
                        _boardLogic[i][j]->_state = 1;
                    }
                }
                else if (_boardLogic[i][j]->_state == 1 && i < boardH - 1 && _boardLogic[i + 1][j]->_type == -1)
                {
                    for (int k = i; k >= 0; k--)
                    {
                        // If garbage, check wether the garbage panels can fall.
                        if (_boardLogic[k][j]->_type == 5)
                        {
                            bool __canFall = CanGarbageFall (_boardLogic, k, j);
                            if (!__canFall)
                            {
                                FallGarbage (_boardLogic, k, j, boardW, boardH, false);
                                break;
                            }
                            else
                            {
                            }
                        }
                                
                        if (_boardLogic[k][j]->_type == -1)
                            break;
                        
                        __fallCheckBoard[k][j] = true;
                        
                        Change __change = 0;
                        __change = AddChangeType(__change, FALL_OPERATION);
                        __change = AddTargetPanelX(__change, j);
                        __change = AddTargetPanelY(__change, k);
                        changes.push_back(__change);
                    }
                }
                else if (_boardLogic[i][j]->_state == 1 && i < boardH - 1 && _boardLogic[i + 1][j]->_type != -1)
                {
                    for (int k = i; k >= 0; k--)
                    {
                        if (_boardLogic[k][j]->_type == -1)
                            break;
                        
                        __fallCheckBoard[k][j] = true;
                        _boardLogic[k][j]->_state = 0;
                    }
                }
                else if (_boardLogic[i][j]->_state == 1 && i == boardH - 1)
                {
                    __fallCheckBoard[i][j] = true;
                    _boardLogic[i][j]->_state = 0;
                }
            }
        }
    }
    
    private: bool CanGarbageFall (LogicPanel *** _boardLogic, int i, int j)
    {
        for (int l = j;; l++)
        {
            if (_boardLogic[i + 1][l]->_type != -1)
                return false;
            if (_boardLogic[i][l]->_right == NULL)
                break;
        }
        
        for (int l = j;; l--)
        {
            if (_boardLogic[i + 1][l]->_type != -1)
                return false;
            if (_boardLogic[i][l]->_left == NULL)
                break;
        }
        
        return true;
    }
    
    private: void FallGarbage (LogicPanel *** _boardLogic, int i, int j, int boardW, int boardH, bool shouldFall)
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
    }
    
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
