#ifndef __SCRIPT_MANAGER__
#define __SCRIPT_MANAGER__

// System Includes
#include "../base/runnable.hpp"
#include "debug.hpp"
#include <vector>

using namespace std;

class ScriptManager
{
    friend class Runnable;
    // Script List
    public: static vector<Runnable*> _script_list;
    public: static unsigned int _thread_number;
    public: static unsigned int _script_number;

    // Initializes Script Manager Class.
    public: static void Init ();

    // Script Subscription. Sets a script to be run
    // both Start and Update methods.
    // @param script: Runnable (base class) script pointer.
    public: static void Subscribe (Runnable * script);

    // Script Wnscription. Removes a script from.
    // the subscription list.
    // @param script: Runnable reference.
    public: static void Unscribe (Runnable * script);

    // Update subscribed scripts once per iteration.
    public: static void UpdateScripts ();
};

#endif // __SCRIPT_MANAGER__
