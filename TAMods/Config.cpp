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
	damageNumbersLimit = 0;
	showErrorNotifications = true;
	showWeapon = true;
	showCrosshair = true;
	crosshairScale = 1;

	// Damage number stream
	showDamageNumberStream = false;
	showRainbow = false;
	// Default damage stream reset time is 1/2 second
	damageNumberStreamingResetTime = 0.5;
	lastDamageNumberShowEventTime = 0;
	damageNumberStreamValue = 0;
	damageNumberStreamCount = 0;
	rainbowBulletInt = 0;
}

void Config::parseFile()
{
	const char *profile = getenv("USERPROFILE");
	std::string directory;
	std::string line;

	if (profile)
		directory = std::string(profile) + "\\Documents\\My Games\\Tribes Ascend\\TribesGame\\config\\";
	else
		directory = std::string("C:\\");
	std::ifstream infile(directory + "mods.conf");
	if (!infile.is_open())
	{
		Utils::console("WARNING: Couldn't open file 'mods.conf' in directory: %s", directory.c_str());
		return;
	}
	reset();

	while (std::getline(infile, line))
	{
		if (Utils::trim(line)[0] == ';' || parseLine(line))
			continue;
		std::smatch match;
		// class#id(loadout name): primary, secondary, belt, pack, perk1, perk2
		std::regex rx(R"rx(^\s*([a-zA-Z]+)#([1-9])\s*\(([^)]*)\):([-'a-zA-Z0-9\s]*),([-'a-zA-Z0-9\s]*),([-'a-zA-Z0-9\s]*),([-'a-zA-Z0-9\s]*),([-'a-zA-Z0-9\s]*),([-'a-zA-Z0-9\s]*)$)rx");
		if (std::regex_match(line, match, rx))
		{
			Loadout *loadout = new Loadout(match);
			if (!loadout->valid)
			{
				delete loadout;
				continue;
			}
			if (loadouts[loadout->class_type][loadout->loadout_nb])
				delete loadouts[loadout->class_type][loadout->loadout_nb];
			loadouts[loadout->class_type][loadout->loadout_nb] = loadout;
		}
	}
	infile.close();
}

bool Config::parseLine(const std::string &str)
{
	std::smatch match;
	std::regex rx;

	// setCrosshairs(className, weaponName): crosshairName, zommedCrosshairName
	rx = std::regex(R"rx(^\s*setcrosshairs?\s*\(\s*([a-zA-Z]+)\s*,([-'a-zA-Z0-9\s]*)\)\s*:\s*([_a-zA-Z0-9\s]*)\s*,\s*([_a-zA-Z0-9\s]*)\s*$)rx", std::regex_constants::icase);
	if (std::regex_match(str, match, rx))
	{
		int weapon_id = _getWeaponID(match[1], match[2]);
		if (!weapon_id)
			return (true);
		int xhair1 = Utils::searchMapId(Data::crosshairs, match[3], "Crosshair");
		int xhair2 = Utils::searchMapId(Data::crosshairs, match[4], "Crosshair");
		crosshairs[weapon_id] = std::pair<int, int>(xhair1, xhair2);
		return (true);
	}

	// varName = x.xxx (float)
	rx = std::regex(R"rx(^\s*([a-zA-Z]+)\s*=\s*(-?[.0-9]+)\s*$)rx");
	if (std::regex_match(str, match, rx))
	{
		std::string name = Utils::cleanString(match[1]);
		if (name == "crosshairscale")
			crosshairScale = (float) atof(std::string(match[2]).c_str());
		else if (name == "damagenumberslimit")
			damageNumbersLimit = (int) atof(std::string(match[2]).c_str());
		else if (name == "damagenumberstreamtimeout")
			damageNumberStreamingResetTime = (double)atof(std::string(match[2]).c_str());
		return (true);
	}

	// varName = true/false (boolean)
	rx = std::regex(R"rx(^\s*([a-zA-Z]+)\s*=\s*(true|false)\s*$)rx");
	if (std::regex_match(str, match, rx))
	{
		std::string name = Utils::cleanString(match[1]);
		if (name == "showerrornotifications")
			showErrorNotifications = (match[2] == "true");
		else if (name == "showweapon")
			showWeapon = (match[2] == "true");
		else if (name == "showcrosshair")
			showCrosshair = (match[2] == "true");
		else if (name == "showchainbullethitcount")
			showChainBulletHitCount = (match[2] == "true");
		else if (name == "showdamagenumberstream")
			showDamageNumberStream = (match[2] == "true");
		else if (name == "showrainbow")
			showRainbow = (match[2] == "true");
		
		return (true);
	}
	return (false);
}

int Config::_getWeaponID(const std::string &class_name, const std::string &str)
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
