#include "input_manager.hpp"

vector<Controller*> InputManager::_registered_controllers;
char InputManager::_scoreboard;

void InputManager::Init ()
{
    WPAD_Init();
    WPAD_SetIdleTimeout(600);
    
    _scoreboard = 0;
}

void InputManager::RegisterController (Controller * controller)
{
    if ((_scoreboard&controller->GetPlayerNumber()) != 0)
    {
        Debug::LogWarning("Controller already registered.");
        return;
    }
    
    _scoreboard |= controller->GetPlayerNumber();
    _registered_controllers.push_back(controller);
}

void InputManager::UpdateInput ()
{
    WPAD_ScanPads();
    for (size_t i = 0; i < _registered_controllers.size(); i++)
    {
        // Down keys
        _registered_controllers[i]->SetKeysDown(WPAD_ButtonsDown(_registered_controllers[i]->GetChannel()));
        // Up Keys
        _registered_controllers[i]->SetKeysUp(WPAD_ButtonsDown(_registered_controllers[i]->GetChannel()));
        // Held Keys
        _registered_controllers[i]->SetKeysHeld(WPAD_ButtonsDown(_registered_controllers[i]->GetChannel()));
    }
}