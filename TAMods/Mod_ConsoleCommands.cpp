#include "Mods.h"

bool toggleBaseTurret(UObject *Object)
{
	if (Object->IsA(ATrBaseTurret_BloodEagle::StaticClass()))
	{
		ATrBaseTurret_BloodEagle *turret = (ATrBaseTurret_BloodEagle*)Object;
		turret->m_bEnabled = turret->m_bEnabled == 0 ? 1 : 0;
	}
	else if (Object->IsA(ATrBaseTurret_DiamondSword::StaticClass()))
	{
		ATrBaseTurret_DiamondSword *turret = (ATrBaseTurret_DiamondSword*)Object;
		turret->m_bEnabled = turret->m_bEnabled == 0 ? 1 : 0;
	}
	return false;
}

bool togglePower(UObject *Object)
{
	if (Object && Object->IsA(ATrPowerGenerator::StaticClass()))
	{
		ATrPowerGenerator *gen = (ATrPowerGenerator *)Object;

		bool isPowered = gen->r_bIsPowered != 0;
		gen->UpdateGeneratorPower(isPowered ? 0 : 1);

		// Restore power for all stations and turrets
		if (isPowered)
		{
			for (int i = 0; i < gen->m_PoweredObjectives.Count; i++)
			{
				if (gen->m_PoweredObjectives.Data[i]->IsA(ATrStation::StaticClass()))
					((ATrStation *)gen->m_PoweredObjectives.Data[i])->SetPowered(1);
				else if (gen->m_PoweredObjectives.Data[i]->IsA(ATrDeployable_BaseTurret::StaticClass()))
					((ATrDeployable_BaseTurret *)gen->m_PoweredObjectives.Data[i])->SetPowered(1);
			}
		}
	}
	return false;
}

int matched;

bool printObjectName(UObject *Object)
{
	Utils::printConsole(Object->GetFullName());
	matched++;

	return false;
}

bool TrChatConsole_InputKey(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	UTrChatConsole *that = (UTrChatConsole *)dwCallingObject;
	UTrChatConsole_execInputKey_Parms *params = (UTrChatConsole_execInputKey_Parms *)pParams;

	if (that->m_TrPC)
		Utils::tr_pc = that->m_TrPC;

	params->AmountDepressed = 1.0f;
	params->bGamepad = false;
	if (params->Key == FName("Enter") && params->Event == 1)
	{
		if (that->m_TrPC && that->m_TrPC->WorldInfo->TimeSeconds - that->m_fTypingTime < 0.150f)
			return false;
		if (that->TypedStr.Count)
		{
			if (that->IsSlashCommand())
			{
				std::wstring line = that->TypedStr.Data;
				bool customcommand = false;
				if (line.size() > 5 && line.substr(0, 5) == L"/lua ")
				{
					std::string luastr = std::string(line.begin() + 5, line.end());
					Utils::printConsole("lua> " + luastr);
					if (luastr[0] == '=')
						luastr.replace(0, 1, "return ");
					g_config.lua.doString(luastr);

					customcommand = true;
				}
				else if (line.size() == 13 && line == L"/reloadsounds")
				{
					g_config.reloadSounds();

					customcommand = true;
				}
				else if (line.size() == 14 && line == L"/toggleturrets")
				{
					Utils::FindObjects("^TrBaseTurret_(BloodEagle|DiamondSword)", &toggleBaseTurret);

					customcommand = true;
				}
				else if (line.size() == 12 && line == L"/togglepower")
				{
					Utils::FindObjects("^TrPowerGenerator_(BloodEagle|DiamondSword) TheWorld.PersistentLevel.TrPowerGenerator_", &togglePower);

					customcommand = true;
				}
				if (line.size() > 13 && line.substr(0, 13) == L"/findobjects ")
				{
					matched = 0;
					std::string needle = std::string(line.begin() + 13, line.end());
					Utils::FindObjects(needle, &printObjectName);
					Utils::console("%d objects matched", matched);

					customcommand = true;
				}

				else if ((line.size() == 13 && line == L"/reloadconfig") || (line.size() == 3 && line == L"/rc"))
				{
					g_config.parseFile();

					customcommand = true;
				}
				if (customcommand)
				{
					that->SetInputText(FString(L""));
					that->SetCursorPos(0);
					that->UpdateCompleteIndices();
					pResult = (void *)true;

					return true;
				}
			}
		}
	}
	return false;
}