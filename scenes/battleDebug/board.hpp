#pragma once
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
#include "animation_manager.hpp"
#include "board_constants.hpp"
#include "utils.hpp"
#include "garbage_badge.hpp"

// Audio inlcudes
#include "../../assets/audio/garbage_fall1.h"

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
    private: Sprite * _boardOuterContainer;
    private: Sprite * _nextRowContainer;
    private: Panel * _leftSwap;
    private: Panel * _rightSwap;
    private: SpriteManager * _spriteManager;
    private: AnimationManager * _animationManager;
    private: int _garbageDelay;
    private: Sprite * _UIGrabageWarningFlare;
    private: Sprite * _badgeContainer;
    private: vector<GarbageBadge *> _garbageBadges;
    private: bool _garbageCanFall;
    private: int _garbageLoadHeight;
    private: int _frameBreakingGarbage;

    // Rival Board Reference
    private: Board * _rival;

    // Sound FX
    private: Sound * _garbage_fall1;

    // Graphics Variables
    private: Point2D * _swapTarget;
    private: bool _isSwapping;
    private: int _leftState;
    private: int _rightState;
    private: int __delay;
    private: vector<Point2D> _transformingPanels;

    // Control Elements
    private: Point2D _cursorPosition;

    // Controller reference
    private: Controller * _wiiremote;

    // Board Shake Controller
    private: int _currentShakeFrame;
    private: float _intialY;
    private: vector<float> _shakeSamples;

    // Pokemon character data
    private: int _pokemonType;

    // Slide Control
    private: int _slideDelay;

    // Alert Animation
    private: char _shakeColumnMap;
    private: char _previousShakeColumnMap;
    private: int _shakeFrame;
    private: int _shakeDelay;

    // Default Constructor, Builds a random set of panels, based on the
    // dimension provided as argument. The board origin point is determined
    // by pos argument.
    // @param dim: the number of rows and columns in the board.
    // @param pos: the origin point used as reference for the board
    // coordinate system.
    // @param cur_pos: Initial cursor position.
    // @param wiiremote: Player's wii remote reference.
    public: Board(RulesInterface * _rules, Dim2D dim, Point2D pos, Point2D cur_pos, int pokemon_type, int initial_height, SpriteManager *spriteManager, AnimationManager * animationManager, Controller * wiiremote) :
        _dimensions(dim),
        _position(pos),
        _cursorPosition(cur_pos),
        _wiiremote(wiiremote),
        _pokemonType(pokemon_type)
    {
        // Fair randomization
        srand(gettime());

        // Initializes Sprite manager.
        // Load basic texture objects on demand.
        _spriteManager = spriteManager;
        _animationManager = animationManager;

        // save reference of board rules.
        this->_rules = _rules;
        _garbageDelay = 0;
        _garbageLoadHeight = 0;
        _slideDelay = 0;
        _shakeDelay = 0;

        // Create base container for board.
        _boardContainer = new Sprite();
        _boardContainer->_x = (int)_position.getX();
        _boardContainer->_y = (int)_position.getY();
        _boardOuterContainer = new Sprite();
        _boardOuterContainer->AddChild(_boardContainer);

        // Incoming row container sprite.
        _nextRowContainer = new Sprite();
        _nextRowContainer->_x = 0;
        _nextRowContainer->_y = (PANEL_IMAGE_SIZE + PANEL_IMAGE_SPACE) * _dimensions.getHeight();

        __delay = 0;
        _currentShakeFrame = 0;
        _intialY = _boardContainer->_y;
        _garbageCanFall = 0;

        // Badge Container
        _badgeContainer = new Sprite ();
        GraphicEngine::_stage->AddChild(_badgeContainer);

        // Shake Column Map
        _shakeColumnMap = 0;
        _previousShakeColumnMap = 0;
        _shakeFrame = PANEL_SHAKE_FRAME_1;

        // UI Animation
        _UIGrabageWarningFlare = _animationManager->GenerateGarbageUIFlare(_wiiremote->GetPlayerNumber());

        // Adjsut Position based on player number
        if (_wiiremote->GetPlayerNumber() == PPL_PLAYER_1)
        {
          _UIGrabageWarningFlare->_x = 24;
          _UIGrabageWarningFlare->_y = 20;
        }
        else
        {
          _UIGrabageWarningFlare->_x = 165;
          _UIGrabageWarningFlare->_y = 379;
        }

        _UIGrabageWarningFlare->_auto_destroy = false;
        _UIGrabageWarningFlare->SetRepeat(false);
        _UIGrabageWarningFlare->_animation_delay = 1;
        GraphicEngine::_stage->AddChild(_UIGrabageWarningFlare);

        // Instantiates main matrices and arrays.
        InstantiateMatrices();

        // Creates the initial board and next-row.
        InstantiateAndIntializeGameMatrices(initial_height);

        // Initialize Swap Sprites
        InitializeSwapSprites();

        // Instantiate Sounds
        LoadAudio ();
    }

    private: void LoadAudio ()
    {
        _garbage_fall1 = new Sound(garbage_fall1, garbage_fall1_size, 1, 12000);
    }

    // Set rival object reference.
    // @param rival: reference to rival board.
    public: void SetRivalReference (Board * rival)
    {
        _rival = rival;
    }

    // Updates cursor position and graphics position based on a point.
    // This method also update sthe cursor animation frames.
    // @param pos: relative position object, each unity in pos object
    // actually represents a columna and a row, which will be converted
    // to actual pixel values, in the function.
    public: void UpdateCursorPosition(Point2D pos)
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

    // Swap two panels based on the rules specification.
    public: void Swap()
    {
        if (_isSwapping)
            return;

        _rules->Swap(_boardLogic, _dimensions.getWidth(), _dimensions.getHeight(), _changes, &_cursorPosition);
    }

    // Update Board Graphics once at each frame. Uses change operation language to
    // parse each change the rules have commited and update the frame
    // accordingly.
    public: void InterpretOperations()
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
                    // format: [TYPE][IS_GARBAGE_SOURCE][TRANSFORMATION_TYPE][SRC_Y][SRC_X]
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
                    // format: [TYPE][XXXX][XXXX][XXXX][DURATION]
                    // Triggers a rumble effect in wii remote
                case RUMBLE_OPERATION:
                {
                    RumbleOperation(_changes[i]);
                    break;
                }
                    // PANEL BREAK ANIMATION OPERATION OPERATION
                    // format: [TYPE][XXXX][TYPE][TARG_Y][TARG_X]
                    // Displays break animation
                case PANEL_BREAK_ANIMATION_OPERATION:
                {
                    PanelOperationAnimation(_changes[i]);
                    break;
                }
                    // REGISTER COMBO OPERATION
                    // format: [TYPE][XXXX][SIZE][TARG_Y][TARG_X]
                    // Register a new Combo and show combo bubble
                case SCORE_COMBO_OPERATION:
                {
                    ScoreCombo(_changes[i]);
                    break;
                }
                    // CHAIN OPERATION
                    // format: [TYPE][XXXX][VALUE][TARG_Y][TARG_X]
                    // Chain operation in a pannel
                case CHAIN_OPERATION:
                {
                    CancelChain(_changes[i]);
                    break;
                }
                    // REGISTER COMBO OPERATION
                    // format: [TYPE][XXXX][SIZE][TARG_Y][TARG_X]
                    // Register a new Combo and show combo bubble
                case SCORE_CHAIN_OPERATION:
                {
                    ScoreChain(_changes[i]);
                    break;
                }
                    // RIVAL GARBAGE OPERATION
                    // format: [TYPE][XXXX][POSITION][WIDTH][HEIGHT]
                    // Sends garbage blocks to rival board.
                case RIVAL_GARBAGE_OPERATION:
                {
                    SendGarbage(_changes[i]);
                    break;
                }
                    // SHAKE OPERATION
                    // format: [TYPE][XXXX][XXXX][XXXX][XXXX]
                    // Shake board upon reques
                case SHAKE_OPERATION:
                {
                    ShakeBoard(20);
                    break;
                }
                    // SHAKE OPERATION
                    // format: [TYPE][XXXX][XXXX][XXXX][XXXX]
                    // Shake board upon reques
                case PAUSE_BOARD_OPERATION:
                {
                    PauseBoard(_changes[i]);
                    break;
                }

                case SHAKE_COLUMN_OPERATION:
                {
                    ShakeColumn(_changes[i]);
                    break;
                }
            }
        }
        _changes.clear();
    }

    // Detect combos in the board and promp the related panels to be broken.
    public: void Detect()
    {
        _rules->Detect(_boardLogic, _dimensions.getWidth(), _dimensions.getHeight(), _changes, _garbageList);
    }

    // Update panel position (vertically) to make the ilusion of gravity.
    public: void Fall()
    {
        _rules->Fall(_boardLogic, _dimensions.getWidth(), _dimensions.getHeight(), _changes, _garbageList);
    }

    // Update board update movement (Slide up/down depending on the rule).
    public: void Slide()
    {
        if (_slideDelay > 0)
        {
            _slideDelay--;
            _rules->PauseBoardSlide();
        }
        else
        {
            _rules->ResumeBoardSlide();
            _rules->Slide(_dimensions.getWidth(), _dimensions.getHeight(), _changes);
        }
    }

    // Increases slide speed on key pressed
    public: void SpeedUp()
    {
        _rules->SpeedUp();
    }

    // Returns current cursor position.
    // @return Point2D: current cursor position.
    public: Point2D getCursorPosition()
    {
        return _cursorPosition;
    }

    // Create new garbages of given size on a given position.
    // @param width: Garbage width. This will stack up rows as the garbage size dont fit the row.
    // @param height: Garbage height.
    // @param position: initial garbage position.
    public: void MakeGarbage (int width, int height, int position)
    {
        // The garbage will overflow in terms of columns.
        if (width + position > _dimensions.getWidth())
            return;

        if (_garbageDelay == 0)
            _garbageDelay = GARBAGE_FALL_DELAY;

        for (int j = 0; j < height; j++)
        {
            LogicPanel ** __garbageSlice  = new LogicPanel *[_dimensions.getWidth()];
            for (int i = 0; i < _dimensions.getWidth(); i++)
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
                __garbageSlice[i]->_break_delay = 0;
                __garbageSlice[i]->_in_chain = 0;
                __garbageSlice[i]->_state = 0;
            }

            for (int i = position; i < position + width; i++)
            {
                __garbageSlice[i]->_type = PANEL_GARBAGE_TYPE;
                __garbageSlice[i]->_sourceX = position;
                __garbageSlice[i]->_sourceY = 0;
                __garbageSlice[i]->_width = width;
                __garbageSlice[i]->_height = height;
                __garbageSlice[i]->_positionX = i;
                __garbageSlice[i]->_positionY = j;
                __garbageSlice[i]->_wait = 0;
                __garbageSlice[i]->_break_delay = 0;
                __garbageSlice[i]->_in_chain = 0;
                __garbageSlice[i]->_state = 1;
            }
            _garbageList.push_back(__garbageSlice);
        }

        EmitGarbageFallingSequence();
    }

    // Update garbage position on falling through the board.
    public: void FallGarbage ()
    {
        if (_garbageList.size() == 0)
        {
            return;
        }

        if (_garbageCanFall == false)
        {
            return;
        }

        if (!CanGarbageFall())
          return;

        for (int i = 0; i < _dimensions.getWidth(); i++)
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
                _boardLogic[0][i]->_break_delay = _garbageList[0][i]->_break_delay;
                _boardLogic[0][i]->_in_chain = _garbageList[0][i]->_in_chain;
                _boardLogic[0][i]->_state = 1;

                if (_garbageList[0][i]->_positionY == _garbageList[0][i]->_sourceY &&
                    _garbageList[0][i]->_positionX == _garbageList[0][i]->_sourceX)
                {
                    DisplayGarbageSprite(0, i);
                    _boardGraphics[0][i]->_visibility = visible;
                }
                else
                {
                    _boardGraphics[0][i]->_visibility = hidden;
                }
            }
        }

        for (int i = 0; i < _dimensions.getWidth(); i++)
            delete _garbageList[0][i];
        delete[] _garbageList[0];
        _garbageList.erase (_garbageList.begin());

        // only when it is zero is that the next garbage will be allowed to fall;
        _garbageLoadHeight--;

        // check if the current garbage have fully fallen
        if (_garbageLoadHeight <= 0)
        {
          _garbageLoadHeight = 0;
          _garbageCanFall = false;
        }
    }

    private: bool CanGarbageFall ()
    {
      for (int i = 0; i < _dimensions.getWidth(); i++)
      {
          // Check if the top most if free let garbage fall.
          if (_boardLogic[0][i]->_type != -1 && _garbageList[0][i]->_type == PANEL_GARBAGE_TYPE)
          {
              return false;
          }
      }
      return true;
    }

    // Debug function to drop garbage in the board.
    public: void DEBUGInput()
    {
      //MakeGarbage(4, 1, 2);
      //MakeGarbage(3, 1, 3);
      MakeGarbage(6, 3, 0);
      //MakeGarbage(4, 1, 0);
      //MakeGarbage(6, 7, 0);
    }

    private: void EmitGarbageFallingSequence ()
    {
      // Generate Garbage -=Badge Object
      GarbageBadge * __badge;

      if (_wiiremote->GetPlayerNumber() == PPL_PLAYER_1)
      {
        __badge = new GarbageBadge(_spriteManager->_comboBox_Player1_0001, _wiiremote->GetPlayerNumber());
        __badge->_x = 393;
        __badge->_y = 26;
      }
      else
      {
        __badge = new GarbageBadge(_spriteManager->_comboBox_Player2_0001, _wiiremote->GetPlayerNumber());
        __badge->_x = 172;
        __badge->_y = 421;
      }

      // If the flare animation is already happening, simply inform the badge that
      // it can appear at the end of the animation.
      if (_UIGrabageWarningFlare->GetIsPlaying())
        __badge->_delay = 15 - _UIGrabageWarningFlare->GetCurrentFrame();
      else
        _UIGrabageWarningFlare->GotoAndPlay(0);

      __badge->_appearing = true;
      _badgeContainer->AddChildAt(__badge, 0);
      _garbageBadges.push_back(__badge);

      AdjustBadgeTargetPositions ();
    }

    // Update garbage badges position based on their index.
    private: void AnimateGarbageBadges ()
    {
        for (size_t i = 0; i < _garbageBadges.size(); i++)
        {
            // Wait the animation (flare animation) before moving the bagde.
            if (_garbageBadges[i]->_delay != 0)
            {
                _garbageBadges[i]->_delay--;
                continue;
            }

            // Determines position based on player number
            if (_wiiremote->GetPlayerNumber() == PPL_PLAYER_1)
            {
              _garbageBadges[i]->_x += ((393 + _garbageBadges[i]->_finalPosition) - _garbageBadges[i]->_x)/5;
            }
            else
            {
              _garbageBadges[i]->_x += ((190 - _garbageBadges[i]->_finalPosition) - _garbageBadges[i]->_x)/5;

            }
            // Adjust Garbage Badge Color
            _garbageBadges[i]->ChangeBadgeColor(_spriteManager);

            // Check if the grabage badge has been in the screen for too long. if so, hide it.
            if (i == 0)
            {
              if (_garbageBadges[0]->_lifeTime == 50 && _garbageBadges[0]->_appearing == true)
              {
                  if (CanGarbageFall() && _garbageLoadHeight == 0)
                  {
                    _garbageBadges[0]->_lifeTime = 0;
                    _garbageBadges[0]->_finalPosition = 0;
                    _garbageBadges[0]->_appearing = false;
                    AdjustBadgeTargetPositions();

                    // Update _garbageLoadHeight to hold the height of the garbage to fall.
                    for (int k = 0; k < _dimensions.getWidth(); k++)
                    {
                      if (_garbageList[0][k]->_type == PANEL_GARBAGE_TYPE)
                      {
                        _garbageLoadHeight = _garbageList[0][k]->_height;
                        break;
                      }
                    }
                    _garbageCanFall = true;
                  }
              }
              else if (_garbageBadges[0]->_lifeTime == 50 && _garbageBadges[0]->_appearing == false)
              {
                  _badgeContainer->RemoveChild(_garbageBadges[0]);
                  _garbageBadges.erase(_garbageBadges.begin());
                  i--;
              }
              else
              {
                  _garbageBadges[0]->_lifeTime++;
              }
            }
        }
    }

    // Recompute target grabage positions
    private: void AdjustBadgeTargetPositions ()
    {
      // Compute the position of the elements based on their indexes.
      int __prev_position = 0;
      int __position_counter = 0;
      for (size_t i = 0; i < _garbageBadges.size(); i++)
      {
          float __target_position = 0;
          if (__position_counter <= 8)
          {
              __target_position = ((35.0)/((__position_counter + 1)*0.6)) + __prev_position;
          }
          else
          {
              __target_position = ((35.0)/((9)*0.6));
          }

          if (_garbageBadges[i]->_appearing)
          {
            __position_counter++;
            __prev_position = __target_position;
            _garbageBadges[i]->_finalPosition = __target_position;
          }
      }
    }

    // Instantates System matrices.
    private: void InstantiateMatrices ()
    {
        // Board Logic and Graphics Matrices instantiation.
        _boardGraphics = new Panel ** [_dimensions.getHeight()];
        _boardLogic = new LogicPanel ** [_dimensions.getHeight()];
        for (int i = 0; i < _dimensions.getHeight(); i++)
        {
            _boardGraphics[i] = new Panel * [_dimensions.getWidth()];
            _boardLogic[i] = new LogicPanel * [_dimensions.getWidth()];
        }

        // Next Row Logic and graphics array instantiation.
        _nextRowLogic = new LogicPanel * [_dimensions.getWidth()];
        _nextRowGraphics = new Panel * [_dimensions.getWidth()];
    }

    // Instantiates the main game matrices (board and next row) and intializes their logic and graphics.
    // @param initial_height: Initial board height. Only this amount of rows are initialized.
    private: void InstantiateAndIntializeGameMatrices(int initial_height)
    {
        char __previous_type = PANEL_VOID_TYPE;
        for (int i = 0; i < _dimensions.getWidth(); i++)
        {
            // Make sure the current panel is different from the previous.
            char __random_type = Utils::GetNextTypeWithoutRepetition(__previous_type);
            __previous_type = __random_type;

            // Instantiate Next-Row Panel Graphics
            _nextRowGraphics[i] = new Panel(Utils::DecodeType(__random_type, _spriteManager, PANEL_DARK_SPRITE),
                                            PANEL_IMAGE_SIZE, PANEL_IMAGE_SIZE);

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
        for (int i = 0; i < _dimensions.getHeight(); i++)
            for (int j = 0; j < _dimensions.getWidth(); j++)
            {
                // Make sure the current panel is different from the previous and the one above..
                __type_above = i==0?PANEL_VOID_TYPE:_boardLogic[i - 1][j]->_type;
                char __random_type = Utils::GetNextTypeWithoutRepetition(__previous_type, __type_above);
                __previous_type = __random_type;

                // Instantiate and initialize new Logic Panel
                _boardLogic[i][j] = new LogicPanel();
                _boardLogic[i][j]->_type = (int)__random_type;
                _boardLogic[i][j]->_state = 0;
                _boardLogic[i][j]->_wait = 0;
                _boardLogic[i][j]->_break_delay = 0;
                _boardLogic[i][j]->_in_chain = 0;

                // Intantiate new Panel Sprite.
                _boardGraphics[i][j] = new Panel (Utils::DecodeType(_boardLogic[i][j]->_type, _spriteManager),
                                                  PANEL_IMAGE_SIZE, PANEL_IMAGE_SIZE);

                // Adjust Panel position on screen.
                _boardGraphics[i][j]->_x = (PANEL_IMAGE_SIZE + PANEL_IMAGE_SPACE) * j;
                _boardGraphics[i][j]->_y = (PANEL_IMAGE_SIZE + PANEL_IMAGE_SPACE) * i;

                // Show panel on screen.
                _boardContainer->AddChild(_boardGraphics[i][j]);

                // If the panel is not to be displayed (empty row), hide it.
                if (i <= (int)initial_height)
                {
                    _boardLogic[i][j]->_type = PANEL_VOID_TYPE;
                    _boardGraphics[i][j]->_visibility = hidden;
                }
            }

        // Show board and next-row on screen.
        _boardContainer->AddChild(_nextRowContainer);
        GraphicEngine::_stage->AddChildAt(_boardOuterContainer, 0);

        ShowBoardBackground ();
    }

    private: void ShowBoardBackground ()
    {
      if (_wiiremote->GetPlayerNumber() == PPL_PLAYER_1)
      {
          // Background image for player`s board
          Sprite * _boardBG = new Sprite(_spriteManager->_P1, 196, 380);
          _boardBG->_x = 30;
          _boardBG->_y = 29;
          GraphicEngine::_stage->AddChildAt(_boardBG, 0);
      }
      else
      {
          // Background image for player`s board
          Sprite * _boardBG = new Sprite(_spriteManager->_P2, 196, 380);
          _boardBG->_x = 418;
          _boardBG->_y = 74;
          GraphicEngine::_stage->AddChildAt(_boardBG, 0);
      }
    }

    // Initializes cursor objects and set its correct position on screen.
    public: void InitializeCursor ()
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


    // Implements Swap Operation.
    // @param change: Change operation binary code.
    private: void SwapOperation(Change change)
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

    // Implements Destroy Operation
    // @param change: Change operation binary code.
    private: void DestroyOperation(Change change)
    {
        // Extract Operation Operands
        int __targetX = ExtractTargetPanelX(change);
        int __targetY = ExtractTargetPanelY(change);

        // Hide target panel graphics
        _boardGraphics[__targetY][__targetX]->_visibility = hidden;

        // Update target logic data.
        _boardLogic[__targetY][__targetX]->_type = PANEL_VOID_TYPE;
        _boardLogic[__targetY][__targetX]->_state = 0;
        _boardLogic[__targetY][__targetX]->_wait = 0;
        _boardLogic[__targetY][__targetX]->_break_delay = 0;
        _boardLogic[__targetY][__targetX]->_in_chain = 0;

        // Ignore Garbage Part
        ClearGarbageData(_boardLogic[__targetY][__targetX]);
    }

    // Implements Fall Operation
    // @param change: Change operation binary code.
    private: void FallOperation (Change change)
    {
        // Extract Operation Operands
        unsigned int __targetX = ExtractTargetPanelX(change);
        unsigned int __targetY = ExtractTargetPanelY(change);

        // Extract derived and useful information
        int __targetType = _boardLogic[__targetY][__targetX]->_type;

        _boardGraphics[__targetY + 1][__targetX]->_visibility = visible;
        if (__targetType == PANEL_GARBAGE_TYPE || __targetType == PANEL_CONCRETE_GARBAGE_TYPE)
        {
            // Show garbage graphics only for the gargabge source.
            if (__targetX == (unsigned)_boardLogic[__targetY][__targetX]->_sourceX &&
                __targetY == (unsigned)_boardLogic[__targetY][__targetX]->_sourceY)
            {

                DisplayGarbageSprite(__targetY, __targetX, 1);
            }
            else
            {
                _boardGraphics[__targetY + 1][__targetX]->_visibility = hidden;
            }
        }
        else
        {
            _boardGraphics[__targetY + 1][__targetX]->SetAsset(Utils::DecodeType(__targetType, _spriteManager),
                                                           PANEL_IMAGE_SIZE, PANEL_IMAGE_SIZE);
        }
        _boardGraphics[__targetY][__targetX]->_visibility = hidden;

        _boardLogic[__targetY + 1][__targetX]->_type = _boardLogic[__targetY][__targetX]->_type;
        _boardLogic[__targetY + 1][__targetX]->_state = 1;
        _boardLogic[__targetY + 1][__targetX]->_wait = _boardLogic[__targetY][__targetX]->_wait;
        _boardLogic[__targetY + 1][__targetX]->_break_delay = _boardLogic[__targetY][__targetX]->_break_delay;
        _boardLogic[__targetY + 1][__targetX]->_in_chain = _boardLogic[__targetY][__targetX]->_in_chain;
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
        _boardLogic[__targetY][__targetX]->_break_delay = 0;
        _boardLogic[__targetY][__targetX]->_in_chain = 0;
        _boardLogic[__targetY][__targetX]->_positionX = -1;
        _boardLogic[__targetY][__targetX]->_positionY = -1;
        _boardLogic[__targetY][__targetX]->_sourceX = -1;
        _boardLogic[__targetY][__targetX]->_sourceY = -1;
        _boardLogic[__targetY][__targetX]->_width = -1;
        _boardLogic[__targetY][__targetX]->_height = -1;

    }

    // Display garabge sprite in a given position (with possibly different row offset).
    // @param i: row index
    // @param j: column index
    // @param offset: row offset
    private: void DisplayGarbageSprite (int i, int j, int offset = 0)
    {
      int __extraSpace = (_boardLogic[i][j]->_height - 1) != 0? _boardLogic[i][j]->_height - 1 : 0;
      _boardGraphics[i + offset][j]->SetAsset(
                                  Utils::DecodeGarbageType(_pokemonType, _boardLogic[i][j]->_width,  _boardLogic[i][j]->_height, _spriteManager),
                                                     PANEL_IMAGE_SIZE, PANEL_IMAGE_SIZE, 0, -((_boardLogic[i][j]->_height - 1)*PANEL_IMAGE_SIZE) + __extraSpace);

    }

    // Implements Panel Graphics Style
    // @param change: Change operation binary code.
    private: void PanelGraphicsStyleOperation(Change change)
    {
        // Extract Operation Operands
        unsigned int __targetX = ExtractTargetPanelX(change);
        unsigned int __targetY = ExtractTargetPanelY(change);
        unsigned int __imageStyle = ExtractPanelImageStyle(change);

        // Extract extra derived information
        int __targetType = _boardLogic[__targetY][__targetX]->_type;

        // Update target panel graphcis according to the intended style.
        _boardGraphics[__targetY][__targetX]->SetAsset(Utils::DecodeType(__targetType, _spriteManager, __imageStyle),
                                                       PANEL_IMAGE_SIZE, PANEL_IMAGE_SIZE);
    }


    // Implements Transport Operation
    private: void TransportOperation ()
    {
        for (int k = 0; k < _dimensions.getWidth(); k++)
            for (int j = 0; j < _dimensions.getHeight() - 1; j++)
            {
                // Update row above with previosu row logic.
                _boardLogic[j][k]->_type = _boardLogic[j + 1][k]->_type;
                _boardLogic[j][k]->_state = _boardLogic[j + 1][k]->_state;
                _boardLogic[j][k]->_wait = _boardLogic[j + 1][k]->_wait;
                _boardLogic[j][k]->_break_delay = _boardLogic[j + 1][k]->_break_delay;
                _boardLogic[j][k]->_in_chain = _boardLogic[j + 1][k]->_in_chain;

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

                // Update graphics accordingly
                if (_boardLogic[j][k]->_type != PANEL_VOID_TYPE && _boardLogic[j][k]->_state != 3)
                {
                    _boardGraphics[j][k]->_visibility = visible;
                    if (_boardLogic[j][k]->_type == PANEL_GARBAGE_TYPE || _boardLogic[j][k]->_type == PANEL_CONCRETE_GARBAGE_TYPE)
                        {
                            // Show image only for the source garbage in the appropriate state
                            if (_boardLogic[j][k]->_state == 15)
                            {
                              _boardGraphics[j][k]->SetAsset(Utils::GarbageIntermediate(_pokemonType,_spriteManager),PANEL_IMAGE_SIZE, PANEL_IMAGE_SIZE);
                            }
                            else
                            {
                              if (_boardLogic[j][k]->_sourceX == k && _boardLogic[j][k]->_sourceY == j)
                              {
                                  DisplayGarbageSprite(j, k);
                              }
                              else
                              {
                                   _boardGraphics[j][k]->_visibility = hidden;
                              }
                            }
                        }
                        else
                        {
                            _boardGraphics[j][k]->SetAsset(Utils::DecodeType(_boardLogic[j][k]->_type, _spriteManager),
                                                           PANEL_IMAGE_SIZE, PANEL_IMAGE_SIZE);
                        }
                }
                else
                {
                    if (_boardLogic[j][k]->_wait < 20)
                        _boardGraphics[j][k]->_visibility = hidden;
                    else
                        _boardGraphics[j][k]->_visibility = visible;
                }
            }

        // Fill the first row with the next row and create a new nextRow with random types.
        char __previous_type = PANEL_VOID_TYPE;
        char __type_above = PANEL_VOID_TYPE;
        for (int k = 0; k < _dimensions.getWidth(); k++)
        {
            // Update first row with nextRow content.
            _boardLogic[_dimensions.getHeight() - 1][k]->_type = _nextRowLogic[k]->_type;
            _boardLogic[_dimensions.getHeight() - 1][k]->_wait = 0;
            _boardLogic[_dimensions.getHeight() - 1][k]->_break_delay = 0;
            _boardLogic[_dimensions.getHeight() - 1][k]->_in_chain = 0;
            _boardLogic[_dimensions.getHeight() - 1][k]->_state = 0;
            _boardGraphics[_dimensions.getHeight() - 1][k]->SetAsset(
                                        Utils::DecodeType(_nextRowLogic[k]->_type, _spriteManager),
                                        PANEL_IMAGE_SIZE, PANEL_IMAGE_SIZE);
            _boardGraphics[_dimensions.getHeight() - 1][k]->_visibility = visible;

            // Ignore Garbage Part
            ClearGarbageData(_boardLogic[_dimensions.getHeight() - 1][k]);

            // Make sure the current panel is different from the previous.
            __type_above = _boardLogic[_dimensions.getHeight() - 1][k]->_type;
            char __random_type = Utils::GetNextTypeWithoutRepetition(__previous_type, __type_above);
            __previous_type = __random_type;

            // Create next row graphics and update logics.
            _nextRowGraphics[k]->SetAsset(Utils::DecodeType(__random_type, _spriteManager, PANEL_DARK_SPRITE),
                                          PANEL_IMAGE_SIZE, PANEL_IMAGE_SIZE);
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
            if (_swapTarget->getY() != 0)
            {
                _swapTarget->setY(_swapTarget->getY() - 1);

                _boardGraphics[_swapTarget->getY()][_swapTarget->getX()]->_visibility = hidden;
                _boardGraphics[_swapTarget->getY()][_swapTarget->getX() + 1]->_visibility = hidden;

                _leftSwap->_y -= PANEL_IMAGE_SIZE;
                _rightSwap->_y -= PANEL_IMAGE_SIZE;
            }
        }

        // Update board container and next row position.
        _boardContainer->_y += PANEL_IMAGE_SIZE + PANEL_IMAGE_SPACE;
        _intialY = _boardContainer->_y;
        _cursor->_y += PANEL_IMAGE_SIZE + PANEL_IMAGE_SPACE;
        _nextRowContainer->_y = (PANEL_IMAGE_SIZE + PANEL_IMAGE_SPACE) * _dimensions.getHeight();
    }

    // Implements Garbage Operation
    // @param change: Change operation binary code.
    private: void GarbageOperation(Change change)
    {
        // Extract Operation Operands
        unsigned int __garbageWidth = ExtractGarbageWidth(change);
        unsigned int __garbageHeight = ExtractGarbageHeight(change);
        unsigned int __garbagePosition = ExtractGarbagePosition(change);

        // Build new garbage object.
        MakeGarbage(__garbageWidth, __garbageHeight, __garbagePosition);
    }

    // Implements Garbage Operation
    // @param change: Change operation binary code.
    private: void SendGarbage(Change change)
    {
        // Extract Operation Operands
        unsigned int __garbageWidth = ExtractGarbageWidth(change);
        unsigned int __garbageHeight = ExtractGarbageHeight(change);
        unsigned int __garbagePosition = ExtractGarbagePosition(change);
        // Build new garbage object.
        _rival->MakeGarbage(__garbageWidth, __garbageHeight, __garbagePosition);
    }

    // Implements Transform Garbage Operation.
    // @param change: Change operation binary code.
    private: void TransformGarbageOperation(Change change)
    {
        // Extract Operation Operands
        unsigned int __garbageSourceX = ExtractTargetPanelX(change);
        unsigned int __garbageSourceY = ExtractTargetPanelY(change);
        unsigned int __transformationType = ExtractGarbageTransformationType(change);
        unsigned int __isGarbageSource = ExtractPanelIsGarbageSource(change);

        Point2D __panel;
        __panel.setX(__garbageSourceX);
        __panel.setY(__garbageSourceY);
        _transformingPanels.push_back(__panel);

        if (__transformationType == GARBAGE_TARNSFORMATION_TO_PANEL)
        {
          // Update garbage object to reflect break state. +20 is an initial delay used to display the transformation animation.
          _boardLogic[__garbageSourceY][__garbageSourceX]->_wait = 15*(_frameBreakingGarbage++ + 1.2) + 40;
          _boardLogic[__garbageSourceY][__garbageSourceX]->_break_delay = 0;
          _boardLogic[__garbageSourceY][__garbageSourceX]->_in_chain = 0;
          _boardLogic[__garbageSourceY][__garbageSourceX]->_state = 15;

          _boardGraphics[__garbageSourceY][__garbageSourceX]->SetAsset(Utils::GarbageIntermediate(_pokemonType, _spriteManager),
                                                                       PANEL_IMAGE_SIZE, PANEL_IMAGE_SIZE);
          _boardGraphics[__garbageSourceY][__garbageSourceX]->_visibility = visible;
          // Show transformation initial animation only for the garbage origin
          if (__isGarbageSource == 1)
          {
            // Show Garbage transformation animation
            ShowGarbageTransformationAnimation(_boardLogic[__garbageSourceY][__garbageSourceX]->_width, _boardLogic[__garbageSourceY][__garbageSourceX]->_height, __garbageSourceY, __garbageSourceX);
          }
          ClearGarbageData(_boardLogic[__garbageSourceY][__garbageSourceX]);
        }
        else
        {
          // Update garbage object to reflect break state. +20 is an initial delay used to display the transformation animation.
          _boardLogic[__garbageSourceY][__garbageSourceX]->_wait = 15*(_frameBreakingGarbage++ + 1.2) + 40;
          _boardLogic[__garbageSourceY][__garbageSourceX]->_break_delay = 0;
          _boardLogic[__garbageSourceY][__garbageSourceX]->_in_chain = 0;
          _boardLogic[__garbageSourceY][__garbageSourceX]->_state = 16;

          _boardGraphics[__garbageSourceY][__garbageSourceX]->SetAsset(Utils::GarbageIntermediate(_pokemonType, _spriteManager),
                                                                       PANEL_IMAGE_SIZE, PANEL_IMAGE_SIZE);
          _boardGraphics[__garbageSourceY][__garbageSourceX]->_visibility = visible;
        }
    }

    // SHow garbage animation when it is broken. If hwight and width are zero, a single panel animation will be shown.
    // @param width: Garbage width;
    // @param height: Garbage height;
    // @param i: vertical position;
    // @param j: horizontal position;
    private: void ShowGarbageTransformationAnimation(int width, int height, int i, int j)
    {
        Sprite * _alphaAnimation;
        if (width == 0 && height == 0)
        {
          _alphaAnimation = new Sprite(_spriteManager->_blockMask0008, 116, 116);
          _alphaAnimation->_x = _boardGraphics[i][j]->_x - 43;
          _alphaAnimation->_y = _boardGraphics[i][j]->_y - 43;
          _alphaAnimation->_alpha = 0;
          SpriteProperties _alphaProperty(_alphaAnimation);
          _alphaProperty.RegisterPropertyFinalValue(SpriteAlpha, 255);
          AnimationEngine::RegisterTween(_alphaAnimation, _alphaProperty, 155.0, EaseInLinear, 0, true, EaseOutLinear, true);
          _boardContainer->AddChild(_alphaAnimation);
        }
        else if (height == 1)
        {
          switch (width)
          {
            case 3:
            {
              _alphaAnimation = new Sprite(_spriteManager->_x3_mask0008, 176, 116);
              _alphaAnimation->_x = _boardGraphics[i][j]->_x - 43;
              _alphaAnimation->_y = _boardGraphics[i][j]->_y - 43;
              _alphaAnimation->_alpha = 0;
              SpriteProperties _alphaProperty(_alphaAnimation);
              _alphaProperty.RegisterPropertyFinalValue(SpriteAlpha, 255);
              AnimationEngine::RegisterTween(_alphaAnimation, _alphaProperty, 305.0, EaseInLinear, 0, true, EaseOutLinear, true);
              _boardContainer->AddChild(_alphaAnimation);
              break;
            }
            case 4:
            {
              _alphaAnimation = new Sprite(_spriteManager->_x4_mask0008, 208, 116);
              _alphaAnimation->_x = _boardGraphics[i][j]->_x - 43;
              _alphaAnimation->_y = _boardGraphics[i][j]->_y - 43;
              _alphaAnimation->_alpha = 0;
              SpriteProperties _alphaProperty(_alphaAnimation);
              _alphaProperty.RegisterPropertyFinalValue(SpriteAlpha, 255);
              AnimationEngine::RegisterTween(_alphaAnimation, _alphaProperty, 305.0, EaseInLinear, 0, true, EaseOutLinear, true);
              _boardContainer->AddChild(_alphaAnimation);
              break;
            }
            case 5:
            {
              _alphaAnimation = new Sprite(_spriteManager->_x5_mask0008, 236, 116);
              _alphaAnimation->_x = _boardGraphics[i][j]->_x - 43;
              _alphaAnimation->_y = _boardGraphics[i][j]->_y - 43;
              _alphaAnimation->_alpha = 0;
              SpriteProperties _alphaProperty(_alphaAnimation);
              _alphaProperty.RegisterPropertyFinalValue(SpriteAlpha, 255);
              AnimationEngine::RegisterTween(_alphaAnimation, _alphaProperty, 305.0, EaseInLinear, 0, true, EaseOutLinear, true);
              _boardContainer->AddChild(_alphaAnimation);
              break;
            }
            case 6:
            {
              _alphaAnimation = new Sprite(_spriteManager->_x6_mask0008, 272, 116);
              _alphaAnimation->_x = _boardGraphics[i][j]->_x - 43;
              _alphaAnimation->_y = _boardGraphics[i][j]->_y - 43;
              _alphaAnimation->_alpha = 0;
              SpriteProperties _alphaProperty(_alphaAnimation);
              _alphaProperty.RegisterPropertyFinalValue(SpriteAlpha, 255);
              AnimationEngine::RegisterTween(_alphaAnimation, _alphaProperty, 305.0, EaseInLinear, 0, true, EaseOutLinear, true);
              _boardContainer->AddChild(_alphaAnimation);
              break;
            }
          }
        }
        else
        {
          switch (height)
          {
            case 2:
            {
              _alphaAnimation = new Sprite(_spriteManager->_xc1_mask0008, 272, 148);
              _alphaAnimation->_x = _boardGraphics[i][j]->_x - 43;
              _alphaAnimation->_y = _boardGraphics[i][j]->_y - (43 + (height - 1)*PANEL_IMAGE_SIZE);
              _alphaAnimation->_alpha = 0;
              SpriteProperties _alphaProperty(_alphaAnimation);
              _alphaProperty.RegisterPropertyFinalValue(SpriteAlpha, 255);
              AnimationEngine::RegisterTween(_alphaAnimation, _alphaProperty, 305.0, EaseInLinear, 0, true, EaseOutLinear, true);
              _boardContainer->AddChild(_alphaAnimation);
              break;
            }
            case 3:
            {
              _alphaAnimation = new Sprite(_spriteManager->_xc2_mask0008, 272, 176);
              _alphaAnimation->_x = _boardGraphics[i][j]->_x - 43;
              _alphaAnimation->_y = _boardGraphics[i][j]->_y - (43 + (height - 1)*PANEL_IMAGE_SIZE);
              _alphaAnimation->_alpha = 0;
              SpriteProperties _alphaProperty(_alphaAnimation);
              _alphaProperty.RegisterPropertyFinalValue(SpriteAlpha, 255);
              AnimationEngine::RegisterTween(_alphaAnimation, _alphaProperty, 305.0, EaseInLinear, 0, true, EaseOutLinear, true);
              _boardContainer->AddChild(_alphaAnimation);
              break;
            }
            case 4:
            {
              _alphaAnimation = new Sprite(_spriteManager->_xc3_mask0008, 272, 212);
              _alphaAnimation->_x = _boardGraphics[i][j]->_x - 43;
              _alphaAnimation->_y = _boardGraphics[i][j]->_y - (43 + (height - 1)*PANEL_IMAGE_SIZE);
              _alphaAnimation->_alpha = 0;
              SpriteProperties _alphaProperty(_alphaAnimation);
              _alphaProperty.RegisterPropertyFinalValue(SpriteAlpha, 255);
              AnimationEngine::RegisterTween(_alphaAnimation, _alphaProperty, 305.0, EaseInLinear, 0, true, EaseOutLinear, true);
              _boardContainer->AddChild(_alphaAnimation);
              break;
            }
            case 5:
            {
              _alphaAnimation = new Sprite(_spriteManager->_xc4_mask0008, 272, 244);
              _alphaAnimation->_x = _boardGraphics[i][j]->_x - 43;
              _alphaAnimation->_y = _boardGraphics[i][j]->_y - (43 + (height - 1)*PANEL_IMAGE_SIZE);
              _alphaAnimation->_alpha = 0;
              SpriteProperties _alphaProperty(_alphaAnimation);
              _alphaProperty.RegisterPropertyFinalValue(SpriteAlpha, 255);
              AnimationEngine::RegisterTween(_alphaAnimation, _alphaProperty, 305.0, EaseInLinear, 0, true, EaseOutLinear, true);
              _boardContainer->AddChild(_alphaAnimation);
              break;
            }
            case 6:
            {
              _alphaAnimation = new Sprite(_spriteManager->_xc5_mask0008, 272, 268);
              _alphaAnimation->_x = _boardGraphics[i][j]->_x - 43;
              _alphaAnimation->_y = _boardGraphics[i][j]->_y - (43 + (height - 1)*PANEL_IMAGE_SIZE);
              _alphaAnimation->_alpha = 0;
              SpriteProperties _alphaProperty(_alphaAnimation);
              _alphaProperty.RegisterPropertyFinalValue(SpriteAlpha, 255);
              AnimationEngine::RegisterTween(_alphaAnimation, _alphaProperty, 305.0, EaseInLinear, 0, true, EaseOutLinear, true);
              _boardContainer->AddChild(_alphaAnimation);
              break;
            }
            case 7:
            {
              _alphaAnimation = new Sprite(_spriteManager->_xc6_mask0008, 272, 304);
              _alphaAnimation->_x = _boardGraphics[i][j]->_x - 43;
              _alphaAnimation->_y = _boardGraphics[i][j]->_y - (43 + (height - 1)*PANEL_IMAGE_SIZE);
              _alphaAnimation->_alpha = 0;
              SpriteProperties _alphaProperty(_alphaAnimation);
              _alphaProperty.RegisterPropertyFinalValue(SpriteAlpha, 255);
              AnimationEngine::RegisterTween(_alphaAnimation, _alphaProperty, 305.0, EaseInLinear, 0, true, EaseOutLinear, true);
              _boardContainer->AddChild(_alphaAnimation);
              break;
            }
            case 8:
            {
              _alphaAnimation = new Sprite(_spriteManager->_xc7_mask0008, 272, 336);
              _alphaAnimation->_x = _boardGraphics[i][j]->_x - 43;
              _alphaAnimation->_y = _boardGraphics[i][j]->_y - (43 + (height - 1)*PANEL_IMAGE_SIZE);
              _alphaAnimation->_alpha = 0;
              SpriteProperties _alphaProperty(_alphaAnimation);
              _alphaProperty.RegisterPropertyFinalValue(SpriteAlpha, 255);
              AnimationEngine::RegisterTween(_alphaAnimation, _alphaProperty, 305.0, EaseInLinear, 0, true, EaseOutLinear, true);
              _boardContainer->AddChild(_alphaAnimation);
              break;
            }
            case 9:
            {
              _alphaAnimation = new Sprite(_spriteManager->_xc8_mask0008, 272, 364);
              _alphaAnimation->_x = _boardGraphics[i][j]->_x - 43;
              _alphaAnimation->_y = _boardGraphics[i][j]->_y - (43 + (height - 1)*PANEL_IMAGE_SIZE);
              _alphaAnimation->_alpha = 0;
              SpriteProperties _alphaProperty(_alphaAnimation);
              _alphaProperty.RegisterPropertyFinalValue(SpriteAlpha, 255);
              AnimationEngine::RegisterTween(_alphaAnimation, _alphaProperty, 305.0, EaseInLinear, 0, true, EaseOutLinear, true);
              _boardContainer->AddChild(_alphaAnimation);
              break;
            }
            case 10:
            {
              _alphaAnimation = new Sprite(_spriteManager->_xc9_mask0008, 272, 396);
              _alphaAnimation->_x = _boardGraphics[i][j]->_x - 43;
              _alphaAnimation->_y = _boardGraphics[i][j]->_y - (43 + (height - 1)*PANEL_IMAGE_SIZE);
              _alphaAnimation->_alpha = 0;
              SpriteProperties _alphaProperty(_alphaAnimation);
              _alphaProperty.RegisterPropertyFinalValue(SpriteAlpha, 255);
              AnimationEngine::RegisterTween(_alphaAnimation, _alphaProperty, 305.0, EaseInLinear, 0, true, EaseOutLinear, true);
              _boardContainer->AddChild(_alphaAnimation);
              break;
            }
            case 11:
            {
              _alphaAnimation = new Sprite(_spriteManager->_xc10_mask0008, 272, 424);
              _alphaAnimation->_x = _boardGraphics[i][j]->_x - 43;
              _alphaAnimation->_y = _boardGraphics[i][j]->_y - (43 + (height - 1)*PANEL_IMAGE_SIZE);
              _alphaAnimation->_alpha = 0;
              SpriteProperties _alphaProperty(_alphaAnimation);
              _alphaProperty.RegisterPropertyFinalValue(SpriteAlpha, 255);
              AnimationEngine::RegisterTween(_alphaAnimation, _alphaProperty, 305.0, EaseInLinear, 0, true, EaseOutLinear, true);
              _boardContainer->AddChild(_alphaAnimation);
              break;
            }
          }
        }
    }

    // Implements Rumble Operation.
    // @param change: Change operation binary code.
    private: void RumbleOperation (Change change)
    {
        unsigned int __rumbleLength = ExtractRumbleLength(change);
        _wiiremote->RumbleFor(__rumbleLength);
    }

    // Implements Rise Board Operation.
    private: void RiseBoardOperation()
    {
        _boardContainer->_y--;
        _intialY = _boardContainer->_y;
    }

    // Create a concrete garbage object.
    private: void MakeConcreteGargabe ()
    {
        LogicPanel ** __garbageSlice  = new LogicPanel *[_dimensions.getWidth()];
        for (int i = 0; i < _dimensions.getWidth(); i++)
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
            __garbageSlice[i]->_break_delay = 0;
            __garbageSlice[i]->_in_chain = 0;
            __garbageSlice[i]->_state = 0;
        }

        for (int i = 0; i < _dimensions.getWidth(); i++)
        {
            __garbageSlice[i]->_type = PANEL_CONCRETE_GARBAGE_TYPE;
            __garbageSlice[i]->_sourceX = 0;
            __garbageSlice[i]->_sourceY = 0;
            __garbageSlice[i]->_width = _dimensions.getWidth();
            __garbageSlice[i]->_height = 1;
            __garbageSlice[i]->_positionX = i;
            __garbageSlice[i]->_positionY = 0;
            __garbageSlice[i]->_wait = 0;
            __garbageSlice[i]->_break_delay = 0;
            __garbageSlice[i]->_in_chain = 0;
            __garbageSlice[i]->_state = 0;
        }
        _garbageList.push_back(__garbageSlice);
        EmitGarbageFallingSequence ();
    }


    // Implements Transform Garbage Operation.
    // @param change: Change operation binary code.
    private: void PanelOperationAnimation (Change change)
    {
        // Extract Operation Operands
        unsigned int __targetX = ExtractTargetPanelX(change);
        unsigned int __targetY = ExtractTargetPanelY(change);

        // Extract extra derived information
        int __targetType = _boardLogic[__targetY][__targetX]->_type;

        _boardGraphics[__targetY][__targetX]->_visibility = hidden;

        // Show Break animation
        Sprite * _break = _animationManager->GeneratePanelOperationAnimation(__targetType);
        _break->SetRepeat(false);
        _break->Play();
        _break->_animation_delay = 1;
        _break->_x = _boardGraphics[__targetY][__targetX]->_x;
        _break->_y = _boardGraphics[__targetY][__targetX]->_y - 64;
        _boardContainer->AddChild(_break);
    }

    // Helper function: Ignore garbage only information in a logic panel object.
    // @param panel: target logic panel.
    private: void ClearGarbageData (LogicPanel * panel)
    {
        panel->_sourceX = -1;
        panel->_sourceY = -1;
        panel->_width = 0;
        panel->_height = 0;
        panel->_positionX = -1;
        panel->_positionY = -1;
    }

    // Initialize Swap sprites.
    private: void InitializeSwapSprites ()
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


    // Register a combo and its location.
    private: void ScoreCombo (Change change)
    {
        // Extract Operation Operands
        int __targetX = ExtractTargetPanelX(change);
        int __targetY = ExtractTargetPanelY(change);
        unsigned int __combo_size = ExtractComboSize(change);

        // Bubble Body
        Sprite * _combo = _animationManager->GenerateBubbleAnimation(__combo_size);
        _combo->SetRepeat(false);
        _combo->Play();
        _combo->_animation_delay = 1;

        // Bubble Content
        Sprite * _number = Utils::GetComboNumber(__combo_size, _spriteManager);
        _animationManager->RegisterBubbleNumberAnimation(_number);
        _number->Play();
        _number->_animation_delay = 1;
        _combo->AddChild(_number);

        // Adjust position of the combo bubble so that it fits correctly in the detection position
        // The initial position of the board is added to the animation sprite since it will be added
        // to the stage graphic three.
        _combo->_x = _boardGraphics[__targetY][__targetX]->_x + COMBO_POSITION_X_OFFSET + _position.getX();
        _combo->_y = _boardGraphics[__targetY][__targetX]->_y + 0.1*COMBO_POSITION_Y_OFFSET + _position.getY();

        GraphicEngine::_stage->AddChild(_combo);

        SpriteProperties __comboProperties(_combo);
        __comboProperties.RegisterPropertyFinalValue(SpriteY, _combo->_y - 3.0*COMBO_POSITION_Y_OFFSET_FINAL + _position.getY());
        AnimationEngine::RegisterTween(_combo, __comboProperties, 1400.0, EaseInCubic);
    }

    // Register a chain and its location.
    private: void ScoreChain (Change change)
    {
        // Extract Operation Operands
        int __targetX = ExtractTargetPanelX(change);
        int __targetY = ExtractTargetPanelY(change);
        unsigned int __chain_size = ExtractChainValue(change);

        // Bubble Body
        Sprite * _chain = _animationManager->GenerateBubbleAnimation(__chain_size);
        _chain->SetRepeat(false);
        _chain->Play();
        _chain->_animation_delay = 1;

        // Bubble Content
        Sprite * _number = Utils::GetChainNumber(__chain_size, _spriteManager);
        _animationManager->RegisterBubbleNumberAnimation(_number, true);
        _number->Play();
        _number->_animation_delay = 1;
        _chain->AddChild(_number);

        // Adjust position of the combo bubble so that it fits correctly in the detection position
        // The initial position of the board is added to the animation sprite since it will be added
        // to the stage graphic three.
        _chain->_x = _boardGraphics[__targetY][__targetX]->_x + COMBO_POSITION_X_OFFSET + _position.getX();
        _chain->_y = _boardGraphics[__targetY][__targetX]->_y + 0.1*COMBO_POSITION_Y_OFFSET + _position.getY();

        GraphicEngine::_stage->AddChild(_chain);

        SpriteProperties __chainProperties(_chain);
        __chainProperties.RegisterPropertyFinalValue(SpriteY, _chain->_y - 3.8*COMBO_POSITION_Y_OFFSET_FINAL + _position.getY());
        AnimationEngine::RegisterTween(_chain, __chainProperties, 1400.0, EaseInCubic);
    }

    // Disable chain chances in panels.
    private: void CancelChain(Change change)
    {
        unsigned int __targetX = ExtractTargetPanelX(change);
        unsigned int __targetY = ExtractTargetPanelY(change);
        unsigned int __value = ExtractChainValue(change);

        _boardLogic[__targetY][__targetX]->_in_chain = __value;
    }

    // Performs swap animation.
    private: void AnimateSwap (unsigned int i, unsigned int j)
    {
        // Swap Animation Sprite
        unsigned int __right_type = _boardLogic[i][j]->_type == PANEL_VOID_TYPE? PANEL_RED_TYPE : _boardLogic[i][j]->_type;
        _leftSwap->SetAsset(Utils::DecodeType(__right_type, _spriteManager), PANEL_IMAGE_SIZE, PANEL_IMAGE_SIZE);

        if (_boardLogic[i][j]->_type != PANEL_VOID_TYPE)
            _leftSwap->_visibility = visible;
        else
            _leftSwap->_visibility = hidden;

        _leftSwap->_x = _boardGraphics[i][j]->_x;
        _leftSwap->_y = _boardGraphics[i][j]->_y;

        _boardGraphics[i][j]->_visibility = hidden;

        SpriteProperties __left_properties(_leftSwap);
        __left_properties.RegisterPropertyFinalValue(SpriteX, _boardGraphics[i][j + 1]->_x);
        AnimationEngine::RegisterTween(_leftSwap, __left_properties, 85.0, EaseInCubic);

        unsigned int __left_type = _boardLogic[i][j + 1]->_type == PANEL_VOID_TYPE? PANEL_RED_TYPE : _boardLogic[i][j + 1]->_type;
        _rightSwap->SetAsset(Utils::DecodeType(__left_type, _spriteManager), PANEL_IMAGE_SIZE, PANEL_IMAGE_SIZE);

        if (_boardLogic[i][j + 1]->_type != PANEL_VOID_TYPE)
            _rightSwap->_visibility = visible;
        else
            _rightSwap->_visibility = hidden;

        _rightSwap->_x = _boardGraphics[i][j + 1]->_x;
        _rightSwap->_y = _boardGraphics[i][j + 1]->_y;

        _boardGraphics[i][j + 1]->_visibility = hidden;

        SpriteProperties __right_properties(_rightSwap);
        __right_properties.RegisterPropertyFinalValue(SpriteX, _boardGraphics[i][j]->_x);
        AnimationEngine::RegisterTween(_rightSwap, __right_properties, 85.0, EaseInCubic);
    }

    // Frees swap animation.
    private: void CompleteSwap ()
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
            _boardGraphics[__targetY][__targetX]->SetAsset(Utils::DecodeType(__destinationType, _spriteManager),
                                                           PANEL_IMAGE_SIZE, PANEL_IMAGE_SIZE);
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
            _boardGraphics[__destinationY][__destinationX]->SetAsset(Utils::DecodeType(__targetType, _spriteManager),
                                                                     PANEL_IMAGE_SIZE, PANEL_IMAGE_SIZE);
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
        _boardLogic[__targetY][__targetX]->_wait = 0;
        _boardLogic[__targetY][__targetX]->_break_delay = 0;

        // Update destination logic data.
        _boardLogic[__destinationY][__destinationX]->_type = __targetType;
        _boardLogic[__destinationY][__destinationX]->_state = 0;
        _boardLogic[__destinationY][__destinationX]->_wait = 0;
        _boardLogic[__destinationY][__destinationX]->_break_delay = 0;

        // Ignore Garbage Part
        ClearGarbageData(_boardLogic[__targetY][__targetX]);
        ClearGarbageData(_boardLogic[__destinationY][__destinationX]);

        _leftSwap->_visibility = hidden;
        _rightSwap->_visibility = hidden;

        _isSwapping = false;
    }

    // Update graphics attributes at each frame.
    public: void UpdateGraphics ()
    {
        // Update Graphics;
        CompleteSwap();
        UpdateShake();
        AnimateGarbageBadges();
        UpdateGarbageDestruction();
        UpdateAlertShake();
    }

    // Update the animation of each garbage being destroyed
    private: void UpdateGarbageDestruction()
    {
        if (_frameBreakingGarbage != 0)
        {
            // Update Fall Delay for the garbages under transformation
            for (unsigned int i = 0; i < _transformingPanels.size(); i++)
            {
                int __x = _transformingPanels[i].getX();
                int __y = _transformingPanels[i].getY();

                _boardLogic[__y][__x]->_break_delay = 15 * (_frameBreakingGarbage--);
            }
            _transformingPanels.clear();
            // Clear total breaking garbage counter;
            _frameBreakingGarbage = 0;
        }

        // Find panels in state 15 and decrease their wait state until it reaches 0
        for (int j = 0; j < _dimensions.getWidth(); j++)
            for (int i = 0; i < _dimensions.getHeight() - 1; i++)
            {
                if (_boardLogic[i][j]->_state == 15)
                {
                    // Check if the garbage panel is supposed to change its appearance.
                    if (_boardLogic[i][j]->_wait == 0)
                    {
                        // Transform garbage into panel
                        if (_boardLogic[i][j]->_type == PANEL_GARBAGE_TYPE || _boardLogic[i][j]->_type == PANEL_CONCRETE_GARBAGE_TYPE)
                        {
                          // Make sure the current panel is different from the previous.
                          char __previous_type = -1;
                          if (j > 0)
                          {
                            __previous_type = _boardLogic[i][j - 1]->_type;
                          }
                          char __random_type = Utils::GetNextTypeWithoutRepetition(__previous_type);

                          // Create new panels in the place of the
                          _boardLogic[i][j]->_type = __random_type;

                          // Update sprite
                          _boardGraphics[i][j]->SetAsset(Utils::DecodeType(_boardLogic[i][j]->_type, _spriteManager),
                                                         PANEL_IMAGE_SIZE, PANEL_IMAGE_SIZE);
                        }

                        // Update Delay -> The panel will only be freed if the delay reaches 0 (it is actually waiting for all panels to finish transforming).
                        if (_boardLogic[i][j]->_break_delay != 0)
                        {
                            _boardLogic[i][j]->_break_delay--;
                            continue;
                        }
                        else
                        {
                            // Update panel status
                            _boardLogic[i][j]->_state = 0;
                            _boardLogic[i][j]->_in_chain = 1;
                        }
                    }
                    else
                    {
                        _boardLogic[i][j]->_wait--;
                        if (_boardLogic[i][j]->_wait == 13)
                        {
                          ShowGarbageTransformationAnimation(0, 0, i, j);
                        }
                        // Keep the board wating while the garbage breaks.
                        _slideDelay = 1;
                    }
                }
                else if (_boardLogic[i][j]->_state == 16)
                {
                    // Check if the garbage panel is supposed to change its appearance.
                    if (_boardLogic[i][j]->_wait == 0)
                    {
                        if (_boardLogic[i][j]->_positionX == 0 && _boardLogic[i][j]->_positionY == 0)
                        {
                          _boardGraphics[i][j]->_visibility = visible;
                          _boardContainer->RemoveChild(_boardGraphics[i][j]);
                          _boardContainer->AddChildAt(_boardGraphics[i][j], 0);
                          DisplayGarbageSprite(i, j);
                        }
                        else
                        {
                          _boardGraphics[i][j]->_visibility = hidden;
                        }

                        // Update Delay -> The panel will only be freed if the delay reaches 0 (it is actually waiting for all panels to finish transforming).
                        if (_boardLogic[i][j]->_break_delay != 0)
                        {
                            _boardLogic[i][j]->_break_delay--;
                            continue;
                        }
                        else
                        {
                            // Update panel status
                            if (_boardLogic[i][j]->_positionX == 0 && _boardLogic[i][j]->_positionY == 0)
                            {
                              CheckAndFreeGarbageIfNeeded (i, j);
                              _boardGraphics[i][j]->_visibility = visible;
                            }
                        }
                    }
                    else
                    {
                        _boardLogic[i][j]->_wait--;
                        // Keep the board wating while the garbage breaks.
                        if (_boardLogic[i][j]->_wait == 13)
                        {
                          ShowGarbageTransformationAnimation(0, 0, i, j);
                        }
                        _slideDelay = 1;
                    }
                }
            }
    }

    private: void CheckAndFreeGarbageIfNeeded (int targetY, int targetX)
    {
        int __garbageWidth = _boardLogic[targetY][targetX]->_width;
        int __garbageHeight = _boardLogic[targetY][targetX]->_height;

        // Check if the garbage have finished transforming.
        for (int i = targetY; i > targetY - __garbageHeight; i--)
        {
          // check board bounds;
          if (i < 0)
            break;
          for (int j = targetX; j < __garbageWidth; j++)
          {
              // Check if some panel is still animating
              if (_boardLogic[i][j]->_wait != 0)
              {
                  return;
              }
          }
        }

        for (int i = targetY; i > targetY - __garbageHeight; i--)
        {
          // check board bounds;
          if (i < 0)
            break;
          for (int j = targetX; j < __garbageWidth; j++)
          {
              // The only case when this if will trigger is when freeing the last garbage of a multi row garbage.
              // This will happen since this method is ran by the source block. At the time all panels have wait 0,
              // the last panel in the garbage will not have been analyzed (to hide is sprite), but it will have
              // already 0 wait (computed in the previous frame).
              if (_boardGraphics[i][j]->_visibility != hidden)
              {
                _boardGraphics[i][j]->_visibility = hidden;
              }
              _boardLogic[i][j]->_state = 0;
          }
        }
    }

    public: void ShakeBoard (int numberOfSamples)
    {
        _shakeSamples.clear();

        //Compute Samples
        for(int i = numberOfSamples - 1; i >= 0; i--)
        {
            if (i%2 == 0)
            {
                _shakeSamples.push_back((1.0*((float)(i)/(float)numberOfSamples)));
            }
            else
            {
                _shakeSamples.push_back(0);
            }
        }
        _currentShakeFrame = 0;
        AudioEngine::PlaySFX(_garbage_fall1);
    }

    // Update shake animation on a frame base.
    public: void UpdateShake ()
    {
        if ((unsigned int)_currentShakeFrame < _shakeSamples.size())
        {
            _boardOuterContainer->_y = 12*_shakeSamples[_currentShakeFrame];
            _currentShakeFrame++;
        }
        else
        {
            _currentShakeFrame = 0;
            _shakeSamples.clear();
        }
    }

    private: void PauseBoard(Change change)
    {
      unsigned int __duration = ExtractPausePeriod(change);
      if (__duration != 0)
        _slideDelay = __duration;
    }

    // Check if the board is in alert status
    public: void CheckAlert ()
    {
        _rules->BoardAlert(_boardLogic, _dimensions.getWidth(), _dimensions.getHeight(), _changes);
    }

    public: void ShakeColumn (Change change)
    {
        int __targetColumn = ExtractTargetShakeColumn(change);
        // Each column is stored as a 1 in the vaiable like
        // 0 1 0 0 1 0 -> only the second and the firth columns shall shake.
        _shakeColumnMap |= __targetColumn;
    }

    public: void UpdateAlertShake ()
    {
        for (int i = 0; i < _dimensions.getWidth(); i++)
        {
            if ((_shakeColumnMap>>i)&1) // Update alert shake animation
            {
                if (_shakeDelay == ALERT_SHAKE_DELAY)
                {
                  for (int j = 0; j < _dimensions.getHeight(); j++)
                  {
                      if (_boardLogic[j][i]->_type != PANEL_VOID_TYPE &&
                      _boardLogic[j][i]->_type != PANEL_GARBAGE_TYPE &&
                      _boardLogic[j][i]->_type != PANEL_CONCRETE_GARBAGE_TYPE)
                      {
                        _boardGraphics[j][i]->SetAsset(Utils::DecodeType(_boardLogic[j][i]->_type, _spriteManager, _shakeFrame),
                                                       PANEL_IMAGE_SIZE, PANEL_IMAGE_SIZE);
                      }
                  }
                }
            }
            else if ((_previousShakeColumnMap>>i)&1) // Restore sprites to original
            {
              for (int j = 0; j < _dimensions.getHeight(); j++)
              {
                  if (_boardLogic[j][i]->_type != PANEL_VOID_TYPE &&
                  _boardLogic[j][i]->_type != PANEL_GARBAGE_TYPE &&
                  _boardLogic[j][i]->_type != PANEL_CONCRETE_GARBAGE_TYPE)
                  {
                    _boardGraphics[j][i]->SetAsset(Utils::DecodeType(_boardLogic[j][i]->_type, _spriteManager, PANEL_NORMAL_SPRITE),
                                                   PANEL_IMAGE_SIZE, PANEL_IMAGE_SIZE);
                  }
              }
            }
        }
        // Update Delay
        if (_shakeDelay == ALERT_SHAKE_DELAY)
        {
          _shakeFrame++;
          _shakeDelay = 0;
        }
        else
        {
          _shakeDelay++;
        }
        if (_shakeFrame >= PANEL_SHAKE_FRAME_10)
        {
          _shakeFrame = PANEL_SHAKE_FRAME_1;
        }
        // Store data for next frame.
        _previousShakeColumnMap = _shakeColumnMap;
        _shakeColumnMap = 0;
    }

    // Default Constructor
    public: ~Board ();
};

#endif // __BOARD__
