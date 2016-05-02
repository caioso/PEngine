#include "debug.hpp"

float Debug::_x_position;
float Debug::_y_position;
string Debug::_framerate;
vector<LogData> Debug::_console_buffer;
GRRLIB_texImg * Debug::_console_font;
bool Debug::_edit_position;

void Debug::Init (int p_x, int p_y)
{
    _x_position = p_x;
    _y_position = p_y;
    _edit_position = false;
    _console_font = GRRLIB_LoadTexture(BMfont5);
    GRRLIB_InitTileSet(_console_font, 8, 16, 0);
}

void Debug::WriteLog (string p_log_data, u32 p_color)
{
    SDL_mutex * __lock = SDL_CreateMutex();
    SDL_mutexP(__lock);
    // Thread safe area
        LogData log_message;
        log_message._message = p_log_data;
        log_message._color = p_color;
        if (_console_buffer.size() < PPL_MAX_CONSOLE_LINES)
            _console_buffer.push_back(log_message);
        else
        {
            _console_buffer.erase(_console_buffer.begin());
            _console_buffer.push_back(log_message);
        }
    // Thread safe area
    SDL_mutexP(__lock);
    SDL_mutexV(__lock);
    SDL_DestroyMutex(__lock);
    __lock = 0;
}

void Debug::Log (string p_log_data)
{
    Debug::WriteLog(p_log_data, PPL_COLOR_WHITE);
}

void Debug::LogError (string p_log_data)
{
    Debug::WriteLog(p_log_data, PPL_COLOR_RED);
}

void Debug::LogWarning (string p_log_data)
{
    Debug::WriteLog(p_log_data, PPL_COLOR_YELLOW);
}

void Debug::LogSuccess (string p_log_data)
{
    Debug::WriteLog(p_log_data, PPL_COLOR_GREEN);
}

void Debug::LogNote (string p_log_data)
{
    Debug::WriteLog(p_log_data, PPL_COLOR_BLUE);
}

void Debug::MoveHorizontally (int p_amount)
{
    if (_edit_position)
        _x_position += p_amount;
}

void Debug::MoveVertically (int p_amount)
{
    if (_edit_position)
        _y_position += p_amount;
}

void Debug::ToggleEdit ()
{
    _edit_position = !_edit_position;
    if (_edit_position)
        Debug::LogNote ("Console in Edit Mode");
    else
        Debug::LogNote ("Console in View Mode");
};

void Debug::RegisterFramerate (int p_framerate)
{
    stringstream ss;
    ss<<"FPS: "<<p_framerate;
    _framerate = ss.str();
}

void Debug::Render ()
{
    for (size_t i = 0; i < _console_buffer.size(); i++)
    {
        GRRLIB_Printf(_x_position, _y_position + (i * 15),
                      _console_font,  _console_buffer[i]._color, 1,
                      _console_buffer[i]._message.c_str());
    }
    
    GRRLIB_Printf(0,10,_console_font,PPL_COLOR_WHITE, 1, _framerate.c_str());
}