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

private:
	static int _total_hooks;
};

int Hook::_total_hooks = 0;
static std::map<UFunction *, std::pair<Hook, Hook>> _hooks;
static bool _print_hookable = true;
ProcessEventFunction pProcessEvent = NULL;

VOID __stdcall NakedFunction(UFunction*, PVOID, PVOID) { }

bool DispatchF(UObject *pCallObject, UFunction *pFunction, void *pParams, void *pResult, Hook &hook, Hooks::Order order)
{
	static std::vector<std::string> dispatched_funcs;

	if (pFunction && pCallObject) {
		char *FunctionName = pFunction->GetFullName();
		char *CallingName = pCallObject->GetFullName();

		// Print hookable functions, only once per object/function
		if (_print_hookable && order == Hooks::PRE)
		{
			std::string str = std::string(CallingName) + "::" + std::string(FunctionName);
			if (std::find(dispatched_funcs.begin(), dispatched_funcs.end(), str) == dispatched_funcs.end())
			{
				dispatched_funcs.push_back(str);
				Logger::log("%s :: %s()", CallingName, FunctionName);
			}
		}

		if (!hook.id)
			return false;
		if (hook.calling_class && !pCallObject->IsA(hook.calling_class))
			return false;
		// Don't call original if true is returned
		return hook.hook_func(hook.id, pCallObject, pFunction, pParams, pResult);
	}
	return false;
}

UObject *pCallObject;
void __stdcall ProxyFunction(UFunction *pFunction, void *pParms, void *pResult)
{
	__asm pushad;
	__asm mov pCallObject, ecx;

	if (pFunction)
	{
		auto it = _hooks.find(pFunction);
		bool call_original = true;
		if (it != _hooks.end())
			call_original = !DispatchF(pCallObject, pFunction, pParms, pResult, it->second.first, Hooks::PRE);
		if (!call_original)
		{
			__asm mov ecx, pCallObject;
			__asm popad;
			NakedFunction(pFunction, pParms, pResult);
		}
		else
		{
			__asm mov ecx, pCallObject;
			__asm popad;
			pProcessEvent(pFunction, pParms, pResult);
			if (it != _hooks.end())
				DispatchF(pCallObject, pFunction, pParms, pResult, it->second.second, Hooks::POST);
		}
	}
	else {
		__asm mov ecx, pCallObject;
		__asm popad;
		pProcessEvent(pFunction, pParms, pResult);
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
	pProcessEvent = (ProcessEventFunction) DetourFunction((PBYTE) *ProcessEventsAddress, (PBYTE)&ProxyFunction); //0x00458B30
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
