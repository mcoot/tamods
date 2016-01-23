#include "Mods.h"

struct DelayedProjectile
{
	ATrDevice *device;
	UClass *spawn_class;
	UClass *init_class;
	APawn *instigator;
	FVector location;
	FRotator rotation;
	FVector owner_velocity;
	FName spawn_tag;
	float delay;
	UParticleSystem *proj_flight_template;
};

DelayedProjectile delayed_projs[50] = { 0 };

void MC_KillProjectiles()
{
	for (int i = 0; i < 50; i++)
	{
		DelayedProjectile &curr_proj = delayed_projs[i];

		curr_proj.delay = 0.0f;
	}
}

static void PostInitProjectile(ATrProjectile *that, const FVector &direction, float speed = 0.0f)
{
	if (speed == 0.0f)
		that->Speed = that->MaxSpeed;
	else
		that->Speed = min(speed, that->MaxSpeed);
	that->Velocity = Geom::scale(direction, that->Speed);
	that->Velocity.Z += that->TossZ;
	if (that->m_bTether && that->Role == ROLE_Authority && that->WorldInfo->NetMode == NM_Client)
		that->Velocity = Geom::scale(Geom::normal(that->Velocity), that->m_fClientSimulatedSpeed);
	that->m_vAccelDirection = Geom::normal(that->Velocity);
	that->ApplyInheritance(direction);
	that->Acceleration = Geom::scale(that->m_vAccelDirection, that->AccelRate);
}

ATrProjectile *TrDev_ProjectileFire(ATrDevice *that)
{
	FVector RealStartLoc, TraceStart, HitLocation, HitNormal;
	FRotator SpawnRotation;
	ATrProjectile *SpawnedProjectile;
	UClass *ProjectileClass, *SpawnClass, *InitClass;
	bool bTether = false;
	bool bSpawnedSimProjectile = false;
	ATrPlayerController *TrPC;
	FTraceHitInfo HitInfo;

	that->IncrementFlashCount();
	ProjectileClass = that->GetProjectileClass();
	SpawnClass = g_config.useSmallBullets ? ProjectileClass : ATrProj_ClientTracer::StaticClass();
	InitClass = g_config.useSmallBullets ? NULL : ProjectileClass;
	if (ProjectileClass)
		bTether = ((ATrProjectile *)ProjectileClass->Default)->m_bTether;
	if (that->Instigator)
		TrPC = (ATrPlayerController *)that->Instigator->Controller;
	if (that->WorldInfo->NetMode != NM_DedicatedServer && ((ATrProjectile *) ProjectileClass->Default)->m_bSimulateAutonomousProjectiles && TrPC)
	{
		if (g_config.useMagicChain || TrPC->m_bAllowSimulatedProjectiles || that->WorldInfo->NetMode == NM_Standalone)
		{
			RealStartLoc = that->GetClientSideProjectileFireStartLoc(FVector());
			TraceStart = that->GetPhysicalFireStartLoc(FVector());

			if (g_config.centerBulletSpawn || that->Trace(RealStartLoc, TraceStart, true, FVector(0.0f, 0.0f, 0.0f), CONST_TRACEFLAG_Bullet, &HitLocation, &HitNormal, &HitInfo))
				RealStartLoc = TraceStart;

			SpawnRotation = that->GetAdjustedAim(RealStartLoc);

			if (g_config.useMagicChain)
			{
				float ping = that->Instigator->PlayerReplicationInfo->ExactPing;
				if (ping <= 0.0)
					ping = (float) 0.001;
				for (int i = 0; i < 50; i++)
				{
					if (delayed_projs[i].delay <= 0.0)
					{
						delayed_projs[i].device = that;
						delayed_projs[i].spawn_class = SpawnClass;
						delayed_projs[i].init_class = InitClass;
						delayed_projs[i].instigator = that->Instigator;
						delayed_projs[i].location = RealStartLoc;
						delayed_projs[i].rotation = SpawnRotation;
						delayed_projs[i].owner_velocity = that->Instigator->Velocity;
						delayed_projs[i].spawn_tag = that->Name;
						delayed_projs[i].delay = ping * 0.5f * g_config.bulletPingMultiplier + g_config.bulletSpawnDelay;
						delayed_projs[i].proj_flight_template = NULL;
						break;
					}
				}
			}
			else
			{
				SpawnedProjectile = (ATrProjectile *)that->Spawn(SpawnClass, that->Instigator, that->Name, RealStartLoc, SpawnRotation, NULL, 0);
				if (SpawnedProjectile)
				{
					FVector rotation = Geom::rotationToVector(SpawnRotation);
					if (SpawnClass == ATrProj_ClientTracer::StaticClass())
						((ATrProj_ClientTracer *)SpawnedProjectile)->InitProjectile(rotation, InitClass);
					else
						SpawnedProjectile->InitProjectile(rotation, InitClass);
				}
			}
			bSpawnedSimProjectile = true;
		}
	}
	if (that->Role == ROLE_Authority || bTether)
	{
		RealStartLoc = that->GetPhysicalFireStartLoc(FVector());
		SpawnedProjectile = (ATrProjectile *) that->Spawn(SpawnClass, that->Instigator, that->Name, RealStartLoc, FRotator(), NULL, 0);
		if (SpawnedProjectile && !SpawnedProjectile->bDeleteMe)
		{
			SpawnedProjectile->InitProjectile(Geom::rotationToVector(that->GetAdjustedAim(RealStartLoc)), InitClass);
			SpawnedProjectile->m_SpawnedEquipPoint = that->r_eEquipAt;
			if (that->WorldInfo->NetMode != NM_DedicatedServer && ((ATrProjectile *)ProjectileClass->Default)->m_bSimulateAutonomousProjectiles && bSpawnedSimProjectile)
				SpawnedProjectile->SetHidden(g_config.bulletSpawnDelay == 0.01f);
			if (bTether && that->Instigator)
			{
				SpawnedProjectile->r_nTetherId = (that->DBWeaponId << 4) + that->m_nTetherCounter;
				that->m_nTetherCounter = (that->m_nTetherCounter + 1) % 100;
				if (that->WorldInfo->NetMode == NM_Client && SpawnedProjectile->Role == ROLE_Authority && TrPC)
				{
					TrPC->AddProjectileToTetherList(SpawnedProjectile);
					SpawnedProjectile->SetTickGroup(2);
				}
			}
			that->DestroyOldestProjectileOverLimit(SpawnedProjectile);
		}
		return SpawnedProjectile;
	}
	return NULL;
}

void Weapon_FireAmmunition(ATrDevice *that)
{
	that->ConsumeAmmo(that->CurrentFireMode);
	if (that->IsA(ATrDevice_LightAssaultRifle::StaticClass()))
	{
		if (((ATrDevice_LightAssaultRifle *)that)->m_nShotsSoFar == 0)
			that->PlayFiringSound();
	}
	else
		that->PlayFiringSound();

	switch (that->WeaponFireTypes.Data[that->CurrentFireMode])
	{
	case EWFT_InstantHit:
		that->InstantFire();
		break;
	case EWFT_Projectile:
		TrDev_ProjectileFire(that);
		break;
	case EWFT_Custom:
		that->CustomFire();
		break;
	}
	if (that->Instigator && that->Instigator->Controller->IsA(AAIController::StaticClass()))
		((AAIController *)that->Instigator->Controller)->NotifyWeaponFired(that, that->CurrentFireMode);
}

void UTWeapon_FireAmmunition(ATrDevice *that)
{
	static FName firedWeapon("FiredWeapon");

	if (that->CurrentFireMode >= that->bZoomedFireMode.Count || that->bZoomedFireMode.Data[that->CurrentFireMode] == 0)
	{
		Weapon_FireAmmunition(that);
		if (that->Instigator && that->Instigator->IsA(AUTPawn::StaticClass()))
			((AUTPawn *)that->Instigator)->DeactivateSpawnProtection();
		((AUTInventoryManager *)that->InvManager)->OwnerEvent(firedWeapon);
	}
}

void TrDev_FireAmmunition(ATrDevice *that)
{
	ATrPawn *P;
	ATrPlayerController *PC;
	FVector StartTrace, EndTrace, AimVector;
	bool bKickedBack;

	if (!that->ReplicateAmmoOnWeaponFire())
		that->r_bReadyToFire = false;
	if (!that->m_bAllowHoldDownFire)
		that->m_bWantsToFire = false;
	UTWeapon_FireAmmunition(that);
	that->PlayFireAnimation(0);
	that->eventCauseMuzzleFlash();
	that->ShakeView();
	that->PayAccuracyForShot();
	that->eventUpdateShotsFired(0);
	bKickedBack = that->AddKickback();
	if ((P = (ATrPawn *)that->Instigator))
	{
		PC = (ATrPlayerController *)P->Controller;
		if (bKickedBack && PC && that == P->Weapon)
		{
			StartTrace = P->GetWeaponStartTraceLocation(that);
			AimVector = Geom::rotationToVector(that->GetAimForCamera(StartTrace));
			EndTrace = Geom::add(StartTrace, Geom::scale(AimVector, that->GetWeaponRange()));
			
			FRotator rot = Geom::sub(Geom::vectorToRotation(Geom::normal(Geom::sub(EndTrace, P->GetPawnViewLocation()))), P->eventGetViewRotation());
			PC->OnKickback(rot, that->m_fKickbackBlendOutTime);
		}
	}
}

void TrDev_LAR_FireAmmunition(ATrDevice_LightAssaultRifle *that)
{
	if (that->m_nShotsSoFar < that->m_nShotBurstCount)
	{
		TrDev_FireAmmunition(that);
		++that->m_nShotsSoFar;
	}
	else
		that->FireAmmunition();
}

bool TrDev_WeaponConstantFiring_RefireCheckTimer(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	ATrDevice_ConstantFire *that = (ATrDevice_ConstantFire *)dwCallingObject;
	AUTPlayerController *pc = (AUTPlayerController *)that->Instigator->Controller;

	if (pc && pc->WorldInfo->NetMode == NM_Standalone || that->IsA(ATrDevice_RepairTool::StaticClass()))
		return false;

	Hooks::lock();
	if (that->ShouldRefire()) {
		if (that->IsA(ATrDevice_LightAssaultRifle::StaticClass()))
			TrDev_LAR_FireAmmunition((ATrDevice_LightAssaultRifle *) that);
		else
			TrDev_FireAmmunition(that);
		that->OnTickConstantFire();
		if (pc && pc->Player && pc->Player->IsA(ULocalPlayer::StaticClass()) && that->CurrentFireMode < that->FireCameraAnim.Count && that->FireCameraAnim.Data[that->CurrentFireMode])
			pc->PlayCameraAnim(that->FireCameraAnim.Data[that->CurrentFireMode], that->GetZoomedState() > 1 ? pc->eventGetFOVAngle() / pc->DefaultFOV : 1.0f, 0.0f, 0.0f, 0.0f, 0, 0);
		Hooks::unlock();
		return true;
	}
	that->GotoState(that->m_PostFireState, FName(), 0, 0);
	if (!that->HasAnyAmmo())
	{
		if (that->WorldInfo->NetMode == NM_DedicatedServer || that->WorldInfo->NetMode == NM_Standalone)
			that->WeaponPlaySound(that->m_DryFireSoundCue, 0.0f, false);
		if (that->m_DeviceAnimNode)
			that->m_DeviceAnimNode->PlayDryFire();
	}
	Hooks::unlock();
	return true;
}

bool TrDev_WeaponConstantFiring_BeginState(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	ATrDevice_ConstantFire *that = (ATrDevice_ConstantFire *)dwCallingObject;
	AUTPlayerController *pc = (AUTPlayerController *)that->Instigator->Controller;

	if (pc && pc->WorldInfo->NetMode == NM_Standalone || that->IsA(ATrDevice_RepairTool::StaticClass()))
		return false;

	TrDev_WeaponConstantFiring_RefireCheckTimer(0, dwCallingObject, NULL, NULL, NULL);
	Hooks::lock();
	that->TimeWeaponFiring(that->CurrentFireMode);
	that->OnStartConstantFire();
	if (that->m_bSoundLinkedWithState && !that->m_AudioComponentWeaponLoop->IsPlaying() && that->m_AudioComponentWeaponLoop->FadeOutTargetVolume != 0.0f)
		that->m_AudioComponentWeaponLoop->FadeIn(that->WeaponFireFadeTime, 1.0f);
	Hooks::unlock();
	return true;
}

bool TrPC_PlayerTick(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	if (dwCallingObject->IsA(ATrPlayerController_Training::StaticClass()))
		return false;

	ATrPlayerController *that = (ATrPlayerController *)dwCallingObject;
	ATrPlayerController_eventPlayerTick_Parms *params = (ATrPlayerController_eventPlayerTick_Parms *) pParams;

	Hooks::lock();

	// Mouse sensitivity
	if (!g_config.useFOVScaling)
	{
		that->PlayerInput->bEnableFOVScaling = 0;

		if (that->DesiredFOV == 40.0f)
			that->PlayerInput->MouseSensitivity = that->FInterpEaseOut(that->PlayerInput->MouseSensitivity, g_config.sensZoom, 40.0f / that->FOVAngle, 0.4f);
		else if (that->DesiredFOV == 20.0f)
			that->PlayerInput->MouseSensitivity = that->FInterpEaseOut(that->PlayerInput->MouseSensitivity, g_config.sensZoooom, 20.0f / that->FOVAngle, 0.4f);
		else
			that->PlayerInput->MouseSensitivity = g_config.sens;
	}
	else
		that->PlayerInput->bEnableFOVScaling = 1;

	Utils::tr_pc = that;

	routeTickRecord(that);
	routeTickReplay(params->DeltaTime);

	if (g_config.useMagicChain)
		that->m_bAllowSimulatedProjectiles = true;
	for (int i = 0; i < 50; i++)
	{
		DelayedProjectile &curr_proj = delayed_projs[i];

		if (curr_proj.delay > 0.0)
		{
			curr_proj.delay -= params->DeltaTime;
			if (curr_proj.delay <= 0.0)
			{
				ATrProjectile *default_proj = (ATrProjectile *)(curr_proj.init_class ? curr_proj.init_class : curr_proj.spawn_class)->Default;
				UParticleSystem *spawn_ps, *init_ps;
				FVector loc = curr_proj.location;
				FVector dir = Geom::rotationToVector(curr_proj.rotation);
				float delay = -curr_proj.delay + g_config.bulletSpawnDelay;
				float dist = 0;
				float speed = g_config.useSmallBullets ? default_proj->MaxSpeed : 1.0f;

				FVector Velocity = Geom::mult(dir, speed);
				Velocity.Z += default_proj->TossZ;
				FVector m_vAccelDirection = Geom::normal(Velocity);

				FVector OwnerVelocity = curr_proj.owner_velocity;
				float ForwardPct = min(Geom::dot(Geom::normal(OwnerVelocity), Geom::normal(dir)), default_proj->m_fMaxProjInheritPct);
				float InheritPct = max(default_proj->m_fProjInheritVelocityPct, ForwardPct);
				FVector InheritedVelocity = Geom::mult(OwnerVelocity, InheritPct);

				Velocity = Geom::add(Velocity, InheritedVelocity);

				if (g_config.useSmallBullets)
				{
					dist = default_proj->MaxSpeed * delay;
					speed = default_proj->MaxSpeed;
				}
				else
				{
					float v0 = speed;				// Initial speed
					float vmax = default_proj->MaxSpeed;
					float a = 100000.0f;			// default_proj->AccelRate;
					float tmax = (vmax - v0) / a;	// Time before speed reaches MaxSpeed

					if (delay < tmax)
					{
						// d(x) = v0*x + (a/2)x²
						dist = v0 * delay + a * 0.5f * delay * delay;
						speed = v0 + delay * a;
					}
					else
					{
						dist = v0 * tmax + a * 0.5f * tmax * tmax;
						dist += (delay - tmax) * vmax;
						speed = vmax;
					}
				}
				loc = Geom::add(loc, Geom::mult(InheritedVelocity, delay));
				loc = Geom::add(loc, Geom::mult(m_vAccelDirection, dist));

				if (curr_proj.proj_flight_template)
				{
					spawn_ps = ((ATrProjectile *)curr_proj.spawn_class->Default)->ProjFlightTemplate;
					((ATrProjectile *)curr_proj.spawn_class->Default)->ProjFlightTemplate = curr_proj.proj_flight_template;
					if (curr_proj.init_class)
					{
						init_ps = ((ATrProjectile *)curr_proj.init_class->Default)->ProjFlightTemplate;
						((ATrProjectile *)curr_proj.init_class->Default)->ProjFlightTemplate = curr_proj.proj_flight_template;
					}
					else
						init_ps = NULL;
				}
				ATrProjectile *proj = (ATrProjectile *)that->Spawn(curr_proj.spawn_class, curr_proj.instigator, curr_proj.spawn_tag, loc, curr_proj.rotation, NULL, 0);
				if (proj)
				{
					if (curr_proj.spawn_class == ATrProj_ClientTracer::StaticClass())
						((ATrProj_ClientTracer *)proj)->InitProjectile(dir, curr_proj.init_class);
					else
						proj->InitProjectile(dir, curr_proj.init_class);
					PostInitProjectile(proj, dir, speed);
				}
				if (curr_proj.proj_flight_template)
				{
					((ATrProjectile *)curr_proj.spawn_class->Default)->ProjFlightTemplate = spawn_ps;
					if (curr_proj.init_class)
						((ATrProjectile *)curr_proj.init_class->Default)->ProjFlightTemplate = init_ps;
				}
			}
		}
	}
	Hooks::unlock();
	return false;
}
