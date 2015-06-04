#include "Mods.h"

bool GFxTrHUD_LoadVGSMenu(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	UGfxTrHud *that = (UGfxTrHud *)dwCallingObject;

	if (!that || !that->m_TrPC || !that->m_TrPC->PlayerInput)
		return (false);
	UTrPlayerInput *tr_pi = (UTrPlayerInput *)that->m_TrPC->PlayerInput;

	if (tr_pi->InVGSClassMode())
		g_config.parseFile();
	else if (tr_pi->InVGSLoadoutMode())
	{
		int class_type = Data::class_id_to_nb[tr_pi->GetVGSClassId()];
		g_config.parseFile();
		for (int i = 0; i < 9; i++)
		{
			Loadout *loadout = g_config.loadouts[class_type][i];
			if (!loadout)
				continue;
			std::ostringstream oss;
			oss << (i + 1) << ": " << loadout->name;
			std::string str = oss.str();
			std::wstring wstr = std::wstring(str.begin(), str.end());
			wchar_t *wch = (wchar_t *)wstr.c_str();
			if (i < 6)
			{
				if (!that->m_TrPC->m_TrEquipInterface->IsLoadoutOwned(loadout->class_id, i))
					continue;
				int vgs_index = 0;
				for (int loadout_i = 0; loadout_i < i; loadout_i++)
				{
					if (that->m_TrPC->m_TrEquipInterface->IsLoadoutOwned(loadout->class_id, loadout_i))
						vgs_index++;
				}
				that->VGSMenuEntry[vgs_index + 1]->SetString(TEXT("label"), wch, NULL);
			}
			else
				that->AddVGSEntry(wch, true);
		}
	}
	return (false);
}

static void applyLoadoutToSlot(UTrEquipInterface *equip, int slot, Loadout *loadout)
{
	std::wstring wstr = std::wstring(loadout->name.begin(), loadout->name.end());
	wchar_t *wch = (wchar_t *)wstr.c_str();
	equip->SetLoadoutName(loadout->class_id, slot, wch);
	for (int i = 0; i < 9; i++)
	{
		int perkType[9] = { 2, 3, 5, 4, 8, 9, 10, 11, 12 };
		if (loadout->equipment[i] == 0)
			continue;
		if (!equip->SetActiveEquipId(loadout->class_id, perkType[i], slot, loadout->equipment[i]))
		{
			Utils::console("WARNING: Failed to equip %s '%s' in %s loadout #%d '%s'",
				Data::equip_type_name[i].c_str(), loadout->equip_name[i].c_str(), Data::class_type_name[loadout->class_type].c_str(), loadout->loadout_nb + 1, loadout->name.c_str());
		}
	}
	equip->RetrieveActives();
}

bool TrPI_OnVGSNumKeyPressed(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	UTrPlayerInput *that = (UTrPlayerInput *)dwCallingObject;
	UTrPlayerInput_eventOnVGSNumKeyPressed_Parms *params = (UTrPlayerInput_eventOnVGSNumKeyPressed_Parms *)pParams;

	if (that->m_bInVGSLoadoutMode)
	{
		int class_type = Data::class_id_to_nb[that->GetVGSClassId()];
		Loadout *loadout = g_config.loadouts[class_type][params->Index];
		ATrPlayerController *tr_pc = (ATrPlayerController *)that->Outer;
		if (!loadout)
			return (false);
		if (loadout->loadout_nb < 6 && !tr_pc->m_TrEquipInterface->IsLoadoutOwned(loadout->class_id, loadout->loadout_nb))
			return (false);
		if (loadout->loadout_nb < 6)
		{
			applyLoadoutToSlot(tr_pc->m_TrEquipInterface, loadout->loadout_nb, loadout);
		}
		else
		{
			applyLoadoutToSlot(tr_pc->m_TrEquipInterface, 0, loadout);
			params->Index = 0;
		}
	}
	return (false);
}
