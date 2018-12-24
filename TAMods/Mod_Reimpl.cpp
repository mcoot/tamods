//#include "Mods.h"
//
//////////////////////////
//// Laser Targeter modifications
//// Used to re-enable call-ins
//////////////////////////
//
//// Cache for cooldown/buildup time for 
//struct _LaserTargetCacheInfo {
//	long long playerId = -1;
//	float lastInvCallInTime;
//	float invCallInEndTime;
//};
//
//static std::map<long long, _LaserTargetCacheInfo> firingLaserTargetTimes;
//
//static _LaserTargetCacheInfo ltCache_get(ATrDevice_LaserTargeter* that) {
//	if (!that->Owner || !that->Owner->IsA(APawn::StaticClass())) return _LaserTargetCacheInfo();
//
//	APawn* pawn = (APawn*)that->Owner;
//	if (!pawn->PlayerReplicationInfo) return _LaserTargetCacheInfo();
//	long long playerId = TAModsServer::netIdToLong(pawn->PlayerReplicationInfo->UniqueId);
//
//	_LaserTargetCacheInfo v;
//	if (firingLaserTargetTimes.find(playerId) != firingLaserTargetTimes.end()) {
//		v = firingLaserTargetTimes[playerId];
//	}
//	v.playerId = playerId;
//
//	return v;
//}
//
//static void ltCache_setFiring(ATrDevice_LaserTargeter* that) {
//	if (!that->WorldInfo || !that->Owner || !that->Owner->IsA(APawn::StaticClass())) return;
//
//	_LaserTargetCacheInfo v = ltCache_get(that);
//	
//	
//
//	firingLaserTargetTimes[v.playerId] = v;
//}
//
//static void ltCache_recordCallIn(ATrDevice_LaserTargeter* that) {
//	if (!that->WorldInfo || !that->Owner || !that->Owner->IsA(APawn::StaticClass())) return;
//
//	_LaserTargetCacheInfo v = ltCache_get(that);
//	v.lastTimeInvStationCalled = that->WorldInfo->TimeSeconds;
//	firingLaserTargetTimes[v.playerId] = v;
//}
//
//static void ltCache_stopFiring(ATrDevice_LaserTargeter* that) {
//	if (!that->Owner || !that->Owner->IsA(APawn::StaticClass())) return;
//
//	_LaserTargetCacheInfo v = ltCache_get(that);
//	v.isFiring = false;
//
//	firingLaserTargetTimes[v.playerId] = v;
//}
//
//static bool ltCache_isFiring(ATrDevice_LaserTargeter* that) {
//	if (!that->WorldInfo || !that->Owner || !that->Owner->IsA(APawn::StaticClass())) return false;
//	_LaserTargetCacheInfo v = ltCache_get(that);
//
//	return v.isFiring;
//}
//
//static float ltCache_buildUpTimePassed(ATrDevice_LaserTargeter* that) {
//	if (!that->WorldInfo || !that->Owner || !that->Owner->IsA(APawn::StaticClass())) return false;
//	_LaserTargetCacheInfo v = ltCache_get(that);
//
//	return that->WorldInfo->TimeSeconds - v.lastTimeFiringStarted;
//}
//
//static float ltCache_cooldownTimePassed(ATrDevice_LaserTargeter* that) {
//	if (!that->WorldInfo || !that->Owner || !that->Owner->IsA(APawn::StaticClass())) return false;
//	_LaserTargetCacheInfo v = ltCache_get(that);
//
//	return that->WorldInfo->TimeSeconds - v.lastTimeInvStationCalled;
//}
//
//static bool ltCache_canFire(ATrDevice_LaserTargeter* that, float buildUpSeconds, float cooldownSeconds) {
//	if (!that->WorldInfo || !that->Owner || !that->Owner->IsA(APawn::StaticClass())) return false;
//
//	bool doneBuildUp = ltCache_buildUpTimePassed(that) >= buildUpSeconds;
//	bool doneCooldown = ltCache_cooldownTimePassed(that) >= cooldownSeconds;
//
//	return ltCache_isFiring(that) && doneBuildUp && doneCooldown;
//}
//
//void ResetLaserTargetCallInCache() {
//	firingLaserTargetTimes.clear();
//}
//
//bool getTargetLocationAndNormal(ATrDevice_LaserTargeter* that, FVector& startLoc, FVector& targetLoc, FVector& targetLocNormal) {
//	FVector startTrace = that->InstantFireStartTrace();
//	FVector endTrace = that->InstantFireEndTrace(startTrace);
//
//	targetLocNormal = FVector(0, 0, 1);
//
//	TArray<FImpactInfo> impactList;
//
//	FImpactInfo testImpact = that->CalcWeaponFire(startTrace, endTrace, FVector(0, 0, 0), 0, &impactList);
//
//	if (that->NotEqual_VectorVector(testImpact.HitLocation, startTrace) || that->NotEqual_VectorVector(testImpact.HitLocation, endTrace)) {
//		targetLoc = testImpact.HitLocation;
//		targetLocNormal = testImpact.HitNormal;
//	}
//
//	startLoc = startTrace;
//
//	// TODO: Check validity of target location!!!
//	return testImpact.HitActor != NULL;
//}
//
//void TrDevice_LaserTargeter_OnStartConstantFire(ATrDevice_LaserTargeter* that, ATrDevice_LaserTargeter_execOnStartConstantFire_Parms* params, void* result, Hooks::CallInfo* callInfo) {
//	ltCache_setFiring(that);
//	that->OnStartConstantFire();
//}
//
//static float TrDevice_LaserTargeter_CalcHUDAimChargePercent(ATrDevice_LaserTargeter* that) {
//	Logger::log("Calculating aim charge percent for targeter!");
//	// Don't show call-in progress if not firing or on cooldown
//	if (ltCache_cooldownTimePassed(that) < g_gameBalanceTracker.getReplicatedSetting("InventoryCallInCooldownTime", 10.f)) {
//		return 0.f;
//	}
//
//	float buildUpPassed = ltCache_buildUpTimePassed(that);
//	float buildUpTime = g_gameBalanceTracker.getReplicatedSetting("InventoryCallInBuildUpTime", 2.f);
//	float progress =  buildUpPassed / buildUpTime;
//	Logger::log("Calculated aim charge percent for targeter: %f/%f = %f!", buildUpPassed, buildUpTime, progress);
//	return that->FClamp(progress, 0.f, 1.f);
//}
//
//void TrDevice_CalcHUDAimChargePercent(ATrDevice* that, ATrDevice_execCalcHUDAimChargePercent_Parms* params, float* result, Hooks::CallInfo callInfo) {
//	Logger::log("Calculating aim charge percent!");
//	*result = that->CalcHUDAimChargePercent();
//
//	if (that->IsA(ATrDevice_LaserTargeter::StaticClass())) {
//		*result = TrDevice_LaserTargeter_CalcHUDAimChargePercent((ATrDevice_LaserTargeter*)that);
//	}
//}
//
//void TrDevice_LaserTargeter_OnEndConstantFire(ATrDevice_LaserTargeter* that, ATrDevice_LaserTargeter_execOnEndConstantFire_Parms* params, void* result, Hooks::CallInfo* callInfo) {
//	if (!g_gameBalanceTracker.getReplicatedSetting("EnableInventoryCallIn", false)) {
//		// Call-In logic not required
//		that->OnEndConstantFire();
//		ltCache_stopFiring(that);
//		return;
//	}
//
//	float buildUpTime = g_gameBalanceTracker.getReplicatedSetting("InventoryCallInBuildUpTime", 2.f);
//	float cooldownTime = g_gameBalanceTracker.getReplicatedSetting("InventoryCallInCooldownTime", 10.f);
//
//	bool canFireCallIn = ltCache_canFire(that, buildUpTime, cooldownTime);
//	ltCache_stopFiring(that);
//
//	if (!canFireCallIn) {
//		that->OnEndConstantFire();
//		return;
//	}
//
//	// Call in an inventory station
//	ltCache_recordCallIn(that);
//
//	static ATrCallIn_SupportInventory* callIn = (ATrCallIn_SupportInventory*)that->Spawn(ATrCallIn_SupportInventory::StaticClass(), that->Owner, FName(), FVector(), FRotator(), NULL, false);
//	callIn->Initialize(0, 0, 0);
//
//	FVector laserStart;
//	FVector laserEnd;
//	FVector hitNormal;
//	bool hasLaserHit = getTargetLocationAndNormal(that, laserStart, laserEnd, hitNormal);
//	that->UpdateTarget(hasLaserHit, laserEnd);
//
//	callIn->FireCompletedCallIn(1, laserEnd, hitNormal);
//
//	that->OnEndConstantFire();
//}