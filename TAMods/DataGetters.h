#pragma once

#include "SdkHeaders.h"

namespace getViewPortData
{
	FVector2D size();
	bool isMainMenuOpen();
}
namespace getPlayerData
{
	std::string name();
	bool isAlive();
	bool isRaged();
	bool isVehicle();
	bool isShielded();
	bool hasFlag();
	float energy();
	float energyMax();
	float energyPct();
	int ping();
	int classId();
	int health();
	int healthMax();
	int speed();
	int respawnTime();
	int numDeployables();
	int numMines();
	int score();
	int rabbitRank();
	int arenaSpawnsLeft();
	unsigned char teamNum();
}
namespace getWeaponData
{
	bool isReadyToFire(unsigned const char &n);
	bool isReloading(unsigned const char &n);
	bool isPack(unsigned const char &n);
	bool isPassiveReady(unsigned const char &n);
	bool isLowAmmo(unsigned const char &n);
	int ammo(unsigned const char &n);
	int ammoMax(unsigned const char &n);
	int ammoCarried(unsigned const char &n);
	int ammoMaxCarried(unsigned const char &n);
	int ammoTotal(unsigned const char &n);
	std::string name(unsigned const char &n);
}
namespace getCurrentWeaponData
{
	bool isReadyToFire();
	bool isReloading();
	bool isReloaded();
	bool isPack();
	bool isLowAmmo();
	int ammo();
	int ammoMax();
	int ammoCarried();
	int ammoMaxCarried();
	int ammoTotal();
	unsigned char equippedAt();
	std::string name();
}
namespace getVehicleData
{
	bool seatAvailable();
	int health();
	int healthMax();
	float energyPct();
	int ammo();
	int ammoMax();
	int speed();
}
namespace getGameData
{
	std::string type();
	std::string timeStr();
	bool isOfflinePlay();
	bool isGameEnd();
	bool isGenUp(unsigned const char &n);
	bool isWarmUp();
	bool isOverTime();
	int genAutoRepairTime(unsigned const char &n);
	int overTimeLimit();
	int score(unsigned const char &n);
	int scoreLimit();
	int time();
	int timeLimit();
}
namespace getRabbitData
{
	int leaderBoardScore(unsigned const char &n);
	std::string leaderBoardName(unsigned const char &n);
	std::string rabbitName();
}
namespace getCaHData
{
	int pointsNum();
	int pointsHeld(unsigned const char &n);
	unsigned char pointHolder(unsigned const char &n);
	unsigned char pointLabel(unsigned const char &n);
}
namespace getArenaData
{
	int round();
	int roundScore(unsigned const char &n);
	unsigned char playerStatus(unsigned const char &team, unsigned const char &player);
}
namespace getFlagData
{
	bool isHome(unsigned const char &n);
	int returnTime(unsigned const char &n);
	std::string holderName(unsigned const char &n);
}