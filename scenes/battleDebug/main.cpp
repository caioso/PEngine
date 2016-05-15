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
    
    // Register Boards
    ScriptManager::Subscribe(__board_p1);
    ScriptManager::Subscribe(__board_p2);
    
    // Register Clock
    ScriptManager::Subscribe(__system_clock);
    
    // Test Animated Sprite
    AnimatedSprite * _aSprite = new AnimatedSprite(5, PANEL_IMAGE_SIZE, PANEL_IMAGE_SIZE);
    _aSprite->_x = 34;
    _aSprite->_y = 50;
    _aSprite->RegisterFrame(_spriteManager->_dred);
    _aSprite->RegisterFrame(_spriteManager->_dblue);
    _aSprite->RegisterFrame(_spriteManager->_dgreen);
    _aSprite->RegisterFrame(_spriteManager->_dyellow);
    _aSprite->RegisterFrame(_spriteManager->_dpurple);
    _aSprite->_animation_delay = 10;
    _aSprite->Play();
    GraphicEngine::_stage->AddChild(dynamic_cast<Sprite*>(_aSprite));


    // Do not change this line.
    Engine::Loop();

    // Do not change this line.
    Engine::Finalize();
}
