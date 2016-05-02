#ifndef __FRAMERATE_CONTROLLER__
#define __FRAMERATE_CONTROLLER__

// Standard includes
#include <stdint.h>
#include <iostream>
#include <sstream>
#include <ogc/lwp_watchdog.h>

// System Includes
#include "../system/debug.hpp"

class FramerateController
{
    private: static unsigned long int _frames;
    private: static double _start_time;
    private: static float _fps;
    private: static double _beginFrame;
    private: static double _endFrame;
    private: static double _deltaTime;
    
    // Intializes Framerate Controller.
    public: static void Init();
    
    // Starts counting the frames
    public: static void StartCount ();
    
    // Starts Ends the frames
    public: static void EndCount ();
    
    // Converts Clock to Miliseconds
    // @param ticks: time delta;
    private: static double ClockToMilliseconds(clock_t ticks);
};

#endif // __FRAMERATE_CONTROLLER__