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

static void TrDev_UpdateReticule(AWeapon *weapon)
{
	ATrDevice *dev = NULL;
	ATrVehicleWeapon *vdev = NULL;

	if (weapon && weapon->IsA(ATrDevice::StaticClass()))
		dev = (ATrDevice *)weapon;
	else if (weapon && weapon->IsA(ATrVehicleWeapon::StaticClass()))
		vdev = (ATrVehicleWeapon *)weapon;
	else
		return;

	auto xhairs = g_config.crosshairs.find(dev ? dev->DBWeaponId : vdev->DBWeaponId);
	if (xhairs != g_config.crosshairs.end())
	{
		ATrPawn *pawn = NULL;

		if (dev)
		{
			if (xhairs->second.second)
				dev->m_nAltReticuleIndex = xhairs->second.second;
			if (g_zoomed && xhairs->second.second)
				dev->m_nReticuleIndex = xhairs->second.second;
			else if (xhairs->second.first)
				dev->m_nReticuleIndex = xhairs->second.first;
			pawn = (ATrPawn *)dev->Instigator;
		}
		else
		{
			if (xhairs->second.second)
				vdev->m_nAltReticuleIndex = xhairs->second.second;
			if (g_zoomed && xhairs->second.second)
				vdev->m_nReticuleIndex = xhairs->second.second;
			else if (xhairs->second.first)
				vdev->m_nReticuleIndex = xhairs->second.first;
			pawn = (ATrPawn *)vdev->Instigator;
		}
		if (pawn)
		{
			ATrHUD *hud = (ATrHUD *)pawn->GetTrHud();
			if (hud)
			{
				UGfxTrHud *hud_movie = (UGfxTrHud *)hud->HudMovie;
				if (hud_movie && hud->HudMovie->IsA(UGfxTrHud::StaticClass()))
				{
					UGFxTrReticules *reticule = (UGFxTrReticules *)hud_movie->Reticules;
					if (reticule && reticule->m_nCurrentReticuleIndex != (dev ? dev->m_nReticuleIndex : vdev->m_nReticuleIndex))
						reticule->UpdateReticule(dev ? dev->Instigator : vdev->Instigator, true);
				}
			}
		}
	}
}

bool TrPC_CallUpdateReticule(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	ATrPlayerController *that = (ATrPlayerController *)dwCallingObject;

	if (that && that->Pawn && that->Pawn->Weapon)
		TrDev_UpdateReticule(that->Pawn->Weapon);
	return (false);
}

static void UpdateCrosshair(ATrHUD *hud)
{
	if (hud && hud->m_GFxHud && hud->m_GFxHud->Reticules)
	{
		UGFxTrReticules *reticule = hud->m_GFxHud->Reticules;
		AWeapon *weapon = reticule->LastWeapon;

		if (weapon && (weapon->IsA(ATrDevice::StaticClass()) || weapon->IsA(ATrVehicleWeapon::StaticClass())))
			TrDev_UpdateReticule(weapon);
	}
}

bool TrVehicle_Tick(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	ATrVehicle *that = (ATrVehicle *)dwCallingObject;
	ATrPlayerController *pc = (ATrPlayerController *) that->Owner;

	if (pc && pc->myHUD)
		UpdateCrosshair((ATrHUD *)pc->myHUD);
	return (false);
}

bool TrPlayerPawn_Tick(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	ATrPawn *that = (ATrPawn *)dwCallingObject;
	ATrHUD *hud = that->GetTrHud();

	if (hud)
		Utils::tr_pc = (ATrPlayerController *)hud->PlayerOwner;
	UpdateCrosshair(hud);

	if (hud && hud->m_GFxHud && hud->m_GFxHud->Reticules)
	{
		UGFxTrReticules *reticule = hud->m_GFxHud->Reticules;
		// Crosshair modification
		if (reticule->ReticulesMC && reticule->ActiveReticule)
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
		}
		if (!g_config.showWeapon)
			that->SetWeaponVisibility(g_config.showWeapon);
	}
	return (false);
}
