#include "animation_engine.hpp"

vector<Tween> AnimationEngine::_tween_list;

void AnimationEngine::RegisterTween (Sprite * object, SpriteProperties properties, float duration, EasingTypesName easing, float delay, void (*completion_completion)(void))
{
    if (object->_isAnimating == false)
    {
        Tween __tween;
        __tween._sprite_reference = object;
        __tween._sprite_properties = properties;
        __tween._easing = easing;
        __tween._duration = duration;
        __tween._delay = delay;
        __tween._total_frames = (duration/1000)*PPL_TARGET_FRAMERATE;
        __tween._total_delay = (delay/1000)*PPL_TARGET_FRAMERATE;
        __tween._completion = completion_completion;
        _tween_list.push_back(__tween);

        object->_isAnimating = true;
    }
}

void AnimationEngine::UpdateTweens ()
{
    for (unsigned int i = 0; i < _tween_list.size(); i++)
    {
        // Update Tween delay
        if (_tween_list[i]._total_delay != 0)
        {
            _tween_list[i]._total_delay--;
            continue;
        }

        // Finalize Tween
        if (_tween_list[i]._current_frame == _tween_list[i]._total_frames)
        {
            if (_tween_list[i]._sprite_properties.IsPropertyRegistered(SpriteX))
                _tween_list[i]._sprite_properties.UpdatePropertyValue
                (SpriteX,_tween_list[i]._sprite_properties.GetFinalPropertyValue(SpriteX));
            if (_tween_list[i]._sprite_properties.IsPropertyRegistered(SpriteY))
                _tween_list[i]._sprite_properties.UpdatePropertyValue
                (SpriteY,_tween_list[i]._sprite_properties.GetFinalPropertyValue(SpriteY));
            if (_tween_list[i]._sprite_properties.IsPropertyRegistered(SpriteScaleX))
                _tween_list[i]._sprite_properties.UpdatePropertyValue
                (SpriteScaleX,_tween_list[i]._sprite_properties.GetFinalPropertyValue(SpriteScaleX));
            if (_tween_list[i]._sprite_properties.IsPropertyRegistered(SpriteScaleY))
                _tween_list[i]._sprite_properties.UpdatePropertyValue
                (SpriteScaleY,_tween_list[i]._sprite_properties.GetFinalPropertyValue(SpriteScaleY));
            if (_tween_list[i]._sprite_properties.IsPropertyRegistered(SpriteRotation))
                _tween_list[i]._sprite_properties.UpdatePropertyValue
                (SpriteRotation,_tween_list[i]._sprite_properties.GetFinalPropertyValue(SpriteRotation));
            if (_tween_list[i]._sprite_properties.IsPropertyRegistered(SpriteAlpha))
                _tween_list[i]._sprite_properties.UpdatePropertyValue
                (SpriteAlpha,_tween_list[i]._sprite_properties.GetFinalPropertyValue(SpriteAlpha));

            _tween_list[i]._sprite_reference->_isAnimating = false;
            if (_tween_list[i]._completion != NULL)
                _tween_list[i]._completion();
            _tween_list.erase(_tween_list.begin() + i);
            i--;
        }
        else
        {
            // Compute next tween frame
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
        __current_value = RunTween(index, SpriteX);

        // Update Value
        _tween_list[index]._sprite_properties.UpdatePropertyValue(SpriteX,  _tween_list[index]._sprite_properties.GetInitialPropertyValue(SpriteX) + _tween_list[index]._sprite_properties.GetFinalPropertyValue(SpriteX) - __current_value);
    }
    if (_tween_list[index]._sprite_properties.IsPropertyRegistered(SpriteY))
    {
        // Compute Value
        __current_value = RunTween(index, SpriteY);

        // Update Value
        _tween_list[index]._sprite_properties.UpdatePropertyValue(SpriteY, _tween_list[index]._sprite_properties.GetInitialPropertyValue(SpriteY) + _tween_list[index]._sprite_properties.GetFinalPropertyValue(SpriteY) - __current_value);
    }
    if (_tween_list[index]._sprite_properties.IsPropertyRegistered(SpriteScaleX))
    {
        // Compute Value
        __current_value = RunTween(index, SpriteScaleX);

        // Update Value
        _tween_list[index]._sprite_properties.UpdatePropertyValue(SpriteScaleX, _tween_list[index]._sprite_properties.GetInitialPropertyValue(SpriteScaleX) + _tween_list[index]._sprite_properties.GetFinalPropertyValue(SpriteScaleX) - __current_value);

    }
    if (_tween_list[index]._sprite_properties.IsPropertyRegistered(SpriteScaleY))
    {
        // Compute Value
        __current_value = RunTween(index, SpriteScaleY);

        // Update Value
        _tween_list[index]._sprite_properties.UpdatePropertyValue(SpriteScaleY, _tween_list[index]._sprite_properties.GetInitialPropertyValue(SpriteScaleY) + _tween_list[index]._sprite_properties.GetFinalPropertyValue(SpriteScaleY) - __current_value);

    }
    if (_tween_list[index]._sprite_properties.IsPropertyRegistered(SpriteRotation))
    {
        // Compute Value
        __current_value = RunTween(index, SpriteRotation);

        // Update Value
        _tween_list[index]._sprite_properties.UpdatePropertyValue(SpriteRotation, _tween_list[index]._sprite_properties.GetInitialPropertyValue(SpriteRotation) + _tween_list[index]._sprite_properties.GetFinalPropertyValue(SpriteRotation) - __current_value);
    }
    if (_tween_list[index]._sprite_properties.IsPropertyRegistered(SpriteAlpha))
    {
        // Compute Value
        __current_value = RunTween(index, SpriteAlpha);

        // Update Value
        _tween_list[index]._sprite_properties.UpdatePropertyValue(SpriteAlpha, _tween_list[index]._sprite_properties.GetInitialPropertyValue(SpriteAlpha) + _tween_list[index]._sprite_properties.GetFinalPropertyValue(SpriteAlpha) -__current_value);
    }
    _tween_list[index]._current_frame++;
}

float AnimationEngine::RunTween (int index, SpritePropertyName property)
{
    float __value = 0;
    EasingTypesName __easing = _tween_list[index]._easing;

    switch(__easing)
    {
        case EaseInCubic: __value = easeInCubic(_tween_list[index]._total_frames - _tween_list[index]._current_frame,
                                                _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                                _tween_list[index]._sprite_properties.GetFinalPropertyValue(property) -
                                                _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                                _tween_list[index]._total_frames);
            break;
        case EaseOutCubic: __value = easeOutCubic(_tween_list[index]._total_frames - _tween_list[index]._current_frame,
                                                _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                                _tween_list[index]._sprite_properties.GetFinalPropertyValue(property) -
                                                _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                                _tween_list[index]._total_frames);
            break;
        case EaseInOutCubic: __value = easeInOutCubic(_tween_list[index]._total_frames - _tween_list[index]._current_frame,
                                                  _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                                  _tween_list[index]._sprite_properties.GetFinalPropertyValue(property) -
                                                  _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                                  _tween_list[index]._total_frames);
            break;
        case EaseInBack: __value = easeInBack(_tween_list[index]._total_frames - _tween_list[index]._current_frame,
                                                      _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                                      _tween_list[index]._sprite_properties.GetFinalPropertyValue(property) -
                                                      _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                                      _tween_list[index]._total_frames);
            break;
        case EaseOutBack: __value = easeOutBack(_tween_list[index]._total_frames - _tween_list[index]._current_frame,
                                              _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                              _tween_list[index]._sprite_properties.GetFinalPropertyValue(property) -
                                              _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                              _tween_list[index]._total_frames);
            break;
        case EaseInOutBack: __value = easeInOutBack(_tween_list[index]._total_frames - _tween_list[index]._current_frame,
                                                _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                                _tween_list[index]._sprite_properties.GetFinalPropertyValue(property) -
                                                _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                                _tween_list[index]._total_frames);
            break;
        case EaseInBounce: __value = easeInBounce(_tween_list[index]._total_frames - _tween_list[index]._current_frame,
                                                    _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                                    _tween_list[index]._sprite_properties.GetFinalPropertyValue(property) -
                                                    _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                                    _tween_list[index]._total_frames);
            break;
        case EaseOutBounce: __value = easeOutBounce(_tween_list[index]._total_frames - _tween_list[index]._current_frame,
                                                  _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                                  _tween_list[index]._sprite_properties.GetFinalPropertyValue(property) -
                                                  _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                                  _tween_list[index]._total_frames);
            break;
        case EaseInOutBounce: __value = easeInOutBounce(_tween_list[index]._total_frames - _tween_list[index]._current_frame,
                                                    _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                                    _tween_list[index]._sprite_properties.GetFinalPropertyValue(property) -
                                                    _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                                    _tween_list[index]._total_frames);
            break;
        case EaseInCirc: __value = easeInCirc(_tween_list[index]._total_frames - _tween_list[index]._current_frame,
                                                        _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                                        _tween_list[index]._sprite_properties.GetFinalPropertyValue(property) -
                                                        _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                                        _tween_list[index]._total_frames);
            break;
        case EaseOutCirc: __value = easeOutCirc(_tween_list[index]._total_frames - _tween_list[index]._current_frame,
                                              _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                              _tween_list[index]._sprite_properties.GetFinalPropertyValue(property) -
                                              _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                              _tween_list[index]._total_frames);
            break;
        case EaseInOutCirc: __value = easeInOutCirc(_tween_list[index]._total_frames - _tween_list[index]._current_frame,
                                                _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                                _tween_list[index]._sprite_properties.GetFinalPropertyValue(property) -
                                                _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                                _tween_list[index]._total_frames);
            break;
        case EaseInElastic: __value = easeInElastic(_tween_list[index]._total_frames - _tween_list[index]._current_frame,
                                                    _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                                    _tween_list[index]._sprite_properties.GetFinalPropertyValue(property) -
                                                    _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                                    _tween_list[index]._total_frames);
            break;
        case EaseOutElastic: __value = easeOutElastic(_tween_list[index]._total_frames - _tween_list[index]._current_frame,
                                                    _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                                    _tween_list[index]._sprite_properties.GetFinalPropertyValue(property) -
                                                    _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                                    _tween_list[index]._total_frames);
            break;
        case EaseInOutElastic: __value = easeInOutElastic(_tween_list[index]._total_frames - _tween_list[index]._current_frame,
                                                      _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                                      _tween_list[index]._sprite_properties.GetFinalPropertyValue(property) -
                                                      _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                                      _tween_list[index]._total_frames);
            break;
        case EaseInExpo: __value = easeInExpo(_tween_list[index]._total_frames - _tween_list[index]._current_frame,
                                                          _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                                          _tween_list[index]._sprite_properties.GetFinalPropertyValue(property) -
                                                          _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                                          _tween_list[index]._total_frames);
            break;
        case EaseOutExpo: __value = easeOutExpo(_tween_list[index]._total_frames - _tween_list[index]._current_frame,
                                              _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                              _tween_list[index]._sprite_properties.GetFinalPropertyValue(property) -
                                              _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                              _tween_list[index]._total_frames);
            break;
        case EaseInOutExpo: __value = easeInOutExpo(_tween_list[index]._total_frames - _tween_list[index]._current_frame,
                                                _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                                _tween_list[index]._sprite_properties.GetFinalPropertyValue(property) -
                                                _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                                _tween_list[index]._total_frames);
            break;
        case EaseNoneLinear: __value = easeNoneLinear(_tween_list[index]._total_frames - _tween_list[index]._current_frame,
                                                    _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                                    _tween_list[index]._sprite_properties.GetFinalPropertyValue(property) -
                                                    _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                                    _tween_list[index]._total_frames);
            break;
        case EaseInLinear: __value = easeInLinear(_tween_list[index]._total_frames - _tween_list[index]._current_frame,
                                                      _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                                      _tween_list[index]._sprite_properties.GetFinalPropertyValue(property) -
                                                      _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                                      _tween_list[index]._total_frames);
            break;
        case EaseOutLinear: __value = easeOutLinear(_tween_list[index]._total_frames - _tween_list[index]._current_frame,
                                                  _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                                  _tween_list[index]._sprite_properties.GetFinalPropertyValue(property) -
                                                  _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                                  _tween_list[index]._total_frames);
            break;
        case EaseInOutLinear: __value = easeInOutLinear(_tween_list[index]._total_frames - _tween_list[index]._current_frame,
                                                    _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                                    _tween_list[index]._sprite_properties.GetFinalPropertyValue(property) -
                                                    _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                                    _tween_list[index]._total_frames);
            break;
        case EaseInQuad: __value = easeInQuad(_tween_list[index]._total_frames - _tween_list[index]._current_frame,
                                                        _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                                        _tween_list[index]._sprite_properties.GetFinalPropertyValue(property) -
                                                        _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                                        _tween_list[index]._total_frames);
            break;
        case EaseOutQuad: __value = easeOutQuad(_tween_list[index]._total_frames - _tween_list[index]._current_frame,
                                              _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                              _tween_list[index]._sprite_properties.GetFinalPropertyValue(property) -
                                              _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                              _tween_list[index]._total_frames);
            break;
        case EaseInOutQuad: __value = easeInOutQuad(_tween_list[index]._total_frames - _tween_list[index]._current_frame,
                                                _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                                _tween_list[index]._sprite_properties.GetFinalPropertyValue(property) -
                                                _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                                _tween_list[index]._total_frames);
            break;
        case EaseInQuart: __value = easeInQuart(_tween_list[index]._total_frames - _tween_list[index]._current_frame,
                                                    _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                                    _tween_list[index]._sprite_properties.GetFinalPropertyValue(property) -
                                                    _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                                    _tween_list[index]._total_frames);
            break;
        case EaseOutQuart: __value = easeOutQuart(_tween_list[index]._total_frames - _tween_list[index]._current_frame,
                                                _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                                _tween_list[index]._sprite_properties.GetFinalPropertyValue(property) -
                                                _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                                _tween_list[index]._total_frames);
            break;
        case EaseInOutQuart: __value = easeInOutQuart(_tween_list[index]._total_frames - _tween_list[index]._current_frame,
                                                  _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                                  _tween_list[index]._sprite_properties.GetFinalPropertyValue(property) -
                                                  _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                                  _tween_list[index]._total_frames);
            break;
        case EaseInQuint: __value = easeInQuint(_tween_list[index]._total_frames - _tween_list[index]._current_frame,
                                                      _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                                      _tween_list[index]._sprite_properties.GetFinalPropertyValue(property) -
                                                      _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                                      _tween_list[index]._total_frames);
            break;
        case EaseOutQuint: __value = easeOutQuint(_tween_list[index]._total_frames - _tween_list[index]._current_frame,
                                                _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                                _tween_list[index]._sprite_properties.GetFinalPropertyValue(property) -
                                                _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                                _tween_list[index]._total_frames);
            break;
        case EaseInOutQuint: __value = easeInOutQuint(_tween_list[index]._total_frames - _tween_list[index]._current_frame,
                                                  _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                                  _tween_list[index]._sprite_properties.GetFinalPropertyValue(property) -
                                                  _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                                  _tween_list[index]._total_frames);
            break;
        case EaseInSine: __value = easeInSine(_tween_list[index]._total_frames - _tween_list[index]._current_frame,
                                                      _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                                      _tween_list[index]._sprite_properties.GetFinalPropertyValue(property) -
                                                      _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                                      _tween_list[index]._total_frames);
            break;
        case EaseOutSine: __value = easeOutSine(_tween_list[index]._total_frames - _tween_list[index]._current_frame,
                                              _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                              _tween_list[index]._sprite_properties.GetFinalPropertyValue(property) -
                                              _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                              _tween_list[index]._total_frames);
            break;
        case EaseInOutSine: __value = easeInOutSine(_tween_list[index]._total_frames - _tween_list[index]._current_frame,
                                                _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                                _tween_list[index]._sprite_properties.GetFinalPropertyValue(property) -
                                                _tween_list[index]._sprite_properties.GetInitialPropertyValue(property),
                                                _tween_list[index]._total_frames);
            break;
    }

    return __value;
}

// t: current time, b: begInnIng value, c: change In value, d: duration
float AnimationEngine::easeInCubic (float t, float b , float c, float d)
{
    return c*(t/=d)*t*t + b;
}

float AnimationEngine::easeOutCubic(float t,float b , float c, float d)
{
    return c*((t=t/d-1)*t*t + 1) + b;
}

float AnimationEngine::easeInOutCubic(float t,float b , float c, float d)
{
    if ((t/=d/2) < 1) return c/2*t*t*t + b;
    return c/2*((t-=2)*t*t + 2) + b;
}

float AnimationEngine::easeInBack (float t, float b , float c, float d)
{
    float s = 1.70158f;
    float postFix = t/=d;
    return c*(postFix)*t*((s+1)*t - s) + b;
}
float AnimationEngine::easeOutBack(float t,float b , float c, float d)
{
    float s = 1.70158f;
    return c*((t=t/d-1)*t*((s+1)*t + s) + 1) + b;
}

float AnimationEngine::easeInOutBack(float t,float b , float c, float d)
{
    float s = 1.70158f;
    if ((t/=d/2) < 1) return c/2*(t*t*(((s*=(1.525f))+1)*t - s)) + b;
    float postFix = t-=2;
    return c/2*((postFix)*t*(((s*=(1.525f))+1)*t + s) + 2) + b;
}

float AnimationEngine::easeInBounce (float t,float b , float c, float d)
{
    return c - easeOutBounce (d-t, 0, c, d) + b;
}
float AnimationEngine::easeOutBounce(float t,float b , float c, float d)
{
    if ((t/=d) < (1/2.75f)) {
        return c*(7.5625f*t*t) + b;
    } else if (t < (2/2.75f)) {
        float postFix = t-=(1.5f/2.75f);
        return c*(7.5625f*(postFix)*t + .75f) + b;
    } else if (t < (2.5/2.75)) {
        float postFix = t-=(2.25f/2.75f);
        return c*(7.5625f*(postFix)*t + .9375f) + b;
    } else {
        float postFix = t-=(2.625f/2.75f);
        return c*(7.5625f*(postFix)*t + .984375f) + b;
    }
}

float AnimationEngine::easeInOutBounce(float t,float b , float c, float d)
{
    if (t < d/2) return easeInBounce (t*2, 0, c, d) * .5f + b;
    else return easeOutBounce (t*2-d, 0, c, d) * .5f + c*.5f + b;
}

float AnimationEngine::easeInCirc (float t,float b , float c, float d)
{
    return -c * (sqrt(1 - (t/=d)*t) - 1) + b;
}
float AnimationEngine::easeOutCirc(float t,float b , float c, float d)
{
    return c * sqrt(1 - (t=t/d-1)*t) + b;
}

float AnimationEngine::easeInOutCirc(float t,float b , float c, float d)
{
    if ((t/=d/2) < 1) return -c/2 * (sqrt(1 - t*t) - 1) + b;
    return c/2 * (sqrt(1 - t*(t-=2)) + 1) + b;
}

float AnimationEngine::easeInElastic(float t,float b , float c, float d)
{
    if (t==0) return b;  if ((t/=d)==1) return b+c;
    float p=d*.3f;
    float a=c;
    float s=p/4;
    float postFix =a*pow(2,10*(t-=1)); // this is a fix, again, with post-increment operators
    return -(postFix * sin((t*d-s)*(2*PI)/p )) + b;
}

float AnimationEngine::easeOutElastic(float t,float b , float c, float d)
{
    if (t==0) return b;  if ((t/=d)==1) return b+c;
    float p=d*.3f;
    float a=c;
    float s=p/4;
    return (a*pow(2,-10*t) * sin( (t*d-s)*(2*PI)/p ) + c + b);
}

float AnimationEngine::easeInOutElastic(float t,float b , float c, float d)
{
    if (t==0) return b;  if ((t/=d/2)==2) return b+c;
    float p=d*(.3f*1.5f);
    float a=c;
    float s=p/4;

    if (t < 1) {
        float postFix =a*pow(2,10*(t-=1)); // postIncrement is evil
        return -.5f*(postFix* sin( (t*d-s)*(2*PI)/p )) + b;
    }
    float postFix =  a*pow(2,-10*(t-=1)); // postIncrement is evil
    return postFix * sin( (t*d-s)*(2*PI)/p )*.5f + c + b;
}

float AnimationEngine::easeInExpo(float t,float b , float c, float d)
{
    return (t==0) ? b : c * pow(2, 10 * (t/d - 1)) + b;
}

float AnimationEngine::easeOutExpo(float t,float b , float c, float d)
{
    return (t==d) ? b+c : c * (-pow(2, -10 * t/d) + 1) + b;
}

float AnimationEngine::easeInOutExpo(float t,float b , float c, float d)
{
    if (t==0) return b;
    if (t==d) return b+c;
    if ((t/=d/2) < 1) return c/2 * pow(2, 10 * (t - 1)) + b;
    return c/2 * (-pow(2, -10 * --t) + 2) + b;
}

float AnimationEngine::easeNoneLinear(float t,float b , float c, float d)
{
    return c*t/d + b;
}

float AnimationEngine::easeInLinear(float t,float b , float c, float d)
{
    return c*t/d + b;
}

float AnimationEngine::easeOutLinear(float t,float b , float c, float d)
{
    return c*t/d + b;
}

float AnimationEngine::easeInOutLinear(float t,float b , float c, float d)
{
    return c*t/d + b;
}

float AnimationEngine::easeInQuad(float t,float b , float c, float d)
{
    return c*(t/=d)*t + b;
}

float AnimationEngine::easeOutQuad(float t,float b , float c, float d)
{
    return -c *(t/=d)*(t-2) + b;
}

float AnimationEngine::easeInOutQuad(float t,float b , float c, float d)
{
    if ((t/=d/2) < 1) return ((c/2)*(t*t)) + b;
    return -c/2 * (((t-2)*(--t)) - 1) + b;
    /*
     originally return -c/2 * (((t-2)*(--t)) - 1) + b;

     I've had to swap (--t)*(t-2) due to diffence in behaviour in
     pre-increment operators between java and c++, after hours
     of joy
     */

}

float AnimationEngine::easeInQuart(float t,float b , float c, float d)
{
    return c*(t/=d)*t*t*t + b;
}

float AnimationEngine::easeOutQuart(float t,float b , float c, float d)
{
    return -c * ((t=t/d-1)*t*t*t - 1) + b;
}

float AnimationEngine::easeInOutQuart(float t,float b , float c, float d)
{
    if ((t/=d/2) < 1) return c/2*t*t*t*t + b;
    return -c/2 * ((t-=2)*t*t*t - 2) + b;
}

float AnimationEngine::easeInQuint(float t,float b , float c, float d)
{
    return c*(t/=d)*t*t*t*t + b;
}
float AnimationEngine::easeOutQuint(float t,float b , float c, float d)
{
    return c*((t=t/d-1)*t*t*t*t + 1) + b;
}

float AnimationEngine::easeInOutQuint(float t,float b , float c, float d)
{
    if ((t/=d/2) < 1) return c/2*t*t*t*t*t + b;
    return c/2*((t-=2)*t*t*t*t + 2) + b;
}

float AnimationEngine::easeInSine (float t,float b , float c, float d)
{
    return -c * cos(t/d * (PI/2)) + c + b;
}

float AnimationEngine::easeOutSine(float t,float b , float c, float d)
{
    return c * sin(t/d * (PI/2)) + b;
}

float AnimationEngine::easeInOutSine(float t,float b , float c, float d)
{
    return -c/2 * (cos(PI*t/d) - 1) + b;
}
