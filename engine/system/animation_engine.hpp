#ifndef __ANIMATION_ENGINE__
#define __ANIMATION_ENGINE__

// Standard Includes
#include <vector>

// System Includes
#include "debug.hpp"
#include "../base/sprite.hpp"
#include "../types/sprite_properties.hpp"
#include "../types/tween.hpp"

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
    public: static void RegisterTween (Sprite * object, SpriteProperties properties, float duration, void (*completion_completion)(void) = NULL);
    
    // Update each animation for the given frame
    public: static void UpdateTweens ();
    
    private: static void UpdateTweenPropertiesLinear (int index);
};

#endif // __ANIMATION_ENGINE__