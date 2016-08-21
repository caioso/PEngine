#ifndef __BEZIER_CONTROLLER__
#define __BEZIER_CONTROLLER__

// Engine include
#include "../../../engine/engine.hpp"

// custom type
#include "types/bezier.hpp"
#include "board_constants.hpp"

class BezierController
{
  // List of Bezier curves
  private: vector<Bezier> _curves;

  private: GRRLIB_texImg * _particle_asset;
  private: int _asset_width;
  private: int _asset_height;

  // DEBUG ONLY
  private: int __counter;

  // default constructor
  // @param asset: particle asset;
  // @param width: particle width;
  // @param height: particle height;
  public: BezierController (GRRLIB_texImg * asset, int width, int height)
  {
    _particle_asset = asset;
    _asset_width = width;
    _asset_height = height;
    __counter = 0;
  }

  // Computes a specific bezier point for a given time
  // @param P0: intial point.
  // @param P1: final point.
  // @param C: control point.
  // @param t: time sample
  Point2D * quadraticBezier(Point2D * P0, Point2D * P1, Point2D  * C, float t)
  {
    Point2D * __point = new Point2D();
    __point->setX((1 - t) * (1 - t) * P0->getX() + (2 - 2 * t) * t * C->getX() + t * t * P1->getX());
    __point->setY((1 - t) * (1 - t) * P0->getY() + (2 - 2 * t) * t * C->getY() + t * t * P1->getY());

    return __point;
  }

  // Updates each bezier trail point.
  public: void UpdateBezierParticles ()
  {
    //int j = 0;
    for (unsigned int j = 0; j < _curves.size(); j++)
    {
      for (int k = 0; k < 4; k++)
      {
        for (int i = BEZIER_TRAIL_LENGTH - 1; i >= 0; i-=1)
        {
          // If first particle, update its position
          int __alpha = _curves[j]._particles[i]->GetMoved()? 255 - (255/BEZIER_TRAIL_LENGTH)*(i) : 0;
          _curves[j]._particles[i]->_alpha = __alpha;

          if (i == 0)
          {
            _curves[j]._particles[0]->_x = _curves[j]._curve[_curves[j]._pivot]->getX();
            _curves[j]._particles[0]->_y = _curves[j]._curve[_curves[j]._pivot]->getY();

            if (_curves[j]._pivot < BEZIER_TOTAL_POINTS - 1)
              _curves[j]._pivot+=1;

            _curves[j]._particles[0]->SetMoved(true);
          }
          else // Move positions otherwise
          {
            if (_curves[j]._particles[i]->_x != _curves[j]._particles[i - 1]->_x || _curves[j]._particles[i]->_y != _curves[j]._particles[i - 1]->_y)
            {
                _curves[j]._particles[i]->SetMoved(true);
                _curves[j]._particles[i]->_x = _curves[j]._particles[i - 1]->_x;
                _curves[j]._particles[i]->_y = _curves[j]._particles[i - 1]->_y;
            }
            else
            {
                _curves[j]._particles[i]->SetMoved(false);
            }
          }
        }
      }
      if (_curves[j]._particles[0]->_x == _curves[j]._particles[BEZIER_TRAIL_LENGTH - 1]->_x &&
          _curves[j]._particles[0]->_y == _curves[j]._particles[BEZIER_TRAIL_LENGTH - 1]->_y)
          {
              // Remove particles from stage.
              for (int i = BEZIER_TRAIL_LENGTH - 1; i >= 0; i-=1)
              {
                  GraphicEngine::_stage->RemoveChild(_curves[j]._particles[i]);
              }

              _curves.erase(_curves.begin() + j);
              j--;
          }
    }
  }

  // Compute Bezier curve
  public: void ComputeBezierPointsAndParticles(Point2D *origin, Point2D *end)
  {
    Bezier __bezier;
    __bezier._bezierTuple->_current->setX(origin->getX());
    __bezier._bezierTuple->_current->setY(origin->getY());

    __bezier._bezierTuple->_next->setX(end->getX());
    __bezier._bezierTuple->_next->setY(end->getY());

    // 0.5773502 : Magic value ;) -> 1/sqrt(3).
    __bezier._bezierTuple->_control->setX(__bezier._bezierTuple->_next->getX() + 0.5773502*(__bezier._bezierTuple->_next->getY() - __bezier._bezierTuple->_current->getY()));
    __bezier._bezierTuple->_control->setY(__bezier._bezierTuple->_next->getY() - 0.5773502*(__bezier._bezierTuple->_next->getX() - __bezier._bezierTuple->_current->getX()));

    for (int i = 0; i < BEZIER_TOTAL_POINTS; i++)
    {
      // Compute particle position
      Point2D * __point = quadraticBezier(__bezier._bezierTuple->_current, __bezier._bezierTuple->_next, __bezier._bezierTuple->_control, i/((float)BEZIER_TOTAL_POINTS));
      __bezier._curve.push_back(__point);
    }

    for (int i = 0; i < BEZIER_TRAIL_LENGTH; i++)
    {
      // Build particle element
      Particle * __particle = new Particle(_particle_asset, _asset_width, _asset_height);
      // Adjust Particle  Scale
      __particle->_scaleX = (BEZIER_PARTICLE_SCALE - (BEZIER_PARTICLE_SCALE/BEZIER_TRAIL_LENGTH)*(i/2));
      __particle->_scaleY = (BEZIER_PARTICLE_SCALE - (BEZIER_PARTICLE_SCALE/BEZIER_TRAIL_LENGTH)*(i/2));

      __bezier._particles.push_back(__particle);

      GraphicEngine::_stage->AddChild(__bezier._particles[__bezier._particles.size() - 1]);
    }
    _curves.push_back(__bezier);
  }
};

#endif // __BEZIER_CONTROLLER__
