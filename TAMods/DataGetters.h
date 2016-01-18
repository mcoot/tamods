#pragma once

#include "SdkHeaders.h"

namespace getViewPortData
{
	FVector2D size();
}
namespace getPlayerData
{
	bool isAlive();
	bool isRaged();
	bool isVehicle();
	bool isShielded();
	bool hasFlag();
	float energy();
	float energyMax();
	float energyPct();
	int classId();
	int health();
	int healthMax();
	int speed();
	int respawnTime();
	int numDeployables();
	int numMines();
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
namespace getFlagData
{
	bool isHome(unsigned const char &n);
	int returnTime(unsigned const char &n);
	std::string holderName(unsigned const char &n);
}