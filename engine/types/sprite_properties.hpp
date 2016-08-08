#ifndef __SPRITE_PROTERTIES__
#define __SPRITE_PROTERTIES__

// Enum that identifies the names of the animatable properties of Sprites.
enum SpritePropertyName
{
    SpriteX,
    SpriteY,
    SpriteScaleX,
    SpriteScaleY,
    SpriteRotation,
    SpriteAlpha
};

class SpriteProperties
{
    // Property map stores which sprite properties the tween is meant to
    // modify. Currently there exists five properties, organized as the
    // following map:
    // bit 0: _x
    // bit 1: _y;
    // bit 2: _scaleX;
    // bit 3: _scaleY;
    // bit 4: _rotation;
    private: unsigned int _property_map;
    
    // Sprite Reference
    Sprite * _sprite;
    
    // Initial Tween properties;
    private: float _initial_x;
    private: float _initial_y;
    private: float _initial_scaleX;
    private: float _initial_scaleY;
    private: float _initial_rotation;
    private: char _initial_alpha;
    
    // Final value of tween properties;
    private: float _final_x;
    private: float _final_y;
    private: float _final_scaleX;
    private: float _final_scaleY;
    private: float _final_rotation;
    private: char _final_alpha;
    
    // Default Constructor
    public: SpriteProperties() : _property_map(0), _sprite(NULL), _final_x(0), _final_y(0), _final_scaleX(0), _final_scaleY(0), _final_rotation(0), _final_alpha(0){}

    // Standard Contructor
    // @param sprite: Object used to initialize the initial values of the Properties
    public: SpriteProperties(Sprite * sprite) : _property_map(0), _final_x(0), _final_y(0), _final_scaleX(0), _final_scaleY(0), _final_rotation(0), _final_alpha(0)
    {
        _sprite = sprite;
        _initial_x = sprite->_x;
        _initial_y = sprite->_y;
        _initial_scaleX = sprite->_scaleX;
        _initial_scaleY = sprite->_scaleY;
        _initial_rotation = sprite->_rotation;
        _initial_alpha = sprite->_alpha;
    };
    
    // Register Property final value in their respective internal vartibales and update the property map
    // signaling animation intention.
    // @param name: Property name;
    // @param finalValue: Final value of the property in the animation.
    public: void RegisterPropertyFinalValue (SpritePropertyName name, float finalValue)
    {
        switch (name)
        {
            case SpriteX: _final_x = finalValue;
                _property_map |= 1;
                break;
            case SpriteY: _final_y = finalValue;
                _property_map |= 2;
                break;
            case SpriteScaleX: _final_scaleX = finalValue;
                _property_map |= 4;
                break;
            case SpriteScaleY: _final_scaleY = finalValue;
                _property_map |= 8;
                break;
            case SpriteRotation: _final_rotation = finalValue;
                _property_map |= 16;
                break;
            case SpriteAlpha: _final_alpha = finalValue;
                _property_map |= 32;
                break;
        }
    }
    
    // Update Property current value
    // @param name: Property name;
    // @param value: updated value of the property in the animation.
    public: void UpdatePropertyValue (SpritePropertyName name, float value)
    {
        switch (name)
        {
            case SpriteX: _sprite->_x = value;
                break;
            case SpriteY: _sprite->_y = value;
                break;
            case SpriteScaleX: _sprite->_scaleX = value;
                break;
            case SpriteScaleY: _sprite->_scaleY = value;
                break;
            case SpriteRotation: _sprite->_rotation = value;
                break;
            case SpriteAlpha: _sprite->_alpha = (char)value;
                break;
        }
    }
    
    
    // Returns value of final property
    // @param name: Property name;
    public: float GetFinalPropertyValue (SpritePropertyName name)
    {
        switch (name)
        {
            case SpriteX: return _final_x;
                break;
            case SpriteY: return _final_y;
                break;
            case SpriteScaleX: return _final_scaleX;
                break;
            case SpriteScaleY: return _final_scaleY;
                break;
            case SpriteRotation: return _final_rotation;
                break;
            case SpriteAlpha: return (float)_final_alpha;
                break;

        }
        return 0.0;
    }
    
    // Returns value of initial property
    // @param name: Property name;
    public: float GetInitialPropertyValue (SpritePropertyName name)
    {
        switch (name)
        {
            case SpriteX: return _initial_x;
                break;
            case SpriteY: return _initial_y;
                break;
            case SpriteScaleX: return _initial_scaleX;
                break;
            case SpriteScaleY: return _initial_scaleY;
                break;
            case SpriteRotation: return _initial_rotation;
                break;
            case SpriteAlpha: return _initial_alpha;
                break;
        }
        return 0.0;
    }

    // Informs if a given property is registered
    // @param name: Property name;
    public: bool IsPropertyRegistered (SpritePropertyName name)
    {
        switch (name)
        {
            case SpriteX: return (_property_map&1) != 0? true : false;
                break;
            case SpriteY: return (_property_map&2) != 0? true : false;
                break;
            case SpriteScaleX: return (_property_map&4) != 0? true : false;
                break;
            case SpriteScaleY: return (_property_map&8) != 0? true : false;
                break;
            case SpriteRotation: return (_property_map&16) != 0? true : false;
                break;
            case SpriteAlpha: return (_property_map&32) != 0? true : false;
                break;
        }
        return false;
    }
    
    
};

#endif // __SPRITE_PROTERTIES__