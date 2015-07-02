#pragma once

#include <fstream>
#include <string>
#include <regex>
#include <map>
#include "Loadout.h"
#include "Utils.h"
#include "Data.h"
#include "Lua.h"
#include "Geom.h"
#include "ParticleModuleHelper.h"
#include "SdkHeaders.h"

struct Crosshairs
{
	Crosshairs(const std::string &pstd, const std::string &pzoomed)
		: standard(pstd), zoomed(pzoomed)
	{ }

	static Crosshairs create(const std::string &xhair)
	{
		return Crosshairs(xhair, xhair);
	}

	static Crosshairs create2(const std::string &xhair1, const std::string &xhair2)
	{
		return Crosshairs(xhair1, xhair2);
	}

	std::string standard;
	std::string zoomed;
};

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
	static void _cloneModules(TArray<UParticleModule *> &out, TArray<UParticleModule *> &in)
	{
		out.Data = (UParticleModule **)malloc(in.Count * sizeof(UParticleModule *));
		for (int i = 0; i < in.Count; i++)
			ParticleModuleHelper::copyModule(out.Data[i], in.Data[i]);
	}

public:
	static UParticleSystem *cloneParticleSystem(UParticleSystem *ps)
	{
		UParticleSystem *out = (UParticleSystem *)malloc(sizeof(UParticleSystem));
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
				_cloneModules(outlod->SpawnModules, inlod->SpawnModules);
				_cloneModules(outlod->UpdateModules, inlod->UpdateModules);

				// Modules and SpawnModules seem to be the same so it's better to reuse the pointers
				outlod->Modules.Data = (UParticleModule **)malloc(outlod->SpawnModules.Count * sizeof(UParticleModule *));
				for (int i = 0; i < outlod->SpawnModules.Count; i++)
					outlod->Modules.Data[i] = outlod->SpawnModules.Data[i];
			}
		}
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
		auto wep = Data::weapon_id_to_name.find(pweapon_id);
		if (wep == Data::weapon_id_to_name.end())
			return;
		std::string def_proj_name = "TrProj_" + wep->second + " TribesGame.Default__TrProj_" + wep->second;
		default_proj = UObject::FindObject<ATrProjectile>(def_proj_name.c_str());
		if (!default_proj)
			return;
		default_ps = default_proj->ProjFlightTemplate;
		weapon_id = pweapon_id;
		custom_ps = cloneParticleSystem(default_ps);
	}

	~CustomProjectile()
	{
		delete custom_ps;
	}

	int weapon_id;
	ATrProjectile *default_proj;
	UParticleSystem *default_ps;
	UParticleSystem *custom_ps;
};

class Config
{
public:
	Config();
	~Config();

	void reset();
	void parseFile();
	void setVariables();
	void updateDefaults();

	void reloadSkiBars(UGfxTrHud *currHud, bool updated = true);

public:
	Lua lua;

	int damageNumbersLimit;
	bool showErrorNotifications;
	bool showWeapon;
	bool showFirstPersonAmmo;
	bool showCrosshair;
	float crosshairScale;
	FColor crosshairColor;
	Loadout *loadouts[9][9];

	// Damage number customization
	float damageNumbersOffsetX;
	float damageNumbersOffsetY;
	float damageNumbersScale;

	// Damage number / chain count streaming
	bool showDamageNumberStream;
	bool showChainBulletHitCount;
	double damageNumberStreamTimeout;
	unsigned long lastDamageNumberShowEventTime;
	int damageNumberStreamValue;
	int damageNumberStreamCount;
	bool showStreamTotalOnly;

	// Lua scripting damage numbers
	LuaRef *onDamageNumberCreate;
	LuaRef *onDamageNumberUpdate;

	// Custom damage number text
	std::string damageNumberCustomText;

	// Damage number colors
	bool showRainbow;
	int rainbowBulletInt;
	FColor damageNumbersColorMin;
	FColor damageNumbersColorMax;
	//Chat Cols
	FColor friendlyChatColor;
	FColor enemyChatColor;
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

	// Sounds
	bool playHitSound;

	// HUD elements toggle
	bool showObjectiveIcon;
	bool showFlagBaseIcon;
	bool showCTFBaseIcon;
	bool showNuggetIcon;
	bool showPlayerIcon;
	bool showVehicleIcon;
	bool showMineIcon;
	bool showSensorIcon;

	//Stats
	bool recordStats;

	//Global Mute
	std::vector<MutedPlayer> globalMuteList;

	// Custom bullet color
	std::map<int, CustomProjectile *> wep_id_to_custom_proj;
	std::map<int, CustomProjectile *> proj_class_to_custom_proj;

	// Bools for reloading
	bool shouldReloadGfxTrHud;
};