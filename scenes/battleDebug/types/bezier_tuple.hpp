#ifndef __BEZIER_TUPLE__
#define __BEZIER_TUPLE__

// Engine include
#include "../../../engine/engine.hpp"

class BezierTuple
{
  public: Point2D * _current;
  public: Point2D * _next;
  public: Point2D * _control;
  
  public: BezierTuple ()
  {
    _current = new Point2D();
    _next = new Point2D();
    _control = new Point2D();
  }
};

#endif // __BEZIER_TUPLE__
