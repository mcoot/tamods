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
}

#define SET_VARIABLE(type, var) (lua.setVar<type>(var, #var))
void Config::setVariables()
{
	SET_VARIABLE(int, damageNumbersLimit);
	SET_VARIABLE(bool, showErrorNotifications);
	SET_VARIABLE(bool, showWeapon);
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

		beginClass<ATrHUD>("HUD").
		endClass().
		addFunction("project", &hud_project).
		addFunction("drawDamageNumber", &hud_drawDamageNumber).
		addFunction("isOnScreen", &hud_isOnScreen).
		addFunction("getPlayerPos", &hud_getPlayerPos).

		addFunction("print", (void(*)(const std::string &)) &Utils::printConsole).
		addFunction("console", (void(*)(const std::string &)) &Utils::printConsole).
		addFunction("consoleRGB", (void(*)(const std::string &, const FColor &)) &Utils::printConsole).
		addFunction("notify", (void (*)(const std::string &, const std::string &)) &Utils::notify).
	endNamespace();
}
