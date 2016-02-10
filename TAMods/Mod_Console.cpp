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

			size_t pos = line.find(' ');

			if (pos != std::string::npos)
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
				{
					(*consoleCommands::map[command].function)(command, params);

					that->SetInputText(FString(L""));
					that->SetCursorPos(0);
					that->UpdateCompleteIndices();
					return true;
				}
			}
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
	if (params->Key == FName("Enter") && params->Event == IE_Released)
	{
		if (TrPC && TrPC->WorldInfo->TimeSeconds - that->m_fTypingTime < 0.150f)
			return false;

		if (execCustomCommand(that))
		{
			pResult = (void *)true;
			return true;
		}
	}
	//else if (params->Key == FName("Tab") && params->Event == IE_Pressed)
	//{
	//	if (that->AutoCompleteIndices.Count > 0 && that->bAutoCompleteLocked == 0)
	//	{
	//		that->TypedStr = that->AutoCompleteList.Get(*that->AutoCompleteIndices.Get(that->AutoCompleteIndex))->Command;
	//		that->SetCursorPos(that->TypedStr.Count);
	//	}
	//	return true;
	//}
	else if (params->Key == FName("Down") && params->Event == IE_Pressed)
	{
		if (!that->bNavigatingHistory && ((that->bRequireCtrlToNavigateAutoComplete && that->bCtrl) || (!that->bRequireCtrlToNavigateAutoComplete && !that->bCtrl && that->AutoCompleteIndices.Count > 1)))
		{
			if (++that->AutoCompleteIndex == that->AutoCompleteIndices.Count)
			{
				that->AutoCompleteIndex = 0;
			}
		}
		else if (that->HistoryBot >= 0)
		{
			if (that->HistoryCur == that->HistoryBot)
				that->HistoryCur = that->HistoryTop;
			else
			{
				that->HistoryCur--;
				if (that->HistoryCur < 0)
					that->HistoryCur = CONST_MaxHistory - 1;
			}

			that->SetInputText(that->History[that->HistoryCur]);
			that->SetCursorPos(that->History[that->HistoryCur].Count);
			that->UpdateCompleteIndices();
			that->bNavigatingHistory = true;
		}
		return true;
	}
	else if (params->Key == FName("Up") && params->Event == IE_Pressed)
	{
		if (!that->bNavigatingHistory && ((that->bRequireCtrlToNavigateAutoComplete && that->bCtrl) || (!that->bRequireCtrlToNavigateAutoComplete && !that->bCtrl && that->AutoCompleteIndices.Count > 1)))
		{
			if (--that->AutoCompleteIndex < 0)
			{
				that->AutoCompleteIndex = that->AutoCompleteIndices.Count - 1;
			}
			that->bAutoCompleteLocked = false;
		}
		else if (that->HistoryBot >= 0)
		{
			if (that->HistoryCur == that->HistoryTop)
				that->HistoryCur = that->HistoryBot;
			else
				that->HistoryCur = (that->HistoryCur + 1) % CONST_MaxHistory;

			that->SetInputText(that->History[that->HistoryCur]);
			that->SetCursorPos(that->History[that->HistoryCur].Count);
			that->UpdateCompleteIndices();
			that->bNavigatingHistory = true;
		}
		return true;
	}
	else if (params->Key == FName("PageUp") || params->Key == FName("MouseScrollUp"))
	{
		if (that->SBPos < that->Scrollback.Count - 1)
		{
			if (that->bCtrl)
				that->SBPos += 20;
			else
				that->SBPos += 5;

			if (that->SBPos >= that->Scrollback.Count)
				that->SBPos = that->Scrollback.Count - 1;
		}
		return true;
	}
	else if (params->Key == FName("PageDown") || params->Key == FName("MouseScrollDown"))
	{
		if (that->SBPos > 0)
		{
			if (that->bCtrl)
				that->SBPos -= 20;
			else
				that->SBPos -= 5;

			if (that->SBPos < 0)
				that->SBPos = 0;
		}
		return true;
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

void TrChatConsole_Open_PostRender_Console(UTrChatConsole *that, UTrChatConsole_execPostRender_Console_Parms *params, void *result, Hooks::CallInfo *callInfo)
{
	float Height;
	float xl, yl, y, ScrollLineXL, ScrollLineYL, info_xl, info_yl;
	FString OutStr;
	int idx, remlen;
	FColor DefaultColor;

	// render the buffer

	// Blank out a space
	params->Canvas->Font = Utils::consoleFont;

	// the height of the buffer will be 75% of the height of the screen
	Height = params->Canvas->ClipY * 0.65f;

	// Set the text color.
	params->Canvas->SetDrawColor(0, 0, 0, 175);

	// move the pen to the top-left pixel
	params->Canvas->SetPos(0, 0, 0);

	// draw the black background tile
	params->Canvas->DrawRect(params->Canvas->ClipX, Height, that->DefaultTexture_White);

	// now render the typing region
	OutStr = that->Concat_StrStr(that->Concat_StrStr(that->ChannelStr, L"> "), that->TypedStr);

	// determine the height of the text
	params->Canvas->StrLen(OutStr, &xl, &yl);

	// move the pen up + 12 pixels of buffer (for the green borders and some space)
	params->Canvas->SetPos(0, Height - 12 - yl, 0);

	// Set the text color.
	if (that->IsSlashCommand())
	{
		params->Canvas->SetDrawColor(0, 255, 0, 255);
	}
	else
	{
		params->Canvas->SetDrawColor(199, 254, 218, 255);
	}

	// draw the top typing region border
	params->Canvas->DrawTile(that->DefaultTexture_White, params->Canvas->ClipX, 2, 0, 0, 32, 32, { 0, 0, 0, 1.0f }, NULL, NULL);

	// move the pen to the bottom of the console buffer area
	params->Canvas->SetPos(0, Height, 0);

	// draw the bottom typing region border
	params->Canvas->DrawTile(that->DefaultTexture_White, params->Canvas->ClipX, 2, 0, 0, 32, 32, { 0, 0, 0, 1.0f }, NULL, NULL);

	// center the pen between the two borders
	params->Canvas->SetPos(0, Height - 5 - yl, 0);
	params->Canvas->bCenter = false;

	// render the text that is being typed
	params->Canvas->DrawTextW(OutStr, false, 1.0f, 1.0f, NULL);

	// draw the remaining text for matching auto-complete
	if (that->AutoCompleteIndices.Count > 0)
	{
		idx = that->AutoCompleteIndices.Data[that->AutoCompleteIndex];
		params->Canvas->SetPos(0 + xl, Height - 5 - yl, 0);
		params->Canvas->SetDrawColor(87, 148, 87, 255);
		remlen = that->AutoCompleteList.Data[idx].Command.Count - that->TypedStr.Count;
		params->Canvas->DrawTextW(that->Right(that->AutoCompleteList.Data[idx].Command, remlen), false, 1.0f, 1.0f, NULL);

		if (remlen > 0)
		{
			params->Canvas->DrawTextW(that->Concat_StrStr(L"    ", that->TabHelp), true, 1.0f, 1.0f, NULL);
		}

		params->Canvas->StrLen(that->Concat_StrStr(that->ChannelStr, L"> "), &xl, &yl);
		y = Height + 5;
		for (int i = 0; i < that->AutoCompleteIndices.Count && i < 10; i++)
		{
			int myIdx = i;

			// Pages
			if (that->AutoCompleteIndex > 9)
				myIdx += 10 * (that->AutoCompleteIndex / 10);
			
			if (myIdx >= that->AutoCompleteIndices.Count)
				break;

			idx = that->AutoCompleteIndices.Data[myIdx];
			params->Canvas->SetPos(0 + xl, y, 0);
			params->Canvas->StrLen(that->AutoCompleteList.Data[idx].Desc, &info_xl, &info_yl);

			FLinearColor bg = { 0.0f, 0.0f, 0.0f, 1.0f };
			if (myIdx == that->AutoCompleteIndex)
				bg = { 0.1f, 0.1f, 0.1f, 1.0f };

			params->Canvas->DrawTile(that->DefaultTexture_White, info_xl, info_yl, 0, 0, 32, 32, bg, NULL, NULL);
			params->Canvas->SetPos(0 + xl, y, 0);
			params->Canvas->SetDrawColor(0, 255, 0, 255);
			params->Canvas->DrawTextW(that->AutoCompleteList.Data[idx].Desc, false, 1.0f, 1.0f, NULL);
			y += info_yl;
		}
	}
	else if (that->TypedStr.Count == 0)
	{
		params->Canvas->SetPos(0 + xl, Height - 5 - yl, 0);
		params->Canvas->SetDrawColor(87, 148, 87, 255);
		params->Canvas->DrawTextW(that->Concat_StrStr(L"       ", ((UTrChatConsole *)that->StaticClass()->Default)->EscHelp), false, 1.0f, 1.0f, NULL);

		y = Height + 5;
		params->Canvas->SetPos(0 + xl, y, 0);
		params->Canvas->StrLen(((UTrChatConsole *)that->StaticClass()->Default)->SlashHelp, &info_xl, &info_yl);
		params->Canvas->SetDrawColor(0, 0, 0, 255);
		params->Canvas->DrawTile(that->DefaultTexture_White, info_xl, info_yl, 0, 0, 32, 32, { 0, 0, 0, 255 }, NULL, NULL);
		params->Canvas->SetPos(0 + xl, y, 0);
		params->Canvas->SetDrawColor(0, 255, 0, 255);
		params->Canvas->DrawTextW(((UTrChatConsole *)that->StaticClass()->Default)->SlashHelp, false, 1.0f, 1.0f, NULL);
		y += info_yl;
		params->Canvas->SetPos(0 + xl, y, 0);
		params->Canvas->StrLen(((UTrChatConsole *)that->StaticClass()->Default)->TellHelp, &info_xl, &info_yl);
		params->Canvas->SetDrawColor(0, 0, 0, 255);
		params->Canvas->DrawTile(that->DefaultTexture_White, info_xl, info_yl, 0, 0, 32, 32, { 0, 0, 0, 255 }, NULL, NULL);
		params->Canvas->SetPos(0 + xl, y, 0);
		params->Canvas->SetDrawColor(0, 255, 0, 255);
		params->Canvas->DrawTextW(((UTrChatConsole *)that->StaticClass()->Default)->TellHelp, false, 1.0f, 1.0f, NULL);
		y += info_yl;
	}

	OutStr = that->Concat_StrStr(that->Concat_StrStr(that->ChannelStr, L"> "), that->Left(that->TypedStr, that->TypedStrPos));

	// position the pen at the cursor position
	params->Canvas->StrLen(OutStr, &xl, &yl);
	params->Canvas->SetPos(xl, Height - 3 - yl, 0);

	// render the cursor
	params->Canvas->DrawTextW(L"_", false, 1.0f, 1.0f, NULL);

	// figure out which element of the scrollback buffer to should appear first (at the top of the screen)
	idx = that->SBHead - that->SBPos;
	y = Height - 16 - (yl * 2);

	if (that->Scrollback.Count == 0)
		return;

	// change the draw color to white
	DefaultColor = ((AHUD *)AHUD::StaticClass()->Default)->WhiteColor;

	// while we have enough room to draw another line and there are more lines to draw
	while (y > yl && idx >= 0)
	{
		// move the pen to the correct position
		params->Canvas->SetPos(0, y, 0);

		// adjust the location for any word wrapping due to long text lines
		params->Canvas->StrLen(that->Scrollback.Data[idx].Text, &ScrollLineXL, &ScrollLineYL);
		if (ScrollLineYL > yl)
		{
			y -= (ScrollLineYL - yl);
			params->Canvas->CurY = y;
		}
		FColor &col1 = that->Scrollback.Data[idx].OverrideColor;
		FColor col2 = ((AUTHUD *)AUTHUD::StaticClass()->Default)->BlackColor;

		if (col1.R != col2.R ||
			col1.G != col2.G ||
			col1.B != col2.B ||
			col1.A != col2.A)
		{
			params->Canvas->SetDrawColorStruct(col1);
		}
		else
		{
			params->Canvas->SetDrawColorStruct(DefaultColor);
		}

		// draw the next line down in the buffer
		params->Canvas->DrawTextW(that->Scrollback.Data[idx].Text, false, 1.0f, 1.0f, NULL);
		idx--;
		y -= yl;
	}
}

void TrChatConsole_Typing_PostRender_Console(UTrChatConsole *that, UTrChatConsole_execPostRender_Console_Parms *params, void *result, Hooks::CallInfo *callInfo)
{
	
}