#include "DataGetters.h"
#include "Mods.h"
#include "NameCryptor.h"

FVector2D getViewPortData::size()
{
	if (!Utils::tr_gvc)
		return{ 0.0f, 0.0f };

	FVector2D s;
	Utils::tr_gvc->GetViewportSize(&s);
	return s;
}
bool getViewPortData::isMainMenuOpen()
{
	// FIXME: crashes when entering a password
	if (Utils::tr_hud)
		return Utils::tr_hud->bIsMainMenuOpen;

	return false;
}
bool getViewPortData::isScoreboardOpen()
{
	if (Utils::tr_hud && Utils::tr_hud->Scoreboard)
		return Utils::tr_hud->Scoreboard->bIsActive;

	return false;
}
/////////////////////////////////////////////////////////////////////////////////////
std::string getPlayerData::name()
{
	if (Utils::tr_pc && Utils::tr_pc->PlayerReplicationInfo)
		return Utils::f2std(Utils::tr_pc->PlayerReplicationInfo->PlayerName);

	return "";
}
bool getPlayerData::isAlive()
{
	if (Utils::tr_pc && Utils::tr_pc->Pawn)
		return true;

	return false;
}
bool getPlayerData::isFirstPerson()
{
	if (Utils::tr_pc && Utils::tr_pc->Pawn)
		return Utils::tr_pc->Pawn->IsFirstPerson();
	return true;
}
bool getPlayerData::isRaged()
{
	ATrPawn *TrP = Utils::getPlayerPawn();
	if (TrP)
		return TrP->r_bIsRaged;

	return false;
}
bool getPlayerData::isVehicle()
{
	if (Utils::tr_pc && Utils::tr_pc->Pawn && Utils::tr_pc->Pawn->Weapon)
	{
		if (Utils::tr_pc->Pawn->Weapon->IsA(ATrVehicleWeapon::StaticClass()) || ((ATrPawn *)Utils::tr_pc->Pawn)->m_RidingVehicle)
			return true;
	}

	return false;
}
bool getPlayerData::isShielded()
{
	ATrPawn *TrP = Utils::getPlayerPawn();
	if (TrP)
		return TrP->r_bIsShielded;

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
	ATrPawn *TrP = Utils::getPlayerPawn();
	if (TrP)
		return TrP->m_fCurrentPowerPool;

	return 0.0f;
}
float getPlayerData::energyMax()
{
	ATrPawn *TrP = Utils::getPlayerPawn();
	if (TrP)
		return TrP->r_fMaxPowerPool;

	return 0.0f;
}
float getPlayerData::energyPct()
{
	ATrPawn *TrP = Utils::getPlayerPawn();
	if (TrP)
		return TrP->m_fCurrentPowerPool / TrP->r_fMaxPowerPool;

	return 0.0f;
}
float getPlayerData::lastDamagedTime()
{
	ATrPawn *TrP = Utils::getPlayerPawn();
	if (TrP)
		return TrP->m_fLastDamagerTimeStamp;

	return 0.0f;
}
float getPlayerData::regenTimer()
{
	ATrPawn *TrP = Utils::getPlayerPawn();
	if (TrP)
	{
		if (TrP->HealthMax == TrP->Health)
			return 0.0f;

		if (TrP->WorldInfo)
		{
			if (getPlayerData::hasFlag())
				return TrP->m_fSecondsBeforeAutoHeal;

			float remaining = TrP->m_fSecondsBeforeAutoHeal - (TrP->WorldInfo->TimeSeconds - TrP->m_fLastDamagerTimeStamp);
			return remaining > 0.0f ? remaining : 0.0f;
		}
	}

	return 0.0f;
}
int getPlayerData::ping()
{
	if (Utils::tr_pc && Utils::tr_pc->PlayerReplicationInfo)
		return Utils::tr_pc->PlayerReplicationInfo->Ping * 4;

	return 0;
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
	ATrPawn *TrP = Utils::getPlayerPawn();
	if (TrP)
		return TrP->Health;

	return 0;
}
int getPlayerData::healthMax()
{
	ATrPawn *TrP = Utils::getPlayerPawn();
	if (TrP)
		return TrP->HealthMax;

	return 0;
}
int getPlayerData::speed()
{
	ATrPawn *TrP = Utils::getPlayerPawn();
	if (TrP)
		return TrP->CalculatePawnSpeed();

	return 0;
}
int getPlayerData::respawnTime()
{
	if (Utils::tr_pc)
		return Utils::tr_pc->bPreventRespawn && Utils::tr_pc->r_fRespawnTime > 0 ? Utils::tr_pc->m_nRespawnTimeRemaining + 1 : 0;

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
int getPlayerData::score()
{
	if (Utils::tr_pc && Utils::tr_pc->PlayerReplicationInfo)
		return (int)Utils::tr_pc->PlayerReplicationInfo->Score;

	return 0;
}
int getPlayerData::rabbitRank()
{
	if (Utils::tr_pc && Utils::tr_pc->PlayerReplicationInfo)
		return ((ATrPlayerReplicationInfo *)Utils::tr_pc->PlayerReplicationInfo)->m_nRabbitRank;

	return 0;
}
int getPlayerData::arenaSpawnsLeft()
{
	if (Utils::tr_pc && Utils::tr_pc->PlayerReplicationInfo)
		return ((ATrPlayerReplicationInfo *)Utils::tr_pc->PlayerReplicationInfo)->r_nArenaSpawnsLeft;

	return 0;
}
int getPlayerData::kills()
{
	if (Utils::tr_pc && Utils::tr_pc->PlayerReplicationInfo)
		return ((ATrPlayerReplicationInfo *)Utils::tr_pc->PlayerReplicationInfo)->m_nKills;

	return 0;
}
int getPlayerData::deaths()
{
	if (Utils::tr_pc && Utils::tr_pc->PlayerReplicationInfo)
		return Utils::tr_pc->PlayerReplicationInfo->Deaths;

	return 0;
}
int getPlayerData::assists()
{
	if (Utils::tr_pc && Utils::tr_pc->PlayerReplicationInfo)
		return ((ATrPlayerReplicationInfo *)Utils::tr_pc->PlayerReplicationInfo)->m_nAssists;

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

	if (dev && n == EQP_Pack && dev->IsA(ATrDevice_Pack::StaticClass()))
		return true;

	return false;
}
bool getWeaponData::isPassiveReady(unsigned const char &n)
{
	ATrDevice *dev = Utils::getDeviceByEquipPointHelper(n);

	if (!dev) return false;

	// Packs, belt items, out of spare ammo or fully reloaded guns don't passively reload
	if (n == EQP_Belt || n == EQP_Pack || dev->m_nCarriedAmmo == 0 || dev->m_RemainingAmmoInClip == dev->MaxAmmoCount)
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
bool getCurrentWeaponData::isReloaded()
{
	ATrDevice *dev = Utils::getCurrentDeviceHelper();
	if (dev) return dev->MaxAmmoCount == dev->m_RemainingAmmoInClip;

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
int getCurrentWeaponData::reticuleIndex()
{
	if (Utils::tr_pc && Utils::tr_pc->Pawn && Utils::tr_pc->Pawn->Weapon)
		return ((ATrDevice *)Utils::tr_pc->Pawn->Weapon)->m_nReticuleIndex;
	else
		return -1;
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
ATrVehicle* getVehicleHelper()
{
	if (Utils::tr_pc && Utils::tr_pc->Pawn)
	{
		ATrPawn *TrP = (ATrPawn *)Utils::tr_pc->Pawn;

		// All vehicles except gravcycle passenger
		if (TrP->Weapon && TrP->Weapon->IsA(ATrVehicleWeapon::StaticClass()))
			return (ATrVehicle *)((ATrVehicleWeapon *)TrP->Weapon)->MyVehicle;
		// Grav bike passenger
		else if (TrP->m_RidingVehicle)
			return TrP->m_RidingVehicle;
	}
	return NULL;
}
int getVehicleData::health()
{
	ATrVehicle *v = getVehicleHelper();
	if (v) return v->Health;

	return 0;
}
int getVehicleData::healthMax()
{
	ATrVehicle *v = getVehicleHelper();
	if (v) return v->HealthMax;

	return 0;
}
float getVehicleData::energyPct()
{
	ATrVehicle *v = getVehicleHelper();
	if (v) return v->GetPowerPoolPercent();

	return 0.0f;
}
int getVehicleData::ammo()
{
	if (Utils::tr_pc && Utils::tr_pc->Pawn)
	{
		ATrPawn *TrP = (ATrPawn *)Utils::tr_pc->Pawn;

		if (TrP->Weapon && TrP->Weapon->IsA(ATrVehicleWeapon::StaticClass()))
			return ((ATrVehicleWeapon *)TrP->Weapon)->AmmoCount;
	}
	return -1;
}
int getVehicleData::ammoMax()
{
	if (Utils::tr_pc && Utils::tr_pc->Pawn)
	{
		ATrPawn *TrP = (ATrPawn *)Utils::tr_pc->Pawn;

		if (TrP->Weapon && TrP->Weapon->IsA(ATrVehicleWeapon::StaticClass()))
			return ((ATrVehicleWeapon *)TrP->Weapon)->MaxAmmoCount;
	}
	return -1;
}
int getVehicleData::speed()
{
	ATrVehicle *v = getVehicleHelper();
	if (v) return (int)(Geom::vSize(v->Velocity) * 0.072f);

	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////
std::string getGameData::type()
{
	if (Utils::tr_pc && Utils::tr_pc->WorldInfo && Utils::tr_pc->WorldInfo->GetGameClass())
		return ((ATrGame *)Utils::tr_pc->WorldInfo->GetGameClass())->GetStringName();

	return "unknown";
}
std::string getGameData::timeStr()
{
	if (Utils::tr_pc && Utils::tr_pc->WorldInfo && Utils::tr_pc->WorldInfo->GRI)
	{
		char c[6];
		int *time = Utils::tr_pc->WorldInfo->GRI->TimeLimit != 0 ? &Utils::tr_pc->WorldInfo->GRI->RemainingTime : &Utils::tr_pc->WorldInfo->GRI->ElapsedTime;
		sprintf(c, "%02d:%02d", *time / 60, *time % 60);
		return c;
	}
	return "00:00";
}
std::string getGameData::spectators()
{
	if (Utils::tr_pc && Utils::tr_pc->WorldInfo && Utils::tr_pc->WorldInfo->GRI)
	{
		TArray<APlayerReplicationInfo *> &priarray = Utils::tr_pc->WorldInfo->GRI->PRIArray;
		std::string specLine;
		unsigned char specCount = 0;

		for (int i = 0; i < priarray.Count; i++)
		{
			if (priarray.Data[i] && ((ATrPlayerReplicationInfo *)priarray.Data[i])->m_Rank && priarray.Data[i]->GetTeamNum() == 255)
			{
				specCount++;
				if (specCount > 1)
					specLine.append(", " + Utils::f2std(priarray.Data[i]->PlayerName));
				else
					specLine.append(Utils::f2std(priarray.Data[i]->PlayerName));
			}
		}
		if (specCount)
		{
			return "(" + std::to_string(specCount) + ") " + specLine;
		}
	}

	return "";
}
bool getGameData::isOfflinePlay()
{
	if (Utils::tr_pc && Utils::tr_pc->WorldInfo)
		return Utils::tr_pc->WorldInfo->NetMode == NM_Standalone ? true : false;

	return true;
}
bool getGameData::isOver()
{
	if (Utils::tr_pc && Utils::tr_pc->WorldInfo && Utils::tr_pc->WorldInfo->GRI)
		return ((ATrGameReplicationInfo *)Utils::tr_pc->WorldInfo->GRI)->bMatchIsOver;

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
		Utils::tr_pc->WorldInfo->GRI->Teams.Num() > n &&
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
		return Utils::tr_pc->WorldInfo->GRI->TimeLimit != 0 ? Utils::tr_pc->WorldInfo->GRI->RemainingTime : Utils::tr_pc->WorldInfo->GRI->ElapsedTime;

	return 0;
}
int getGameData::timeLimit()
{
	if (Utils::tr_pc && Utils::tr_pc->WorldInfo && Utils::tr_pc->WorldInfo->GRI)
		return Utils::tr_pc->WorldInfo->GRI->TimeLimit;

	return 0;
}
float getGameData::timeSeconds()
{
	if (Utils::tr_pc && Utils::tr_pc->WorldInfo)
		return Utils::tr_pc->WorldInfo->TimeSeconds;

	return 0.0f;
}
float getGameData::realTimeSeconds()
{
	if (Utils::tr_pc && Utils::tr_pc->WorldInfo)
		return Utils::tr_pc->WorldInfo->RealTimeSeconds;

	return 0.0f;
}
/////////////////////////////////////////////////////////////////////////////////////
int getRabbitData::leaderBoardScore(unsigned const char &n)
{
	if (Utils::tr_pc && Utils::tr_pc->WorldInfo && Utils::tr_pc->WorldInfo->GRI)
	{
		ATrGameReplicationInfo *gri = (ATrGameReplicationInfo *)Utils::tr_pc->WorldInfo->GRI;

		if (gri->m_RabbitLeaderBoard[n])
			return (int)gri->m_RabbitLeaderBoard[n]->Score;
	}
	return 0;
}
std::string getRabbitData::leaderBoardName(unsigned const char &n)
{
	if (Utils::tr_pc && Utils::tr_pc->WorldInfo && Utils::tr_pc->WorldInfo->GRI)
	{
		ATrGameReplicationInfo *gri = (ATrGameReplicationInfo *)Utils::tr_pc->WorldInfo->GRI;

		if (gri->m_RabbitLeaderBoard[n])
			return Utils::f2std(gri->m_RabbitLeaderBoard[n]->PlayerName);
	}
	return "";
}
std::string getRabbitData::rabbitName()
{
	if (Utils::tr_pc && Utils::tr_pc->WorldInfo && Utils::tr_pc->WorldInfo->GRI)
	{
		ATrGameReplicationInfo *gri = (ATrGameReplicationInfo *)Utils::tr_pc->WorldInfo->GRI;

		if (gri->m_CurrentRabbitPRI)
			return Utils::f2std(gri->m_CurrentRabbitPRI->PlayerName);
	}
	return "";
}
/////////////////////////////////////////////////////////////////////////////////////
int getCaHData::pointsNum()
{
	if (Utils::tr_pc && Utils::tr_pc->myHUD && ((ATrHUD *)Utils::tr_pc->myHUD)->CaHStats)
		return ((ATrHUD *)Utils::tr_pc->myHUD)->CaHStats->m_CapturePointData.Count;

	return 0;
}
int getCaHData::pointsHeld(unsigned const char &n)
{
	if (Utils::tr_pc && Utils::tr_pc->WorldInfo && Utils::tr_pc->WorldInfo->GRI)
	{
		ATrGameReplicationInfo *gri = (ATrGameReplicationInfo *)Utils::tr_pc->WorldInfo->GRI;

		if (gri->r_nNumCapturePointsHeld[n])
			return gri->r_nNumCapturePointsHeld[n];
	}
	return 0;
}
unsigned char getCaHData::pointHolder(unsigned const char &n)
{
	if (Utils::tr_pc && Utils::tr_pc->myHUD && ((ATrHUD *)Utils::tr_pc->myHUD)->CaHStats)
	{
		UTrCaHStats *stats = ((ATrHUD *)Utils::tr_pc->myHUD)->CaHStats;

		if (stats->m_CapturePoints.Data[n])
			return stats->m_CapturePoints.Data[n]->DefenderTeamIndex;
	}
	return 255;
}
unsigned char getCaHData::pointLabel(unsigned const char &n)
{
	if (Utils::tr_pc && Utils::tr_pc->myHUD && ((ATrHUD *)Utils::tr_pc->myHUD)->CaHStats)
	{
		UTrCaHStats *stats = ((ATrHUD *)Utils::tr_pc->myHUD)->CaHStats;

		if (stats->m_CapturePointData.Get(n))
			return stats->m_CapturePointData.Data[n].PointLabel;
	}
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////
int getArenaData::round()
{
	if (Utils::tr_pc && Utils::tr_pc->WorldInfo->GRI)
		return ((ATrGameReplicationInfo *)Utils::tr_pc->WorldInfo->GRI)->r_nCurrentRound;

	return 0;
}
int getArenaData::roundScore(unsigned const char &n)
{
	if (Utils::tr_pc && Utils::tr_pc->WorldInfo->GRI)
	{
		ATrGameReplicationInfo *gri = (ATrGameReplicationInfo *)Utils::tr_pc->WorldInfo->GRI;

		if (gri->r_nRoundScore[n])
			return gri->r_nRoundScore[n];
	}
	return 0;
}
unsigned char getArenaData::playerStatus(unsigned const char &team, unsigned const char &player)
{
	if (Utils::tr_pc && Utils::tr_pc->WorldInfo->GRI)
	{
		ATrGameReplicationInfo *gri = (ATrGameReplicationInfo *)Utils::tr_pc->WorldInfo->GRI;
		ATrPlayerReplicationInfo *pri;

		if (team == 0 && gri->r_BEPlayerList[player])
			pri = gri->r_BEPlayerList[player];
		else if (gri->r_DSPlayerList[player])
			pri = gri->r_DSPlayerList[player];

		if (pri && pri->Team && pri->m_nRankNum)
		{
			unsigned char statusMask = 1;

			if (!pri->r_bIsCrossedOffArenaList)
				statusMask += 2;
			if (pri->r_nArenaSpawnsLeft > 0)
				statusMask += 4;

			return statusMask;
		}
	}
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////
bool getFlagData::isHome(unsigned const char &n)
{
	if (Utils::tr_pc && Utils::tr_pc->WorldInfo && Utils::tr_pc->WorldInfo->GRI)
	{
		ATrGameReplicationInfo *gri = (ATrGameReplicationInfo *)Utils::tr_pc->WorldInfo->GRI;

		if (Utils::tr_pc->WorldInfo->GetGameClass() == ATrGame_TRTeamRabbit::StaticClass() ||
			gri->GameClass == ATrGame_TRTeamRabbit::StaticClass() ||
			Utils::tr_pc->WorldInfo->GetGameClass() == ATrGame_TRRabbit::StaticClass() ||
			gri->GameClass == ATrGame_TRRabbit::StaticClass())
			return false;

		if (gri->m_Flags[n])
			return gri->m_Flags[n]->bHome;
	}
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
	if (Utils::tr_pc && Utils::tr_pc->WorldInfo && Utils::tr_pc->WorldInfo->GRI)
	{
		ATrGameReplicationInfo *gri = (ATrGameReplicationInfo *)Utils::tr_pc->WorldInfo->GRI;

		if (Utils::tr_pc->WorldInfo->GetGameClass() == ATrGame_TRTeamRabbit::StaticClass() ||
			gri->GameClass == ATrGame_TRTeamRabbit::StaticClass())
		{ // TDM
			if (gri->m_Flags[0] && gri->m_Flags[0]->HolderPRI &&
				gri->m_Flags[0]->HolderPRI->GetTeamNum() != n)
				return Utils::f2std(gri->m_Flags[0]->HolderPRI->PlayerName);
		}
		else if (Utils::tr_pc->WorldInfo->GetGameClass() == ATrGame_TRRabbit::StaticClass() ||
			gri->GameClass == ATrGame_TRRabbit::StaticClass())
		{ // Rabbit
			if (gri->m_Flags[0] && gri->m_Flags[0]->HolderPRI)
				return Utils::f2std(gri->m_Flags[0]->HolderPRI->PlayerName);
		}
		// Everything else
		else if (gri->m_Flags[n] && gri->m_Flags[n]->HolderPRI)
			return Utils::f2std(gri->m_Flags[n]->HolderPRI->PlayerName);
	}
	return "";
}
/////////////////////////////////////////////////////////////////////////////////////
bool getStopwatchData::isRunning()
{
	return g_config.stopwatchRunning;
}
float getStopwatchData::time()
{
	if (Utils::tr_pc && Utils::tr_pc->WorldInfo)
		return Utils::tr_pc->WorldInfo->RealTimeSeconds - g_config.stopwatchStartTime;
	else
		return 0.0f;
}
std::string getStopwatchData::timeStr()
{
	if (Utils::tr_pc && Utils::tr_pc->WorldInfo)
		return Utils::fTime2stopwatch(Utils::tr_pc->WorldInfo->RealTimeSeconds - g_config.stopwatchStartTime);

	return "00:00.0";
}

// Custom death messages
void TrHUD_AddUpdateToCombatLog(ATrHUD *that, ATrHUD_execAddUpdateToCombatLog_Parms *params)
{
	// params->CombatType: 0 = Aggressor is from own team. 1 = Aggressor is from enemy team (Suicide is an aggressor)
	// I forward CombatType as a bitmask where the second bit means the death message is related to us
	// First bit still means whether the aggressor is an enemy or not, so 2 means we killed someone and 3 we got killed
	// params->WeaponIcon = CONST_TRICON_KILLTYPE_* (130 - 142)

	if (g_config.onAddToCombatLog && !g_config.onAddToCombatLog->isNil() && g_config.onAddToCombatLog->isFunction())
	{
		std::string Aggressor = Utils::f2std(params->Aggressor);
		std::string Victim = Utils::f2std(params->Victim);
		unsigned char CombatType = (unsigned char)params->CombatType;

		if (Utils::tr_pc && Utils::tr_pc->PlayerReplicationInfo)
		{
			std::string me = Utils::f2std(Utils::tr_pc->PlayerReplicationInfo->PlayerName);
			if (Aggressor == me || Victim == me)
				CombatType |= 2;
		}
		try
		{
			// We only have to encrypt the victims name if the agressor is in our team (first bit in CombatType not set)
			(*g_config.onAddToCombatLog)(CombatType, Aggressor, params->WeaponIcon - 129, CombatType & 1 ? Victim : cryptor.toId(Victim));
		}
		catch (const LuaException &e)
		{
			Utils::console("LuaException: %s", e.what());
		}
	}
	if (Utils::tr_pc && Utils::tr_pc->m_bShowHUDCombatLog)
		that->AddUpdateToCombatLog(params->CombatType, params->Aggressor, params->WeaponIcon, params->Victim);
}

void TrHUD_AddToHeroStatus(ATrHUD *that, ATrHUD_execAddToHeroStatus_Parms *params)
{
	if (g_config.onGameMessage && !g_config.onGameMessage->isNil() && g_config.onGameMessage->isFunction())
	{
		try
		{
			(*g_config.onGameMessage)(Utils::f2std(params->Message), params->ShowTime);
		}
		catch (const LuaException &e)
		{
			Utils::console("LuaException: %s", e.what());
		}
		return;
	}
	that->AddToHeroStatus(params->Message, params->ShowTime);
}

// Flood protection
void TrHUD_SendLocalMessageToChat(ATrHUD *that, ATrHUD_execSendLocalMessageToChat_Parms *params)
{
	if (g_config.onGameMessage && !g_config.onGameMessage->isNil() && g_config.onGameMessage->isFunction())
	{
		try
		{
			(*g_config.onGameMessage)(Utils::f2std(params->Message), 1);
		}
		catch (const LuaException &e)
		{
			Utils::console("LuaException: %s", e.what());
		}
		return;
	}
	that->SendLocalMessageToChat(params->Message);
}

// Pending class
void GfxTrHud_UpdateChatLog(UGfxTrHud *that, UGfxTrHud_execUpdateChatLog_Parms *params)
{
	if (g_config.onGameMessage && !g_config.onGameMessage->isNil() && g_config.onGameMessage->isFunction())
	{
		try
		{
			(*g_config.onGameMessage)(Utils::f2std(params->Message), 1);
		}
		catch (const LuaException &e)
		{
			Utils::console("LuaException: %s", e.what());
		}
		return;
	}
	that->UpdateChatLog(params->Message, params->ChannelColor, params->bPublic);
}

// Whisper messages
bool TrPC_AddChatToConsole(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	ATrPlayerController *that = (ATrPlayerController *)dwCallingObject;
	ATrPlayerController_eventAddChatToConsole_Parms *params = (ATrPlayerController_eventAddChatToConsole_Parms *)pParams;

	if (g_config.onChatMessage && !g_config.onChatMessage->isNil() && g_config.onChatMessage->isFunction())
	{
		try
		{
			(*g_config.onChatMessage)(255, params->Channel, Utils::f2std(params->Sender), Utils::f2std(params->ChatMessage), false);
		}
		catch (const LuaException &e)
		{
			Utils::console("LuaException: %s", e.what());
		}
		return true;
	}

	return false;
	//that->eventAddChatToConsole(params->Sender, params->ChatMessage, params->Channel);
}

void TrHUD_AddUpdateToKillMessage(ATrHUD *that, ATrHUD_execAddUpdateToKillMessage_Parms *params)
{
	if (g_config.onKillMessage && !g_config.onKillMessage->isNil() && g_config.onKillMessage->isFunction())
	{
		try
		{
			(*g_config.onKillMessage)(Utils::f2std(params->Message), cryptor.toId(Utils::f2std(params->PlayerName)));
		}
		catch (const LuaException &e)
		{
			Utils::console("LuaException: %s", e.what());
		}
		return;
	}
	that->AddUpdateToKillMessage(params->RankIcon, params->PlayerIcon, params->PlayerName, params->Message);
}