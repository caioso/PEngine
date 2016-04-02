#include "engine.hpp"

bool Engine::finish_main_loop;

void Engine::Init ()
{
    GraphicEngine::Init();
    AudioEngine::Init(255, 255);
    InputManager::Init();
    //Debug::Init(300, 0);
    ScriptManager::Init();
    Engine::finish_main_loop = false;
}

// Game Main Loop
void Engine::Loop ()
{
    while(1)
    {
        if (finish_main_loop)
            break;

        // Read Input - BEGIN
        InputManager::UpdateInput ();

        // Update Scripts - MIDDLE
        ScriptManager::UpdateScripts();

        // Update Graphics and Audio - END
        AudioEngine::StreamAudio();
        GraphicEngine::Render();
        Debug::Render();
        GRRLIB_Render();
    }
}

// Abort Loop in the next iteration of the main loop.
void Engine::AbortLoop ()
{
    finish_main_loop = true;
}

// Finalizes the engine resources.
void Engine::Finalize ()
{
    GRRLIB_Exit();
    exit(0);
}
