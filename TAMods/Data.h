#pragma once

#include <string>
#include <regex>
#include <map>
#include "SdkHeaders.h"

#define CONST_MAP_ID_CTF_KATABATIC              1447
#define CONST_MAP_ID_CTF_ARXNOVENA              1456
#define CONST_MAP_ID_CTF_DRYDOCK                1457
#define CONST_MAP_ID_RABBIT_OUTSKIRTS           1458
#define CONST_MAP_ID_RABBIT_QUICKSAND           1461
#define CONST_MAP_ID_CTF_CROSSFIRE              1462
#define CONST_MAP_ID_RABBIT_CROSSFIRE           1464
#define CONST_MAP_ID_TDM_DRYDOCKNIGHT           1480
#define CONST_MAP_ID_TDM_CROSSFIRE              1482
#define CONST_MAP_ID_TDM_QUICKSAND              1484
#define CONST_MAP_ID_TDM_NIGHTABATIC            1485
#define CONST_MAP_ID_TDM_INFERNO                1487
#define CONST_MAP_ID_TDM_SULFURCOVE             1488
#define CONST_MAP_ID_TDM_OUTSKIRTS              1490
#define CONST_MAP_ID_RABBIT_INFERNO             1491
#define CONST_MAP_ID_CTF_TEMPLERUINS            1493
#define CONST_MAP_ID_RABBIT_NIGHTABATIC         1494
#define CONST_MAP_ID_ARENA_AIRARENA             1495
#define CONST_MAP_ID_RABBIT_SULFURCOVE          1496
#define CONST_MAP_ID_ARENA_WALLEDIN             1497
#define CONST_MAP_ID_ARENA_LAVAARENA            1498
#define CONST_MAP_ID_CTF_TARTARUS               1512
#define CONST_MAP_ID_CTF_CANYONCRUSADEREVIVAL   1514
#define CONST_MAP_ID_CTF_RAINDANCE              1516
#define CONST_MAP_ID_CAH_KATABATIC              1521
#define CONST_MAP_ID_CTF_STONEHENGE             1522
#define CONST_MAP_ID_CTF_SUNSTAR                1523
#define CONST_MAP_ID_CAH_OUTSKIRTS3P            1526
#define CONST_MAP_ID_CAH_RAINDANCE              1528
#define CONST_MAP_ID_CAH_DRYDOCKNIGHT           1530
#define CONST_MAP_ID_ARENA_HINTERLANDS          1533
#define CONST_MAP_ID_CTF_PERMAFROST             1534
#define CONST_MAP_ID_CAH_SULFURCOVE             1535
#define CONST_MAP_ID_TDM_MIASMA                 1536
#define CONST_MAP_ID_CAH_TARTARUS               1537
#define CONST_MAP_ID_CTF_DANGEROUSCROSSING      1538
#define CONST_MAP_ID_BLITZ_CROSSFIRE            1542
#define CONST_MAP_ID_CTF_BLUESHIFT              1543
#define CONST_MAP_ID_ARENA_WHITEOUT             1544
#define CONST_MAP_ID_ARENA_FRAYTOWN             1545
#define CONST_MAP_ID_ARENA_UNDERCROFT           1546
#define CONST_MAP_ID_CAH_CANYONCRUSADEREVIVAL   1548
#define CONST_MAP_ID_BLITZ_CANYONCRUSADEREVIVAL 1549
#define CONST_MAP_ID_BLITZ_BELLAOMEGA           1550
#define CONST_MAP_ID_CTF_BELLAOMEGANS           1551
#define CONST_MAP_ID_BLITZ_BLUESHIFT            1552
#define CONST_MAP_ID_CTF_TERMINUS               1553
#define CONST_MAP_ID_CTF_ICECOASTER             1554
#define CONST_MAP_ID_CTF_PERDITION              1555
#define CONST_MAP_ID_CTF_HELLFIRE               1560
#define CONST_MAP_ID_BLITZ_HELLFIRE             1561
#define CONST_MAP_ID_CTF_BELLAOMEGA             1573
#define CONST_MAP_ID_BLITZ_ARXNOVENA            2566
#define CONST_MAP_ID_BLITZ_KATABATIC            2598
#define CONST_MAP_ID_BLITZ_DRYDOCK              2599

namespace Data
{
	extern std::map<std::string, int> weapons[3];
	extern std::map<int, std::string> weapon_id_to_name;
	extern std::map<int, std::string> weapon_id_to_proj_name;
	extern std::map<int, UClass*> weapon_id_to_weapon_class;
	extern std::map<std::string, int> vehicle_weapons;
	extern std::map<std::string, int> classes;
	extern std::map<std::string, int> crosshairs;
	extern int classes_id[3];
	extern std::map<int, int> class_id_to_nb;
	extern std::string class_type_name[];
	extern std::string equip_type_name[];
	extern std::map<std::string, int> map_id;
	extern std::map<int, std::string> map_id_to_name;
}
