#include "script_template.hpp"

void ScriptTemplate::Start ()
{
    Debug::LogWarning("Script Started.");
}

void ScriptTemplate::Update ()
{
    Debug::LogWarning("Script Running.");
    ScriptManager::Unscribe(this);
        
}

void ScriptTemplate::End ()
{
    Debug::LogWarning("Script Finished.");
}