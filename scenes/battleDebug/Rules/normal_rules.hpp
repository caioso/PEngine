#ifndef __NORMAL_RULES__
#define __NORMAL_RULES__

#include "rules_interface.hpp"
#include "../types/changes.hpp"
#include "../types/logic_panel.hpp"
#include "../types/work_panel.hpp"

class NormalRules : public RulesInterface
{
    enum Direction {up, down, left, right};
    
    std::vector<Point2D> _foundVertical;
    std::vector<Point2D> _foundHorizontal;
    int ** __checkBoard;
    WorkPanel ** __fallCheckBoard;
    int _boardVerticalPosition;
    int _targetDelay;
    int _currentDelay;
    
    public: NormalRules (Dim2D boardDim)
    {
        __checkBoard = new int * [boardDim.getHeight()];
        __fallCheckBoard = new WorkPanel * [boardDim.getHeight()];
        for (unsigned int i = 0; i < boardDim.getHeight(); i++)
        {
            __checkBoard[i] = new int[boardDim.getWidth()];
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
        if (_boardLogic[cursorPosition->getY()][cursorPosition->getX()]->_type == PANEL_GARBAGE_TYPE ||
            _boardLogic[cursorPosition->getY()][cursorPosition->getX() + 1]->_type == PANEL_GARBAGE_TYPE)
            return;
        if (_boardLogic[cursorPosition->getY()][cursorPosition->getX()]->_type == PANEL_CONCRETE_GARBAGE_TYPE ||
            _boardLogic[cursorPosition->getY()][cursorPosition->getX() + 1]->_type == PANEL_CONCRETE_GARBAGE_TYPE)
            return;
        if (_boardLogic[cursorPosition->getY()][cursorPosition->getX()]->_state == 3 ||
            _boardLogic[cursorPosition->getY()][cursorPosition->getX() + 1]->_state == 3)
            return;
        if (_boardLogic[cursorPosition->getY()][cursorPosition->getX()]->_state == 1 ||
            _boardLogic[cursorPosition->getY()][cursorPosition->getX() + 1]->_state == 1)
            return;
        if (cursorPosition->getY() != (unsigned)(boardH - 1) &&
            _boardLogic[cursorPosition->getY() + 1][cursorPosition->getX()]->_type == -1 &&
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
    
    public: void Detect (LogicPanel *** boardLogic, int boardW, int boardH, vector<Change> &changes, vector<LogicPanel **> &_garbageList)
    {
        // Panel checkboard
        for (int i = 0; i < boardH; i++)
        {
            for (int j = 0; j < boardW; j++)
                __checkBoard[i][j] = 0;
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
                    {
                        __checkBoard[_foundVertical[k].getX()][_foundVertical[k].getY()] = 1;
                        CheckGarbageContact(boardLogic, _foundVertical[k].getX(), _foundVertical[k].getY(), boardW, boardH, _garbageList);
                    }
                }
                
                if (_foundHorizontal.size() >= 3)
                {
                    for (unsigned int k = 0; k < _foundHorizontal.size(); k++)
                    {
                        __checkBoard[_foundHorizontal[k].getX()][_foundHorizontal[k].getY()] = 1;
                        CheckGarbageContact(boardLogic, _foundHorizontal[k].getX(), _foundHorizontal[k].getY(), boardW, boardH, _garbageList);
                    }
                }
                
                _foundVertical.clear();
                _foundHorizontal.clear();
            }
        }
        
        // Check panels to destroy them
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
                if (__checkBoard[i][j] != 0)
                {
                    if (__checkBoard[i][j] == 1)
                    {
                        boardLogic[i][j]->_state = 3;
                        boardLogic[i][j]->_wait = 20;
                    }
                    else if (__checkBoard[i][j] == 2)
                    {
                        Change __change = 0;
                        __change = AddChangeType(__change, TRANSFORM_GARBAGE_OPERATION);
                        __change = AddTargetPanelX(__change, j);
                        __change = AddTargetPanelY(__change, i);
                        changes.push_back(__change);
                    }

                }
    }
    
    // Detect combinations in vertical direction.
    // @param i: row index.
    // @param j: column index.
    private: void DetectVertical (LogicPanel *** boardLogic, int type, int i, int j, Direction dir, int boardW, int boardH)
    {
        if (boardLogic[i][j]->_state == 3 || boardLogic[i][j]->_state == 2)
            return;
        if (i != boardH - 1 && boardLogic[i + 1][j]->_type == -1)
            return;
        if (boardLogic[i][j]->_type != type || boardLogic[i][j]->_type == -1 ||
            boardLogic[i][j]->_type == PANEL_CONCRETE_GARBAGE_TYPE ||
            boardLogic[i][j]->_type == PANEL_GARBAGE_TYPE || boardLogic[i][j]->_state == 1)
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
        if (boardLogic[i][j]->_state == 3 || boardLogic[i][j]->_state == 2)
            return;
        if (i != boardH - 1 && boardLogic[i + 1][j]->_type == -1)
            return;
        if (boardLogic[i][j]->_type != type || boardLogic[i][j]->_type == -1 ||
            boardLogic[i][j]->_type == PANEL_GARBAGE_TYPE ||
            boardLogic[i][j]->_type == PANEL_CONCRETE_GARBAGE_TYPE || boardLogic[i][j]->_state == 1)
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
    
    // Check if a breaking panel is touching any sort of garbage
    // @param _boardLogic: Board logic matrix reference.
    // @param i: row index;
    // @param j: column index;
    // @param boardW: board width;
    // @param boardH: board height;
    private: void CheckGarbageContact (LogicPanel *** _boardLogic, int i, int j, int boardW, int boardH, vector<LogicPanel **> &_garbageList)
    {
        if (i > 0 && _boardLogic[i - 1][j]->_type == PANEL_GARBAGE_TYPE)
        {
            MarkGarbage(_boardLogic, i - 1, j, _garbageList);
            FindSurroudingGarbage(_boardLogic, i - 1, j, boardW, boardH, _garbageList);
        }
        else if (i > 0 && _boardLogic[i - 1][j]->_type == PANEL_CONCRETE_GARBAGE_TYPE)
        {
            MarkGarbage(_boardLogic, i - 1, j, _garbageList);
        }
        
        if (i < boardH - 1 && _boardLogic[i + 1][j]->_type == PANEL_GARBAGE_TYPE)
        {
            MarkGarbage(_boardLogic, i + 1, j, _garbageList);
            FindSurroudingGarbage(_boardLogic, i + 1, j, boardW, boardH, _garbageList);
        }
        else if (i < boardH - 1 && _boardLogic[i + 1][j]->_type == PANEL_CONCRETE_GARBAGE_TYPE)
        {
            MarkGarbage(_boardLogic, i + 1, j, _garbageList);
        }
        
        if (j > 0 && _boardLogic[i][j - 1]->_type == PANEL_GARBAGE_TYPE)
        {
            MarkGarbage(_boardLogic, i, j - 1, _garbageList);
            FindSurroudingGarbage(_boardLogic, i, j - 1, boardW, boardH, _garbageList);
        }
        else if (j > 0 && _boardLogic[i][j - 1]->_type == PANEL_CONCRETE_GARBAGE_TYPE)
        {
            MarkGarbage(_boardLogic, i, j - 1, _garbageList);
        }
        
        if (j < boardW - 1 && _boardLogic[i][j + 1]->_type == PANEL_GARBAGE_TYPE)
        {
            MarkGarbage(_boardLogic, i, j + 1, _garbageList);
            FindSurroudingGarbage(_boardLogic, i , j + 1, boardW, boardH, _garbageList);
        }
        else if (j < boardW - 1 && _boardLogic[i][j + 1]->_type == PANEL_CONCRETE_GARBAGE_TYPE)
        {
            MarkGarbage(_boardLogic, i, j + 1, _garbageList);
        }
    }
    
    // Analyses the board to figure out if a target garbage is in contact with other garbage objects.
    // @param _boardLogic: Board logic matrix reference.
    // @param i: row index;
    // @param j: column index;
    // @param _garbageList: grabage list vecrtor;
    private: void FindSurroudingGarbage (LogicPanel *** _boardLogic, int i, int j, int boardW, int boardH, vector<LogicPanel **> &_garbageList)
    {
        stringstream ss;
        int __sourceY = _boardLogic[i][j]->_sourceY;
        int __height = __sourceY - _boardLogic[i][j]->_height;
        int __sourceX = _boardLogic[i][j]->_sourceX;
        int __width = __sourceX + _boardLogic[i][j]->_width;
        Debug::Log(ss.str());
        for (int k = __sourceY; k > __height; k--)
        {
            if (k < 0)
                break;
            for (int l = __sourceX; l < __width; l++)
            {
                if (k > 0 && _boardLogic[k - 1][l]->_type == PANEL_GARBAGE_TYPE &&
                    __checkBoard[_boardLogic[k - 1][l]->_sourceY][_boardLogic[k - 1][l]->_sourceX] != 2 &&
                    __checkBoard[_boardLogic[k - 1][l]->_sourceY][_boardLogic[k - 1][l]->_sourceX] != 3)
                {
                    MarkGarbage(_boardLogic, k - 1, l, _garbageList);
                    FindSurroudingGarbage(_boardLogic, k - 1, l, boardW, boardH, _garbageList);
                }
                
                if (k < boardH - 1 && _boardLogic[k + 1][l]->_type == PANEL_GARBAGE_TYPE &&
                    __checkBoard[_boardLogic[k + 1][l]->_sourceY][_boardLogic[k + 1][l]->_sourceX] != 2 &&
                    __checkBoard[_boardLogic[k + 1][l]->_sourceY][_boardLogic[k + 1][l]->_sourceX] != 3)
                {
                    MarkGarbage(_boardLogic, k + 1, l, _garbageList);
                    FindSurroudingGarbage(_boardLogic, k + 1, l, boardW, boardH, _garbageList);
                }
                
                if (l > 0 && _boardLogic[k][l - 1]->_type == PANEL_GARBAGE_TYPE &&
                    __checkBoard[_boardLogic[k][l - 1]->_sourceY][_boardLogic[k][l - 1]->_sourceX] != 2 &&
                    __checkBoard[_boardLogic[k][l - 1]->_sourceY][_boardLogic[k][l - 1]->_sourceX] != 3)
                {
                    MarkGarbage(_boardLogic, k, l - 1, _garbageList);
                    FindSurroudingGarbage(_boardLogic, k, l - 1, boardW, boardH, _garbageList);
                }
                
                if (l < boardW - 1 && _boardLogic[k][l + 1]->_type == PANEL_GARBAGE_TYPE &&
                    __checkBoard[_boardLogic[k][l + 1]->_sourceY][_boardLogic[k][l + 1]->_sourceX] != 2 &&
                    __checkBoard[_boardLogic[k][l + 1]->_sourceY][_boardLogic[k][l + 1]->_sourceX] != 3)
                {
                    MarkGarbage(_boardLogic, k, l + 1, _garbageList);
                    FindSurroudingGarbage(_boardLogic, k, l + 1, boardW, boardH, _garbageList);
                }
            }
        }
    }

    // Set a garbage (first line) that it must be transformed into panels. It also updates
    // the remaining panels in the garbage to reduce its height and source position.
    // @param _boardLogic: Board logic matrix reference.
    // @param i: row index;
    // @param j: column index;
    // @param _garbageList: grabage list vecrtor;
    private: void MarkGarbage (LogicPanel *** _boardLogic, int i, int j, vector<LogicPanel **> &_garbageList)
    {
        int __initialY = _boardLogic[i][j]->_sourceY;
        int __heightY = _boardLogic[i][j]->_height;
        int __initialX =  _boardLogic[i][j]->_sourceX;
        int __width = _boardLogic[i][j]->_width;
        int __garbageCounter = 0;
        
        for ( int k = __initialY; k > __initialY - __heightY; k--)
        {

            for ( int l = __initialX; l < __initialX + __width; l++)
            {
                if (__checkBoard[k][l] == 2)
                {
                    return;
                }
                if (k == __initialY)
                {
                    // 2 represents garbage elements that should be transformed into panels.
                    __checkBoard[k][l] = 2;
                }
                else if (k >= 0)
                {
                    _boardLogic[k][l]->_sourceY--;
                    _boardLogic[k][l]->_height--;
                    _boardLogic[k][l]->_positionY--;
                    
                    // Three represents elements from a already broken multi-layer garbage
                    // that have already been analyzed.
                    __checkBoard[k][l] = 3;
                }
                else if (k < 0)
                {
                    
                    for (int m = __initialX; m < __initialX + __width; m++)
                    {
                        _garbageList[__garbageCounter][m]->_sourceY = __initialY- 1 >= 0? __initialY - 1: 0;
                        _garbageList[__garbageCounter][m]->_height--;
                        _garbageList[__garbageCounter][m]->_positionY--;
                    }
                    __garbageCounter++;
                    break;
                }
            }
        }
    }
    
    // Implements fall logic. Sweeps the board for panels in falling condition and update those
    // already falling.
    // @param _boardLogic: Pointer to logic board.
    // @param _garbageList: garbage queue list.
    // @param boardW: Board Width.
    // @param boardH: Board Height.
    // @param changes: change array.
    public: void Fall (LogicPanel *** _boardLogic,
                       int boardW,
                       int boardH,
                       vector<Change> &changes,
                       vector<LogicPanel **> &_garbageList)
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
                __fallCheckBoard[i][j]._wait = _boardLogic[i][j]->_wait;
            }
        
        // Detect Potential falls
        for (int i = boardH - 1; i >= 0; i--)
        {
            for (int j = 0; j < boardW; j++)
            {
                if (i != boardH - 1)
                {
                    // If Swapping, ignore the panel
                    if (__fallCheckBoard[i][j]._state == 2)
                        continue;
                    
                    // Start fall
                    if (__fallCheckBoard[i][j]._type != -1 && (__fallCheckBoard[i][j]._state == 0 || IsInFallingAnimation(i,j)) && __fallCheckBoard[i][j]._state != 2 && (__fallCheckBoard[i + 1][j]._type == -1 || __fallCheckBoard[i + 1][j]._state == 4))
                    {
                        if (__fallCheckBoard[i][j]._type != PANEL_CONCRETE_GARBAGE_TYPE &&
                            __fallCheckBoard[i][j]._type != PANEL_GARBAGE_TYPE)
                        {
                            _boardLogic[i][j]->_state = 4;
                            _boardLogic[i][j]->_wait = FALL_DELAY;
                            
                            __fallCheckBoard[i][j]._state = 4;
                            __fallCheckBoard[i][j]._wait = FALL_DELAY;

                        }
                        else
                        {
                            bool __canFall = CanGarbageFall (i, j);
                            if (__canFall)
                                FallGarbage(i, j, changes, _garbageList);
                        }
                    }
                    else if (__fallCheckBoard[i][j]._state == 4)
                    {
                        if (_boardLogic[i][j]->_wait == 0)
                        {
                            __fallCheckBoard[i][j]._state = 1;
                            _boardLogic[i][j]->_state = 1;
                        }
                        else
                        {
                            _boardLogic[i][j]->_wait--;
                        }
                    }
                    // Update fall
                    else if (__fallCheckBoard[i][j]._type != -1 && (__fallCheckBoard[i][j]._state == 1 ||  IsInFallingAnimation(i,j)) && __fallCheckBoard[i][j]._state != 2 && __fallCheckBoard[i + 1][j]._type == -1)
                    {
                        if (__fallCheckBoard[i][j]._type != PANEL_CONCRETE_GARBAGE_TYPE &&
                            __fallCheckBoard[i][j]._type != PANEL_GARBAGE_TYPE)
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
                            if (__canFall)
                                FallGarbage(i, j, changes, _garbageList);
                        }
                    }
                    // Stop fall
                    else if (__fallCheckBoard[i][j]._type != -1 && (__fallCheckBoard[i][j]._state == 1 || (__fallCheckBoard[i][j]._state >= 5 && __fallCheckBoard[i][j]._state <= 14))&& __fallCheckBoard[i + 1][j]._type != -1)
                    {
                        if (__fallCheckBoard[i][j]._type != PANEL_CONCRETE_GARBAGE_TYPE &&
                            __fallCheckBoard[i][j]._type != PANEL_GARBAGE_TYPE)
                        {
                            UpdateFallSprite(i, j, changes, _boardLogic);
                        }
                        else
                        {
                            _boardLogic[i][j]->_state = 0;
                            __fallCheckBoard[i][j]._state = 0;
                        }
                    }
                }
                else
                {
                    // Stop fall hit the last line
                    if (__fallCheckBoard[i][j]._type != PANEL_CONCRETE_GARBAGE_TYPE &&
                        __fallCheckBoard[i][j]._type != PANEL_GARBAGE_TYPE)
                    {
                        UpdateFallSprite(i, j, changes, _boardLogic);
                    }
                    else
                    {
                        _boardLogic[i][j]->_state = 0;
                        __fallCheckBoard[i][j]._state = 0;
                    }
                }
            }
        }
    }
    
    private: bool IsInFallingAnimation (int i, int j)
    {
        return (__fallCheckBoard[i][j]._state >= 5 && __fallCheckBoard[i][j]._state <= 14);
    }
    
    private: void UpdateFallSprite (int i, int j, vector<Change> &changes, LogicPanel *** _boardLogic)
    {
        if (__fallCheckBoard[i][j]._state == 1)
        {
            _boardLogic[i][j]->_state = 5;
            __fallCheckBoard[i][j]._state = 5;
            
            Change __change = 0;
            __change = AddChangeType(__change, PANEL_GRAPHICS_STYLE_OPERATION);
            __change = AddPanelImageStyle(__change, PANEL_FALL_FRAME_1);
            __change = AddTargetPanelX(__change, j);
            __change = AddTargetPanelY(__change, i);
            changes.push_back(__change);
        }
        else if (__fallCheckBoard[i][j]._state == 5)
        {
            _boardLogic[i][j]->_state = 6;
            __fallCheckBoard[i][j]._state = 6;
            
            Change __change = 0;
            __change = AddChangeType(__change, PANEL_GRAPHICS_STYLE_OPERATION);
            __change = AddPanelImageStyle(__change, PANEL_FALL_FRAME_2);
            __change = AddTargetPanelX(__change, j);
            __change = AddTargetPanelY(__change, i);
            changes.push_back(__change);
        }
        else if (__fallCheckBoard[i][j]._state == 6)
        {
            _boardLogic[i][j]->_state = 7;
            __fallCheckBoard[i][j]._state = 7;
            
            Change __change = 0;
            __change = AddChangeType(__change, PANEL_GRAPHICS_STYLE_OPERATION);
            __change = AddPanelImageStyle(__change, PANEL_FALL_FRAME_3);
            __change = AddTargetPanelX(__change, j);
            __change = AddTargetPanelY(__change, i);
            changes.push_back(__change);
        }
        else if (__fallCheckBoard[i][j]._state == 7)
        {
            _boardLogic[i][j]->_state = 8;
            __fallCheckBoard[i][j]._state = 8;
            
            Change __change = 0;
            __change = AddChangeType(__change, PANEL_GRAPHICS_STYLE_OPERATION);
            __change = AddPanelImageStyle(__change, PANEL_FALL_FRAME_4);
            __change = AddTargetPanelX(__change, j);
            __change = AddTargetPanelY(__change, i);
            changes.push_back(__change);
        }
        else if (__fallCheckBoard[i][j]._state == 8)
        {
            _boardLogic[i][j]->_state = 9;
            __fallCheckBoard[i][j]._state = 9;
            
            Change __change = 0;
            __change = AddChangeType(__change, PANEL_GRAPHICS_STYLE_OPERATION);
            __change = AddPanelImageStyle(__change, PANEL_FALL_FRAME_5);
            __change = AddTargetPanelX(__change, j);
            __change = AddTargetPanelY(__change, i);
            changes.push_back(__change);
        }
        else if (__fallCheckBoard[i][j]._state == 9)
        {
            _boardLogic[i][j]->_state = 10;
            __fallCheckBoard[i][j]._state = 10;
            
            Change __change = 0;
            __change = AddChangeType(__change, PANEL_GRAPHICS_STYLE_OPERATION);
            __change = AddPanelImageStyle(__change, PANEL_FALL_FRAME_6);
            __change = AddTargetPanelX(__change, j);
            __change = AddTargetPanelY(__change, i);
            changes.push_back(__change);
        }
        else if (__fallCheckBoard[i][j]._state == 10)
        {
            _boardLogic[i][j]->_state = 11;
            __fallCheckBoard[i][j]._state = 11;
            
            Change __change = 0;
            __change = AddChangeType(__change, PANEL_GRAPHICS_STYLE_OPERATION);
            __change = AddPanelImageStyle(__change, PANEL_FALL_FRAME_7);
            __change = AddTargetPanelX(__change, j);
            __change = AddTargetPanelY(__change, i);
            changes.push_back(__change);
        }
        else if (__fallCheckBoard[i][j]._state == 11)
        {
            _boardLogic[i][j]->_state = 12;
            __fallCheckBoard[i][j]._state = 12;
            
            Change __change = 0;
            __change = AddChangeType(__change, PANEL_GRAPHICS_STYLE_OPERATION);
            __change = AddPanelImageStyle(__change, PANEL_FALL_FRAME_8);
            __change = AddTargetPanelX(__change, j);
            __change = AddTargetPanelY(__change, i);
            changes.push_back(__change);
        }
        else if (__fallCheckBoard[i][j]._state == 12)
        {
            _boardLogic[i][j]->_state = 13;
            __fallCheckBoard[i][j]._state = 13;
            
            Change __change = 0;
            __change = AddChangeType(__change, PANEL_GRAPHICS_STYLE_OPERATION);
            __change = AddPanelImageStyle(__change, PANEL_FALL_FRAME_9);
            __change = AddTargetPanelX(__change, j);
            __change = AddTargetPanelY(__change, i);
            changes.push_back(__change);
        }
        else if (__fallCheckBoard[i][j]._state == 13)
        {
            _boardLogic[i][j]->_state = 14;
            __fallCheckBoard[i][j]._state = 14;
            
            Change __change = 0;
            __change = AddChangeType(__change, PANEL_GRAPHICS_STYLE_OPERATION);
            __change = AddPanelImageStyle(__change, PANEL_FALL_FRAME_10);
            __change = AddTargetPanelX(__change, j);
            __change = AddTargetPanelY(__change, i);
            changes.push_back(__change);
        }
        else if (__fallCheckBoard[i][j]._state == 14)
        {
            _boardLogic[i][j]->_state = 0;
            __fallCheckBoard[i][j]._state = 0;
            
            Change __change = 0;
            __change = AddChangeType(__change, PANEL_GRAPHICS_STYLE_OPERATION);
            __change = AddPanelImageStyle(__change, PANEL_NORMAL_SPRITE);
            __change = AddTargetPanelX(__change, j);
            __change = AddTargetPanelY(__change, i);
            changes.push_back(__change);
        }
    }

    // Determines if a garbage at location i, j can fall.
    // @param i: row index;
    // @param j: column index;
    // @return true if the garbage can fall, false if not.
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
    
    
    // Update grabage object in the board to make it fall as a single unit.
    // @param i: row index;
    // @param j: column index;
    // @param _garbageList: grabage list vecrtor;
    private: void FallGarbage (int i, int j, vector<Change> &changes, vector<LogicPanel **> &_garbageList)
    {
        int __initialIndexX = __fallCheckBoard[i][j]._sourceX;
        int __initialIndexY = i;
        int __lastIndexX = __fallCheckBoard[i][j]._sourceX + __fallCheckBoard[i][j]._width;
        int __lastIndexY = i - __fallCheckBoard[i][j]._height;
        int __garbageCounter = 0;
        for (int l = __initialIndexY; l > __lastIndexY; l--)
        {
            if (l >= 0)
            {
                for (int k = __initialIndexX; k < __lastIndexX; k++)
                {
                    Change __fall = 0;
                    __fall = AddChangeType(__fall, FALL_OPERATION);
                    __fall = AddTargetPanelX(__fall, k);
                    __fall = AddTargetPanelY(__fall, l);
                    changes.push_back(__fall);
                    
                    __fallCheckBoard[l + 1][k]._type= __fallCheckBoard[l][k]._type;
                    __fallCheckBoard[l + 1][k]._state = __fallCheckBoard[l][k]._state;
                    __fallCheckBoard[l + 1][k]._positionX = __fallCheckBoard[l][k]._positionX;
                    __fallCheckBoard[l + 1][k]._positionY = __fallCheckBoard[l][k]._positionY;
                    __fallCheckBoard[l + 1][k]._sourceX = __fallCheckBoard[l][k]._sourceX;
                    __fallCheckBoard[l + 1][k]._sourceY = __fallCheckBoard[l][k]._sourceY + 1;
                    __fallCheckBoard[l + 1][k]._width = __fallCheckBoard[l][k]._width;
                    __fallCheckBoard[l + 1][k]._height = __fallCheckBoard[l][k]._height;
                    
                    __fallCheckBoard[l][k]._type = -1;
                    __fallCheckBoard[l][k]._state = -1;
                    __fallCheckBoard[l][k]._positionX = -1;
                    __fallCheckBoard[l][k]._positionY = -1;
                    __fallCheckBoard[l][k]._sourceX = -1;
                    __fallCheckBoard[l][k]._sourceY = -1;
                    __fallCheckBoard[l][k]._width = -1;
                    __fallCheckBoard[l][k]._height = -1;
                }
            }
            else
            {
                for (int k = __initialIndexX; k < __lastIndexX; k++)
                {
                    _garbageList[__garbageCounter][k]->_sourceY += 1;
                }
                __garbageCounter++;
            }
        }
    }
    
    public: void SpeedUp()
    {
        _targetDelay = 0;
    }
    
    public: void SlowDown()
    {
        //_targetDelay = 20;
    }
    
    public: void Slide (LogicPanel *** _boardLogic, int boardW, int boardH, std::vector<Change> &changes, Sprite * board)
    {
         if (_currentDelay >= _targetDelay)
         {
             _currentDelay = 0;
             _boardVerticalPosition++;
             if (_boardVerticalPosition == PANEL_IMAGE_SIZE)
             {
                 _boardVerticalPosition = 0;
                 
                 Change __change = 0;
                 __change = AddChangeType(__change, TRANSPORT_OPERATION);
                 changes.push_back(__change);
                 _targetDelay = 20;
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
