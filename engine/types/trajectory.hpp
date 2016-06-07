#ifndef __TRAJECTORY__
#define __TRAJECTORY__

#include "point2d.hpp"

enum PointType {
                // Absolute Position, relative to the parent sprite
                AbsolutePoint,
                // Relative Position. Will be added to the coordinates.
                RelativePoint,
                // Ignore Position. Will not be used in this frame.
                IgnorePoint
               };

class Trajectory
{
    public: Point2D _point;
    public: PointType _type;
};

#endif // __TRAJECTORY__