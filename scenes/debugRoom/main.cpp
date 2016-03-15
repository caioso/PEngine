// Engine Include
#include "../../engine/engine.hpp"

// Custom User Scripts
#include "script_template.hpp"
#include "demo_script_2.hpp"

int main(int argc, char **argv)
{
    // Do not change this line.
    Engine::Init();
    
    // Declare and Subscribe your scripts here.
    DemoScript2 * __demo = new DemoScript2();
    ScriptManager::Subscribe(__demo);
    
    ScriptTemplate * __script = new ScriptTemplate();
    ScriptManager::Subscribe(__script);
    
    // Do not change this line.
    Engine::Loop();
    
    // Do not change this line.
    Engine::Finalize();
}
