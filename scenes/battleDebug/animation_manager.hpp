#ifndef __ANIMATION_MANAGER__
#define __ANIMATION_MANAGER__

#include "sprite_manager.hpp"
#include "board_constants.hpp"

class AnimationManager
{
    private: SpriteManager * _spriteManager;

    public: AnimationManager (SpriteManager * spriteManager)
    {
        _spriteManager = spriteManager;
    }

    public: void RegisterBubbleNumberAnimation (Sprite * sprite, bool IsChain = false)
    {
        Point2D __point;
        if (!IsChain)
        {
          __point.setX(31);
          __point.setY(103);
        }
        else
        {
          __point.setX(27);
          __point.setY(104);
        }
        Transformation __tranform;
        __tranform.RegisterFullAbsoluteTransformation(__point, 0, 1, 1, 0);
        sprite->RegisterFrameWithTransformation(sprite->GetTexture(), __tranform);
        __tranform.RegisterFullAbsoluteTransformation(__point, 0, 1, 1, 15);
        sprite->RegisterFrameWithTransformation(sprite->GetTexture(), __tranform);
        __tranform.RegisterFullAbsoluteTransformation(__point, 0, 1, 1, 35);
        sprite->RegisterFrameWithTransformation(sprite->GetTexture(), __tranform);
        __tranform.RegisterFullAbsoluteTransformation(__point, 0, 1, 1, 45);
        sprite->RegisterFrameWithTransformation(sprite->GetTexture(), __tranform);
        __tranform.RegisterFullAbsoluteTransformation(__point, 0, 1, 1, 55);
        sprite->RegisterFrameWithTransformation(sprite->GetTexture(), __tranform);
        __tranform.RegisterFullAbsoluteTransformation(__point, 0, 1, 1, 65);
        sprite->RegisterFrameWithTransformation(sprite->GetTexture(), __tranform);
        __tranform.RegisterFullAbsoluteTransformation(__point, 0, 1, 1, 75);
        sprite->RegisterFrameWithTransformation(sprite->GetTexture(), __tranform);
        __tranform.RegisterFullAbsoluteTransformation(__point, 0, 1, 1, 85);
        sprite->RegisterFrameWithTransformation(sprite->GetTexture(), __tranform);
        __tranform.RegisterFullAbsoluteTransformation(__point, 0, 1, 1, 95);
        sprite->RegisterFrameWithTransformation(sprite->GetTexture(), __tranform);
        __tranform.RegisterFullAbsoluteTransformation(__point, 0, 1, 1, 105);
        sprite->RegisterFrameWithTransformation(sprite->GetTexture(), __tranform);
        __tranform.RegisterFullAbsoluteTransformation(__point, 0, 1, 1, 125);
        sprite->RegisterFrameWithTransformation(sprite->GetTexture(), __tranform);
        __tranform.RegisterFullAbsoluteTransformation(__point, 0, 1, 1, 235);
        sprite->RegisterFrameWithTransformation(sprite->GetTexture(), __tranform);
        __tranform.RegisterFullAbsoluteTransformation(__point, 0, 1, 1, 245);
        sprite->RegisterFrameWithTransformation(sprite->GetTexture(), __tranform);
        __tranform.RegisterFullAbsoluteTransformation(__point, 0, 1, 1, 255);
        sprite->RegisterFrameWithTransformation(sprite->GetTexture(), __tranform);
        sprite->RegisterFrameWithTransformation(sprite->GetTexture(), __tranform);
        sprite->RegisterFrameWithTransformation(sprite->GetTexture(), __tranform);
        sprite->RegisterFrameWithTransformation(sprite->GetTexture(), __tranform);
        sprite->RegisterFrameWithTransformation(sprite->GetTexture(), __tranform);
        sprite->RegisterFrameWithTransformation(sprite->GetTexture(), __tranform);
        sprite->RegisterFrameWithTransformation(sprite->GetTexture(), __tranform);
        sprite->RegisterFrameWithTransformation(sprite->GetTexture(), __tranform);
        sprite->RegisterFrameWithTransformation(sprite->GetTexture(), __tranform);
        sprite->RegisterFrameWithTransformation(sprite->GetTexture(), __tranform);
        sprite->RegisterFrameWithTransformation(sprite->GetTexture(), __tranform);
        sprite->RegisterFrameWithTransformation(sprite->GetTexture(), __tranform);
        sprite->RegisterFrameWithTransformation(sprite->GetTexture(), __tranform);
        sprite->RegisterFrameWithTransformation(sprite->GetTexture(), __tranform);
        sprite->RegisterFrameWithTransformation(sprite->GetTexture(), __tranform);
        sprite->RegisterFrameWithTransformation(sprite->GetTexture(), __tranform);
        sprite->RegisterFrameWithTransformation(sprite->GetTexture(), __tranform);
        sprite->RegisterFrameWithTransformation(sprite->GetTexture(), __tranform);
        sprite->RegisterFrameWithTransformation(sprite->GetTexture(), __tranform);
        sprite->RegisterFrameWithTransformation(sprite->GetTexture(), __tranform);
        sprite->RegisterFrameWithTransformation(sprite->GetTexture(), __tranform);
        sprite->RegisterFrameWithTransformation(sprite->GetTexture(), __tranform);
        sprite->RegisterFrameWithTransformation(sprite->GetTexture(), __tranform);
        sprite->RegisterFrameWithTransformation(sprite->GetTexture(), __tranform);
        __tranform.RegisterFullAbsoluteTransformation(__point, 0, 1, 1, 225);
        sprite->RegisterFrameWithTransformation(sprite->GetTexture(), __tranform);
        __tranform.RegisterFullAbsoluteTransformation(__point, 0, 1, 1, 165);
        sprite->RegisterFrameWithTransformation(sprite->GetTexture(), __tranform);
        __tranform.RegisterFullAbsoluteTransformation(__point, 0, 1, 1, 105);
        sprite->RegisterFrameWithTransformation(sprite->GetTexture(), __tranform);
        __tranform.RegisterFullAbsoluteTransformation(__point, 0, 1, 1, 75);
        sprite->RegisterFrameWithTransformation(sprite->GetTexture(), __tranform);
        __tranform.RegisterFullAbsoluteTransformation(__point, 0, 1, 1, 55);
        sprite->RegisterFrameWithTransformation(sprite->GetTexture(), __tranform);
        __tranform.RegisterFullAbsoluteTransformation(__point, 0, 1, 1, 15);
        sprite->RegisterFrameWithTransformation(sprite->GetTexture(), __tranform);
        __tranform.RegisterFullAbsoluteTransformation(__point, 0, 1, 1, 0);
        sprite->RegisterFrameWithTransformation(sprite->GetTexture(), __tranform);
        __tranform.RegisterFullAbsoluteTransformation(__point, 0, 1, 1, 0);
        sprite->RegisterFrameWithTransformation(sprite->GetTexture(), __tranform);
        __tranform.RegisterFullAbsoluteTransformation(__point, 0, 1, 1, 0);
        sprite->RegisterFrameWithTransformation(sprite->GetTexture(), __tranform);
        __tranform.RegisterFullAbsoluteTransformation(__point, 0, 1, 1, 0);
        sprite->RegisterFrameWithTransformation(sprite->GetTexture(), __tranform);
        __tranform.RegisterFullAbsoluteTransformation(__point, 0, 1, 1, 0);
        sprite->RegisterFrameWithTransformation(sprite->GetTexture(), __tranform);
    }

    public: Sprite * GenerateGarbageUIFlare (int player)
    {
        Sprite * _animation;
        if (player == PPL_PLAYER_1)
        {
            _animation = new Sprite(_spriteManager->_comboInterfaceAnimationP1_0001, 452, 84);
            _animation->RegisterFrame(_spriteManager->_comboInterfaceAnimationP1_0001);
            _animation->RegisterFrame(_spriteManager->_comboInterfaceAnimationP1_0002);
            _animation->RegisterFrame(_spriteManager->_comboInterfaceAnimationP1_0003);
            _animation->RegisterFrame(_spriteManager->_comboInterfaceAnimationP1_0004);
            _animation->RegisterFrame(_spriteManager->_comboInterfaceAnimationP1_0005);
            _animation->RegisterFrame(_spriteManager->_comboInterfaceAnimationP1_0006);
            _animation->RegisterFrame(_spriteManager->_comboInterfaceAnimationP1_0007);
            _animation->RegisterFrame(_spriteManager->_comboInterfaceAnimationP1_0008);
            _animation->RegisterFrame(_spriteManager->_comboInterfaceAnimationP1_0009);
            _animation->RegisterFrame(_spriteManager->_comboInterfaceAnimationP1_0010);
            _animation->RegisterFrame(_spriteManager->_comboInterfaceAnimationP1_0011);
            _animation->RegisterFrame(_spriteManager->_comboInterfaceAnimationP1_0012);
            _animation->RegisterFrame(_spriteManager->_comboInterfaceAnimationP1_0013);
            _animation->RegisterFrame(_spriteManager->_comboInterfaceAnimationP1_0014);
            _animation->RegisterFrame(_spriteManager->_comboInterfaceAnimationP1_0001);
        }
        else
        {
            _animation = new Sprite(_spriteManager->_comboInterfaceAnimationP2_0001, 452, 84);
            _animation->RegisterFrame(_spriteManager->_comboInterfaceAnimationP2_0001);
            _animation->RegisterFrame(_spriteManager->_comboInterfaceAnimationP2_0002);
            _animation->RegisterFrame(_spriteManager->_comboInterfaceAnimationP2_0003);
            _animation->RegisterFrame(_spriteManager->_comboInterfaceAnimationP2_0004);
            _animation->RegisterFrame(_spriteManager->_comboInterfaceAnimationP2_0005);
            _animation->RegisterFrame(_spriteManager->_comboInterfaceAnimationP2_0006);
            _animation->RegisterFrame(_spriteManager->_comboInterfaceAnimationP2_0007);
            _animation->RegisterFrame(_spriteManager->_comboInterfaceAnimationP2_0008);
            _animation->RegisterFrame(_spriteManager->_comboInterfaceAnimationP2_0009);
            _animation->RegisterFrame(_spriteManager->_comboInterfaceAnimationP2_0010);
            _animation->RegisterFrame(_spriteManager->_comboInterfaceAnimationP2_0011);
            _animation->RegisterFrame(_spriteManager->_comboInterfaceAnimationP2_0012);
            _animation->RegisterFrame(_spriteManager->_comboInterfaceAnimationP2_0013);
            _animation->RegisterFrame(_spriteManager->_comboInterfaceAnimationP2_0014);
            _animation->RegisterFrame(_spriteManager->_comboInterfaceAnimationP2_0001);
        }
        return _animation;
    }

    public: Sprite * GenerateBubbleAnimation (int size)
    {
        Sprite * _bubble;

        _bubble = new Sprite(_spriteManager->_xAny0001, 80, 200);
        _bubble->RegisterFrame(_spriteManager->_xAny0001);
        _bubble->RegisterFrame(_spriteManager->_xAny0002);
        _bubble->RegisterFrame(_spriteManager->_xAny0003);
        _bubble->RegisterFrame(_spriteManager->_xAny0004);
        _bubble->RegisterFrame(_spriteManager->_xAny0005);
        _bubble->RegisterFrame(_spriteManager->_xAny0006);
        _bubble->RegisterFrame(_spriteManager->_xAny0007);
        _bubble->RegisterFrame(_spriteManager->_xAny0008);
        _bubble->RegisterFrame(_spriteManager->_xAny0009);
        _bubble->RegisterFrame(_spriteManager->_xAny0010);
        _bubble->RegisterFrame(_spriteManager->_xAny0011);
        _bubble->RegisterFrame(_spriteManager->_xAny0012);
        _bubble->RegisterFrame(_spriteManager->_xAny0013);
        _bubble->RegisterFrame(_spriteManager->_xAny0014);
        _bubble->RegisterFrame(_spriteManager->_xAny0014);
        _bubble->RegisterFrame(_spriteManager->_xAny0014);
        _bubble->RegisterFrame(_spriteManager->_xAny0014);
        _bubble->RegisterFrame(_spriteManager->_xAny0014);
        _bubble->RegisterFrame(_spriteManager->_xAny0014);
        _bubble->RegisterFrame(_spriteManager->_xAny0014);
        _bubble->RegisterFrame(_spriteManager->_xAny0014);
        _bubble->RegisterFrame(_spriteManager->_xAny0014);
        _bubble->RegisterFrame(_spriteManager->_xAny0014);
        _bubble->RegisterFrame(_spriteManager->_xAny0014);
        _bubble->RegisterFrame(_spriteManager->_xAny0014);
        _bubble->RegisterFrame(_spriteManager->_xAny0014);
        _bubble->RegisterFrame(_spriteManager->_xAny0014);
        _bubble->RegisterFrame(_spriteManager->_xAny0014);
        _bubble->RegisterFrame(_spriteManager->_xAny0014);
        _bubble->RegisterFrame(_spriteManager->_xAny0014);
        _bubble->RegisterFrame(_spriteManager->_xAny0014);
        _bubble->RegisterFrame(_spriteManager->_xAny0014);
        _bubble->RegisterFrame(_spriteManager->_xAny0014);
        _bubble->RegisterFrame(_spriteManager->_xAny0014);
        _bubble->RegisterFrame(_spriteManager->_xAny0014);
        _bubble->RegisterFrame(_spriteManager->_xAny0014);
        _bubble->RegisterFrame(_spriteManager->_xAny0014);
        _bubble->RegisterFrame(_spriteManager->_xAny0014);
        _bubble->RegisterFrame(_spriteManager->_xAny0015);
        _bubble->RegisterFrame(_spriteManager->_xAny0016);
        _bubble->RegisterFrame(_spriteManager->_xAny0017);
        _bubble->RegisterFrame(_spriteManager->_xAny0018);
        _bubble->RegisterFrame(_spriteManager->_xAny0019);
        _bubble->RegisterFrame(_spriteManager->_xAny0020);
        _bubble->RegisterFrame(_spriteManager->_xAny0021);
        _bubble->RegisterFrame(_spriteManager->_xAny0022);
        _bubble->RegisterFrame(_spriteManager->_xAny0023);
        _bubble->RegisterFrame(_spriteManager->_xAny0024);
        _bubble->RegisterFrame(_spriteManager->_xAny0025);
        _bubble->RegisterFrame(_spriteManager->_xAny0026);
        return _bubble;
    }

    // Update _slideDelay in board if the number of the frames change.
    public: Sprite * GeneratePanelOperationAnimation (int type)
    {
        // Show Break animation
        Sprite * _break;
        switch (type)
        {
            case PANEL_CYAN_TYPE:
                _break = new Sprite(_spriteManager->_blueBreak0001, 32, 160);
                _break->RegisterFrame(_spriteManager->_blueBreak0001);
                _break->RegisterFrame(_spriteManager->_blueBreak0002);
                _break->RegisterFrame(_spriteManager->_blueBreak0003);
                _break->RegisterFrame(_spriteManager->_blueBreak0004);
                _break->RegisterFrame(_spriteManager->_blueBreak0005);
                _break->RegisterFrame(_spriteManager->_blueBreak0006);
                _break->RegisterFrame(_spriteManager->_blueBreak0007);
                _break->RegisterFrame(_spriteManager->_blueBreak0008);
                _break->RegisterFrame(_spriteManager->_blueBreak0009);
                _break->RegisterFrame(_spriteManager->_blueBreak0010);
                _break->RegisterFrame(_spriteManager->_blueBreak0011);
                break;
            case PANEL_GREEN_TYPE:
                _break = new Sprite(_spriteManager->_greenBreak0001, 32, 160);
                _break->RegisterFrame(_spriteManager->_greenBreak0001);
                _break->RegisterFrame(_spriteManager->_greenBreak0002);
                _break->RegisterFrame(_spriteManager->_greenBreak0003);
                _break->RegisterFrame(_spriteManager->_greenBreak0004);
                _break->RegisterFrame(_spriteManager->_greenBreak0005);
                _break->RegisterFrame(_spriteManager->_greenBreak0006);
                _break->RegisterFrame(_spriteManager->_greenBreak0007);
                _break->RegisterFrame(_spriteManager->_greenBreak0008);
                _break->RegisterFrame(_spriteManager->_greenBreak0009);
                _break->RegisterFrame(_spriteManager->_greenBreak0010);
                _break->RegisterFrame(_spriteManager->_greenBreak0011);
                break;
            case PANEL_PURPLE_TYPE:
                _break = new Sprite(_spriteManager->_purpleBreak0001, 32, 160);
                _break->RegisterFrame(_spriteManager->_purpleBreak0001);
                _break->RegisterFrame(_spriteManager->_purpleBreak0002);
                _break->RegisterFrame(_spriteManager->_purpleBreak0003);
                _break->RegisterFrame(_spriteManager->_purpleBreak0004);
                _break->RegisterFrame(_spriteManager->_purpleBreak0005);
                _break->RegisterFrame(_spriteManager->_purpleBreak0006);
                _break->RegisterFrame(_spriteManager->_purpleBreak0007);
                _break->RegisterFrame(_spriteManager->_purpleBreak0008);
                _break->RegisterFrame(_spriteManager->_purpleBreak0009);
                _break->RegisterFrame(_spriteManager->_purpleBreak0010);
                _break->RegisterFrame(_spriteManager->_purpleBreak0011);
                break;
            case PANEL_RED_TYPE:
                _break = new Sprite(_spriteManager->_redBreak0001, 32, 160);
                _break->RegisterFrame(_spriteManager->_redBreak0001);
                _break->RegisterFrame(_spriteManager->_redBreak0002);
                _break->RegisterFrame(_spriteManager->_redBreak0003);
                _break->RegisterFrame(_spriteManager->_redBreak0004);
                _break->RegisterFrame(_spriteManager->_redBreak0005);
                _break->RegisterFrame(_spriteManager->_redBreak0006);
                _break->RegisterFrame(_spriteManager->_redBreak0007);
                _break->RegisterFrame(_spriteManager->_redBreak0008);
                _break->RegisterFrame(_spriteManager->_redBreak0009);
                _break->RegisterFrame(_spriteManager->_redBreak0010);
                _break->RegisterFrame(_spriteManager->_redBreak0011);
                break;
            default:
                _break = new Sprite(_spriteManager->_yellowBreak0001, 32, 160);
                _break->RegisterFrame(_spriteManager->_yellowBreak0001);
                _break->RegisterFrame(_spriteManager->_yellowBreak0002);
                _break->RegisterFrame(_spriteManager->_yellowBreak0003);
                _break->RegisterFrame(_spriteManager->_yellowBreak0004);
                _break->RegisterFrame(_spriteManager->_yellowBreak0005);
                _break->RegisterFrame(_spriteManager->_yellowBreak0006);
                _break->RegisterFrame(_spriteManager->_yellowBreak0007);
                _break->RegisterFrame(_spriteManager->_yellowBreak0008);
                _break->RegisterFrame(_spriteManager->_yellowBreak0009);
                _break->RegisterFrame(_spriteManager->_yellowBreak0010);
                _break->RegisterFrame(_spriteManager->_yellowBreak0011);
                break;
        }
        return _break;
    }
};

#endif // __ANIMATION_MANAGER__
