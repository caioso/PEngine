#ifndef __ENGINE__
#define __ENGINE__

// Wii/GRRLIB Includes
#include <grrlib.h>
#include <stdlib.h>
#include <wiiuse/wpad.h>
#include <string>
#include <time.h>
#include <memory>
#include <math.h>
#include <sstream>
#include <sdl/SDL_thread.h>
#include <sdl/SDL_timer.h>
#include <asndlib.h>
#include <mp3player.h>

// Common Includes
#include "common/constants.h"
#include "common/macros.h"

// Base Includes
#include "base/controller.hpp"
#include "base/sound.hpp"
#include "base/music.hpp"
#include "base/runnable.hpp"
#include "base/sprite.hpp"
#include "base/animated_sprite.hpp"

// System Includes
#include "system/audio_engine.hpp"
#include "system/debug.hpp"
#include "system/graphic_engine.hpp"
#include "system/input_manager.hpp"
#include "system/script_manager.hpp"
#include "system/animation_engine.hpp"

// Utils
#include "utils/framerate_controller.hpp"

// Type Includes
#include "types/point2d.hpp"
#include "types/dim2D.hpp"
#include "types/sprite_properties.hpp"

class Engine
{
    // Control main loop execition.
    private: static bool finish_main_loop;

    // Initialize engine
    public: static void Init ();

    // Game Main Loop
    public: static void Loop ();

    // Abort Loop in the next iteration of the main loop.
    public: static void AbortLoop ();

    // Finalizes the engine resources.
    public: static void Finalize ();
};

#endif // __ENGINE__
