#ifndef __DEBUG_CONSOLE__
#define __DEBUG_CONSOLE__

#include <grrlib.h>
#include "../common/fonts/BMfont5.h"
#include "../common/constants.h"
#include "../common/macros.h"

#include <stdlib.h>
#include <wiiuse/wpad.h>
#include <vector>
#include <string>

#include <sdl/SDL_thread.h>

using namespace std;

struct LogData
{
    string _message;
    u32 _color;
};

class Debug
{
    private: static float _x_position;
    private: static float _y_position;
    private: static vector<LogData> _console_buffer;
    private: static GRRLIB_texImg * _console_font;
    private: static bool _edit_position;
    
    public: static void Init (int p_x, int p_y);
    
    // Use Log to right the desired message in the console.
    // @param p_log_data: the message to be logged on screen.
    public: static void Log (string p_log_data);
    
    // Use Log to right the desired message in the console, with Red color.
    // @param p_log_data: the message to be logged on screen.
    public: static void LogError (string p_log_data);
    
    // Use Log to right the desired message in the console, with Yellow color.
    // @param p_log_data: the message to be logged on screen.
    public: static void LogWarning (string p_log_data);
    
    // Use Log to right the desired message in the console, with Green color.
    // @param p_log_data: the message to be logged on screen.
    public: static void LogSuccess (string p_log_data);
    
    // Use Log to right the desired message in the console, with Blue color.
    // @param p_log_data: the message to be logged on screen.
    public: static void LogNote (string p_log_data);
    
    // Translate the terminal window horizontally according to a certain amount of pixels.
    // @param p_amount: the number of pixels to move (left < 0, right > 0).
    public: static void MoveHorizontally (int p_amount);
    
    // Translate the terminal window vertically according to a certain amount of pixels.
    // @param p_amount: the number of pixels to move (up < 0, down > 0).
    public: static void MoveVertically (int p_amount);
    
    // Enable or disable edit mode.
    public: static void ToggleEdit ();
    
    // Effectively writes content in the terminal.
    // @param p_log_data: the message to be logged on screen.
    // @param p_color: color constant of the desired text.
    private: static void WriteLog (string p_log_data, u32 p_color);
    
    // Will render every entry in the console buffer. When the buffer is full
    // The first line will be replced with teh second and so forth, so that
    // there will be room for a new entry.
    public: static void Render ();
    
};

#endif // __DEBUG_CONSOLE__