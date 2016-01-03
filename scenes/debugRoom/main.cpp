// Engine Include
#include "../../engine/engine.hpp"

// Custom User Scripts
#include "script_template.hpp"

int main(int argc, char **argv)
{
    // Do not change this line.
    Engine::Init();
    
    // Declare and Subscribe your scripts here.
    ScriptTemplate * __script = new ScriptTemplate();
    ScriptManager::Subscribe(__script);
    
    // Do not change this line.
    Engine::Loop();
    
    // Do not change this line.
    Engine::Finalize();
}
