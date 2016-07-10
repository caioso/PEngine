#pragma once
#ifndef __CLOCK__
#define __CLOCK__

// Engine includes
#include "../../engine/engine.hpp"

// System Includes
#include <sstream>
#include <ogc/lwp_watchdog.h>

// Other Includes
#include "sprite_manager.hpp"

#define NUMBER_1_SPACE 7

class Clock : public Runnable
{
    private: double _startTime;
    private: double _endTime;
    private: double _deltaTime;
    
    private: int _seconds;
    private: int _minutes;
    
    private: Sprite * _clockContainer;
    private: Sprite * _second1;
    private: Sprite * _second2;
    private: Sprite * _minute1;
    private: Sprite * _minute2;
    private: Sprite * _points;
    private: SpriteManager * _spriteManager;
    
    public: Clock (SpriteManager * spriteManager)
    {
        _spriteManager = spriteManager;
    }
    
    public: void Start ()
    {
        _startTime = ticks_to_millisecs(gettime());
        _seconds = 0;
        _minutes = 0;
        _deltaTime = 0;
        
        _clockContainer = new Sprite();
        
        _minute1 = new Sprite(_spriteManager->_n0, 0, 0, 36, 24);
        _minute2 = new Sprite(_spriteManager->_n0, 36, 0, 36, 24);
        
        _second1 = new Sprite(_spriteManager->_n0, 94, 0, 36, 24);
        _second2 = new Sprite(_spriteManager->_n0, 130, 0, 36, 24);
        
        _points = new Sprite(_spriteManager->_points, 78, 5, 36, 24);
        
        _clockContainer->AddChild(_minute1);
        _clockContainer->AddChild(_minute2);
        _clockContainer->AddChild(_second1);
        _clockContainer->AddChild(_second2);
        _clockContainer->AddChild(_points);
        _clockContainer->_x = 237;
        _clockContainer->_y = 205;
        
        GraphicEngine::_stage->AddChild(_clockContainer);
    }

    public: void Update ()
    {
        _endTime = ticks_to_millisecs(gettime());
        _deltaTime += _endTime - _startTime;
        if(_deltaTime >= 32000.0)
        {
            _startTime = ticks_to_millisecs(gettime());
            
            UpdateTime ();
            RenderClock ();
            
            _deltaTime = 0;
        }
    }
    
    private: void RenderClock ()
    {
        if (_seconds < 10)
        {
            _second1->SetAsset(_spriteManager->DecodeNumber(0), 36, 24);
            _second2->SetAsset(_spriteManager->DecodeNumber(_seconds), 36, 24);
            
            if (_seconds == 1)
                _second2->_x = 130 + NUMBER_1_SPACE;
            else
                _second2->_x = 130;
        }
        else
        {
            _second1->SetAsset(_spriteManager->DecodeNumber(_seconds/10), 36, 24);
            _second2->SetAsset(_spriteManager->DecodeNumber(_seconds%10), 36, 24);
            
            if (_seconds/10 == 1)
                _second1->_x = 94 + NUMBER_1_SPACE;
            else
                _second1->_x = 94;
            
            if (_seconds%10 == 1)
                _second2->_x = 130 + NUMBER_1_SPACE;
            else
                _second2->_x = 130;
        }
        
        if (_minutes < 10)
        {
            _minute1->SetAsset(_spriteManager->DecodeNumber(0), 36, 24);
            _minute2->SetAsset(_spriteManager->DecodeNumber(_minutes), 36, 24);
            
            if (_minutes == 1)
                _minute2->_x = 36 + NUMBER_1_SPACE;
            else
                _minute2->_x = 36;
        }
        else
        {
            _minute1->SetAsset(_spriteManager->DecodeNumber(_minutes/10), 36, 24);
            _minute2->SetAsset(_spriteManager->DecodeNumber(_minutes%10), 36, 24);
            
            if (_minutes/10 == 1)
                _minute1->_x = 0 + NUMBER_1_SPACE;
            else
                _minute1->_x = 0;
            
             if (_minutes == 1)
                 _minute2->_x = 36 + NUMBER_1_SPACE;
             else
                 _minute2->_x = 36;
        }
    }
    
    public: void End() {}
    
    private: void UpdateTime ()
    {
        _seconds++;
        if (_seconds == 60)
        {
            _seconds = 0;
            _minutes++;
            if (_minutes == 60)
                _minutes = 0;
        }
    }
};

#endif // __CLOCK__