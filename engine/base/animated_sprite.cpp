#include "animated_sprite.hpp"

bool AnimatedSprite::RegisterFrame (GRRLIB_texImg * _frame)
{
    if (_frames.size() == _total_frames)
    {
        Debug::LogWarning("Animation array already full of frames. Ignoring this frame.");
        return false;
    }
    else
    {
        if (_frames.size() == 0)
            SetAsset (_frame, _width, _height);
        _frames.push_back(_frame);
        return true;
    }
}

void AnimatedSprite::GotoAndStop (unsigned int target_frame)
{
    GotoFrame(target_frame);
    _is_playing = false;
}

void AnimatedSprite::GotoAndPlay (unsigned int target_frame)
{
    GotoFrame(target_frame);
    _is_playing = true;
}

void AnimatedSprite::GotoFrame (unsigned int target_frame)
{
    if (target_frame >= _frames.size())
    {
        Debug::LogWarning("Target frame is out of animation bounds. The last frame will be shown.");
        _current_frame = _frames.size() - 1;
    }
    else
    {
        _current_frame = target_frame;
    }
    
    // Set asset
    SetAsset (_frames[_current_frame], _width, _height);
}

void AnimatedSprite::NextFrame ()
{
    if(_current_delay == _animation_delay)
    {
        GotoFrame(++_current_frame);
        _current_delay = 0;
    }
    else
    {
        _current_delay++;
    }
}