#include "controller.hpp"
#include "../system/debug.hpp"

Controller::Controller(int player_number) : _player(player_number), _keys_down(0)
{
    switch (player_number)
    {
        case PPL_PLAYER_1: WPAD_SetDataFormat(WPAD_CHAN_0, WPAD_FMT_BTNS_ACC_IR);
                           _channel = WPAD_CHAN_0;
                           break;
        case PPL_PLAYER_2: WPAD_SetDataFormat(WPAD_CHAN_1, WPAD_FMT_BTNS_ACC_IR);
                           _channel = WPAD_CHAN_1;
                           break;
        case PPL_PLAYER_3: WPAD_SetDataFormat(WPAD_CHAN_2, WPAD_FMT_BTNS_ACC_IR);
                           _channel = WPAD_CHAN_2;
                           break;
        case PPL_PLAYER_4: WPAD_SetDataFormat(WPAD_CHAN_3, WPAD_FMT_BTNS_ACC_IR);
                           _channel = WPAD_CHAN_3;
                           break;
    }
}

void Controller::SetKeysDown (int keys)
{
    _keys_down = keys;
}

void Controller::SetKeysUp (int keys)
{
    _keys_up = keys;
}

void Controller::SetKeysHeld (int keys)
{
    _keys_held = keys;
}

bool Controller::CheckKeysOR (int key_event, int keys, ...)
{
    va_list __arguments;
    va_start(__arguments, keys);
    
    for (int i = 0; i < keys; i++)
    {
        if (key_event == PPL_KEY_DOWN && (_keys_down&(va_arg(__arguments,int))))
            return true;
        else if (key_event == PPL_KEY_UP && (_keys_up&(va_arg(__arguments,int))))
            return true;
         else if (key_event == PPL_KEY_HELD && (_keys_held&(va_arg(__arguments,int))))
            return true;
    }
    return false;
}

bool Controller::CheckKeysAND (int key_event, int keys, ...)
{
    va_list __arguments;
    va_start(__arguments, keys);
    
    for (int i = 0; i < keys; i++)
    {
        if (key_event == PPL_KEY_DOWN && !(_keys_down&(va_arg(__arguments,int))))
            return false;
        else if (key_event == PPL_KEY_UP && !(_keys_up&(va_arg(__arguments,int))))
            return false;
        else if (key_event == PPL_KEY_HELD && !(_keys_held&(va_arg(__arguments,int))))
            return false;
    }
    return true;
}