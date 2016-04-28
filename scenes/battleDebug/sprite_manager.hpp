#ifndef __SPRITE_MANAGER__
#define __SPRITE_MANAGER__

// Assets
#include "../../assets/graphics/dred.h"
#include "../../assets/graphics/dblue.h"
#include "../../assets/graphics/dgreen.h"
#include "../../assets/graphics/dyellow.h"
#include "../../assets/graphics/dpurple.h"
#include "../../assets/graphics/dred1.h"
#include "../../assets/graphics/dblue1.h"
#include "../../assets/graphics/dgreen1.h"
#include "../../assets/graphics/dyellow1.h"
#include "../../assets/graphics/dpurple1.h"
#include "../../assets/graphics/dgarbage.h"
#include "../../assets/graphics/concrete.h"
#include "../../assets/graphics/cursor.h"
#include "../../assets/graphics/cursor1.h"

// Sprite manager class handles texture instances. It keeps a static reference to
// each assets reference and deploy them as needed.
class SpriteManager
{
    public: GRRLIB_texImg* _dred;
    public: GRRLIB_texImg* _dblue;
    public: GRRLIB_texImg* _dgreen;
    public: GRRLIB_texImg* _dyellow;
    public: GRRLIB_texImg* _dpurple;
    public: GRRLIB_texImg* _dred1;
    public: GRRLIB_texImg* _dblue1;
    public: GRRLIB_texImg* _dgreen1;
    public: GRRLIB_texImg* _dyellow1;
    public: GRRLIB_texImg* _dpurple1;
    public: GRRLIB_texImg* _dgarbage;
    public: GRRLIB_texImg* _cursor;
    public: GRRLIB_texImg* _cursor1;
    public: GRRLIB_texImg* _concrete;
    
    public: SpriteManager ()
    {
        _dred = GRRLIB_LoadTexture(dred);
        _dblue = GRRLIB_LoadTexture(dblue);
        _dgreen = GRRLIB_LoadTexture(dgreen);
        _dyellow = GRRLIB_LoadTexture(dyellow);
        _dpurple = GRRLIB_LoadTexture(dpurple);
        _dred1 = GRRLIB_LoadTexture(dred1);
        _dblue1 = GRRLIB_LoadTexture(dblue1);
        _dgreen1 = GRRLIB_LoadTexture(dgreen1);
        _dyellow1 = GRRLIB_LoadTexture(dyellow1);
        _dpurple1 = GRRLIB_LoadTexture(dpurple1);
        _dgarbage = GRRLIB_LoadTexture(dgarbage);
        _cursor = GRRLIB_LoadTexture(cursor);
        _cursor1 = GRRLIB_LoadTexture(cursor1);
        _concrete = GRRLIB_LoadTexture(concrete);
    }
};

#endif // __SPRITE_MANAGER__