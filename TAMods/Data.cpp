#include "Data.h"

namespace Data
{
	std::map<std::string, int> weapons[3][7] =
	{
		// LIGHT
		{
			// IMPACT
			{
				{ R"rx(^(spin(fusor)?|light(spin)?(fusor)?)$)rx", CONST_WEAPON_ID_SPINFUSOR_LIGHT },
				{ R"rx(^(bolt|boltlauncher)$)rx", CONST_WEAPON_ID_LAUNCHER_BOLT },
				{ R"rx(^(twin|twinfusor|lighttwinfusor)$)rx", CONST_WEAPON_ID_LIGHTTWINFUSOR },
				{ R"rx(^(blinks?|blinks?fusor)$)rx", CONST_WEAPON_ID_SPINFUSOR_LIGHT_100X },
			},
			// TIMED
			{
				{ R"rx(^((light)?(gl|grenadelauncher)|lgl)$)rx", CONST_WEAPON_ID_LIGHTGRENADELAUNCHER },
				{ R"rx(^(jackal)$)rx", CONST_WEAPON_ID_REMOTE_ARX_BUSTER },
			},
			// SPECIALTY
			{
				{ R"rx(^(bxt|bxt1|bxt1rifle)$)rx", CONST_WEAPON_ID_RIFLE_SNIPER },
				{ R"rx(^(phase|phaserifle)$)rx", CONST_WEAPON_ID_RIFLE_PHASE },
			},
			// AUTOMATIC
			{
				{ R"rx(^(falcon)$)rx", CONST_WEAPON_ID_PISTOL_FALCON },
				{ R"rx(^(lightassaultrifle|lar|ar|assaultrifle|rifle)$)rx", CONST_WEAPON_ID_RIFLE_ASSAULT_LIGHT },
			},
			// SHORT RANGE
			{
				{ R"rx(^(shotgun)$)rx", CONST_WEAPON_ID_SHOTGUN },
				{ R"rx(^(shocklance)$)rx", CONST_WEAPON_ID_PISTOL_H1 },
			},
			// SIDEARMS
			{
				{ R"rx(^(sparrow)$)rx", CONST_WEAPON_ID_PISTOL_SPARROW },
				{ R"rx(^(throwingknives|knives)$)rx", CONST_WEAPON_ID_THROWINGKNIVES },
			},
			// BELT
			{
				{ R"rx(^(nitrons?|impactnitrons?|impacts?)$)rx", CONST_WEAPON_ID_GRENADE_NITRON },
				{ R"rx(^(explosivenitrons?|explosives?)$)rx", CONST_WEAPON_ID_GRENADE_ST },
				{ R"rx(^(stickygrenades?|sticky|stickies)$)rx", CONST_WEAPON_ID_GRENADE_STICKY },
				{ R"rx(^(claymores?|claymoremines?)$)rx", CONST_WEAPON_ID_MINE_CLAYMORE },
				{ R"rx(^(prismmines?|mines?)$)rx", CONST_WEAPON_ID_MINE_PRISM },
				{ R"rx(^(chaffs?(grenades?)?)$)rx", CONST_WEAPON_ID_GRENADE_NINJASMOKE },
			},
		},

		// MEDIUM
		{
			// IMPACT
			{
				{ R"rx(^(spinfusor|spin)$)rx", CONST_WEAPON_ID_SPINFUSOR },
				{ R"rx(^(thumper)$)rx", CONST_WEAPON_ID_THUMPER },
				{ R"rx(^(twinfusor)$)rx", CONST_WEAPON_ID_TWINFUSOR },
				{ R"rx(^(blinks?|blinks?fusor)$)rx", CONST_WEAPON_ID_SPINFUSOR_100X },
			},
			// TIMED
			{
				{ R"rx(^(arxbuster|arx)$)rx", CONST_WEAPON_ID_ARX_BUSTER },
				{ R"rx(^(grenadelauncher|nadelauncher|launcher|gl)$)rx", CONST_WEAPON_ID_LAUNCHER_GRENADE },
			},
			// SPECIALTY
			{
				{ R"rx(^(improvedrepairtool|repairtool|repair)$)rx", CONST_WEAPON_ID_REPAIR_TOOL_SD },
				{ R"rx(^(elf(projector)?)$)rx", CONST_WEAPON_ID_ELFPROJECTOR },
			},
			// AUTOMATIC
			{
				{ R"rx(^(assaultrifle|rifle|ar)$)rx", CONST_WEAPON_ID_RIFLE_ASSAULT },
				{ R"rx(^(nj4smg|nj4)$)rx", CONST_WEAPON_ID_SMG_NJ4 },
				{ R"rx(^(plasmagun|plasma)$)rx", CONST_WEAPON_ID_PLASMA_GUN },
			},
			// SHORT RANGE
			{
				{ R"rx(^(sawed-?offshotgun|shotgun|sawed-?off)$)rx", CONST_WEAPON_ID_SHOTGUN_SAWED_OFF },
				{ R"rx(^(flak(cannon)?)$)rx", CONST_WEAPON_ID_TC24 },
			},
			// SIDEARMS
			{
				{ R"rx(^(nova|blaster|novablaster)$)rx", CONST_WEAPON_ID_PISTOL_NOVA_COLT },
				{ R"rx(^(eaglepistol|eagle|pistol)$)rx", CONST_WEAPON_ID_PISTOL_EAGLE },
			},
			// BELT
			{
				{ R"rx(^(emps?|empgrenades?)$)rx", CONST_WEAPON_ID_GRENADE_EMP },
				{ R"rx(^(blackouts?|blackoutgrenades?)$)rx", CONST_WEAPON_ID_GRENADE_WHITEOUT },
				{ R"rx(^(clustergrenades?|clusters?)$)rx", CONST_WEAPON_ID_MIRV_GRENADE },
				{ R"rx(^(anti-?personnelgrenades?|aps?|apgrenades?)$)rx", CONST_WEAPON_ID_GRENADE_AP },
			},
		},

		// HEAVY
		{
			// IMPACT
			{
				{ R"rx(^(heavy(spin)?(fusor)?|spin(fusor)?|fusor)$)rx", CONST_WEAPON_ID_SPINFUSOR_HEAVY },
				{ R"rx(^(heavyboltlauncher|boltlauncher|bolt)$)rx", CONST_WEAPON_ID_LAUNCHER_BOLT_HEAVY },
				{ R"rx(^((heavy)?blinks?(fusor)?)$)rx", CONST_WEAPON_ID_SPINFUSOR_HEAVY_MKD },
				{ R"rx(^(heavytwinfusor|twinfusor|twin)$)rx", CONST_WEAPON_ID_HEAVYTWINFUSOR },
			},
			// TIMED
			{
				{ R"rx(^(fusionmortar|mortar)$)rx", CONST_WEAPON_ID_LAUNCHER_MORTAR },
				{ R"rx(^(mirvlauncher|mirv)$)rx", CONST_WEAPON_ID_LAUNCHER_MIRV },
			},
			// SPECIALTY
			{
				{ R"rx(^(saberlauncher|saber)$)rx", CONST_WEAPON_ID_LAUNCHER_SABER },
				{ R"rx(^(gladiator)$)rx", CONST_WEAPON_ID_SPIKELAUNCHER },
			},
			// AUTOMATIC
			{
				{ R"rx(^(chaingun)$)rx", CONST_WEAPON_ID_CHAINGUN },
				{ R"rx(^(x1|lmg|x1lmg)$)rx", CONST_WEAPON_ID_RIFLE_ASSAULT_X1 },
				{ R"rx(^(plasmacannon|plasma)$)rx", CONST_WEAPON_ID_PLASMA_CANNON },
			},
			// SHORT RANGE
			{
				{ R"rx(^(automaticshotgun|shotgun)$)rx", CONST_WEAPON_ID_SHOTGUN_AUTO },
				{ R"rx(^(efg)$)rx", CONST_WEAPON_ID_ELFFLAK },
			},
			// SIDEARMS
			{
				{ R"rx(^(novacolt|colt|nova)$)rx", CONST_WEAPON_ID_PISTOL_NOVA_SLUG },
				{ R"rx(^(mx|novablastermx|novamx|blastermx)$)rx", CONST_WEAPON_ID_PISTOL_NOVA_COLT_MKD },
			},
			// BELT
			{
				{ R"rx(^(fraggrenades?|frags?)$)rx", CONST_WEAPON_ID_GRENADE },
				{ R"rx(^(fractals?|fractalgrenades?)$)rx", CONST_WEAPON_ID_GRENADE_SPIKE },
				{ R"rx(^(mines?)$)rx", CONST_WEAPON_ID_MINE },
				{ R"rx(^(spinfusordisks?|spins?|disks?|spindisks?)$)rx", CONST_WEAPON_ID_SPINFUSOR_TOSS },
			},
		}
	};

	std::map<int, std::string> weapon_id_to_name = {
		{ CONST_WEAPON_ID_SPINFUSOR_LIGHT, "LightSpinfusor" },
		{ CONST_WEAPON_ID_LAUNCHER_BOLT, "BoltLauncher" },
		{ CONST_WEAPON_ID_SPINFUSOR_LIGHT_MKD, "LightSpinfusor_MKD" },
		{ CONST_WEAPON_ID_LIGHTTWINFUSOR, "LightTwinfusor" },
		{ CONST_WEAPON_ID_SPINFUSOR_LIGHT_100X, "LightSpinfusor_100X" },
		{ CONST_WEAPON_ID_SHOTGUN, "Shotgun" },
		{ CONST_WEAPON_ID_RIFLE_ASSAULT_LIGHT, "LightAssaultRifle" },
		{ CONST_WEAPON_ID_SHOTGUN_MKD, "Shotgun_MKD" },
		{ CONST_WEAPON_ID_RIFLE_SNIPER, "SniperRifle" },
		{ CONST_WEAPON_ID_RIFLE_PHASE, "PhaseRifle" },
		{ CONST_WEAPON_ID_RIFLE_SNIPER_MKD, "SniperRifle_MKD" },
		{ CONST_WEAPON_ID_SAP20, "SAP20" },
		{ CONST_WEAPON_ID_PISTOL_NOVA_COLT, "NovaColt" },
		{ CONST_WEAPON_ID_PISTOL_FALCON, "Falcon" },
		{ CONST_WEAPON_ID_PISTOL_NOVA_COLT_MKD, "NovaColt_MKD" },
		{ CONST_WEAPON_ID_ACCURIZEDSHOTGUN, "AccurizedShotgun" },
		{ CONST_WEAPON_ID_SMG_RHINO, "RhinoSMG" },
		{ CONST_WEAPON_ID_STEALTHLIGHTSPINFUSOR, "StealthLightSpinfusor" },
		{ CONST_WEAPON_ID_REMOTE_ARX_BUSTER, "RemoteArxBuster" },
		{ CONST_WEAPON_ID_SMG_RHINO_MKD, "RhinoSMG_MKD" },
		{ CONST_WEAPON_ID_PISTOL_SN7, "SN7" },
		{ CONST_WEAPON_ID_THROWINGKNIVES, "ThrowingKnives" },
		{ CONST_WEAPON_ID_PISTOL_SN7_MKD, "SN7_MKD" },
		{ CONST_WEAPON_ID_RIFLE_ASSAULT, "AssaultRifle" },
		{ CONST_WEAPON_ID_SPINFUSOR, "Spinfusor" },
		{ CONST_WEAPON_ID_RIFLE_ASSAULT_MKD, "AssaultRifle_MKD" },
		{ CONST_WEAPON_ID_TWINFUSOR, "Twinfusor" },
		{ CONST_WEAPON_ID_THUMPER_D, "ThumperD" },
		{ CONST_WEAPON_ID_PISTOL_EAGLE, "Eagle" },
		{ CONST_WEAPON_ID_THUMPERD_MKD, "ThumperD_MKD" },
		{ CONST_WEAPON_ID_SPINFUSOR_100X, "Spinfusor_100X" },
		{ CONST_WEAPON_ID_ARX_BUSTER, "ArxBuster" },
		{ CONST_WEAPON_ID_LAUNCHER_GRENADE, "GrenadeLauncher" },
		{ CONST_WEAPON_ID_PLASMA_GUN, "PlasmaGun" },
		{ CONST_WEAPON_ID_ARX_BUSTER_MKD, "ArxBuster_MKD" },
		{ CONST_WEAPON_ID_SMG_NJ4, "NJ4SMG" },
		{ CONST_WEAPON_ID_NJ5SMG, "NJ5SMG" },
		{ CONST_WEAPON_ID_SMG_NJ4_MKD, "NJ4SMG_MKD" },
		{ CONST_WEAPON_ID_SMG_TCN4, "TCN4SMG" },
		{ CONST_WEAPON_ID_THUMPER, "Thumper" },
		{ CONST_WEAPON_ID_SMG_TCN4_MKD, "TCN4SMG_MKD" },
		{ CONST_WEAPON_ID_TC24, "TC24" },
		{ CONST_WEAPON_ID_REPAIR_TOOL_SD, "RepairToolSD" },
		{ CONST_WEAPON_ID_SHOTGUN_SAWED_OFF, "SawedOffShotgun" },
		{ CONST_WEAPON_ID_PISTOL_SPARROW, "Sparrow" },
		{ CONST_WEAPON_ID_REPAIR_TOOL_SD_MKD, "RepairToolSD_MKD" },
		{ CONST_WEAPON_ID_LAUNCHER_MORTAR, "MortarLauncher" },
		{ CONST_WEAPON_ID_LAUNCHER_MIRV, "MIRVLauncher" },
		{ CONST_WEAPON_ID_LAUNCHER_MORTAR_MKD, "MortarLauncher_MKD" },
		{ CONST_WEAPON_ID_SPINFUSOR_D, "SpinfusorD" },
		{ CONST_WEAPON_ID_RIFLE_ASSAULT_X1, "X1Rifle" },
		{ CONST_WEAPON_ID_SPINFUSOR_D_MKD, "SpinfusorD_MKD" },
		{ CONST_WEAPON_ID_HEAVYTWINFUSOR, "HeavyTwinfusor" },
		{ CONST_WEAPON_ID_CHAINGUN, "ChainGun" },
		{ CONST_WEAPON_ID_LAUNCHER_BOLT_HEAVY, "HeavyBoltLauncher" },
		{ CONST_WEAPON_ID_CHAINGUN_MKD, "ChainGun_MKD" },
		{ CONST_WEAPON_ID_LAUNCHER_SABER, "SaberLauncher" },
		{ CONST_WEAPON_ID_LAUNCHER_SABER_MKD, "SaberLauncher_MKD" },
		{ CONST_WEAPON_ID_SPINFUSOR_HEAVY, "HeavySpinfusor" },
		{ CONST_WEAPON_ID_SPIKELAUNCHER, "SpikeLauncher" },
		{ CONST_WEAPON_ID_SPINFUSOR_HEAVY_MKD, "HeavySpinfusor_MKD" },
		{ CONST_WEAPON_ID_SHOTGUN_AUTO, "AutoShotgun" },
		{ CONST_WEAPON_ID_PLASMA_CANNON, "PlasmaCannon" },
		{ CONST_WEAPON_ID_PISTOL_NOVA_SLUG, "NovaSlug" },
		{ CONST_WEAPON_ID_SHOTGUN_AUTO_MKD, "AutoShotgun_MKD" },
		{ CONST_WEAPON_ID_ELFPROJECTOR, "ElfProjector" },
		{ CONST_WEAPON_ID_ELFFLAK, "ElfFlak" },
		{ CONST_WEAPON_ID_PILOT_GRAVCYCLE, "GravCyclePilot" },
		{ CONST_WEAPON_ID_PILOT_SHRIKE, "ShrikePilot" },
		{ CONST_WEAPON_ID_PILOT_BEOWULF, "BeowulfPilot" },
		{ CONST_WEAPON_ID_GUNNER_BEOWULF, "BeowulfGunner" }
	};

	std::map<int, std::string> weapon_id_to_proj_name = {
		{ CONST_WEAPON_ID_SPINFUSOR_LIGHT, "LightSpinfusor" },
		{ CONST_WEAPON_ID_LAUNCHER_BOLT, "BoltLauncher" },
		{ CONST_WEAPON_ID_SPINFUSOR_LIGHT_MKD, "LightSpinfusor_MKD" },
		{ CONST_WEAPON_ID_LIGHTTWINFUSOR, "LightTwinfusor" },
		{ CONST_WEAPON_ID_SPINFUSOR_LIGHT_100X, "LightSpinfusor_100X" },
		{ CONST_WEAPON_ID_SHOTGUN, "" },
		{ CONST_WEAPON_ID_RIFLE_ASSAULT_LIGHT, "LightAssaultRifle" },
		{ CONST_WEAPON_ID_SHOTGUN_MKD, "" },
		{ CONST_WEAPON_ID_RIFLE_SNIPER, "" },
		{ CONST_WEAPON_ID_RIFLE_PHASE, "" },
		{ CONST_WEAPON_ID_RIFLE_SNIPER_MKD, "" },
		{ CONST_WEAPON_ID_SAP20, "" },
		{ CONST_WEAPON_ID_PISTOL_NOVA_COLT, "NovaColt" },
		{ CONST_WEAPON_ID_PISTOL_FALCON, "Falcon" },
		{ CONST_WEAPON_ID_PISTOL_NOVA_COLT_MKD, "NovaColt_MKD" },
		{ CONST_WEAPON_ID_ACCURIZEDSHOTGUN, "" },
		{ CONST_WEAPON_ID_SMG_RHINO, "RhinoSMG" },
		{ CONST_WEAPON_ID_STEALTHLIGHTSPINFUSOR, "StealthSpinfusor" },
		{ CONST_WEAPON_ID_REMOTE_ARX_BUSTER, "RemoteArxBuster" },
		{ CONST_WEAPON_ID_SMG_RHINO_MKD, "RhinoSMG_MKD" },
		{ CONST_WEAPON_ID_PISTOL_SN7, "SN7" },
		{ CONST_WEAPON_ID_THROWINGKNIVES, "ThrowingKnives" },
		{ CONST_WEAPON_ID_PISTOL_SN7_MKD, "SN7_MKD" },
		{ CONST_WEAPON_ID_RIFLE_ASSAULT, "AssaultRifle" },
		{ CONST_WEAPON_ID_SPINFUSOR, "Spinfusor" },
		{ CONST_WEAPON_ID_RIFLE_ASSAULT_MKD, "AssaultRifle_MKD" },
		{ CONST_WEAPON_ID_TWINFUSOR, "Twinfusor" },
		{ CONST_WEAPON_ID_THUMPER_D, "ThumperD" },
		{ CONST_WEAPON_ID_PISTOL_EAGLE, "Eagle" },
		{ CONST_WEAPON_ID_THUMPERD_MKD, "ThumperD_MKD" },
		{ CONST_WEAPON_ID_SPINFUSOR_100X, "Spinfusor_100X" },
		{ CONST_WEAPON_ID_ARX_BUSTER, "ArxBuster" },
		{ CONST_WEAPON_ID_LAUNCHER_GRENADE, "GrenadeLauncher" },
		{ CONST_WEAPON_ID_PLASMA_GUN, "PlasmaGun" },
		{ CONST_WEAPON_ID_ARX_BUSTER_MKD, "ArxBuster_MKD" },
		{ CONST_WEAPON_ID_SMG_NJ4, "NJ4SMG" },
		{ CONST_WEAPON_ID_NJ5SMG, "NJ5SMG" },
		{ CONST_WEAPON_ID_SMG_NJ4_MKD, "NJ4SMG_MKD" },
		{ CONST_WEAPON_ID_SMG_TCN4, "TCN4SMG" },
		{ CONST_WEAPON_ID_THUMPER, "Thumper" },
		{ CONST_WEAPON_ID_SMG_TCN4_MKD, "TCN4SMG_MKD" },
		{ CONST_WEAPON_ID_TC24, "TC24" },
		{ CONST_WEAPON_ID_REPAIR_TOOL_SD, "" },
		{ CONST_WEAPON_ID_SHOTGUN_SAWED_OFF, "SawedOffShotgun" },
		{ CONST_WEAPON_ID_PISTOL_SPARROW, "" },
		{ CONST_WEAPON_ID_REPAIR_TOOL_SD_MKD, "" },
		{ CONST_WEAPON_ID_LAUNCHER_MORTAR, "MortarLauncher" },
		{ CONST_WEAPON_ID_LAUNCHER_MIRV, "MIRVLauncher" },
		{ CONST_WEAPON_ID_LAUNCHER_MORTAR_MKD, "MortarLauncher_MKD" },
		{ CONST_WEAPON_ID_SPINFUSOR_D, "SpinfusorD" },
		{ CONST_WEAPON_ID_RIFLE_ASSAULT_X1, "X1Rifle" },
		{ CONST_WEAPON_ID_SPINFUSOR_D_MKD, "SpinfusorD_MKD" },
		{ CONST_WEAPON_ID_HEAVYTWINFUSOR, "HeavyTwinfusor" },
		{ CONST_WEAPON_ID_CHAINGUN, "Chaingun" },
		{ CONST_WEAPON_ID_LAUNCHER_BOLT_HEAVY, "HeavyBoltLauncher" },
		{ CONST_WEAPON_ID_CHAINGUN_MKD, "Chaingun_MKD" },
		{ CONST_WEAPON_ID_LAUNCHER_SABER, "TrackingMissile" },
		{ CONST_WEAPON_ID_LAUNCHER_SABER_MKD, "TrackingMissile_MKD" },
		{ CONST_WEAPON_ID_SPINFUSOR_HEAVY, "HeavySpinfusor" },
		{ CONST_WEAPON_ID_SPIKELAUNCHER, "SpikeLauncher" },
		{ CONST_WEAPON_ID_SPINFUSOR_HEAVY_MKD, "HeavySpinfusor_MKD" },
		{ CONST_WEAPON_ID_SHOTGUN_AUTO, "" },
		{ CONST_WEAPON_ID_PLASMA_CANNON, "" },
		{ CONST_WEAPON_ID_PISTOL_NOVA_SLUG, "" },
		{ CONST_WEAPON_ID_SHOTGUN_AUTO_MKD, "" },
		{ CONST_WEAPON_ID_ELFPROJECTOR, "" },
		{ CONST_WEAPON_ID_ELFFLAK, "ElfFlak" },
		{ CONST_WEAPON_ID_PILOT_GRAVCYCLE, "GravCyclePilot" },
		{ CONST_WEAPON_ID_PILOT_SHRIKE, "ShrikePilot" },
		{ CONST_WEAPON_ID_PILOT_BEOWULF, "BeowulfPilot" },
		{ CONST_WEAPON_ID_GUNNER_BEOWULF, "BeowulfGunner" }
	};

	std::map<std::string, int> vehicle_weapons =
	{
		{ R"rx(^(grav(cycle|bike)?)$)rx", CONST_WEAPON_ID_PILOT_GRAVCYCLE },
		{ R"rx(^(shrike)$)rx", CONST_WEAPON_ID_PILOT_SHRIKE },
		{ R"rx(^(tank|beowulf(cann?on|pilot)?)$)rx", CONST_WEAPON_ID_PILOT_BEOWULF },
		{ R"rx(^((tank|beowulf)(gunner|chaingun|chain|gun))$)rx", CONST_WEAPON_ID_GUNNER_BEOWULF }
	};

	std::map<std::string, int> classes =
	{
		{ R"rx(^(light|lht)$)rx", 1 },
		{ R"rx(^(medium|med)$)rx", 2 },
		{ R"rx(^(heavy|hvy)$)rx", 3 }
	};

	std::map<std::string, int> crosshairs =
	{
		{ R"rx(^(spin(fusor)?)$)rx", CONST_THR_SPINFUSOR },
		{ R"rx(^(smg)$)rx", CONST_THR_SMG },
		{ R"rx(^(rifle)$)rx", CONST_THR_RIFLE },
		{ R"rx(^(locked_?on)$)rx", CONST_THR_LOCKED_ON },
		{ R"rx(^(crossbow)$)rx", CONST_THR_CROSSBOW },
		{ R"rx(^(flamethrower)$)rx", CONST_THR_FLAME_THROWER },
		{ R"rx(^(chaingun)$)rx", CONST_THR_CHAIN_GUN },
		{ R"rx(^(bolt(launcher)?|thumper|missile)$)rx", CONST_THR_MISSILE },
		{ R"rx(^(nanite)$)rx", CONST_THR_NANITE },
		{ R"rx(^(shotgun)$)rx", CONST_THR_SHOTGUN },
		{ R"rx(^(unknown)$)rx", CONST_THR_UNKNOWN },
		{ R"rx(^(laser)$)rx", CONST_THR_LASER },
		{ R"rx(^(ch_?v13)$)rx", CONST_THR_CH_V13 },
		{ R"rx(^(scope)$)rx", CONST_THR_SCOPE },
		{ R"rx(^(standard|(nova)?(colt|blaster)?)$)rx", CONST_THR_STANDARD },
		{ R"rx(^(grenadelauncher|mortar)$)rx", CONST_THR_GRENADE_LAUNCHER },
		{ R"rx(^(melee)$)rx", CONST_THR_MELEE },
		{ R"rx(^(shrike)$)rx", CONST_THR_SHRIKE },
		{ R"rx(^(spectator)$)rx", CONST_THR_FREE_SPECTATOR },
		{ R"rx(^(chain|dot|assaultrifle|ar|red_?dot)$)rx", CONST_THR_RED_DOT },
		{ R"rx(^(bxt1?)$)rx", CONST_THR_BXT1 },
		{ R"rx(^(phase(rifle)?)$)rx", CONST_THR_PHASERIFLE },
		{ R"rx(^(sap(20)?)$)rx", CONST_THR_SAP20 },
		{ R"rx(^(plasma(gun)?)$)rx", CONST_THR_PLASMAGUN }
	};

	int classes_id[3] = {
		CONST_CLASS_TYPE_LIGHT,
		CONST_CLASS_TYPE_MEDIUM,
		CONST_CLASS_TYPE_HEAVY
	};

	std::map<int, int> class_id_to_nb =
	{
		{ CONST_CLASS_TYPE_LIGHT, 0 },
		{ CONST_CLASS_TYPE_MEDIUM, 1 },
		{ CONST_CLASS_TYPE_HEAVY, 2 }
	};

	std::string class_type_name[] =
	{
		"Light",
		"Medium",
		"Heavy"
	};

	std::string equip_type_name[] =
	{
		"Impact",
		"Timed",
		"Specialty",
		"Automatic",
		"Short Range",
		"Sidearm",
		"Belt",
		"Pack"
	};
}
