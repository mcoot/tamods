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

class Config
{
public:
	Config();
	~Config();

	void reset();
	void parseFile();
	void setVariables();

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
	//TODO actual implimentation
	FColor enemyColor;
	FColor enemyIsFColor;
	FColor friendColor;
	FColor friendIsFColor;

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
};