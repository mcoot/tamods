#include "Data.h"

namespace Data
{
	std::map<std::string, int> equipment[9][4] =
	{
		// PATHFINDER
		{
			// PRIMARY
			{
				{ R"rx(^(spin(fusor)?|light(spin)?(fusor)?)$)rx", CONST_WEAPON_ID_SPINFUSOR_LIGHT },
				{ R"rx(^(bolt|boltlauncher)$)rx", CONST_WEAPON_ID_LAUNCHER_BOLT },
				{ R"rx(^(duel|dueling|duelingspinfusor)$)rx", CONST_WEAPON_ID_SPINFUSOR_LIGHT_MKD },
				{ R"rx(^(twin|twinfusor|lighttwinfusor)$)rx", CONST_WEAPON_ID_LIGHTTWINFUSOR },
				{ R"rx(^(blinks|blinksfusor)$)rx", CONST_WEAPON_ID_SPINFUSOR_LIGHT_100X },
			},
			// SECONDARY
			{
				{ R"rx(^(shotgun)$)rx", CONST_WEAPON_ID_SHOTGUN },
				{ R"rx(^(lightassaultrifle|lar|ar|assaultrifle|rifle)$)rx", CONST_WEAPON_ID_RIFLE_ASSAULT_LIGHT },
				{ R"rx(^(holdoutshotgun|holdout)$)rx", CONST_WEAPON_ID_SHOTGUN_MKD },
				{ R"rx(^(shocklance)$)rx", CONST_WEAPON_ID_PISTOL_H1 },
			},
			// BELT
			{
				{ R"rx(^(nitrons?|impactnitrons?|impacts?)$)rx", CONST_WEAPON_ID_GRENADE_NITRON },
				{ R"rx(^(explosivenitrons?|explosives?)$)rx", CONST_WEAPON_ID_GRENADE_ST },
				{ R"rx(^(compactnitrons?|compacts?)$)rx", CONST_WEAPON_ID_GRENADE_NITRON_MKD },
			},
			// PACK
			{
				{ R"rx(^(energyrecharge|energy)$)rx", CONST_ITEM_PACK_RECHARGE_PATHFINDER },
				{ R"rx(^(thrustpack|thrust)$)rx", CONST_ITEM_PACK_BLINK },
			}
		},
		// SENTINEL
		{
			// PRIMARY
			{
				{ R"rx(^(bxt|bxt1|bxt1rifle)$)rx", CONST_WEAPON_ID_RIFLE_SNIPER },
				{ R"rx(^(phase|phaserifle)$)rx", CONST_WEAPON_ID_RIFLE_PHASE },
				{ R"rx(^(bxt1a|bxt1-a|bxt1-arifle|bxt1arifle)$)rx", CONST_WEAPON_ID_RIFLE_SNIPER_MKD },
				{ R"rx(^(sap20(sniper)?(rifle)?)$)rx", CONST_WEAPON_ID_SAP20 },
			},
			// SECONDARY
			{
				{ R"rx(^(nova|blaster|novablaster)$)rx", CONST_WEAPON_ID_PISTOL_NOVA_COLT },
				{ R"rx(^(falcon)$)rx", CONST_WEAPON_ID_PISTOL_FALCON },
				{ R"rx(^(mx|novablastermx|novamx|blastermx)$)rx", CONST_WEAPON_ID_PISTOL_NOVA_COLT_MKD },
				{ R"rx(^(shotgun|accurizedshotgun)$)rx", CONST_WEAPON_ID_ACCURIZEDSHOTGUN },
				{ R"rx(^(shocklance)$)rx", CONST_WEAPON_ID_PISTOL_H1 },
			},
			// BELT
			{
				{ R"rx(^(claymores?|claymoremines?)$)rx", CONST_WEAPON_ID_MINE_CLAYMORE },
				{ R"rx(^(t5s?|grenades?|t5grenades?)$)rx", CONST_WEAPON_ID_GRENADE_T5 },
				{ R"rx(^(focusedclaymores?|focusedclaymoremines?)$)rx", CONST_WEAPON_ID_MINE_CLAYMORE_MKD },
				{ R"rx(^(motionmines?|motions?|mines?)$)rx", CONST_WEAPON_ID_MINE_ARMOREDCLAYMORE },
			},
			// PACK
			{
				{ R"rx(^(dropjammer|jammer|jammerpack)$)rx", CONST_WEAPON_ID_DROPJAMMER },
				{ R"rx(^(energypack|energyrecharge|energy)$)rx", CONST_ITEM_PACK_RECHARGE_SENTINEL },
			}
		},
		// INFILTRATOR
		{
			// PRIMARY
			{
				{ R"rx(^(rhinosmg|smg|rhino)$)rx", CONST_WEAPON_ID_SMG_RHINO },
				{ R"rx(^(stealthspin(fusor)?|spin(fusor)?|stealth)$)rx", CONST_WEAPON_ID_STEALTHLIGHTSPINFUSOR },
				{ R"rx(^(jackal)$)rx", CONST_WEAPON_ID_REMOTE_ARX_BUSTER },
				{ R"rx(^(arcticrhinosmg|arcticrhino|arcticsmg)$)rx", CONST_WEAPON_ID_SMG_RHINO_MKD },
			},
			// SECONDARY
			{
				{ R"rx(^(sn7silencedpistol|sn7|pistol)$)rx", CONST_WEAPON_ID_PISTOL_SN7 },
				{ R"rx(^(throwingknives|knives)$)rx", CONST_WEAPON_ID_THROWINGKNIVES },
				{ R"rx(^(arcticsn7silencedpistol|arcticsn7|arcticpistol)$)rx", CONST_WEAPON_ID_PISTOL_SN7_MKD },
				{ R"rx(^(shocklance)$)rx", CONST_WEAPON_ID_PISTOL_H1 },
			},
			// BELT
			{
				{ R"rx(^(stickygrenades?|sticky|stickies)$)rx", CONST_WEAPON_ID_GRENADE_STICKY },
				{ R"rx(^(prismmines?|mines?)$)rx", CONST_WEAPON_ID_MINE_PRISM },
				{ R"rx(^(smokegrenades?|smokes?)$)rx", CONST_WEAPON_ID_GRENADE_NINJASMOKE },
				{ R"rx(^(stickygrenades?xl|stickyxls?|stickiesxl)$)rx", CONST_WEAPON_ID_GRENADE_STICKY_MKD },
			},
			// PACK
			{
				{ R"rx(^(stealthpack|stealth)$)rx", CONST_ITEM_PACK_STEALTH },
			}
		},
		// SOLDIER
		{
			// PRIMARY
			{
				{ R"rx(^(assaultrifle|rifle|ar)$)rx", CONST_WEAPON_ID_RIFLE_ASSAULT },
				{ R"rx(^(spinfusor|spin)$)rx", CONST_WEAPON_ID_SPINFUSOR },
				{ R"rx(^(gast'srifle|gast|gastrifle)$)rx", CONST_WEAPON_ID_RIFLE_ASSAULT_MKD },
				{ R"rx(^(twinfusor)$)rx", CONST_WEAPON_ID_TWINFUSOR },
			},
			// SECONDARY
			{
				{ R"rx(^(thumper|thumperd)$)rx", CONST_WEAPON_ID_THUMPER_D },
				{ R"rx(^(eaglepistol|eagle|pistol)$)rx", CONST_WEAPON_ID_PISTOL_EAGLE },
				{ R"rx(^(thumperdx)$)rx", CONST_WEAPON_ID_THUMPERD_MKD },
				{ R"rx(^(sparespinfusor|sparespin|spin|spinfusor)$)rx", CONST_WEAPON_ID_SPINFUSOR_100X },
				{ R"rx(^(shocklance)$)rx", CONST_WEAPON_ID_PISTOL_H1 },
			},
			// BELT
			{
				{ R"rx(^(fraggrenades?(xl)?|frag(xl)?|grenades?(xl)?)$)rx", CONST_WEAPON_ID_GRENADE_XL },
				{ R"rx(^(anti-?personnelgrenades?|aps?|apgrenades?)$)rx", CONST_WEAPON_ID_GRENADE_AP },
				{ R"rx(^(proxmitys?(grenades?)?|proxies|proxys?)$)rx", CONST_WEAPON_ID_PROXIMITY_GRENADE },
				{ R"rx(^(short-?fusefraggrenades?|short-?fuses?)$)rx", CONST_WEAPON_ID_GRENADE_XL_MKD },
			},
			// PACK
			{
				{ R"rx(^(energypack|energy)$)rx", CONST_ITEM_PACK_ENERGY_SOLDIER },
				{ R"rx(^(utilitypack|utility)$)rx", CONST_ITEM_PACK_UTILITY_SOLDIER },
			}
		},
		// RAIDER
		{
			// PRIMARY
			{
				{ R"rx(^(arxbuster|arx)$)rx", CONST_WEAPON_ID_ARX_BUSTER },
				{ R"rx(^(grenadelauncher|nadelauncher|launcher)$)rx", CONST_WEAPON_ID_LAUNCHER_GRENADE },
				{ R"rx(^(plasmagun|plasma)$)rx", CONST_WEAPON_ID_PLASMA_GUN },
				{ R"rx(^(dustdevil|dust|devil)$)rx", CONST_WEAPON_ID_ARX_BUSTER_MKD },
			},
			// SECONDARY
			{
				{ R"rx(^(nj4smg|nj4)$)rx", CONST_WEAPON_ID_SMG_NJ4 },
				{ R"rx(^(nj5-?bsmg|nj5)$)rx", CONST_WEAPON_ID_NJ5SMG },
				{ R"rx(^(desertnj4smg|desertnj4|desert)$)rx", CONST_WEAPON_ID_SMG_NJ4_MKD },
				{ R"rx(^(shocklance)$)rx", CONST_WEAPON_ID_PISTOL_H1 },
			},
			// BELT
			{
				{ R"rx(^(blackouts?|blackoutgrenades?)$)rx", CONST_WEAPON_ID_GRENADE_WHITEOUT },
				{ R"rx(^(emps?|empgrenades?)$)rx", CONST_WEAPON_ID_GRENADE_EMP },
				{ R"rx(^(clustergrenades?|clusters?)$)rx", CONST_WEAPON_ID_MIRV_GRENADE },
				{ R"rx(^(emps?xls?|empgrenades?xls?)$)rx", CONST_WEAPON_ID_GRENADE_EMP_MKD },
			},
			// PACK
			{
				{ R"rx(^(shieldpack|shield)$)rx", CONST_ITEM_PACK_SHIELD },
				{ R"rx(^(jammerpack|jammer)$)rx", CONST_ITEM_PACK_JAMMER },
			}
		},
		// TECHNICIAN
		{
			// PRIMARY
			{
				{ R"rx(^(tcn4smg|tcn4)$)rx", CONST_WEAPON_ID_SMG_TCN4 },
				{ R"rx(^(thumper)$)rx", CONST_WEAPON_ID_THUMPER },
				{ R"rx(^(tcn4rockwindsmg|rockwind|rockwindsmg|tcn4rockwind)$)rx", CONST_WEAPON_ID_SMG_TCN4_MKD },
				{ R"rx(^(tc24)$)rx", CONST_WEAPON_ID_TC24 },
			},
			// SECONDARY
			{
				{ R"rx(^(improvedrepairtool|repairtool|repair)$)rx", CONST_WEAPON_ID_REPAIR_TOOL_SD },
				{ R"rx(^(sawed-?offshotgun|shotgun|sawed-?off)$)rx", CONST_WEAPON_ID_SHOTGUN_SAWED_OFF },
				{ R"rx(^(sparrow)$)rx", CONST_WEAPON_ID_PISTOL_SPARROW },
				{ R"rx(^(longrangerepairtool|longrange(repair|tool)?)$)rx", CONST_WEAPON_ID_REPAIR_TOOL_SD_MKD },
				{ R"rx(^(shocklance)$)rx", CONST_WEAPON_ID_PISTOL_H1 },
			},
			// BELT
			{
				{ R"rx(^(tcngs?|grenades?)$)rx", CONST_WEAPON_ID_TCNG },
				{ R"rx(^(motionsensors?|sensors?)$)rx", CONST_WEAPON_ID_MOTIONALARM },
				{ R"rx(^(tcngs?quickfuses?|quickfuses?)$)rx", CONST_WEAPON_ID_TCNG_MKD },
				{ R"rx(^(repairkits?|repair|kits?)$)rx", CONST_WEAPON_ID_REPAIR_DEPLOYABLE },
			},
			// PACK
			{
				{ R"rx(^(turrets?|lightturrets?)$)rx", CONST_WEAPON_ID_TURRET_LIGHT },
				{ R"rx(^(exrs?|exrturrets?)$)rx", CONST_WEAPON_ID_TURRET_EXR },
			}
		},
		// JUGGERNAUT
		{
			// PRIMARY
			{
				{ R"rx(^(fusionmortar|mortar)$)rx", CONST_WEAPON_ID_LAUNCHER_MORTAR },
				{ R"rx(^(mirvlauncher|mirv)$)rx", CONST_WEAPON_ID_LAUNCHER_MIRV },
				{ R"rx(^((fusion)?(mortar)?deluxe)$)rx", CONST_WEAPON_ID_LAUNCHER_MORTAR_MKD },
			},
			// SECONDARY
			{
				{ R"rx(^(spin(fusor)?|spin(fusor)?mkd|(fusor)?mkd)$)rx", CONST_WEAPON_ID_SPINFUSOR_D },
				{ R"rx(^(x1|lmg|x1lmg)$)rx", CONST_WEAPON_ID_RIFLE_ASSAULT_X1 },
				{ R"rx(^((spin)?(fusor)?mk-?x)$)rx", CONST_WEAPON_ID_SPINFUSOR_D_MKD },
				{ R"rx(^(heavytwinfusor|twinfusor|twin)$)rx", CONST_WEAPON_ID_HEAVYTWINFUSOR },
				{ R"rx(^(shocklance)$)rx", CONST_WEAPON_ID_PISTOL_H1 },
			},
			// BELT
			{
				{ R"rx(^(heavyaps?grenades?|grenades?|heavyaps?|aps?)$)rx", CONST_WEAPON_ID_GRENADE_AP_HEAVY },
				{ R"rx(^(spinfusordisks?|spins?|disks?|spindisks?)$)rx", CONST_WEAPON_ID_SPINFUSOR_TOSS },
				{ R"rx(^(xls?|heavy(aps?)?(grenades?)?xl|aps?xl|heavyxls?)$)rx", CONST_WEAPON_ID_GRENADE_AP_HEAVY_MKD },
			},
			// PACK
			{
				{ R"rx(^(healthregenpack|healthpack|health|regenpack|regen)$)rx", CONST_ITEM_PACK_REGEN },
			}
		},
		// DOOMBRINGER
		{
			// PRIMARY
			{
				{ R"rx(^(chaingun)$)rx", CONST_WEAPON_ID_CHAINGUN },
				{ R"rx(^(heavyboltlauncher|boltlauncher|bolt)$)rx", CONST_WEAPON_ID_LAUNCHER_BOLT_HEAVY },
				{ R"rx(^(chaincannon)$)rx", CONST_WEAPON_ID_CHAINGUN_MKD },
			},
			// SECONDARY
			{
				{ R"rx(^(saberlauncher|saber)$)rx", CONST_WEAPON_ID_LAUNCHER_SABER },
				{ R"rx(^(titanlauncher|titan)$)rx", CONST_WEAPON_ID_LAUNCHER_SABER_MKD },
				{ R"rx(^(shocklance)$)rx", CONST_WEAPON_ID_PISTOL_H1 },
			},
			// BELT
			{
				{ R"rx(^(fraggrenades?|frags?)$)rx", CONST_WEAPON_ID_GRENADE },
				{ R"rx(^(mines?)$)rx", CONST_WEAPON_ID_MINE },
				{ R"rx(^(defectivefraggrenades?|defectivefrags?|defectivegrenades?)$)rx", CONST_WEAPON_ID_GRENADE_MKD },
			},
			// PACK
			{
				{ R"rx(^(forcefield|shield|energyfield)$)rx", CONST_WEAPON_ID_FORCEFIELD },
			}
		},
		// BRUTE
		{
			// PRIMARY
			{
				{ R"rx(^(heavy(spin)?(fusor)?|spin(fusor)?|fusor)$)rx", CONST_WEAPON_ID_SPINFUSOR_HEAVY },
				{ R"rx(^(gladiator)$)rx", CONST_WEAPON_ID_SPIKELAUNCHER },
				{ R"rx(^(devastator|devastatorspin(fusor)?|dev|devspin)$)rx", CONST_WEAPON_ID_SPINFUSOR_HEAVY_MKD },
			},
			// SECONDARY
			{
				{ R"rx(^(automaticshotgun|shotgun)$)rx", CONST_WEAPON_ID_SHOTGUN_AUTO },
				{ R"rx(^(plasmacannon|plasma)$)rx", CONST_WEAPON_ID_PLASMA_CANNON },
				{ R"rx(^(novacolt|colt|nova)$)rx", CONST_WEAPON_ID_PISTOL_NOVA_SLUG },
				{ R"rx(^(thehammer|hammer)$)rx", CONST_WEAPON_ID_SHOTGUN_AUTO_MKD },
				{ R"rx(^(shocklance)$)rx", CONST_WEAPON_ID_PISTOL_H1 },
			},
			// BELT
			{
				{ R"rx(^(heavystickygrenades?|stickys?|stickies|heavystickys?|heavystickies)$)rx", CONST_WEAPON_ID_GRENADE_STICKY_LIGHT },
				{ R"rx(^(fractals?|fractalgrenades?)$)rx", CONST_WEAPON_ID_GRENADE_SPIKE },
				{ R"rx(^(extendedfractalgrenades?|extendedfractals?)$)rx", CONST_WEAPON_ID_GRENADE_SPIKE_MKD },
			},
			// PACK
			{
				{ R"rx(^(energypack|energy)$)rx", CONST_ITEM_PACK_ENERGY_BRUTE },
				{ R"rx(^(survivalpack|survival)$)rx", CONST_ITEM_PACK_SURVIVAL },
				{ R"rx(^(heavyshieldpack|heavyshield|shieldpack|shield)$)rx", CONST_ITEM_PACK_HEAVYSHIELD },
			}
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
		{ CONST_WEAPON_ID_PILOT_GRAVCYCLE, "GravCyclePilot" },
		{ CONST_WEAPON_ID_PILOT_SHRIKE, "ShrikePilot" },
		{ CONST_WEAPON_ID_PILOT_BEOWULF, "BeowulfPilot" },
		{ CONST_WEAPON_ID_GUNNER_BEOWULF, "BeowulfGunner" }
	};

	std::map<std::string, int> perks[2] =
	{
		// PERK 1
		{
			{ R"rx(^(rage)$)rx", CONST_ITEM_PERK_RAGE },
			{ R"rx(^(ultracapacitor[i1]?|capacitor)$)rx", CONST_ITEM_PERK_SUPERCAPACITOR },
			{ R"rx(^(reach)$)rx", CONST_ITEM_PERK_REACH },
			{ R"rx(^(safefall|fall|sf)$)rx", CONST_ITEM_PERK_SAFEFALL },
			{ R"rx(^(wheeldeal)$)rx", CONST_ITEM_PERK_WHEELDEAL },
			{ R"rx(^(bountyhunter|bounty|hunter)$)rx", CONST_ITEM_PERK_BOUNTYHUNTER },
			{ R"rx(^(closecombat|cc)$)rx", CONST_ITEM_PERK_CLOSECOMBAT },
			{ R"rx(^(looter)$)rx", CONST_ITEM_PERK_LOOTER },
			{ R"rx(^(stealthy)$)rx", CONST_ITEM_PERK_STEALTHY },
			{ R"rx(^(safetythird|safety3rd|3rd|third)$)rx", CONST_ITEM_PERK_SAFETYTHIRD }
		},
		// PERK 2
		{
			{ R"rx(^(sonicpunch|sonic|punch)$)rx", CONST_ITEM_PERK_SONICPUNCH },
			{ R"rx(^(determination)$)rx", CONST_ITEM_PERK_DETERMINATION },
			{ R"rx(^(egocentric|ego)$)rx", CONST_ITEM_PERK_EGOCENTRIC },
			{ R"rx(^(potentialenergy|pe)$)rx", CONST_ITEM_PERK_POTENTIALENERGY },
			{ R"rx(^(pilot)$)rx", CONST_ITEM_PERK_PILOT },
			{ R"rx(^(survivalist)$)rx", CONST_ITEM_PERK_SURVIVALIST },
			{ R"rx(^(superheavy|heavy|sh)$)rx", CONST_ITEM_PERK_SUPERHEAVY },
			{ R"rx(^(ultracapacitor(2|ii)?|capacitor)$)rx", CONST_ITEM_PERK_ULTRACAPACITOR },
			{ R"rx(^(quickdraw|qd|draw)$)rx", CONST_ITEM_PERK_QUICKDRAW },
			{ R"rx(^(mechanic)$)rx", CONST_ITEM_PERK_MECHANIC },
			{ R"rx(^(lightweight)$)rx", CONST_ITEM_PERK_LIGHTWEIGHT }
		}
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
		{ R"rx(^(pathfinder|pth)$)rx", 1 },
		{ R"rx(^(sentinel|sen)$)rx", 2 },
		{ R"rx(^(infiltrator|inf)$)rx", 3 },
		{ R"rx(^(soldier|sld)$)rx", 4 },
		{ R"rx(^(raider|rdr)$)rx", 5 },
		{ R"rx(^(technician|tcn|tech)$)rx", 6 },
		{ R"rx(^(juggernaut|juggernaught|jug|jugg)$)rx", 7 },
		{ R"rx(^(doombringer|doom|dmb)$)rx", 8 },
		{ R"rx(^(brute|brt)$)rx", 9 },
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

	int classes_id[9] = {
		CONST_CLASS_TYPE_LIGHT_PATHFINDER,
		CONST_CLASS_TYPE_LIGHT_SENTINEL,
		CONST_CLASS_TYPE_LIGHT_INFILTRATOR,
		CONST_CLASS_TYPE_MEDIUM_SOLDIER,
		CONST_CLASS_TYPE_MEDIUM_RAIDER,
		CONST_CLASS_TYPE_MEDIUM_TECHNICIAN,
		CONST_CLASS_TYPE_HEAVY_JUGGERNAUGHT,
		CONST_CLASS_TYPE_HEAVY_DOOMBRINGER,
		CONST_CLASS_TYPE_HEAVY_BRUTE
	};

	std::map<int, int> class_id_to_nb =
	{
		{ CONST_CLASS_TYPE_LIGHT_PATHFINDER, 0 },
		{ CONST_CLASS_TYPE_LIGHT_SENTINEL, 1 },
		{ CONST_CLASS_TYPE_LIGHT_INFILTRATOR, 2 },
		{ CONST_CLASS_TYPE_MEDIUM_SOLDIER, 3 },
		{ CONST_CLASS_TYPE_MEDIUM_RAIDER, 4 },
		{ CONST_CLASS_TYPE_MEDIUM_TECHNICIAN, 5 },
		{ CONST_CLASS_TYPE_HEAVY_JUGGERNAUGHT, 6 },
		{ CONST_CLASS_TYPE_HEAVY_DOOMBRINGER, 7 },
		{ CONST_CLASS_TYPE_HEAVY_BRUTE, 8 }
	};

	std::string class_type_name[] =
	{
		"Pathfinder",
		"Sentinel",
		"Infiltrator",
		"Soldier",
		"Raider",
		"Technician",
		"Juggernaut",
		"Doombringer",
		"Brute"
	};

	std::string equip_type_name[] =
	{
		"Primary weapon",
		"Secondary weapon",
		"Belt item",
		"Pack",
		"Armor upgrade",
		"Perk 1",
		"Perk 2",
		"Skin",
		"Voice"
	};
}
