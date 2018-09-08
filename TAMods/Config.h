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
#include "ParticleModuleHelper.h"
#include "SdkHeaders.h"
#include "Hooks.h"
#include "Audio.h"
#include "ConsoleCommands.h"
#include "Routes.h"
#include "SoundEffect.h"
#include "StateSaving.h"
#include "Stopwatch.h"

#ifndef RELEASE
void DebugCustomWeaponsBindFunc();
#endif

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

struct CustomProjectile
{
private:
	static void _freeModules(TArray<UParticleModule *> &mod)
	{
		for (int i = 0; i < mod.Count; i++)
		{
			ParticleModuleHelper::freeModuleTArrays(mod.Data[i]);
			free(mod.Data[i]);
		}
		free(mod.Data);
	}

	static void _cloneModules(TArray<UParticleModule *> &out, TArray<UParticleModule *> &in)
	{
		out.Data = (UParticleModule **)malloc(in.Count * sizeof(UParticleModule *));
		for (int i = 0; i < in.Count; i++)
			ParticleModuleHelper::copyModule(out.Data[i], in.Data[i]);
	}

public:
	static void freeParticleSystem(UParticleSystem *ps)
	{
		for (int em = 0; em < ps->Emitters.Count; em++)
		{
			UParticleEmitter *psem = ps->Emitters.Data[em];

			for (int lod = 0; lod < psem->LODLevels.Count; lod++)
			{
				UParticleLODLevel *pslod = psem->LODLevels.Data[lod];

				_freeModules(pslod->SpawnModules);
				_freeModules(pslod->UpdateModules);
				_freeModules(pslod->Modules);
				free(psem->LODLevels.Data[lod]);
			}
			free(psem->LODLevels.Data);
			free(ps->Emitters.Data[em]);
		}
		free(ps->Emitters.Data);
	}

	static UParticleSystem *cloneParticleSystem(UParticleSystem *ps)
	{
		int timesec = clock() / CLOCKS_PER_SEC;
		UParticleSystem *out = NULL;

		if (!ps)
			return NULL;

		// 10 secs is the time a static straight up mortar takes to fall down, so 20 should be safe
		if (freePS.size() && timesec - freeTimes.front() > 20)
		{
			out = freePS.front();
			freeParticleSystem(out);
			freePS.pop();
			freeTimes.pop();
		}
		else
			out = (UParticleSystem *)malloc(sizeof(UParticleSystem));
		memcpy(out, ps, sizeof(UParticleSystem));
		out->Emitters.Data = (UParticleEmitter **)malloc(ps->Emitters.Count * sizeof(UParticleEmitter *));

		for (int em = 0; em < ps->Emitters.Count; em++)
		{
			if (ps->Emitters.Data[em]->IsA(UParticleSpriteEmitter::StaticClass()))
			{
				out->Emitters.Data[em] = (UParticleSpriteEmitter *)malloc(sizeof(UParticleSpriteEmitter));
				memcpy(out->Emitters.Data[em], ps->Emitters.Data[em], sizeof(UParticleSpriteEmitter));
			}
			else
			{
				out->Emitters.Data[em] = (UParticleEmitter *)malloc(sizeof(UParticleEmitter));
				memcpy(out->Emitters.Data[em], ps->Emitters.Data[em], sizeof(UParticleEmitter));
			}

			UParticleEmitter *outem = out->Emitters.Data[em];
			UParticleEmitter *inem = ps->Emitters.Data[em];
			outem->LODLevels.Data = (UParticleLODLevel **)malloc(inem->LODLevels.Count * sizeof(UParticleLODLevel *));

			for (int lod = 0; lod < inem->LODLevels.Count; lod++)
			{
				outem->LODLevels.Data[lod] = (UParticleLODLevel *)malloc(sizeof(UParticleLODLevel));
				memcpy(outem->LODLevels.Data[lod], inem->LODLevels.Data[lod], sizeof(UParticleLODLevel));

				UParticleLODLevel *outlod = outem->LODLevels.Data[lod];
				UParticleLODLevel *inlod = inem->LODLevels.Data[lod];
				_cloneModules(outlod->Modules, inlod->Modules);
				_cloneModules(outlod->SpawnModules, inlod->SpawnModules);
				_cloneModules(outlod->UpdateModules, inlod->UpdateModules);
			}
		}
		usedPS.push(out);
		return out;
	}

	CustomProjectile()
		: weapon_id(0)
	{
		default_proj = NULL;
		default_ps = NULL;
		custom_ps = NULL;
	}

	CustomProjectile(int pweapon_id)
		: weapon_id(0)
	{
		auto wep = Data::weapon_id_to_proj_name.find(pweapon_id);
		if (wep == Data::weapon_id_to_proj_name.end() || wep->second.size() == 0)
			return;
		std::string def_proj_name = "TrProj_" + wep->second + " TribesGame.Default__TrProj_" + wep->second;
		default_proj = UObject::FindObject<ATrProjectile>(def_proj_name.c_str());
		if (!default_proj)
		{
			Utils::console("ERROR: Projectile could not be found for weapon #%d PLEASE REPORT TO /u/ensiss", pweapon_id);
			return;
		}
		//Utils::console("SET %s ", def_proj_name);
		default_ps = default_proj->ProjFlightTemplate;
		weapon_id = pweapon_id;
		custom_ps = cloneParticleSystem(default_ps);
	}

	~CustomProjectile()
	{
	}

	int weapon_id;
	ATrProjectile *default_proj;
	UParticleSystem *default_ps;
	UParticleSystem *custom_ps;

	static std::queue<UParticleSystem *> usedPS;
	static std::queue<UParticleSystem *> freePS;
	static std::queue<int> freeTimes;
};

struct CustomWeapon {
	UClass* normalClass;
	UClass* replacementClass;
	bool swapAnims;
	bool leavePositioning;
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
	bool   revertOriginalDamageNumbers;
	float  revertOriginalDamageNumbersThreshold;

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
	LuaRef *onQueueAccolade;

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

	// Route recording
	int routeDrawInterval;
	int routeDrawETAInterval;
	float routeDrawTransparency;
	bool routeReplayRotation;
	bool routeCinematicMode;

	// Sounds
	Audio audioEngine;

	SoundEffect s_hitSound,   s_headShot,     s_killSound,     s_bluePlate,  s_airMail,
	            s_streak1,    s_streak2,      s_streak3,       s_streak4,    s_streak5,
	            s_multiKill1, s_multiKill2,   s_multiKill3,    s_multiKill4, s_multiKill5,
	            s_firstBlood, s_headShotKill, s_artilleryShot, s_meleeKill,  s_roadKill, s_fastGrab;
	
	// Flag events
	SoundEffect s_flagBlueGrab,    s_flagRedGrab,
	            s_flagBluePickup,  s_flagRedPickup,
	            s_flagBlueCapture, s_flagRedCapture,
	            s_flagBlueReturn,  s_flagRedReturn,
	            s_flagBlueDrop,    s_flagRedDrop;
	std::vector<SoundEffect*>      s_soundEffects;

	// Pointers to vanilla sounds so we can enable/disable them without searching every time
	USoundCue   *hitsound, *headshotsound, *flagpickedup, *flagcaptured, *flagreturned;

	// Sound user variables
	int         hitSoundMode, // 0: no custom hitsounds, 1: static hitsounds 2: dynamic pitch 3: dynamic pitch inverse
	            hitSoundDamageRef; // Used as reference for the calculation when to raise and when to lower pitch
	float       hitSoundPitchMin, hitSoundPitchMax;
	
	std::string  soundHit,  soundHeadShot,  soundKill,  soundAirMail,  soundBluePlate;
	float       volumeHit, volumeHeadShot, volumeKill, volumeAirMail, volumeBluePlate;
	
	// Accolades
	std::string soundStreak1,     soundStreak2,       soundStreak3,        soundStreak4,     soundStreak5,
	            soundMultiKill1,  soundMultiKill2,    soundMultiKill3,     soundMultiKill4,  soundMultiKill5,
	            soundFirstBlood,  soundHeadShotKill,  soundArtilleryShot,  soundMeleeKill,   soundRoadKill, soundFastGrab;
	float       volumeStreak1,    volumeStreak2,      volumeStreak3,       volumeStreak4,    volumeStreak5,
	            volumeMultiKill1, volumeMultiKill2,   volumeMultiKill3,    volumeMultiKill4, volumeMultiKill5,
	            volumeFirstBlood, volumeHeadShotKill, volumeArtilleryShot, volumeMeleeKill,  volumeRoadKill, volumeFastGrab;
	
	// Flag events
	std::string soundFlagBlueGrab,     soundFlagRedGrab,
	            soundFlagBluePickup,   soundFlagRedPickup,
	            soundFlagBlueCapture,  soundFlagRedCapture,
	            soundFlagBlueReturn,   soundFlagRedReturn,
	            soundFlagBlueDrop,     soundFlagRedDrop;
	float       volumeFlagBlueGrab,    volumeFlagRedGrab,
	            volumeFlagBluePickup,  volumeFlagRedPickup,
				volumeFlagBlueCapture, volumeFlagRedCapture,
				volumeFlagBlueReturn,  volumeFlagRedReturn,
				volumeFlagBlueDrop,    volumeFlagRedDrop;

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

	// Whether to use the ping replicated from the server, or locally calculated
	bool useServerSidePing;

	// Console
	float consoleSize;
	float consoleTransparency;

	//Stats
	bool recordStats;
	bool recordTeamStats;
	bool saveTeamStats;
	bool saveStats;

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

	// Custom weapon models
	std::map<UClass*, CustomWeapon> wep_class_to_custom_weapon;

	// Custom bullet color
	std::map<int, CustomProjectile *> wep_id_to_custom_proj;
	std::map<int, CustomProjectile *> proj_class_to_custom_proj;

	// Custom lua keybinds
	std::map<int, LuaRef **> lua_keybinds;
	LuaRef                   *onInputEvent;

	// Bools for reloading
	bool shouldReloadTrHud;
};
