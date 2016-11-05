#ifndef __TRANSFORMATION__
#define __TRANSFORMATION__

#include "point2d.hpp"

enum PointType {
                // Absolute Position, relative to the parent sprite
                AbsolutePoint,
                // Relative Position. Will be added to the coordinates.
                RelativePoint,
               };
 enum RotationType {
                 // Absolute Rotation, will overwrite the rotation value.
                 AbsoluteRotation,
                 // Incremental Position. Will be added to the rotation.
                 IncrementalRotation
                };

  enum ScaleXType {
                  // Absolute ScaleX, will overwrite the scaleX value.
                  AbsoluteScaleX,
                  // Incremental ScaleX. Will be added to the scaleX.
                  IncrementalScaleX
                 };

   enum ScaleYType {
                   // Absolute ScaleY, will overwrite the scaleY value.
                   AbsoluteScaleY,
                   // Incremental ScaleY. Will be added to the scaleY.
                   IncrementalScaleY
                  };

    enum AlphaType {
                    // Absolute Alpha, will overwrite the alpha value.
                    AbsoluteAlpha,
                    // Incremental Alpha. Will be added to the alpha.
                    IncrementalAlpha
                   };

class Transformation
{
    public: Point2D _point;
    public: PointType _pointType;

    public: float _rotation;
    public: RotationType _rotationType;

    public: float _scaleX;
    public: ScaleXType _scaleXType;

    public: float _scaleY;
    public: ScaleYType _scaleYType;

    public: char _alpha;
    public: AlphaType _alphaType;

    // Setters
    public: void SetPoint (Point2D _p, PointType _t = AbsolutePoint) { _point = _p; _pointType = _t; }
    public: void SetRotation (float _r, RotationType _t = AbsoluteRotation) { _rotation = _r; _rotationType = _t; }
    public: void SetScaleX (float _sX, ScaleXType _t = AbsoluteScaleX) { _scaleX = _sX; _scaleXType = _t; }
    public: void SetScaleY (float _sY, ScaleYType _t = AbsoluteScaleY) { _scaleY = _sY; _scaleYType = _t; }
    public: void SetAlpha (char _a, AlphaType _t = AbsoluteAlpha) { _alpha = _a; _alphaType = _t; }
    public: void RegisterFullAbsoluteTransformation (Point2D _p, float _r, float _sX, float _sY, char _a)
    {
       _point = _p; _pointType = AbsolutePoint;
       _rotation = _r; _rotationType = AbsoluteRotation;
       _scaleX = _sX; _scaleXType = AbsoluteScaleX;
       _scaleY = _sY; _scaleYType = AbsoluteScaleY;
       _alpha = _a; _alphaType = AbsoluteAlpha;
    }

    public: void RegisterFullIncrementalTransformation (Point2D _p, float _r, float _sX, float _sY, char _a)
    {
       _point = _p; _pointType = RelativePoint;
       _rotation = _r; _rotationType = IncrementalRotation;
       _scaleX = _sX; _scaleXType = IncrementalScaleX;
       _scaleY = _sY; _scaleYType = IncrementalScaleY;
       _alpha = _a; _alphaType = IncrementalAlpha;
    }
};

#endif // __TRANSFORMATION__
