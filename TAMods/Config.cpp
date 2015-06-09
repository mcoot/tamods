#include "Config.h"

Config g_config;

Config::Config()
{
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

	crosshairs.clear();
	
	showErrorNotifications = true;
	showWeapon = true;
	showCrosshair = true;
	crosshairScale = 1;

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
	enemyColor = Utils::rgb(255, 0, 255);
	enemyIsFColor = Utils::rgb(255, 125, 0);
	friendColor = Utils::rgb(0, 125, 255);
	friendIsFColor = Utils::rgb(0, 255, 0);

	// Toggle HUD
	showObjectiveIcon = true;
	showFlagBaseIcon = true;
	showCTFBaseIcon = true;
	showNuggetIcon = true;
	showPlayerIcon = true;
	showVehicleIcon = true;

	//Stats
	recordStats = false;
}

void Config::parseFile()
{
	const char *profile = getenv("USERPROFILE");
	std::string directory;
	Lua lua;

	if (profile)
		directory = std::string(profile) + "\\Documents\\My Games\\Tribes Ascend\\TribesGame\\config\\";
	else
		directory = std::string("C:\\");
	reset();
	std::string err = lua.doFile(directory + "config.lua");
	if (err.size())
	{
		Utils::console("Lua config error: %s", err.c_str());
		return;
	}
	setVariables(lua);
}

#define SET_VARIABLE(type, var) (lua.setVar<type>(var, #var))
void Config::setVariables(Lua &lua)
{
	SET_VARIABLE(int, damageNumbersLimit);
	SET_VARIABLE(bool, showErrorNotifications);
	SET_VARIABLE(bool, showWeapon);
	SET_VARIABLE(bool, showCrosshair);
	SET_VARIABLE(float, crosshairScale);

	// Damage number customization
	SET_VARIABLE(float, damageNumbersOffsetX);
	SET_VARIABLE(float, damageNumbersOffsetY);
	SET_VARIABLE(float, damageNumbersScale);

	// Damage number / chain count streaming
	SET_VARIABLE(bool, showDamageNumberStream);
	SET_VARIABLE(bool, showChainBulletHitCount);
	SET_VARIABLE(double, damageNumberStreamTimeout);

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
	SET_VARIABLE(FColor, enemyColor);
	SET_VARIABLE(FColor, enemyIsFColor);
	SET_VARIABLE(FColor, friendColor);
	SET_VARIABLE(FColor, friendIsFColor);

	// Toggle HUD
	SET_VARIABLE(bool, showObjectiveIcon);
	SET_VARIABLE(bool, showFlagBaseIcon);
	SET_VARIABLE(bool, showCTFBaseIcon);
	SET_VARIABLE(bool, showNuggetIcon);
	SET_VARIABLE(bool, showPlayerIcon);
	SET_VARIABLE(bool, showVehicleIcon);

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

static bool config_setCrosshairs(const std::string &pclass, const std::string &weapon, Crosshairs &xhairs)
{
	int weapon_id = getWeaponID(pclass, weapon);
	if (!weapon_id)
		return false;
	int xhair1 = Utils::searchMapId(Data::crosshairs, xhairs.standard, "Crosshair");
	int xhair2 = Utils::searchMapId(Data::crosshairs, xhairs.zoomed, "Crosshair");
	g_config.crosshairs[weapon_id] = std::pair<int, int>(xhair1, xhair2);
	return true;
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
	endNamespace();
}
