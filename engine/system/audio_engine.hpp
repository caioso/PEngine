#ifndef __AUDIO_ENGINE__
#define __AUDIO_ENGINE__

// Standard Includes
#include <vector>
#include <asndlib.h>
#include <mp3player.h>
#include <math.h>

// System Includes
#include "debug.hpp"
#include "../base/sound.hpp"
#include "../base/music.hpp"

// Note about sound effects: There exist 15 different voices to be used at the same time
// COnsider that the voice number 0 is reserved for MP3 and the remaining voices
// are sound effects. in this case if there arent available voices upon a Play request,
// the Engine object will schedule the sound file to be played as soon as
// other voices are available.
class AudioEngine
{
    private: static std::vector <Sound *> _sfx_list;
    private: static Music * _current_music;
    private: static Music * _temp_music;
    private: static int _sfx_volume;
    private: static int _music_volume;
    private: static char _song_transition;
    
    // Initialize Sound Engine, ASNDLib and MP3PlayerLib.
    public: static void Init (int sfx_volume, int music_volume);
    
    // Play a sound effect file for the amount of times the object has registered internally.
    // @param sound: sound object with samples and length previously set.
    public: static void PlaySFX (Sound * sound);
    
    // Stop a sound file effect.
    // @param sound: sound object.
    public: static void StopSFX (Sound * sound);
    
    // Play MP3 Full music track. By default, if another music is requeted to be played,
    // the songs are transitioned with a fade-out/fade-in effect.
    // @param music: Music/Sound object.
    // @param transition: enables/disables transition when playing differend songs.
    // @param volume: Intended music volume.
    public: static void PlayMusic (Music * music, bool transition = true, int volume = 255);
    
    // Stop MP3 Full music track. By default, the songs is transitioned with a fade-out effect.
    // @param music: Music/Sound object.
    // @param transition: enables/disables transition when playing differend songs.
    public: static void StopMusic (Music * music, bool transition = true);
    
    // Fades volume out with easing transition.
    private: static bool VolumeFadeOut ();
    
    // Set global music volume to desired value.
    // @param volume: intended music volume (range 0-255).
    public: static void SetMusicVolume (int volume);
    
    // Fades volume in with easing transition.
    private: static bool VolumeFadeIn ();
    
    // Schedule sound requests to be played, once at each frame.
    public: static void StreamAudio ();
};

#endif // __AUDIO_ENGINE__