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

// The length of the extent box use to check for collisions.
float collisionExtentUnits = 100;

// The following explanation was for the planar trace version. Some specifics
// are not relevant. The size of each individual extent surface. If this length
// is 10 times smaller than the length of the extent box then you are
// essentially using 10*10=100 extent traces. Diving by 4 results in 16 traces,
// by is 25 traces, etc. 10 is probably overkill if the extent length is small
// but performace needs to be tested.

// Since we're not using planar tracing but line tracing then this value is
// basically the distance between neighbouring line traces.
float subCollisionExtentUnits = collisionExtentUnits / 7;

// The length of the extent box used to search for neighbouring inventories.
// Basically the same thing as collisionExtentUnits.
// Obviously this cannot differentiate between enemy or friendly inventories.
float nearbyInventoryExtentUnits = 700;

// Same thing as subCollisionExtentUnits but for nearbyInventoryExtentUnits.
float subNearbyInventoryExtentUnits = nearbyInventoryExtentUnits / 7;

// Any terrain with surface normal angle above this wil be rejected (too steep).
float angle_terrain_max = 70;

// Any mesh with surface normal angle above this wil be rejected (too steep).
// Basically for stuff around the map like pillars.
float angle_mesh_max = 40;

// Check that the surface normal angle is within our set bounds.
// Also have to check what exactly we hit in order to check the angle.
bool TraceNormalAngleCheck(AActor* HitActor, FVector HitNormal) {
	float angle = (std::acos(HitNormal.Z / Geom::distance3D(FVector(), HitNormal))) * CONST_RadToDeg;
	char* name = HitActor->GetName();
	bool isTerrain = strncmp(name, "Terrain", 7) == 0;
	bool isMesh = strncmp(name, "StaticMes", 8) == 0;
	bool isWorldInfo = strncmp(name, "WorldInfo", 9) == 0;
	bool res = (isTerrain && angle < angle_terrain_max) || ((isMesh || isWorldInfo) && angle < angle_mesh_max);
	return res;
	// If we didn't hit terrain, mesh or worldinfo then it's very probable
	// the inventory can't be placed at where ever actor was hit.
}

// Basically a normal non-zero extent trace.
// This checks if any actor is hit. If so, checks if its terrain or not.
// If !checkForInvo then we're probably doing the collision check, where only
// Terrain is valid to collide with. If checkForInvo then we're obviously
// checking for nearby inventories. Return true -> Valid position. Return false
// -> Invalid position.
bool LineTrace(FVector end, FVector start, bool bTraceActors, FVector extent, int bExtraTraceFlags, FVector* HitLocation, FVector* HitNormal, FTraceHitInfo* HitInfo, AActor* a, bool checkForInvo = false) {
	HitInfo = NULL;
	AActor* hitActor = a->Trace(end, start, 1, extent, 0, HitLocation, HitNormal, HitInfo);
	if (hitActor) {
		char* name = hitActor->GetName();
		if (!checkForInvo) {
			if (strncmp(name, "Terrain", 7) == 0)  // Hit terrain.
				return true;
			return false;  // Hit something but it wasn't terrain.
		}
		else {
			if (strncmp(name, "TrInven", 7) == 0)  // Hit Invo.
				return false;
			if (strncmp(name, "TrCallIn", 8) == 0)  // Hit Invo.
				return false;
			return true;  // Didn't hit Invo.
		}
	}

	// Some sort of check for Level stuff, if trace returns null but still hit
	// something. Probably broken but might be useful for future things.
	if (!hitActor && HitInfo) {
		// return false;
	}

	// Didn't hit anything at all, so this location is safe.
	// Doesn't really stop spawning invos on the edge of a surface...
	// Perhaps first check what mesh we're aiming at? Hmmm.
	return true;
}

// This calls the line trace by using math, division and loops.
// This has lines from the air all the way to the ground (wherever that may be)
// for a given X-Y coordinate. The zoffset is the literally the Z offset of the
// plane from the hitlocation. We should keep it to around 1. Delta is just the
// length of subNearbyInventoryExtentUnits.

bool SplitLineTrace(FVector end, FVector start, bool bTraceActors, FVector extent, int bExtraTraceFlags, FVector* HitLocation, FVector* HitNormal, FTraceHitInfo* HitInfo, AActor* a, float delta, float zoffset, bool checkForInvo = false) {
	FVector hitLocation = *HitLocation;  // We need to keep the original
										 // hitlocation so we can use it values.
	FVector newHitLocation;              // The pointer to this vector will be used for
										 // further tracing. Its value is not actually useful.
	bool res = true;
	float pos_z = hitLocation.Z + zoffset;  // Set the end trace Z position to be like a lot lower than
											// where we originally hit. So zoffset is a large negative.
	FVector splitExtent = { delta, delta, 0 };
	for (float y = hitLocation.Y - extent.Y + delta / 2; y < hitLocation.Y + extent.Y; y += delta) {
		float pos_y = y;
		for (float x = hitLocation.X - extent.X + delta / 2; x < hitLocation.X + extent.X; x += delta) {
			float pos_x = x;
			FVector startpos = { pos_x, pos_y, start.Z };  // The start position for tracing must have
														 // the same X-Y as the end position, but with
														 // the original Z value of the start vector.
			FVector pos = { pos_x, pos_y, pos_z };         // End location
			bool r = LineTrace(pos, startpos, 1, splitExtent, 0, &newHitLocation, HitNormal, HitInfo, a, checkForInvo);
			if (!r) {  // Hit something that wasn't terrain OR an inventory was hit,
					   // so early exit.
				return false;
			}
			res = res && r;
		}
	}
	return res;
}

static bool IsValidTargetLocation(ATrDevice_LaserTargeter* that, FVector currentTarget, FVector prevTarget, AActor* hitTarget) {
	// Unfortunately the original version of this was native, and doesn't exist in OOTB :(
	// So I've reimplemented it from scratch with traces yaaaaay

	// Rules:
	// 1) Nowhere is valid in pre-round
	// 2) Nowhere is valid if the player lacks enough credits
	// 3) Must not collide with flag, other inv stations etc.
	// 4) Must not be underneath any world geometry (e.g. inside a base)

	// Check we aren't in preround
	if (!that->WorldInfo || !that->WorldInfo->GRI) return false;
	if (((ATrGameReplicationInfo*)that->WorldInfo->GRI)->bWarmupRound) {
		return false;
	}
	if (!Utils::tr_pc) return false;
	int callInCost = g_gameBalanceTracker.getReplicatedSetting("InventoryCallInCost", 0);
	if (callInCost > 0 && Utils::tr_pc->r_nCurrentCredits < callInCost) {
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

	// Find where the actual final location is. Maybe its equivalent to
	// currentTarget? Trace again just to make sure.
	FVector landLocationBottomed = { landLocation.X, landLocation.Y, landLocation.Z - 1000 };
	hitActor = that->Trace(landLocationBottomed, podFallStart, 1, FVector(), 0, &hitLocation, &hitNormal, &hitInfo);
	if (hitActor) {  // What did we hit? Terrain, WorldInfo, Mesh etc?
		if (TraceNormalAngleCheck(hitActor,
			hitNormal)) {  // Is the surface normal angle within our bounds?
			bool res = true;
			// First lets check for neighbouring inventories.
			res = res && SplitLineTrace(hitLocation, podFallStart, 1, { nearbyInventoryExtentUnits, nearbyInventoryExtentUnits, 0 }, 0, &hitLocation, &hitNormal, &hitInfo, that, subNearbyInventoryExtentUnits, -10000, true);
			if (!res)
				return false;  // Early exit because an inventory is too close to the
							   // target location.
			// Now lets do the collision checking.
			res = res && SplitLineTrace(hitLocation, podFallStart, 1, { collisionExtentUnits, collisionExtentUnits, 0 }, 0, &hitLocation, &hitNormal, &hitInfo, that, subCollisionExtentUnits, 1, false);
			return res;
		}
		// The surface normal of the hitactor was too high.
		return false;
	}
	// No hit actor found, so probably looking at the sky.
	return false;
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
		callInData.RecordActivation(that);
		if (callIn->FireCompletedCallIn(1, endLocation, hitNormal)) {
			CallInConfirmed(that);
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