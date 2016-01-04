#pragma once

#include <functional>
#include <vector>
#include <map>

#include "SdkHeaders.h"
#include "detours.h"
#include "Logger.h"
#include "Profiler.h"

typedef void(__stdcall * ProcessEventFunction)(UFunction*, void *, void *);
typedef bool(*HookFunction)(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult);

namespace Hooks
{
	enum Order
	{
		PRE, POST
	};

	struct FFrame
	{
		char			unknown_data[16];
		UStruct			*Node;
		UObject			*Object;
		unsigned char	*Code;
		unsigned char	*Locals;
		int				LineNum;
		FFrame			*PreviousFrame;

		void			Step(UObject *Context, void *result);
	};

	
	void init(bool print_hookable = true);
	void cleanup();
	int add(HookFunction hook_function, char *original_name, Order hook_order = PRE, UClass *thisclassonly = NULL);
	bool remove(char *original_name, Order order = PRE);
	bool remove(int id);
	void lock();
	void unlock();
};

extern UObject *pCallObject;
template<void(*hook)(UObject *, void *, void *), const char *original_name>
void __stdcall UScriptBaseHook(Hooks::FFrame *stack, void *result)
{
	__asm pushad;
	__asm mov pCallObject, ecx;

	static UFunction *pFunction = NULL;
	static std::vector<UProperty *> vProperty;
	static int paramsSize = 0;
	static char params[512];
	
	if (!pFunction)
	{
		pFunction = (UFunction *)UObject::FindObject<UFunction>(original_name);

		// Retrieve parameters
		for (UProperty* pProperty = (UProperty*)pFunction->Children; pProperty; pProperty = (UProperty*)pProperty->Next)
		{
			if (pProperty->ElementSize > 0 && pProperty->PropertyFlags.A & 0x0000000000000080 /* CPF_Parm */)
			{
				vProperty.push_back(pProperty);
				Logger::log("Property: %s @ %d\tElementSize(%d), PropertySize(%d), ArrayDim(%d)", pProperty->GetName(), pProperty->Offset, pProperty->ElementSize, pProperty->PropertySize, pProperty->ArrayDim);
				paramsSize += pProperty->ElementSize * pProperty->ArrayDim;
			}
		}

		// Sort parameters
		std::sort(vProperty.begin(), vProperty.end(), [](UProperty *pPropertyA, UProperty *pPropertyB) -> bool {
			if (pPropertyA->Offset == pPropertyB->Offset && pPropertyA->IsA(UBoolProperty::StaticClass()) && pPropertyB->IsA(UBoolProperty::StaticClass()))
				return (((UBoolProperty*)pPropertyA)->BitMask < ((UBoolProperty*)pPropertyB)->BitMask);
			else
				return (pPropertyA->Offset < pPropertyB->Offset);
		});

		Logger::log("Custom size found: %d", paramsSize);
		//params = (char *)malloc(paramsSize);
	}

	for (int i = 0; *stack->Code != 22 /* EX_EndFunctionParms */; i++)
	{
		Logger::log("Offset: %d", vProperty[i]->Offset);
		stack->Step(stack->Object, params + vProperty[i]->Offset);
	}
	stack->Code++;
	if (*stack->Code == 0x41 /* EX_DebugInfo */)
		stack->Step(stack->Object, NULL);

	hook(pCallObject, params, result);
}

template<void(*hook)(UObject *, void *, void *), const char *original_name>
int addUScriptHook()
{
	UFunction *original_func = (UFunction *)UObject::FindObject<UFunction>(original_name);

	if (!original_func)
		return 0;
	original_func->iNative = 0x789;
	original_func->Func = &UScriptBaseHook<hook, original_name>;
	return 1;
}

typedef void(UObject::*UObjectNative)(Hooks::FFrame &, void *);
