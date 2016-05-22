#include "sprite.hpp"

Sprite::Sprite (GRRLIB_texImg* asset) :
                _x(0), _y(0), _width(0), _height(0), _rotation(0), _scaleX(1), _scaleY(1), _tex(asset),
                _current_frame(0), _is_playing(false), _repeat(true), _animation_delay(0), _current_delay(0)
{
    _isAnimating = false;
    _visibility = visible;
    _parent = NULL;
}

Sprite::Sprite (GRRLIB_texImg* asset, float width, float height) :
                _x(0), _y(0), _width(width), _height(height), _rotation(0), _scaleX(1), _scaleY(1), _tex(asset),
                _current_frame(0), _is_playing(false), _repeat(true), _animation_delay(0), _current_delay(0)
{
    _isAnimating = false;
    _visibility = visible;
    _parent = NULL;
}

Sprite::Sprite (GRRLIB_texImg* asset, float x, float y, float width, float height) :
                _x(x), _y(y), _width(width), _height(height), _rotation(0), _tex(asset),
                _current_frame(0), _is_playing(false), _repeat(true), _animation_delay(0), _current_delay(0)
{
    _scaleX = 1;
    _scaleY = 1;
    _isAnimating = false;
    _visibility = visible;
    _parent = NULL;
}

void Sprite::SetAsset (GRRLIB_texImg* asset, float width, float height)
{
    _width = width;
    _height = height;
    _tex = asset;
}

void Sprite::AddChild (Sprite* child)
{
    // Child already in other parent
    if (child->_parent == this)
    {
        Debug::LogWarning("Child already belongs to this Sprite.");
        return;
    }
    else if (child->_parent != NULL)
    {
        Debug::LogWarning("Child already in some list. Changing it.");
        child->_parent->RemoveChild(child);
    }
    _children.push_back(child);
    child->_parent = this;
}

void Sprite::AddChildAt (Sprite* child, int index)
{
    // Child already in other parent
    if (child->_parent == this)
    {
        Debug::LogWarning("Child already belongs to this Sprite.");
        return;
    }
    else if (_children.size() < index)
    {
        Debug::LogWarning("Child index out of bounds.");
        return;
    }
    else if (child->_parent != NULL)
    {
        Debug::LogWarning("Child already in some list. Changing it.");
        child->_parent->RemoveChild(child);
    }
    _children.insert(_children.begin() + index, child);
    child->_parent = this;
}

void Sprite::RemoveChild (Sprite* child)
{
    for (size_t i = 0; i < _children.size(); i++)
    {
        if (_children[i] == child)
        {
            _children.erase(_children.begin() + i);
            child->_parent = NULL;
            return;
        }
    }
    Debug::LogWarning("Child not found in children list.");
}

bool Sprite::RegisterFrame (GRRLIB_texImg * _frame)
{
    if (_frames.size() == 0)
        SetAsset (_frame, _width, _height);
    _frames.push_back(_frame);
    return true;
}

void Sprite::GotoAndStop (unsigned int target_frame)
{
    GotoFrame(target_frame);
    _is_playing = false;
}

void Sprite::GotoAndPlay (unsigned int target_frame)
{
    GotoFrame(target_frame);
    _is_playing = true;
}

void Sprite::GotoFrame (unsigned int target_frame)
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

void Sprite::NextFrame ()
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

Sprite::~Sprite()
{
  delete _parent;
}
