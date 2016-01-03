#include "script_manager.hpp"

vector<Runnable*> ScriptManager::_script_list;
unsigned int ScriptManager::_thread_number;
unsigned int ScriptManager::_script_number;

void ScriptManager::Init ()
{
    _thread_number = 0;
}

void ScriptManager::Subscribe (Runnable * script)
{
    if (script->_script_id == -1)
    {
        script->_script_id = ++_script_number;
        _script_list.push_back(script);
    }
    else
        Debug::LogWarning("Script Already Registered.");

    script->Start();
    return;
}

void ScriptManager::Unscribe (Runnable * script)
{
    for (size_t i = 0; i < _script_list.size(); i++)
        if (_script_list[i]->_script_id == script->_script_id)
        {
            _script_list[i]->End();
            _script_list.erase(_script_list.begin() + i);
            return;
        }
    
    Debug::LogWarning("Script not registered.");
}

void ScriptManager::UpdateScripts ()
{
    for (size_t i = 0; i < _script_list.size(); i++)
        _script_list[i]->Update();
}