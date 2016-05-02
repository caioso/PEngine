#ifndef __TWEEN__
#define __TWEEN__

#include "../base/sprite.hpp"
#include "sprite_properties.hpp"

class Tween
{
    // Sprite object
    public: Sprite * _sprite_reference;
    
    // Sprite Properties
    public: SpriteProperties _sprite_properties;
    
    // Tween duration in miliseconds
    public: float _duration;
    
    // Total Frames given target framerate
    public: long long int _total_frames;
    
    // Total Frames given target framerate
    public: long long int _current_frame;
    
    // Default Constructor
    public: Tween () : _duration(0.0), _total_frames(0), _current_frame(0) {};
};

#endif // __TWEEN__