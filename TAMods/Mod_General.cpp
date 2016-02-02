#include "Mods.h"
#include "NameCryptor.h"

bool TrPC_InitInputSystem(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	Utils::tr_pc = (ATrPlayerController *)dwCallingObject;

	return false;
}

bool TrGVC_PostRender(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	Utils::tr_gvc = (UTrGameViewportClient *)dwCallingObject;

	return false;
}

struct Modifier
{
	struct Key
	{
		FName key;
		bool status;

		Key(const std::string &pname)
			: key(pname.c_str()), status(false)
		{}
		void update(FName &pkey, EInputEvent evt)
		{
			if (key == pkey && evt < 2 /* Pressed or released */)
				status = !evt;
		}
	};

	Key left;
	Key right;

	Modifier(const std::string &pname)
		: left("Left" + pname), right("Right" + pname)
	{ }
	void update(FName &pkey, EInputEvent evt)
	{
		left.update(pkey, evt);
		right.update(pkey, evt);
	}
	bool isPressed()
	{
		return left.status || right.status;
	}
};

// Lua keybindings
bool TrChatConsole_InputKey(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	static Modifier mods[3] = { Modifier("Control"), Modifier("Shift"), Modifier("Alt") };
	UTrChatConsole *that = (UTrChatConsole *)dwCallingObject;
	UTrChatConsole_execInputKey_Parms *params = (UTrChatConsole_execInputKey_Parms *)pParams;

	if (that->m_TrPC)
		Utils::tr_pc = that->m_TrPC;

	for (int i = 0; i < 3; i++)
		mods[i].update(params->Key, (EInputEvent)params->Event);

	// Big hook "onInputevent", intercept everything
	if (g_config.onInputEvent)
	{
		try
		{
			(*g_config.onInputEvent)(std::string(params->Key.GetName()), (int)params->Event, mods[0].isPressed(), mods[1].isPressed(), mods[2].isPressed());
		}
		catch (const LuaException &e)
		{
			Utils::console("LuaException: %s", e.what());
		}
	}

	// Individual hooks
	auto &it = g_config.lua_keybinds.find(params->Key.Index);
	if (it == g_config.lua_keybinds.end())
		return false;
	if (it->second[params->Event] == NULL)
		return false;
	try
	{
		(*it->second[params->Event])(std::string(params->Key.GetName()), (int)params->Event, mods[0].isPressed(), mods[1].isPressed(), mods[2].isPressed());
	}
	catch (const LuaException &e)
	{
		Utils::console("LuaException: %s", e.what());
	}
	return false;
}

bool TrPC_Dead_BeginState(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	ATrPlayerController *that = (ATrPlayerController *)dwCallingObject;

	if (!dwCallingObject->IsA(ATrPlayerController_Training::StaticClass()))
	{
		if (that->WorldInfo && g_config.stopwatchRunning && g_config.stopwatchStopOnDeath)
		{
			g_config.stopwatchDisplayTime("Stopped - ", that->WorldInfo->RealTimeSeconds);
			g_config.stopwatchPrintSummary();
			g_config.stopwatchRunning = 0;
		}
		routeStopRec();
	}

	if ((g_config.routeBotReplay && that->IsA(ATrPlayerController_Training::StaticClass()))
		|| (!g_config.routeBotReplay && !that->IsA(ATrPlayerController_Training::StaticClass())))
		routeStopReplay();

	return false;
}

bool TrPC_Suicide(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	ATrPlayerController *that = (ATrPlayerController *)dwCallingObject;
	
	if (that->WorldInfo && that->WorldInfo->NetMode == NM_Standalone)
	{
		that->m_bLastDeathWasUserSuicide = 0;
		that->m_fLastSuicideTimestamp = 0.0f;
	}
	return false;
}

// Base turrets
bool TrDeployable_FinalizeDeployment(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	if (!g_config.disableBaseTurrets)
		return true;

	ATrBaseTurret_BloodEagle *that = (ATrBaseTurret_BloodEagle *)dwCallingObject;

	if (that->WorldInfo && that->WorldInfo->NetMode == NM_Standalone)
	{
		if (dwCallingObject->IsA(ATrBaseTurret_BloodEagle::StaticClass()))
		{
			that->m_bEnabled = 0;
		}
		else if (dwCallingObject->IsA(ATrBaseTurret_DiamondSword::StaticClass()))
		{
			ATrBaseTurret_DiamondSword *that = (ATrBaseTurret_DiamondSword *)dwCallingObject;
			that->m_bEnabled = 0;
		}
	}
	return true;
}

// Generators
bool TrPowerGenerator_PostBeginPlay(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	if (!g_config.disablePower)
		return true;

	ATrPowerGenerator *gen = (ATrPowerGenerator *)dwCallingObject;

	if (gen->WorldInfo && gen->WorldInfo->NetMode == NM_Standalone)
	{
		gen->UpdateGeneratorPower(0);

		// Restore power for all stations and turrets
		for (int i = 0; i < gen->m_PoweredObjectives.Count; i++)
		{
			if (gen->m_PoweredObjectives.Data[i]->IsA(ATrStation::StaticClass()))
				((ATrStation *)gen->m_PoweredObjectives.Data[i])->SetPowered(1);
			else if (gen->m_PoweredObjectives.Data[i]->IsA(ATrDeployable_BaseTurret::StaticClass()))
				((ATrDeployable_BaseTurret *)gen->m_PoweredObjectives.Data[i])->SetPowered(1);
		}
	}

	return true;
}

bool TrEntryPlayerController_Destroyed(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	// Generate a new key every map load, just in case
	cryptor.GenerateKey();

	savesReset();
	// FIXME: this sometimes crashes when loading a (rabbit) map
	stopwatchReset();
	routeReset();

	return false;
}

bool TrDevice_SetPosition(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	if (!g_config.customWeaponOffset)
		return false;

	ATrDevice *that = (ATrDevice *)dwCallingObject;
	ATrDevice_eventSetPosition_Parms *params = (ATrDevice_eventSetPosition_Parms *)pParams;

	FVector DrawOffset, ViewOffset, FinalSmallWeaponsOffset, FinalLocation, X, Y, Z;
	unsigned char CurrentHand;
	FRotator NewRotation, FinalRotation, HeadOffsRot;
	ATrPlayerController *TrPC = (ATrPlayerController *)that->GetALocalPlayerController();
	ATrHUD *TrH;
	FVector2D ViewportSize;
	bool bIsWideScreen, bRidingInVehicle;
	FVector HeadOffset;
	ATrPawn *TrP;

	TrP = (ATrPawn *)params->Holder;
	if (!TrP || !TrP->IsFirstPerson())
		return true;

	((ULocalPlayer *)that->GetALocalPlayerController()->Player)->ViewportClient->GetViewportSize(&ViewportSize);

	if (TrPC)
	{
		TrH = (ATrHUD *)TrPC->myHUD;
		if (TrH)
		{
			if (TrH->bIsMainMenuOpen)
			{
				if (that->Mesh)
					that->Mesh->SetOwnerNoSee(true);
			}
			else
				that->Mesh->SetOwnerNoSee(false);
		}
	}

	// Hide the weapon if hidden
	CurrentHand = that->GetHand();
	if (that->bForceHidden || CurrentHand == HAND_Hidden)
	{
		that->Mesh->SetHidden(true);
		params->Holder->ArmsMesh[0]->SetHidden(true);
		params->Holder->ArmsMesh[1]->SetHidden(true);
		NewRotation = params->Holder->eventGetViewRotation();
		that->SetLocation(Geom::add(((ATrPawn *)that->Instigator)->GetPawnViewLocation(), that->TransformVectorByRotation(NewRotation, that->HiddenWeaponsOffset, false)));
		that->SetRotation(NewRotation);
		that->SetBase(that->Instigator, FVector(0, 0, 0), NULL, NULL);
		return true;
	}

	if (that->bPendingShow)
	{
		that->SetHidden(false);
		that->bPendingShow = false;
	}

	that->Mesh->SetHidden(false);

	bIsWideScreen = (ViewportSize.Y > 0.f) && (ViewportSize.X / ViewportSize.Y >= 1.6);

	if (TrP->DrivenWeaponPawn.BaseVehicle && TrP->DrivenWeaponPawn.SeatIndex < TrP->DrivenWeaponPawn.BaseVehicle->Seats.Count &&
		TrP->DrivenWeaponPawn.BaseVehicle->Seats.Data[TrP->DrivenWeaponPawn.SeatIndex].m_bAttachPawnDirectly)
	{
		bRidingInVehicle = true;
	}

	// Adjust for the current hand
	ViewOffset = Geom::add(that->PlayerViewOffset, g_config.weaponOffset);
	FinalSmallWeaponsOffset = that->SmallWeaponsOffset;

	if (that->m_bTinyWeaponsEnabled)
		ViewOffset = Geom::add(ViewOffset, that->m_TinyWeaponsOffset);

	if (CurrentHand == HAND_Left)
	{
		FVector scale = ((ATrDevice *)that->StaticClass()->Default)->Mesh->Scale3D;
		scale.Y *= -1.0f;
		that->Mesh->SetScale3D(scale);
		that->Mesh->SetRotation(that->Subtract_RotatorRotator({ 0, 0, 0 }, ((ATrDevice *)that->StaticClass()->Default)->Mesh->Rotation));
		if (that->ArmsAnimSet)
		{
			params->Holder->ArmsMesh[0]->SetScale3D(((AUDKPawn *)params->Holder->StaticClass()->Default)->ArmsMesh[0]->Scale3D);
			params->Holder->ArmsMesh[0]->Scale3D.Y *= -1;
			params->Holder->ArmsMesh[1]->SetScale3D(((AUDKPawn *)params->Holder->StaticClass()->Default)->ArmsMesh[1]->Scale3D);
			params->Holder->ArmsMesh[1]->Scale3D.Y *= -1;
		}
		ViewOffset.Y *= -1.0f;
		FinalSmallWeaponsOffset.Y *= -1.0f;
	}
	else if (CurrentHand == HAND_Centered)
	{
		ViewOffset.Y = 0.0f;
		FinalSmallWeaponsOffset.Y = 0.0f;
	}
	else if (CurrentHand == HAND_Right)
	{
		that->Mesh->SetScale3D(((ATrDevice *)that->StaticClass()->Default)->Mesh->Scale3D);
		that->Mesh->SetRotation(((ATrDevice *)that->StaticClass()->Default)->Mesh->Rotation);

		if (that->ArmsAnimSet)
		{
			params->Holder->ArmsMesh[0]->SetScale3D(((AUDKPawn *)params->Holder->StaticClass()->Default)->ArmsMesh[0]->Scale3D);
			params->Holder->ArmsMesh[1]->SetScale3D(((AUDKPawn *)params->Holder->StaticClass()->Default)->ArmsMesh[1]->Scale3D);
		}
	}

	if (bIsWideScreen)
	{
		ViewOffset = Geom::add(ViewOffset, Geom::scale(FinalSmallWeaponsOffset, that->WideScreenOffsetScaling));
		if (that->bSmallWeapons)
			ViewOffset = Geom::add(ViewOffset, Geom::scale(FinalSmallWeaponsOffset, 0.7f));
	}
	else if (that->bSmallWeapons)
		ViewOffset = Geom::add(ViewOffset, FinalSmallWeaponsOffset);

	// Calculate the draw offset
	if (!params->Holder->Controller)
	{
		DrawOffset = that->TransformVectorByRotation(params->Holder->eventGetBaseAimRotation(), ViewOffset, 0);
		DrawOffset.Z += ((AUTPawn *)params->Holder)->GetEyeHeight();
	}
	else
	{
		// We want to extract each rotation axis and offset based on the axes instead of putting everything into controller space
		// like UTWeapon does. Positioning in controller space causes the weapon to not line up with the camera when pitching.
		that->GetAxes(params->Holder->Controller->Rotation, &X, &Y, &Z);

		// Bring it up to eye height.
		DrawOffset.Z = TrP->GetEyeHeight();

		// Weapon bob.
		//DrawOffset = Geom::add(DrawOffset, TrP->WeaponBob(that->BobDamping, that->JumpDamping));
		DrawOffset = Geom::add(DrawOffset, TrP->WeaponBob(1.0f, 1.0f));

		HeadOffsRot = params->Holder->Rotation;

		// If we are a passenger and we attach directly, use the controller's rotation for the head offset.
		// This fixes the issue with wonky rotation offsets as gravcycle passenger.
		if (bRidingInVehicle)
			HeadOffsRot = params->Holder->Controller->Rotation;

		// Forward offset (position the 'head' of the pawn forward)
		HeadOffset.X = TrP->m_fPawnViewForwardAmount;
		DrawOffset = Geom::add(DrawOffset, that->TransformVectorByRotation(HeadOffsRot, Geom::add(HeadOffset, that->m_vPositionPivotOffset), 0));

		// Zoom.
		if (that->m_bUseMeshZoomOffset && that->GetZoomedState() != 0) // 0 == ZST_NotZoomed
			if (TrPC)
			{
				//`log(TrPlayerController(PC).GetFOVAngle()@"    "@TrPlayerController(PC).DesiredFOV);
				ViewOffset = Geom::add(ViewOffset, Geom::scale(that->m_vZoomMeshOffset, (1 - ((TrPC->FOVAngle - TrPC->DesiredFOV) / (TrPC->DefaultFOV - TrPC->DesiredFOV)))));
			}

		// View offset.
		ViewOffset = Geom::add(ViewOffset, ((AUTPlayerController *)params->Holder->Controller)->ShakeOffset);
		DrawOffset = Geom::add(DrawOffset, Geom::scale(X, ViewOffset.X));
		DrawOffset = Geom::add(DrawOffset, Geom::scale(Y, ViewOffset.Y));
		DrawOffset = Geom::add(DrawOffset, Geom::scale(Z, ViewOffset.Z));
	}

	// Adjust it in the world
	FinalLocation = Geom::add(params->Holder->Location, DrawOffset);
	that->SetLocation(FinalLocation);
	that->SetBase(params->Holder, { 0, 0, 0 }, NULL, NULL);

	if (that->ArmsAnimSet)
	{
		if (params->Holder->ArmsMesh[0])
			params->Holder->ArmsMesh[0]->SetTranslation(DrawOffset);
		if (params->Holder->ArmsMesh[1])
			params->Holder->ArmsMesh[1]->SetTranslation(DrawOffset);
	}

	// Crash around this line
	NewRotation = params->Holder->Controller ? params->Holder->eventGetBaseAimRotation() : params->Holder->Controller->Rotation;

	// Add some rotation leading
	if (params->Holder->Controller)
	{
		FinalRotation.Yaw = that->LagRot(NewRotation.Yaw & 65535, that->LastRotation.Yaw & 65535, that->MaxYawLag, 0, params->DeltaSeconds);
		FinalRotation.Pitch = that->LagRot(NewRotation.Pitch & 65535, that->LastRotation.Pitch & 65535, that->MaxPitchLag, 1, params->DeltaSeconds);
		FinalRotation.Roll = NewRotation.Roll;
	}
	else
		FinalRotation = NewRotation;


	that->LastRotUpdate = that->WorldInfo->TimeSeconds;
	that->LastRotation = NewRotation;

	if (bIsWideScreen)
		FinalRotation = that->Add_RotatorRotator(FinalRotation, that->WidescreenRotationOffset);

	// Add current kickback amount to rotation.
	if (TrPC)
		FinalRotation = that->Add_RotatorRotator(FinalRotation, TrPC->m_rCurrentKickbackDirection);

	that->SetRotation(FinalRotation);
	if (that->ArmsAnimSet)
	{
		params->Holder->ArmsMesh[0]->SetRotation(FinalRotation);
		params->Holder->ArmsMesh[1]->SetRotation(FinalRotation);
	}

	//if (g_config.customWeaponOffset)
	//	that->m_TinyWeaponsOffset = g_config.weaponOffset;
	
	if (g_config.customBulletSpawnOffset)
		that->m_vClientSideFireOffset = g_config.bulletSpawnOffset;
	
	return true;
}