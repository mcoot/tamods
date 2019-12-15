#include "Hooks.h"

struct Hook
{
    Hook(HookFunction hook, char *original_name, Hooks::Order hook_order = Hooks::PRE, UClass *thisclassonly = NULL)
        : id(0), hook_func(hook), order(hook_order), calling_class(thisclassonly)
    {
        original_func = (UFunction *)UObject::FindObject<UFunction>(original_name);
        if (original_func)
            id = ++_total_hooks;
    }

    Hook()
        : id(0)
    { }

    int id;
    UFunction *original_func;
    HookFunction hook_func;
    Hooks::Order order;
    UClass *calling_class;

public:
    static int _total_hooks;
};

// Table of native functions
UObjectNative *GNatives = (UObjectNative *)0x01328C40;

int Hook::_total_hooks = 0;
static std::map<UFunction *, std::pair<Hook, Hook>> _hooks;
static bool _print_hookable = true;
static bool _lock = false;
std::map<int, Hooks::CustomParameters> _customHookParameters;
static ProcessEventFunction pProcessEvent = NULL;

void Hooks::FFrame::Step(UObject *Context, void *result)
{
    int b = *Code++;
    (Context->*GNatives[b])(*this, result);
}

bool DispatchF(UObject *pCallObject, UFunction *pFunction, void *pParams, void *pResult, Hook &hook)
{
    if (pFunction && pCallObject) {
        if (!hook.id)
            return false;
        if (hook.calling_class && !pCallObject->IsA(hook.calling_class))
            return false;
        // Don't call original if true is returned
        if (Profiler::isActive())
            Profiler::enterFunction(pFunction->GetFullName());
        bool ret = hook.hook_func(hook.id, pCallObject, pFunction, pParams, pResult);
        if (Profiler::isActive())
            Profiler::leaveFunction();
        return ret;
    }
    return false;
}

void __fastcall ProxyFunction(UObject *that, void *, UFunction *pFunction, void *pParms, void *pResult)
{
    if (pFunction && !_lock)
    {
        static std::vector<std::string> dispatched_funcs;

        // Print hookable functions, only once per object/function
        if (_print_hookable && !Logger::isQuiet())
        {
            char FunctionName[128];
            char CallingName[128];
            
            strcpy(FunctionName, pFunction->GetFullName());
            strcpy(CallingName, that->GetFullName());
            std::string str = std::string(CallingName) + "::" + std::string(FunctionName);
            if (std::find(dispatched_funcs.begin(), dispatched_funcs.end(), str) == dispatched_funcs.end())
            {
                dispatched_funcs.push_back(str);
                Logger::log("%s :: %s()", CallingName, FunctionName);
            }
        }

        auto it = _hooks.find(pFunction);
        bool call_original = true;
        if (it != _hooks.end())
            call_original = !DispatchF(that, pFunction, pParms, pResult, it->second.first);
        if (call_original)
        {
            pProcessEvent(that, pFunction, pParms, pResult);
            if (it != _hooks.end())
                DispatchF(that, pFunction, pParms, pResult, it->second.second);
        }
    }
    else {
        pProcessEvent(that, pFunction, pParms, pResult);
    }
}

void Hooks::init(bool print_hookable) {
    // If the hookable functions should be logged as they are received
    _print_hookable = print_hookable;

    // Locate the ProcessEvent function
    UObject *Object = UObject::GObjObjects()->Data[1];
    unsigned long *cObject = (unsigned long *)Object;
    unsigned long *ProcessEventsAddress = (unsigned long *)(*(cObject)+65 * sizeof(unsigned long));

    // Detour the function
    pProcessEvent = (ProcessEventFunction) DetourFunction((PBYTE) *ProcessEventsAddress, (PBYTE)&ProxyFunction);
}

void Hooks::cleanup()
{
    DetourRemove((PBYTE)pProcessEvent, (PBYTE)&ProxyFunction);
}

// Returns the id of the created hook, 0 on failure
int Hooks::add(HookFunction hook_function, char *original_name, Order hook_order, UClass *thisclassonly)
{
    Hook hook(hook_function, original_name, hook_order, thisclassonly);

    if (!hook.id)
    {
        Logger::log("WARNING: unable hook function: '%s'. Check if you didn't make a typo", original_name);
        return (false);
    }
    auto &it = _hooks[hook.original_func];
    if (hook_order == PRE)
        it.first = hook;
    else
        it.second = hook;
    return (hook.id);
}

bool Hooks::remove(char *original_name, Order order)
{
    UFunction *ufunc = (UFunction *)UObject::FindObject<UFunction>(original_name);

    if (!ufunc)
        return (false);
    auto &it = _hooks.find(ufunc);
    if (it == _hooks.end())
        return false;
    Hook &hook = order == PRE ? it->second.first : it->second.second;
    hook.id = 0;
    if (!it->second.first.id && !it->second.second.id)
        return !!_hooks.erase(ufunc);
    return true;
}

bool Hooks::remove(int id)
{
    for (auto &it : _hooks)
    {
        if (it.second.first.id == id)
            it.second.first.id = 0;
        else if (it.second.second.id == id)
            it.second.second.id = 0;
        if (!it.second.first.id && !it.second.second.id)
            _hooks.erase(it.first);
        return true;
    }
    return false;
}

// "locks" the hook system, use this to speed up portions of code where you call native functions and don't need to hook them
// Don't forget to unlock the system when you're done
void Hooks::lock()
{
    _lock = true;
}

void Hooks::unlock()
{
    _lock = false;
}
