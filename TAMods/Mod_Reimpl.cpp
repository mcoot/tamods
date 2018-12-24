#include "Mods.h"

////////////////////////
// Display charge in hud
////////////////////////

float TrDevice_SniperRifle_CalcHUDAimChargePercent(ATrDevice_SniperRifle* that) {
	if (that->WorldInfo->NetMode != NM_DedicatedServer && that->r_fAimChargeTime > 0) {
		return that->m_fAimChargeDeltaTime / that->r_fAimChargeTime;
	}
	return 0.0f;
}

void TrDevice_SniperRifle_PlayScopeRechargeSound(ATrDevice_SniperRifle* that, ATrDevice_SniperRifle_execPlayScopeRechargeSound_Parms* params, void* result, Hooks::CallInfo* callInfo) {
	if (that->m_ScopeChargeSound) {
		that->m_ScopeChargeSound->Stop();
		that->m_ScopeChargeSound->FadeIn(0.1f, 1.0f);
	}
}

void TrDevice_SniperRifle_StopScopeRechargeSound(ATrDevice_SniperRifle* that, ATrDevice_SniperRifle_execStopScopeRechargeSound_Parms* params, void* result, Hooks::CallInfo* callInfo) {
	if (that->m_ScopeChargeSound && that->m_ScopeChargeSound->IsPlaying() && that->m_ScopeChargeSound->FadeOutTargetVolume != 0.0f) {
		that->m_ScopeChargeSound->FadeOut(0.2f, 0.0f);
	}
}

void TrDevice_CalcHUDAimChargePercent(ATrDevice* that, ATrDevice_execCalcHUDAimChargePercent_Parms* params, float* result, Hooks::CallInfo callInfo) {
	*result = that->CalcHUDAimChargePercent();

	if (that->IsA(ATrDevice_LaserTargeter::StaticClass())) {
		*result = TrDevice_LaserTargeter_CalcHUDAimChargePercent((ATrDevice_LaserTargeter*)that);
	}
	else if (that->IsA(ATrDevice_SniperRifle::StaticClass())) {
		*result = TrDevice_SniperRifle_CalcHUDAimChargePercent((ATrDevice_SniperRifle*)that);
	}
}

bool TrDevice_SniperRifle_Tick(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult) {
	ATrDevice_SniperRifle* that = (ATrDevice_SniperRifle*)dwCallingObject;
	ATrDevice_SniperRifle_eventTick_Parms* params = (ATrDevice_SniperRifle_eventTick_Parms*)pParams;

	if (!g_gameBalanceTracker.getReplicatedSetting("UseGOTYBXTCharging", false)) {
		that->eventTick(params->DeltaTime);
		return true;
	}

	if (!that->Owner) {
		that->ATrDevice::eventTick(params->DeltaTime);
		return true;
	}
	ATrPawn* owner = (ATrPawn*)that->Owner;

	if (!that->Instigator || !that->Instigator->Controller) {
		that->ATrDevice::eventTick(params->DeltaTime);
		return true;
	}
	ATrPlayerController* pc = (ATrPlayerController*)that->Instigator->Controller;

	// If not zoomed, no charge
	if (pc->m_ZoomState == ZST_NotZoomed) {
		that->m_fAimChargeDeltaTime = 0.f;
	}
	else {
		float interpDeltaTime = params->DeltaTime;

		if (owner->Physics == PHYS_Falling || owner->Physics == PHYS_Flying || that->VSizeSq(owner->Velocity) > 490000) {
			interpDeltaTime *= 0.5f;
		}

		// Increment charge time
		that->m_fAimChargeDeltaTime += interpDeltaTime;
	}

	if (that->m_fAimChargeDeltaTime >= that->r_fAimChargeTime) {
		that->StopScopeRechargeSound();
	}

	that->ATrDevice::eventTick(params->DeltaTime);

	return true;
}

void ATrPlayerController_ResetZoomDuration(ATrPlayerController* that, ATrPlayerController_execResetZoomDuration_Parms* params, void* result, Hooks::CallInfo* callInfo) {
	if (!g_gameBalanceTracker.getReplicatedSetting("UseGOTYBXTCharging", false)) {
		that->ResetZoomDuration(params->bPlayRechargeSoundOnWeapon);
		return;
	}
	
	if (!that->Pawn || !that->Pawn->Weapon) return;

	if (that->WorldInfo->NetMode == NM_DedicatedServer) return;

	that->c_fHUDZoomDuration = 0;

	if (!that->Pawn->Weapon->IsA(ATrDevice_SniperRifle::StaticClass())) return;

	ATrDevice_SniperRifle* dev = (ATrDevice_SniperRifle*)that->Pawn->Weapon;

	if (params->bPlayRechargeSoundOnWeapon && that->m_ZoomState != ZST_NotZoomed) {
		//dev->PlayScopeRechargeSound();
		TrDevice_SniperRifle_PlayScopeRechargeSound(dev, NULL, NULL, NULL);
	}
	else {
		TrDevice_SniperRifle_StopScopeRechargeSound(dev, NULL, NULL, NULL);
	}
}

void TrDevice_SniperRifle_ModifyInstantHitDamage(ATrDevice_SniperRifle* that, ATrDevice_SniperRifle_execModifyInstantHitDamage_Parms* params, float* result, Hooks::CallInfo* callInfo) {
	if (!g_gameBalanceTracker.getReplicatedSetting("UseGOTYBXTCharging", false)) {
		that->ModifyInstantHitDamage(params->FiringMode, params->Impact, params->Damage);
		return;
	}
	
	float damage = params->Damage;

	if (that->Instigator && that->Instigator->Controller) {
		ATrPlayerController* pc = (ATrPlayerController*)that->Instigator->Controller;

		if (pc && pc->m_ZoomState != ZST_NotZoomed) {
			// Polynomial scale, 16x^2
			float aimChargePct = that->FMin(that->r_fAimChargeTime, that->m_fAimChargeDeltaTime);
			aimChargePct = that->FMin((that->m_fMultCoeff * aimChargePct * aimChargePct) / that->m_fDivCoeff, 1.0f);

			if (aimChargePct > 0 && that->r_fAimChargeTime > 0) {
				if (that->m_fMaxAimedDamage > damage) {
					damage += (that->m_fMaxAimedDamage - damage) * aimChargePct;
				}
			}
		}
	}

	// Reset the aim charge
	that->m_fAimChargeDeltaTime = 0.f;

	*result = that->ATrDevice::ModifyInstantHitDamage(params->FiringMode, params->Impact, damage);
}