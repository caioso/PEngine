#ifndef __SPRITE__
#define __SPRITE__

#include <grrlib.h>
#include <vector>

#include "../system/debug.hpp"
#include "../types/visibility.hpp"

using namespace std;

// Class that represents a drawable Sprite asset.
// The coordinate system of any Sprite starts at the top-left corner
// of the asset.
class Sprite
{
    public: float _x;
    public: float _y;
    public: float _width;
    public: float _height;
    public: float _rotation;
    public: Sprite * _parent;
    public: Visibility _visibility;
    private: unsigned char const* _asset;
    private: GRRLIB_texImg* _tex;
    private: vector<Sprite*> _children;

    // Generic Constructor Method.
    // This Constructor makes sure the Sprite position is set to (0,0).
    public: Sprite () : _x(0), _y(0), _width(0), _height(0), _rotation(0), _parent(NULL), _tex(NULL) {}

    // Coordinate defining constructor. Width and height set null.
    // @param x: asset x coordinate.
    // @param y: asset y coordinate.
    public: Sprite (float x, float y) : _x(x), _y(y), _width(0), _height(0), _rotation(0), _parent(NULL), _tex(NULL) {}

    // Asset defining constructor. The Sprite coordinates are set to (0,0). Width and height set null.
    // @param asset: unsigned char array of the asset.
    public: Sprite (GRRLIB_texImg* asset);

    // Asset defining constructor. The Sprite coordinates are set to (0,0).
    // @param asset: unsigned char array of the asset.
    // @param width: sprite image width.
    // @param height: sprite image height.
    public: Sprite (GRRLIB_texImg* asset, float width, float height);

    // Full definition constructor.
    // @param asset: unsigned char array of the asset.
    // @param x: asset x coordinate.
    // @param y: asset y coordinate.
    // @param width: sprite image width.
    // @param height: sprite image height.
    public: Sprite (GRRLIB_texImg* asset, float x, float y, float width, float height);

    // Return Texture Object
    public: GRRLIB_texImg*  GetTexture() { return _tex; }

    // Manually loads an asset object into the Sprite.
    // @param asset: asset array.
    public: void SetAsset (GRRLIB_texImg* asset, float width, float height);

    // Add child Sprite to the current Sprite children list.
    // @param child: Child sprite to be stored in this Sprite children list.
    public: void AddChild (Sprite* child);

    // Remove child Sprite to the current Sprite children list, based on a Sprite reference.
    // @param child: Child sprite to be removed in this Sprite children list.
    public: void RemoveChild (Sprite* child);

    // Return children list vector
    public: vector<Sprite*> GetChildren () { return _children;}

    // Initializes the sprite object in GRRLIB.
    private: void DefineSprite ();

    // Standard Destructir
    public: ~Sprite();
};

#endif // __SPRITE__
