#pragma once

#include <fstream>
#include <string>
#include <regex>
#include <queue>
#include <map>
#include "Logger.h"
#include "Utils.h"
#include "Data.h"
#include "DataGetters.h"
#include "Lua.h"
#include "Geom.h"
#include "SdkHeaders.h"
#include "Hooks.h"
#include "Audio.h"
#include "SoundEffect.h"

#define MODVERSION 0.51

// Declared here to use as lua functions
void stopwatch();
void stopwatchStart();
void stopwatchStop();
void stopwatchReset();
void savesSave();
void savesSaveTo(int n);
void savesTp();
void savesTpTo(int n);
void savesRecall();
void savesRecallTo(int n);
void savesReset();
void savesToSpawns();
void toggleTurrets();
void togglePower();
void returnFlags();

// Route recording
LuaRef routeGetAll();
LuaRef routeGetEnemyRoutes();
void routeRec();
void routeStartRec();
void routeStopRec();
void routeReplay();
void routeStartReplay(float startTime);
void routeStopReplay();
void routeReset();
void routeSaveFile(const std::string &desc);
void routeLoadFile(unsigned int num);
void routeList(const std::string &needle);
unsigned int routeListAll();
void routeEnableBot(bool on);

struct MutedPlayer
{
	MutedPlayer(const std::string &pusername, const bool &pmuteVGS, const bool &pmuteText, const bool &pmuteDirectMessage)
		: username(pusername), muteVGS(pmuteVGS), muteText(pmuteText), muteDirectMessage(pmuteDirectMessage)
	{
		// Convert player name to lowercase (since T:A names are case-insensitive)
		for (unsigned i = 0; i < username.length(); i++)
		{
			if (username.at(i) >= 'A' && username.at(i) <= 'Z')
			{
				username.at(i) = username.at(i) + ('a' - 'A');
			}
		}
	}

	static MutedPlayer create_custom(const std::string &pusername, const bool &pmuteVGS, const bool &pmuteText, const bool &pmuteDirectMessage)
	{
		return MutedPlayer(pusername, pmuteVGS, pmuteText, pmuteDirectMessage);
	}

	static MutedPlayer create(const std::string &pusername)
	{
		return MutedPlayer(pusername, true, true, true);
	}
	
	std::string username;
	bool muteVGS;
	bool muteText;
	bool muteDirectMessage;
};

class Config
{
public:
	struct TogglableIcon
	{
		bool *variable_ptr;
		const char *func_name;

		TogglableIcon(bool *pvar, const char *pfunc)
			: variable_ptr(pvar), func_name(pfunc) {}
	};

public:
	Config();
	~Config();

	void reset();
	void parseFile();
	void setVariables();
	void updateDefaults();
	void initializeAudio();
	void reloadSounds();
	void refreshSoundVolumes();
	void stopwatchDisplayTime(const std::string &prestr, float cur_time);
	void stopwatchPrintSummary();

	void reloadTrHUD(ATrHUD *currHud, bool updated = true);

public:
	Lua lua;

	int     damageNumbersLimit;
	bool    showWeapon;
	bool    showFirstPersonAmmo;
	bool    showBodyMesh;
	bool    showCrosshair;
	float   crosshairScale;
	FColor  crosshairColor;

	// Damage number customization
	float  damageNumbersOffsetX;
	float  damageNumbersOffsetY;
	float  damageNumbersScale;

	// Damage number / chain count streaming
	bool   showDamageNumberStream;
	bool   showChainBulletHitCount;
	double damageNumberStreamTimeout;
	unsigned long lastDamageNumberShowEventTime;
	int    damageNumberStreamValue;
	int    damageNumberStreamCount;
	bool   showStreamTotalOnly;

	// Lua scripting damage numbers
	LuaRef *onDamageNumberCreate;
	LuaRef *onDamageNumberUpdate;
	// Lua scripting HUD
	LuaRef *onDrawCustomHud;
	LuaRef *onAddToCombatLog;
	LuaRef *onChatMessage;
	LuaRef *onGameMessage;
	LuaRef *onKillMessage;
	LuaRef *onDrawHealthBar;

	// Custom damage number text
	std::string damageNumberCustomText;

	// Damage number colors
	bool   showRainbow;
	int    rainbowBulletInt;
	FColor damageNumbersColorMin;
	FColor damageNumbersColorMax;
	//Chat Cols
	FColor friendlyChatColor;
	FColor enemyChatColor;
	FColor whisperChatColor;
	FColor friendlyHUDChatColor;
	FColor enemyHUDChatColor;
	//Marker Cols
	FColor friendlyColor;
	FColor enemyColor;
	FColor enemyMarkerColor;
	FColor enemyIsFMarkerColor;
	FColor friendlyMarkerColor;
	FColor friendlyIsFMarkerColor;

	// Fix Ski bars' ridiculous values
	float skiBarMin;
	float skiBarMax;

	// Roam map variables
	bool disableBaseTurrets;
	bool disablePower;
	bool showSavedLocations;
	int  maxSpeedWithFlag;
	int  decelerationRateWithFlag;

	// Route timer
	bool stopwatchStopOnCap;
	bool stopwatchStopOnDeath;
	bool stopwatchNotifications;
	// Non-user variables
	bool stopwatchFlagRecall = false;
	bool stopwatchRunning    = false;
	float stopwatchStartTime = 0.0f;
	float stopwatchGrabTime  = 0.0f;
	float stopwatchCapTime   = 0.0f;
	int stopwatchGrabHealth  = 0;
	int stopwatchGrabSpeed   = -1;
	bool routeBotReplay;

	// Route recording
	int routeDrawInterval;
	int routeDrawETAInterval;
	bool routeReplayRotation;
	bool routeCinematicMode;

	// Sounds
	Audio audioEngine;
	SoundEffect s_hitSound,   s_headShot,     s_killSound;
	SoundEffect s_bluePlate,  s_airMail;
	SoundEffect s_streak1,    s_streak2,      s_streak3,       s_streak4,    s_streak5;
	SoundEffect s_multiKill1, s_multiKill2,   s_multiKill3,    s_multiKill4, s_multiKill5;
	SoundEffect s_firstBlood, s_headShotKill, s_artilleryShot, s_meleeKill,  s_roadKill, s_fastGrab;
	// Flag events
	SoundEffect s_flagBlueGrab,    s_flagRedGrab;
	SoundEffect s_flagBluePickup,  s_flagRedPickup;
	SoundEffect s_flagBlueCapture, s_flagRedCapture;
	SoundEffect s_flagBlueReturn,  s_flagRedReturn;
	SoundEffect s_flagBlueDrop,	   s_flagRedDrop;
	std::vector<SoundEffect*> s_soundEffects;
	// Pointers to vanilla sounds so we can enable/disable them without searching every time
	USoundCue *hitsound;
	USoundCue *headshotsound;
	USoundCue *flagpickedup;
	USoundCue *flagcaptured;
	USoundCue *flagreturned;
	// Sound user variables
	int   hitSoundMode; // 0: no custom hitsounds, 1: static hitsounds 2: dynamic pitch 3: dynamic pitch inverse
	bool  customHeadShotSound;
	bool  customKillSound;
	bool  customAirMailSound;
	bool  customBluePlateSound;
	float hitSoundPitchMin;
	float hitSoundPitchMax;
	int   hitSoundDamageRef; // Used as reference for the calculation when to raise and when to lower pitch
	float volumeHitSound;
	float volumeHeadShot;
	float volumeKillSound;
	float volumeBluePlate;
	float volumeAirMail;
	// Accolades
	bool  customStreak1,    customStreak2,      customStreak3,       customStreak4,    customStreak5;
	bool  customMultiKill1, customMultiKill2,   customMultiKill3,    customMultiKill4, customMultiKill5;
	bool  customFirstBlood, customHeadShotKill, customArtilleryShot, customMeleeKill,  customRoadKill, customFastGrab;
	float volumeStreak1,    volumeStreak2,      volumeStreak3,       volumeStreak4,    volumeStreak5;
	float volumeMultiKill1, volumeMultiKill2,   volumeMultiKill3,    volumeMultiKill4, volumeMultiKill5;
	float volumeFirstBlood, volumeHeadShotKill, volumeArtilleryShot, volumeMeleeKill,  volumeRoadKill, volumeFastGrab;
	// Flag events
	bool  customFlagBlueGrab,    customFlagRedGrab;
	bool  customFlagBluePickup,  customFlagRedPickup;
	bool  customFlagBlueCapture, customFlagRedCapture;
	bool  customFlagBlueReturn,  customFlagRedReturn;
	bool  customFlagBlueDrop,    customFlagRedDrop;
	float volumeFlagBlueGrab,    volumeFlagRedGrab;
	float volumeFlagBluePickup,  volumeFlagRedPickup;
	float volumeFlagBlueCapture, volumeFlagRedCapture;
	float volumeFlagBlueReturn,  volumeFlagRedReturn;
	float volumeFlagBlueDrop,    volumeFlagRedDrop;

	// HUD elements toggle
	static TogglableIcon togglable_icons[];
	bool showObjectiveIcon;
	bool showFlagBaseIcon;
	bool showFlagHomeBaseIcon;
	bool showCTFBaseIcon;
	bool showNuggetIcon;
	bool showPlayerIcon;
	bool showVehicleIcon;
	bool showMineIcon;
	bool showSensorIcon;

	bool showObjectiveText;
	bool showMineText;

	// HUD scaling
	float IFFScale;
	bool  showHUDWeapons;

	//Stats
	bool recordStats;

	// Magic chain
	bool  useSmallBullets;
	bool  useMagicChain;
	bool  centerBulletSpawn;
	float bulletPingMultiplier;
	float bulletSpawnDelay;

	// Mouse sensitivity
	bool useFOVScaling;
	float sens;
	float sensZoom;
	float sensZoooom;

	// Weapon and bullet position
	bool customWeaponOffset;
	FVector weaponOffset;
	bool customBulletSpawnOffset;
	FVector bulletSpawnOffset;

	//Global Mute
	std::vector<MutedPlayer> globalMuteList;
	bool muteVGS;

	// Custom lua keybinds
	std::map<int, LuaRef **> lua_keybinds;
	LuaRef                   *onInputEvent;

	// Bools for reloading
	bool shouldReloadTrHud;
};
