#pragma once
#ifndef __PARTICLE__
#define __PARTICLE__

// Engine includes
#include "../../../engine/engine.hpp"

class Particle: public Sprite
{
  // Determines if the particle have changed its position.
  private: bool _moved;

  // Default constructor
  // @param image: particle texture.
  // @param width: particle width.
  // @param height: particle height.
  // @param moved: informs if the particle has chanced its position.
  public: Particle (GRRLIB_texImg * image, int width, int height, bool moved = false) : Sprite (image, width, height), _moved(moved) {}

  // Gets _moved.
  // @return: _moved
  public: bool GetMoved () { return _moved; }

  // Sets _moved.
  // @param moved: intended value for _moved.
  public: void SetMoved (bool moved) { _moved = moved; }
};

#endif // __PARTICLE__
