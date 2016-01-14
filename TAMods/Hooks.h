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

	struct CustomParameters
	{
		void			*hookPtr;
		const char		*name;
		UFunction		*function;
		void			*defaultParams;
		void			*orig_Func;
		int				orig_iNative;

		CustomParameters(void *pHookPtr, const char *pName, UFunction *pFunction, void *pDefaultParams)
			: hookPtr(pHookPtr), name(pName), function(pFunction), defaultParams(pDefaultParams), orig_Func(pFunction->Func), orig_iNative(pFunction->iNative)
		{}
		CustomParameters()
			: hookPtr(NULL), name(NULL), function(NULL), defaultParams(NULL)
		{}
	};

	struct CallInfo
	{
		UObject *callerObject;
		UObject *calleeObject;
		UFunction *caller;
		UFunction *callee;

		CallInfo()
			: callerObject(NULL), calleeObject(NULL), caller(NULL), callee(NULL)
		{ }
	};
	
	void init(bool print_hookable = true);
	void cleanup();
	int add(HookFunction hook_function, char *original_name, Order hook_order = PRE, UClass *thisclassonly = NULL);
	bool remove(char *original_name, Order order = PRE);
	bool remove(int id);
	void lock();
	void unlock();
};

template<typename S>
class DefaultConstructor
{
public:
	DefaultConstructor()
		: _default((S *) calloc(sizeof(S), 1))
	{}

	template<typename T>
	DefaultConstructor	&add(T S::*member, const T &value)
	{
		_default->*member = value;
		return *this;
	}

	S					*get()
	{
		return _default;
	}

private:
	S		*_default;
};

extern std::map<int, Hooks::CustomParameters> _customHookParameters;
extern UObject *pCallObject;

namespace Hooks
{
	template<int ID>
	void __stdcall UScriptBaseHook(Hooks::FFrame *stack, void *result)
	{
		__asm pushad;
		__asm mov pCallObject, ecx;

		static const Hooks::CustomParameters &hookInfo = _customHookParameters[ID];
		static UFunction *pFunction = NULL;
		static std::vector<UProperty *> vProperty;
		static int paramsSize = 0;
		static int iNativeCustom = 0;
		static void *FuncCustom = NULL;
		static char *params;

		// Initialise everything only the first time the hook is called
		if (!pFunction)
		{
			pFunction = hookInfo.function;

			// Store custom values
			FuncCustom = pFunction->Func;
			iNativeCustom = pFunction->iNative;

			// Retrieve parameters
			for (UProperty* pProperty = (UProperty*)pFunction->Children; pProperty; pProperty = (UProperty*)pProperty->Next)
			{
				if (pProperty->ElementSize > 0 && pProperty->PropertyFlags.A & 0x00000080 /* CPF_Parm */)
				{
					vProperty.push_back(pProperty);
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

			params = (char *)calloc(paramsSize, 1);
		}

		Hooks::CallInfo callInfo;
		callInfo.callerObject = stack->Object;
		callInfo.calleeObject = pCallObject;
		if (stack->Node && stack->Node->IsA(UFunction::StaticClass()))
			callInfo.caller = (UFunction *)stack->Node;
		callInfo.callee = pFunction;

		if (hookInfo.defaultParams)
			memcpy(params, hookInfo.defaultParams, paramsSize);
		else
			memset(params, 0, paramsSize);

		for (int i = 0; *stack->Code != 22 /* EX_EndFunctionParms */; i++)
		{
			stack->Step(stack->Object, params + vProperty[i]->Offset);
		}
		stack->Code++;
		if (*stack->Code == 0x41 /* EX_DebugInfo */)
			stack->Step(stack->Object, NULL);

		// Restore original function before calling, in case we want to call it inside our hook
		pFunction->iNative = hookInfo.orig_iNative;
		pFunction->Func = hookInfo.orig_Func;

		// Lock ProcessEvent hooks before calling, for performance
		// If you need these hooks to be applied in your function, just unlock() when you need it
		Hooks::lock();

		// Call the hook
		void(*hook)(UObject *, void *, void *, Hooks::CallInfo *) = (void(*)(UObject *, void *, void *, Hooks::CallInfo *))hookInfo.hookPtr;
		hook(callInfo.calleeObject, params, result, &callInfo);

		Hooks::unlock();

		// Re-hook the function
		pFunction->iNative = iNativeCustom;
		pFunction->Func = FuncCustom;
	}

	template<int ID>
	int addUScript_Explicit(void *hookPtr, const char *original_name, void *defaultParams = NULL)
	{
		UFunction *original_func = (UFunction *)UObject::FindObject<UFunction>(original_name);

		if (!original_func)
		{
			Logger::log("WARNING: unable hook function: '%s'. Check if you didn't make a typo", original_name);
			return 0;
		}

		// Save original values in a map
		_customHookParameters[ID] = Hooks::CustomParameters(hookPtr, original_name, original_func, defaultParams);

		// Replace them
		original_func->iNative = 0x789;
		original_func->Func = &UScriptBaseHook < ID > ;
		return 1;
	}
};

typedef void(UObject::*UObjectNative)(Hooks::FFrame &, void *);
#define addUScript	addUScript_Explicit<__COUNTER__>
