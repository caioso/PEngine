#include "animation_engine.hpp"

vector<Tween> AnimationEngine::_tween_list;

void AnimationEngine::RegisterTween (Sprite * object, SpriteProperties properties, float duration)
{
    if (object->_isAnimating == false)
    {
        Tween __tween;
        __tween._sprite_reference = object;
        __tween._sprite_properties = properties;
        __tween._duration = duration;
        __tween._total_frames = (duration/1000)*PPL_TARGET_FRAMERATE;
        _tween_list.push_back(__tween);
        
        object->_isAnimating = true;
    }
}

void AnimationEngine::UpdateTweens ()
{
    for (unsigned int i = 0; i < _tween_list.size(); i++)
    {
        if (_tween_list[i]._current_frame == _tween_list[i]._total_frames - 1)
        {
            //stringstream ss;
            //ss<<_tween_list[i]._current_frame;
            //Debug::Log(ss.str());
            _tween_list[i]._sprite_reference->_isAnimating = false;
            _tween_list.erase(_tween_list.begin() + i);
            i--;
        }
        else
        {
            stringstream ss;
            ss<<_tween_list[i]._current_frame;
            Debug::Log(ss.str());
            UpdateTweenPropertiesLinear(i);
        }
    }
}

void AnimationEngine::UpdateTweenPropertiesLinear (int index)
{
    // This is implemented for only linear tweens.
    float __current_value;
    if (_tween_list[index]._sprite_properties.IsPropertyRegistered(SpriteX))
    {
        // Compute Value
        __current_value = _tween_list[index]._sprite_reference->_x;
        __current_value += (_tween_list[index]._sprite_properties.GetFinalPropertyValue(SpriteX) - _tween_list[index]._sprite_properties.GetInitialPropertyValue(SpriteX))/_tween_list[index]._total_frames;
        
        // Update Value
        _tween_list[index]._sprite_properties.UpdatePropertyValue(SpriteX, __current_value);
    }
    if (_tween_list[index]._sprite_properties.IsPropertyRegistered(SpriteY))
    {
        // Compute Value
        __current_value = _tween_list[index]._sprite_reference->_y;
        __current_value += (_tween_list[index]._sprite_properties.GetFinalPropertyValue(SpriteY) - _tween_list[index]._sprite_properties.GetInitialPropertyValue(SpriteY))/_tween_list[index]._total_frames;
        
        // Update Value
        _tween_list[index]._sprite_properties.UpdatePropertyValue(SpriteY, __current_value);
    }
    if (_tween_list[index]._sprite_properties.IsPropertyRegistered(SpriteScaleX))
    {
        // Compute Value
        __current_value = _tween_list[index]._sprite_reference->_scaleX;
        __current_value += (_tween_list[index]._sprite_properties.GetFinalPropertyValue(SpriteScaleX) - _tween_list[index]._sprite_properties.GetInitialPropertyValue(SpriteScaleX))/_tween_list[index]._total_frames;
        
        // Update Value
        _tween_list[index]._sprite_properties.UpdatePropertyValue(SpriteScaleX, __current_value);

    }
    if (_tween_list[index]._sprite_properties.IsPropertyRegistered(SpriteScaleY))
    {
        // Compute Value
        __current_value = _tween_list[index]._sprite_reference->_scaleY;
        __current_value += (_tween_list[index]._sprite_properties.GetFinalPropertyValue(SpriteScaleY) - _tween_list[index]._sprite_properties.GetInitialPropertyValue(SpriteScaleY))/_tween_list[index]._total_frames;
        
        // Update Value
        _tween_list[index]._sprite_properties.UpdatePropertyValue(SpriteScaleY, __current_value);

    }
    if (_tween_list[index]._sprite_properties.IsPropertyRegistered(SpriteRotation))
    {
        // Compute Value
        __current_value = _tween_list[index]._sprite_reference->_rotation;
        __current_value += (_tween_list[index]._sprite_properties.GetFinalPropertyValue(SpriteRotation) - _tween_list[index]._sprite_properties.GetInitialPropertyValue(SpriteRotation))/_tween_list[index]._total_frames;
        
        // Update Value
        _tween_list[index]._sprite_properties.UpdatePropertyValue(SpriteRotation, __current_value);
    }
    _tween_list[index]._current_frame++;
}


