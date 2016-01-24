#include "Config.h"

Config g_config;

Config::TogglableIcon Config::togglable_icons[] =
{
	Config::TogglableIcon(&g_config.showObjectiveIcon, "Function TribesGame.TrGameObjective.PostRenderFor"),
	Config::TogglableIcon(&g_config.showCTFBaseIcon, "Function TribesGame.TrCTFBase.PostRenderFor"),
	//Config::TogglableIcon(&g_config.showFlagBaseIcon, "Function TribesGame.TrFlagBase.PostRenderFor"),
	Config::TogglableIcon(&g_config.showNuggetIcon, "Function TribesGame.TrDroppedPickup.PostRenderFor"),
	Config::TogglableIcon(&g_config.showPlayerIcon, "Function TribesGame.TrPawn.PostRenderFor"),
	Config::TogglableIcon(&g_config.showVehicleIcon, "Function TribesGame.TrVehicle.PostRenderFor"),
	Config::TogglableIcon(&g_config.showMineIcon, "Function TribesGame.TrProj_Mine.PostRenderFor"),
	Config::TogglableIcon(&g_config.showSensorIcon, "Function TribesGame.TrDeployable_MotionSensor.PostRenderFor")
};

Config::Config()
{
	hitsound = UObject::FindObject<USoundCue>("SoundCue AUD_PC_Notifications.Impact__Notify.A_CUE_PC_HitImpactOnPawnNotify");
	headshotsound = UObject::FindObject<USoundCue>("SoundCue AUD_PC_Notifications.Headshot.A_CUE_PC_ImpactOnPawnNotify_Headshot");
	flagpickedup = UObject::FindObject<USoundCue>("SoundCue AUD_MUS_CTF.Stingers.A_CUE_UI_CTF_FlagPickedUp");
	flagcaptured = UObject::FindObject<USoundCue>("SoundCue AUD_MUS_CTF.Stingers.A_CUE_UI_CTF_FlagCaptured");
	flagreturned = UObject::FindObject<USoundCue>("SoundCue AUD_MUS_CTF.Stingers.A_CUE_UI_CTF_FlagReturned");
	onDamageNumberCreate = NULL;
	onDamageNumberUpdate = NULL;
	onDrawCustomHud = NULL;
	onAddToCombatLog = NULL;
	onInputEvent = NULL;
	reset();
}

Config::~Config()
{
}

void Config::reset()
{
	// General stuff
	showWeapon             = true;
	showFirstPersonAmmo    = false;
	showBodyMesh           = true;
	showCrosshair          = true;
	crosshairScale         = 1;
	crosshairColor         = Utils::rgb(255, 255, 255);

	// Damage number customization
	damageNumbersOffsetX = 0.0f;
	damageNumbersOffsetY = 0.0f;
	damageNumbersScale   = 1.0f;

	// Damage number stream
	showDamageNumberStream = false;
	showRainbow            = false;
	// Default damage stream reset time is 1/2 second
	damageNumberStreamTimeout     = 0.5;
	lastDamageNumberShowEventTime = 0;
	damageNumberStreamValue       = 0;
	damageNumberStreamCount       = 0;
	// Custom damage number text
	damageNumberCustomText = std::string("");

	delete onDamageNumberCreate;
	delete onDamageNumberUpdate;
	delete onDrawCustomHud;
	delete onAddToCombatLog;
	onDamageNumberCreate = NULL;
	onDamageNumberUpdate = NULL;
	onDrawCustomHud = NULL;
	onAddToCombatLog = NULL;

	//Damage Number color variables
	rainbowBulletInt      = 0;
	damageNumbersLimit    = 0;
	damageNumbersColorMin = Utils::rgb(255, 255, 255);
	damageNumbersColorMax = Utils::rgb(248, 83, 83);
	friendlyChatColor     = Utils::rgb(158, 208, 212);
	enemyChatColor        = Utils::rgb(255, 111, 111);
	whisperChatColor      = Utils::rgb(207, 165, 101);
	friendlyHUDChatColor  = Utils::rgb(158, 208, 211);
	enemyHUDChatColor     = Utils::rgb(249, 32, 32);

	//Marker Colors
	friendlyColor          = Utils::rgb(119, 186, 255);
	enemyColor             = Utils::rgb(248, 83, 83);
	enemyMarkerColor       = Utils::rgb(255, 23, 23);
	enemyIsFMarkerColor    = Utils::rgb(239, 164, 0);
	friendlyMarkerColor    = Utils::rgb(115, 225, 255);
	friendlyIsFMarkerColor = Utils::rgb(81, 250, 85);

	// Ski bars
	skiBarMin = 30;
	skiBarMax = 300;

	// Roam map variables
	disableBaseTurrets       = false;
	disablePower             = false;
	showSavedLocations       = true;
	maxSpeedWithFlag         = 0;
	decelerationRateWithFlag = 10;

	// Stopwatch
	stopwatchStopOnCap     = false;
	stopwatchStopOnDeath   = true;
	stopwatchNotifications = true;

	// Route recording
	routeDrawInterval      = 500; // Drawing a dot every 500ms
	routeDrawETAInterval   = 5; // ETA every 5 seconds
	routeReplayRotation    = true;
	routeCinematicMode     = false;

	// Sounds
	hitSoundMode = 0;
	customHeadShotSound  = false;
	customKillSound      = false;
	customAirMailSound   = false;
	customBluePlateSound = false;
	hitSoundPitchMin     = 0.4f;
	hitSoundPitchMax     = 1.6f;
	hitSoundDamageRef    = 600;
	volumeHitSound       = 0.55f;
	volumeHeadShot       = 0.55f;
	volumeKillSound      = 0.55f;
	volumeBluePlate      = 0.55f;
	volumeAirMail        = 0.55f;
	// Accolades
	customStreak1    = false; customStreak2      = false; customStreak3       = false; customStreak4    = false; customStreak5    = false;
	customMultiKill1 = false; customMultiKill2   = false; customMultiKill3    = false; customMultiKill4 = false; customMultiKill5 = false;
	customFirstBlood = false; customHeadShotKill = false; customArtilleryShot = false; customMeleeKill  = false; customRoadKill   = false; customFastGrab = false;
	volumeStreak1    = 0.5f;  volumeStreak2      = 0.5f;  volumeStreak3       = 0.5f;  volumeStreak4    = 0.5f;  volumeStreak5    = 0.5f;
	volumeMultiKill1 = 0.5f;  volumeMultiKill2   = 0.5f;  volumeMultiKill3    = 0.5f;  volumeMultiKill4 = 0.5f;  volumeMultiKill5 = 0.5f;
	volumeFirstBlood = 0.5f;  volumeHeadShotKill = 0.5f;  volumeArtilleryShot = 0.5f;  volumeMeleeKill  = 0.5f;  volumeRoadKill   = 0.5f;  volumeFastGrab = 0.5f;
	// Flag events
	customFlagBlueGrab    = false; customFlagRedGrab    = false;
	customFlagBluePickup  = false; customFlagRedPickup  = false;
	customFlagBlueCapture = false; customFlagRedCapture = false;
	customFlagBlueReturn  = false; customFlagRedReturn  = false;
	customFlagBlueDrop    = false; customFlagRedDrop    = false;
	volumeFlagBlueGrab    = 0.5f;  volumeFlagRedGrab    = 0.5f;
	volumeFlagBluePickup  = 0.5f;  volumeFlagRedPickup  = 0.5f;
	volumeFlagBlueCapture = 0.5f;  volumeFlagRedCapture = 0.5f;
	volumeFlagBlueReturn  = 0.5f;  volumeFlagRedReturn  = 0.5f;
	volumeFlagBlueDrop    = 0.5f;  volumeFlagRedDrop    = 0.5f;

	// Toggle HUD
	showObjectiveIcon    = true;
	showFlagBaseIcon     = true;
	showFlagHomeBaseIcon = true;
	showCTFBaseIcon      = true;
	showNuggetIcon       = true;
	showPlayerIcon       = true;
	showVehicleIcon      = true;
	showMineIcon         = true;
	showSensorIcon       = true;

	// HUD scaling
	IFFScale			 = 1.0f;

	//Stats
	recordStats = false;

	// Magic chain
	useSmallBullets      = false;
	useMagicChain        = false;
	centerBulletSpawn    = false;
	bulletPingMultiplier = 1.0f;
	bulletSpawnDelay     = 0.0f;

	// Mouse sensitivity
	useFOVScaling        = true;
	sens                 = 10.0f;
	sensZoom             = 5.0f;
	sensZoooom           = 2.0f;

	// Weapon and bullet position
	customWeaponOffset = false;
	weaponOffset = { 0.0f, 0.0f, 0.0f };
	customBulletSpawnOffset = false;
	bulletSpawnOffset = { 180.0f, 0.0f, 0.0f };

	//Global mute
	globalMuteList = std::vector<MutedPlayer>();
	muteVGS = false;

	// Lua keybinds
	for (auto &it : lua_keybinds)
	{
		for (int i = 0; i < IE_MAX; i++)
		{
			if (it.second[i])
				delete it.second[i];
		}
		delete it.second;
	}
	lua_keybinds.clear();
	delete onInputEvent;
	onInputEvent = NULL;

	// Bools for reloading
	shouldReloadTrHud = true;
}

void Config::parseFile()
{
	std::string directory = Utils::getConfigDir();
	reset();
	lua = Lua();

	if (Utils::fileExists(directory + "config.lua"))
	{
		std::string err = lua.doFile(directory + "config.lua");
		if (err.size())
		{
			Utils::console("Lua config error: %s", err.c_str());
			return;
		}
	}
	if (Utils::fileExists(directory + "custom.lua"))
	{
		std::string err = lua.doFile(directory + "custom.lua");
		if (err.size())
		{
			Utils::console("Custom Lua config error: %s", err.c_str());
			return;
		}
	}
	setVariables();
	updateDefaults();
	refreshSoundVolumes();
}

void Config::reloadTrHUD(ATrHUD *currHud, bool updated)
{
	static float defaultHealthBarWidth = 0;
	static float defaultHealthBarHeight = 0;

	if (g_config.shouldReloadTrHud && currHud)
	{
		// Ski Bars
		UGfxTrHud *default_gfxhud = (UGfxTrHud *) UGfxTrHud::StaticClass()->Default;
		UGfxTrHud *currGfxHud = currHud->m_GFxHud;

		if (g_config.skiBarMin < 1)
			g_config.skiBarMin = 1.0f;
		if (g_config.skiBarMax < g_config.skiBarMin + 1)
			g_config.skiBarMax = g_config.skiBarMin + 1;
		for (int i = 0; i < 12; i++)
		{
			int val = (int)((g_config.skiBarMin + (i - 1) * (g_config.skiBarMax - g_config.skiBarMin) / 10.0f) / 0.072f);
			if (currGfxHud)
				currGfxHud->m_SkiSpeedSteps[i] = val;
			if (default_gfxhud)
				default_gfxhud->m_SkiSpeedSteps[i] = val;
		}

		if (!defaultHealthBarWidth)
		{
			defaultHealthBarWidth = currHud->m_fHealthBarWidth;
			defaultHealthBarHeight = currHud->m_fHealthBarHeight;
		}
		currHud->m_fHealthBarWidth = defaultHealthBarWidth * IFFScale;
		currHud->m_fHealthBarHeight = defaultHealthBarHeight * IFFScale;
		ATrHUD *default_hud = (ATrHUD *)ATrHUD::StaticClass()->Default;
		if (default_hud)
		{
			// IFF scaling

			for (UTexture2D **textureList = &default_hud->MarkerLight; textureList < (UTexture2D **)&default_hud->InfoChatColorIdx; textureList++)
			{
				UTexture2D *texture = *textureList;
				if (texture)
				{
					texture->SizeX = (int)(texture->OriginalSizeX * IFFScale);
					texture->SizeY = (int)(texture->OriginalSizeY * IFFScale);
				}
			}
			default_hud->m_fHealthBarWidth = defaultHealthBarWidth * IFFScale;
			default_hud->m_fHealthBarHeight = defaultHealthBarHeight * IFFScale;

			// Chat color
			default_hud->FriendlyChatColor = g_config.friendlyChatColor;
			default_hud->EnemyChatColor = g_config.enemyChatColor;
			default_hud->WhisperChatColor = g_config.whisperChatColor;
		}
		currHud->FriendlyChatColor = g_config.friendlyChatColor;
		currHud->EnemyChatColor = g_config.enemyChatColor;
		currHud->WhisperChatColor = g_config.whisperChatColor;

		// Damage numbers
		if (default_hud)
		{
			default_hud->m_OverheadNumberColorMin = g_config.damageNumbersColorMin;
			default_hud->m_OverheadNumberColorMax = g_config.damageNumbersColorMax;
		}
		if (!showRainbow)
		{
			currHud->m_OverheadNumberColorMin = g_config.damageNumbersColorMin;
			currHud->m_OverheadNumberColorMax = g_config.damageNumbersColorMax;
		}

		if (updated)
			g_config.shouldReloadTrHud = false;
	}
}

bool Function_HookBlock(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	return true;
}

void Config::updateDefaults()
{
	// Player name/marker colors
	ATrHUD *hud = (ATrHUD *)ATrHUD::StaticClass()->Default;
	if (hud)
	{
		hud->ColorEnemy = enemyColor;
		hud->ColorFriend = friendlyColor;
		hud->MarkerColorFriendly = Utils::linCol(friendlyMarkerColor);
		hud->MarkerColorFriendly_IsFriend = Utils::linCol(friendlyIsFMarkerColor);
		hud->MarkerColorEnemy = Utils::linCol(enemyMarkerColor);
		hud->MarkerColorEnemy_IsFriend = Utils::linCol(enemyIsFMarkerColor);
	}

	// Toggle default sounds
	if (hitsound)
		hitsound->VolumeMultiplier = hitSoundMode > 0 ? 0.0f : volumeHitSound;

	if (headshotsound)
		headshotsound->VolumeMultiplier = customHeadShotSound ? 0.0f : volumeHeadShot;

	if (flagpickedup)
		flagpickedup->VolumeMultiplier = customFlagBluePickup || customFlagRedPickup || customFlagBlueGrab || customFlagRedGrab ? 0.0f : 0.55f;

	if (flagcaptured)
		flagcaptured->VolumeMultiplier = customFlagBlueCapture || customFlagRedCapture ? 0.0f : 0.55f;

	if (flagreturned)
		flagreturned->VolumeMultiplier = customFlagBlueReturn || customFlagRedReturn ? 0.0f : 0.55f;

	// Toggle icons
	for (int i = 0; i < sizeof(togglable_icons) / sizeof(togglable_icons[0]); i++)
	{
		if (*(togglable_icons[i].variable_ptr))
			Hooks::remove(const_cast<char *>(togglable_icons[i].func_name));
		else
			Hooks::add(&Function_HookBlock, const_cast<char *>(togglable_icons[i].func_name));
	}

	// HUD variables
	reloadTrHUD(NULL, false);
}

void Config::initializeAudio()
{
	audioEngine.Initialize();
	if (audioEngine.audioAvailable())
	{
		s_soundEffects.push_back(s_hitSound.Initialize(audioEngine.SoundEffectEngine,        std::string("hit.wav"),              &volumeHitSound));
		s_soundEffects.push_back(s_headShot.Initialize(audioEngine.SoundEffectEngine,        std::string("headshot.wav"),         &volumeHeadShot));
		s_soundEffects.push_back(s_killSound.Initialize(audioEngine.SoundEffectEngine,       std::string("kill.wav"),             &volumeKillSound));
		s_soundEffects.push_back(s_bluePlate.Initialize(audioEngine.SoundEffectEngine,       std::string("blueplate.wav"),        &volumeBluePlate));
		s_soundEffects.push_back(s_airMail.Initialize(audioEngine.SoundEffectEngine,         std::string("airmail.wav"),          &volumeAirMail));
		s_soundEffects.push_back(s_streak1.Initialize(audioEngine.SoundEffectEngine,         std::string("streak1.wav"),          &volumeStreak1));
		s_soundEffects.push_back(s_streak2.Initialize(audioEngine.SoundEffectEngine,         std::string("streak2.wav"),          &volumeStreak2));
		s_soundEffects.push_back(s_streak3.Initialize(audioEngine.SoundEffectEngine,         std::string("streak3.wav"),          &volumeStreak3));
		s_soundEffects.push_back(s_streak4.Initialize(audioEngine.SoundEffectEngine,         std::string("streak4.wav"),          &volumeStreak4));
		s_soundEffects.push_back(s_streak5.Initialize(audioEngine.SoundEffectEngine,         std::string("streak5.wav"),          &volumeStreak5));
		s_soundEffects.push_back(s_multiKill1.Initialize(audioEngine.SoundEffectEngine,      std::string("multikill1.wav"),       &volumeMultiKill1));
		s_soundEffects.push_back(s_multiKill2.Initialize(audioEngine.SoundEffectEngine,      std::string("multikill2.wav"),       &volumeMultiKill2));
		s_soundEffects.push_back(s_multiKill3.Initialize(audioEngine.SoundEffectEngine,      std::string("multikill3.wav"),       &volumeMultiKill3));
		s_soundEffects.push_back(s_multiKill4.Initialize(audioEngine.SoundEffectEngine,      std::string("multikill4.wav"),       &volumeMultiKill4));
		s_soundEffects.push_back(s_multiKill5.Initialize(audioEngine.SoundEffectEngine,      std::string("multikill5.wav"),       &volumeMultiKill5));
		s_soundEffects.push_back(s_firstBlood.Initialize(audioEngine.SoundEffectEngine,      std::string("firstblood.wav"),       &volumeFirstBlood));
		s_soundEffects.push_back(s_headShotKill.Initialize(audioEngine.SoundEffectEngine,    std::string("headshotkill.wav"),     &volumeHeadShotKill));
		s_soundEffects.push_back(s_artilleryShot.Initialize(audioEngine.SoundEffectEngine,   std::string("artilleryshot.wav"),    &volumeArtilleryShot));
		s_soundEffects.push_back(s_meleeKill.Initialize(audioEngine.SoundEffectEngine,       std::string("meleekill.wav"),        &volumeMeleeKill));
		s_soundEffects.push_back(s_roadKill.Initialize(audioEngine.SoundEffectEngine,        std::string("roadkill.wav"),         &volumeRoadKill));
		s_soundEffects.push_back(s_fastGrab.Initialize(audioEngine.SoundEffectEngine,        std::string("fastgrab.wav"),         &volumeFastGrab));
		// Flag events
		s_soundEffects.push_back(s_flagBlueGrab.Initialize(audioEngine.SoundEffectEngine,    std::string("flagblue_grab.wav"),    &volumeFlagBlueGrab));
		s_soundEffects.push_back(s_flagRedGrab.Initialize(audioEngine.SoundEffectEngine,     std::string("flagred_grab.wav"),     &volumeFlagRedGrab));
		s_soundEffects.push_back(s_flagBluePickup.Initialize(audioEngine.SoundEffectEngine,  std::string("flagblue_pickup.wav"),  &volumeFlagBluePickup));
		s_soundEffects.push_back(s_flagRedPickup.Initialize(audioEngine.SoundEffectEngine,   std::string("flagred_pickup.wav"),   &volumeFlagRedPickup));
		s_soundEffects.push_back(s_flagBlueCapture.Initialize(audioEngine.SoundEffectEngine, std::string("flagblue_capture.wav"), &volumeFlagBlueCapture));
		s_soundEffects.push_back(s_flagRedCapture.Initialize(audioEngine.SoundEffectEngine,  std::string("flagred_capture.wav"),  &volumeFlagRedCapture));
		s_soundEffects.push_back(s_flagBlueReturn.Initialize(audioEngine.SoundEffectEngine,  std::string("flagblue_return.wav"),  &volumeFlagBlueReturn));
		s_soundEffects.push_back(s_flagRedReturn.Initialize(audioEngine.SoundEffectEngine,   std::string("flagred_return.wav"),   &volumeFlagRedReturn));
		s_soundEffects.push_back(s_flagBlueDrop.Initialize(audioEngine.SoundEffectEngine,    std::string("flagblue_drop.wav"),    &volumeFlagBlueDrop));
		s_soundEffects.push_back(s_flagRedDrop.Initialize(audioEngine.SoundEffectEngine,     std::string("flagred_drop.wav"),     &volumeFlagRedDrop));
	}
	else
		Utils::console("Error: could not initialize audio engine");
}

void Config::reloadSounds()
{
	if (audioEngine.audioAvailable())
	{
		for (size_t i = 0; i < s_soundEffects.size(); i++)
		{
			if (s_soundEffects[i])
			{
				s_soundEffects[i]->Reload();
				if (s_soundEffects[i]->audioAvailable())
					Utils::printConsole("Reloaded " + s_soundEffects[i]->m_filePath);
				else
					Utils::printConsole("Failed to reload " + s_soundEffects[i]->m_filePath);
			}
		}
	}
	else
		Utils::printConsole("Error: audio engine unavailable");
}

void Config::refreshSoundVolumes()
{
	if (audioEngine.audioAvailable())
	{
		for (size_t i = 0; i < s_soundEffects.size(); i++)
		{
			if (s_soundEffects[i])
				s_soundEffects[i]->RefreshVolume();
		}
	}
	else
		Utils::console("Error: audio engine unavailable");
}

void Config::stopwatchDisplayTime(const std::string &prestr, float cur_time)
{
	if (stopwatchRunning)
	{
		float time = cur_time - stopwatchStartTime;

		std::string s = Utils::fTime2stopwatch(time);
		Utils::printConsole("Stopwatch: " + prestr + s, Utils::rgba(15, 255, 135, 255));
		if (stopwatchNotifications)
			Utils::notify(std::string("Stopwatch"), prestr + s);
	}
}

void Config::stopwatchPrintSummary()
{
	if (g_config.stopwatchGrabTime > 0.0f)
	{
		// Speed and health
		Utils::printConsole("\nSummary\n----------------------------------------\n Flag taken at " + std::to_string(g_config.stopwatchGrabSpeed) + " km/h " + std::to_string(g_config.stopwatchGrabHealth) + " hp");

		// Time from stopwatch start until grab, only when the stopwatch was started pre-grab
		if (g_config.stopwatchStartTime != 0.0f && g_config.stopwatchStartTime < g_config.stopwatchGrabTime)
			Utils::printConsole(" On route:     " + Utils::fTime2string(g_config.stopwatchGrabTime - g_config.stopwatchStartTime));

		if (g_config.stopwatchGrabTime < g_config.stopwatchCapTime)
		{
			// Capture time, only when cap time is available
			Utils::printConsole(" Captured in: " + Utils::fTime2string(g_config.stopwatchCapTime - g_config.stopwatchGrabTime));

			// Total time, only when the stopwatch was started pre-grab
			if (g_config.stopwatchStartTime != 0.0f && g_config.stopwatchStartTime < g_config.stopwatchGrabTime)
			{
				Utils::printConsole("----------------------------------------");
				Utils::printConsole(" Total:          " + Utils::fTime2string(g_config.stopwatchCapTime - g_config.stopwatchStartTime));
			}
		}
		Utils::printConsole("===============================");
	}
}

#define SET_VARIABLE(type, var) (lua.setVar<type>(var, #var))
#define SET_FUNCTION(var) do {\
	var = new LuaRef(getGlobal(lua.getState(), #var));\
	if (var && (var->isNil() || !var->isFunction())) {\
		delete var;\
		var = NULL;\
	}\
} while (0)

void Config::setVariables()
{
	// General stuff
	SET_VARIABLE(int, damageNumbersLimit);
	SET_VARIABLE(bool, showWeapon);
	SET_VARIABLE(bool, showFirstPersonAmmo);
	SET_VARIABLE(bool, showBodyMesh);
	SET_VARIABLE(bool, showCrosshair);
	SET_VARIABLE(float, crosshairScale);
	SET_VARIABLE(FColor, crosshairColor);

	// Damage number customization
	SET_FUNCTION(onDamageNumberCreate);
	SET_FUNCTION(onDamageNumberUpdate);
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
	SET_VARIABLE(FColor, whisperChatColor);
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

	// Roam map variables
	SET_VARIABLE(bool, disableBaseTurrets);
	SET_VARIABLE(bool, disablePower);
	SET_VARIABLE(bool, showSavedLocations);
	SET_VARIABLE(int, maxSpeedWithFlag);
	SET_VARIABLE(int, decelerationRateWithFlag);

	// Stopwatch
	SET_VARIABLE(bool, stopwatchStopOnCap);
	SET_VARIABLE(bool, stopwatchStopOnDeath);
	SET_VARIABLE(bool, stopwatchNotifications);

	// Route recording
	SET_VARIABLE(int, routeDrawInterval);
	SET_VARIABLE(int, routeDrawETAInterval);
	SET_VARIABLE(bool, routeReplayRotation);
	SET_VARIABLE(bool, routeCinematicMode);

	// Sounds
	SET_VARIABLE(int, hitSoundMode);
	SET_VARIABLE(bool, customHeadShotSound);
	SET_VARIABLE(bool, customKillSound);
	SET_VARIABLE(bool, customAirMailSound);
	SET_VARIABLE(bool, customBluePlateSound);
	SET_VARIABLE(float, hitSoundPitchMin);
	SET_VARIABLE(float, hitSoundPitchMax);
	SET_VARIABLE(int, hitSoundDamageRef);
	SET_VARIABLE(float, volumeHitSound);
	SET_VARIABLE(float, volumeHeadShot);
	SET_VARIABLE(float, volumeKillSound);
	SET_VARIABLE(float, volumeBluePlate);
	SET_VARIABLE(float, volumeAirMail);
	// Accolades
	SET_VARIABLE(bool, customStreak1);
	SET_VARIABLE(bool, customStreak2);
	SET_VARIABLE(bool, customStreak3);
	SET_VARIABLE(bool, customStreak4);
	SET_VARIABLE(bool, customStreak5);
	SET_VARIABLE(bool, customMultiKill1); 
	SET_VARIABLE(bool, customMultiKill2); 
	SET_VARIABLE(bool, customMultiKill3); 
	SET_VARIABLE(bool, customMultiKill4); 
	SET_VARIABLE(bool, customMultiKill5); 
	SET_VARIABLE(bool, customFirstBlood);
	SET_VARIABLE(bool, customHeadShotKill);
	SET_VARIABLE(bool, customArtilleryShot);
	SET_VARIABLE(bool, customMeleeKill);
	SET_VARIABLE(bool, customRoadKill);
	SET_VARIABLE(bool, customFastGrab);
	SET_VARIABLE(float, volumeStreak1);
	SET_VARIABLE(float, volumeStreak2);
	SET_VARIABLE(float, volumeStreak3);
	SET_VARIABLE(float, volumeStreak4);
	SET_VARIABLE(float, volumeStreak5);
 	SET_VARIABLE(float, volumeMultiKill1);
	SET_VARIABLE(float, volumeMultiKill2);
	SET_VARIABLE(float, volumeMultiKill3);
	SET_VARIABLE(float, volumeMultiKill4);
	SET_VARIABLE(float, volumeMultiKill5);
	SET_VARIABLE(float, volumeFirstBlood);
	SET_VARIABLE(float, volumeHeadShotKill);
	SET_VARIABLE(float, volumeArtilleryShot);
	SET_VARIABLE(float, volumeMeleeKill);
	SET_VARIABLE(float, volumeRoadKill);
	SET_VARIABLE(float, volumeFastGrab);
	// Flag events
	SET_VARIABLE(bool, customFlagBlueGrab);
	SET_VARIABLE(bool, customFlagRedGrab);
	SET_VARIABLE(bool, customFlagBluePickup);
	SET_VARIABLE(bool, customFlagRedPickup);
	SET_VARIABLE(bool, customFlagBlueCapture);
	SET_VARIABLE(bool, customFlagRedCapture);
	SET_VARIABLE(bool, customFlagBlueReturn);
	SET_VARIABLE(bool, customFlagRedReturn);
	SET_VARIABLE(bool, customFlagBlueDrop);
	SET_VARIABLE(bool, customFlagRedDrop);
	SET_VARIABLE(float, volumeFlagBlueGrab);
	SET_VARIABLE(float, volumeFlagRedGrab);
	SET_VARIABLE(float, volumeFlagBluePickup);
	SET_VARIABLE(float, volumeFlagRedPickup);
	SET_VARIABLE(float, volumeFlagBlueCapture);
	SET_VARIABLE(float, volumeFlagRedCapture);
	SET_VARIABLE(float, volumeFlagBlueReturn);
	SET_VARIABLE(float, volumeFlagRedReturn);
	SET_VARIABLE(float, volumeFlagBlueDrop);
	SET_VARIABLE(float, volumeFlagRedDrop);

	// Toggle HUD
	SET_VARIABLE(bool, showObjectiveIcon);
	SET_VARIABLE(bool, showFlagBaseIcon);
	SET_VARIABLE(bool, showFlagHomeBaseIcon);
	SET_VARIABLE(bool, showCTFBaseIcon);
	SET_VARIABLE(bool, showNuggetIcon);
	SET_VARIABLE(bool, showPlayerIcon);
	SET_VARIABLE(bool, showVehicleIcon);
	SET_VARIABLE(bool, showMineIcon);
	SET_VARIABLE(bool, showSensorIcon);

	// Custom HUD
	SET_FUNCTION(onDrawCustomHud);
	SET_FUNCTION(onAddToCombatLog);

	// HUD scaling
	SET_VARIABLE(float, IFFScale);

	// VGS Mute
	SET_VARIABLE(bool, muteVGS),

	// Toggle Stats
	SET_VARIABLE(bool, recordStats);

	// Magic chain
	SET_VARIABLE(bool, useSmallBullets);
	SET_VARIABLE(bool, useMagicChain);
	SET_VARIABLE(bool, centerBulletSpawn);
	SET_VARIABLE(float, bulletPingMultiplier);
	SET_VARIABLE(float, bulletSpawnDelay);

	// Mouse sensitivity
	SET_VARIABLE(bool, useFOVScaling);
	SET_VARIABLE(float, sens);
	SET_VARIABLE(float, sensZoom);
	SET_VARIABLE(float, sensZoooom);

	// Weapon and bullet position
	SET_VARIABLE(bool, customWeaponOffset);
	SET_VARIABLE(FVector, weaponOffset);
	SET_VARIABLE(bool, customBulletSpawnOffset);
	SET_VARIABLE(FVector, bulletSpawnOffset);

	// Lua keybinds
	SET_FUNCTION(onInputEvent);
}

static void config_rereadVariables()
{
	g_config.setVariables();
	g_config.updateDefaults();
}

static void config_reload()
{
	g_config.parseFile();
}

static void config_reloadSounds()
{
	g_config.reloadSounds();
}

static bool config_addMutedPlayer(MutedPlayer player)
{
	g_config.globalMuteList.push_back(player);
	return true;
}

static bool config_bindKey(const std::string &key, int event_type, LuaRef func)
{
	if (event_type >= IE_MAX || event_type < 0)
	{
		Utils::console("Error: Unable to bind key %s: unknown event type %d", event_type, key.c_str());
		return false;
	}
	FName key_name(key.c_str());
	if (!key_name.Index)
	{
		Utils::console("Error: Unable to bind key %s: unknown key", key.c_str());
		return false;
	}
	if (func.isNil() || !func.isFunction())
	{
		Utils::console("Error: Unable to bind key %s: provided callback is not a function", key.c_str());
		return false;
	}
	LuaRef **funcs = NULL;
	auto &it = g_config.lua_keybinds.find(key_name.Index);
	if (it == g_config.lua_keybinds.end())
	{
		funcs = new LuaRef*[IE_MAX];
		for (int i = 0; i < IE_MAX; i++)
			funcs[i] = NULL;
		g_config.lua_keybinds[key_name.Index] = funcs;
	}
	else
		funcs = g_config.lua_keybinds[key_name.Index];
	funcs[event_type] = new LuaRef(func);
	return true;
}

static bool config_unbindKey(const std::string &key, int event_type)
{
	// Check for errors
	if (event_type >= IE_MAX || event_type < 0)
	{
		Utils::console("Error: Unable to unbind key %s: unknown event type %d", event_type, key.c_str());
		return false;
	}
	FName key_name(key.c_str());
	if (!key_name.Index)
	{
		Utils::console("Error: Unable to unbind key %s: unknown key", key.c_str());
		return false;
	}
	// Remove the callback
	auto &it = g_config.lua_keybinds.find(key_name.Index);
	if (it == g_config.lua_keybinds.end())
		return true;
	if (it->second[event_type])
	{
		delete it->second[event_type];
		it->second[event_type] = NULL;
	}
	// Remove the map index if none of the event types are bound
	for (int i = 0; i < IE_MAX; i++)
	{
		if (it->second[i])
			return true;
	}
	delete it->second;
	g_config.lua_keybinds.erase(it);
	return true;
}

static LuaRef config_searchTribesInputCommands(const std::string &needle)
{
	LuaRef out = newTable(g_config.lua.getState());
	if (!Utils::tr_pc)
		return out;
	std::regex re(needle, std::regex_constants::icase);
	TArray<FKeyBind> &bindings = Utils::tr_pc->PlayerInput->Bindings;
	for (int i = 0; i < bindings.Count; i++)
	{
		FKeyBind *bind = bindings.Data + i;
		std::string haystack = Utils::f2std(bind->Command);
		if (std::regex_search(haystack, re))
			out.append(bind);
	}
	return out;
}

static void config_modifySound(const std::string &name, float pitch, float volume)
{
	if (name[0] == 'A' || name[0] == 'a')
	{
		UAudioComponent *sound = UObject::FindObject<UAudioComponent>(name.c_str());
		if (sound)
		{
			sound->PitchMultiplier = pitch;
			sound->VolumeMultiplier = volume;
		}
		else
			Utils::printConsole("No AudioComponent found with that name");
	}
	else
	{
		USoundCue *sound = UObject::FindObject<USoundCue>(name.c_str());
		if (sound)
		{
			sound->PitchMultiplier = pitch;
			sound->VolumeMultiplier = volume;
		}
		else
			Utils::printConsole("No SoundCue found with that name");
	}

}

static void config_modifySoundRe(const std::string &needle, float pitch, float volume)
{
	while (!UObject::GObjObjects())
		Sleep(100);

	while (!FName::Names())
		Sleep(100);

	std::regex r(needle, std::regex_constants::icase);

	int matches = 0;

	for (int i = 0; i < UObject::GObjObjects()->Count; ++i)
	{
		UObject* Object = UObject::GObjObjects()->Data[i];

		// skip everything but matched SoundCues and AudioComponents
		if (Object
			&& (Object->IsA(USoundCue::StaticClass()) || Object->IsA(UAudioComponent::StaticClass()))
			&& std::regex_search(Object->GetFullName(), r))
		{
			matches++;

			if (Object->IsA(USoundCue::StaticClass()))
			{
				USoundCue *sound = (USoundCue*)Object;

				sound->PitchMultiplier = pitch;
				sound->VolumeMultiplier = volume;
			}
			else
			{
				UAudioComponent *sound = (UAudioComponent*)Object;

				sound->PitchMultiplier = pitch;
				sound->VolumeMultiplier = volume;
			}
		}
	}
	Utils::printConsole(matches == 1 ? std::to_string(matches) + " sound matched" : std::to_string(matches) + " sounds matched");
}

static void config_searchSoundRe(const std::string &needle)
{
	while (!UObject::GObjObjects())
		Sleep(100);

	while (!FName::Names())
		Sleep(100);

	std::regex r(needle, std::regex_constants::icase);

	int matches = 0;

	for (int i = 0; i < UObject::GObjObjects()->Count; ++i)
	{
		UObject* Object = UObject::GObjObjects()->Data[i];

		// skip everything but matched SoundCues and AudioComponents
		if (Object
			&& (Object->IsA(USoundCue::StaticClass()) || Object->IsA(UAudioComponent::StaticClass()))
			&& std::regex_search(Object->GetFullName(), r))
		{
			matches++;

			Utils::printConsole(std::string(Object->GetFullName()));
		}
	}
	Utils::printConsole("Total: " + std::to_string(matches));
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

static void config_placeholder()
{
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
		addFunction("lerpColor", &Utils::lerpColor).

		// Damage Numbers
		beginClass<FVector2D>("Vector2").
			addData("x", &FVector2D::X).
			addData("y", &FVector2D::Y).
		endClass().

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

		// Loadouts placeholders
		addFunction("equipment", &config_placeholder).
		addFunction("setLoadout", &config_placeholder).

		// Custom crosshairs placeholders
		addFunction("crosshair", &config_placeholder).
		addFunction("crosshairs", &config_placeholder).
		addFunction("setCrosshairs", &config_placeholder).

		// Custom projectiles placeholders
		addFunction("getProjectile", &config_placeholder).
		addFunction("setProjectile", &config_placeholder).
		addFunction("cloneProjectile", &config_placeholder).
		addFunction("setProjectileColor", &config_placeholder).

		// HUD/Mute

		beginClass<ATrHUD>("HUD").
			addData("canvas", &ATrHUD::Canvas).
		endClass().
		addFunction("project", &hud_project).
		addFunction("drawDamageNumber", &hud_drawDamageNumber).
		addFunction("isOnScreen", &hud_isOnScreen).
		addFunction("getPlayerPos", &hud_getPlayerPos).

		beginClass<UCanvas>("Canvas").
		endClass().

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

		// Sounds
		addFunction("modifySound", &config_modifySound).
		addFunction("modifySoundRe", &config_modifySoundRe).
		addFunction("searchSound", &config_searchSoundRe).
		addFunction("searchSoundRe", &config_searchSoundRe).

		// Keybinds
		addFunction("bindKey", &config_bindKey).
		addFunction("unbindKey", &config_unbindKey).
		beginClass<FKeyBind>("KeyBind").
			addProperty("name", &FKeyBind::getName).
			addProperty("command", &FKeyBind::getCommand).
			addProperty("ctrl", &FKeyBind::getControl).
			addProperty("shift", &FKeyBind::getShift).
			addProperty("alt", &FKeyBind::getAlt).
			addProperty("ignoreCtrl", &FKeyBind::getIgnoreControl).
			addProperty("ignoreShift", &FKeyBind::getIgnoreShift).
			addProperty("ignoreAlt", &FKeyBind::getIgnoreAlt).
		endClass().
		addFunction("searchTribesInputCommands", &config_searchTribesInputCommands).

		// Console commands as lua functions for the use as keybinds
		addFunction("reloadSounds", &config_reloadSounds).
		beginNamespace("stopwatch").
			addFunction("toggle", &stopwatch).
			addFunction("start", &stopwatchStart).
			addFunction("stop", &stopwatchStop).
		endNamespace().
		beginNamespace("state").
			addFunction("save", &savesSave).
			addFunction("saveTo", &savesSaveTo).
			addFunction("recall", &savesRecall).
			addFunction("recallTo", &savesRecallTo).
			addFunction("tp", &savesTp).
			addFunction("tpTo", &savesTpTo).
			addFunction("reset", &savesReset).
			addFunction("setToSpawns", &savesToSpawns).
		endNamespace().
		beginNamespace("route").
			addFunction("rec", &routeRec).
			addFunction("record", &routeRec).
			addFunction("recStart", &routeStartRec).
			addFunction("recStop", &routeStopRec).
			addFunction("replay", &routeReplay).
			addFunction("replayStart", &routeStartReplay).
			addFunction("replayStop", &routeStopReplay).
			addFunction("reset", &routeReset).
			addFunction("save", &routeSaveFile).
			addFunction("load", &routeLoadFile).
			addFunction("search", &routeList).
			addFunction("find", &routeList).
			addFunction("list", &routeListAll).
			addFunction("enableBot", &routeEnableBot).
			addFunction("getAll", &routeGetAll).
			addFunction("getEnemyRoutes", &routeGetEnemyRoutes).
		endNamespace().
		addFunction("toggleTurrets", &toggleTurrets).
		addFunction("togglePower", &togglePower).
		addFunction("returnFlags", &returnFlags).

		// Custom HUD drawing functions
		addFunction("drawText",        &Utils::drawText).
		addFunction("drawSmallText",   &Utils::drawSmallText).
		addFunction("drawUTText",      &Utils::drawUTText).
		addFunction("drawRect",        &Utils::drawRect).
		addFunction("drawBox",         &Utils::drawBox).
		addFunction("drawProgressBar", &Utils::drawProgressBar).

		// Custom HUD getter functions
		beginNamespace("viewPort").
			addFunction("size", getViewPortData::size).
			addFunction("isMainMenuOpen", getViewPortData::isMainMenuOpen).
		endNamespace().
		beginNamespace("player").
			addFunction("name",            getPlayerData::name).
			addFunction("isAlive",         getPlayerData::isAlive).
			addFunction("isFirstPerson",   getPlayerData::isFirstPerson).
			addFunction("isRaged",         getPlayerData::isRaged).
			addFunction("isVehicle",       getPlayerData::isVehicle).
			addFunction("isShielded",      getPlayerData::isShielded).
			addFunction("hasFlag",         getPlayerData::hasFlag).
			addFunction("energy",          getPlayerData::energy).
			addFunction("energyMax",       getPlayerData::energyMax).
			addFunction("energyPct",       getPlayerData::energyPct).
			addFunction("ping",            getPlayerData::ping).
			addFunction("classId",         getPlayerData::classId).
			addFunction("health",          getPlayerData::health).
			addFunction("healthMax",       getPlayerData::healthMax).
			addFunction("speed",           getPlayerData::speed).
			addFunction("respawnTime",     getPlayerData::respawnTime).
			addFunction("numDeployables",  getPlayerData::numDeployables).
			addFunction("numMines",        getPlayerData::numMines).
			addFunction("score",           getPlayerData::score).
			addFunction("rabbitRank",      getPlayerData::rabbitRank).
			addFunction("teamNum",         getPlayerData::teamNum).
			addFunction("kills",           getPlayerData::kills).
			addFunction("deaths",          getPlayerData::deaths).
			addFunction("assists",         getPlayerData::assists).
			addFunction("arenaSpawnsLeft", getPlayerData::arenaSpawnsLeft).
		endNamespace().
		beginNamespace("weapon").
			addFunction("isReadyToFire",      getWeaponData::isReadyToFire).
			addFunction("isReloading",        getWeaponData::isReloading).
			addFunction("isPack",             getWeaponData::isPack).
			addFunction("isPassiveReady",     getWeaponData::isPassiveReady).
			addFunction("isLowAmmo",          getWeaponData::isLowAmmo).
			addFunction("ammo",               getWeaponData::ammo).
			addFunction("ammoMax",            getWeaponData::ammoMax).
			addFunction("ammoCarried",        getWeaponData::ammoCarried).
			addFunction("ammoMaxCarried",     getWeaponData::ammoMaxCarried).
			addFunction("ammoTotal",          getWeaponData::ammoTotal).
			addFunction("name",               getWeaponData::name).
		endNamespace().
		beginNamespace("currentWeapon").
			addFunction("isReadyToFire",      getCurrentWeaponData::isReadyToFire).
			addFunction("isReloading",        getCurrentWeaponData::isReloading).
			addFunction("isReloaded",         getCurrentWeaponData::isReloaded).
			addFunction("isPack",             getCurrentWeaponData::isPack).
			addFunction("isLowAmmo",          getCurrentWeaponData::isLowAmmo).
			addFunction("ammo",               getCurrentWeaponData::ammo).
			addFunction("ammoMax",            getCurrentWeaponData::ammoMax).
			addFunction("ammoCarried",        getCurrentWeaponData::ammoCarried).
			addFunction("ammoMaxCarried",     getCurrentWeaponData::ammoMaxCarried).
			addFunction("ammoTotal",          getCurrentWeaponData::ammoTotal).
			addFunction("equippedAt",         getCurrentWeaponData::equippedAt).
			addFunction("name",               getCurrentWeaponData::name).
		endNamespace().
		beginNamespace("vehicle").
			addFunction("health",    getVehicleData::health).
			addFunction("healthMax", getVehicleData::healthMax).
			addFunction("energyPct", getVehicleData::energyPct).
			addFunction("ammo",      getVehicleData::ammo).
			addFunction("ammoMax",   getVehicleData::ammoMax).
			addFunction("speed",     getVehicleData::speed).
		endNamespace().
		beginNamespace("game").
			addFunction("type",              getGameData::type).
			addFunction("timeStr",           getGameData::timeStr).
			addFunction("isOfflinePlay",     getGameData::isOfflinePlay).
			addFunction("isOver",            getGameData::isOver).
			addFunction("isGenUp",           getGameData::isGenUp).
			addFunction("isWarmUp",          getGameData::isWarmUp).
			addFunction("genAutoRepairTime", getGameData::genAutoRepairTime).
			addFunction("overTimeLimit",     getGameData::overTimeLimit).
			addFunction("score",             getGameData::score).
			addFunction("scoreLimit",        getGameData::scoreLimit).
			addFunction("time",              getGameData::time).
			addFunction("timeLimit",         getGameData::timeLimit).
		endNamespace().
		beginNamespace("rabbit").
			addFunction("leaderBoardScore", getRabbitData::leaderBoardScore).
			addFunction("leaderBoardName",  getRabbitData::leaderBoardName).
			addFunction("rabbitName",       getRabbitData::rabbitName).
		endNamespace().
		beginNamespace("cah").
			addFunction("pointsNum",   getCaHData::pointsNum).
			addFunction("pointsHeld",  getCaHData::pointsHeld).
			addFunction("pointHolder", getCaHData::pointHolder).
			addFunction("pointLabel",  getCaHData::pointLabel).
		endNamespace().
		beginNamespace("arena").
			addFunction("round",      getArenaData::round).
			addFunction("roundScore", getArenaData::roundScore).
			addFunction("playerStatus", getArenaData::playerStatus).
		endNamespace().
		beginNamespace("flag").
			addFunction("isHome",     getFlagData::isHome).
			addFunction("returnTime", getFlagData::returnTime).
			addFunction("holderName", getFlagData::holderName).
		endNamespace().

		beginNamespace("config").
			addFunction("reloadVariables", &config_rereadVariables).
			addFunction("reload", &config_reload).
		endNamespace().
	endNamespace();

	if (!Logger::isQuiet())
	{
		getGlobalNamespace(_state)
			.addFunction("profilerStart", &Profiler::start)
			.addFunction("profilerStop", &Profiler::stop)
			.addFunction("profiler", &Profiler::toggle)
		.endNamespace();
	}
}
