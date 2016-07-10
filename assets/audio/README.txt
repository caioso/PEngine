how to convert MP3 to bin:
ffmpeg -i <sound_name>.mp3 -f s16be -acodec pcm_s16be <sound_name>.pcm

/opt/devkitpro/devkitPPC/bin/raw2c <sound_name>.pcm

REMEMBER
the bitrate should match in the code and the sound will be stereo with 16 bit depth

Music files don`t need to be converted.