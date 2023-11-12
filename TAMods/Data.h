#pragma once

#include <string>
#include <regex>
#include <map>
#include "Logger.h"
#include "Utils.h"
#include "SdkHeaders.h"

#define CONST_MAP_ID_CTF_KATABATIC              1447
#define CONST_MAP_ID_CTF_ARXNOVENA              1456
#define CONST_MAP_ID_CTF_DRYDOCK                1457
#define CONST_MAP_ID_RABBIT_OUTSKIRTS           1458
#define CONST_MAP_ID_RABBIT_QUICKSAND           1461
#define CONST_MAP_ID_CTF_CROSSFIRE              1462
#define CONST_MAP_ID_RABBIT_CROSSFIRE           1464
#define CONST_MAP_ID_CTF_BELLAOMEGA             1473
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
#define CONST_MAP_ID_CAH_DRYDOCKNIGHT           1525
#define CONST_MAP_ID_CAH_OUTSKIRTS3P            1526
#define CONST_MAP_ID_CAH_RAINDANCE              1528
#define CONST_MAP_ID_ARENA_HINTERLANDS          1533
#define CONST_MAP_ID_CTF_PERMAFROST             1534
#define CONST_MAP_ID_CAH_SULFURCOVE             1535
#define CONST_MAP_ID_TDM_MIASMA                 1536
#define CONST_MAP_ID_CAH_TARTARUS               1537
#define CONST_MAP_ID_CTF_DANGEROUSCROSSING      1538
#define CONST_MAP_ID_BLITZ_KATABATIC            1539
#define CONST_MAP_ID_BLITZ_ARXNOVENA            1540
#define CONST_MAP_ID_BLITZ_DRYDOCK              1541
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
#define CONST_MAP_ID_TDM_PERDITION              1557
#define CONST_MAP_ID_BLITZ_ICECOASTER           1558
#define CONST_MAP_ID_BLITZ_TERMINUS             1559
#define CONST_MAP_ID_CTF_HELLFIRE               1560
#define CONST_MAP_ID_BLITZ_HELLFIRE             1561
#define CONST_MAP_ID_CTF_ACHERON                1601
#define CONST_MAP_ID_CTF_BLUES                  1602
#define CONST_MAP_ID_CTF_DESERTEDVALLEY         1603
#define CONST_MAP_ID_CTF_FRACTURE               1604
#define CONST_MAP_ID_CTF_INCIDAMUS              1605
#define CONST_MAP_ID_CTF_PERICULO               1606
#define CONST_MAP_ID_CTF_PHLEGATHON             1607
#define CONST_MAP_ID_CTF_STYX                   1608
#define CONST_MAP_ID_CTF_OCEANUS                1609
#define CONST_MAP_ID_CTF_TREACHEROUSPASS        1610
#define CONST_MAP_ID_CTF_MERIDIAN               1611
#define CONST_MAP_ID_CTF_ASCENT                 1612
#define CONST_MAP_ID_CTF_ECLIPSE                1613
#define CONST_MAP_ID_CTF_POLARIS                1614
#define CONST_MAP_ID_CTF_CRASH                  1615
#define CONST_MAP_ID_CTF_ANDROMEDA              1616
#define CONST_MAP_ID_ARENA_RUINS                1641
#define CONST_MAP_ID_ARENA_ELYSIANBATTLEGROUND  1642
#define CONST_MAP_ID_BLITZ_BROADSIDE            1651
#define CONST_MAP_ID_BLITZ_AIRARENA             1652
#define CONST_MAP_ID_BLITZ_MAZERUNNER           1653

namespace Data
{
    int getItemId(const std::string& className, const std::string &itemName);
    UClass* getRankByXp(int rankXp);
    int getTotalXpByRank(int rankNum, int xp);    
    int getXpFromPlayerProfile(UTgPlayerProfile* profile);

    extern std::map<std::string, int> weapons[3];
    extern std::map<std::string, int> packs[3];
    extern std::map<std::string, int> skins[3];
    extern std::map<std::string, int> perks;
    extern std::map<std::string, int> voices;
    extern std::map<int, std::string> item_id_to_name;
    extern std::map<int, std::string> perk_id_to_name;
    extern std::vector<int> perks_by_slot[2];
    extern std::map<int, std::string> voice_id_to_name;
    extern std::map<int, std::string> weapon_id_to_proj_name;
    extern std::map<int, UClass*> weapon_id_to_weapon_class;
    extern std::map<std::string, int> vehicle_weapons;
    extern std::map<int, UClass*> vehicle_weapon_id_to_class;
    extern std::map<int, std::string> vehicle_weapon_id_to_name;
    extern std::map<std::string, int> vehicles;
    extern std::map<int, std::string> vehicle_id_to_name;
    extern std::map<int, UClass*> vehicle_id_to_class;
    extern std::map<std::string, int> classes;
    extern std::map<std::string, int> armor_class_to_id;
    extern std::map<int, std::string> armor_class_id_to_name;
    extern std::map<int, int> armor_class_to_ootb_class;
    extern std::map<int, std::string> armor_class_id_to_armor_mod_name;
    extern std::map<std::string, int> value_mod_types;
    extern std::map<std::string, int> crosshairs;
    extern int classes_id[3];
    extern std::map<int, UClass*> class_id_to_class;
    extern std::map<int, std::string> class_id_to_name;
    extern std::map<int, int> class_id_to_nb;
    extern std::string class_type_name[];
    extern std::string equip_type_name[];
    extern std::map<std::string, int> map_id;
    extern std::map<int, std::string> map_id_to_name;
    extern std::map<int, std::string> map_id_to_filename;
}
