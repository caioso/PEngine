#ifndef __TWEEN__
#define __TWEEN__

#include "../base/sprite.hpp"
#include "sprite_properties.hpp"

// Tween types supported by the engine
enum EasingTypesName
{
    EaseInCubic,
    EaseOutCubic,
    EaseInOutCubic,
    EaseInBack,
    EaseOutBack,
    EaseInOutBack,
    EaseInBounce,
    EaseOutBounce,
    EaseInOutBounce,
    EaseInCirc,
    EaseOutCirc,
    EaseInOutCirc,
    EaseInElastic,
    EaseOutElastic,
    EaseInOutElastic,
    EaseInExpo,
    EaseOutExpo,
    EaseInOutExpo,
    EaseNoneLinear,
    EaseInLinear,
    EaseOutLinear,
    EaseInOutLinear,
    EaseInQuad,
    EaseOutQuad,
    EaseInOutQuad,
    EaseInQuart,
    EaseOutQuart,
    EaseInOutQuart,
    EaseInQuint,
    EaseOutQuint,
    EaseInOutQuint,
    EaseInSine,
    EaseOutSine,
    EaseInOutSine
};

class Tween
{
    // Sprite object
    public: Sprite * _sprite_reference;

    // Sprite Properties
    public: SpriteProperties _sprite_properties;

    // Easing Types
    public: EasingTypesName _easing;

    // Tween duration in miliseconds
    public: float _duration;

    // Tween initialization delay
    public: float _delay;

    // Total Frames given target framerate
    public: long long int _total_frames;

    // Tween total delay frames for a given target framerate
    public: long long int _total_delay;

    // Total Frames given target framerate
    public: long long int _current_frame;

    // Completion callback
    public: void (*_completion)(void);

    // Default Constructor
    public: Tween () : _easing(EaseNoneLinear), _duration(0.0), _total_frames(0), _current_frame(0), _completion(NULL){};
};

#endif // __TWEEN__
