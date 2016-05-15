#ifndef __ANIMATED_SPRITE__
#define __ANIMATED_SPRITE__

#include <grrlib.h>
#include <vector>

#include "sprite.hpp"
#include "../system/debug.hpp"

class AnimatedSprite : public Sprite
{
    friend class GraphicEngine;
    
    public: unsigned int _total_frames;
    public: vector<GRRLIB_texImg*> _frames;
    private: unsigned int _current_frame;
    private: bool _is_playing;
    private: bool _repeat;
    public: int _animation_delay;
    private: int _current_delay;
    
    // Standard Constructor.
    // @param total_frames: maximumm number of frames in the animation.
    public: AnimatedSprite (unsigned total_frames) : Sprite(NULL, 0, 0, 0, 0), _total_frames(total_frames), _current_frame(0), _is_playing(false), _repeat(true) { _current_delay = 0; _animation_delay = 0;}
    
    // Position defining Constructor.
    // @param total_frames: maximumm number of frames in the animation.
    // @param width: asset width.
    // @param height: asset height.
    public: AnimatedSprite (unsigned total_frames, float width, float height) : Sprite(NULL, 0, 0, width, height), _total_frames(total_frames), _current_frame(0), _is_playing(false), _repeat(true) { _current_delay = 0; _animation_delay = 0; }
    
    // Position defining Constructor.
    // @param total_frames: maximumm number of frames in the animation.
    // @param width: asset width.
    // @param height: asset height.
    // @param x: asset x coordinate.
    // @param y: asset y coordinate.
    public: AnimatedSprite (unsigned total_frames, float width, float height, float x, float y) : Sprite(NULL, x, y, width, height),  _total_frames(total_frames), _current_frame(0), _is_playing(false), _repeat(true) { _current_delay = 0; _animation_delay = 0; }
    
    // Register frame in the animation list.
    // @param _frame: Frame texture reference.
    // @return inform if the operation was successful.
    public: bool RegisterFrame (GRRLIB_texImg * _frame);
    
    // Starts animation or resume if previously paused.
    public: void Play () { _is_playing = true; }
    
    // Pause animation.
    public: void Pause () { _is_playing = false; }
    
    // Stop animation and restart current frame.
    public: void Stop () { _is_playing = false; _current_frame = 0; }
    
    // Renders a target frame and stops animation.
    // @param target_frame: Frame number to be rendered (0-based).
    public: void GotoAndStop (unsigned int target_frame);
    
    // Renders a target frame and play animation.
    // @param target_frame: Frame number to be rendered (0-based).
    public: void GotoAndPlay (unsigned int target_frame);
    
    // Renders a target frame.
    // @param target_frame: Frame number to be rendered (0-based).
    private: void GotoFrame (unsigned int target_frame);
    
    // Go to next frame.
    private: void NextFrame ();
    
    // Set repeat switch.
    // @param repeat: repeat value.
    public: void SetRepeat (bool repeat) { _repeat = true; }
    
    public: ~AnimatedSprite() {};
};

#endif // __ANIMATED_SPRITE__