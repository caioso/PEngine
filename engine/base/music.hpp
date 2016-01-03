#ifndef __MUSIC__
#define __MUSIC__

class Music : public Sound
{
    // Standard Constructor. Simply initializes internal attributes.
    public: Music () : Sound () {};
    
    // Samples/Length pair defining contructor.
    // @param samples: pointer to music samples array.
    // @param length: number of samples in the music.
    public: Music (unsigned char const* samples, int length) : Sound(samples, length) {};
    
    // Full definition constructor. Repetition object informs the number
    // of times the music will be played. Negative values of repetition
    // will imply endless repetitions.
    // @param samples: pointer to sound samples array.
    // @param length: number of samples in the music.
    // @param repetitions: number of times the music will be played.
    public: Music (unsigned char const* samples, int length, int repetitions) : Sound(samples, length, repetitions) {};
};

#endif // __MUSIC__