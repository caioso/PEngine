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
    // 4: Waiting to fall
    public: int _state;
    
    // Fall delay counter
    public: int _wait;
    
    // Garbage only data
    public: LogicPanel * _up;
    public: LogicPanel * _down;
    public: LogicPanel * _left;
    public: LogicPanel * _right;
};

#endif // __LOGIC_PANEL__