#include "Mods.h"

static CustomProjectile *fired_proj = NULL;
static APawn *proj_instigator = NULL;

bool TrProj_ReplicatedEvent_POST(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	ATrProjectile *that = (ATrProjectile *)dwCallingObject;
	static FName particleSystemComponent = FName("ParticleSystemComponent0");

	if (proj_instigator && that->Instigator == proj_instigator)
	{
		auto it = g_config.proj_class_to_custom_proj.find((int) that->Class);
		if (it == g_config.proj_class_to_custom_proj.end() || !it->second)
			return false;
		if (!it->second->custom_ps)
			return false;
		that->ProjFlightTemplate = it->second->custom_ps;
		for (int i = that->Components.Count - 1; i >= 0; i--)
		{
			if (that->Components(i)->TemplateName == particleSystemComponent)
			{
				that->DetachComponent(that->Components(i));
				break;
			}
		}
		that->SpawnFlightEffects();
	}
	return false;
}

bool TrDev_WeaponFiring(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	ATrDevice *that = (ATrDevice *)dwCallingObject;

	if (that->ShouldRefire())
		proj_instigator = that->Instigator;
	return false;
}

struct DelayedProjectile
{
	ATrDevice *device;
	UClass *spawn_class;
	UClass *proj_class;
	APawn *instigator;
	FVector location;
	FRotator rotation;
	FName spawn_tag;
	float delay;
};

DelayedProjectile delayed_projs[50] = { 0 };

ATrProjectile *TrDev_ProjectileFire(ATrDevice *that)
{
	FVector RealStartLoc, TraceStart, HitLocation, HitNormal;
	// ATrProjectile *SpawnedProjectile;
	UClass *ProjectileClass;
	bool bTether, bSpawnedSimProjectile;
	ATrPlayerController *TrPC;

	that->IncrementFlashCount();
	ProjectileClass = that->GetProjectileClass();
	if (ProjectileClass)
		bTether = false;// ProjectileClass.default.bTether...
	if (that->Instigator)
		TrPC = (ATrPlayerController *)that->Instigator->Controller;
	if (that->WorldInfo->NetMode != 1 /* NM_DedicatedServer */ && TrPC)
	{
		if (TrPC->m_bAllowSimulatedProjectiles || that->WorldInfo->NetMode == 0 /* NM_Standalone */)
		{
			float ping = that->Instigator->PlayerReplicationInfo->ExactPing;
			if (ping <= 0.0)
				ping = (float) 0.001;
			for (int i = 0; i < 50; i++)
			{
				if (delayed_projs[i].delay <= 0.0)
				{
					delayed_projs[i].device = that;
					delayed_projs[i].spawn_class = g_config.useSmallBullets ? ProjectileClass : ATrProj_ClientTracer::StaticClass();
					delayed_projs[i].proj_class = g_config.useSmallBullets ? NULL : ProjectileClass;
					delayed_projs[i].instigator = that->Instigator;
					delayed_projs[i].location = that->GetClientSideProjectileFireStartLoc(FVector(0, 0, 0));
					delayed_projs[i].rotation = that->GetAdjustedAim(delayed_projs[i].location);
					delayed_projs[i].spawn_tag = that->Name;
					delayed_projs[i].delay = ping;
					break;
				}
			}
			bSpawnedSimProjectile = true;
			return NULL;
		}
	}
	return NULL;
}

void Weapon_FireAmmunition(ATrDevice *that)
{
	that->ConsumeAmmo(that->CurrentFireMode);
	that->PlayFiringSound();

	switch (that->WeaponFireTypes.Data[that->CurrentFireMode])
	{
	case 0: // EWFT_InstantHit
		that->InstantFire();
		break;
	case 1: // EWFT_Projectile
		TrDev_ProjectileFire(that);
		break;
	case 2: // EWFT_Custom
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

bool TrDev_WeaponConstantFiring_RefireCheckTimer_POST()
{
	if (fired_proj)
	{
		fired_proj->default_proj->ProjFlightTemplate = fired_proj->default_ps;
		fired_proj = NULL;
	}
	return false;
}

bool TrDev_WeaponConstantFiring_RefireCheckTimer(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	ATrDevice_ConstantFire *that = (ATrDevice_ConstantFire *)dwCallingObject;
	AUTPlayerController *pc;

	if (that->ShouldRefire()) {
		// Retrieve default object for the projectile that will be fired
		auto it = g_config.wep_id_to_custom_proj.find(that->DBWeaponId);
		if (it != g_config.wep_id_to_custom_proj.end() && it->second)
		{
			fired_proj = it->second;
			fired_proj->default_proj->ProjFlightTemplate = fired_proj->custom_ps;
			proj_instigator = that->Instigator;
		}

		TrDev_FireAmmunition(that);
		that->OnTickConstantFire();
		pc = (AUTPlayerController *)that->Instigator->Controller;
		if (pc && pc->Player && pc->Player->IsA(ULocalPlayer::StaticClass()) && that->CurrentFireMode < that->FireCameraAnim.Count && that->FireCameraAnim.Data[that->CurrentFireMode])
			pc->PlayCameraAnim(that->FireCameraAnim.Data[that->CurrentFireMode], that->GetZoomedState() > 1 ? pc->eventGetFOVAngle() / pc->DefaultFOV : 1.0f, 0.0f, 0.0f, 0.0f, 0, 0);
		TrDev_WeaponConstantFiring_RefireCheckTimer_POST();
		return true;
	}
	that->GotoState(that->m_PostFireState, FName(), 0, 0);
	if (!that->HasAnyAmmo())
	{
		if (that->WorldInfo->NetMode == 1 /* NM_DedicatedServer */ || that->WorldInfo->NetMode == 0 /* NM_Standalone */)
			that->WeaponPlaySound(that->m_DryFireSoundCue, 0.0f, false);
		if (that->m_DeviceAnimNode)
			that->m_DeviceAnimNode->PlayDryFire();
	}
	return true;
}

bool TrDev_WeaponConstantFiring_BeginState(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	ATrDevice_ConstantFire *that = (ATrDevice_ConstantFire *)dwCallingObject;

	TrDev_WeaponConstantFiring_RefireCheckTimer(0, dwCallingObject, NULL, NULL, NULL);
	that->TimeWeaponFiring(that->CurrentFireMode);
	that->OnStartConstantFire();
	if (that->m_bSoundLinkedWithState && !that->m_AudioComponentWeaponLoop->IsPlaying() && that->m_AudioComponentWeaponLoop->FadeOutTargetVolume != 0.0f)
		that->m_AudioComponentWeaponLoop->FadeIn(that->WeaponFireFadeTime, 1.0f);
	return true;
}

bool TrPC_PlayerTick(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	ATrPlayerController *that = (ATrPlayerController *)dwCallingObject;
	ATrPlayerController_eventPlayerTick_Parms *params = (ATrPlayerController_eventPlayerTick_Parms *) pParams;

	Utils::tr_pc = that;
	for (int i = 0; i < 50; i++)
	{
		DelayedProjectile &curr_proj = delayed_projs[i];

		if (curr_proj.delay > 0.0)
		{
			curr_proj.delay -= params->DeltaTime;
			if (curr_proj.delay <= 0.0)
			{
				ATrDevice *device = curr_proj.device;
				ATrProjectile *proj = (ATrProjectile *)that->Spawn(curr_proj.spawn_class, curr_proj.instigator, curr_proj.spawn_tag, curr_proj.location, curr_proj.rotation, NULL, 0);
				if (proj)
				{
					proj->m_bTether = false;
					proj->InitProjectile(Geom::rotationToVector(curr_proj.rotation), curr_proj.proj_class);
				}
			}
		}
	}
	return false;
}
