#ifndef __ANIMATION_ENGINE__
#define __ANIMATION_ENGINE__

// Standard Includes
#include <vector>
#include <math.h>

// System Includes
#include "debug.hpp"
#include "../base/sprite.hpp"
#include "../types/sprite_properties.hpp"
#include "../types/tween.hpp"
#include <ogc/lwp_watchdog.h>

#define PI 3.14159265358979323846

class AnimationEngine
{
    friend class Sprite;

    private: static vector<Tween> _tween_list;

    // Intializes Animation Engine
    public: static void Init (){};

    // Reister a new Tween in Animation Engine
    // @param object: Target sprite to be animated;
    // @param properties: Which sprite properties will be animated;
    // @param duration: Animation length in miliseconds.
    // @param completion_completion: callback called when the tween completes execution.
    public: static void RegisterTween (Sprite * object, SpriteProperties properties, float duration, EasingTypesName easin = EaseNoneLinear, float delay = 0.0, void (*completion_completion)(void) = NULL);

    // Update each animation for the given frame
    public: static void UpdateTweens ();

    private: static void UpdateTweenPropertiesLinear (int index);

    private: static float RunTween (int index, SpritePropertyName property);

    // Easing Fucntions
    // t: current time, b: begInnIng value, c: change In value, d: duration
    private: static float easeInCubic (float t, float b , float c, float d);
    private: static float easeOutCubic(float t,float b , float c, float d);
    private: static float easeInOutCubic(float t,float b , float c, float d);
    private: static float easeInBack(float t, float b , float c, float d);
    private: static float easeOutBack(float t,float b , float c, float d);
    private: static float easeInOutBack(float t,float b , float c, float d);
    private: static float easeInBounce(float t, float b , float c, float d);
    private: static float easeOutBounce(float t,float b , float c, float d);
    private: static float easeInOutBounce(float t,float b , float c, float d);
    private: static float easeInCirc(float t, float b , float c, float d);
    private: static float easeOutCirc(float t,float b , float c, float d);
    private: static float easeInOutCirc(float t,float b , float c, float d);
    private: static float easeInElastic(float t, float b , float c, float d);
    private: static float easeOutElastic(float t,float b , float c, float d);
    private: static float easeInOutElastic(float t,float b , float c, float d);
    private: static float easeInExpo(float t, float b , float c, float d);
    private: static float easeOutExpo(float t,float b , float c, float d);
    private: static float easeInOutExpo(float t,float b , float c, float d);
    private: static float easeNoneLinear(float t, float b , float c, float d);
    private: static float easeInLinear(float t,float b , float c, float d);
    private: static float easeOutLinear(float t,float b , float c, float d);
    private: static float easeInOutLinear(float t,float b , float c, float d);
    private: static float easeInQuad(float t, float b , float c, float d);
    private: static float easeOutQuad(float t,float b , float c, float d);
    private: static float easeInOutQuad(float t,float b , float c, float d);
    private: static float easeInQuart(float t, float b , float c, float d);
    private: static float easeOutQuart(float t,float b , float c, float d);
    private: static float easeInOutQuart(float t,float b , float c, float d);
    private: static float easeInQuint(float t, float b , float c, float d);
    private: static float easeOutQuint(float t,float b , float c, float d);
    private: static float easeInOutQuint(float t,float b , float c, float d);
    private: static float easeInSine(float t, float b , float c, float d);
    private: static float easeOutSine(float t,float b , float c, float d);
    private: static float easeInOutSine(float t,float b , float c, float d);

};

#endif // __ANIMATION_ENGINE__
