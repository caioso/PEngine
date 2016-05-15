#include "framerate_controller.hpp"

unsigned long int FramerateController::_frames;
double FramerateController::_start_time;
float FramerateController::_fps;
double FramerateController::_beginFrame;
double FramerateController::_endFrame;
double FramerateController::_deltaTime;

void FramerateController::Init()
{
    _frames = 0;
    _deltaTime = 0;
    _start_time = 0;
    _fps = 0.0f;
}

void FramerateController::StartCount ()
{
    _beginFrame = ticks_to_millisecs(gettime());
    _frames++;
}

void FramerateController::EndCount ()
{
    _endFrame = ticks_to_millisecs(gettime());
    _deltaTime += _endFrame - _beginFrame;


    if(_deltaTime>1000.0)
    {
        Debug::RegisterFramerate(_frames);
        _beginFrame = ticks_to_millisecs(gettime());
        _deltaTime = 0;
        _frames = 0;
    }
}

double FramerateController::ClockToMilliseconds(clock_t ticks)
{
    return (ticks/(double)CLOCKS_PER_SEC)/1000.0;
}

