#include "Mods.h"

//////////////////////////
//// Keep track of players' call-in status
//////////////////////////

class _CallInData {
private:
	struct _CallInPlayerData {
		long long playerId = -1;
		float lastInvCallInTime = -1;
		float invCallInEndTime = -1;
		FVector lastTargetPos = FVector(0, 0, 0);
	};

	std::map<long long, _CallInPlayerData> callInPlayerData;

	_CallInPlayerData getByLaserTargeter(ATrDevice_LaserTargeter* that) {
		if (!that->Owner) return _CallInPlayerData();

		APawn* pawn = (APawn*)that->Owner;
		if (!pawn->PlayerReplicationInfo) return _CallInPlayerData();
		long long playerId = TAModsServer::netIdToLong(pawn->PlayerReplicationInfo->UniqueId);

		_CallInPlayerData data;
		if (callInPlayerData.find(playerId) != callInPlayerData.end()) data = callInPlayerData[playerId];
		data.playerId = playerId;
		return data;
	}

	void set(_CallInPlayerData data) {
		callInPlayerData[data.playerId] = data;
	}
public:
	void ClearAllData() {
		callInPlayerData.clear();
	}

	void BeginFiring(ATrDevice_LaserTargeter* that) {
		if (!that->WorldInfo || !that->Owner) return;
		_CallInPlayerData data = getByLaserTargeter(that);

		// Personal cooldown remaining, if any
		float remainingCooldown = 0;
		if (data.lastInvCallInTime >= 0.f) {
			float cooldownTime = g_gameBalanceTracker.getReplicatedSetting("InventoryCallInCooldownTime", 10.f);
			float timeSinceLastCallIn = that->WorldInfo->TimeSeconds - data.lastInvCallInTime;
			remainingCooldown = that->FMax(cooldownTime - timeSinceLastCallIn, 0);
		}

		float buildUpTime = g_gameBalanceTracker.getReplicatedSetting("InventoryCallInBuildUpTime", 2.f);

		// Time at which the call-in would successfully happen
		data.invCallInEndTime = that->WorldInfo->TimeSeconds + remainingCooldown + buildUpTime;
		set(data);
	}

	void EndFiring(ATrDevice_LaserTargeter* that) {
		if (!that->WorldInfo || !that->Owner) return;
		_CallInPlayerData data = getByLaserTargeter(that);

		// Reset the successful call-in time as the user has cancelled firing
		data.invCallInEndTime = -1;
		data.lastTargetPos = FVector(0, 0, 0);

		set(data);
	}

	void UpdateTarget(ATrDevice_LaserTargeter* that, bool hasHitSomething, FVector laserEnd) {
		if (!that->WorldInfo || !that->Owner) return;
		_CallInPlayerData data = getByLaserTargeter(that);

		float buildUpTime = g_gameBalanceTracker.getReplicatedSetting("InventoryCallInBuildUpTime", 2.f);

		if (hasHitSomething) {
			// Update call-in end time, we are hitting a target
			if (data.invCallInEndTime <= 0) {
				data.invCallInEndTime = that->WorldInfo->TimeSeconds + buildUpTime;
			}

			// Update target position
			data.lastTargetPos = laserEnd;
		}
		else {
			// Not hitting anything,kill the end point
			data.invCallInEndTime = that->FClamp(data.invCallInEndTime + 2.0f, that->WorldInfo->TimeSeconds, that->WorldInfo->TimeSeconds + buildUpTime);
			data.lastTargetPos = FVector(0, 0, 0);
		}

		set(data);
	}

	void RecordActivation(ATrDevice_LaserTargeter* that) {
		if (!that->WorldInfo || !that->Owner) return;
		_CallInPlayerData data = getByLaserTargeter(that);

		data.lastInvCallInTime = that->WorldInfo->TimeSeconds;
		set(data);
	}

	FVector GetTargetPos(ATrDevice_LaserTargeter* that) {
		if (!that->WorldInfo || !that->Owner) return FVector(0, 0, 0);
		_CallInPlayerData data = getByLaserTargeter(that);

		return data.lastTargetPos;
	}

	bool IsTimeToActivate(ATrDevice_LaserTargeter* that) {
		if (!that->WorldInfo || !that->Owner) return false;
		_CallInPlayerData data = getByLaserTargeter(that);

		return data.invCallInEndTime > 0 && data.invCallInEndTime <= that->WorldInfo->TimeSeconds;
	}

	float CalcHUDAimChargePercent(ATrDevice_LaserTargeter* that) {
		if (!that->WorldInfo || !that->Owner) return 0.f;
		_CallInPlayerData data = getByLaserTargeter(that);

		// Personal cooldown remaining, if any
		float remainingCooldown = 0;
		if (data.lastInvCallInTime >= 0.f) {
			float cooldownTime = g_gameBalanceTracker.getReplicatedSetting("InventoryCallInCooldownTime", 10.f);
			float timeSinceLastCallIn = that->WorldInfo->TimeSeconds - data.lastInvCallInTime;
			remainingCooldown = that->FMax(cooldownTime - timeSinceLastCallIn, 0);
		}

		if (data.invCallInEndTime <= 0 || remainingCooldown > 0) {
			return 0.f;
		}

		if (data.invCallInEndTime <= that->WorldInfo->TimeSeconds) {
			return 1.f;
		}

		float buildUpTime = g_gameBalanceTracker.getReplicatedSetting("InventoryCallInBuildUpTime", 2.f);
		float result = (buildUpTime - (data.invCallInEndTime - that->WorldInfo->TimeSeconds)) / buildUpTime;

		return result;
	}
};

static _CallInData callInData;

void ResetLaserTargetCallInCache() {
	callInData.ClearAllData();
}

//////////////////////////
//// Laser Targeter modifications
//// Used to re-enable call-ins
//////////////////////////

static bool IsValidTargetLocation(ATrDevice_LaserTargeter* that, FVector currentTarget, FVector prevTarget, AActor* hitTarget) {
	// Unfortunately the original version of this was native, and doesn't exist in OOTB :(
	// So I've reimplemented it from scratch with traces yaaaaay

	// Rules:
	// 1) Nowhere is valid in pre-round
	// 2) Must not collide with flag
	// 3) Must not be underneath any world geometry (e.g. inside a base)

	// Check we aren't in preround
	if (!that->WorldInfo || !that->WorldInfo->GRI) return false;
	if (((ATrGameReplicationInfo*)that->WorldInfo->GRI)->bWarmupRound) {
		return false;
	}

	FVector landLocation = currentTarget;
	// Spawn location for the pod is directly above where it will land
	// It is supposed to take 5sec to land
	ATrCallIn_DeliveryPod* podDefault = (ATrCallIn_DeliveryPod*)ATrCallIn_DeliveryPod::StaticClass()->Default;
	FVector podFallStart = Geom::add(landLocation, Geom::mult(FVector(0, 0, 1), 5.0f * (podDefault->Speed)));
	// End collision check slightly above the ground
	FVector podFallEnd = Geom::add(landLocation, Geom::mult(FVector(0, 0, 1), 50));

	// Trace the path of the fall, and see if it hits world geometry
	FVector hitLocation, hitNormal;
	FTraceHitInfo hitInfo;
	AActor* hitActor = that->Trace(podFallEnd, podFallStart, false, FVector(), 0, &hitLocation, &hitNormal, &hitInfo);

	if (hitActor) {
		// There was something above the point we wanted to land
		return false;
	}

	// Now, we want to check if we're going to hit a flag
	hitActor = that->Trace(podFallEnd, podFallStart, true, FVector(10, 10, 10), 0, &hitLocation, &hitNormal, &hitInfo);
	if (hitActor) {
		// Should probably check that it is a flag, but thus far flags are the only thing that seem to trigger
		// Maybe turrets do too (haven't tested) but that's probably a good thing if so
		return false;
	}

	return true;
}

static bool GetLaserStartAndEnd(ATrDevice_LaserTargeter* that, FVector& startLocation, FVector& endLocation, FVector& endLocationNormal) {
	FVector startTrace = that->InstantFireStartTrace();
	FVector endTrace = that->InstantFireEndTrace(startTrace);

	endLocationNormal = FVector(0, 0, 1);

	TArray<FImpactInfo> impactList;

	FImpactInfo testImpact = that->CalcWeaponFire(startTrace, endTrace, FVector(0, 0, 0), 0, &impactList);

	if (that->NotEqual_VectorVector(testImpact.HitLocation, startTrace) || that->NotEqual_VectorVector(testImpact.HitLocation, endTrace)) {
		endLocation = testImpact.HitLocation;
		endLocationNormal = testImpact.HitNormal;
	}

	startLocation = startTrace;
	bool targetLocValid = IsValidTargetLocation(that, endLocation, callInData.GetTargetPos(that), testImpact.HitActor);
	return testImpact.HitActor != NULL && targetLocValid;
}

static void CallInConfirmed(ATrDevice_LaserTargeter* that) {
	//if (that->Role == ROLE_Authority) return;
}

static void ServerPerformCallIn(ATrDevice_LaserTargeter* that, FVector endLocation, FVector hitNormal) {
	if (that->Role != ROLE_Authority) {
		if (IsValidTargetLocation(that, endLocation, callInData.GetTargetPos(that), NULL)) {
			callInData.RecordActivation(that);
			callInData.EndFiring(that);
		}
		return;
	}

	if (IsValidTargetLocation(that, endLocation, callInData.GetTargetPos(that), NULL)) {
		ATrCallIn_SupportInventory* callIn = (ATrCallIn_SupportInventory*)that->Spawn(ATrCallIn_SupportInventory::StaticClass(),
			that->Owner, FName(), FVector(), FRotator(), NULL, false);
		callIn->Initialize(0, 0, 0);
		if (callIn->FireCompletedCallIn(1, endLocation, hitNormal)) {
			CallInConfirmed(that);
			callInData.RecordActivation(that);
		}

		callIn->bPendingDelete = true;

		callInData.EndFiring(that);

		if (that->Instigator->Controller) {
			ATrPlayerController* pc = (ATrPlayerController*)(that->Instigator->Controller);

			if (pc && pc->Stats) {
				// Stats... 
				//pc->Stats->CallIn(pc);
			}
		}

		that->EndFire(that->CurrentFireMode);
		that->GotoState(that->m_PostFireState, NULL, NULL, NULL);
	}
}

void TrDevice_LaserTargeter_OnStartConstantFire(ATrDevice_LaserTargeter* that, ATrDevice_LaserTargeter_execOnStartConstantFire_Parms* params, void* result, Hooks::CallInfo* callInfo) {
	if (!g_gameBalanceTracker.getReplicatedSetting("EnableInventoryCallIn", false)) {
		that->OnStartConstantFire();
		return;
	}

	that->SpawnLaserEffect();
	callInData.BeginFiring(that);
}

void TrDevice_LaserTargeter_OnEndConstantFire(ATrDevice_LaserTargeter* that, ATrDevice_LaserTargeter_execOnEndConstantFire_Parms* params, void* result, Hooks::CallInfo* callInfo) {
	if (!g_gameBalanceTracker.getReplicatedSetting("EnableInventoryCallIn", false)) {
		that->OnEndConstantFire();
		return;
	}

	if (that->Instigator != NULL) {
		ATrPawn* p = (ATrPawn*)that->Instigator;
		p->WeaponStoppedFiring(that, false);
	}

	that->ATrDevice_ConstantFire::OnEndConstantFire();
	that->KillLaserEffect();

	if (that->WorldInfo->NetMode != NM_DedicatedServer) {
		callInData.EndFiring(that);
	}
}

float TrDevice_LaserTargeter_CalcHUDAimChargePercent(ATrDevice_LaserTargeter* that) {
	return callInData.CalcHUDAimChargePercent(that);
}


// Disabled due to OutParam weirdness
void TrDevice_LaserTargeter_GetLaserStartAndEnd(ATrDevice_LaserTargeter* that, ATrDevice_LaserTargeter_execGetLaserStartAndEnd_Parms* params, void* result, Hooks::CallInfo* callInfo) {
	//if (!g_config.serverSettings.EnableInventoryCallIn) {
	//	that->GetLaserStartAndEnd(params->StartLocation, params->EndLocation);
	//	return;
	//}
}

void TrDevice_LaserTargeter_UpdateTarget(ATrDevice_LaserTargeter* that, ATrDevice_LaserTargeter_execUpdateTarget_Parms* params, void* result, Hooks::CallInfo* callInfo) {
	if (!g_gameBalanceTracker.getReplicatedSetting("EnableInventoryCallIn", false)) {
		that->UpdateTarget(params->hasHitSomething, params->End);
		return;
	}

	if (!that->Instigator) return;

	FVector start, end, hitNormal;
	bool hasLaserHit = GetLaserStartAndEnd(that, start, end, hitNormal);

	callInData.UpdateTarget(that, params->hasHitSomething && hasLaserHit, params->End);
}

// Not currently hooked...
void TrDevice_LaserTargeter_SpawnLaserEffect(ATrDevice_LaserTargeter* that, ATrDevice_LaserTargeter_execSpawnLaserEffect_Parms* params, void* result, Hooks::CallInfo* callInfo) {
	if (!g_gameBalanceTracker.getReplicatedSetting("EnableInventoryCallIn", false)) {
		that->SpawnLaserEffect();
		return;
	}

	FVector start, end, hitNormal;
	bool hasLaserHit = GetLaserStartAndEnd(that, start, end, hitNormal);

	ATrPawn* pOwner;
	if (!that->Instigator) {
		return;
	}
	pOwner = (ATrPawn*)that->Instigator;

	// Spawn laser effect clientside only
	UParticleSystemComponent* pscLaser = that->m_pscLaserEffect;
	if (!pscLaser && pOwner->Controller && pOwner->Controller->IsLocalPlayerController()) {
		pscLaser = that->WorldInfo->MyEmitterPool->SpawnEmitterMeshAttachment(that->m_TracerBeamTemplate, (USkeletalMeshComponent*)that->Mesh, FName("WSO_Emit_01"), true, FVector(), FRotator());
		pscLaser->SetDepthPriorityGroup(SDPG_World);
		pscLaser->SetTickGroup(TG_EffectsUpdateWork);
		pscLaser->SetVectorParameter(FName("TracerEnd"), end);

		//UMaterialInstanceConstant* beamMIC = 
	}

	callInData.UpdateTarget(that, hasLaserHit, end);
}

// Not hooked on client
void TrDevice_LaserTargeter_UpdateLaserEffect(ATrDevice_LaserTargeter* that, ATrDevice_LaserTargeter_execUpdateLaserEffect_Parms* params, void* result, Hooks::CallInfo* callInfo) {
	if (!g_gameBalanceTracker.getReplicatedSetting("EnableInventoryCallIn", false)) {
		that->UpdateLaserEffect();
		return;
	}

	that->UpdateLaserEffect();

	FVector start, end, hitNormal;
	bool hasLaserHit = GetLaserStartAndEnd(that, start, end, hitNormal);

	//if (that->m_pscLaserEffect) {
	//	that->m_pscLaserEffect->SetVectorParameter(FName("TracerEnd"), end);
	//	FVector testy(0, 0, 0);
	//	that->m_pscLaserEffect->GetVectorParameter(FName("TracerEnd"), &testy);
	//	Logger::log("Set laser end to (%f, %f, %f), actual is (%f, %f, %f)", end.X, end.Y, end.Z, testy.X, testy.Y, testy.Z);

	//	UMaterialInterface* beamMIOut;
	//	if (that->m_pscLaserEffect->GetMaterialParameter(FName("Beam_Material"), &beamMIOut)) {
	//		if (beamMIOut) {
	//			UMaterialInstanceConstant* beamMIC = (UMaterialInstanceConstant*)beamMIOut;
	//			beamMIC->SetScalarParameterValue(FName("bValidLocation"), hasLaserHit ? 1.f : 0.f);
	//		}
	//	}
	//}

	//ATrDevice_LaserTargeter_execUpdateTarget_Parms utParams;
	//utParams.hasHitSomething = hasLaserHit;
	//utParams.End = end;
	//TrDevice_LaserTargeter_UpdateTarget(that, &utParams, NULL, NULL);

	// Is it time to activate the call-in?
	if (callInData.IsTimeToActivate(that)) {
		ServerPerformCallIn(that, end, hitNormal);
		that->EndFire(that->CurrentFireMode);
		that->GotoState(that->m_PostFireState, NULL, NULL, NULL);
	}
}