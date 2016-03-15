#ifndef __SCRIPT_TEMPLATE__
#define __SCRIPT_TEMPLATE__

#include "../../engine/engine.hpp"

class ScriptTemplate : public Runnable
{
    // Initializes control variable
    public: void Start ();
    
    // Update Counter
    public: void Update ();
    
    // Prints finalization text
    public: void End ();
};

#endif // __SCRIPT_TEMPLATE__