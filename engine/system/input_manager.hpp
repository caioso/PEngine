#ifndef __INPUT_MANAGER__
#define __INPUT_MANAGER__

#include "../base/controller.hpp"
#include "debug.hpp"
#include <wiiuse/wpad.h>
#include <vector>

using namespace std;

class InputManager
{
    public: static vector<Controller*> _registered_controllers;
    public: static char _scoreboard;
    
    // Initializes controller settings in GRRLIB side
    public: static void Init ();
    
    // Register a new controller in the system. Controller scoreboard
    // is also checked to ensure two same players are not registered.
    // @param controller: Controller object reference.
    public: static void RegisterController (Controller * controller);
    
    // Read input and update controller buffers accordingly.
    // Must be called once each frame.
    public: static void UpdateInput ();
};

#endif // __INPUT_MANAGER__