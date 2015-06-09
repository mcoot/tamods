#include "Mods.h"

static void my_UpdateOverheadNumbers(ATrHUD *that, float DeltaTime)
{
	float accumulated_time, scaling_peak_time, alpha;
	FVector view_location, overhead_number_location;
	FRotator view_rotation;

	for (int i = 0; i < that->m_OverheadNumbers.Count; i++)
	{
		FOverheadNumber &curr = that->m_OverheadNumbers(i);

		curr.RemainingTime -= DeltaTime;
		if (curr.RemainingTime <= 0.0f)
		{
			TArray<FOverheadNumber> &nums = that->m_OverheadNumbers;
			memmove(nums.Data + i, nums.Data + (i + 1), (nums.Count - (i + 1)) * sizeof(FOverheadNumber));
			nums.Count--;
			nums.Max = nums.Count;
			i--;
		}
		else
		{
			accumulated_time = that->m_fOverheadNumberTotalTime - curr.RemainingTime;
			curr.WorldSpaceLocation.Z += (DeltaTime * that->m_fOverheadNumberZSpeed);
			if (accumulated_time > that->m_fOverheadNumberColorizeTimeMax)
			{
				FColor &col = curr.bShieldDamage ? that->m_OverheadNumberColorShieldMax : that->m_OverheadNumberColorMax;

				curr.CurrentColor.R = col.R;
				curr.CurrentColor.G = col.G;
				curr.CurrentColor.B = col.B;
			}
			else
			{
				if (accumulated_time > that->m_fOverheadNumberColorizeTimeMin && that->m_fOverheadNumberColorizeTimeMin < that->m_fOverheadNumberColorizeTimeMax)
				{
					alpha = (that->m_fOverheadNumberColorizeTimeMin - (that->m_fOverheadNumberColorizeTimeMax - accumulated_time)) / (that->m_fOverheadNumberColorizeTimeMax - that->m_fOverheadNumberColorizeTimeMin);
					FColor &cmin = curr.bShieldDamage ? that->m_OverheadNumberColorShieldMin : that->m_OverheadNumberColorMin;
					FColor &cmax = curr.bShieldDamage ? that->m_OverheadNumberColorShieldMax : that->m_OverheadNumberColorMax;

					curr.CurrentColor.R = (byte) (that->Lerp(float(cmin.R), float(cmax.R), alpha));
					curr.CurrentColor.G = (byte) (that->Lerp(float(cmin.G), float(cmax.G), alpha));
					curr.CurrentColor.B = (byte) (that->Lerp(float(cmin.B), float(cmax.B), alpha));
				}
			}

			if (curr.RemainingTime < that->m_fOverheadNumberFadeTime && that->m_fOverheadNumberFadeTime > 0.0f)
				curr.CurrentColor.A = (byte) ((int) ((curr.RemainingTime / that->m_fOverheadNumberFadeTime) * 255.0f));

			if (accumulated_time < that->m_fOverheadNumberScaleTime)
			{
				scaling_peak_time = that->m_fOverheadNumberScaleTime / 2.0f;
				if (accumulated_time < scaling_peak_time)
					curr.CurrentScale = 1.0f + ((accumulated_time / scaling_peak_time) * that->m_fOverheadNumberMaxScaleAmount);
				else
					curr.CurrentScale = 1.0f + ((1.0f - ((accumulated_time - (that->m_fOverheadNumberScaleTime - scaling_peak_time)) / (that->m_fOverheadNumberScaleTime - scaling_peak_time))) * that->m_fOverheadNumberMaxScaleAmount);
			}
			else if (curr.CurrentScale != 1.0f)
				curr.CurrentScale = 1.0f;

			if (that->TrPlayerOwner)
			{
				overhead_number_location.X = curr.WorldSpaceLocation.X;
				overhead_number_location.Y = curr.WorldSpaceLocation.Y;
				overhead_number_location.Z = curr.WorldSpaceLocation.Z;
				that->TrPlayerOwner->eventGetPlayerViewPoint(&view_location, &view_rotation);

				// vector(ViewRotation) Dot Normal(OverheadNumberLocation - ViewLocation)
				if (Geom::dot(Geom::rotationToVector(view_rotation), Geom::normal(Geom::sub(overhead_number_location, view_location))) >= 0.0f)
				{
					overhead_number_location = that->Canvas->Project(overhead_number_location);
					overhead_number_location.Z = curr.WorldSpaceLocation.W;
					if (curr.bShieldDamage)
						overhead_number_location.Y -= 20.0f;

					// MODIFICATIONS
					curr.CurrentScale *= g_config.damageNumbersScale;
					overhead_number_location.X += g_config.damageNumbersOffsetX;
					overhead_number_location.Y += g_config.damageNumbersOffsetY;

					wchar_t buff[16];
					wsprintf(buff, L"%d", curr.NumberValue);
					that->DrawColoredMarkerText(buff, curr.CurrentColor, overhead_number_location, that->Canvas, curr.CurrentScale, curr.CurrentScale);
				}
			}
		}
	}
}

bool TrHUD_eventPostRender(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult) {

	ATrHUD *that = (ATrHUD *)dwCallingObject;

	//Friend chat, enemy chat, team chat
	that->FriendlyChatColor = g_config.friendlyChatColor;
	that->EnemyChatColor = g_config.enemyChatColor;
	that->TeamChatColor = g_config.teamChatColor;
	that->WhisperChatColor = g_config.whisperChatColor;

	//Hud icon colors

	that->MarkerColorEnemy = Utils::linCol(g_config.enemyColor);
	that->MarkerColorEnemy_IsFriend = Utils::linCol(g_config.enemyIsFColor);
	that->MarkerColorFriendly = Utils::linCol(g_config.friendColor);
	that->MarkerColorFriendly_IsFriend = Utils::linCol(g_config.friendIsFColor);

	if (g_config.showRainbow == true){
		static FColor rainbow;
		//TODO switch statement should be replaced with a while statement
		switch (g_config.rainbowBulletInt) {
		case 0:
			rainbow.R = 255;
			rainbow.G = 0;
			rainbow.B = 0;
			break;
		case 1:
			rainbow.G = 125;
			break;
		case 2:
			rainbow.G = 255;
			break;
		case 3:
			rainbow.R = 125;
			break;
		case 4:
			rainbow.R = 0;
			break;
		case 5:
			rainbow.B = 125;
			break;
		case 6:
			rainbow.B = 255;
			break;
		case 7:
			rainbow.G = 125;
			break;
		case 8:
			rainbow.G = 0;
			break;
		case 9:
			rainbow.R = 125;
			break;
		case 10:
			rainbow.R = 255;
			break;
		case 11:
			rainbow.B = 125;
			break;
		case 12:
			rainbow.B = 0;
			break;
		}
		rainbow.A = 255;

		that->m_OverheadNumberColorMin = rainbow;
		that->m_OverheadNumberColorMax = rainbow;
	}
	else
	{
		that->m_OverheadNumberColorMin = g_config.damageNumbersColorMin;
		that->m_OverheadNumberColorMax = g_config.damageNumbersColorMax;
	}

	// Original function
	if (!that->m_GameClass)
	{
		if (!that->WorldInfo->GRI || !that->WorldInfo->GRI->GameClass)
			return true;
		that->InitializeGameHUD();
	}

	that->AUTGFxHudWrapper::eventPostRender();

	if (that->Scoreboard && that->Scoreboard->bIsActive)
		that->Scoreboard->Tick(that->RenderDelta);
	if (that->HUDTeamCTFStats && that->HUDTeamCTFStats->bIsActive)
		that->HUDTeamCTFStats->Tick();
	if (that->RabbitLeaderboard && that->RabbitLeaderboard->bIsActive)
		that->RabbitLeaderboard->Tick();
	if (that->TeamRabbitStats && that->TeamRabbitStats->bIsActive)
		that->TeamRabbitStats->Tick();
	if (that->ArenaStats && that->ArenaStats->bIsActive)
		that->ArenaStats->Tick();
	if (that->DaDStats && that->DaDStats->bIsActive)
		that->DaDStats->Tick();
	if (that->CaHStats && that->CaHStats->bIsActive)
		that->CaHStats->Tick();
	if (that->TeamSelectionMenuMovie && that->TeamSelectionMenuMovie->bMovieIsOpen)
		that->TeamSelectionMenuMovie->Tick(that->WorldInfo->GRI);

	if (that->m_UperPPEffect)
		that->m_UperPPEffect->bUseWorldSettings = !that->bIsMainMenuOpen;

	if (that->bIsMainMenuOpen || that->TrPlayerOwner && that->TrPlayerOwner->IsSpectating())
	{
		if (that->m_GFxHud && that->m_GFxHud->m_DirectionalDamageEffect)
			that->m_GFxHud->m_DirectionalDamageEffect->bShowInGame = false;
	}

	that->bGreenCrosshair = that->CheckCrosshairOnFriendly();
	that->bCrosshairOnFriendly = false;
	that->UpdateSkiEffect();
	that->UpdatePickupFlashEffect();
	that->UpdateInvulnerableEfect();
	that->UpdateShieldEffect();
	that->UpdateJammerEffect();
	that->UpdateFadeEffect();
	that->UpdateWhiteoutEffect();
	that->UpdateFumbledFlagEffect();
	my_UpdateOverheadNumbers(that, that->RenderDelta);
	that->UpdateOwnedItems();

	if (that->bRestoreHUDState)
	{
		if (that->LastChangeResCheckTime != (int)that->WorldInfo->TimeSeconds)
		{
			if (that->WorldInfo->TimeSeconds - (float)that->LastChangeResTime < 3.0f)
				that->RestoreHUDState();
			else
				that->bRestoreHUDState = false;
			that->LastChangeResCheckTime = (int)that->WorldInfo->TimeSeconds;
		}
	}
	return (true);
}

bool TrGO_PostRenderFor(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	return !g_config.showObjectiveIcon;
}

bool TrFlagBase_PostRenderFor(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	return !g_config.showFlagBaseIcon;
}

bool TrCTFBase_PostRenderFor(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	return !g_config.showCTFBaseIcon;
}

bool TrNugget_PostRenderFor(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	return !g_config.showNuggetIcon;
}

bool TrPawn_PostRenderFor(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	return !g_config.showPlayerIcon;
}

bool TrVehicle_PostRenderFor(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	return !g_config.showVehicleIcon;
}
