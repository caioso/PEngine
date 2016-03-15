#ifndef __LOGIC_PANEL__
#define __LOGIC_PANEL__

class LogicPanel
{
    // Logic Panel Type
    public: int _type;
    
    // Panel State
    // 0: Steady
    // 1: Falling
    // 2: Swapping
    // 3: Breaking
    public: int _state;
    
    // Fall delay counter
    public: int _wait;
};

#endif // __LOGIC_PANEL__