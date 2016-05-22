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
    AudioEngine::PlayMusic(__msc, false, 128);
    
    SpriteManager * _spriteManager = new SpriteManager();
    
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
                                           _spriteManager);
    BoardTask * __board_p2 = new BoardTask("P2 Board",
                                           Dim2D(6,11),
                                           Point2D(419, 108),
                                           Point2D(3,5),
                                           PPL_PLAYER_2,
                                           _spriteManager);
    
    // Initialize Game Clock
    Clock * __system_clock = new Clock(_spriteManager);
    
    
    Sprite * _break = new Sprite(_spriteManager->_blueBreak0001, 32, 160);
    _break->RegisterFrame(_spriteManager->_blueBreak0001);
    _break->RegisterFrame(_spriteManager->_blueBreak0002);
    _break->RegisterFrame(_spriteManager->_blueBreak0003);
    _break->RegisterFrame(_spriteManager->_blueBreak0004);
    _break->RegisterFrame(_spriteManager->_blueBreak0005);
    _break->RegisterFrame(_spriteManager->_blueBreak0006);
    _break->RegisterFrame(_spriteManager->_blueBreak0007);
    _break->RegisterFrame(_spriteManager->_blueBreak0008);
    _break->RegisterFrame(_spriteManager->_blueBreak0009);
    _break->RegisterFrame(_spriteManager->_blueBreak0010);
    _break->RegisterFrame(_spriteManager->_blueBreak0011);
    _break->SetRepeat(false);
    _break->Play();
    _break->_animation_delay = 1;
    _break->_x = 40;
    _break->_y = 100;
    GraphicEngine::_stage->AddChild(_break);
    
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
