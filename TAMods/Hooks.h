#pragma once

#include <vector>
#include <map>

#include "SdkHeaders.h"
#include "detours.h"
#include "Logger.h"
#include "Profiler.h"

typedef VOID(__stdcall * ProcessEventFunction)(UFunction*, PVOID, PVOID);
typedef bool(*HookFunction)(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);

namespace Hooks
{
	enum Order
	{
		PRE, POST
	};
	
	void init(bool print_hookable = true);
	void cleanup();
	int add(HookFunction hook_function, char *original_name, Order hook_order = PRE, UClass *thisclassonly = NULL);
	bool remove(char *original_name, Order order = PRE);
	bool remove(int id);
	void lock();
	void unlock();
};
