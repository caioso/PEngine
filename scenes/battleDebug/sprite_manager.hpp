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

#include "../../assets/graphics/dBlueFalling0001.h"
#include "../../assets/graphics/dBlueFalling0002.h"
#include "../../assets/graphics/dBlueFalling0003.h"
#include "../../assets/graphics/dBlueFalling0004.h"
#include "../../assets/graphics/dBlueFalling0005.h"
#include "../../assets/graphics/dBlueFalling0006.h"
#include "../../assets/graphics/dBlueFalling0007.h"
#include "../../assets/graphics/dBlueFalling0008.h"
#include "../../assets/graphics/dBlueFalling0009.h"
#include "../../assets/graphics/dBlueFalling0010.h"

#include "../../assets/graphics/dRedFalling0001.h"
#include "../../assets/graphics/dRedFalling0002.h"
#include "../../assets/graphics/dRedFalling0003.h"
#include "../../assets/graphics/dRedFalling0004.h"
#include "../../assets/graphics/dRedFalling0005.h"
#include "../../assets/graphics/dRedFalling0006.h"
#include "../../assets/graphics/dRedFalling0007.h"
#include "../../assets/graphics/dRedFalling0008.h"
#include "../../assets/graphics/dRedFalling0009.h"
#include "../../assets/graphics/dRedFalling0010.h"

#include "../../assets/graphics/dGreenFalling0001.h"
#include "../../assets/graphics/dGreenFalling0002.h"
#include "../../assets/graphics/dGreenFalling0003.h"
#include "../../assets/graphics/dGreenFalling0004.h"
#include "../../assets/graphics/dGreenFalling0005.h"
#include "../../assets/graphics/dGreenFalling0006.h"
#include "../../assets/graphics/dGreenFalling0007.h"
#include "../../assets/graphics/dGreenFalling0008.h"
#include "../../assets/graphics/dGreenFalling0009.h"
#include "../../assets/graphics/dGreenFalling0010.h"

#include "../../assets/graphics/dPurpleFalling0001.h"
#include "../../assets/graphics/dPurpleFalling0002.h"
#include "../../assets/graphics/dPurpleFalling0003.h"
#include "../../assets/graphics/dPurpleFalling0004.h"
#include "../../assets/graphics/dPurpleFalling0005.h"
#include "../../assets/graphics/dPurpleFalling0006.h"
#include "../../assets/graphics/dPurpleFalling0007.h"
#include "../../assets/graphics/dPurpleFalling0008.h"
#include "../../assets/graphics/dPurpleFalling0009.h"
#include "../../assets/graphics/dPurpleFalling0010.h"

#include "../../assets/graphics/dYellowFalling0001.h"
#include "../../assets/graphics/dYellowFalling0002.h"
#include "../../assets/graphics/dYellowFalling0003.h"
#include "../../assets/graphics/dYellowFalling0004.h"
#include "../../assets/graphics/dYellowFalling0005.h"
#include "../../assets/graphics/dYellowFalling0006.h"
#include "../../assets/graphics/dYellowFalling0007.h"
#include "../../assets/graphics/dYellowFalling0008.h"
#include "../../assets/graphics/dYellowFalling0009.h"
#include "../../assets/graphics/dYellowFalling0010.h"

#include "../../assets/graphics/cursor0001.h"
#include "../../assets/graphics/cursor0002.h"
#include "../../assets/graphics/cursor0003.h"
#include "../../assets/graphics/cursor0004.h"
#include "../../assets/graphics/cursor0005.h"
#include "../../assets/graphics/cursor0006.h"
#include "../../assets/graphics/cursor0007.h"
#include "../../assets/graphics/cursor0008.h"
#include "../../assets/graphics/cursor0009.h"
#include "../../assets/graphics/cursor0010.h"
#include "../../assets/graphics/cursor0011.h"

#include "../../assets/graphics/n0.h"
#include "../../assets/graphics/n1.h"
#include "../../assets/graphics/n2.h"
#include "../../assets/graphics/n3.h"
#include "../../assets/graphics/n4.h"
#include "../../assets/graphics/n5.h"
#include "../../assets/graphics/n6.h"
#include "../../assets/graphics/n7.h"
#include "../../assets/graphics/n8.h"
#include "../../assets/graphics/n9.h"
#include "../../assets/graphics/points.h"

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
    public: GRRLIB_texImg* _concrete;
    
    // Cyan Falling Sprites
    public: GRRLIB_texImg* _dBlueFalling0001;
    public: GRRLIB_texImg* _dBlueFalling0002;
    public: GRRLIB_texImg* _dBlueFalling0003;
    public: GRRLIB_texImg* _dBlueFalling0004;
    public: GRRLIB_texImg* _dBlueFalling0005;
    public: GRRLIB_texImg* _dBlueFalling0006;
    public: GRRLIB_texImg* _dBlueFalling0007;
    public: GRRLIB_texImg* _dBlueFalling0008;
    public: GRRLIB_texImg* _dBlueFalling0009;
    public: GRRLIB_texImg* _dBlueFalling0010;
    
    // Red Falling Sprites
    public: GRRLIB_texImg* _dRedFalling0001;
    public: GRRLIB_texImg* _dRedFalling0002;
    public: GRRLIB_texImg* _dRedFalling0003;
    public: GRRLIB_texImg* _dRedFalling0004;
    public: GRRLIB_texImg* _dRedFalling0005;
    public: GRRLIB_texImg* _dRedFalling0006;
    public: GRRLIB_texImg* _dRedFalling0007;
    public: GRRLIB_texImg* _dRedFalling0008;
    public: GRRLIB_texImg* _dRedFalling0009;
    public: GRRLIB_texImg* _dRedFalling0010;
    
    // Green Falling Sprites
    public: GRRLIB_texImg* _dGreenFalling0001;
    public: GRRLIB_texImg* _dGreenFalling0002;
    public: GRRLIB_texImg* _dGreenFalling0003;
    public: GRRLIB_texImg* _dGreenFalling0004;
    public: GRRLIB_texImg* _dGreenFalling0005;
    public: GRRLIB_texImg* _dGreenFalling0006;
    public: GRRLIB_texImg* _dGreenFalling0007;
    public: GRRLIB_texImg* _dGreenFalling0008;
    public: GRRLIB_texImg* _dGreenFalling0009;
    public: GRRLIB_texImg* _dGreenFalling0010;
    
    // Purple Falling Sprites
    public: GRRLIB_texImg* _dPurpleFalling0001;
    public: GRRLIB_texImg* _dPurpleFalling0002;
    public: GRRLIB_texImg* _dPurpleFalling0003;
    public: GRRLIB_texImg* _dPurpleFalling0004;
    public: GRRLIB_texImg* _dPurpleFalling0005;
    public: GRRLIB_texImg* _dPurpleFalling0006;
    public: GRRLIB_texImg* _dPurpleFalling0007;
    public: GRRLIB_texImg* _dPurpleFalling0008;
    public: GRRLIB_texImg* _dPurpleFalling0009;
    public: GRRLIB_texImg* _dPurpleFalling0010;
    
    // Yellow Falling Sprites
    public: GRRLIB_texImg* _dYellowFalling0001;
    public: GRRLIB_texImg* _dYellowFalling0002;
    public: GRRLIB_texImg* _dYellowFalling0003;
    public: GRRLIB_texImg* _dYellowFalling0004;
    public: GRRLIB_texImg* _dYellowFalling0005;
    public: GRRLIB_texImg* _dYellowFalling0006;
    public: GRRLIB_texImg* _dYellowFalling0007;
    public: GRRLIB_texImg* _dYellowFalling0008;
    public: GRRLIB_texImg* _dYellowFalling0009;
    public: GRRLIB_texImg* _dYellowFalling0010;
    
    // Cursor Sprites
    public: GRRLIB_texImg* _cursor0001;
    public: GRRLIB_texImg* _cursor0002;
    public: GRRLIB_texImg* _cursor0003;
    public: GRRLIB_texImg* _cursor0004;
    public: GRRLIB_texImg* _cursor0005;
    public: GRRLIB_texImg* _cursor0006;
    public: GRRLIB_texImg* _cursor0007;
    public: GRRLIB_texImg* _cursor0008;
    public: GRRLIB_texImg* _cursor0009;
    public: GRRLIB_texImg* _cursor0010;
    public: GRRLIB_texImg* _cursor0011;
    
    // Clock Sprites
    public: GRRLIB_texImg* _n0;
    public: GRRLIB_texImg* _n1;
    public: GRRLIB_texImg* _n2;
    public: GRRLIB_texImg* _n3;
    public: GRRLIB_texImg* _n4;
    public: GRRLIB_texImg* _n5;
    public: GRRLIB_texImg* _n6;
    public: GRRLIB_texImg* _n7;
    public: GRRLIB_texImg* _n8;
    public: GRRLIB_texImg* _n9;
    public: GRRLIB_texImg* _points;
    
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
        _concrete = GRRLIB_LoadTexture(concrete);
        
        // Cursor sprites
        _cursor0001 = GRRLIB_LoadTexture(cursor0001);
        _cursor0002 = GRRLIB_LoadTexture(cursor0002);
        _cursor0003 = GRRLIB_LoadTexture(cursor0003);
        _cursor0004 = GRRLIB_LoadTexture(cursor0004);
        _cursor0005 = GRRLIB_LoadTexture(cursor0005);
        _cursor0006 = GRRLIB_LoadTexture(cursor0006);
        _cursor0007 = GRRLIB_LoadTexture(cursor0007);
        _cursor0008 = GRRLIB_LoadTexture(cursor0008);
        _cursor0009 = GRRLIB_LoadTexture(cursor0009);
        _cursor0010 = GRRLIB_LoadTexture(cursor0010);
        _cursor0011 = GRRLIB_LoadTexture(cursor0011);
        
        // Cyan Falling Sprites
        _dBlueFalling0001 = GRRLIB_LoadTexture(dBlueFalling0001);
        _dBlueFalling0002 = GRRLIB_LoadTexture(dBlueFalling0002);
        _dBlueFalling0003 = GRRLIB_LoadTexture(dBlueFalling0003);
        _dBlueFalling0004 = GRRLIB_LoadTexture(dBlueFalling0004);
        _dBlueFalling0005 = GRRLIB_LoadTexture(dBlueFalling0005);
        _dBlueFalling0006 = GRRLIB_LoadTexture(dBlueFalling0006);
        _dBlueFalling0007 = GRRLIB_LoadTexture(dBlueFalling0007);
        _dBlueFalling0008 = GRRLIB_LoadTexture(dBlueFalling0008);
        _dBlueFalling0009 = GRRLIB_LoadTexture(dBlueFalling0009);
        _dBlueFalling0010 = GRRLIB_LoadTexture(dBlueFalling0010);
        
        // Red Falling Sprites
        _dRedFalling0001 = GRRLIB_LoadTexture(dRedFalling0001);
        _dRedFalling0002 = GRRLIB_LoadTexture(dRedFalling0002);
        _dRedFalling0003 = GRRLIB_LoadTexture(dRedFalling0003);
        _dRedFalling0004 = GRRLIB_LoadTexture(dRedFalling0004);
        _dRedFalling0005 = GRRLIB_LoadTexture(dRedFalling0005);
        _dRedFalling0006 = GRRLIB_LoadTexture(dRedFalling0006);
        _dRedFalling0007 = GRRLIB_LoadTexture(dRedFalling0007);
        _dRedFalling0008 = GRRLIB_LoadTexture(dRedFalling0008);
        _dRedFalling0009 = GRRLIB_LoadTexture(dRedFalling0009);
        _dRedFalling0010 = GRRLIB_LoadTexture(dRedFalling0010);
        
        // Green Falling Sprites
        _dGreenFalling0001 = GRRLIB_LoadTexture(dGreenFalling0001);
        _dGreenFalling0002 = GRRLIB_LoadTexture(dGreenFalling0002);
        _dGreenFalling0003 = GRRLIB_LoadTexture(dGreenFalling0003);
        _dGreenFalling0004 = GRRLIB_LoadTexture(dGreenFalling0004);
        _dGreenFalling0005 = GRRLIB_LoadTexture(dGreenFalling0005);
        _dGreenFalling0006 = GRRLIB_LoadTexture(dGreenFalling0006);
        _dGreenFalling0007 = GRRLIB_LoadTexture(dGreenFalling0007);
        _dGreenFalling0008 = GRRLIB_LoadTexture(dGreenFalling0008);
        _dGreenFalling0009 = GRRLIB_LoadTexture(dGreenFalling0009);
        _dGreenFalling0010 = GRRLIB_LoadTexture(dGreenFalling0010);
        
        // Purple Falling Sprites
        _dPurpleFalling0001 = GRRLIB_LoadTexture(dPurpleFalling0001);
        _dPurpleFalling0002 = GRRLIB_LoadTexture(dPurpleFalling0002);
        _dPurpleFalling0003 = GRRLIB_LoadTexture(dPurpleFalling0003);
        _dPurpleFalling0004 = GRRLIB_LoadTexture(dPurpleFalling0004);
        _dPurpleFalling0005 = GRRLIB_LoadTexture(dPurpleFalling0005);
        _dPurpleFalling0006 = GRRLIB_LoadTexture(dPurpleFalling0006);
        _dPurpleFalling0007 = GRRLIB_LoadTexture(dPurpleFalling0007);
        _dPurpleFalling0008 = GRRLIB_LoadTexture(dPurpleFalling0008);
        _dPurpleFalling0009 = GRRLIB_LoadTexture(dPurpleFalling0009);
        _dPurpleFalling0010 = GRRLIB_LoadTexture(dPurpleFalling0010);

        // Yellow Falling Sprites
        _dYellowFalling0001 = GRRLIB_LoadTexture(dYellowFalling0001);
        _dYellowFalling0002 = GRRLIB_LoadTexture(dYellowFalling0002);
        _dYellowFalling0003 = GRRLIB_LoadTexture(dYellowFalling0003);
        _dYellowFalling0004 = GRRLIB_LoadTexture(dYellowFalling0004);
        _dYellowFalling0005 = GRRLIB_LoadTexture(dYellowFalling0005);
        _dYellowFalling0006 = GRRLIB_LoadTexture(dYellowFalling0006);
        _dYellowFalling0007 = GRRLIB_LoadTexture(dYellowFalling0007);
        _dYellowFalling0008 = GRRLIB_LoadTexture(dYellowFalling0008);
        _dYellowFalling0009 = GRRLIB_LoadTexture(dYellowFalling0009);
        _dYellowFalling0010 = GRRLIB_LoadTexture(dYellowFalling0010);
        
        // Clock Sprites
        _n0 = GRRLIB_LoadTexture(n0);
        _n1 = GRRLIB_LoadTexture(n1);
        _n2 = GRRLIB_LoadTexture(n2);
        _n3 = GRRLIB_LoadTexture(n3);
        _n4 = GRRLIB_LoadTexture(n4);
        _n5 = GRRLIB_LoadTexture(n5);
        _n6 = GRRLIB_LoadTexture(n6);
        _n7 = GRRLIB_LoadTexture(n7);
        _n8 = GRRLIB_LoadTexture(n8);
        _n9 = GRRLIB_LoadTexture(n9);
        _points = GRRLIB_LoadTexture(points);
    }
    
    public: GRRLIB_texImg * DecodeNumber (int number)
    {
        switch (number)
        {
            case 1: return _n1; break;
            case 2: return _n2; break;
            case 3: return _n3; break;
            case 4: return _n4; break;
            case 5: return _n5; break;
            case 6: return _n6; break;
            case 7: return _n7; break;
            case 8: return _n8; break;
            case 9: return _n9; break;
            default: return _n0;
        }
    }
};

#endif // __SPRITE_MANAGER__