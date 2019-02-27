#include "Mods.h"

////////////////////////
// Nova Colt Ping Dependency
////////////////////////

void TrDevice_NovaSlug_FireAmmunition(ATrDevice_NovaSlug* that, ATrDevice_NovaSlug_execFireAmmunition_Parms* params, void* result, Hooks::CallInfo callInfo) {
	//that->r_bReadyToFire = true;
	TrDevice_FireAmmunition(that, NULL, NULL, Hooks::CallInfo());
}

void TrDevice_FireAmmunition(ATrDevice* that, ATrDevice_execFireAmmunition_Parms* params, void* result, Hooks::CallInfo callInfo) {
	if (!that->ReplicateAmmoOnWeaponFire() && !that->IsA(ATrDevice_NovaSlug::StaticClass())) {
		that->r_bReadyToFire = false;
	}

	if (!that->m_bAllowHoldDownFire) {
		that->m_bWantsToFire = false;
	}

	that->AUTWeapon::FireAmmunition();
	if (!that->m_bAllowHoldDownFire) {
		that->StopFire(0);
	}

	that->PlayFireAnimation(0);
	that->eventCauseMuzzleFlash();
	that->ShakeView();

	that->PayAccuracyForShot();
	that->eventUpdateShotsFired(false);

	bool bKickedBack = that->AddKickback();

	ATrPawn* pawn = (ATrPawn*)that->Instigator;

	if (pawn) {
		ATrPlayerController* pc = (ATrPlayerController*)pawn->Controller;

		if (bKickedBack && pc && pawn->Weapon == that) {
			FVector StartTrace = pawn->GetWeaponStartTraceLocation(that);
			FVector AimVector = Geom::rotationToVector(that->GetAimForCamera(StartTrace));
			FVector EndTrace = that->Add_VectorVector(StartTrace, that->Multiply_VectorFloat(AimVector, that->GetWeaponRange()));
			FVector kbVec = that->Normal(that->Subtract_VectorVector(EndTrace, pawn->GetPawnViewLocation()));
			pc->OnKickback(that->Subtract_RotatorRotator(Geom::vectorToRotation(kbVec), pawn->eventGetViewRotation()), that->m_fKickbackBlendOutTime);
		}
	}
}

////////////////////////
// Thrust pack rage dependency fix
////////////////////////

void TrPlayerController_PlayerWalking_ProcessMove(ATrPlayerController* that, APlayerController_execProcessMove_Parms* params) {
	ATrPawn* TrP = (ATrPawn*)that->Pawn;
	if (!TrP) return;

	if (that->m_bBlink) {


		if (TrP->Physics != PHYS_Falling && TrP->Physics != PHYS_Flying) {
			TrP->SetPhysics(PHYS_Falling);
		}

		ATrPlayerController_execGetBlinkPackAccel_Parms callParams;
		callParams.BlinkPackPctEffectiveness = 0;
		callParams.newAccel = FVector(0, 0, 0);
		TrPlayerController_GetBlinkPackAccel(that, &callParams, NULL, NULL);
		TrP->Velocity = Geom::add(TrP->Velocity, callParams.newAccel);

		if (that->Role == ROLE_Authority) {
			TrP->r_nBlinked++;
		}

		TrP->PlayBlinkPackEffect();

		if (that->Role == ROLE_Authority) {
			that->Pawn->SetRemoteViewPitch(that->Rotation.Pitch);
		}
		return;
	}

	if (that->m_bPressingJetpack) {
		if (that->Pawn->Physics != PHYS_Flying) {
			if (that->m_bJumpJet) {
				that->bPressedJump = true;
				that->CheckJumpOrDuck();
			}

			that->Pawn->SetPhysics(PHYS_Flying);
		}
	}
	else {
		if (that->Pawn->Physics == PHYS_Flying) {
			that->Pawn->SetPhysics(PHYS_Falling);
		}
	}

	if (that->Role == ROLE_Authority) {
		that->Pawn->SetRemoteViewPitch(that->Rotation.Pitch);
	}

	that->Pawn->Acceleration = params->newAccel;

	if (that->Pawn->Physics != PHYS_Flying) {
		that->CheckJumpOrDuck();
	}
}

void TrPlayerController_GetBlinkPackAccel(ATrPlayerController* that, ATrPlayerController_execGetBlinkPackAccel_Parms* params, void* result, Hooks::CallInfo* callInfo) {
	if (!g_gameBalanceTracker.getReplicatedSetting("RageThrustPackDependsOnCapperSpeed", true)) {
		that->GetBlinkPackAccel(&(params->newAccel), &(params->BlinkPackPctEffectiveness));
		return;
	}

	FVector NewAccel;
	float BlinkPackPctEffectiveness;

	ATrPawn* TrP = (ATrPawn*)that->Pawn;
	ATrPlayerReplicationInfo* TrPRI = (ATrPlayerReplicationInfo*)TrP->PlayerReplicationInfo;
	ATrDevice_Blink* BlinkPack = (ATrDevice_Blink*)that->GetDeviceByEquipPoint(EQP_Pack);

	if (!TrP || !BlinkPack) {
		return;
	}

	if (!TrP->IsA(ATrPawn::StaticClass()) || !BlinkPack->IsA(ATrDevice_Blink::StaticClass())) return;

	FVector ViewPos;
	FRotator ViewRot;
	that->eventGetPlayerViewPoint(&ViewPos, &ViewRot);

	// Start with a local-space impulse amount
	//NewAccel = BlinkPack->GetBlinkImpulse();
	NewAccel = BlinkPack->m_vBlinkImpulse;
	if (TrPRI) {
		UTrValueModifier* VM = TrPRI->GetCurrentValueModifier();
		if (VM) {
			NewAccel = Geom::mult(NewAccel, 1.0 + VM->m_fBlinkPackPotencyBuffPct);
		}
	}

	// Transform from local to world space
	NewAccel = that->GreaterGreater_VectorRotator(NewAccel, ViewRot);

	// Always make sure we have upward impulse
	if (NewAccel.Z <= BlinkPack->m_fMinZImpulse) {
		NewAccel.Z = BlinkPack->m_fMinZImpulse;
	}

	// Modify acceleration based on the power pool
	BlinkPackPctEffectiveness = BlinkPack->m_fPowerPoolCost > 0.0f ? that->FClamp(TrP->GetPowerPoolPercent() * 100 / BlinkPack->m_fPowerPoolCost, 0.0f, 1.0f) : 1.0f;

	// Modify the acceleration based on a speed cap
	float PawnSpeed = that->VSize(TrP->Velocity);
	float BlinkPackSpeedCapMultiplier = 1.0f;
	if ((that->Dot_VectorVector(that->Normal(TrP->Velocity), Geom::rotationToVector(ViewRot)) >= 0) && PawnSpeed > BlinkPack->m_fSpeedCapThresholdStart) {
		BlinkPackSpeedCapMultiplier = that->Lerp(1.0f, BlinkPack->m_fSpeedCapPct, that->FPctByRange(that->Min(PawnSpeed, BlinkPack->m_fSpeedCapThreshold), BlinkPack->m_fSpeedCapThresholdStart, BlinkPack->m_fSpeedCapThreshold));
	}
	BlinkPackPctEffectiveness *= BlinkPackSpeedCapMultiplier;

	// Apply the effectiveness debuf
	NewAccel = that->Multiply_FloatVector(BlinkPackPctEffectiveness, NewAccel);

	// Take energy from the player
	//BlinkPack->OnBlink(BlinkPackPctEffectiveness, false);
	float VMMultiplier = 1.0f;
	if (TrPRI) {
		UTrValueModifier* VM = TrPRI->GetCurrentValueModifier();
		if (VM) {
			VMMultiplier = 1.0f - VM->m_fPackEnergyCostBuffPct;
		}
	}
	TrP->ConsumePowerPool(BlinkPack->m_fPowerPoolCost * VMMultiplier);
	TrP->SyncClientCurrentPowerPool();

	// Out params
	params->newAccel = NewAccel;
	params->BlinkPackPctEffectiveness = BlinkPackPctEffectiveness;
}

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
		return false;
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