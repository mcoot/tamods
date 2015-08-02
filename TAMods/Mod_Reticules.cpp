#include "Mods.h"

bool TrPlayerPawn_Tick(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	// TODO: Is this also called by bots?

	Hooks::lock();

	ATrPawn *that = (ATrPawn *)dwCallingObject;
	ATrHUD *hud = that->GetTrHud();

	if (hud && hud->PlayerOwner)
		Utils::tr_pc = (ATrPlayerController *)hud->PlayerOwner;

	if (hud && hud->m_GFxHud && hud->m_GFxHud->Reticules)
	{
		UGFxTrReticules *reticule = hud->m_GFxHud->Reticules;
		// Crosshair modification
		if (reticule->ReticulesMC && reticule->ActiveReticule)
		{
			wchar_t buff[128];

			float offset = g_config.showCrosshair && !g_config.customCrosshairs[reticule->m_nCurrentReticuleIndex] ? 0.0f : 9999.0f;

			// Hide/show crosshair
			reticule->ReticulesMC->SetFloat(L"_y", -offset);
			reticule->ActiveReticule->SetFloat(L"_y", offset / g_config.crosshairScale);

			// Resize crosshair
			reticule->ReticulesMC->SetFloat(L"_xscale", g_config.crosshairScale * 100.0f);
			reticule->ReticulesMC->SetFloat(L"_yscale", g_config.crosshairScale * 100.0f);
			reticule->ActiveReticule->SetFloat(L"_xscale", (1.0f / g_config.crosshairScale) * 100.0f);
			reticule->ActiveReticule->SetFloat(L"_yscale", (1.0f / g_config.crosshairScale) * 100.0f);

			// Crosshair color
			FASColorTransform trans = reticule->ReticulesMC->GetColorTransform();
			trans.Multiply = Utils::linCol(g_config.crosshairColor);
			reticule->ReticulesMC->SetColorTransform(trans);

			// Ammo info in 1st person
			if (g_config.showFirstPersonAmmo)
			{
				reticule->EnableVehicleAmmoClip();
				ATrDevice *dev = (ATrDevice *)reticule->LastWeapon;
				static UGFxObject *obj = NULL;
				static UGfxTrHud *lasthud = NULL;
				
				if (!obj || lasthud != hud->m_GFxHud)
				{
					obj = hud->m_GFxHud->GetVariableObject(L"_root.reticulesMC.reticules.clipMC.clipTF", NULL);
					lasthud = hud->m_GFxHud;
				}
				if (obj && dev && reticule->LastWeapon->IsA(ATrDevice::StaticClass()))
				{
					wsprintf(buff, L"%d/%d", dev->m_RemainingAmmoInClip, dev->m_nCarriedAmmo);
					obj->SetText(buff, NULL);
				}
			}
		}
		if (!g_config.showWeapon)
			that->SetWeaponVisibility(g_config.showWeapon);
	}
	Hooks::unlock();
	return false;
}
