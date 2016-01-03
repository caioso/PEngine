#ifndef __RUNNABLE__
#define __RUNNABLE__

class ScriptManager;

// Game Script Virtual Interface
class Runnable
{
    friend class ScriptManager;
    
    // Unique script identifier
    private: int _script_id;
    
    // Standard Constructor
    public: Runnable () : _script_id(-1) {};
    
    // Initialization Method. Called only once, when the
    // script is register in the game system.
    public: virtual void Start () = 0;
    
    // Update Method. Run only once per frame.
    // Can't be skipped unless unregister method is
    // explicitly called.
    public: virtual void Update () = 0;
    
    // Finaliztion Method. Called once, when the script
    // is unscribed.
    public: virtual void End () = 0;
};

#endif // __RUNNABLE__