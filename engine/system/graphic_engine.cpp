#include "graphic_engine.hpp"

Sprite * GraphicEngine::_stage;

void GraphicEngine::Init ()
{
    GRRLIB_Init();
    _stage = new Sprite(0, 0);
}

void GraphicEngine::Render()
{
    RenderSprites (_stage);
}

void GraphicEngine::RenderSprites (Sprite * sprite)
{
    int __stack_size = sprite->GetChildren().size();

    // Break Condition
    if (__stack_size == 0) return;

    for (int i = 0; i < __stack_size; i++)
    {
        Sprite * __tmp = sprite->GetChildren()[i];
        if (__tmp->GetTexture() != NULL)
        {
            if (__tmp->_visibility == visible)
            {
                // Correct Position in terms of all parents
                float __x = 0, __y = 0;
                Sprite * __ref = __tmp->_parent;

                // Compute Relative positions
                while (__ref != NULL)
                {
                    __x += __ref->_x;
                    __y += __ref->_y;
                    __ref = __ref->_parent;
                }

                // Compute sprite animations if this is the case.
                if (__tmp->_frames.size() > 0)
                {
                    UpdateSpriteAnimation(__tmp);
                    UpdateSpriteTransformation(__tmp);
                }

                // If not repeating, destroy the sprite
                if (!__tmp->_repeat && __tmp->_current_frame >= __tmp->_frames.size() - 1 && __tmp->_auto_destroy)
                {
                    sprite->RemoveChild(__tmp);
                    __stack_size--;
                    i--;
                    __tmp = NULL;
                    delete __tmp;
                    continue;
                }
                GRRLIB_DrawImg(__tmp->_x + __x + __tmp->_offsetX, __tmp->_y + __y + __tmp->_offsetY, __tmp->GetTexture(), __tmp->_rotation, __tmp->_scaleX, __tmp->_scaleY, PPL_RGBA(255, 255, 255, __tmp->_alpha));
            }
        }
        RenderSprites(__tmp);
        //else
        //    Debug::LogWarning("Sprite without texture loaded. Skipped.");
    }
}

void GraphicEngine::UpdateSpriteTransformation(Sprite* tmp)
{
      // Get Trajectory Point
    Transformation __transform = tmp->_transformations[tmp->_current_frame];

    // Determine with to do depending on the trajectory point type.
    switch (__transform._pointType)
    {
        case AbsolutePoint: tmp->_x = __transform._point.getX();
                            tmp->_y = __transform._point.getY();
                            break;
        case RelativePoint: tmp->_x += __transform._point.getX();
                            tmp->_y += __transform._point.getY();
                            break;
    }

    switch (__transform._rotationType)
    {
        case AbsoluteRotation: tmp->_rotation = __transform._rotation;
                               break;
        case IncrementalRotation: tmp->_rotation += __transform._rotation;
                                  break;
    }

    switch (__transform._scaleXType)
    {
        case AbsoluteScaleX: tmp->_scaleX = __transform._scaleX;
                             break;
        case IncrementalScaleX: tmp->_scaleX += __transform._scaleX;
                                break;
    }

    switch (__transform._scaleYType)
    {
        case AbsoluteScaleY: tmp->_scaleY = __transform._scaleY;
                             break;
        case IncrementalScaleY: tmp->_scaleY += __transform._scaleY;
                                break;
    }

    switch (__transform._alphaType)
    {
        case AbsoluteAlpha: tmp->_alpha = __transform._alpha;
                             break;
        case IncrementalAlpha: tmp->_alpha += __transform._alpha;
                                break;
    }
}

void GraphicEngine::UpdateSpriteAnimation(Sprite* tmp)
{
    if (!tmp->_is_playing)
        return;
    else
    {
        if (tmp->_current_frame == tmp->_frames.size() - 1 && tmp->_repeat)
        {
            tmp->GotoFrame(0);
        }
        else if (tmp->_current_frame != tmp->_frames.size() - 1)
        {
            tmp->NextFrame();
        }
        else
        {
            tmp->_is_playing = false;
        }
    }
}
