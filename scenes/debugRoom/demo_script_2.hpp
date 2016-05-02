#ifndef __DEMO_SCRIPT_2__
#define __DEMO_SCRIPT_2__

// Engine Include
#include "../../engine/engine.hpp"

// Image
#include "../../assets/graphics/scott.h"

// Audio
#include "../../assets/audio/airwing.h"
#include "../../assets/audio/sample.h"
#include "../../assets/audio/magi.h"
#include "../../assets/audio/obstacles.h"

class DemoScript2 : public Runnable
{
    private: Controller * __remote_1;
    private: Controller * __remote_2;
    
    private: GRRLIB_texImg* _scott;
    private: Sprite * __lv1;
    private: Sprite * __lv2;
    private: Sprite * __lv3;
    
    private: Sound * __sfx;
    private: Sound * __sfx1;
    
    private: Music * __msc;
    private: Music * __msc2;
    
    // Initializes control variable
    public: void Start ();

    // Update Counter
    public: void Update ();

    // Prints finalization text
    public: void End ();
};

#endif // __DEMO_SCRIPT_2__