// Engine Include
#include "../../engine/engine.hpp"

// Custom User Scripts
#include "board_task.hpp"
#include "clock.hpp"

// DEBUG TEST
#include "../../assets/audio/battleTheme.h"
#include "../../assets/graphics/BG1.h"

int main(int argc, char **argv)
{
    // Do not change this line.
    Engine::Init();
    
    // DEBUG
    Music * __msc;
    __msc = new Music(battleTheme, battleTheme_size, 1000);
    //AudioEngine::PlayMusic(__msc, false, 128);
    
    // Animation and Sprite Managers
    SpriteManager * _spriteManager = new SpriteManager();
    AnimationManager * _animationManager = new AnimationManager(_spriteManager);
    
    // Intialize BG
    Sprite * _bg;
    GRRLIB_texImg* _bgText;
    _bgText = GRRLIB_LoadTexture(BG1);
    _bg = new Sprite(_bgText, 0, 0, 640, 480);
    GraphicEngine::_stage->AddChild(_bg);
    
    // Declare and Subscribe your scripts here.
    BoardTask * __board_p1 = new BoardTask("P1 Board",
                                           Dim2D(6,11),
                                           Point2D(32, 64),
                                           Point2D(0,5),
                                           PPL_PLAYER_1,
                                           _spriteManager,
                                           _animationManager);
    BoardTask * __board_p2 = new BoardTask("P2 Board",
                                           Dim2D(6,11),
                                           Point2D(419, 108),
                                           Point2D(3,5),
                                           PPL_PLAYER_2,
                                           _spriteManager,
                                           _animationManager);
    
    // Initialize Game Clock
    Clock * __system_clock = new Clock(_spriteManager);
    
    
        
    // Register Boards
    ScriptManager::Subscribe(__board_p1);
    ScriptManager::Subscribe(__board_p2);
    
    // Register Clock
    ScriptManager::Subscribe(__system_clock);
    
    // Do not change this line.
    Engine::Loop();

    // Do not change this line.
    Engine::Finalize();
}
