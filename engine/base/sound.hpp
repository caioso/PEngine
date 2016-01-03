#ifndef __SOUND__
#define __SOUND__

class AudioEngine;

class Sound
{
    friend class AudioEngine;
    
    private: int _repetitions;
    private: int _current_iteration;
    private: int _length;
    private: unsigned char const* _samples;
    private: int _current_voice;
    private: int _sample_rate;
    private: int _sound_index;
    
    // Standard Constructor. Simply initializes internal attributes.
    public: Sound () : _repetitions(0), _current_iteration(0), _length(0), _current_voice(-1), _sample_rate(0), _sound_index(-1) {};
    
    // Samples/Length pair defining contructor.
    // @param samples: pointer to sound samples array.
    // @param length: number of samples in the sound effect.
    public: Sound (unsigned char const* samples, int length) :
            _repetitions(0), _current_iteration(0), _length(length), _samples(samples), _current_voice(-1), _sample_rate(0), _sound_index(-1) {};
    
    // Full definition constructor. Repetition object informs the number
    // of times the sound will be played. Negative values of repetition
    // will imply endless repetitions.
    // @param samples: pointer to sound samples array.
    // @param length: number of samples in the sound effect.
    // @param repetitions: number of times the sound effect will be played.
    public: Sound (unsigned char const* samples, int length, int repetitions) :
            _current_iteration(0), _length(length), _samples(samples), _current_voice(-1), _sample_rate(0), _sound_index(-1)
            { _repetitions = repetitions < 0 ? -1 : repetitions;};
    
    // Full definition constructor. Repetition object informs the number
    // of times the sound will be played. Negative values of repetition
    // will imply endless repetitions.
    // @param samples: pointer to sound samples array.
    // @param length: number of samples in the sound effect.
    // @param repetitions: number of times the sound effect will be played.
    // @param sample_rate: number of samples per second.
    public: Sound (unsigned char const* samples, int length, int repetitions, int sample_rate) :
    _current_iteration(0), _length(length), _samples(samples), _current_voice(-1), _sample_rate(sample_rate), _sound_index(-1)
    { _repetitions = repetitions < 0 ? -1 : repetitions;};
    
    // Returns current Iteration (number of times the sound effect has be played.
    public: int GetCurrentIteration () { return _current_iteration; }
    
    // Returns Total Repetitions.
    public: int GetRepetitions () { return _repetitions; };
    
    // Set Repetition value.
    // @param repetitions: number of times the sound effect will be played.
    public: void SetRepetitions (int repetitions) { _repetitions = repetitions; }
    
    // Returns Sample Rate
    public: int GetSampleRate () { return _sample_rate; };
    
    // Set Sample Rate
    // @param sample_rate: number of samples per second.
    public: void SetSampleRate (int sample_rate) { _sample_rate = sample_rate; }
};

#endif // __SOUND__