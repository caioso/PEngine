#include "sprite.hpp"

Sprite::Sprite (unsigned char const* asset) :
                _x(0), _y(0), _width(0), _height(0), _rotation(0), _asset(asset)
{
    _parent = NULL;
    DefineSprite ();
}

Sprite::Sprite (unsigned char const* asset, float width, float height) :
                _x(0), _y(0), _width(width), _height(height), _rotation(0), _asset(asset)
{
    _parent = NULL;
    DefineSprite ();
}

Sprite::Sprite (unsigned char const* asset, float x, float y, float width, float height) :
                _x(x), _y(y), _width(width), _height(height), _asset(asset)
{
    _parent = NULL;
    DefineSprite ();
}

void Sprite::SetAsset (unsigned char const* asset, float width, float height)
{
    _width = width;
    _height = height;
    _asset = asset;
    DefineSprite ();
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

void Sprite::DefineSprite ()
{
    _tex = GRRLIB_LoadTexture(_asset);
    GRRLIB_InitTileSet(_tex, _width, _height, 0);
    GRRLIB_SetMidHandle(_tex, true);
}
