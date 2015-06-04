#include "Mods.h"

bool g_zoomed = false;

bool TrPC_PressedZoom(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	ATrPlayerController *that = (ATrPlayerController *)dwCallingObject;

	g_zoomed = true;
	if (that->PlayerInput->bUseToggleZoom && that->m_ZoomState != 0)
		g_zoomed = false;
	return (false);
}

bool TrPC_ReleasedZoom(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	ATrPlayerController *that = (ATrPlayerController *)dwCallingObject;

	if (!that->PlayerInput->bUseToggleZoom)
		g_zoomed = false;
	return (false);
}

bool TrPC_ReloadWeapon(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	ATrPlayerController *that = (ATrPlayerController *)dwCallingObject;
	ATrDevice *dev = NULL;

	if (!that->Pawn || !that->Pawn->Weapon)
		return (false);
	dev = (ATrDevice *)that->Pawn->Weapon;
	if (dev->CanClientRequestReloadNow() && dev->m_bEndZoomOnReload)
		g_zoomed = false;
	return (false);
}

static void TrDev_UpdateReticule(ATrDevice *dev)
{
	if (!dev)
		return;
	// printNotification(L"Ensis' mod", "UpdateReticule:%d, zoomed=%d", dev->DBWeaponId, g_zoomed);
	auto xhairs = g_config.crosshairs.find(dev->DBWeaponId);
	if (xhairs != g_config.crosshairs.end())
	{
		if (xhairs->second.second)
			dev->m_nAltReticuleIndex = xhairs->second.second;
		if (g_zoomed && xhairs->second.second)
			dev->m_nReticuleIndex = xhairs->second.second;
		else if (xhairs->second.first)
			dev->m_nReticuleIndex = xhairs->second.first;
		ATrPawn *pawn = (ATrPawn *)dev->Instigator;
		if (pawn)
		{
			ATrHUD *hud = (ATrHUD *)pawn->GetTrHud();
			if (hud)
			{
				UGfxTrHud *hud_movie = (UGfxTrHud *)hud->HudMovie;
				if (hud_movie)
				{
					UGFxTrReticules *reticule = (UGFxTrReticules *)hud_movie->Reticules;
					if (reticule)
						reticule->UpdateReticule(dev->Instigator, true);
				}
			}
		}
	}
}

bool TrPC_CallUpdateReticule(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	ATrPlayerController *that = (ATrPlayerController *)dwCallingObject;

	if (that && that->Pawn && that->Pawn->Weapon)
	{
		/*if (dynamic_cast<ATrVehicleWeapon *>(that->Pawn->Weapon))
		printNotification(L"Ensis' mod", "TrVehicleWeapon");
		else if (dynamic_cast<ATrDevice *>(that->Pawn->Weapon))
		printNotification(L"Ensis' mod", "TrDevice");
		else
		printNotification(L"Ensis' mod", "You're fucked");*/
		TrDev_UpdateReticule((ATrDevice *)that->Pawn->Weapon);
	}
	return (false);
}

bool TrPlayerPawn_Tick(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	ATrPawn *that = (ATrPawn *)dwCallingObject;
	ATrHUD *hud = that->GetTrHud();
	if (hud)
		Utils::tr_pc = (ATrPlayerController *)hud->PlayerOwner;
	if (hud && hud->m_GFxHud && hud->m_GFxHud->Reticules)
	{
		UGFxTrReticules *reticule = hud->m_GFxHud->Reticules;
		if (reticule)
		{
			ATrDevice *dev = (ATrDevice *)reticule->LastWeapon;

			// Per-weapon crosshair change
			static int lastWeapon = 0;
			if (dev && dev->DBWeaponId != lastWeapon)
			{
				TrDev_UpdateReticule(dev);
				lastWeapon = dev->DBWeaponId;
			}

			// Crosshair modification
			static int lastIndex = 0;
			if (reticule->ReticulesMC && reticule->ActiveReticule && reticule->m_nCurrentReticuleIndex != lastIndex)
			{
				float offset = g_config.showCrosshair ? 0.0f : 9999.0f;
				// Hide/show crosshair
				reticule->ReticulesMC->SetFloat(L"_y", -offset);
				reticule->ActiveReticule->SetFloat(L"_y", offset);

				// Resize crosshair
				reticule->ReticulesMC->SetFloat(L"_xscale", g_config.crosshairScale * 100.0f);
				reticule->ReticulesMC->SetFloat(L"_yscale", g_config.crosshairScale * 100.0f);
				reticule->ActiveReticule->SetFloat(L"_xscale", (1.0f / g_config.crosshairScale) * 100.0f);
				reticule->ActiveReticule->SetFloat(L"_yscale", (1.0f / g_config.crosshairScale) * 100.0f);
				lastIndex = reticule->m_nCurrentReticuleIndex;
			}
		}
	}
	if (!g_config.showWeapon)
		that->SetWeaponVisibility(g_config.showWeapon);
	return (false);
}
