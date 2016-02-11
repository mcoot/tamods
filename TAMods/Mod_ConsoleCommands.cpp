#include "Mods.h"
#include "ConsoleCommands.h"

void TrChatConsole_AddOnlineFriendHelp(UTrChatConsole *that, UTrChatConsole_execAddOnlineFriendHelp_Parms *params, void *result, Hooks::CallInfo *callInfo)
{
	TArray<FAutoCompleteCommand> arr = that->TribesAutoCompleteList;
	consoleCommands::generateAutoCompleteList(arr);
	that->ManualAutoCompleteList = arr;

	that->BuildRuntimeAutoCompleteList(1);
}

bool execCustomCommand(UTrChatConsole *that)
{
	if (that->TypedStr.Count)
	{
		if (that->IsSlashCommand())
		{
			std::wstring line = that->TypedStr.Data;
			std::wstring command, params;

			// remove trailing spaces
			size_t end = line.find_last_not_of(L' ');
			if (end != std::wstring::npos)
				line = line.substr(0, end + 1);

			// try to split command and arguments
			size_t pos = line.find(' ');
			if (pos != std::wstring::npos)
			{
				command = std::wstring(line.begin(), line.begin() + pos);
				params = std::wstring(line.begin() + pos + 1, line.end());
			}
			else
				command = line;

			std::transform(command.begin(), command.end(), command.begin(), ::tolower);

			if (consoleCommands::map.find(command) != consoleCommands::map.end())
			{
				if (consoleCommands::map[command].function)
					(*consoleCommands::map[command].function)(command, params);
			}
			else // vanilla commands
				that->ConsoleCommand((wchar_t *)std::wstring(line.begin() + 1, line.end()).c_str());

			that->SetInputText(FString(L""));
			that->SetCursorPos(0);
			that->UpdateCompleteIndices();

			return true;
		}
	}
	return false;
}

// Custom console commands for the big console
bool TrChatConsole_Open_InputKey(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	UTrChatConsole *that = (UTrChatConsole *)dwCallingObject;
	UTrChatConsole_execInputKey_Parms *params = (UTrChatConsole_execInputKey_Parms *)pParams;

	ATrPlayerController *TrPC = that->m_TrPC;

	if (that->m_TrPC)
		Utils::tr_pc = that->m_TrPC;

	params->AmountDepressed = 1.0f;
	params->bGamepad = false;
	if (params->Key == FName("Enter") && params->Event == 1)
	{
		if (TrPC && TrPC->WorldInfo->TimeSeconds - that->m_fTypingTime < 0.150f)
			return false;

		if (execCustomCommand(that))
		{
			pResult = (void *)true;
			return true;
		}
	}
	return false;
}

// Custom console commands for the one-line console
bool TrChatConsole_Typing_InputKey(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	UTrChatConsole *that = (UTrChatConsole *)dwCallingObject;
	UTrChatConsole_execInputKey_Parms *params = (UTrChatConsole_execInputKey_Parms *)pParams;

	ATrPlayerController *TrPC = that->m_TrPC;

	if (that->m_TrPC)
		Utils::tr_pc = that->m_TrPC;

	params->AmountDepressed = 1.0f;
	params->bGamepad = false;
	if (params->Key == FName("Enter") && params->Event == 1)
	{
		if (TrPC && TrPC->WorldInfo->TimeSeconds - that->m_fTypingTime < 0.150f)
			return false;

		if (execCustomCommand(that))
		{
			that->TypedStr = L"";
			that->ChannelStr = L"";
			that->GotoState(FName(""), NULL, NULL, NULL);
			return true;
		}
	}
	return false;
}
