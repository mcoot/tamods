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

struct DelayedProjectile {
	ATrDevice *device;
	float delaytime;
	FVector direction;
	UClass* SpawnClass;
	AActor* SpawnOwner;
	FName SpawnTag;
	FVector SpawnLocation;
	FRotator SpawnRotation;
};

DelayedProjectile MyDelayedProjectiles[50] = { 0 };

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
	that->AUTWeapon::FireAmmunition();
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

bool TrDev_WeaponConstantFiring(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
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

		/*
		FVector a; a.X = 0; a.Y = 0; a.Z = 0;
		//FVector StartLoc = that->GetClientSideProjectileFireStartLoc(a);
		FVector StartLoc = that->GetPhysicalFireStartLoc(a);
		FRotator adjusted = that->GetAdjustedAim(StartLoc);
		APawn *myinstigator = that->Instigator;

		float pingtime = myinstigator->PlayerReplicationInfo->ExactPing;
		if (pingtime <= 0.0)
			pingtime = (float) 0.001;
		FVector Mydir = Geom::rotationToVector(adjusted);
		for (int i = 0; i < 50; i++)
		{
			if (MyDelayedProjectiles[i].delaytime <= 0.0)
			{
				MyDelayedProjectiles[i].delaytime = pingtime;
				MyDelayedProjectiles[i].SpawnClass = ATrProj_NJ4SMG::StaticClass(); //mydevice->WeaponProjectiles.Data[0];
				MyDelayedProjectiles[i].direction = Mydir;
				MyDelayedProjectiles[i].SpawnLocation = StartLoc;
				MyDelayedProjectiles[i].SpawnOwner = myinstigator;
				MyDelayedProjectiles[i].SpawnRotation = adjusted;
				MyDelayedProjectiles[i].SpawnTag = that->Name;

				MyDelayedProjectiles[i].device = that;

				return true;
			}
		}
		*/
		return true;
	}
	return false;
}

bool TrPC_PlayerTick(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	static int count = 0;
	ATrPlayerController *that = (ATrPlayerController *)dwCallingObject;
	ATrPlayerController_eventPlayerTick_Parms *Tick_Params = (ATrPlayerController_eventPlayerTick_Parms *) pParams;

	Utils::tr_pc = that;
	for (int i = 0; i < 50; i++)
	{
		if (MyDelayedProjectiles[i].delaytime > 0.0)
		{
			MyDelayedProjectiles[i].delaytime -= Tick_Params->DeltaTime;
			if (MyDelayedProjectiles[i].delaytime <= 0.0)
			{
				MyDelayedProjectiles[i].delaytime = 0;

				ATrDevice *mydevice = (ATrDevice *)MyDelayedProjectiles[i].device;
				const FVector &dir = MyDelayedProjectiles[i].direction;
				FVector loc = MyDelayedProjectiles[i].SpawnLocation;
				float speed = 21000.0f * that->PlayerReplicationInfo->ExactPing;
				//FVector spawnloc(loc.X + dir.X * speed, loc.Y + dir.Y * speed, loc.Z + dir.Z * speed);
				FVector spawnloc(loc.X, loc.Y, loc.Z);
				ATrProjectile *myproj = (ATrProjectile *)mydevice->Spawn(MyDelayedProjectiles[i].SpawnClass, MyDelayedProjectiles[i].SpawnOwner, MyDelayedProjectiles[i].SpawnTag, spawnloc, MyDelayedProjectiles[i].SpawnRotation, 0, 0);
				if (myproj) {
					//MyDelayedProjectiles[i].proj->InitProjectile(MyDelayedProjectiles[i].direction, MyDelayedProjectiles[i].projclass);
					myproj->m_bTether = 0;
					myproj->InitProjectile(MyDelayedProjectiles[i].direction, 0);
				}
			}
		}
	}
	return false;
}

bool TrDev_WeaponConstantFiring_POST(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	if (fired_proj)
	{
		fired_proj->default_proj->ProjFlightTemplate = fired_proj->default_ps;
		fired_proj = NULL;
	}
	return false;
}
