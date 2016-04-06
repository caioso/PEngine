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
    public: int _positionX;
    public: int _positionY;
    public: int _sourceX;
    public: int _sourceY;
    public: int _width;
    public: int _height;
};

#endif // __LOGIC_PANEL__