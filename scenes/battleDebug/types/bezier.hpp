#ifndef __BEZIER__
#define __BEZIER__

// Engine include
#include "../../../engine/engine.hpp"

// custom type
#include "particle.hpp"
#include "bezier_tuple.hpp"

class Bezier
{
    public: vector<Particle*> _particles;
    public: vector<Point2D*> _curve;
    public: BezierTuple * _bezierTuple;
    public: int _pivot;
    public: Bezier ()
    {
      _pivot = 0;
      _bezierTuple = new BezierTuple();
    }
};

#endif // __BEZIER__
