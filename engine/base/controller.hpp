#ifndef __CONTROLLER__
#define __CONTROLLER__

#include "../common/constants.h"
#include <wiiuse/wpad.h>
#include <stdarg.h>

class Controller
{
    private: int _player;
    private: int _channel;
    private: int _keys_down;
    private: int _keys_up;
    private: int _keys_held;
    
    // Generic Constructor.
    // @param player_number: Player unique ID (0 to 4)
    public: Controller (int player_number);
    
    // Update internal _keys_down buffer.
    // @param keys: Input Key Map
    public: void SetKeysDown (int keys);
    
    // Update internal _keys_up buffer.
    // @param keys: Input Key Map
    public: void SetKeysUp (int keys);
    
    // Update internal _keys_held buffer.
    // @param keys: Input Key Map
    public: void SetKeysHeld (int keys);
    
    // Return controller channel number
    public: int GetChannel () { return _channel; }
    
     // Return controller player ID
    public: int GetPlayerNumber () { return _player; }
    
    // Return Key Down Map
    public: int GetKeysDown () { return _keys_down; }
    
    // Return Key Up Map
    public: int GetKeysUp () { return _keys_up; }
    
    // Return Key Help Map
    public: int GetKeysHeld () { return _keys_held; }
    
    // Return true if one of the listed keys are present in the key map
    // for the requeted event.
    public: bool CheckKeysOR (int key_event, int keys, ...);
    
    // Return true if all the listed keys are present in the key map
    // for the requeted event.
    public: bool CheckKeysAND (int key_event, int keys, ...);
};

#endif // __CONTROLLER__