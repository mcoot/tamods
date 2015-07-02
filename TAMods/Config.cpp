#include "Config.h"

Config g_config;

Config::Config()
{
	onDamageNumberCreate = NULL;
	onDamageNumberUpdate = NULL;
	reset();
}

Config::~Config()
{
}

void Config::reset()
{
	// Clear loadouts
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (loadouts[i][j])
				delete loadouts[i][j];
			loadouts[i][j] = NULL;
		}
	}
	
	showErrorNotifications = true;
	showWeapon = true;
	showFirstPersonAmmo = false;
	showCrosshair = true;
	crosshairScale = 1;
	crosshairColor = Utils::rgb(255, 255, 255);

	// Damage number customization
	damageNumbersOffsetX = 0.0f;
	damageNumbersOffsetY = 0.0f;
	damageNumbersScale = 1.0f;

	// Damage number stream
	showDamageNumberStream = false;
	showRainbow = false;
	// Default damage stream reset time is 1/2 second
	damageNumberStreamTimeout = 0.5;
	lastDamageNumberShowEventTime = 0;
	damageNumberStreamValue = 0;
	damageNumberStreamCount = 0;
	// Custom damage number text
	damageNumberCustomText = std::string("");

	if (onDamageNumberCreate)
		delete onDamageNumberCreate;
	if (onDamageNumberUpdate)
		delete onDamageNumberUpdate;
	onDamageNumberCreate = NULL;
	onDamageNumberUpdate = NULL;

	//Damage Number color variables
	rainbowBulletInt = 0;
	damageNumbersLimit = 0;
	damageNumbersColorMin = Utils::rgb(255, 255, 255);
	damageNumbersColorMax = Utils::rgb(248, 83, 83);
	friendlyChatColor = Utils::rgb(158, 208, 212);
	enemyChatColor = Utils::rgb(255, 111, 111);
	friendlyHUDChatColor = Utils::rgb(158, 208, 211);
	enemyHUDChatColor = Utils::rgb(249, 32, 32);

	//Marker Colors
	friendlyColor = Utils::rgb(119, 186, 255);
	enemyColor = Utils::rgb(248, 83, 83);
	enemyMarkerColor = Utils::rgb(255, 23, 23);
	enemyIsFMarkerColor = Utils::rgb(239, 164, 0);
	friendlyMarkerColor = Utils::rgb(115, 225, 255);
	friendlyIsFMarkerColor = Utils::rgb(81, 250, 85);

	// Ski bars
	skiBarMin = 30;
	skiBarMax = 300;

	// Sounds
	int hitSoundMode = 0;
	bool customAirMailSound = false;
	bool customBluePlateSound = false;
	float hitSoundPitchMin = 0.4f;
	float hitSoundPitchMax = 1.6f;
	int hitSoundDamageRef = 600;
	float volumeHitSound = 0.55f;
	float volumeHeadShot = 0.55f;
	float volumeBluePlate = 1.0f;
	float volumeAirMail = 1.0f;


	// Toggle HUD
	showObjectiveIcon = true;
	showFlagBaseIcon = true;
	showCTFBaseIcon = true;
	showNuggetIcon = true;
	showPlayerIcon = true;
	showVehicleIcon = true;
	showMineIcon = true;
	showSensorIcon = true;

	//Stats
	recordStats = false;

	//Global mute
	globalMuteList = std::vector<MutedPlayer>();

	// Bools for reloading
	shouldReloadGfxTrHud = true;
}

void Config::parseFile()
{
	const char *profile = getenv("USERPROFILE");
	std::string directory;

	if (profile)
		directory = std::string(profile) + "\\Documents\\My Games\\Tribes Ascend\\TribesGame\\config\\";
	else
		directory = std::string("C:\\");
	reset();
	lua = Lua();
	std::string err = lua.doFile(directory + "config.lua");
	if (err.size())
	{
		Utils::console("Lua config error: %s", err.c_str());
		return;
	}
	if (FILE *custom = fopen(std::string(directory + "custom.lua").c_str(), "r"))
	{
		fclose(custom);
		std::string err = lua.doFile(directory + "custom.lua");
		if (err.size())
		{
			Utils::console("Custom Lua config error: %s", err.c_str());
			return;
		}
	}
	setVariables();
	updateDefaults();
}

void Config::reloadSkiBars(UGfxTrHud *currHud, bool updated)
{
	if (g_config.shouldReloadGfxTrHud)
	{
		UGfxTrHud *hud = UObject::FindObject<UGfxTrHud>("GfxTrHud TribesGame.Default__GfxTrHud");

		if (!hud || !currHud)
			return;
		if (updated)
			g_config.shouldReloadGfxTrHud = false;
		for (int i = 0; i < 12; i++)
		{
			int val = (int)((g_config.skiBarMin + (i - 1) * (g_config.skiBarMax - g_config.skiBarMin) / 10.0f) / 0.072f);
			if (currHud)
				currHud->m_SkiSpeedSteps[i] = val;
			if (hud)
				hud->m_SkiSpeedSteps[i] = val;
		}
	}
}

void Config::updateDefaults()
{
	ATrHUD *hud = UObject::FindObject<ATrHUD>("TrHUD TribesGame.Default__TrHUD");
	if (hud)
	{
		hud->ColorEnemy = enemyColor;
		hud->ColorFriend = friendlyColor;
		hud->MarkerColorFriendly = Utils::linCol(friendlyMarkerColor);
		hud->MarkerColorFriendly_IsFriend = Utils::linCol(friendlyIsFMarkerColor);
		hud->MarkerColorEnemy = Utils::linCol(enemyMarkerColor);
		hud->MarkerColorEnemy_IsFriend = Utils::linCol(enemyIsFMarkerColor);
	}

	USoundCue *hitsound = UObject::FindObject<USoundCue>("SoundCue AUD_PC_Notifications.Impact__Notify.A_CUE_PC_HitImpactOnPawnNotify");
	if (hitsound)
		hitsound->VolumeMultiplier = hitSoundMode > 0 ? 0.0f : volumeHitSound;

	USoundCue *headshotsound = UObject::FindObject<USoundCue>("SoundCue AUD_PC_Notifications.Headshot.A_CUE_PC_ImpactOnPawnNotify_Headshot");
	if (headshotsound)
		headshotsound->VolumeMultiplier = volumeHeadShot;

	reloadSkiBars(NULL, false);
}

#define SET_VARIABLE(type, var) (lua.setVar<type>(var, #var))
void Config::setVariables()
{
	SET_VARIABLE(int, damageNumbersLimit);
	SET_VARIABLE(bool, showErrorNotifications);
	SET_VARIABLE(bool, showWeapon);
	SET_VARIABLE(bool, showFirstPersonAmmo);
	SET_VARIABLE(bool, showCrosshair);
	SET_VARIABLE(float, crosshairScale);
	SET_VARIABLE(FColor, crosshairColor);

	// Damage number customization
	onDamageNumberCreate = new LuaRef(getGlobal(lua.getState(), "onDamageNumberCreate"));
	onDamageNumberUpdate = new LuaRef(getGlobal(lua.getState(), "onDamageNumberUpdate"));
	SET_VARIABLE(float, damageNumbersOffsetX);
	SET_VARIABLE(float, damageNumbersOffsetY);
	SET_VARIABLE(float, damageNumbersScale);

	// Damage number / chain count streaming
	SET_VARIABLE(bool, showDamageNumberStream);
	SET_VARIABLE(bool, showChainBulletHitCount);
	SET_VARIABLE(double, damageNumberStreamTimeout);

	// Custom damage number text
	SET_VARIABLE(std::string, damageNumberCustomText);

	// Damage number colors
	SET_VARIABLE(bool, showRainbow);
	SET_VARIABLE(FColor, damageNumbersColorMin);
	SET_VARIABLE(FColor, damageNumbersColorMax);

	// Chat colors
	SET_VARIABLE(FColor, friendlyChatColor);
	SET_VARIABLE(FColor, enemyChatColor);
	SET_VARIABLE(FColor, friendlyHUDChatColor);
	SET_VARIABLE(FColor, enemyHUDChatColor);

	//Marker Colors
	SET_VARIABLE(FColor, friendlyColor);
	SET_VARIABLE(FColor, enemyColor);
	SET_VARIABLE(FColor, enemyMarkerColor);
	SET_VARIABLE(FColor, enemyIsFMarkerColor);
	SET_VARIABLE(FColor, friendlyMarkerColor);
	SET_VARIABLE(FColor, friendlyIsFMarkerColor);

	// Ski bars
	SET_VARIABLE(float, skiBarMin);
	SET_VARIABLE(float, skiBarMax);

	// Sounds
	SET_VARIABLE(int, hitSoundMode);
	SET_VARIABLE(bool, customAirMailSound);
	SET_VARIABLE(bool, customBluePlateSound);
	SET_VARIABLE(float, hitSoundPitchMin);
	SET_VARIABLE(float, hitSoundPitchMax);
	SET_VARIABLE(int, hitSoundDamageRef);
	SET_VARIABLE(float, volumeHitSound);
	SET_VARIABLE(float, volumeHeadShot);
	SET_VARIABLE(float, volumeBluePlate);
	SET_VARIABLE(float, volumeAirMail);


	// Toggle HUD
	SET_VARIABLE(bool, showObjectiveIcon);
	SET_VARIABLE(bool, showFlagBaseIcon);
	SET_VARIABLE(bool, showCTFBaseIcon);
	SET_VARIABLE(bool, showNuggetIcon);
	SET_VARIABLE(bool, showPlayerIcon);
	SET_VARIABLE(bool, showVehicleIcon);
	SET_VARIABLE(bool, showMineIcon);
	SET_VARIABLE(bool, showSensorIcon);

	// Toggle Stats
	SET_VARIABLE(bool, recordStats);
}

static int getWeaponID(const std::string &class_name, const std::string &str)
{
	if (Utils::cleanString(class_name) == "vehicle")
		return Utils::searchMapId(Data::vehicle_weapons, str, "vehicle weapon");

	int class_id = Utils::searchMapId(Data::classes, class_name, "a Class") - 1;
	if (class_id == -1)
		return (0);
	for (int i = 0; i < 2; i++)
	{
		int ret = Utils::searchMapId(Data::equipment[class_id][i], str, "", false);
		if (ret)
			return (ret);
	}
	Utils::console("WARNING: searched item '%s' could not be identified as a %s's weapon", Utils::trim(str).c_str(), Utils::trim(class_name).c_str());
	return (0);
}

static bool config_setLoadout(const std::string &pclass, int pnum, const std::string &pname, Equipment &lo)
{
	Loadout *loadout = new Loadout(pclass, pnum, pname, lo);
	if (!loadout->valid)
	{
		delete loadout;
		return false;
	}
	if (g_config.loadouts[loadout->class_type][loadout->loadout_nb])
		delete g_config.loadouts[loadout->class_type][loadout->loadout_nb];
	g_config.loadouts[loadout->class_type][loadout->loadout_nb] = loadout;
	return true;
}

static void parseModuleArray(TArray<UParticleModule *> &tab, const FColor &col, float intensity)
{
	for (int si = 0; si < tab.Count; si++)
	{
		UParticleModule *module = tab.Data[si];

		FRawDistributionVector *vecs;

		Logger::log("      Module %d: %s", si, tab.Data[si]->GetFullName());
		if (module->IsA(UParticleModuleColorOverLife::StaticClass()))
		{
			UParticleModuleColorOverLife *m = (UParticleModuleColorOverLife *)module;
			vecs = &m->ColorOverLife;
		}
		else if (module->IsA(UParticleModuleColorScaleOverDensity::StaticClass()))
		{
			UParticleModuleColorScaleOverDensity *m = (UParticleModuleColorScaleOverDensity *)module;
			vecs = &m->ColorScaleOverDensity;
		}
		else if (module->IsA(UParticleModuleColorScaleOverLife::StaticClass()))
		{
			UParticleModuleColorScaleOverLife *m = (UParticleModuleColorScaleOverLife *)module;
			vecs = &m->ColorScaleOverLife;
		}
		else if (module->IsA(UParticleModuleColor::StaticClass()))
		{
			UParticleModuleColor *m = (UParticleModuleColor *)module;
			vecs = &m->StartColor;

			if (vecs->LookupTable.Count >= 5)
			{
				vecs->LookupTable.Data[2] = (float)col.R * intensity / 255.0f;
				vecs->LookupTable.Data[3] = (float)col.G * intensity / 255.0f;
				vecs->LookupTable.Data[4] = (float)col.B * intensity / 255.0f;
			}
		}
		else if (module->IsA(UParticleModuleColorByParameter::StaticClass()))
		{
			UParticleModuleColorByParameter *m = (UParticleModuleColorByParameter *)module;

			Logger::log("ColorByParameter");
			Logger::log("Color: (%d, %d, %d, %d)", m->DefaultColor.R, m->DefaultColor.G, m->DefaultColor.B, m->DefaultColor.A);
			continue;
		}
		else
			continue;

		TArray<float> &vtable = vecs->LookupTable;
		Logger::log("        Vector Table size: %d, type:%d, op:%d, StartTime: %f, TimeScale: %f, NumElements: %d, ChunkSize: %d", vtable.Count, vecs->Type, vecs->Op, vecs->LookupTableStartTime, vecs->LookupTableTimeScale, vecs->LookupTableNumElements, vecs->LookupTableChunkSize);
		for (int i = 0; i < vtable.Count; i++)
			Logger::log("        VTABLE #%d: %f", i, vtable(i));
	}
}

static void editParticleSystem(UParticleSystem *ps, const FColor &col, float intensity)
{
	if (ps)
	{
		Logger::log("%d Emitters found", ps->Emitters.Count);
		for (int ei = 0; ei < ps->Emitters.Count; ei++)
		{
			Logger::log("  Accessing emitter %d", ei);
			UParticleEmitter *emitter = ps->Emitters.Data[ei];
			Logger::log("  %d LODLevels found", emitter->LODLevels.Count);
			for (int lodi = 0; lodi < emitter->LODLevels.Count; lodi++)
			{
				Logger::log("    Accessing LODLevel %d", lodi);
				UParticleLODLevel *lod = emitter->LODLevels.Data[lodi];

				Logger::log("    %d SpawnModules found", lod->SpawnModules.Count);
				parseModuleArray(lod->SpawnModules, col, intensity);
				Logger::log("    %d UpdateModules found", lod->UpdateModules.Count);
				parseModuleArray(lod->UpdateModules, col, intensity);
			}
		}
	}
}

static bool config_setBulletColor(const std::string &pclass, const std::string &weapon, const FColor &col, float intensity)
{
	int weapon_id = getWeaponID(pclass, weapon);
	if (!weapon_id)
		return false;
	CustomProjectile *proj = NULL;
	auto it = g_config.wep_id_to_custom_proj.find(weapon_id);
	if (it == g_config.wep_id_to_custom_proj.end())
	{
		proj = new CustomProjectile(weapon_id);
		g_config.wep_id_to_custom_proj[weapon_id] = proj;
	}
	else
		proj = it->second;
	if (!proj)
		return false;
	Logger::log("Editing bullet: %s", proj->default_proj->GetFullName());
	editParticleSystem(proj->custom_ps, col, intensity);
	return true;
}

static UParticleSystem *config_getProjectile(const std::string &pclass, const std::string &weapon)
{
	int weapon_id = getWeaponID(pclass, weapon);
	if (!weapon_id)
		return false;
	CustomProjectile *proj = NULL;
	auto it = g_config.wep_id_to_custom_proj.find(weapon_id);
	if (it == g_config.wep_id_to_custom_proj.end())
	{
		proj = new CustomProjectile(weapon_id);
		g_config.wep_id_to_custom_proj[weapon_id] = proj;
		g_config.proj_class_to_custom_proj[(int) proj->default_proj->Class] = proj;
		Logger::log("Created projectile %d: %s", (int)proj->default_proj->Class, proj->default_proj->GetFullName());
	}
	else
		proj = it->second;
	if (!proj)
		return NULL;
	return proj->custom_ps;
}

static bool config_setCrosshairs(const std::string &pclass, const std::string &weapon, Crosshairs &xhairs)
{
	int weapon_id = getWeaponID(pclass, weapon);
	if (!weapon_id)
		return false;
	bool vehicle = (Utils::cleanString(pclass) == "vehicle");
	auto it = Data::weapon_id_to_name.find(weapon_id);
	if (it == Data::weapon_id_to_name.end())
		return false;
	int xhair1 = Utils::searchMapId(Data::crosshairs, xhairs.standard, "Crosshair");
	int xhair2 = Utils::searchMapId(Data::crosshairs, xhairs.zoomed, "Crosshair");
	std::string device_name = vehicle ? "TrVehicleWeapon" : "TrDevice";
	std::string default_name = device_name + "_" + it->second + " TribesGame.Default__" + device_name + "_" + it->second;
	ATrDevice *dev = !vehicle ? UObject::FindObject<ATrDevice>(default_name.c_str()) : NULL;
	ATrVehicleWeapon *vdev = vehicle ? UObject::FindObject<ATrVehicleWeapon>(default_name.c_str()) : NULL;
	if (dev)
	{
		if (xhair1) dev->m_nReticuleIndex = xhair1;
		if (xhair2) dev->m_nAltReticuleIndex = xhair2;
	}
	else if (vdev)
	{
		if (xhair1) vdev->m_nReticuleIndex = xhair1;
		if (xhair2) vdev->m_nAltReticuleIndex = xhair2;
	}
	else
	{
		Utils::console("Unable to set stock crosshairs for weapon: %s", it->second.c_str());
		return false;
	}
	return true;
}

static bool config_addMutedPlayer(MutedPlayer player)
{
	g_config.globalMuteList.push_back(player);
	return true;
}

static FVector hud_project(ATrHUD *hud, FVector vec)
{
	return hud->Canvas->Project(vec);
}

static void hud_drawDamageNumber(ATrHUD *hud, std::string num, FColor col, FVector loc, float scalex, float scaley)
{
	std::wstring wstr(num.begin(), num.end());
	wchar_t *wchar = (wchar_t *)wstr.c_str();
	hud->DrawColoredMarkerText(wchar, col, loc, hud->Canvas, scalex, scaley);
}

static bool hud_isOnScreen(ATrHUD *hud, FVector loc)
{
	FVector view_location;
	FRotator view_rotation;

	if (hud->TrPlayerOwner)
	{
		hud->TrPlayerOwner->eventGetPlayerViewPoint(&view_location, &view_rotation);
		return Geom::dot(Geom::rotationToVector(view_rotation), Geom::normal(Geom::sub(loc, view_location))) >= 0.0f;
	}
	return false;
}

static FVector hud_getPlayerPos(ATrHUD *hud)
{
	FVector out;
	FRotator view_rotation;
	
	if (hud->TrPlayerOwner)
		hud->TrPlayerOwner->eventGetPlayerViewPoint(&out, &view_rotation);
	return out;
}

void Lua::init()
{
	getGlobalNamespace(_state).
		beginClass<FColor>("Color").
			addData("r", &FColor::R).
			addData("g", &FColor::G).
			addData("b", &FColor::B).
			addData("a", &FColor::A).
		endClass().
		addFunction("rgba", &Utils::rgba).
		addFunction("rgb", &Utils::rgb).

		beginClass<Equipment>("Equipment").
			addData("primary", &Equipment::primary).
			addData("secondary", &Equipment::secondary).
			addData("belt", &Equipment::belt).
			addData("pack", &Equipment::pack).
			addData("perk1", &Equipment::perk1).
			addData("perk2", &Equipment::perk2).
		endClass().
		addFunction("equipment", &Equipment::create).
		addFunction("setLoadout", &config_setLoadout).

		beginClass<Crosshairs>("Crosshairs").
			addData("standard", &Crosshairs::standard).
			addData("zoomed", &Crosshairs::zoomed).
		endClass().
		addFunction("crosshair", &Crosshairs::create).
		addFunction("crosshairs", &Crosshairs::create2).
		addFunction("setCrosshairs", &config_setCrosshairs).

		beginClass<FVector>("Vector").
			addData("x", &FVector::X).
			addData("y", &FVector::Y).
			addData("z", &FVector::Z).
			addConstructor<void(*)(float, float, float)>().
		endClass().

		beginClass<FVector4>("Vector4").
			addData("x", &FVector4::X).
			addData("y", &FVector4::Y).
			addData("z", &FVector4::Z).
			addData("w", &FVector4::W).
			addConstructor<void(*)(float, float, float, float)>().
		endClass().

		beginClass<FOverheadNumber>("DamageNumber").
			addData("number", &FOverheadNumber::NumberValue).
			addData("time", &FOverheadNumber::RemainingTime).
			addData("location", &FOverheadNumber::WorldSpaceLocation).
			addData("color", &FOverheadNumber::CurrentColor).
			addData("scale", &FOverheadNumber::CurrentScale).
			addProperty("shieldDamage", &FOverheadNumber::isShieldDamage, &FOverheadNumber::setShieldDamage).
			addConstructor<void(*)(int, float, FVector4, bool)>().
		endClass().

		beginClass<TArray<FOverheadNumber>>("DamageNumberArray").
			addFunction("add", &TArray<FOverheadNumber>::Add).
			addFunction("remove", &TArray<FOverheadNumber>::Remove).
			addFunction("clear", &TArray<FOverheadNumber>::Clear).
			addFunction("size", &TArray<FOverheadNumber>::Num).
			addFunction("get", &TArray<FOverheadNumber>::Get).
		endClass().

		// Particle Systems

		beginClass<UObject>("Object").
			addFunction("getName", &UObject::GetStringName).
			addFunction("getClassName", &UObject::GetStringClassName).
			addFunction("getFullName", &UObject::GetStringFullName).
		endClass().

		beginClass<TArray<float>>("FloatArray").
			addFunction("add", &TArray<float>::Add).
			addFunction("remove", &TArray<float>::Remove).
			addFunction("clear", &TArray<float>::Clear).
			addFunction("size", &TArray<float>::Num).
			addFunction("get", &TArray<float>::GetStd).
			addFunction("set", &TArray<float>::Set).
		endClass().

		beginClass<FRawDistribution>("RawDistribution").
			addData("Type", &FRawDistribution::Type).
			addData("Op", &FRawDistribution::Op).
			addData("NumElements", &FRawDistribution::LookupTableNumElements).
			addData("ChunkSize", &FRawDistribution::LookupTableChunkSize).
			addProperty("LookupTable", &ParticleModuleHelper::RawDistribution_getTable, &ParticleModuleHelper::RawDistribution_setTable).
			addData("TimeScale", &FRawDistribution::LookupTableTimeScale).
			addData("StartTime", &FRawDistribution::LookupTableStartTime).
		endClass().

		deriveClass<FRawDistributionFloat, FRawDistribution>("RawDistributionFloat").
		endClass().

		deriveClass<FRawDistributionVector, FRawDistribution>("RawDistributionVector").
		endClass().

		deriveClass<UParticleModule, UObject>("ParticleModule").
			addProperty("bSpawnModule", &ParticleModuleHelper::ParticleModule_getbSpawnModule, &ParticleModuleHelper::ParticleModule_setbSpawnModule).
			addProperty("bUpdateModule", &ParticleModuleHelper::ParticleModule_getbUpdateModule, &ParticleModuleHelper::ParticleModule_setbUpdateModule).
			addProperty("bFinalUpdateModule", &ParticleModuleHelper::ParticleModule_getbFinalUpdateModule, &ParticleModuleHelper::ParticleModule_setbFinalUpdateModule).
			addProperty("bCurvesAsColor", &ParticleModuleHelper::ParticleModule_getbCurvesAsColor, &ParticleModuleHelper::ParticleModule_setbCurvesAsColor).
			addProperty("b3DDrawMode", &ParticleModuleHelper::ParticleModule_getb3DDrawMode, &ParticleModuleHelper::ParticleModule_setb3DDrawMode).
			addProperty("bSupported3DDrawMode", &ParticleModuleHelper::ParticleModule_getbSupported3DDrawMode, &ParticleModuleHelper::ParticleModule_setbSupported3DDrawMode).
			addProperty("bEnabled", &ParticleModuleHelper::ParticleModule_getbEnabled, &ParticleModuleHelper::ParticleModule_setbEnabled).
			addProperty("bEditable", &ParticleModuleHelper::ParticleModule_getbEditable, &ParticleModuleHelper::ParticleModule_setbEditable).
			addProperty("LODDuplicate", &ParticleModuleHelper::ParticleModule_getLODDuplicate, &ParticleModuleHelper::ParticleModule_setLODDuplicate).
			addProperty("bSupportsRandomSeed", &ParticleModuleHelper::ParticleModule_getbSupportsRandomSeed, &ParticleModuleHelper::ParticleModule_setbSupportsRandomSeed).
			addProperty("bRequiresLoopingNotification", &ParticleModuleHelper::ParticleModule_getbRequiresLoopingNotification, &ParticleModuleHelper::ParticleModule_setbRequiresLoopingNotification).
			addData("LODValidity", &UParticleModule::LODValidity).
			addProperty("ModuleEditorColor", &ParticleModuleHelper::ParticleModule_getModuleEditorColor, &ParticleModuleHelper::ParticleModule_setModuleEditorColor).
		endClass().
		deriveClass<UParticleModuleAccelerationBase, UParticleModule>("ParticleModuleAccelerationBase").
			addProperty("bAlwaysInWorldSpace", &ParticleModuleHelper::ParticleModuleAccelerationBase_getbAlwaysInWorldSpace, &ParticleModuleHelper::ParticleModuleAccelerationBase_setbAlwaysInWorldSpace).
		endClass().
		deriveClass<UParticleModuleAcceleration, UParticleModuleAccelerationBase>("ParticleModuleAcceleration").
			addProperty("Acceleration", &ParticleModuleHelper::ParticleModuleAcceleration_getAcceleration, &ParticleModuleHelper::ParticleModuleAcceleration_setAcceleration).
			addProperty("bApplyOwnerScale", &ParticleModuleHelper::ParticleModuleAcceleration_getbApplyOwnerScale, &ParticleModuleHelper::ParticleModuleAcceleration_setbApplyOwnerScale).
		endClass().
		deriveClass<UParticleModuleAccelerationOverLifetime, UParticleModuleAccelerationBase>("ParticleModuleAccelerationOverLifetime").
			addProperty("AccelOverLife", &ParticleModuleHelper::ParticleModuleAccelerationOverLifetime_getAccelOverLife, &ParticleModuleHelper::ParticleModuleAccelerationOverLifetime_setAccelOverLife).
		endClass().
		deriveClass<UParticleModuleAttractorBase, UParticleModule>("ParticleModuleAttractorBase").
		endClass().
		deriveClass<UParticleModuleAttractorLine, UParticleModuleAttractorBase>("ParticleModuleAttractorLine").
			addProperty("EndPoint0", &ParticleModuleHelper::ParticleModuleAttractorLine_getEndPoint0, &ParticleModuleHelper::ParticleModuleAttractorLine_setEndPoint0).
			addProperty("EndPoint1", &ParticleModuleHelper::ParticleModuleAttractorLine_getEndPoint1, &ParticleModuleHelper::ParticleModuleAttractorLine_setEndPoint1).
			addProperty("Range", &ParticleModuleHelper::ParticleModuleAttractorLine_getRange, &ParticleModuleHelper::ParticleModuleAttractorLine_setRange).
			addProperty("Strength", &ParticleModuleHelper::ParticleModuleAttractorLine_getStrength, &ParticleModuleHelper::ParticleModuleAttractorLine_setStrength).
		endClass().
		deriveClass<UParticleModuleAttractorParticle, UParticleModuleAttractorBase>("ParticleModuleAttractorParticle").
			addProperty("EmitterName", &ParticleModuleHelper::ParticleModuleAttractorParticle_getEmitterName, &ParticleModuleHelper::ParticleModuleAttractorParticle_setEmitterName).
			addProperty("Range", &ParticleModuleHelper::ParticleModuleAttractorParticle_getRange, &ParticleModuleHelper::ParticleModuleAttractorParticle_setRange).
			addProperty("bStrengthByDistance", &ParticleModuleHelper::ParticleModuleAttractorParticle_getbStrengthByDistance, &ParticleModuleHelper::ParticleModuleAttractorParticle_setbStrengthByDistance).
			addProperty("bAffectBaseVelocity", &ParticleModuleHelper::ParticleModuleAttractorParticle_getbAffectBaseVelocity, &ParticleModuleHelper::ParticleModuleAttractorParticle_setbAffectBaseVelocity).
			addProperty("bRenewSource", &ParticleModuleHelper::ParticleModuleAttractorParticle_getbRenewSource, &ParticleModuleHelper::ParticleModuleAttractorParticle_setbRenewSource).
			addProperty("bInheritSourceVel", &ParticleModuleHelper::ParticleModuleAttractorParticle_getbInheritSourceVel, &ParticleModuleHelper::ParticleModuleAttractorParticle_setbInheritSourceVel).
			addProperty("Strength", &ParticleModuleHelper::ParticleModuleAttractorParticle_getStrength, &ParticleModuleHelper::ParticleModuleAttractorParticle_setStrength).
			addData("SelectionMethod", &UParticleModuleAttractorParticle::SelectionMethod).
			addData("LastSelIndex", &UParticleModuleAttractorParticle::LastSelIndex).
		endClass().
		deriveClass<UParticleModuleAttractorPoint, UParticleModuleAttractorBase>("ParticleModuleAttractorPoint").
			addProperty("Position", &ParticleModuleHelper::ParticleModuleAttractorPoint_getPosition, &ParticleModuleHelper::ParticleModuleAttractorPoint_setPosition).
			addProperty("Range", &ParticleModuleHelper::ParticleModuleAttractorPoint_getRange, &ParticleModuleHelper::ParticleModuleAttractorPoint_setRange).
			addProperty("Strength", &ParticleModuleHelper::ParticleModuleAttractorPoint_getStrength, &ParticleModuleHelper::ParticleModuleAttractorPoint_setStrength).
			addProperty("StrengthByDistance", &ParticleModuleHelper::ParticleModuleAttractorPoint_getStrengthByDistance, &ParticleModuleHelper::ParticleModuleAttractorPoint_setStrengthByDistance).
			addProperty("bAffectBaseVelocity", &ParticleModuleHelper::ParticleModuleAttractorPoint_getbAffectBaseVelocity, &ParticleModuleHelper::ParticleModuleAttractorPoint_setbAffectBaseVelocity).
			addProperty("bOverrideVelocity", &ParticleModuleHelper::ParticleModuleAttractorPoint_getbOverrideVelocity, &ParticleModuleHelper::ParticleModuleAttractorPoint_setbOverrideVelocity).
			addProperty("bUseWorldSpacePosition", &ParticleModuleHelper::ParticleModuleAttractorPoint_getbUseWorldSpacePosition, &ParticleModuleHelper::ParticleModuleAttractorPoint_setbUseWorldSpacePosition).
		endClass().
		deriveClass<UParticleModuleBeamBase, UParticleModule>("ParticleModuleBeamBase").
		endClass().
		deriveClass<UParticleModuleBeamModifier, UParticleModuleBeamBase>("ParticleModuleBeamModifier").
			addData("ModifierType", &UParticleModuleBeamModifier::ModifierType).
			addProperty("PositionOptions", &ParticleModuleHelper::ParticleModuleBeamModifier_getPositionOptions, &ParticleModuleHelper::ParticleModuleBeamModifier_setPositionOptions).
			addProperty("Position", &ParticleModuleHelper::ParticleModuleBeamModifier_getPosition, &ParticleModuleHelper::ParticleModuleBeamModifier_setPosition).
			addProperty("TangentOptions", &ParticleModuleHelper::ParticleModuleBeamModifier_getTangentOptions, &ParticleModuleHelper::ParticleModuleBeamModifier_setTangentOptions).
			addProperty("Tangent", &ParticleModuleHelper::ParticleModuleBeamModifier_getTangent, &ParticleModuleHelper::ParticleModuleBeamModifier_setTangent).
			addProperty("bAbsoluteTangent", &ParticleModuleHelper::ParticleModuleBeamModifier_getbAbsoluteTangent, &ParticleModuleHelper::ParticleModuleBeamModifier_setbAbsoluteTangent).
			addProperty("StrengthOptions", &ParticleModuleHelper::ParticleModuleBeamModifier_getStrengthOptions, &ParticleModuleHelper::ParticleModuleBeamModifier_setStrengthOptions).
			addProperty("Strength", &ParticleModuleHelper::ParticleModuleBeamModifier_getStrength, &ParticleModuleHelper::ParticleModuleBeamModifier_setStrength).
		endClass().
		deriveClass<UParticleModuleBeamNoise, UParticleModuleBeamBase>("ParticleModuleBeamNoise").
			addProperty("bLowFreq_Enabled", &ParticleModuleHelper::ParticleModuleBeamNoise_getbLowFreq_Enabled, &ParticleModuleHelper::ParticleModuleBeamNoise_setbLowFreq_Enabled).
			addProperty("bNRScaleEmitterTime", &ParticleModuleHelper::ParticleModuleBeamNoise_getbNRScaleEmitterTime, &ParticleModuleHelper::ParticleModuleBeamNoise_setbNRScaleEmitterTime).
			addProperty("bSmooth", &ParticleModuleHelper::ParticleModuleBeamNoise_getbSmooth, &ParticleModuleHelper::ParticleModuleBeamNoise_setbSmooth).
			addProperty("bNoiseLock", &ParticleModuleHelper::ParticleModuleBeamNoise_getbNoiseLock, &ParticleModuleHelper::ParticleModuleBeamNoise_setbNoiseLock).
			addProperty("bOscillate", &ParticleModuleHelper::ParticleModuleBeamNoise_getbOscillate, &ParticleModuleHelper::ParticleModuleBeamNoise_setbOscillate).
			addProperty("bUseNoiseTangents", &ParticleModuleHelper::ParticleModuleBeamNoise_getbUseNoiseTangents, &ParticleModuleHelper::ParticleModuleBeamNoise_setbUseNoiseTangents).
			addProperty("bTargetNoise", &ParticleModuleHelper::ParticleModuleBeamNoise_getbTargetNoise, &ParticleModuleHelper::ParticleModuleBeamNoise_setbTargetNoise).
			addProperty("bApplyNoiseScale", &ParticleModuleHelper::ParticleModuleBeamNoise_getbApplyNoiseScale, &ParticleModuleHelper::ParticleModuleBeamNoise_setbApplyNoiseScale).
			addData("Frequency", &UParticleModuleBeamNoise::Frequency).
			addData("Frequency_LowRange", &UParticleModuleBeamNoise::Frequency_LowRange).
			addProperty("NoiseRange", &ParticleModuleHelper::ParticleModuleBeamNoise_getNoiseRange, &ParticleModuleHelper::ParticleModuleBeamNoise_setNoiseRange).
			addProperty("NoiseRangeScale", &ParticleModuleHelper::ParticleModuleBeamNoise_getNoiseRangeScale, &ParticleModuleHelper::ParticleModuleBeamNoise_setNoiseRangeScale).
			addProperty("NoiseSpeed", &ParticleModuleHelper::ParticleModuleBeamNoise_getNoiseSpeed, &ParticleModuleHelper::ParticleModuleBeamNoise_setNoiseSpeed).
			addData("NoiseLockRadius", &UParticleModuleBeamNoise::NoiseLockRadius).
			addData("NoiseLockTime", &UParticleModuleBeamNoise::NoiseLockTime).
			addData("NoiseTension", &UParticleModuleBeamNoise::NoiseTension).
			addProperty("NoiseTangentStrength", &ParticleModuleHelper::ParticleModuleBeamNoise_getNoiseTangentStrength, &ParticleModuleHelper::ParticleModuleBeamNoise_setNoiseTangentStrength).
			addData("NoiseTessellation", &UParticleModuleBeamNoise::NoiseTessellation).
			addData("FrequencyDistance", &UParticleModuleBeamNoise::FrequencyDistance).
			addProperty("NoiseScale", &ParticleModuleHelper::ParticleModuleBeamNoise_getNoiseScale, &ParticleModuleHelper::ParticleModuleBeamNoise_setNoiseScale).
		endClass().
		deriveClass<UParticleModuleBeamSource, UParticleModuleBeamBase>("ParticleModuleBeamSource").
			addData("SourceMethod", &UParticleModuleBeamSource::SourceMethod).
			addData("SourceTangentMethod", &UParticleModuleBeamSource::SourceTangentMethod).
			addProperty("SourceName", &ParticleModuleHelper::ParticleModuleBeamSource_getSourceName, &ParticleModuleHelper::ParticleModuleBeamSource_setSourceName).
			addProperty("bSourceAbsolute", &ParticleModuleHelper::ParticleModuleBeamSource_getbSourceAbsolute, &ParticleModuleHelper::ParticleModuleBeamSource_setbSourceAbsolute).
			addProperty("bLockSource", &ParticleModuleHelper::ParticleModuleBeamSource_getbLockSource, &ParticleModuleHelper::ParticleModuleBeamSource_setbLockSource).
			addProperty("bLockSourceTangent", &ParticleModuleHelper::ParticleModuleBeamSource_getbLockSourceTangent, &ParticleModuleHelper::ParticleModuleBeamSource_setbLockSourceTangent).
			addProperty("bLockSourceStength", &ParticleModuleHelper::ParticleModuleBeamSource_getbLockSourceStength, &ParticleModuleHelper::ParticleModuleBeamSource_setbLockSourceStength).
			addProperty("Source", &ParticleModuleHelper::ParticleModuleBeamSource_getSource, &ParticleModuleHelper::ParticleModuleBeamSource_setSource).
			addProperty("SourceTangent", &ParticleModuleHelper::ParticleModuleBeamSource_getSourceTangent, &ParticleModuleHelper::ParticleModuleBeamSource_setSourceTangent).
			addProperty("SourceStrength", &ParticleModuleHelper::ParticleModuleBeamSource_getSourceStrength, &ParticleModuleHelper::ParticleModuleBeamSource_setSourceStrength).
		endClass().
		deriveClass<UParticleModuleBeamTarget, UParticleModuleBeamBase>("ParticleModuleBeamTarget").
			addData("TargetMethod", &UParticleModuleBeamTarget::TargetMethod).
			addData("TargetTangentMethod", &UParticleModuleBeamTarget::TargetTangentMethod).
			addProperty("TargetName", &ParticleModuleHelper::ParticleModuleBeamTarget_getTargetName, &ParticleModuleHelper::ParticleModuleBeamTarget_setTargetName).
			addProperty("Target", &ParticleModuleHelper::ParticleModuleBeamTarget_getTarget, &ParticleModuleHelper::ParticleModuleBeamTarget_setTarget).
			addProperty("bTargetAbsolute", &ParticleModuleHelper::ParticleModuleBeamTarget_getbTargetAbsolute, &ParticleModuleHelper::ParticleModuleBeamTarget_setbTargetAbsolute).
			addProperty("bLockTarget", &ParticleModuleHelper::ParticleModuleBeamTarget_getbLockTarget, &ParticleModuleHelper::ParticleModuleBeamTarget_setbLockTarget).
			addProperty("bLockTargetTangent", &ParticleModuleHelper::ParticleModuleBeamTarget_getbLockTargetTangent, &ParticleModuleHelper::ParticleModuleBeamTarget_setbLockTargetTangent).
			addProperty("bLockTargetStength", &ParticleModuleHelper::ParticleModuleBeamTarget_getbLockTargetStength, &ParticleModuleHelper::ParticleModuleBeamTarget_setbLockTargetStength).
			addProperty("TargetTangent", &ParticleModuleHelper::ParticleModuleBeamTarget_getTargetTangent, &ParticleModuleHelper::ParticleModuleBeamTarget_setTargetTangent).
			addProperty("TargetStrength", &ParticleModuleHelper::ParticleModuleBeamTarget_getTargetStrength, &ParticleModuleHelper::ParticleModuleBeamTarget_setTargetStrength).
			addData("LockRadius", &UParticleModuleBeamTarget::LockRadius).
		endClass().
		deriveClass<UParticleModuleCameraBase, UParticleModule>("ParticleModuleCameraBase").
		endClass().
		deriveClass<UParticleModuleCameraOffset, UParticleModuleCameraBase>("ParticleModuleCameraOffset").
			addProperty("CameraOffset", &ParticleModuleHelper::ParticleModuleCameraOffset_getCameraOffset, &ParticleModuleHelper::ParticleModuleCameraOffset_setCameraOffset).
			addProperty("bSpawnTimeOnly", &ParticleModuleHelper::ParticleModuleCameraOffset_getbSpawnTimeOnly, &ParticleModuleHelper::ParticleModuleCameraOffset_setbSpawnTimeOnly).
			addData("UpdateMethod", &UParticleModuleCameraOffset::UpdateMethod).
		endClass().
		deriveClass<UParticleModuleCollisionBase, UParticleModule>("ParticleModuleCollisionBase").
		endClass().
		deriveClass<UParticleModuleCollision, UParticleModuleCollisionBase>("ParticleModuleCollision").
			addProperty("DampingFactor", &ParticleModuleHelper::ParticleModuleCollision_getDampingFactor, &ParticleModuleHelper::ParticleModuleCollision_setDampingFactor).
			addProperty("DampingFactorRotation", &ParticleModuleHelper::ParticleModuleCollision_getDampingFactorRotation, &ParticleModuleHelper::ParticleModuleCollision_setDampingFactorRotation).
			addProperty("MaxCollisions", &ParticleModuleHelper::ParticleModuleCollision_getMaxCollisions, &ParticleModuleHelper::ParticleModuleCollision_setMaxCollisions).
			addData("CollisionCompletionOption", &UParticleModuleCollision::CollisionCompletionOption).
			addProperty("bApplyPhysics", &ParticleModuleHelper::ParticleModuleCollision_getbApplyPhysics, &ParticleModuleHelper::ParticleModuleCollision_setbApplyPhysics).
			addProperty("bPawnsDoNotDecrementCount", &ParticleModuleHelper::ParticleModuleCollision_getbPawnsDoNotDecrementCount, &ParticleModuleHelper::ParticleModuleCollision_setbPawnsDoNotDecrementCount).
			addProperty("bOnlyVerticalNormalsDecrementCount", &ParticleModuleHelper::ParticleModuleCollision_getbOnlyVerticalNormalsDecrementCount, &ParticleModuleHelper::ParticleModuleCollision_setbOnlyVerticalNormalsDecrementCount).
			addProperty("bDropDetail", &ParticleModuleHelper::ParticleModuleCollision_getbDropDetail, &ParticleModuleHelper::ParticleModuleCollision_setbDropDetail).
			addProperty("ParticleMass", &ParticleModuleHelper::ParticleModuleCollision_getParticleMass, &ParticleModuleHelper::ParticleModuleCollision_setParticleMass).
			addData("DirScalar", &UParticleModuleCollision::DirScalar).
			addData("VerticalFudgeFactor", &UParticleModuleCollision::VerticalFudgeFactor).
			addProperty("DelayAmount", &ParticleModuleHelper::ParticleModuleCollision_getDelayAmount, &ParticleModuleHelper::ParticleModuleCollision_setDelayAmount).
		endClass().
		deriveClass<UParticleModuleColorBase, UParticleModule>("ParticleModuleColorBase").
		endClass().
		deriveClass<UParticleModuleColor, UParticleModuleColorBase>("ParticleModuleColor").
			addProperty("StartColor", &ParticleModuleHelper::ParticleModuleColor_getStartColor, &ParticleModuleHelper::ParticleModuleColor_setStartColor).
			addProperty("StartAlpha", &ParticleModuleHelper::ParticleModuleColor_getStartAlpha, &ParticleModuleHelper::ParticleModuleColor_setStartAlpha).
			addProperty("bClampAlpha", &ParticleModuleHelper::ParticleModuleColor_getbClampAlpha, &ParticleModuleHelper::ParticleModuleColor_setbClampAlpha).
		endClass().
		deriveClass<UParticleModuleColor_Seeded, UParticleModuleColor>("ParticleModuleColor_Seeded").
			addProperty("RandomSeedInfo", &ParticleModuleHelper::ParticleModuleColor_Seeded_getRandomSeedInfo, &ParticleModuleHelper::ParticleModuleColor_Seeded_setRandomSeedInfo).
		endClass().
		deriveClass<UParticleModuleColorByParameter, UParticleModuleColorBase>("ParticleModuleColorByParameter").
			addProperty("ColorParam", &ParticleModuleHelper::ParticleModuleColorByParameter_getColorParam, &ParticleModuleHelper::ParticleModuleColorByParameter_setColorParam).
			addProperty("DefaultColor", &ParticleModuleHelper::ParticleModuleColorByParameter_getDefaultColor, &ParticleModuleHelper::ParticleModuleColorByParameter_setDefaultColor).
		endClass().
		deriveClass<UParticleModuleColorOverLife, UParticleModuleColorBase>("ParticleModuleColorOverLife").
			addProperty("ColorOverLife", &ParticleModuleHelper::ParticleModuleColorOverLife_getColorOverLife, &ParticleModuleHelper::ParticleModuleColorOverLife_setColorOverLife).
			addProperty("AlphaOverLife", &ParticleModuleHelper::ParticleModuleColorOverLife_getAlphaOverLife, &ParticleModuleHelper::ParticleModuleColorOverLife_setAlphaOverLife).
			addProperty("bClampAlpha", &ParticleModuleHelper::ParticleModuleColorOverLife_getbClampAlpha, &ParticleModuleHelper::ParticleModuleColorOverLife_setbClampAlpha).
		endClass().
		deriveClass<UParticleModuleColorScaleOverDensity, UParticleModuleColorBase>("ParticleModuleColorScaleOverDensity").
			addProperty("ColorScaleOverDensity", &ParticleModuleHelper::ParticleModuleColorScaleOverDensity_getColorScaleOverDensity, &ParticleModuleHelper::ParticleModuleColorScaleOverDensity_setColorScaleOverDensity).
			addProperty("AlphaScaleOverDensity", &ParticleModuleHelper::ParticleModuleColorScaleOverDensity_getAlphaScaleOverDensity, &ParticleModuleHelper::ParticleModuleColorScaleOverDensity_setAlphaScaleOverDensity).
		endClass().
		deriveClass<UParticleModuleColorScaleOverLife, UParticleModuleColorBase>("ParticleModuleColorScaleOverLife").
			addProperty("ColorScaleOverLife", &ParticleModuleHelper::ParticleModuleColorScaleOverLife_getColorScaleOverLife, &ParticleModuleHelper::ParticleModuleColorScaleOverLife_setColorScaleOverLife).
			addProperty("AlphaScaleOverLife", &ParticleModuleHelper::ParticleModuleColorScaleOverLife_getAlphaScaleOverLife, &ParticleModuleHelper::ParticleModuleColorScaleOverLife_setAlphaScaleOverLife).
			addProperty("bEmitterTime", &ParticleModuleHelper::ParticleModuleColorScaleOverLife_getbEmitterTime, &ParticleModuleHelper::ParticleModuleColorScaleOverLife_setbEmitterTime).
		endClass().
		deriveClass<UParticleModuleEventBase, UParticleModule>("ParticleModuleEventBase").
		endClass().
		deriveClass<UParticleModuleEventGenerator, UParticleModuleEventBase>("ParticleModuleEventGenerator").
			addProperty("Events", &ParticleModuleHelper::ParticleModuleEventGenerator_getEvents, &ParticleModuleHelper::ParticleModuleEventGenerator_setEvents).
		endClass().
		deriveClass<UParticleModuleEventReceiverBase, UParticleModuleEventBase>("ParticleModuleEventReceiverBase").
			addData("EventGeneratorType", &UParticleModuleEventReceiverBase::EventGeneratorType).
			addProperty("EventName", &ParticleModuleHelper::ParticleModuleEventReceiverBase_getEventName, &ParticleModuleHelper::ParticleModuleEventReceiverBase_setEventName).
		endClass().
		deriveClass<UParticleModuleEventReceiverKillParticles, UParticleModuleEventReceiverBase>("ParticleModuleEventReceiverKillParticles").
			addProperty("bStopSpawning", &ParticleModuleHelper::ParticleModuleEventReceiverKillParticles_getbStopSpawning, &ParticleModuleHelper::ParticleModuleEventReceiverKillParticles_setbStopSpawning).
		endClass().
		deriveClass<UParticleModuleEventReceiverSpawn, UParticleModuleEventReceiverBase>("ParticleModuleEventReceiverSpawn").
			addProperty("SpawnCount", &ParticleModuleHelper::ParticleModuleEventReceiverSpawn_getSpawnCount, &ParticleModuleHelper::ParticleModuleEventReceiverSpawn_setSpawnCount).
			addProperty("bUseParticleTime", &ParticleModuleHelper::ParticleModuleEventReceiverSpawn_getbUseParticleTime, &ParticleModuleHelper::ParticleModuleEventReceiverSpawn_setbUseParticleTime).
			addProperty("bUsePSysLocation", &ParticleModuleHelper::ParticleModuleEventReceiverSpawn_getbUsePSysLocation, &ParticleModuleHelper::ParticleModuleEventReceiverSpawn_setbUsePSysLocation).
			addProperty("bInheritVelocity", &ParticleModuleHelper::ParticleModuleEventReceiverSpawn_getbInheritVelocity, &ParticleModuleHelper::ParticleModuleEventReceiverSpawn_setbInheritVelocity).
			addProperty("InheritVelocityScale", &ParticleModuleHelper::ParticleModuleEventReceiverSpawn_getInheritVelocityScale, &ParticleModuleHelper::ParticleModuleEventReceiverSpawn_setInheritVelocityScale).
		endClass().
		deriveClass<UParticleModuleKillBase, UParticleModule>("ParticleModuleKillBase").
		endClass().
		deriveClass<UParticleModuleKillBox, UParticleModuleKillBase>("ParticleModuleKillBox").
			addProperty("LowerLeftCorner", &ParticleModuleHelper::ParticleModuleKillBox_getLowerLeftCorner, &ParticleModuleHelper::ParticleModuleKillBox_setLowerLeftCorner).
			addProperty("UpperRightCorner", &ParticleModuleHelper::ParticleModuleKillBox_getUpperRightCorner, &ParticleModuleHelper::ParticleModuleKillBox_setUpperRightCorner).
			addProperty("bAbsolute", &ParticleModuleHelper::ParticleModuleKillBox_getbAbsolute, &ParticleModuleHelper::ParticleModuleKillBox_setbAbsolute).
			addProperty("bKillInside", &ParticleModuleHelper::ParticleModuleKillBox_getbKillInside, &ParticleModuleHelper::ParticleModuleKillBox_setbKillInside).
		endClass().
		deriveClass<UParticleModuleKillHeight, UParticleModuleKillBase>("ParticleModuleKillHeight").
			addProperty("Height", &ParticleModuleHelper::ParticleModuleKillHeight_getHeight, &ParticleModuleHelper::ParticleModuleKillHeight_setHeight).
			addProperty("bAbsolute", &ParticleModuleHelper::ParticleModuleKillHeight_getbAbsolute, &ParticleModuleHelper::ParticleModuleKillHeight_setbAbsolute).
			addProperty("bFloor", &ParticleModuleHelper::ParticleModuleKillHeight_getbFloor, &ParticleModuleHelper::ParticleModuleKillHeight_setbFloor).
			addProperty("bApplyPSysScale", &ParticleModuleHelper::ParticleModuleKillHeight_getbApplyPSysScale, &ParticleModuleHelper::ParticleModuleKillHeight_setbApplyPSysScale).
		endClass().
		deriveClass<UParticleModuleLifetimeBase, UParticleModule>("ParticleModuleLifetimeBase").
		endClass().
		deriveClass<UParticleModuleLifetime, UParticleModuleLifetimeBase>("ParticleModuleLifetime").
			addProperty("Lifetime", &ParticleModuleHelper::ParticleModuleLifetime_getLifetime, &ParticleModuleHelper::ParticleModuleLifetime_setLifetime).
		endClass().
		deriveClass<UParticleModuleLifetime_Seeded, UParticleModuleLifetime>("ParticleModuleLifetime_Seeded").
			addProperty("RandomSeedInfo", &ParticleModuleHelper::ParticleModuleLifetime_Seeded_getRandomSeedInfo, &ParticleModuleHelper::ParticleModuleLifetime_Seeded_setRandomSeedInfo).
		endClass().
		deriveClass<UParticleModuleLocationBase, UParticleModule>("ParticleModuleLocationBase").
		endClass().
		deriveClass<UParticleModuleLocation, UParticleModuleLocationBase>("ParticleModuleLocation").
			addProperty("StartLocation", &ParticleModuleHelper::ParticleModuleLocation_getStartLocation, &ParticleModuleHelper::ParticleModuleLocation_setStartLocation).
		endClass().
		deriveClass<UParticleModuleLocation_Seeded, UParticleModuleLocation>("ParticleModuleLocation_Seeded").
			addProperty("RandomSeedInfo", &ParticleModuleHelper::ParticleModuleLocation_Seeded_getRandomSeedInfo, &ParticleModuleHelper::ParticleModuleLocation_Seeded_setRandomSeedInfo).
		endClass().
		deriveClass<UParticleModuleLocationBoneSocket, UParticleModuleLocationBase>("ParticleModuleLocationBoneSocket").
			addData("SourceType", &UParticleModuleLocationBoneSocket::SourceType).
			addData("SelectionMethod", &UParticleModuleLocationBoneSocket::SelectionMethod).
			addProperty("UniversalOffset", &ParticleModuleHelper::ParticleModuleLocationBoneSocket_getUniversalOffset, &ParticleModuleHelper::ParticleModuleLocationBoneSocket_setUniversalOffset).
			addProperty("SourceLocations", &ParticleModuleHelper::ParticleModuleLocationBoneSocket_getSourceLocations, &ParticleModuleHelper::ParticleModuleLocationBoneSocket_setSourceLocations).
			addProperty("bUpdatePositionEachFrame", &ParticleModuleHelper::ParticleModuleLocationBoneSocket_getbUpdatePositionEachFrame, &ParticleModuleHelper::ParticleModuleLocationBoneSocket_setbUpdatePositionEachFrame).
			addProperty("bOrientMeshEmitters", &ParticleModuleHelper::ParticleModuleLocationBoneSocket_getbOrientMeshEmitters, &ParticleModuleHelper::ParticleModuleLocationBoneSocket_setbOrientMeshEmitters).
			addProperty("SkelMeshActorParamName", &ParticleModuleHelper::ParticleModuleLocationBoneSocket_getSkelMeshActorParamName, &ParticleModuleHelper::ParticleModuleLocationBoneSocket_setSkelMeshActorParamName).
			addData("EditorSkelMesh", &UParticleModuleLocationBoneSocket::EditorSkelMesh).
		endClass().
		deriveClass<UParticleModuleLocationDirect, UParticleModuleLocationBase>("ParticleModuleLocationDirect").
			addProperty("Location", &ParticleModuleHelper::ParticleModuleLocationDirect_getLocation, &ParticleModuleHelper::ParticleModuleLocationDirect_setLocation).
			addProperty("LocationOffset", &ParticleModuleHelper::ParticleModuleLocationDirect_getLocationOffset, &ParticleModuleHelper::ParticleModuleLocationDirect_setLocationOffset).
			addProperty("ScaleFactor", &ParticleModuleHelper::ParticleModuleLocationDirect_getScaleFactor, &ParticleModuleHelper::ParticleModuleLocationDirect_setScaleFactor).
			addProperty("Direction", &ParticleModuleHelper::ParticleModuleLocationDirect_getDirection, &ParticleModuleHelper::ParticleModuleLocationDirect_setDirection).
		endClass().
		deriveClass<UParticleModuleLocationEmitter, UParticleModuleLocationBase>("ParticleModuleLocationEmitter").
			addProperty("EmitterName", &ParticleModuleHelper::ParticleModuleLocationEmitter_getEmitterName, &ParticleModuleHelper::ParticleModuleLocationEmitter_setEmitterName).
			addData("SelectionMethod", &UParticleModuleLocationEmitter::SelectionMethod).
			addProperty("InheritSourceVelocity", &ParticleModuleHelper::ParticleModuleLocationEmitter_getInheritSourceVelocity, &ParticleModuleHelper::ParticleModuleLocationEmitter_setInheritSourceVelocity).
			addProperty("bInheritSourceRotation", &ParticleModuleHelper::ParticleModuleLocationEmitter_getbInheritSourceRotation, &ParticleModuleHelper::ParticleModuleLocationEmitter_setbInheritSourceRotation).
			addData("InheritSourceVelocityScale", &UParticleModuleLocationEmitter::InheritSourceVelocityScale).
			addData("InheritSourceRotationScale", &UParticleModuleLocationEmitter::InheritSourceRotationScale).
		endClass().
		deriveClass<UParticleModuleLocationEmitterDirect, UParticleModuleLocationBase>("ParticleModuleLocationEmitterDirect").
			addProperty("EmitterName", &ParticleModuleHelper::ParticleModuleLocationEmitterDirect_getEmitterName, &ParticleModuleHelper::ParticleModuleLocationEmitterDirect_setEmitterName).
		endClass().
		deriveClass<UParticleModuleLocationPrimitiveBase, UParticleModuleLocationBase>("ParticleModuleLocationPrimitiveBase").
			addProperty("Positive_X", &ParticleModuleHelper::ParticleModuleLocationPrimitiveBase_getPositive_X, &ParticleModuleHelper::ParticleModuleLocationPrimitiveBase_setPositive_X).
			addProperty("Positive_Y", &ParticleModuleHelper::ParticleModuleLocationPrimitiveBase_getPositive_Y, &ParticleModuleHelper::ParticleModuleLocationPrimitiveBase_setPositive_Y).
			addProperty("Positive_Z", &ParticleModuleHelper::ParticleModuleLocationPrimitiveBase_getPositive_Z, &ParticleModuleHelper::ParticleModuleLocationPrimitiveBase_setPositive_Z).
			addProperty("Negative_X", &ParticleModuleHelper::ParticleModuleLocationPrimitiveBase_getNegative_X, &ParticleModuleHelper::ParticleModuleLocationPrimitiveBase_setNegative_X).
			addProperty("Negative_Y", &ParticleModuleHelper::ParticleModuleLocationPrimitiveBase_getNegative_Y, &ParticleModuleHelper::ParticleModuleLocationPrimitiveBase_setNegative_Y).
			addProperty("Negative_Z", &ParticleModuleHelper::ParticleModuleLocationPrimitiveBase_getNegative_Z, &ParticleModuleHelper::ParticleModuleLocationPrimitiveBase_setNegative_Z).
			addProperty("SurfaceOnly", &ParticleModuleHelper::ParticleModuleLocationPrimitiveBase_getSurfaceOnly, &ParticleModuleHelper::ParticleModuleLocationPrimitiveBase_setSurfaceOnly).
			addProperty("Velocity", &ParticleModuleHelper::ParticleModuleLocationPrimitiveBase_getVelocity, &ParticleModuleHelper::ParticleModuleLocationPrimitiveBase_setVelocity).
			addProperty("VelocityScale", &ParticleModuleHelper::ParticleModuleLocationPrimitiveBase_getVelocityScale, &ParticleModuleHelper::ParticleModuleLocationPrimitiveBase_setVelocityScale).
			addProperty("StartLocation", &ParticleModuleHelper::ParticleModuleLocationPrimitiveBase_getStartLocation, &ParticleModuleHelper::ParticleModuleLocationPrimitiveBase_setStartLocation).
		endClass().
		deriveClass<UParticleModuleLocationPrimitiveCylinder, UParticleModuleLocationPrimitiveBase>("ParticleModuleLocationPrimitiveCylinder").
			addProperty("RadialVelocity", &ParticleModuleHelper::ParticleModuleLocationPrimitiveCylinder_getRadialVelocity, &ParticleModuleHelper::ParticleModuleLocationPrimitiveCylinder_setRadialVelocity).
			addProperty("StartRadius", &ParticleModuleHelper::ParticleModuleLocationPrimitiveCylinder_getStartRadius, &ParticleModuleHelper::ParticleModuleLocationPrimitiveCylinder_setStartRadius).
			addProperty("StartHeight", &ParticleModuleHelper::ParticleModuleLocationPrimitiveCylinder_getStartHeight, &ParticleModuleHelper::ParticleModuleLocationPrimitiveCylinder_setStartHeight).
			addData("HeightAxis", &UParticleModuleLocationPrimitiveCylinder::HeightAxis).
		endClass().
		deriveClass<UParticleModuleLocationPrimitiveCylinder_Seeded, UParticleModuleLocationPrimitiveCylinder>("ParticleModuleLocationPrimitiveCylinder_Seeded").
			addProperty("RandomSeedInfo", &ParticleModuleHelper::ParticleModuleLocationPrimitiveCylinder_Seeded_getRandomSeedInfo, &ParticleModuleHelper::ParticleModuleLocationPrimitiveCylinder_Seeded_setRandomSeedInfo).
		endClass().
		deriveClass<UParticleModuleLocationPrimitiveSphere, UParticleModuleLocationPrimitiveBase>("ParticleModuleLocationPrimitiveSphere").
			addProperty("StartRadius", &ParticleModuleHelper::ParticleModuleLocationPrimitiveSphere_getStartRadius, &ParticleModuleHelper::ParticleModuleLocationPrimitiveSphere_setStartRadius).
		endClass().
		deriveClass<UParticleModuleLocationPrimitiveSphere_Seeded, UParticleModuleLocationPrimitiveSphere>("ParticleModuleLocationPrimitiveSphere_Seeded").
			addProperty("RandomSeedInfo", &ParticleModuleHelper::ParticleModuleLocationPrimitiveSphere_Seeded_getRandomSeedInfo, &ParticleModuleHelper::ParticleModuleLocationPrimitiveSphere_Seeded_setRandomSeedInfo).
		endClass().
		deriveClass<UParticleModuleSourceMovement, UParticleModuleLocationBase>("ParticleModuleSourceMovement").
			addProperty("SourceMovementScale", &ParticleModuleHelper::ParticleModuleSourceMovement_getSourceMovementScale, &ParticleModuleHelper::ParticleModuleSourceMovement_setSourceMovementScale).
		endClass().
		deriveClass<UParticleModuleMaterialBase, UParticleModule>("ParticleModuleMaterialBase").
		endClass().
		deriveClass<UParticleModuleMaterialByParameter, UParticleModuleMaterialBase>("ParticleModuleMaterialByParameter").
			addProperty("MaterialParameters", &ParticleModuleHelper::ParticleModuleMaterialByParameter_getMaterialParameters, &ParticleModuleHelper::ParticleModuleMaterialByParameter_setMaterialParameters).
			addProperty("DefaultMaterials", &ParticleModuleHelper::ParticleModuleMaterialByParameter_getDefaultMaterials, &ParticleModuleHelper::ParticleModuleMaterialByParameter_setDefaultMaterials).
		endClass().
		deriveClass<UParticleModuleMeshMaterial, UParticleModuleMaterialBase>("ParticleModuleMeshMaterial").
			addProperty("MeshMaterials", &ParticleModuleHelper::ParticleModuleMeshMaterial_getMeshMaterials, &ParticleModuleHelper::ParticleModuleMeshMaterial_setMeshMaterials).
		endClass().
		deriveClass<UParticleModuleOrbitBase, UParticleModule>("ParticleModuleOrbitBase").
			addProperty("bUseEmitterTime", &ParticleModuleHelper::ParticleModuleOrbitBase_getbUseEmitterTime, &ParticleModuleHelper::ParticleModuleOrbitBase_setbUseEmitterTime).
		endClass().
		deriveClass<UParticleModuleOrbit, UParticleModuleOrbitBase>("ParticleModuleOrbit").
			addData("ChainMode", &UParticleModuleOrbit::ChainMode).
			addProperty("OffsetAmount", &ParticleModuleHelper::ParticleModuleOrbit_getOffsetAmount, &ParticleModuleHelper::ParticleModuleOrbit_setOffsetAmount).
			addProperty("OffsetOptions", &ParticleModuleHelper::ParticleModuleOrbit_getOffsetOptions, &ParticleModuleHelper::ParticleModuleOrbit_setOffsetOptions).
			addProperty("RotationAmount", &ParticleModuleHelper::ParticleModuleOrbit_getRotationAmount, &ParticleModuleHelper::ParticleModuleOrbit_setRotationAmount).
			addProperty("RotationOptions", &ParticleModuleHelper::ParticleModuleOrbit_getRotationOptions, &ParticleModuleHelper::ParticleModuleOrbit_setRotationOptions).
			addProperty("RotationRateAmount", &ParticleModuleHelper::ParticleModuleOrbit_getRotationRateAmount, &ParticleModuleHelper::ParticleModuleOrbit_setRotationRateAmount).
			addProperty("RotationRateOptions", &ParticleModuleHelper::ParticleModuleOrbit_getRotationRateOptions, &ParticleModuleHelper::ParticleModuleOrbit_setRotationRateOptions).
		endClass().
		deriveClass<UParticleModuleOrientationBase, UParticleModule>("ParticleModuleOrientationBase").
		endClass().
		deriveClass<UParticleModuleOrientationAxisLock, UParticleModuleOrientationBase>("ParticleModuleOrientationAxisLock").
			addData("LockAxisFlags", &UParticleModuleOrientationAxisLock::LockAxisFlags).
		endClass().
		deriveClass<UParticleModuleParameterBase, UParticleModule>("ParticleModuleParameterBase").
		endClass().
		deriveClass<UParticleModuleParameterDynamic, UParticleModuleParameterBase>("ParticleModuleParameterDynamic").
			addProperty("DynamicParams", &ParticleModuleHelper::ParticleModuleParameterDynamic_getDynamicParams, &ParticleModuleHelper::ParticleModuleParameterDynamic_setDynamicParams).
		endClass().
		deriveClass<UParticleModuleParameterDynamic_Seeded, UParticleModuleParameterDynamic>("ParticleModuleParameterDynamic_Seeded").
			addProperty("RandomSeedInfo", &ParticleModuleHelper::ParticleModuleParameterDynamic_Seeded_getRandomSeedInfo, &ParticleModuleHelper::ParticleModuleParameterDynamic_Seeded_setRandomSeedInfo).
		endClass().
		deriveClass<UParticleModuleRequired, UParticleModule>("ParticleModuleRequired").
			addData("Material", &UParticleModuleRequired::Material).
			addData("ScreenAlignment", &UParticleModuleRequired::ScreenAlignment).
			addData("SortMode", &UParticleModuleRequired::SortMode).
			addData("ParticleBurstMethod", &UParticleModuleRequired::ParticleBurstMethod).
			addData("InterpolationMethod", &UParticleModuleRequired::InterpolationMethod).
			addData("EmitterNormalsMode", &UParticleModuleRequired::EmitterNormalsMode).
			addProperty("bUseLocalSpace", &ParticleModuleHelper::ParticleModuleRequired_getbUseLocalSpace, &ParticleModuleHelper::ParticleModuleRequired_setbUseLocalSpace).
			addProperty("bKillOnDeactivate", &ParticleModuleHelper::ParticleModuleRequired_getbKillOnDeactivate, &ParticleModuleHelper::ParticleModuleRequired_setbKillOnDeactivate).
			addProperty("bKillOnCompleted", &ParticleModuleHelper::ParticleModuleRequired_getbKillOnCompleted, &ParticleModuleHelper::ParticleModuleRequired_setbKillOnCompleted).
			addProperty("bRequiresSorting", &ParticleModuleHelper::ParticleModuleRequired_getbRequiresSorting, &ParticleModuleHelper::ParticleModuleRequired_setbRequiresSorting).
			addProperty("bUseLegacyEmitterTime", &ParticleModuleHelper::ParticleModuleRequired_getbUseLegacyEmitterTime, &ParticleModuleHelper::ParticleModuleRequired_setbUseLegacyEmitterTime).
			addProperty("bEmitterDurationUseRange", &ParticleModuleHelper::ParticleModuleRequired_getbEmitterDurationUseRange, &ParticleModuleHelper::ParticleModuleRequired_setbEmitterDurationUseRange).
			addProperty("bDurationRecalcEachLoop", &ParticleModuleHelper::ParticleModuleRequired_getbDurationRecalcEachLoop, &ParticleModuleHelper::ParticleModuleRequired_setbDurationRecalcEachLoop).
			addProperty("bEmitterDelayUseRange", &ParticleModuleHelper::ParticleModuleRequired_getbEmitterDelayUseRange, &ParticleModuleHelper::ParticleModuleRequired_setbEmitterDelayUseRange).
			addProperty("bDelayFirstLoopOnly", &ParticleModuleHelper::ParticleModuleRequired_getbDelayFirstLoopOnly, &ParticleModuleHelper::ParticleModuleRequired_setbDelayFirstLoopOnly).
			addProperty("bScaleUV", &ParticleModuleHelper::ParticleModuleRequired_getbScaleUV, &ParticleModuleHelper::ParticleModuleRequired_setbScaleUV).
			addProperty("bDirectUV", &ParticleModuleHelper::ParticleModuleRequired_getbDirectUV, &ParticleModuleHelper::ParticleModuleRequired_setbDirectUV).
			addProperty("bUseMaxDrawCount", &ParticleModuleHelper::ParticleModuleRequired_getbUseMaxDrawCount, &ParticleModuleHelper::ParticleModuleRequired_setbUseMaxDrawCount).
			addData("EmitterDuration", &UParticleModuleRequired::EmitterDuration).
			addData("EmitterDurationLow", &UParticleModuleRequired::EmitterDurationLow).
			addData("EmitterLoops", &UParticleModuleRequired::EmitterLoops).
			addProperty("SpawnRate", &ParticleModuleHelper::ParticleModuleRequired_getSpawnRate, &ParticleModuleHelper::ParticleModuleRequired_setSpawnRate).
			addProperty("BurstList", &ParticleModuleHelper::ParticleModuleRequired_getBurstList, &ParticleModuleHelper::ParticleModuleRequired_setBurstList).
			addData("EmitterDelay", &UParticleModuleRequired::EmitterDelay).
			addData("EmitterDelayLow", &UParticleModuleRequired::EmitterDelayLow).
			addData("SubImages_Horizontal", &UParticleModuleRequired::SubImages_Horizontal).
			addData("SubImages_Vertical", &UParticleModuleRequired::SubImages_Vertical).
			addData("RandomImageTime", &UParticleModuleRequired::RandomImageTime).
			addData("RandomImageChanges", &UParticleModuleRequired::RandomImageChanges).
			addData("MaxDrawCount", &UParticleModuleRequired::MaxDrawCount).
			addData("DownsampleThresholdScreenFraction", &UParticleModuleRequired::DownsampleThresholdScreenFraction).
			addProperty("NormalsSphereCenter", &ParticleModuleHelper::ParticleModuleRequired_getNormalsSphereCenter, &ParticleModuleHelper::ParticleModuleRequired_setNormalsSphereCenter).
			addProperty("NormalsCylinderDirection", &ParticleModuleHelper::ParticleModuleRequired_getNormalsCylinderDirection, &ParticleModuleHelper::ParticleModuleRequired_setNormalsCylinderDirection).
		endClass().
		deriveClass<UParticleModuleRotationBase, UParticleModule>("ParticleModuleRotationBase").
		endClass().
		deriveClass<UParticleModuleMeshRotation, UParticleModuleRotationBase>("ParticleModuleMeshRotation").
			addProperty("StartRotation", &ParticleModuleHelper::ParticleModuleMeshRotation_getStartRotation, &ParticleModuleHelper::ParticleModuleMeshRotation_setStartRotation).
			addProperty("bInheritParent", &ParticleModuleHelper::ParticleModuleMeshRotation_getbInheritParent, &ParticleModuleHelper::ParticleModuleMeshRotation_setbInheritParent).
		endClass().
		deriveClass<UParticleModuleMeshRotation_Seeded, UParticleModuleMeshRotation>("ParticleModuleMeshRotation_Seeded").
			addProperty("RandomSeedInfo", &ParticleModuleHelper::ParticleModuleMeshRotation_Seeded_getRandomSeedInfo, &ParticleModuleHelper::ParticleModuleMeshRotation_Seeded_setRandomSeedInfo).
		endClass().
		deriveClass<UParticleModuleRotation, UParticleModuleRotationBase>("ParticleModuleRotation").
			addProperty("StartRotation", &ParticleModuleHelper::ParticleModuleRotation_getStartRotation, &ParticleModuleHelper::ParticleModuleRotation_setStartRotation).
		endClass().
		deriveClass<UParticleModuleRotation_Seeded, UParticleModuleRotation>("ParticleModuleRotation_Seeded").
			addProperty("RandomSeedInfo", &ParticleModuleHelper::ParticleModuleRotation_Seeded_getRandomSeedInfo, &ParticleModuleHelper::ParticleModuleRotation_Seeded_setRandomSeedInfo).
		endClass().
		deriveClass<UParticleModuleRotationOverLifetime, UParticleModuleRotationBase>("ParticleModuleRotationOverLifetime").
			addProperty("RotationOverLife", &ParticleModuleHelper::ParticleModuleRotationOverLifetime_getRotationOverLife, &ParticleModuleHelper::ParticleModuleRotationOverLifetime_setRotationOverLife).
			addProperty("Scale", &ParticleModuleHelper::ParticleModuleRotationOverLifetime_getScale, &ParticleModuleHelper::ParticleModuleRotationOverLifetime_setScale).
		endClass().
		deriveClass<UParticleModuleRotationRateBase, UParticleModule>("ParticleModuleRotationRateBase").
		endClass().
		deriveClass<UParticleModuleMeshRotationRate, UParticleModuleRotationRateBase>("ParticleModuleMeshRotationRate").
			addProperty("StartRotationRate", &ParticleModuleHelper::ParticleModuleMeshRotationRate_getStartRotationRate, &ParticleModuleHelper::ParticleModuleMeshRotationRate_setStartRotationRate).
		endClass().
		deriveClass<UParticleModuleMeshRotationRate_Seeded, UParticleModuleMeshRotationRate>("ParticleModuleMeshRotationRate_Seeded").
			addProperty("RandomSeedInfo", &ParticleModuleHelper::ParticleModuleMeshRotationRate_Seeded_getRandomSeedInfo, &ParticleModuleHelper::ParticleModuleMeshRotationRate_Seeded_setRandomSeedInfo).
		endClass().
		deriveClass<UParticleModuleMeshRotationRateMultiplyLife, UParticleModuleRotationRateBase>("ParticleModuleMeshRotationRateMultiplyLife").
			addProperty("LifeMultiplier", &ParticleModuleHelper::ParticleModuleMeshRotationRateMultiplyLife_getLifeMultiplier, &ParticleModuleHelper::ParticleModuleMeshRotationRateMultiplyLife_setLifeMultiplier).
		endClass().
		deriveClass<UParticleModuleMeshRotationRateOverLife, UParticleModuleRotationRateBase>("ParticleModuleMeshRotationRateOverLife").
			addProperty("RotRate", &ParticleModuleHelper::ParticleModuleMeshRotationRateOverLife_getRotRate, &ParticleModuleHelper::ParticleModuleMeshRotationRateOverLife_setRotRate).
			addProperty("bScaleRotRate", &ParticleModuleHelper::ParticleModuleMeshRotationRateOverLife_getbScaleRotRate, &ParticleModuleHelper::ParticleModuleMeshRotationRateOverLife_setbScaleRotRate).
		endClass().
		deriveClass<UParticleModuleRotationRate, UParticleModuleRotationRateBase>("ParticleModuleRotationRate").
			addProperty("StartRotationRate", &ParticleModuleHelper::ParticleModuleRotationRate_getStartRotationRate, &ParticleModuleHelper::ParticleModuleRotationRate_setStartRotationRate).
		endClass().
		deriveClass<UParticleModuleRotationRate_Seeded, UParticleModuleRotationRate>("ParticleModuleRotationRate_Seeded").
			addProperty("RandomSeedInfo", &ParticleModuleHelper::ParticleModuleRotationRate_Seeded_getRandomSeedInfo, &ParticleModuleHelper::ParticleModuleRotationRate_Seeded_setRandomSeedInfo).
		endClass().
		deriveClass<UParticleModuleRotationRateMultiplyLife, UParticleModuleRotationRateBase>("ParticleModuleRotationRateMultiplyLife").
			addProperty("LifeMultiplier", &ParticleModuleHelper::ParticleModuleRotationRateMultiplyLife_getLifeMultiplier, &ParticleModuleHelper::ParticleModuleRotationRateMultiplyLife_setLifeMultiplier).
		endClass().
		deriveClass<UParticleModuleSizeBase, UParticleModule>("ParticleModuleSizeBase").
		endClass().
		deriveClass<UParticleModuleSize, UParticleModuleSizeBase>("ParticleModuleSize").
			addProperty("StartSize", &ParticleModuleHelper::ParticleModuleSize_getStartSize, &ParticleModuleHelper::ParticleModuleSize_setStartSize).
		endClass().
		deriveClass<UParticleModuleSize_Seeded, UParticleModuleSize>("ParticleModuleSize_Seeded").
			addProperty("RandomSeedInfo", &ParticleModuleHelper::ParticleModuleSize_Seeded_getRandomSeedInfo, &ParticleModuleHelper::ParticleModuleSize_Seeded_setRandomSeedInfo).
		endClass().
		deriveClass<UParticleModuleSizeMultiplyLife, UParticleModuleSizeBase>("ParticleModuleSizeMultiplyLife").
			addProperty("LifeMultiplier", &ParticleModuleHelper::ParticleModuleSizeMultiplyLife_getLifeMultiplier, &ParticleModuleHelper::ParticleModuleSizeMultiplyLife_setLifeMultiplier).
			addProperty("MultiplyX", &ParticleModuleHelper::ParticleModuleSizeMultiplyLife_getMultiplyX, &ParticleModuleHelper::ParticleModuleSizeMultiplyLife_setMultiplyX).
			addProperty("MultiplyY", &ParticleModuleHelper::ParticleModuleSizeMultiplyLife_getMultiplyY, &ParticleModuleHelper::ParticleModuleSizeMultiplyLife_setMultiplyY).
			addProperty("MultiplyZ", &ParticleModuleHelper::ParticleModuleSizeMultiplyLife_getMultiplyZ, &ParticleModuleHelper::ParticleModuleSizeMultiplyLife_setMultiplyZ).
		endClass().
		deriveClass<UParticleModuleSizeMultiplyVelocity, UParticleModuleSizeBase>("ParticleModuleSizeMultiplyVelocity").
			addProperty("VelocityMultiplier", &ParticleModuleHelper::ParticleModuleSizeMultiplyVelocity_getVelocityMultiplier, &ParticleModuleHelper::ParticleModuleSizeMultiplyVelocity_setVelocityMultiplier).
			addProperty("MultiplyX", &ParticleModuleHelper::ParticleModuleSizeMultiplyVelocity_getMultiplyX, &ParticleModuleHelper::ParticleModuleSizeMultiplyVelocity_setMultiplyX).
			addProperty("MultiplyY", &ParticleModuleHelper::ParticleModuleSizeMultiplyVelocity_getMultiplyY, &ParticleModuleHelper::ParticleModuleSizeMultiplyVelocity_setMultiplyY).
			addProperty("MultiplyZ", &ParticleModuleHelper::ParticleModuleSizeMultiplyVelocity_getMultiplyZ, &ParticleModuleHelper::ParticleModuleSizeMultiplyVelocity_setMultiplyZ).
		endClass().
		deriveClass<UParticleModuleSizeScale, UParticleModuleSizeBase>("ParticleModuleSizeScale").
			addProperty("SizeScale", &ParticleModuleHelper::ParticleModuleSizeScale_getSizeScale, &ParticleModuleHelper::ParticleModuleSizeScale_setSizeScale).
			addProperty("EnableX", &ParticleModuleHelper::ParticleModuleSizeScale_getEnableX, &ParticleModuleHelper::ParticleModuleSizeScale_setEnableX).
			addProperty("EnableY", &ParticleModuleHelper::ParticleModuleSizeScale_getEnableY, &ParticleModuleHelper::ParticleModuleSizeScale_setEnableY).
			addProperty("EnableZ", &ParticleModuleHelper::ParticleModuleSizeScale_getEnableZ, &ParticleModuleHelper::ParticleModuleSizeScale_setEnableZ).
		endClass().
		deriveClass<UParticleModuleSizeScaleByTime, UParticleModuleSizeBase>("ParticleModuleSizeScaleByTime").
			addProperty("SizeScaleByTime", &ParticleModuleHelper::ParticleModuleSizeScaleByTime_getSizeScaleByTime, &ParticleModuleHelper::ParticleModuleSizeScaleByTime_setSizeScaleByTime).
			addProperty("bEnableX", &ParticleModuleHelper::ParticleModuleSizeScaleByTime_getbEnableX, &ParticleModuleHelper::ParticleModuleSizeScaleByTime_setbEnableX).
			addProperty("bEnableY", &ParticleModuleHelper::ParticleModuleSizeScaleByTime_getbEnableY, &ParticleModuleHelper::ParticleModuleSizeScaleByTime_setbEnableY).
			addProperty("bEnableZ", &ParticleModuleHelper::ParticleModuleSizeScaleByTime_getbEnableZ, &ParticleModuleHelper::ParticleModuleSizeScaleByTime_setbEnableZ).
		endClass().
		deriveClass<UParticleModuleSpawnBase, UParticleModule>("ParticleModuleSpawnBase").
			addProperty("bProcessSpawnRate", &ParticleModuleHelper::ParticleModuleSpawnBase_getbProcessSpawnRate, &ParticleModuleHelper::ParticleModuleSpawnBase_setbProcessSpawnRate).
			addProperty("bProcessBurstList", &ParticleModuleHelper::ParticleModuleSpawnBase_getbProcessBurstList, &ParticleModuleHelper::ParticleModuleSpawnBase_setbProcessBurstList).
		endClass().
		deriveClass<UParticleModuleSpawn, UParticleModuleSpawnBase>("ParticleModuleSpawn").
			addProperty("Rate", &ParticleModuleHelper::ParticleModuleSpawn_getRate, &ParticleModuleHelper::ParticleModuleSpawn_setRate).
			addProperty("RateScale", &ParticleModuleHelper::ParticleModuleSpawn_getRateScale, &ParticleModuleHelper::ParticleModuleSpawn_setRateScale).
			addData("ParticleBurstMethod", &UParticleModuleSpawn::ParticleBurstMethod).
			addProperty("BurstList", &ParticleModuleHelper::ParticleModuleSpawn_getBurstList, &ParticleModuleHelper::ParticleModuleSpawn_setBurstList).
		endClass().
		deriveClass<UParticleModuleSpawnPerUnit, UParticleModuleSpawnBase>("ParticleModuleSpawnPerUnit").
			addData("UnitScalar", &UParticleModuleSpawnPerUnit::UnitScalar).
			addProperty("SpawnPerUnit", &ParticleModuleHelper::ParticleModuleSpawnPerUnit_getSpawnPerUnit, &ParticleModuleHelper::ParticleModuleSpawnPerUnit_setSpawnPerUnit).
			addProperty("bIgnoreSpawnRateWhenMoving", &ParticleModuleHelper::ParticleModuleSpawnPerUnit_getbIgnoreSpawnRateWhenMoving, &ParticleModuleHelper::ParticleModuleSpawnPerUnit_setbIgnoreSpawnRateWhenMoving).
			addProperty("bIgnoreMovementAlongX", &ParticleModuleHelper::ParticleModuleSpawnPerUnit_getbIgnoreMovementAlongX, &ParticleModuleHelper::ParticleModuleSpawnPerUnit_setbIgnoreMovementAlongX).
			addProperty("bIgnoreMovementAlongY", &ParticleModuleHelper::ParticleModuleSpawnPerUnit_getbIgnoreMovementAlongY, &ParticleModuleHelper::ParticleModuleSpawnPerUnit_setbIgnoreMovementAlongY).
			addProperty("bIgnoreMovementAlongZ", &ParticleModuleHelper::ParticleModuleSpawnPerUnit_getbIgnoreMovementAlongZ, &ParticleModuleHelper::ParticleModuleSpawnPerUnit_setbIgnoreMovementAlongZ).
			addData("MovementTolerance", &UParticleModuleSpawnPerUnit::MovementTolerance).
		endClass().
		deriveClass<UParticleModuleStoreSpawnTimeBase, UParticleModule>("ParticleModuleStoreSpawnTimeBase").
		endClass().
		deriveClass<UParticleModuleStoreSpawnTime, UParticleModuleStoreSpawnTimeBase>("ParticleModuleStoreSpawnTime").
		endClass().
		deriveClass<UParticleModuleSubUVBase, UParticleModule>("ParticleModuleSubUVBase").
		endClass().
		deriveClass<UParticleModuleSubUV, UParticleModuleSubUVBase>("ParticleModuleSubUV").
			addProperty("SubImageIndex", &ParticleModuleHelper::ParticleModuleSubUV_getSubImageIndex, &ParticleModuleHelper::ParticleModuleSubUV_setSubImageIndex).
		endClass().
		deriveClass<UParticleModuleSubUVMovie, UParticleModuleSubUV>("ParticleModuleSubUVMovie").
			addProperty("bUseEmitterTime", &ParticleModuleHelper::ParticleModuleSubUVMovie_getbUseEmitterTime, &ParticleModuleHelper::ParticleModuleSubUVMovie_setbUseEmitterTime).
			addProperty("FrameRate", &ParticleModuleHelper::ParticleModuleSubUVMovie_getFrameRate, &ParticleModuleHelper::ParticleModuleSubUVMovie_setFrameRate).
			addData("StartingFrame", &UParticleModuleSubUVMovie::StartingFrame).
		endClass().
		deriveClass<UParticleModuleSubUVDirect, UParticleModuleSubUVBase>("ParticleModuleSubUVDirect").
			addProperty("SubUVPosition", &ParticleModuleHelper::ParticleModuleSubUVDirect_getSubUVPosition, &ParticleModuleHelper::ParticleModuleSubUVDirect_setSubUVPosition).
			addProperty("SubUVSize", &ParticleModuleHelper::ParticleModuleSubUVDirect_getSubUVSize, &ParticleModuleHelper::ParticleModuleSubUVDirect_setSubUVSize).
		endClass().
		deriveClass<UParticleModuleSubUVSelect, UParticleModuleSubUVBase>("ParticleModuleSubUVSelect").
			addProperty("SubImageSelect", &ParticleModuleHelper::ParticleModuleSubUVSelect_getSubImageSelect, &ParticleModuleHelper::ParticleModuleSubUVSelect_setSubImageSelect).
		endClass().
		deriveClass<UParticleModuleTrailBase, UParticleModule>("ParticleModuleTrailBase").
		endClass().
		deriveClass<UParticleModuleTrailSource, UParticleModuleTrailBase>("ParticleModuleTrailSource").
			addData("SourceMethod", &UParticleModuleTrailSource::SourceMethod).
			addData("SelectionMethod", &UParticleModuleTrailSource::SelectionMethod).
			addProperty("SourceName", &ParticleModuleHelper::ParticleModuleTrailSource_getSourceName, &ParticleModuleHelper::ParticleModuleTrailSource_setSourceName).
			addProperty("SourceStrength", &ParticleModuleHelper::ParticleModuleTrailSource_getSourceStrength, &ParticleModuleHelper::ParticleModuleTrailSource_setSourceStrength).
			addProperty("bLockSourceStength", &ParticleModuleHelper::ParticleModuleTrailSource_getbLockSourceStength, &ParticleModuleHelper::ParticleModuleTrailSource_setbLockSourceStength).
			addProperty("bInheritRotation", &ParticleModuleHelper::ParticleModuleTrailSource_getbInheritRotation, &ParticleModuleHelper::ParticleModuleTrailSource_setbInheritRotation).
			addData("SourceOffsetCount", &UParticleModuleTrailSource::SourceOffsetCount).
			addProperty("SourceOffsetDefaults", &ParticleModuleHelper::ParticleModuleTrailSource_getSourceOffsetDefaults, &ParticleModuleHelper::ParticleModuleTrailSource_setSourceOffsetDefaults).
		endClass().
		deriveClass<UParticleModuleTrailSpawn, UParticleModuleTrailBase>("ParticleModuleTrailSpawn").
			addData("SpawnDistanceMap", &UParticleModuleTrailSpawn::SpawnDistanceMap).
			addData("MinSpawnVelocity", &UParticleModuleTrailSpawn::MinSpawnVelocity).
		endClass().
		deriveClass<UParticleModuleTrailTaper, UParticleModuleTrailBase>("ParticleModuleTrailTaper").
			addData("TaperMethod", &UParticleModuleTrailTaper::TaperMethod).
			addProperty("TaperFactor", &ParticleModuleHelper::ParticleModuleTrailTaper_getTaperFactor, &ParticleModuleHelper::ParticleModuleTrailTaper_setTaperFactor).
		endClass().
		deriveClass<UParticleModuleTypeDataBase, UParticleModule>("ParticleModuleTypeDataBase").
		endClass().
		deriveClass<UParticleModuleTypeDataAnimTrail, UParticleModuleTypeDataBase>("ParticleModuleTypeDataAnimTrail").
			addProperty("ControlEdgeName", &ParticleModuleHelper::ParticleModuleTypeDataAnimTrail_getControlEdgeName, &ParticleModuleHelper::ParticleModuleTypeDataAnimTrail_setControlEdgeName).
			addData("SheetsPerTrail", &UParticleModuleTypeDataAnimTrail::SheetsPerTrail).
			addProperty("bDeadTrailsOnDeactivate", &ParticleModuleHelper::ParticleModuleTypeDataAnimTrail_getbDeadTrailsOnDeactivate, &ParticleModuleHelper::ParticleModuleTypeDataAnimTrail_setbDeadTrailsOnDeactivate).
			addProperty("bClipSourceSegement", &ParticleModuleHelper::ParticleModuleTypeDataAnimTrail_getbClipSourceSegement, &ParticleModuleHelper::ParticleModuleTypeDataAnimTrail_setbClipSourceSegement).
			addProperty("bEnablePreviousTangentRecalculation", &ParticleModuleHelper::ParticleModuleTypeDataAnimTrail_getbEnablePreviousTangentRecalculation, &ParticleModuleHelper::ParticleModuleTypeDataAnimTrail_setbEnablePreviousTangentRecalculation).
			addProperty("bTangentRecalculationEveryFrame", &ParticleModuleHelper::ParticleModuleTypeDataAnimTrail_getbTangentRecalculationEveryFrame, &ParticleModuleHelper::ParticleModuleTypeDataAnimTrail_setbTangentRecalculationEveryFrame).
			addProperty("bRenderGeometry", &ParticleModuleHelper::ParticleModuleTypeDataAnimTrail_getbRenderGeometry, &ParticleModuleHelper::ParticleModuleTypeDataAnimTrail_setbRenderGeometry).
			addProperty("bRenderSpawnPoints", &ParticleModuleHelper::ParticleModuleTypeDataAnimTrail_getbRenderSpawnPoints, &ParticleModuleHelper::ParticleModuleTypeDataAnimTrail_setbRenderSpawnPoints).
			addProperty("bRenderTangents", &ParticleModuleHelper::ParticleModuleTypeDataAnimTrail_getbRenderTangents, &ParticleModuleHelper::ParticleModuleTypeDataAnimTrail_setbRenderTangents).
			addProperty("bRenderTessellation", &ParticleModuleHelper::ParticleModuleTypeDataAnimTrail_getbRenderTessellation, &ParticleModuleHelper::ParticleModuleTypeDataAnimTrail_setbRenderTessellation).
			addData("TilingDistance", &UParticleModuleTypeDataAnimTrail::TilingDistance).
			addData("DistanceTessellationStepSize", &UParticleModuleTypeDataAnimTrail::DistanceTessellationStepSize).
			addData("TangentTessellationScalar", &UParticleModuleTypeDataAnimTrail::TangentTessellationScalar).
		endClass().
		deriveClass<UParticleModuleTypeDataApex, UParticleModuleTypeDataBase>("ParticleModuleTypeDataApex").
			addData("ApexIOFX", &UParticleModuleTypeDataApex::ApexIOFX).
			addData("ApexEmitter", &UParticleModuleTypeDataApex::ApexEmitter).
		endClass().
		deriveClass<UParticleModuleTypeDataBeam, UParticleModuleTypeDataBase>("ParticleModuleTypeDataBeam").
			addData("BeamMethod", &UParticleModuleTypeDataBeam::BeamMethod).
			addData("EndPointMethod", &UParticleModuleTypeDataBeam::EndPointMethod).
			addProperty("Distance", &ParticleModuleHelper::ParticleModuleTypeDataBeam_getDistance, &ParticleModuleHelper::ParticleModuleTypeDataBeam_setDistance).
			addProperty("EndPoint", &ParticleModuleHelper::ParticleModuleTypeDataBeam_getEndPoint, &ParticleModuleHelper::ParticleModuleTypeDataBeam_setEndPoint).
			addData("TessellationFactor", &UParticleModuleTypeDataBeam::TessellationFactor).
			addProperty("EmitterStrength", &ParticleModuleHelper::ParticleModuleTypeDataBeam_getEmitterStrength, &ParticleModuleHelper::ParticleModuleTypeDataBeam_setEmitterStrength).
			addProperty("TargetStrength", &ParticleModuleHelper::ParticleModuleTypeDataBeam_getTargetStrength, &ParticleModuleHelper::ParticleModuleTypeDataBeam_setTargetStrength).
			addProperty("EndPointDirection", &ParticleModuleHelper::ParticleModuleTypeDataBeam_getEndPointDirection, &ParticleModuleHelper::ParticleModuleTypeDataBeam_setEndPointDirection).
			addData("TextureTile", &UParticleModuleTypeDataBeam::TextureTile).
			addProperty("RenderGeometry", &ParticleModuleHelper::ParticleModuleTypeDataBeam_getRenderGeometry, &ParticleModuleHelper::ParticleModuleTypeDataBeam_setRenderGeometry).
			addProperty("RenderDirectLine", &ParticleModuleHelper::ParticleModuleTypeDataBeam_getRenderDirectLine, &ParticleModuleHelper::ParticleModuleTypeDataBeam_setRenderDirectLine).
			addProperty("RenderLines", &ParticleModuleHelper::ParticleModuleTypeDataBeam_getRenderLines, &ParticleModuleHelper::ParticleModuleTypeDataBeam_setRenderLines).
			addProperty("RenderTessellation", &ParticleModuleHelper::ParticleModuleTypeDataBeam_getRenderTessellation, &ParticleModuleHelper::ParticleModuleTypeDataBeam_setRenderTessellation).
		endClass().
		deriveClass<UParticleModuleTypeDataBeam2, UParticleModuleTypeDataBase>("ParticleModuleTypeDataBeam2").
			addData("BeamMethod", &UParticleModuleTypeDataBeam2::BeamMethod).
			addData("TaperMethod", &UParticleModuleTypeDataBeam2::TaperMethod).
			addData("TextureTile", &UParticleModuleTypeDataBeam2::TextureTile).
			addData("TextureTileDistance", &UParticleModuleTypeDataBeam2::TextureTileDistance).
			addData("Sheets", &UParticleModuleTypeDataBeam2::Sheets).
			addData("MaxBeamCount", &UParticleModuleTypeDataBeam2::MaxBeamCount).
			addData("Speed", &UParticleModuleTypeDataBeam2::Speed).
			addData("InterpolationPoints", &UParticleModuleTypeDataBeam2::InterpolationPoints).
			addProperty("bAlwaysOn", &ParticleModuleHelper::ParticleModuleTypeDataBeam2_getbAlwaysOn, &ParticleModuleHelper::ParticleModuleTypeDataBeam2_setbAlwaysOn).
			addProperty("RenderGeometry", &ParticleModuleHelper::ParticleModuleTypeDataBeam2_getRenderGeometry, &ParticleModuleHelper::ParticleModuleTypeDataBeam2_setRenderGeometry).
			addProperty("RenderDirectLine", &ParticleModuleHelper::ParticleModuleTypeDataBeam2_getRenderDirectLine, &ParticleModuleHelper::ParticleModuleTypeDataBeam2_setRenderDirectLine).
			addProperty("RenderLines", &ParticleModuleHelper::ParticleModuleTypeDataBeam2_getRenderLines, &ParticleModuleHelper::ParticleModuleTypeDataBeam2_setRenderLines).
			addProperty("RenderTessellation", &ParticleModuleHelper::ParticleModuleTypeDataBeam2_getRenderTessellation, &ParticleModuleHelper::ParticleModuleTypeDataBeam2_setRenderTessellation).
			addData("UpVectorStepSize", &UParticleModuleTypeDataBeam2::UpVectorStepSize).
			addProperty("BranchParentName", &ParticleModuleHelper::ParticleModuleTypeDataBeam2_getBranchParentName, &ParticleModuleHelper::ParticleModuleTypeDataBeam2_setBranchParentName).
			addProperty("Distance", &ParticleModuleHelper::ParticleModuleTypeDataBeam2_getDistance, &ParticleModuleHelper::ParticleModuleTypeDataBeam2_setDistance).
			addProperty("TaperFactor", &ParticleModuleHelper::ParticleModuleTypeDataBeam2_getTaperFactor, &ParticleModuleHelper::ParticleModuleTypeDataBeam2_setTaperFactor).
			addProperty("TaperScale", &ParticleModuleHelper::ParticleModuleTypeDataBeam2_getTaperScale, &ParticleModuleHelper::ParticleModuleTypeDataBeam2_setTaperScale).
		endClass().
		deriveClass<UParticleModuleTypeDataMesh, UParticleModuleTypeDataBase>("ParticleModuleTypeDataMesh").
			addData("Mesh", &UParticleModuleTypeDataMesh::Mesh).
			addProperty("CastShadows", &ParticleModuleHelper::ParticleModuleTypeDataMesh_getCastShadows, &ParticleModuleHelper::ParticleModuleTypeDataMesh_setCastShadows).
			addProperty("DoCollisions", &ParticleModuleHelper::ParticleModuleTypeDataMesh_getDoCollisions, &ParticleModuleHelper::ParticleModuleTypeDataMesh_setDoCollisions).
			addProperty("bAllowMotionBlur", &ParticleModuleHelper::ParticleModuleTypeDataMesh_getbAllowMotionBlur, &ParticleModuleHelper::ParticleModuleTypeDataMesh_setbAllowMotionBlur).
			addProperty("bOverrideMaterial", &ParticleModuleHelper::ParticleModuleTypeDataMesh_getbOverrideMaterial, &ParticleModuleHelper::ParticleModuleTypeDataMesh_setbOverrideMaterial).
			addProperty("bCameraFacing", &ParticleModuleHelper::ParticleModuleTypeDataMesh_getbCameraFacing, &ParticleModuleHelper::ParticleModuleTypeDataMesh_setbCameraFacing).
			addProperty("bApplyParticleRotationAsSpin", &ParticleModuleHelper::ParticleModuleTypeDataMesh_getbApplyParticleRotationAsSpin, &ParticleModuleHelper::ParticleModuleTypeDataMesh_setbApplyParticleRotationAsSpin).
			addData("MeshAlignment", &UParticleModuleTypeDataMesh::MeshAlignment).
			addData("AxisLockOption", &UParticleModuleTypeDataMesh::AxisLockOption).
			addData("CameraFacingUpAxisOption", &UParticleModuleTypeDataMesh::CameraFacingUpAxisOption).
			addData("CameraFacingOption", &UParticleModuleTypeDataMesh::CameraFacingOption).
			addData("Pitch", &UParticleModuleTypeDataMesh::Pitch).
			addData("Roll", &UParticleModuleTypeDataMesh::Roll).
			addData("Yaw", &UParticleModuleTypeDataMesh::Yaw).
		endClass().
		deriveClass<UParticleModuleTypeDataMeshPhysX, UParticleModuleTypeDataMesh>("ParticleModuleTypeDataMeshPhysX").
			addData("PhysXParSys", &UParticleModuleTypeDataMeshPhysX::PhysXParSys).
			addData("PhysXRotationMethod", &UParticleModuleTypeDataMeshPhysX::PhysXRotationMethod).
			addData("FluidRotationCoefficient", &UParticleModuleTypeDataMeshPhysX::FluidRotationCoefficient).
			addProperty("RenderInstance", &ParticleModuleHelper::ParticleModuleTypeDataMeshPhysX_getRenderInstance, &ParticleModuleHelper::ParticleModuleTypeDataMeshPhysX_setRenderInstance).
			addProperty("VerticalLod", &ParticleModuleHelper::ParticleModuleTypeDataMeshPhysX_getVerticalLod, &ParticleModuleHelper::ParticleModuleTypeDataMeshPhysX_setVerticalLod).
		endClass().
		deriveClass<UParticleModuleTypeDataPhysX, UParticleModuleTypeDataBase>("ParticleModuleTypeDataPhysX").
			addData("PhysXParSys", &UParticleModuleTypeDataPhysX::PhysXParSys).
			addProperty("VerticalLod", &ParticleModuleHelper::ParticleModuleTypeDataPhysX_getVerticalLod, &ParticleModuleHelper::ParticleModuleTypeDataPhysX_setVerticalLod).
		endClass().
		deriveClass<UParticleModuleTypeDataRibbon, UParticleModuleTypeDataBase>("ParticleModuleTypeDataRibbon").
			addData("MaxTessellationBetweenParticles", &UParticleModuleTypeDataRibbon::MaxTessellationBetweenParticles).
			addData("SheetsPerTrail", &UParticleModuleTypeDataRibbon::SheetsPerTrail).
			addData("MaxTrailCount", &UParticleModuleTypeDataRibbon::MaxTrailCount).
			addData("MaxParticleInTrailCount", &UParticleModuleTypeDataRibbon::MaxParticleInTrailCount).
			addProperty("bDeadTrailsOnDeactivate", &ParticleModuleHelper::ParticleModuleTypeDataRibbon_getbDeadTrailsOnDeactivate, &ParticleModuleHelper::ParticleModuleTypeDataRibbon_setbDeadTrailsOnDeactivate).
			addProperty("bDeadTrailsOnSourceLoss", &ParticleModuleHelper::ParticleModuleTypeDataRibbon_getbDeadTrailsOnSourceLoss, &ParticleModuleHelper::ParticleModuleTypeDataRibbon_setbDeadTrailsOnSourceLoss).
			addProperty("bClipSourceSegement", &ParticleModuleHelper::ParticleModuleTypeDataRibbon_getbClipSourceSegement, &ParticleModuleHelper::ParticleModuleTypeDataRibbon_setbClipSourceSegement).
			addProperty("bEnablePreviousTangentRecalculation", &ParticleModuleHelper::ParticleModuleTypeDataRibbon_getbEnablePreviousTangentRecalculation, &ParticleModuleHelper::ParticleModuleTypeDataRibbon_setbEnablePreviousTangentRecalculation).
			addProperty("bTangentRecalculationEveryFrame", &ParticleModuleHelper::ParticleModuleTypeDataRibbon_getbTangentRecalculationEveryFrame, &ParticleModuleHelper::ParticleModuleTypeDataRibbon_setbTangentRecalculationEveryFrame).
			addProperty("bRenderGeometry", &ParticleModuleHelper::ParticleModuleTypeDataRibbon_getbRenderGeometry, &ParticleModuleHelper::ParticleModuleTypeDataRibbon_setbRenderGeometry).
			addProperty("bRenderSpawnPoints", &ParticleModuleHelper::ParticleModuleTypeDataRibbon_getbRenderSpawnPoints, &ParticleModuleHelper::ParticleModuleTypeDataRibbon_setbRenderSpawnPoints).
			addProperty("bRenderTangents", &ParticleModuleHelper::ParticleModuleTypeDataRibbon_getbRenderTangents, &ParticleModuleHelper::ParticleModuleTypeDataRibbon_setbRenderTangents).
			addProperty("bRenderTessellation", &ParticleModuleHelper::ParticleModuleTypeDataRibbon_getbRenderTessellation, &ParticleModuleHelper::ParticleModuleTypeDataRibbon_setbRenderTessellation).
			addData("RenderAxis", &UParticleModuleTypeDataRibbon::RenderAxis).
			addData("TangentSpawningScalar", &UParticleModuleTypeDataRibbon::TangentSpawningScalar).
			addData("TilingDistance", &UParticleModuleTypeDataRibbon::TilingDistance).
			addData("DistanceTessellationStepSize", &UParticleModuleTypeDataRibbon::DistanceTessellationStepSize).
			addData("TangentTessellationScalar", &UParticleModuleTypeDataRibbon::TangentTessellationScalar).
		endClass().
		deriveClass<UParticleModuleTypeDataTrail, UParticleModuleTypeDataBase>("ParticleModuleTypeDataTrail").
			addProperty("RenderGeometry", &ParticleModuleHelper::ParticleModuleTypeDataTrail_getRenderGeometry, &ParticleModuleHelper::ParticleModuleTypeDataTrail_setRenderGeometry).
			addProperty("RenderLines", &ParticleModuleHelper::ParticleModuleTypeDataTrail_getRenderLines, &ParticleModuleHelper::ParticleModuleTypeDataTrail_setRenderLines).
			addProperty("RenderTessellation", &ParticleModuleHelper::ParticleModuleTypeDataTrail_getRenderTessellation, &ParticleModuleHelper::ParticleModuleTypeDataTrail_setRenderTessellation).
			addProperty("Tapered", &ParticleModuleHelper::ParticleModuleTypeDataTrail_getTapered, &ParticleModuleHelper::ParticleModuleTypeDataTrail_setTapered).
			addProperty("SpawnByDistance", &ParticleModuleHelper::ParticleModuleTypeDataTrail_getSpawnByDistance, &ParticleModuleHelper::ParticleModuleTypeDataTrail_setSpawnByDistance).
			addData("TessellationFactor", &UParticleModuleTypeDataTrail::TessellationFactor).
			addProperty("Tension", &ParticleModuleHelper::ParticleModuleTypeDataTrail_getTension, &ParticleModuleHelper::ParticleModuleTypeDataTrail_setTension).
			addProperty("SpawnDistance", &ParticleModuleHelper::ParticleModuleTypeDataTrail_getSpawnDistance, &ParticleModuleHelper::ParticleModuleTypeDataTrail_setSpawnDistance).
		endClass().
		deriveClass<UParticleModuleTypeDataTrail2, UParticleModuleTypeDataBase>("ParticleModuleTypeDataTrail2").
			addData("TessellationFactor", &UParticleModuleTypeDataTrail2::TessellationFactor).
			addData("TessellationFactorDistance", &UParticleModuleTypeDataTrail2::TessellationFactorDistance).
			addData("TessellationStrength", &UParticleModuleTypeDataTrail2::TessellationStrength).
			addData("TextureTile", &UParticleModuleTypeDataTrail2::TextureTile).
			addData("Sheets", &UParticleModuleTypeDataTrail2::Sheets).
			addData("MaxTrailCount", &UParticleModuleTypeDataTrail2::MaxTrailCount).
			addData("MaxParticleInTrailCount", &UParticleModuleTypeDataTrail2::MaxParticleInTrailCount).
			addProperty("bClipSourceSegement", &ParticleModuleHelper::ParticleModuleTypeDataTrail2_getbClipSourceSegement, &ParticleModuleHelper::ParticleModuleTypeDataTrail2_setbClipSourceSegement).
			addProperty("bClearTangents", &ParticleModuleHelper::ParticleModuleTypeDataTrail2_getbClearTangents, &ParticleModuleHelper::ParticleModuleTypeDataTrail2_setbClearTangents).
			addProperty("RenderGeometry", &ParticleModuleHelper::ParticleModuleTypeDataTrail2_getRenderGeometry, &ParticleModuleHelper::ParticleModuleTypeDataTrail2_setRenderGeometry).
			addProperty("RenderDirectLine", &ParticleModuleHelper::ParticleModuleTypeDataTrail2_getRenderDirectLine, &ParticleModuleHelper::ParticleModuleTypeDataTrail2_setRenderDirectLine).
			addProperty("RenderLines", &ParticleModuleHelper::ParticleModuleTypeDataTrail2_getRenderLines, &ParticleModuleHelper::ParticleModuleTypeDataTrail2_setRenderLines).
			addProperty("RenderTessellation", &ParticleModuleHelper::ParticleModuleTypeDataTrail2_getRenderTessellation, &ParticleModuleHelper::ParticleModuleTypeDataTrail2_setRenderTessellation).
		endClass().
		deriveClass<UParticleModuleUberBase, UParticleModule>("ParticleModuleUberBase").
			addProperty("RequiredModules", &ParticleModuleHelper::ParticleModuleUberBase_getRequiredModules, &ParticleModuleHelper::ParticleModuleUberBase_setRequiredModules).
		endClass().
		deriveClass<UParticleModuleUberLTISIVCL, UParticleModuleUberBase>("ParticleModuleUberLTISIVCL").
			addProperty("Lifetime", &ParticleModuleHelper::ParticleModuleUberLTISIVCL_getLifetime, &ParticleModuleHelper::ParticleModuleUberLTISIVCL_setLifetime).
			addProperty("StartSize", &ParticleModuleHelper::ParticleModuleUberLTISIVCL_getStartSize, &ParticleModuleHelper::ParticleModuleUberLTISIVCL_setStartSize).
			addProperty("StartVelocity", &ParticleModuleHelper::ParticleModuleUberLTISIVCL_getStartVelocity, &ParticleModuleHelper::ParticleModuleUberLTISIVCL_setStartVelocity).
			addProperty("StartVelocityRadial", &ParticleModuleHelper::ParticleModuleUberLTISIVCL_getStartVelocityRadial, &ParticleModuleHelper::ParticleModuleUberLTISIVCL_setStartVelocityRadial).
			addProperty("ColorOverLife", &ParticleModuleHelper::ParticleModuleUberLTISIVCL_getColorOverLife, &ParticleModuleHelper::ParticleModuleUberLTISIVCL_setColorOverLife).
			addProperty("AlphaOverLife", &ParticleModuleHelper::ParticleModuleUberLTISIVCL_getAlphaOverLife, &ParticleModuleHelper::ParticleModuleUberLTISIVCL_setAlphaOverLife).
		endClass().
		deriveClass<UParticleModuleUberLTISIVCLIL, UParticleModuleUberBase>("ParticleModuleUberLTISIVCLIL").
			addProperty("Lifetime", &ParticleModuleHelper::ParticleModuleUberLTISIVCLIL_getLifetime, &ParticleModuleHelper::ParticleModuleUberLTISIVCLIL_setLifetime).
			addProperty("StartSize", &ParticleModuleHelper::ParticleModuleUberLTISIVCLIL_getStartSize, &ParticleModuleHelper::ParticleModuleUberLTISIVCLIL_setStartSize).
			addProperty("StartVelocity", &ParticleModuleHelper::ParticleModuleUberLTISIVCLIL_getStartVelocity, &ParticleModuleHelper::ParticleModuleUberLTISIVCLIL_setStartVelocity).
			addProperty("StartVelocityRadial", &ParticleModuleHelper::ParticleModuleUberLTISIVCLIL_getStartVelocityRadial, &ParticleModuleHelper::ParticleModuleUberLTISIVCLIL_setStartVelocityRadial).
			addProperty("ColorOverLife", &ParticleModuleHelper::ParticleModuleUberLTISIVCLIL_getColorOverLife, &ParticleModuleHelper::ParticleModuleUberLTISIVCLIL_setColorOverLife).
			addProperty("AlphaOverLife", &ParticleModuleHelper::ParticleModuleUberLTISIVCLIL_getAlphaOverLife, &ParticleModuleHelper::ParticleModuleUberLTISIVCLIL_setAlphaOverLife).
			addProperty("StartLocation", &ParticleModuleHelper::ParticleModuleUberLTISIVCLIL_getStartLocation, &ParticleModuleHelper::ParticleModuleUberLTISIVCLIL_setStartLocation).
		endClass().
		deriveClass<UParticleModuleUberLTISIVCLILIRSSBLIRR, UParticleModuleUberBase>("ParticleModuleUberLTISIVCLILIRSSBLIRR").
			addProperty("Lifetime", &ParticleModuleHelper::ParticleModuleUberLTISIVCLILIRSSBLIRR_getLifetime, &ParticleModuleHelper::ParticleModuleUberLTISIVCLILIRSSBLIRR_setLifetime).
			addProperty("StartSize", &ParticleModuleHelper::ParticleModuleUberLTISIVCLILIRSSBLIRR_getStartSize, &ParticleModuleHelper::ParticleModuleUberLTISIVCLILIRSSBLIRR_setStartSize).
			addProperty("StartVelocity", &ParticleModuleHelper::ParticleModuleUberLTISIVCLILIRSSBLIRR_getStartVelocity, &ParticleModuleHelper::ParticleModuleUberLTISIVCLILIRSSBLIRR_setStartVelocity).
			addProperty("StartVelocityRadial", &ParticleModuleHelper::ParticleModuleUberLTISIVCLILIRSSBLIRR_getStartVelocityRadial, &ParticleModuleHelper::ParticleModuleUberLTISIVCLILIRSSBLIRR_setStartVelocityRadial).
			addProperty("ColorOverLife", &ParticleModuleHelper::ParticleModuleUberLTISIVCLILIRSSBLIRR_getColorOverLife, &ParticleModuleHelper::ParticleModuleUberLTISIVCLILIRSSBLIRR_setColorOverLife).
			addProperty("AlphaOverLife", &ParticleModuleHelper::ParticleModuleUberLTISIVCLILIRSSBLIRR_getAlphaOverLife, &ParticleModuleHelper::ParticleModuleUberLTISIVCLILIRSSBLIRR_setAlphaOverLife).
			addProperty("StartLocation", &ParticleModuleHelper::ParticleModuleUberLTISIVCLILIRSSBLIRR_getStartLocation, &ParticleModuleHelper::ParticleModuleUberLTISIVCLILIRSSBLIRR_setStartLocation).
			addProperty("StartRotation", &ParticleModuleHelper::ParticleModuleUberLTISIVCLILIRSSBLIRR_getStartRotation, &ParticleModuleHelper::ParticleModuleUberLTISIVCLILIRSSBLIRR_setStartRotation).
			addProperty("SizeLifeMultiplier", &ParticleModuleHelper::ParticleModuleUberLTISIVCLILIRSSBLIRR_getSizeLifeMultiplier, &ParticleModuleHelper::ParticleModuleUberLTISIVCLILIRSSBLIRR_setSizeLifeMultiplier).
			addProperty("SizeMultiplyX", &ParticleModuleHelper::ParticleModuleUberLTISIVCLILIRSSBLIRR_getSizeMultiplyX, &ParticleModuleHelper::ParticleModuleUberLTISIVCLILIRSSBLIRR_setSizeMultiplyX).
			addProperty("SizeMultiplyY", &ParticleModuleHelper::ParticleModuleUberLTISIVCLILIRSSBLIRR_getSizeMultiplyY, &ParticleModuleHelper::ParticleModuleUberLTISIVCLILIRSSBLIRR_setSizeMultiplyY).
			addProperty("SizeMultiplyZ", &ParticleModuleHelper::ParticleModuleUberLTISIVCLILIRSSBLIRR_getSizeMultiplyZ, &ParticleModuleHelper::ParticleModuleUberLTISIVCLILIRSSBLIRR_setSizeMultiplyZ).
			addProperty("StartRotationRate", &ParticleModuleHelper::ParticleModuleUberLTISIVCLILIRSSBLIRR_getStartRotationRate, &ParticleModuleHelper::ParticleModuleUberLTISIVCLILIRSSBLIRR_setStartRotationRate).
		endClass().
		deriveClass<UParticleModuleUberRainDrops, UParticleModuleUberBase>("ParticleModuleUberRainDrops").
			addData("LifetimeMin", &UParticleModuleUberRainDrops::LifetimeMin).
			addData("LifetimeMax", &UParticleModuleUberRainDrops::LifetimeMax).
			addProperty("StartSizeMin", &ParticleModuleHelper::ParticleModuleUberRainDrops_getStartSizeMin, &ParticleModuleHelper::ParticleModuleUberRainDrops_setStartSizeMin).
			addProperty("StartSizeMax", &ParticleModuleHelper::ParticleModuleUberRainDrops_getStartSizeMax, &ParticleModuleHelper::ParticleModuleUberRainDrops_setStartSizeMax).
			addProperty("StartVelocityMin", &ParticleModuleHelper::ParticleModuleUberRainDrops_getStartVelocityMin, &ParticleModuleHelper::ParticleModuleUberRainDrops_setStartVelocityMin).
			addProperty("StartVelocityMax", &ParticleModuleHelper::ParticleModuleUberRainDrops_getStartVelocityMax, &ParticleModuleHelper::ParticleModuleUberRainDrops_setStartVelocityMax).
			addData("StartVelocityRadialMin", &UParticleModuleUberRainDrops::StartVelocityRadialMin).
			addData("StartVelocityRadialMax", &UParticleModuleUberRainDrops::StartVelocityRadialMax).
			addProperty("ColorOverLife", &ParticleModuleHelper::ParticleModuleUberRainDrops_getColorOverLife, &ParticleModuleHelper::ParticleModuleUberRainDrops_setColorOverLife).
			addData("AlphaOverLife", &UParticleModuleUberRainDrops::AlphaOverLife).
			addProperty("bIsUsingCylinder", &ParticleModuleHelper::ParticleModuleUberRainDrops_getbIsUsingCylinder, &ParticleModuleHelper::ParticleModuleUberRainDrops_setbIsUsingCylinder).
			addProperty("bPositive_X", &ParticleModuleHelper::ParticleModuleUberRainDrops_getbPositive_X, &ParticleModuleHelper::ParticleModuleUberRainDrops_setbPositive_X).
			addProperty("bPositive_Y", &ParticleModuleHelper::ParticleModuleUberRainDrops_getbPositive_Y, &ParticleModuleHelper::ParticleModuleUberRainDrops_setbPositive_Y).
			addProperty("bPositive_Z", &ParticleModuleHelper::ParticleModuleUberRainDrops_getbPositive_Z, &ParticleModuleHelper::ParticleModuleUberRainDrops_setbPositive_Z).
			addProperty("bNegative_X", &ParticleModuleHelper::ParticleModuleUberRainDrops_getbNegative_X, &ParticleModuleHelper::ParticleModuleUberRainDrops_setbNegative_X).
			addProperty("bNegative_Y", &ParticleModuleHelper::ParticleModuleUberRainDrops_getbNegative_Y, &ParticleModuleHelper::ParticleModuleUberRainDrops_setbNegative_Y).
			addProperty("bNegative_Z", &ParticleModuleHelper::ParticleModuleUberRainDrops_getbNegative_Z, &ParticleModuleHelper::ParticleModuleUberRainDrops_setbNegative_Z).
			addProperty("bSurfaceOnly", &ParticleModuleHelper::ParticleModuleUberRainDrops_getbSurfaceOnly, &ParticleModuleHelper::ParticleModuleUberRainDrops_setbSurfaceOnly).
			addProperty("bVelocity", &ParticleModuleHelper::ParticleModuleUberRainDrops_getbVelocity, &ParticleModuleHelper::ParticleModuleUberRainDrops_setbVelocity).
			addProperty("bRadialVelocity", &ParticleModuleHelper::ParticleModuleUberRainDrops_getbRadialVelocity, &ParticleModuleHelper::ParticleModuleUberRainDrops_setbRadialVelocity).
			addData("PC_VelocityScale", &UParticleModuleUberRainDrops::PC_VelocityScale).
			addProperty("PC_StartLocation", &ParticleModuleHelper::ParticleModuleUberRainDrops_getPC_StartLocation, &ParticleModuleHelper::ParticleModuleUberRainDrops_setPC_StartLocation).
			addData("PC_StartRadius", &UParticleModuleUberRainDrops::PC_StartRadius).
			addData("PC_StartHeight", &UParticleModuleUberRainDrops::PC_StartHeight).
			addData("PC_HeightAxis", &UParticleModuleUberRainDrops::PC_HeightAxis).
			addProperty("StartLocationMin", &ParticleModuleHelper::ParticleModuleUberRainDrops_getStartLocationMin, &ParticleModuleHelper::ParticleModuleUberRainDrops_setStartLocationMin).
			addProperty("StartLocationMax", &ParticleModuleHelper::ParticleModuleUberRainDrops_getStartLocationMax, &ParticleModuleHelper::ParticleModuleUberRainDrops_setStartLocationMax).
		endClass().
		deriveClass<UParticleModuleUberRainImpacts, UParticleModuleUberBase>("ParticleModuleUberRainImpacts").
			addProperty("Lifetime", &ParticleModuleHelper::ParticleModuleUberRainImpacts_getLifetime, &ParticleModuleHelper::ParticleModuleUberRainImpacts_setLifetime).
			addProperty("StartSize", &ParticleModuleHelper::ParticleModuleUberRainImpacts_getStartSize, &ParticleModuleHelper::ParticleModuleUberRainImpacts_setStartSize).
			addProperty("StartRotation", &ParticleModuleHelper::ParticleModuleUberRainImpacts_getStartRotation, &ParticleModuleHelper::ParticleModuleUberRainImpacts_setStartRotation).
			addProperty("bInheritParent", &ParticleModuleHelper::ParticleModuleUberRainImpacts_getbInheritParent, &ParticleModuleHelper::ParticleModuleUberRainImpacts_setbInheritParent).
			addProperty("MultiplyX", &ParticleModuleHelper::ParticleModuleUberRainImpacts_getMultiplyX, &ParticleModuleHelper::ParticleModuleUberRainImpacts_setMultiplyX).
			addProperty("MultiplyY", &ParticleModuleHelper::ParticleModuleUberRainImpacts_getMultiplyY, &ParticleModuleHelper::ParticleModuleUberRainImpacts_setMultiplyY).
			addProperty("MultiplyZ", &ParticleModuleHelper::ParticleModuleUberRainImpacts_getMultiplyZ, &ParticleModuleHelper::ParticleModuleUberRainImpacts_setMultiplyZ).
			addProperty("bIsUsingCylinder", &ParticleModuleHelper::ParticleModuleUberRainImpacts_getbIsUsingCylinder, &ParticleModuleHelper::ParticleModuleUberRainImpacts_setbIsUsingCylinder).
			addProperty("bPositive_X", &ParticleModuleHelper::ParticleModuleUberRainImpacts_getbPositive_X, &ParticleModuleHelper::ParticleModuleUberRainImpacts_setbPositive_X).
			addProperty("bPositive_Y", &ParticleModuleHelper::ParticleModuleUberRainImpacts_getbPositive_Y, &ParticleModuleHelper::ParticleModuleUberRainImpacts_setbPositive_Y).
			addProperty("bPositive_Z", &ParticleModuleHelper::ParticleModuleUberRainImpacts_getbPositive_Z, &ParticleModuleHelper::ParticleModuleUberRainImpacts_setbPositive_Z).
			addProperty("bNegative_X", &ParticleModuleHelper::ParticleModuleUberRainImpacts_getbNegative_X, &ParticleModuleHelper::ParticleModuleUberRainImpacts_setbNegative_X).
			addProperty("bNegative_Y", &ParticleModuleHelper::ParticleModuleUberRainImpacts_getbNegative_Y, &ParticleModuleHelper::ParticleModuleUberRainImpacts_setbNegative_Y).
			addProperty("bNegative_Z", &ParticleModuleHelper::ParticleModuleUberRainImpacts_getbNegative_Z, &ParticleModuleHelper::ParticleModuleUberRainImpacts_setbNegative_Z).
			addProperty("bSurfaceOnly", &ParticleModuleHelper::ParticleModuleUberRainImpacts_getbSurfaceOnly, &ParticleModuleHelper::ParticleModuleUberRainImpacts_setbSurfaceOnly).
			addProperty("bVelocity", &ParticleModuleHelper::ParticleModuleUberRainImpacts_getbVelocity, &ParticleModuleHelper::ParticleModuleUberRainImpacts_setbVelocity).
			addProperty("bRadialVelocity", &ParticleModuleHelper::ParticleModuleUberRainImpacts_getbRadialVelocity, &ParticleModuleHelper::ParticleModuleUberRainImpacts_setbRadialVelocity).
			addProperty("LifeMultiplier", &ParticleModuleHelper::ParticleModuleUberRainImpacts_getLifeMultiplier, &ParticleModuleHelper::ParticleModuleUberRainImpacts_setLifeMultiplier).
			addProperty("PC_VelocityScale", &ParticleModuleHelper::ParticleModuleUberRainImpacts_getPC_VelocityScale, &ParticleModuleHelper::ParticleModuleUberRainImpacts_setPC_VelocityScale).
			addProperty("PC_StartLocation", &ParticleModuleHelper::ParticleModuleUberRainImpacts_getPC_StartLocation, &ParticleModuleHelper::ParticleModuleUberRainImpacts_setPC_StartLocation).
			addProperty("PC_StartRadius", &ParticleModuleHelper::ParticleModuleUberRainImpacts_getPC_StartRadius, &ParticleModuleHelper::ParticleModuleUberRainImpacts_setPC_StartRadius).
			addProperty("PC_StartHeight", &ParticleModuleHelper::ParticleModuleUberRainImpacts_getPC_StartHeight, &ParticleModuleHelper::ParticleModuleUberRainImpacts_setPC_StartHeight).
			addData("PC_HeightAxis", &UParticleModuleUberRainImpacts::PC_HeightAxis).
			addProperty("ColorOverLife", &ParticleModuleHelper::ParticleModuleUberRainImpacts_getColorOverLife, &ParticleModuleHelper::ParticleModuleUberRainImpacts_setColorOverLife).
			addProperty("AlphaOverLife", &ParticleModuleHelper::ParticleModuleUberRainImpacts_getAlphaOverLife, &ParticleModuleHelper::ParticleModuleUberRainImpacts_setAlphaOverLife).
		endClass().
		deriveClass<UParticleModuleUberRainSplashA, UParticleModuleUberBase>("ParticleModuleUberRainSplashA").
			addProperty("Lifetime", &ParticleModuleHelper::ParticleModuleUberRainSplashA_getLifetime, &ParticleModuleHelper::ParticleModuleUberRainSplashA_setLifetime).
			addProperty("StartSize", &ParticleModuleHelper::ParticleModuleUberRainSplashA_getStartSize, &ParticleModuleHelper::ParticleModuleUberRainSplashA_setStartSize).
			addProperty("StartRotation", &ParticleModuleHelper::ParticleModuleUberRainSplashA_getStartRotation, &ParticleModuleHelper::ParticleModuleUberRainSplashA_setStartRotation).
			addProperty("bInheritParent", &ParticleModuleHelper::ParticleModuleUberRainSplashA_getbInheritParent, &ParticleModuleHelper::ParticleModuleUberRainSplashA_setbInheritParent).
			addProperty("MultiplyX", &ParticleModuleHelper::ParticleModuleUberRainSplashA_getMultiplyX, &ParticleModuleHelper::ParticleModuleUberRainSplashA_setMultiplyX).
			addProperty("MultiplyY", &ParticleModuleHelper::ParticleModuleUberRainSplashA_getMultiplyY, &ParticleModuleHelper::ParticleModuleUberRainSplashA_setMultiplyY).
			addProperty("MultiplyZ", &ParticleModuleHelper::ParticleModuleUberRainSplashA_getMultiplyZ, &ParticleModuleHelper::ParticleModuleUberRainSplashA_setMultiplyZ).
			addProperty("LifeMultiplier", &ParticleModuleHelper::ParticleModuleUberRainSplashA_getLifeMultiplier, &ParticleModuleHelper::ParticleModuleUberRainSplashA_setLifeMultiplier).
			addProperty("ColorOverLife", &ParticleModuleHelper::ParticleModuleUberRainSplashA_getColorOverLife, &ParticleModuleHelper::ParticleModuleUberRainSplashA_setColorOverLife).
			addProperty("AlphaOverLife", &ParticleModuleHelper::ParticleModuleUberRainSplashA_getAlphaOverLife, &ParticleModuleHelper::ParticleModuleUberRainSplashA_setAlphaOverLife).
		endClass().
		deriveClass<UParticleModuleUberRainSplashB, UParticleModuleUberBase>("ParticleModuleUberRainSplashB").
			addProperty("Lifetime", &ParticleModuleHelper::ParticleModuleUberRainSplashB_getLifetime, &ParticleModuleHelper::ParticleModuleUberRainSplashB_setLifetime).
			addProperty("StartSize", &ParticleModuleHelper::ParticleModuleUberRainSplashB_getStartSize, &ParticleModuleHelper::ParticleModuleUberRainSplashB_setStartSize).
			addProperty("ColorOverLife", &ParticleModuleHelper::ParticleModuleUberRainSplashB_getColorOverLife, &ParticleModuleHelper::ParticleModuleUberRainSplashB_setColorOverLife).
			addProperty("AlphaOverLife", &ParticleModuleHelper::ParticleModuleUberRainSplashB_getAlphaOverLife, &ParticleModuleHelper::ParticleModuleUberRainSplashB_setAlphaOverLife).
			addProperty("LifeMultiplier", &ParticleModuleHelper::ParticleModuleUberRainSplashB_getLifeMultiplier, &ParticleModuleHelper::ParticleModuleUberRainSplashB_setLifeMultiplier).
			addProperty("MultiplyX", &ParticleModuleHelper::ParticleModuleUberRainSplashB_getMultiplyX, &ParticleModuleHelper::ParticleModuleUberRainSplashB_setMultiplyX).
			addProperty("MultiplyY", &ParticleModuleHelper::ParticleModuleUberRainSplashB_getMultiplyY, &ParticleModuleHelper::ParticleModuleUberRainSplashB_setMultiplyY).
			addProperty("MultiplyZ", &ParticleModuleHelper::ParticleModuleUberRainSplashB_getMultiplyZ, &ParticleModuleHelper::ParticleModuleUberRainSplashB_setMultiplyZ).
			addProperty("StartRotationRate", &ParticleModuleHelper::ParticleModuleUberRainSplashB_getStartRotationRate, &ParticleModuleHelper::ParticleModuleUberRainSplashB_setStartRotationRate).
		endClass().
		deriveClass<UParticleModuleVelocityBase, UParticleModule>("ParticleModuleVelocityBase").
			addProperty("bInWorldSpace", &ParticleModuleHelper::ParticleModuleVelocityBase_getbInWorldSpace, &ParticleModuleHelper::ParticleModuleVelocityBase_setbInWorldSpace).
			addProperty("bApplyOwnerScale", &ParticleModuleHelper::ParticleModuleVelocityBase_getbApplyOwnerScale, &ParticleModuleHelper::ParticleModuleVelocityBase_setbApplyOwnerScale).
		endClass().
		deriveClass<UParticleModuleVelocity, UParticleModuleVelocityBase>("ParticleModuleVelocity").
			addProperty("StartVelocity", &ParticleModuleHelper::ParticleModuleVelocity_getStartVelocity, &ParticleModuleHelper::ParticleModuleVelocity_setStartVelocity).
			addProperty("StartVelocityRadial", &ParticleModuleHelper::ParticleModuleVelocity_getStartVelocityRadial, &ParticleModuleHelper::ParticleModuleVelocity_setStartVelocityRadial).
		endClass().
		deriveClass<UParticleModuleVelocity_Seeded, UParticleModuleVelocity>("ParticleModuleVelocity_Seeded").
			addProperty("RandomSeedInfo", &ParticleModuleHelper::ParticleModuleVelocity_Seeded_getRandomSeedInfo, &ParticleModuleHelper::ParticleModuleVelocity_Seeded_setRandomSeedInfo).
		endClass().
		deriveClass<UParticleModuleVelocityInheritParent, UParticleModuleVelocityBase>("ParticleModuleVelocityInheritParent").
			addProperty("Scale", &ParticleModuleHelper::ParticleModuleVelocityInheritParent_getScale, &ParticleModuleHelper::ParticleModuleVelocityInheritParent_setScale).
		endClass().
		deriveClass<UParticleModuleVelocityOverLifetime, UParticleModuleVelocityBase>("ParticleModuleVelocityOverLifetime").
			addProperty("VelOverLife", &ParticleModuleHelper::ParticleModuleVelocityOverLifetime_getVelOverLife, &ParticleModuleHelper::ParticleModuleVelocityOverLifetime_setVelOverLife).
			addProperty("Absolute", &ParticleModuleHelper::ParticleModuleVelocityOverLifetime_getAbsolute, &ParticleModuleHelper::ParticleModuleVelocityOverLifetime_setAbsolute).
		endClass().

		beginNamespace("cast").
			addFunction("ParticleModuleAccelerationBase", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleAccelerationBase>).
			addFunction("ParticleModuleAcceleration", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleAcceleration>).
			addFunction("ParticleModuleAccelerationOverLifetime", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleAccelerationOverLifetime>).
			addFunction("ParticleModuleAttractorBase", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleAttractorBase>).
			addFunction("ParticleModuleAttractorLine", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleAttractorLine>).
			addFunction("ParticleModuleAttractorParticle", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleAttractorParticle>).
			addFunction("ParticleModuleAttractorPoint", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleAttractorPoint>).
			addFunction("ParticleModuleBeamBase", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleBeamBase>).
			addFunction("ParticleModuleBeamModifier", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleBeamModifier>).
			addFunction("ParticleModuleBeamNoise", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleBeamNoise>).
			addFunction("ParticleModuleBeamSource", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleBeamSource>).
			addFunction("ParticleModuleBeamTarget", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleBeamTarget>).
			addFunction("ParticleModuleCameraBase", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleCameraBase>).
			addFunction("ParticleModuleCameraOffset", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleCameraOffset>).
			addFunction("ParticleModuleCollisionBase", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleCollisionBase>).
			addFunction("ParticleModuleCollision", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleCollision>).
			addFunction("ParticleModuleColorBase", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleColorBase>).
			addFunction("ParticleModuleColor", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleColor>).
			addFunction("ParticleModuleColor_Seeded", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleColor_Seeded>).
			addFunction("ParticleModuleColorByParameter", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleColorByParameter>).
			addFunction("ParticleModuleColorOverLife", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleColorOverLife>).
			addFunction("ParticleModuleColorScaleOverDensity", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleColorScaleOverDensity>).
			addFunction("ParticleModuleColorScaleOverLife", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleColorScaleOverLife>).
			addFunction("ParticleModuleEventBase", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleEventBase>).
			addFunction("ParticleModuleEventGenerator", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleEventGenerator>).
			addFunction("ParticleModuleEventReceiverBase", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleEventReceiverBase>).
			addFunction("ParticleModuleEventReceiverKillParticles", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleEventReceiverKillParticles>).
			addFunction("ParticleModuleEventReceiverSpawn", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleEventReceiverSpawn>).
			addFunction("ParticleModuleKillBase", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleKillBase>).
			addFunction("ParticleModuleKillBox", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleKillBox>).
			addFunction("ParticleModuleKillHeight", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleKillHeight>).
			addFunction("ParticleModuleLifetimeBase", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleLifetimeBase>).
			addFunction("ParticleModuleLifetime", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleLifetime>).
			addFunction("ParticleModuleLifetime_Seeded", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleLifetime_Seeded>).
			addFunction("ParticleModuleLocationBase", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleLocationBase>).
			addFunction("ParticleModuleLocation", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleLocation>).
			addFunction("ParticleModuleLocation_Seeded", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleLocation_Seeded>).
			addFunction("ParticleModuleLocationBoneSocket", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleLocationBoneSocket>).
			addFunction("ParticleModuleLocationDirect", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleLocationDirect>).
			addFunction("ParticleModuleLocationEmitter", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleLocationEmitter>).
			addFunction("ParticleModuleLocationEmitterDirect", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleLocationEmitterDirect>).
			addFunction("ParticleModuleLocationPrimitiveBase", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleLocationPrimitiveBase>).
			addFunction("ParticleModuleLocationPrimitiveCylinder", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleLocationPrimitiveCylinder>).
			addFunction("ParticleModuleLocationPrimitiveCylinder_Seeded", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleLocationPrimitiveCylinder_Seeded>).
			addFunction("ParticleModuleLocationPrimitiveSphere", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleLocationPrimitiveSphere>).
			addFunction("ParticleModuleLocationPrimitiveSphere_Seeded", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleLocationPrimitiveSphere_Seeded>).
			addFunction("ParticleModuleSourceMovement", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleSourceMovement>).
			addFunction("ParticleModuleMaterialBase", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleMaterialBase>).
			addFunction("ParticleModuleMaterialByParameter", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleMaterialByParameter>).
			addFunction("ParticleModuleMeshMaterial", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleMeshMaterial>).
			addFunction("ParticleModuleOrbitBase", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleOrbitBase>).
			addFunction("ParticleModuleOrbit", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleOrbit>).
			addFunction("ParticleModuleOrientationBase", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleOrientationBase>).
			addFunction("ParticleModuleOrientationAxisLock", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleOrientationAxisLock>).
			addFunction("ParticleModuleParameterBase", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleParameterBase>).
			addFunction("ParticleModuleParameterDynamic", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleParameterDynamic>).
			addFunction("ParticleModuleParameterDynamic_Seeded", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleParameterDynamic_Seeded>).
			addFunction("ParticleModuleRequired", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleRequired>).
			addFunction("ParticleModuleRotationBase", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleRotationBase>).
			addFunction("ParticleModuleMeshRotation", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleMeshRotation>).
			addFunction("ParticleModuleMeshRotation_Seeded", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleMeshRotation_Seeded>).
			addFunction("ParticleModuleRotation", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleRotation>).
			addFunction("ParticleModuleRotation_Seeded", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleRotation_Seeded>).
			addFunction("ParticleModuleRotationOverLifetime", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleRotationOverLifetime>).
			addFunction("ParticleModuleRotationRateBase", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleRotationRateBase>).
			addFunction("ParticleModuleMeshRotationRate", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleMeshRotationRate>).
			addFunction("ParticleModuleMeshRotationRate_Seeded", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleMeshRotationRate_Seeded>).
			addFunction("ParticleModuleMeshRotationRateMultiplyLife", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleMeshRotationRateMultiplyLife>).
			addFunction("ParticleModuleMeshRotationRateOverLife", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleMeshRotationRateOverLife>).
			addFunction("ParticleModuleRotationRate", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleRotationRate>).
			addFunction("ParticleModuleRotationRate_Seeded", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleRotationRate_Seeded>).
			addFunction("ParticleModuleRotationRateMultiplyLife", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleRotationRateMultiplyLife>).
			addFunction("ParticleModuleSizeBase", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleSizeBase>).
			addFunction("ParticleModuleSize", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleSize>).
			addFunction("ParticleModuleSize_Seeded", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleSize_Seeded>).
			addFunction("ParticleModuleSizeMultiplyLife", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleSizeMultiplyLife>).
			addFunction("ParticleModuleSizeMultiplyVelocity", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleSizeMultiplyVelocity>).
			addFunction("ParticleModuleSizeScale", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleSizeScale>).
			addFunction("ParticleModuleSizeScaleByTime", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleSizeScaleByTime>).
			addFunction("ParticleModuleSpawnBase", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleSpawnBase>).
			addFunction("ParticleModuleSpawn", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleSpawn>).
			addFunction("ParticleModuleSpawnPerUnit", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleSpawnPerUnit>).
			addFunction("ParticleModuleStoreSpawnTimeBase", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleStoreSpawnTimeBase>).
			addFunction("ParticleModuleStoreSpawnTime", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleStoreSpawnTime>).
			addFunction("ParticleModuleSubUVBase", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleSubUVBase>).
			addFunction("ParticleModuleSubUV", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleSubUV>).
			addFunction("ParticleModuleSubUVMovie", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleSubUVMovie>).
			addFunction("ParticleModuleSubUVDirect", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleSubUVDirect>).
			addFunction("ParticleModuleSubUVSelect", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleSubUVSelect>).
			addFunction("ParticleModuleTrailBase", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleTrailBase>).
			addFunction("ParticleModuleTrailSource", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleTrailSource>).
			addFunction("ParticleModuleTrailSpawn", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleTrailSpawn>).
			addFunction("ParticleModuleTrailTaper", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleTrailTaper>).
			addFunction("ParticleModuleTypeDataBase", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleTypeDataBase>).
			addFunction("ParticleModuleTypeDataAnimTrail", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleTypeDataAnimTrail>).
			addFunction("ParticleModuleTypeDataApex", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleTypeDataApex>).
			addFunction("ParticleModuleTypeDataBeam", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleTypeDataBeam>).
			addFunction("ParticleModuleTypeDataBeam2", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleTypeDataBeam2>).
			addFunction("ParticleModuleTypeDataMesh", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleTypeDataMesh>).
			addFunction("ParticleModuleTypeDataMeshPhysX", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleTypeDataMeshPhysX>).
			addFunction("ParticleModuleTypeDataPhysX", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleTypeDataPhysX>).
			addFunction("ParticleModuleTypeDataRibbon", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleTypeDataRibbon>).
			addFunction("ParticleModuleTypeDataTrail", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleTypeDataTrail>).
			addFunction("ParticleModuleTypeDataTrail2", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleTypeDataTrail2>).
			addFunction("ParticleModuleUberBase", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleUberBase>).
			addFunction("ParticleModuleUberLTISIVCL", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleUberLTISIVCL>).
			addFunction("ParticleModuleUberLTISIVCLIL", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleUberLTISIVCLIL>).
			addFunction("ParticleModuleUberLTISIVCLILIRSSBLIRR", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleUberLTISIVCLILIRSSBLIRR>).
			addFunction("ParticleModuleUberRainDrops", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleUberRainDrops>).
			addFunction("ParticleModuleUberRainImpacts", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleUberRainImpacts>).
			addFunction("ParticleModuleUberRainSplashA", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleUberRainSplashA>).
			addFunction("ParticleModuleUberRainSplashB", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleUberRainSplashB>).
			addFunction("ParticleModuleVelocityBase", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleVelocityBase>).
			addFunction("ParticleModuleVelocity", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleVelocity>).
			addFunction("ParticleModuleVelocity_Seeded", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleVelocity_Seeded>).
			addFunction("ParticleModuleVelocityInheritParent", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleVelocityInheritParent>).
			addFunction("ParticleModuleVelocityOverLifetime", &ParticleModuleHelper::ParticleModule_cast<UParticleModuleVelocityOverLifetime>).
		endNamespace().

		beginClass<TArray<UParticleModule*>>("ParticleModuleArray").
			addFunction("add", &TArray<UParticleModule*>::Add).
			addFunction("remove", &TArray<UParticleModule*>::Remove).
			addFunction("clear", &TArray<UParticleModule*>::Clear).
			addFunction("size", &TArray<UParticleModule*>::Num).
			addFunction("get", &TArray<UParticleModule*>::GetStd).
		endClass().

		deriveClass<UParticleLODLevel, UObject>("ParticleLODLevel").
			addProperty("spawnModules", &ParticleModuleHelper::ParticleLODLevel_getSpawnModules, &ParticleModuleHelper::ParticleLODLevel_setSpawnModules).
			addProperty("updateModules", &ParticleModuleHelper::ParticleLODLevel_getUpdateModules, &ParticleModuleHelper::ParticleLODLevel_setUpdateModules).
		endClass().

		beginClass<TArray<UParticleLODLevel*>>("ParticleLODLevelArray").
			addFunction("add", &TArray<UParticleLODLevel*>::Add).
			addFunction("remove", &TArray<UParticleLODLevel*>::Remove).
			addFunction("clear", &TArray<UParticleLODLevel*>::Clear).
			addFunction("size", &TArray<UParticleLODLevel*>::Num).
			addFunction("get", &TArray<UParticleLODLevel*>::GetStd).
		endClass().

		deriveClass<UParticleEmitter, UObject>("ParticleEmitter").
			addProperty("LODLevels", &ParticleModuleHelper::ParticleEmitter_getLODLevels, &ParticleModuleHelper::ParticleEmitter_setLODLevels).
		endClass().

		beginClass<TArray<UParticleEmitter*>>("ParticleEmitterArray").
			addFunction("add", &TArray<UParticleEmitter*>::Add).
			addFunction("remove", &TArray<UParticleEmitter*>::Remove).
			addFunction("clear", &TArray<UParticleEmitter*>::Clear).
			addFunction("size", &TArray<UParticleEmitter*>::Num).
			addFunction("get", &TArray<UParticleEmitter*>::GetStd).
		endClass().

		deriveClass<UParticleSystem, UObject>("ParticleSystem").
			addProperty("emitters", &ParticleModuleHelper::ParticleSystem_getEmitters, &ParticleModuleHelper::ParticleSystem_setEmitters).
		endClass().
		addFunction("getProjectile", &config_getProjectile).
		addFunction("setBulletColor", &config_setBulletColor).

		// HUD/Mute

		beginClass<ATrHUD>("HUD").
		endClass().
		addFunction("project", &hud_project).
		addFunction("drawDamageNumber", &hud_drawDamageNumber).
		addFunction("isOnScreen", &hud_isOnScreen).
		addFunction("getPlayerPos", &hud_getPlayerPos).

		beginClass<MutedPlayer>("MutedPlayer").
			addData("username", &MutedPlayer::username).
			addData("muteText", &MutedPlayer::muteText).
			addData("muteVGS", &MutedPlayer::muteVGS).
			addData("muteDirectMessage", &MutedPlayer::muteDirectMessage).
		endClass().
		addFunction("mplayer", &MutedPlayer::create).
		addFunction("mplayer_custom", &MutedPlayer::create_custom).
		addFunction("mutePlayer", &config_addMutedPlayer).

		addFunction("print", (void(*)(const std::string &)) &Utils::printConsole).
		addFunction("console", (void(*)(const std::string &)) &Utils::printConsole).
		addFunction("consoleRGB", (void(*)(const std::string &, const FColor &)) &Utils::printConsole).
		addFunction("notify", (void (*)(const std::string &, const std::string &)) &Utils::notify).
	endNamespace();
}
