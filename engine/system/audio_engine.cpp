#include "audio_engine.hpp"

std::vector<Sound *> AudioEngine::_sfx_list;
Music * AudioEngine::_current_music;
Music * AudioEngine::_temp_music;
int AudioEngine::_sfx_volume;
int AudioEngine::_music_volume;
char AudioEngine::_song_transition;

void AudioEngine::Init(int sfx_volume, int music_volume)
{
    _temp_music = NULL;
    _sfx_volume = sfx_volume;
    _music_volume = music_volume;
    _song_transition = 0;
    ASND_Init();
    MP3Player_Init();
}

void AudioEngine::PlaySFX (Sound * sound)
{
    if (sound->_current_voice != -1)
        return;
    if (sound->_current_iteration == sound->_repetitions)
        sound->_current_iteration = 0;
    if (sound->_repetitions == -1)
        sound->_repetitions = INT32_MAX;
    _sfx_list.push_back(sound);
    return;
}

void AudioEngine::StopSFX (Sound * sound)
{
    ASND_StopVoice(sound->_current_voice);
    sound->_current_iteration = sound->_repetitions;
    return;
}

void AudioEngine::StreamAudio ()
{
    if (_song_transition == 1)
        if (VolumeFadeOut()) {
            _current_music = NULL;
            MP3Player_Stop();
            _song_transition = 0;
        }
    
    if (_song_transition == 2)
        if (VolumeFadeIn())
        {
            _song_transition = 0;
        }
    
    if (_song_transition == 3)
        if (VolumeFadeOut()) {
            MP3Player_Stop();
            PlayMusic(_temp_music);
            _temp_music = NULL;
        }
    
    if (_current_music != NULL && !MP3Player_IsPlaying())
    {
        if (_current_music->_current_iteration != _current_music->_repetitions)
        {
            _current_music->_current_iteration++;
            AudioEngine::PlayMusic(_current_music);
        }
    }
    
    for (size_t i = 0; i < _sfx_list.size(); i++)
    {
        // Check if sound has finished playing.
        if (ASND_StatusVoice(_sfx_list[i]->_current_voice) == SND_UNUSED && _sfx_list[i]->_current_voice != -1)
        {
            _sfx_list[i]->_current_voice = -1;
            if (_sfx_list[i]->_current_iteration == _sfx_list[i]->_repetitions)
            {
                _sfx_list[i]->_current_iteration = 0;
                _sfx_list.erase(_sfx_list.begin() + (i--));
            }
        }
        // Play a sound if it is available to be played.
        if (_sfx_list[i]->_current_voice == -1 && _sfx_list[i]->_current_iteration != _sfx_list[i]->_repetitions)
        {
            _sfx_list[i]->_current_voice = ASND_GetFirstUnusedVoice();
            if (_sfx_list[i]->_current_voice < 1)
                _sfx_list[i]->_current_voice = -1;
            else
            {
                _sfx_list[i]->_current_iteration++;
                ASND_SetVoice(_sfx_list[i]->_current_voice,
                              VOICE_STEREO_16BIT,
                              _sfx_list[i]->_sample_rate,
                              0,
                              (u8 *)_sfx_list[i]->_samples,
                              _sfx_list[i]->_length,
                              _sfx_volume,
                              _sfx_volume, NULL);
            }
        }
    }
}

void AudioEngine::PlayMusic (Music * music, bool transition, int volume)
{
    if (music == _current_music)
    {
        //Debug::LogWarning("This music file is already being played.");
        return;
    }
    
    if (transition)
    {
        if (_current_music != NULL && _temp_music == NULL)
        {
            _song_transition = 3;
            _temp_music = music;
            return;
        }
        else
        {
            _song_transition = 2;
            _music_volume = 0;
        }
    }
    else
    {
        _music_volume = volume;
        MP3Player_Volume(_music_volume);
    }
    
    _current_music = music;
    _current_music->_current_iteration = 0;
    if (_current_music->_repetitions == -1)
        _current_music->_repetitions = INT32_MAX;
    MP3Player_PlayBuffer(_current_music->_samples, _current_music->_length, NULL);
    return;
}

void AudioEngine::StopMusic (Music * music, bool transition)
{
    if (_current_music == NULL)
    {
        Debug::LogWarning("No song is being played.");
        return;
    }

    _song_transition = 1;
    if (!transition)
        _music_volume = 0;
    return;
}

bool AudioEngine::VolumeFadeOut ()
{
    _music_volume += (-_music_volume)/20.0f;
    MP3Player_Volume(_music_volume);
    if (floor(_music_volume) == 0)
        return true;
    else
        return false;
}

void AudioEngine::SetMusicVolume (int volume)
{
    _music_volume = volume;
}

bool AudioEngine::VolumeFadeIn ()
{
    _music_volume += (280 -_music_volume)/20.0f;
    MP3Player_Volume(_music_volume);
    if (ceil(_music_volume) >= 255)
        return true;
    else
        return false;
}