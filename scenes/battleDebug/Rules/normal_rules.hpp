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
    bool ** __checkBoard;
    int _boardVerticalPosition;
    int _targetDelay;
    int _currentDelay;
    
    public: NormalRules (Dim2D boardDim)
    {
        __checkBoard = new bool * [boardDim.getHeight()];
        for (unsigned int i = 0; i < boardDim.getHeight(); i++)
            __checkBoard[i] = new bool [boardDim.getWidth()];
        
        _boardVerticalPosition = 0;
        _targetDelay = 20;
        _currentDelay = 0;
    }
    
    // Implements Swap logic.
    // @param changes: Reference to changes array.
    // @param cursorPosition: Refence to current cursor position.
    public: void Swap (LogicPanel *** _boardLogic, int boardW, int boardH, std::vector<Change> &changes, Point2D *cursorPosition)
    {
        if (_boardLogic[cursorPosition->getY()][cursorPosition->getX()]->_state == 3 ||
            _boardLogic[cursorPosition->getY()][cursorPosition->getX() + 1]->_state == 3)
            return;
        if ((int)cursorPosition->getY() < boardH - 1 &&
            _boardLogic[cursorPosition->getY()][cursorPosition->getX()]->_type != -1 &&
            _boardLogic[cursorPosition->getY() + 1][cursorPosition->getX()]->_type == -1)
            return;
        if ((int)cursorPosition->getY() < boardH - 1 &&
            _boardLogic[cursorPosition->getY()][cursorPosition->getX() + 1]->_type != -1 &&
            _boardLogic[cursorPosition->getY() + 1][cursorPosition->getX() + 1]->_type == -1)
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
                
                _foundVertical.resize(0);
                _foundHorizontal.resize(0);
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
        if (boardLogic[i][j]->_type != type || boardLogic[i][j]->_type == -1 || boardLogic[i][j]->_state == 1)
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
        if (boardLogic[i][j]->_type != type || boardLogic[i][j]->_type == -1 || boardLogic[i][j]->_state == 1)
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
        for (int i = boardH - 1; i >= 0; i--)
        {
            for (int j = 0; j < boardW; j++)
            {
                if (_boardLogic[i][j]->_state == 3)
                    continue;
                if (_boardLogic[i][j]->_wait != 0)
                {
                    _boardLogic[i][j]->_wait--;
                    continue;
                }

                if (i == boardH - 1)
                {
                    _boardLogic[i][j]->_state = 0;
                    continue;
                }
                if (_boardLogic[i + 1][j]->_type == -1 && _boardLogic[i][j]->_type != -1 && !__checkBoard[i][j])
                {
                    _boardLogic[i][j]->_state = 1;
                    for (int k = i; k >= 0; k--)
                    {
                        if (_boardLogic[k][j]->_type == -1)
                            break;
                        
                        Change __change = 0;
                        __change = AddChangeType(__change, FALL_OPERATION);
                        __change = AddTargetPanelX(__change, j);
                        __change = AddTargetPanelY(__change, k);
                        changes.push_back(__change);
                        _boardLogic[k][j]->_state = 1;
                    }
                }
                else if (_boardLogic[i + 1][j]->_type != -1 && _boardLogic[i][j]->_state == 1)
                {
                    for (int k = i; k >= 0; k--)
                    {
                        _boardLogic[k][j]->_state = 0;
                        if (_boardLogic[k][j]->_type == -1)
                            break;
                    }
                }
            }
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
             if (_boardVerticalPosition == 32)
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
