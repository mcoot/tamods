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
static std::map<UFunction *, Hook> _pre_hooks;
static std::map<UFunction *, Hook> _post_hooks;
static bool _print_hookable = true;
ProcessEventFunction pProcessEvent = NULL;

VOID __stdcall NakedFunction(UFunction*, PVOID, PVOID) { }

bool DispatchF(UObject *pCallObject, UFunction *pFunction, void *pParams, void *pResult, Hooks::Order order)
{
	auto &hook_map = (order == Hooks::PRE ? _pre_hooks : _post_hooks);
	static std::vector<std::string> dispatched_funcs;

	if (pFunction && pCallObject) {
		static char FunctionName[128];
		static char CallingName[128];

		strcpy(FunctionName, pFunction->GetFullName());
		strcpy(CallingName, pCallObject->GetFullName());

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

		auto it = hook_map.find(pFunction);
		if (it == hook_map.end())
			return false;
		if (it->second.calling_class && !pCallObject->IsA(it->second.calling_class))
			return false;
		// Don't call original if true is returned
		return it->second.hook_func(it->second.id, pCallObject, pFunction, pParams, pResult);
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
		if (DispatchF(pCallObject, pFunction, pParms, pResult, Hooks::PRE)) {
			__asm mov ecx, pCallObject;
			__asm popad;
			NakedFunction(pFunction, pParms, pResult);
		}
		else {
			__asm mov ecx, pCallObject;
			__asm popad;
			pProcessEvent(pFunction, pParms, pResult);
			DispatchF(pCallObject, pFunction, pParms, pResult, Hooks::POST);
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
	auto &hook_map = (hook.order == PRE ? _pre_hooks : _post_hooks);
	if (hook_map.find(hook.original_func) != hook_map.end())
		Logger::log("WARNING: overriding hook for function: '%s'", original_name);
	hook_map[hook.original_func] = hook;
	return (hook.id);
}

bool Hooks::remove(char *original_name, Order order)
{
	auto &hook_map = (order == PRE ? _pre_hooks : _post_hooks);
	UFunction *ufunc = (UFunction *)UObject::FindObject<UFunction>(original_name);

	if (!ufunc)
		return (false);
	return (!!hook_map.erase(ufunc));
}

bool Hooks::remove(int id)
{
	for (auto it : _pre_hooks)
	{
		if (it.second.id == id)
		{
			_pre_hooks.erase(it.first);
			return true;
		}
	}
	for (auto it : _post_hooks)
	{
		if (it.second.id == id)
		{
			_post_hooks.erase(it.first);
			return true;
		}
	}
	return false;
}
