#include "DataGetters.h"
#include "Utils.h"

/*
	TODO:
	Rabbit / CaH stats (other gametypes as well?)
	drawRect kann nicht die groesseren koordinaten zuerst wie drawProgress
	more helper functions
	Fix vehicle/seat detection
	Stopwatch (all data)
	menuOpen() ?
	WorldSeconds and DeltaTime ?
	Game::time() in roammap manuell oder automatisch in der funktion handlen?
	Stats: Kills / Deaths / K/D / MAs / Streaks / Returns / Grabs
	Killfeed
	Chat / VGS / Whisper (prompt info)
	Game messages / Flag grabs etc
	Accolades
	Kill info
	Killer info
	Vehicle HP energy ammo
	Spectator stuff -> TrPlayerOwner.InRovingSpectate()? plus team 255
*/

FVector2D getViewPortData::size()
{
	if (!Utils::tr_gvc)
		return{ 0.0f, 0.0f };

	FVector2D s;
	Utils::tr_gvc->GetViewportSize(&s);
	return s;
}
/////////////////////////////////////////////////////////////////////////////////////
bool getPlayerData::isAlive()
{
	if (Utils::tr_pc && Utils::tr_pc->Pawn)
		return true;

	return false;
}
bool getPlayerData::isRaged()
{
	if (Utils::tr_pc && Utils::tr_pc->Pawn)
		return ((ATrPawn *)Utils::tr_pc->Pawn)->r_bIsRaged;

	return false;
}
bool getPlayerData::isVehicle()
{
	if (Utils::tr_pc && Utils::tr_pc->Pawn)
		return ((ATrPawn *)Utils::tr_pc->Pawn)->m_RidingVehicle || ((ATrPawn *)Utils::tr_pc->Pawn)->IsA(ATrVehicle::StaticClass());

	return false;
}
bool getPlayerData::isShielded()
{
	if (Utils::tr_pc && Utils::tr_pc->Pawn)
		return ((ATrPawn *)Utils::tr_pc->Pawn)->r_bIsShielded;

	return false;
}
bool getPlayerData::hasFlag()
{
	if (Utils::tr_pc && Utils::tr_pc->PlayerReplicationInfo)
		return ((ATrPlayerReplicationInfo *)Utils::tr_pc->PlayerReplicationInfo)->bHasFlag;

	return false;
}
float getPlayerData::energy()
{
	if (Utils::tr_pc && Utils::tr_pc->Pawn)
		return ((ATrPawn *)Utils::tr_pc->Pawn)->m_fCurrentPowerPool;

	return 0.0f;
}
float getPlayerData::energyMax()
{
	if (Utils::tr_pc && Utils::tr_pc->Pawn)
		return ((ATrPawn *)Utils::tr_pc->Pawn)->r_fMaxPowerPool;

	return 0.0f;
}
float getPlayerData::energyPct()
{
	if (Utils::tr_pc && Utils::tr_pc->Pawn)
		return ((ATrPawn *)Utils::tr_pc->Pawn)->m_fCurrentPowerPool / ((ATrPawn *)Utils::tr_pc->Pawn)->r_fMaxPowerPool;

	return 0.0f;
}
int getPlayerData::classId()
{
	if (Utils::tr_pc && Utils::tr_pc->PlayerReplicationInfo)
	{
		int classId = ((ATrPlayerReplicationInfo *)Utils::tr_pc->PlayerReplicationInfo)->GetPlayerClassId();
		if (classId == CONST_CLASS_TYPE_LIGHT) return 1;
		if (classId == CONST_CLASS_TYPE_MEDIUM) return 2;
		if (classId == CONST_CLASS_TYPE_HEAVY) return 3;
	}
	return 0;
}
int getPlayerData::health()
{
	if (Utils::tr_pc && Utils::tr_pc->Pawn)
		return Utils::tr_pc->Pawn->Health;

	return 0;
}
int getPlayerData::healthMax()
{
	if (Utils::tr_pc && Utils::tr_pc->Pawn)
		return Utils::tr_pc->Pawn->HealthMax;

	return 0;
}
int getPlayerData::speed()
{
	if (Utils::tr_pc && Utils::tr_pc->Pawn && !isVehicle())
		return ((ATrPawn *)Utils::tr_pc->Pawn)->CalculatePawnSpeed();

	return 0;
}
int getPlayerData::respawnTime()
{
	if (Utils::tr_pc)
		return Utils::tr_pc->bPreventRespawn ? Utils::tr_pc->m_nRespawnTimeRemaining + 1 : Utils::tr_pc->m_nRespawnTimeRemaining;

	return 0;
}
int getPlayerData::numDeployables()
{
	if (Utils::tr_pc && Utils::tr_pc->myHUD)
		return ((ATrHUD *)Utils::tr_pc->myHUD)->m_OwnedDeployables.Count;

	return 0;
}
int getPlayerData::numMines()
{
	if (Utils::tr_pc && Utils::tr_pc->myHUD)
		return ((ATrHUD *)Utils::tr_pc->myHUD)->m_OwnedMines.Count;

	return 0;
}
unsigned char getPlayerData::teamNum()
{
	if (Utils::tr_pc)
		return Utils::tr_pc->GetTeamNum();

	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////
bool getWeaponData::isReadyToFire(unsigned const char &n)
{
	ATrDevice *dev = Utils::getDeviceByEquipPointHelper(n);
	if (dev) return dev->r_bReadyToFire;

	return false;
}
bool getWeaponData::isReloading(unsigned const char &n)
{
	ATrDevice *dev = Utils::getDeviceByEquipPointHelper(n);
	if (dev) return dev->r_bIsReloading;

	return false;
}
bool getWeaponData::isPack(unsigned const char &n)
{
	ATrDevice *dev = Utils::getDeviceByEquipPointHelper(n);

	if (dev && dev->IsA(ATrDevice_Pack::StaticClass()))
		return true;

	return false;
}
bool getWeaponData::isPassiveReady(unsigned const char &n)
{
	ATrDevice *dev = Utils::getDeviceByEquipPointHelper(n);

	if (!dev) return false;

	// Packs, belt items, out of spare ammo or fully reloaded guns don't passively reload
	if (n == EQP_Belt || n == EQP_Pack || dev->m_nCarriedAmmo == 0 || dev->m_RemainingAmmoInClip == dev->GetMaxAmmoCount())
		return true;

	// check passive reload time
	if (Utils::tr_pc->WorldInfo && dev->m_fLastActiveTime > 0.0f && Utils::tr_pc->WorldInfo->TimeSeconds - dev->m_fLastActiveTime > dev->m_fTimeBeforeInactiveReload)
		return true;

	return false;
}
bool getWeaponData::isLowAmmo(unsigned const char &n)
{
	ATrDevice *dev = Utils::getDeviceByEquipPointHelper(n);
	if (dev) return dev->m_bLowAmmoOn;

	return false;
}
int getWeaponData::ammo(unsigned const char &n)
{
	ATrDevice *dev = Utils::getDeviceByEquipPointHelper(n);
	if (!dev) return -1;
	
	if (n == EQP_Belt)
		return dev->m_nCarriedAmmo;
	else if (n == EQP_Pack)
		return dev->AmmoCount;
	else
		return dev->m_RemainingAmmoInClip;
}
int getWeaponData::ammoMax(unsigned const char &n)
{
	ATrDevice *dev = Utils::getDeviceByEquipPointHelper(n);
	if (dev) return (int)dev->MaxAmmoCount;

	return -1;
}
int getWeaponData::ammoCarried(unsigned const char &n)
{
	ATrDevice *dev = Utils::getDeviceByEquipPointHelper(n);
	if (dev) return dev->m_nCarriedAmmo;

	return -1;
}
int getWeaponData::ammoMaxCarried(unsigned const char &n)
{
	ATrDevice *dev = Utils::getDeviceByEquipPointHelper(n);
	if (dev) return dev->m_nMaxCarriedAmmo;

	return -1;
}
int getWeaponData::ammoTotal(unsigned const char &n)
{
	ATrDevice *dev = Utils::getDeviceByEquipPointHelper(n);
	if (!dev) return -1;
	
	if (n == EQP_Belt)
		return dev->m_nCarriedAmmo;
	else if (n == EQP_Pack)
		return dev->AmmoCount;
	else
		return dev->m_RemainingAmmoInClip + dev->m_nCarriedAmmo;
}
std::string getWeaponData::name(unsigned const char &n)
{
	ATrDevice *dev = Utils::getDeviceByEquipPointHelper(n);
	if (dev) return Utils::f2std(dev->ItemName);

	return "unknown";
}
/////////////////////////////////////////////////////////////////////////////////////
bool getCurrentWeaponData::isReadyToFire()
{
	ATrDevice *dev = Utils::getCurrentDeviceHelper();
	if (dev) return dev->r_bReadyToFire;

	return false;
}
bool getCurrentWeaponData::isReloading()
{
	ATrDevice *dev = Utils::getCurrentDeviceHelper();
	if (dev) return dev->r_bIsReloading;

	return false;
}
bool getCurrentWeaponData::isPack()
{
	ATrDevice *dev = Utils::getCurrentDeviceHelper();

	if (dev && dev->r_eEquipAt == EQP_Pack)
		return true;

	return false;
}
bool getCurrentWeaponData::isLowAmmo()
{
	ATrDevice *dev = Utils::getCurrentDeviceHelper();
	if (dev) return dev->m_bLowAmmoOn;

	return false;
}
int getCurrentWeaponData::ammo()
{
	ATrDevice *dev = Utils::getCurrentDeviceHelper();
	if (!dev) return -1;

	if (dev->r_eEquipAt == EQP_Belt)
		return dev->m_nCarriedAmmo;
	else if (dev->r_eEquipAt == EQP_Pack)
		return dev->AmmoCount;
	else
		return dev->m_RemainingAmmoInClip;	
}
int getCurrentWeaponData::ammoMax()
{
	ATrDevice *dev = Utils::getCurrentDeviceHelper();
	if (dev) return dev->MaxAmmoCount;

	return -1;
}
int getCurrentWeaponData::ammoCarried()
{
	ATrDevice *dev = Utils::getCurrentDeviceHelper();
	if (dev) return dev->m_nCarriedAmmo;

	return -1;
}
int getCurrentWeaponData::ammoMaxCarried()
{
	ATrDevice *dev = Utils::getCurrentDeviceHelper();
	if (dev) return dev->m_nMaxCarriedAmmo;

	return -1;
}
int getCurrentWeaponData::ammoTotal()
{
	ATrDevice *dev = Utils::getCurrentDeviceHelper();
	if (!dev) return -1;
	
	if (dev->r_eEquipAt == EQP_Belt)
		return dev->m_nCarriedAmmo;
	else if (dev->r_eEquipAt == EQP_Pack)
		return dev->AmmoCount;
	else
		return dev->m_RemainingAmmoInClip + dev->m_nCarriedAmmo;
}
unsigned char getCurrentWeaponData::equippedAt()
{
	ATrDevice *dev = Utils::getCurrentDeviceHelper();
	if (dev) return dev->r_eEquipAt;

	return EQP_NONE;
}
std::string getCurrentWeaponData::name()
{
	ATrDevice *dev = Utils::getCurrentDeviceHelper();
	if (dev) return Utils::f2std(dev->ItemName);

	return "unknown";
}
/////////////////////////////////////////////////////////////////////////////////////
std::string getGameData::type()
{
	if (Utils::tr_pc && Utils::tr_pc->WorldInfo && Utils::tr_pc->WorldInfo->GetGameClass())
		return ((ATrGame *)Utils::tr_pc->WorldInfo->GetGameClass())->GetStringName();

	return "none";
}
std::string getGameData::timeStr()
{
	if (Utils::tr_pc && Utils::tr_pc->WorldInfo && Utils::tr_pc->WorldInfo->GRI)
	{
		char c[6];
		int *time = &Utils::tr_pc->WorldInfo->GRI->RemainingTime;
		sprintf(c, "%02d:%02d", *time / 60, *time % 60);
		return c;
	}
	return "00:00";
}
bool getGameData::isOfflinePlay()
{
	if (Utils::tr_pc && Utils::tr_pc->WorldInfo)
		return Utils::tr_pc->WorldInfo->NetMode == 0 ? true : false;

	return true;
}
bool getGameData::isGameEnd()
{
	if (Utils::tr_pc && Utils::tr_pc->WorldInfo && Utils::tr_pc->WorldInfo->Game)
		return Utils::tr_pc->WorldInfo->Game->bGameEnded;

	return false;
}
bool getGameData::isGenUp(unsigned const char &n)
{
	if (Utils::tr_pc && Utils::tr_pc->WorldInfo->GRI)
		return ((ATrGameReplicationInfo *)Utils::tr_pc->WorldInfo->GRI)->GeneratorPower[n] != 0;

	return false;
}
bool getGameData::isWarmUp()
{
	if (Utils::tr_pc && Utils::tr_pc->WorldInfo->GRI)
		return ((ATrGameReplicationInfo *)Utils::tr_pc->WorldInfo->GRI)->bWarmupRound;

	return false;
}
bool getGameData::isOverTime()
{
	if (Utils::tr_pc && Utils::tr_pc->WorldInfo && Utils::tr_pc->WorldInfo->Game)
		return Utils::tr_pc->WorldInfo->Game->bOverTime;

	return false;
}
int getGameData::genAutoRepairTime(unsigned const char &n)
{
	if (Utils::tr_pc && Utils::tr_pc->WorldInfo->GRI)
		return ((ATrGameReplicationInfo *)Utils::tr_pc->WorldInfo->GRI)->GeneratorDowntime[n];

	return 0;
}
int getGameData::overTimeLimit()
{
	if (Utils::tr_pc && Utils::tr_pc->WorldInfo && Utils::tr_pc->WorldInfo->GRI &&
		((ATrGameReplicationInfo *)Utils::tr_pc->WorldInfo->GRI)->r_ServerConfig)
		return ((ATrGameReplicationInfo *)Utils::tr_pc->WorldInfo->GRI)->r_ServerConfig->OvertimeLimit;

	return 0;
}
int getGameData::score(unsigned const char &n)
{
	if (Utils::tr_pc && Utils::tr_pc->WorldInfo && Utils::tr_pc->WorldInfo->GRI &&
		(unsigned)Utils::tr_pc->WorldInfo->GRI->Teams.Num() > n &&
		Utils::tr_pc->WorldInfo->GRI->Teams.Data[n])
		return (int)Utils::tr_pc->WorldInfo->GRI->Teams.Data[n]->Score;

	return 0;
}
int getGameData::scoreLimit()
{
	if (Utils::tr_pc && Utils::tr_pc->WorldInfo && Utils::tr_pc->WorldInfo->GRI &&
		((ATrGameReplicationInfo *)Utils::tr_pc->WorldInfo->GRI)->r_ServerConfig)
		return ((ATrGameReplicationInfo *)Utils::tr_pc->WorldInfo->GRI)->r_ServerConfig->ScoreLimit;

	return 0;
}
int getGameData::time()
{
	if (Utils::tr_pc && Utils::tr_pc->WorldInfo && Utils::tr_pc->WorldInfo->GRI)
		return Utils::tr_pc->WorldInfo->GRI->RemainingTime;

	return 0;
}
int getGameData::timeLimit()
{
	if (Utils::tr_pc && Utils::tr_pc->WorldInfo && Utils::tr_pc->WorldInfo->GRI)
		return Utils::tr_pc->WorldInfo->GRI->TimeLimit;

	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////
bool getFlagData::isHome(unsigned const char &n)
{
	if (Utils::tr_pc && Utils::tr_pc->WorldInfo && Utils::tr_pc->WorldInfo->GRI &&
		((ATrGameReplicationInfo *)Utils::tr_pc->WorldInfo->GRI)->m_Flags[n])
		return ((ATrGameReplicationInfo *)Utils::tr_pc->WorldInfo->GRI)->m_Flags[n]->bHome;

	return true;
}
int getFlagData::returnTime(unsigned const char &n)
{
	if (Utils::tr_pc && Utils::tr_pc->WorldInfo && Utils::tr_pc->WorldInfo->GRI &&
		((ATrGameReplicationInfo *)Utils::tr_pc->WorldInfo->GRI)->FlagReturnTime[n])
		return ((ATrGameReplicationInfo *)Utils::tr_pc->WorldInfo->GRI)->FlagReturnTime[n];

	return 0;
}
std::string getFlagData::holderName(unsigned const char &n)
{
	if (Utils::tr_pc && Utils::tr_pc->WorldInfo && Utils::tr_pc->WorldInfo->Game && Utils::tr_pc->WorldInfo->GRI)
	{
		AGameInfo *game = Utils::tr_pc->WorldInfo->Game;

		/*if ((game->IsA(ATrGame_TRRabbit::StaticClass()) || game->IsA(ATrGame_TRTeamRabbit::StaticClass())) &&
			((ATrGameReplicationInfo *)Utils::tr_pc->WorldInfo->GRI)->m_Flags[0] &&
			((ATrGameReplicationInfo *)Utils::tr_pc->WorldInfo->GRI)->m_Flags[0]->HolderPRI)
		{
			Utils::printConsole("Rabbit or TDM");
			ATrPlayerReplicationInfo *pri = (ATrPlayerReplicationInfo *)((ATrGameReplicationInfo *)Utils::tr_pc->WorldInfo->GRI)->m_Flags[0]->HolderPRI;
			
			// Enemy holding the flag in these modes means it's ours. Teammate holding it means their flag is held.
			if (pri->GetTeamNum() != n)
				return Utils::f2std(pri->PlayerName);
		}
		else*/ if (((ATrGameReplicationInfo *)Utils::tr_pc->WorldInfo->GRI)->m_Flags[n] &&
			((ATrGameReplicationInfo *)Utils::tr_pc->WorldInfo->GRI)->m_Flags[n]->HolderPRI)
		{
			Utils::printConsole("CTF or Blitz");
			return Utils::f2std(((ATrGameReplicationInfo *)Utils::tr_pc->WorldInfo->GRI)->m_Flags[n]->HolderPRI->PlayerName);
		}
	}

	return " ";
}