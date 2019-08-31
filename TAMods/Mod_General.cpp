#include "Mods.h"
#include "NameCryptor.h"


bool TrPC_InitInputSystem(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	ATrPlayerController* that = (ATrPlayerController *)dwCallingObject;
	
	Utils::tr_pc = that;

	if (g_TAServerControlClient.isKnownToBeModded() && that && that->WorldInfo && that->WorldInfo->NetMode == NM_Client) {
		std::string serverUrl = Utils::f2std(that->WorldInfo->GetAddressURL());
		Logger::log("Connecting to server at %s", serverUrl.c_str());
		g_CustomServerManager = CustomServerManager();

		g_CustomServerManager.start(serverUrl);
	}

	// Set how much XP we have at the start of the match
	if (Utils::tr_menuMovie && Utils::tr_menuMovie->PlayerProfile) {
		g_GlobalState.matchStartXp = Data::getXpFromPlayerProfile(Utils::tr_menuMovie->PlayerProfile);
	}

	return false;
}

bool TrPC_PostBeginPlay(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult) {
	Logger::log("[PostBeginPlay DISABLED HOOK]");

	return false;
}

bool TrPC_Destroyed(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult) {
	// If the client is connected to a modded server, disconnect
	Logger::log("About to disconnect from serverclient.disconnect();");
	//if (g_CustomServerManager.isConnected()) {
	g_CustomServerManager.stop();
	//}
	
	// Remove any game balance modifications this server imposed
	g_gameBalanceTracker.revert();
	return false;
}

bool TrPC_LoadPlayerProfile(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult) {
	Logger::log("[LoadPlayerProfile] Utils::tr_pc = %d", Utils::tr_pc);
	if (Utils::tr_pc) {
		Logger::log("Utils::tr_pc->PlayerReplicationInfo = %d", Utils::tr_pc->PlayerReplicationInfo);
	}

	return false;
}

void UTGame_EndGame(AUTGame* that, AUTGame_execEndGame_Parms* params, void* result, Hooks::CallInfo* callInfo) {
	//if (g_CustomServerManager.isConnected()) {
	//	g_CustomServerManager.stop();
	//}
	that->EndGame(params->Winner, params->Reason);
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

	//CustomWeaponsOnPlayerDeath(that);

	if (!dwCallingObject->IsA(ATrPlayerController_Training::StaticClass()))
	{
		if (that->WorldInfo && stopwatch::running && g_config.stopwatchStopOnDeath)
		{
			stopwatch::displayTime("Stopped - ", that->WorldInfo->RealTimeSeconds);
			stopwatch::printSummary();
			stopwatch::running = 0;
		}
		routes::stopRec();
	}

	if ((routes::botReplay && that->IsA(ATrPlayerController_Training::StaticClass()))
		|| (!routes::botReplay && !that->IsA(ATrPlayerController_Training::StaticClass())))
		routes::stopReplay();

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
	states::reset();
	// FIXME: this sometimes crashes when loading a (rabbit) map
	stopwatch::reset();
	routes::reset();

	return false;
}

bool TrDevice_SetPosition(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	ATrDevice *that = (ATrDevice *)dwCallingObject;

	// Poll for updating custom weapon models
	CustomWeaponsTick(that);

	// Set up the offsets expected for this weapon
	WeaponPositioningDetails wepPos(that);

	if (g_config.showWeapon && !g_config.customWeaponOffset) {
		return false;
	}

	// If there's a custom weapon offset, add it in
	if (g_config.customWeaponOffset)
		wepPos.CustomOffset = g_config.weaponOffset;
	
	ATrDevice_eventSetPosition_Parms *params = (ATrDevice_eventSetPosition_Parms *)pParams;

	FVector DrawOffset, ViewOffset, FinalSmallWeaponsOffset, FinalLocation, X, Y, Z;
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
	if (!g_config.showWeapon || wepPos.IsHidden || wepPos.CurrentHand == HAND_Hidden)
	{
		that->Mesh->SetHidden(true);
		params->Holder->ArmsMesh[0]->SetHidden(true);
		params->Holder->ArmsMesh[1]->SetHidden(true);
		NewRotation = params->Holder->eventGetViewRotation();
		that->SetLocation(Geom::add(((ATrPawn *)that->Instigator)->GetPawnViewLocation(), that->TransformVectorByRotation(NewRotation, wepPos.HiddenWeaponsOffset, false)));
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
	ViewOffset = Geom::add(wepPos.PlayerViewOffset, wepPos.CustomOffset);
	FinalSmallWeaponsOffset = wepPos.SmallWeaponsOffset;

	if (wepPos.bTinyWeapons)
		ViewOffset = Geom::add(ViewOffset, wepPos.TinyWeaponsOffset);

	if (wepPos.CurrentHand == HAND_Left)
	{
		FVector scale = ((ATrDevice *)wepPos.DeviceClass->Default)->Mesh->Scale3D;
		scale.Y *= -1.0f;
		that->Mesh->SetScale3D(scale);
		that->Mesh->SetRotation(that->Subtract_RotatorRotator({ 0, 0, 0 }, ((ATrDevice *)wepPos.DeviceClass->Default)->Mesh->Rotation));
		if (wepPos.ArmsAnimSet)
		{
			params->Holder->ArmsMesh[0]->SetScale3D(((AUDKPawn *)params->Holder->StaticClass()->Default)->ArmsMesh[0]->Scale3D);
			params->Holder->ArmsMesh[0]->Scale3D.Y *= -1;
			params->Holder->ArmsMesh[1]->SetScale3D(((AUDKPawn *)params->Holder->StaticClass()->Default)->ArmsMesh[1]->Scale3D);
			params->Holder->ArmsMesh[1]->Scale3D.Y *= -1;
		}
		ViewOffset.Y *= -1.0f;
		FinalSmallWeaponsOffset.Y *= -1.0f;
	}
	else if (wepPos.CurrentHand == HAND_Centered)
	{
		ViewOffset.Y = 0.0f;
		FinalSmallWeaponsOffset.Y = 0.0f;
	}
	else if (wepPos.CurrentHand == HAND_Right)
	{
		that->Mesh->SetScale3D(((ATrDevice *)wepPos.DeviceClass->Default)->Mesh->Scale3D);
		that->Mesh->SetRotation(((ATrDevice *)wepPos.DeviceClass->Default)->Mesh->Rotation);

		if (wepPos.ArmsAnimSet)
		{
			params->Holder->ArmsMesh[0]->SetScale3D(((AUDKPawn *)params->Holder->StaticClass()->Default)->ArmsMesh[0]->Scale3D);
			params->Holder->ArmsMesh[1]->SetScale3D(((AUDKPawn *)params->Holder->StaticClass()->Default)->ArmsMesh[1]->Scale3D);
		}
	}

	if (bIsWideScreen)
	{
		ViewOffset = Geom::add(ViewOffset, Geom::scale(FinalSmallWeaponsOffset, wepPos.WidescreenOffsetScaling));
		if (wepPos.bSmallWeapons)
			ViewOffset = Geom::add(ViewOffset, Geom::scale(FinalSmallWeaponsOffset, 0.7f));
	}
	else if (wepPos.bSmallWeapons)
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
		DrawOffset = Geom::add(DrawOffset, that->TransformVectorByRotation(HeadOffsRot, Geom::add(HeadOffset, wepPos.PositionPivotOffset), 0));

		// Zoom.
		if (wepPos.UseMeshZoomOffset && wepPos.ZoomedState != 0) // 0 == ZST_NotZoomed
			if (TrPC)
			{
				//`log(TrPlayerController(PC).GetFOVAngle()@"    "@TrPlayerController(PC).DesiredFOV);
				ViewOffset = Geom::add(ViewOffset, Geom::scale(wepPos.ZoomMeshOffset, (1 - ((TrPC->FOVAngle - TrPC->DesiredFOV) / (TrPC->DefaultFOV - TrPC->DesiredFOV)))));
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

	// FIXME: occasional crash around this line
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
		FinalRotation = that->Add_RotatorRotator(FinalRotation, wepPos.WidescreenRotationOffset);

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

void TrDevice_NovaSlug_StartFire(ATrDevice_NovaSlug* that, ATrDevice_NovaSlug_execStartFire_Parms* params, void* result, Hooks::CallInfo callInfo) {
	that->ATrDevice::StartFire(params->FireModeNum);
}

void TrDevice_Shotgun_AddSpreadWithAccuracy(ATrDevice_Shotgun* that, ATrDevice_Shotgun_execAddSpreadWithAccuracy_Parms* params, FRotator* result, Hooks::CallInfo callInfo) {
	bool shouldUseGotySpread = false;
	GameBalance::PropValue prop;
	if (GameBalance::Items::getWeaponProp(that->DBWeaponId, (int)GameBalance::Items::PropId::SHOTGUN_USE_GOTY_SPREAD, prop)) {
		shouldUseGotySpread = prop.valBool;
	}

	if (shouldUseGotySpread) {
		*result = that->ATrDevice::AddSpreadWithAccuracy(params->BaseAim, params->fAccuracy);
	}
	else {
		*result = that->ATrDevice_Shotgun::AddSpreadWithAccuracy(params->BaseAim, params->fAccuracy);
	}
	
}

void UGFxTrMenuMoviePlayer_HideMovie(UGFxTrMenuMoviePlayer* that, UGFxTrMenuMoviePlayer_eventHideMovie_Parms* params, void* result, Hooks::CallInfo callInfo) {
	ATrPlayerController* pc = (ATrPlayerController*)that->eventGetPC();
	if (pc->r_bNeedLoadout) {
		// On custom servers this flag fails to get cleared, causing the client to get stuck in the menu
		that->bEndOfMatch = false;
	}
	that->eventHideMovie();
}