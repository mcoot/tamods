#include "Mods.h"

namespace getViewPortData
{
	FVector2D size()
	{
		if (Utils::tr_pc && Utils::tr_pc->Player && ((ULocalPlayer *)Utils::tr_pc->Player)->ViewportClient)
		{
			FVector2D s;
			((ULocalPlayer *)Utils::tr_pc->Player)->ViewportClient->GetViewportSize(&s);
			return s;
		}

		return{ 0.0f, 0.0f };
	}
}
namespace getPlayerData
{
	bool isAlive()
	{
		if (Utils::tr_pc && Utils::tr_pc->Pawn)
			return true;

		return false;
	}
	bool isRaged()
	{
		if (Utils::tr_pc && Utils::tr_pc->Pawn)
			return ((ATrPawn *)Utils::tr_pc->Pawn)->r_bIsRaged;

		return false;
	}
	bool isVehicle()
	{
		if (Utils::tr_pc && Utils::tr_pc->Pawn)
			return ((ATrPawn *)Utils::tr_pc->Pawn)->m_RidingVehicle || ((ATrPawn *)Utils::tr_pc->Pawn)->IsA(ATrVehicle::StaticClass());

		return false;
	}
	bool hasFlag()
	{
		if (Utils::tr_pc && Utils::tr_pc->PlayerReplicationInfo)
			return ((ATrPlayerReplicationInfo *)Utils::tr_pc->PlayerReplicationInfo)->bHasFlag;

		return false;
	}
	int energy()
	{
		if (Utils::tr_pc && Utils::tr_pc->Pawn)
			return (int)((ATrPawn *)Utils::tr_pc->Pawn)->m_fCurrentPowerPool;

		return 0;
	}
	int energyMax()
	{
		if (Utils::tr_pc && Utils::tr_pc->Pawn)
			return (int)((ATrPawn *)Utils::tr_pc->Pawn)->r_fMaxPowerPool;

		return 0;
	}
	int health()
	{
		if (Utils::tr_pc && Utils::tr_pc->Pawn)
			return Utils::tr_pc->Pawn->Health;

		return 0;
	}
	int healthMax()
	{
		if (Utils::tr_pc && Utils::tr_pc->Pawn)
			return Utils::tr_pc->Pawn->HealthMax;

		return 0;
	}
	int speed()
	{
		if (Utils::tr_pc && Utils::tr_pc->Pawn && !isVehicle())
			return ((ATrPawn *)Utils::tr_pc->Pawn)->CalculatePawnSpeed();

		return 0;
	}
	int respawnTime()
	{
		if (Utils::tr_pc)
			return Utils::tr_pc->bPreventRespawn ? Utils::tr_pc->m_nRespawnTimeRemaining + 1 : Utils::tr_pc->m_nRespawnTimeRemaining;

		return 0;
	}
	unsigned char teamNum()
	{
		if (Utils::tr_pc)
			return Utils::tr_pc->GetTeamNum();

		return 0;
	}
}
namespace getWeaponData
{
	ATrDevice* getDeviceByEquipPointHelper(unsigned char n)
	{
		if (Utils::tr_pc && Utils::tr_pc->Pawn && Utils::tr_pc->Pawn->InvManager)
			return ((ATrInventoryManager *)Utils::tr_pc->Pawn->InvManager)->GetDeviceByEquipPoint(n);

		return NULL;
	}
	////////////////////////////////////////////
	bool isReadyToFire(unsigned char n)
	{
		ATrDevice *dev = getDeviceByEquipPointHelper(n);
		if (dev) return dev->r_bReadyToFire;

		return false;
	}
	bool isReloading(unsigned char n)
	{
		ATrDevice *dev = getDeviceByEquipPointHelper(n);
		if (dev) return dev->r_bIsReloading;

		return false;
	}
	bool isSingleShotWeapon(unsigned char n)
	{
		ATrDevice *dev = getDeviceByEquipPointHelper(n);
		if (dev) return dev->m_bReloadSingles || dev->GetMaxAmmoCount() == 1;

		return true;
	}
	bool isPassiveReady(unsigned char n)
	{
		ATrDevice *dev = getDeviceByEquipPointHelper(n);
		if (dev && Utils::tr_pc->WorldInfo)
		{
			if (dev->m_fLastActiveTime > 0.0f && Utils::tr_pc->WorldInfo->TimeSeconds - dev->m_fLastActiveTime > dev->m_fTimeBeforeInactiveReload)
				return true;
		}
		return false;
	}
	bool isLowAmmo(unsigned char n)
	{
		ATrDevice *dev = getDeviceByEquipPointHelper(n);
		if (dev) return dev->m_bLowAmmoOn;

		return false;
	}
	int ammo(unsigned char n)
	{
		ATrDevice *dev = getDeviceByEquipPointHelper(n);
		if (dev) return dev->GetAmmoCount();

		return -1;
	}
	int ammoCarried(unsigned char n)
	{
		ATrDevice *dev = getDeviceByEquipPointHelper(n);
		if (dev) return dev->m_nCarriedAmmo;

		return -1;
	}
	int ammoTotal(unsigned char n)
	{
		ATrDevice *dev = getDeviceByEquipPointHelper(n);
		if (dev) return dev->GetAmmoCount() + dev->m_nCarriedAmmo;

		return -1;
	}
	FString name(unsigned char n)
	{
		ATrDevice *dev = getDeviceByEquipPointHelper(n);
		if (dev) return dev->ItemName;

		return L"unknown";
	}
}
namespace getCurrentWeaponData
{
	ATrDevice* getCurrentDeviceHelper()
	{
		if (Utils::tr_pc && Utils::tr_pc->Pawn && Utils::tr_pc->Pawn->Weapon && !Utils::tr_pc->Pawn->Weapon->IsA(ATrVehicleWeapon::StaticClass()))
			return (ATrDevice *)Utils::tr_pc->Pawn->Weapon;

		return NULL;
	}
	////////////////////////////////////////////
	bool isSingleShotWeapon()
	{
		ATrDevice *dev = getCurrentDeviceHelper();
		if (dev) return dev->GetMaxAmmoCount() == 1;

		return true;
	}
	bool isReadyToFire()
	{
		ATrDevice *dev = getCurrentDeviceHelper();
		if (dev) return dev->r_bReadyToFire;

		return false;
	}
	bool isReloading()
	{
		ATrDevice *dev = getCurrentDeviceHelper();
		if (dev) return dev->r_bIsReloading;

		return false;
	}
	bool isLowAmmo()
	{
		ATrDevice *dev = getCurrentDeviceHelper();
		if (dev) return dev->m_bLowAmmoOn;

		return false;
	}
	int ammo()
	{
		ATrDevice *dev = getCurrentDeviceHelper();
		if (dev) return dev->GetAmmoCount();

		return -1;
	}
	int ammoCarried()
	{
		ATrDevice *dev = getCurrentDeviceHelper();
		if (dev) return dev->m_nCarriedAmmo;

		return -1;
	}
	int ammoTotal()
	{
		ATrDevice *dev = getCurrentDeviceHelper();
		if (dev) return dev->GetAmmoCount() + dev->m_nCarriedAmmo;

		return -1;
	}
	unsigned char equippedAt()
	{
		ATrDevice *dev = getCurrentDeviceHelper();
		if (dev) return dev->r_eEquipAt;

		return EQP_NONE;
	}
	FString name()
	{
		ATrDevice *dev = getCurrentDeviceHelper();
		if (dev) return dev->ItemName;

		return L"unknown";
	}
}
namespace getGameData
{
	std::string type()
	{
		if (Utils::tr_pc && Utils::tr_pc->WorldInfo && Utils::tr_pc->WorldInfo->GetGameClass())
			return ((ATrGame *)Utils::tr_pc->WorldInfo->GetGameClass())->GetStringName();

		return "none";
	}
	std::string timeStr()
	{
		if (Utils::tr_pc && Utils::tr_pc->WorldInfo && Utils::tr_pc->WorldInfo->GRI)
		{
			char c[6];
			int *time = &Utils::tr_pc->WorldInfo->GRI->RemainingTime;
			sprintf(c, "%02d:%02d", *time / 60, *time % 60);
			return c;
			FString asd = L"asd";
		}
		return "00:00";
	}
	bool isOfflinePlay()
	{
		if (Utils::tr_pc && Utils::tr_pc->WorldInfo)
			return Utils::tr_pc->WorldInfo->NetMode == 0 ? true : false;

		return true;
	}
	bool isGameEnd()
	{
		if (Utils::tr_pc && Utils::tr_pc->WorldInfo && Utils::tr_pc->WorldInfo->Game)
			return Utils::tr_pc->WorldInfo->Game->bGameEnded;

		return false;
	}
	bool isGenUp(unsigned int n)
	{
		if (Utils::tr_pc && Utils::tr_pc->WorldInfo->GRI)
			return ((ATrGameReplicationInfo *)Utils::tr_pc->WorldInfo->GRI)->GeneratorPower[n] != 0;

		return false;
	}
	bool isWarmUp()
	{
		if (Utils::tr_pc && Utils::tr_pc->WorldInfo->GRI)
			return ((ATrGameReplicationInfo *)Utils::tr_pc->WorldInfo->GRI)->bWarmupRound;

		return false;
	}
	bool isOverTime()
	{
		if (Utils::tr_pc && Utils::tr_pc->WorldInfo && Utils::tr_pc->WorldInfo->Game)
			return Utils::tr_pc->WorldInfo->Game->bOverTime;

		return false;
	}
	int genAutoRepairTime(unsigned int n)
	{
		if (Utils::tr_pc && Utils::tr_pc->WorldInfo->GRI)
			return ((ATrGameReplicationInfo *)Utils::tr_pc->WorldInfo->GRI)->GeneratorDowntime[n];

		return 0;
	}
	int overTimeLimit()
	{
		if (Utils::tr_pc && Utils::tr_pc->WorldInfo && Utils::tr_pc->WorldInfo->GRI &&
			((ATrGameReplicationInfo *)Utils::tr_pc->WorldInfo->GRI)->r_ServerConfig)
			return ((ATrGameReplicationInfo *)Utils::tr_pc->WorldInfo->GRI)->r_ServerConfig->OvertimeLimit;

		return 0;
	}
	int score(unsigned int n)
	{
		if (Utils::tr_pc && Utils::tr_pc->WorldInfo && Utils::tr_pc->WorldInfo->GRI &&
			(unsigned)Utils::tr_pc->WorldInfo->GRI->Teams.Num() > n &&
			Utils::tr_pc->WorldInfo->GRI->Teams.Data[n])
			return (int)Utils::tr_pc->WorldInfo->GRI->Teams.Data[n]->Score;

		return 0;
	}
	int scoreLimit()
	{
		if (Utils::tr_pc && Utils::tr_pc->WorldInfo && Utils::tr_pc->WorldInfo->GRI &&
			((ATrGameReplicationInfo *)Utils::tr_pc->WorldInfo->GRI)->r_ServerConfig)
			return ((ATrGameReplicationInfo *)Utils::tr_pc->WorldInfo->GRI)->r_ServerConfig->ScoreLimit;

		return 0;
	}
	int time()
	{
		if (Utils::tr_pc && Utils::tr_pc->WorldInfo && Utils::tr_pc->WorldInfo->GRI)
			return Utils::tr_pc->WorldInfo->GRI->RemainingTime;

		return 0;
	}
	int timeLimit()
	{
		if (Utils::tr_pc && Utils::tr_pc->WorldInfo && Utils::tr_pc->WorldInfo->GRI)
			return Utils::tr_pc->WorldInfo->GRI->TimeLimit;

		return 0;
	}
}
namespace getFlagData
{
	bool isHome(unsigned int n)
	{
		if (Utils::tr_pc && Utils::tr_pc->WorldInfo && Utils::tr_pc->WorldInfo->GRI &&
			((ATrGameReplicationInfo *)Utils::tr_pc->WorldInfo->GRI)->m_Flags[n])
			return ((ATrGameReplicationInfo *)Utils::tr_pc->WorldInfo->GRI)->m_Flags[n]->bHome;

		return true;
	}
	int returnTime(unsigned int n)
	{
		if (Utils::tr_pc && Utils::tr_pc->WorldInfo && Utils::tr_pc->WorldInfo->GRI &&
			((ATrGameReplicationInfo *)Utils::tr_pc->WorldInfo->GRI)->FlagReturnTime[n])
			return ((ATrGameReplicationInfo *)Utils::tr_pc->WorldInfo->GRI)->FlagReturnTime[n];

		return 0;
	}
	FString holderName(unsigned int n)
	{
		if (Utils::tr_pc && Utils::tr_pc->WorldInfo && Utils::tr_pc->WorldInfo->GRI &&
			((ATrGameReplicationInfo *)Utils::tr_pc->WorldInfo->GRI)->m_Flags[n] &&
			((ATrGameReplicationInfo *)Utils::tr_pc->WorldInfo->GRI)->m_Flags[n]->HolderPRI)
			return ((ATrGameReplicationInfo *)Utils::tr_pc->WorldInfo->GRI)->m_Flags[n]->HolderPRI->PlayerName;

		return L" ";
	}
}

/*
	IsShielded() for PlayerInfo
	Fix vehicle/seat detection
	Class
	Rabbit / CaH stats (other gametypes as well?)
	Deployables
	Stopwatch
	LerpColor function
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
	Spectator stuff -> TrPlayerOwner.InRovingSpectate()? plus team 255`
*/

void drawCustomHUD(ATrHUD *that)
{
	if (that->Canvas)
	{
		bool practiceMode = getGameData::isOfflinePlay();
		unsigned char myTeam = getPlayerData::teamNum();
		std::string gameType = getGameData::type();

		wchar_t buff[40];

		FColor white = { 255, 255, 255, 255 };
		FColor black = { 0, 0, 0, 75 };
		FColor black2 = { 0, 0, 0, 50 };

		// Game timer
		Utils::drawRect(657.0f, 0.0f, 783.0f, 40.0f, black, that->Canvas);
		wsprintf(buff, L"%02d:%02d", getGameData::time() / 60, getGameData::time() % 60);
		Utils::drawText(buff, white, 720.0f, 22.0f, 1, 2, that, 2.0f, 2.0f);

		// Score/Flag HUD
		if (gameType == "TrGame_TRCTF" || gameType == "TrGame_TrCTFBlitz")
		{
			FColor colBE = { 0, 0, 240, 100 };
			FColor colDS = { 255, 202, 0, 100 };
			FColor colBEText = { 0, 0, 240, 255 };
			FColor colDSText = { 255, 202, 0, 255 };

			// BE
			Utils::drawRect(587.0f, 0.0f, 657.0f, 37.0f, colBE, that->Canvas);
			if (myTeam == 0)
				Utils::drawRect(587.0f, 37.0f, 657.0f, 39.0f, { 200, 200, 200, 220 }, that->Canvas);
			wsprintf(buff, L"%d", getGameData::score(0));
			Utils::drawText(buff, white, 622.0f, 20.0f, 1, 2, that, 1.5f, 1.5f);
			// DS
			Utils::drawRect(783.0f, 0.0f, 853.0f, 37.0f, colDS, that->Canvas);
			if (myTeam == 1)
				Utils::drawRect(783.0f, 37.0f, 853.0f, 39.0f, { 200, 200, 200, 220 }, that->Canvas);
			wsprintf(buff, L"%d", getGameData::score(1));
			Utils::drawText(buff, white, 818.0f, 20.0f, 1, 2, that, 1.5f, 1.5f);

			// Flags
			if (!getFlagData::isHome(0))
			{
				int returnTime = getFlagData::returnTime(0);
				if (returnTime > 0)
				{
					wsprintf(buff, L"%d", returnTime);
					Utils::drawText(buff, colBEText, 577.0f, 20.0f, 2, 2, that, 1.5f, 1.5f);
				}
				else
					Utils::drawText(getFlagData::holderName(0), colDSText, 577.0f, 20.0f, 2, 2, that, 1.0f, 1.0f);
			}
			if (!getFlagData::isHome(1))
			{
				int returnTime = getFlagData::returnTime(1);
				if (returnTime > 0)
				{
					wsprintf(buff, L"%d", returnTime);
					Utils::drawText(buff, colDSText, 863.0f, 20.0f, 0, 2, that, 1.5f, 1.5f);
				}
				else
					Utils::drawText(getFlagData::holderName(1), colBEText, 863.0f, 20.0f, 0, 2, that, 1.0f, 1.0f);
			}
			// Gens
			if (getGameData::isGenUp(0))
				Utils::drawText(L"G", colBEText, 622.0f, 50.0f, 1, 2, that, 1.0f, 1.0f);
			else
			{
				int genTimer = getGameData::genAutoRepairTime(0);
				if (genTimer != 0)
				{
					wsprintf(buff, L"%d:%02d", genTimer / 60, genTimer % 60);
					Utils::drawText(buff, colBEText, 622.0f, 50.0f, 1, 2, that, 1.0f, 1.0f);
				}
			}
			if (getGameData::isGenUp(1))
				Utils::drawText(L"G", colDSText, 818.0f, 50.0f, 1, 2, that, 1.0f, 1.0f);
			else
			{
				int genTimer = getGameData::genAutoRepairTime(1);
				if (genTimer != 0)
				{
					wsprintf(buff, L"%d:%02d", genTimer / 60, genTimer % 60);
					Utils::drawText(buff, colDSText, 818.0f, 50.0f, 1, 2, that, 1.0f, 1.0f);
				}
			}
		}

		// Health/Energy/Speed
		if (getPlayerData::isAlive())
		{
			int h = getPlayerData::health();
			int e = getPlayerData::energy();
			int s = getPlayerData::speed();
			float hPct = (float)h / (float)getPlayerData::healthMax();
			float ePct = (float)e / (float)getPlayerData::energyMax();

			float cSizeX = (float)that->Canvas->SizeX;
			float cSizeY = (float)that->Canvas->SizeY;

			FVector2D locHealth = { cSizeX * 49.0f / 100, cSizeY * 94.5f / 100 };
			FVector2D locEnergy = { cSizeX * 51.0f / 100, cSizeY * 94.5f / 100 };
			FVector2D locSpeed = { cSizeX * 50.0f / 100, cSizeY * 80.0f / 100 };

			FColor cH = that->LerpColor({ 0, 0, 255, 255 }, { 0, 255, 0, 255 }, hPct);
			FColor cE = that->LerpColor({ 141, 141, 255, 255 }, { 255, 255, 179, 255 }, ePct);

			Utils::drawRect(313.0f, 1037.0f, 719.0f, 1063.0f, black2, that->Canvas);
			Utils::drawBox(313.0f, 1037.0f, 719.0f, 1063.0f, black, that->Canvas);
			Utils::drawProgressBar(316.0f, 1040.0f, 716.0f, 1060.0f, { cH.B, cH.G, cH.R, 125 }, 3, hPct, that->Canvas);
			Utils::drawRect(721.0f, 1037.0f, 1127.0f, 1063.0f, black2, that->Canvas);
			Utils::drawBox(721.0f, 1037.0f, 1127.0f, 1063.0f, black, that->Canvas);
			Utils::drawProgressBar(724.0f, 1040.0f, 1124.0f, 1060.0f, { cE.B, cE.G, cE.R, 125 }, 1, ePct, that->Canvas);

			// Health
			wsprintf(buff, L"%d", h);
			Utils::drawText(buff, cH, locHealth.X, locHealth.Y, 2, 2, that, 2.0f, 2.0f);

			// Energy
			wsprintf(buff, L"%d", e);
			Utils::drawText(buff, cE, locEnergy.X, locEnergy.Y, 0, 2, that, 2.0f, 2.0f);

			// Speed
			if (s > 0)
			{
				wsprintf(buff, L"%d", s);
				Utils::drawText(buff, white, locSpeed.X, locSpeed.Y, 1, 2, that, 1.0f, 1.0f);
			}

			// Ammo
			FColor cA = getCurrentWeaponData::isLowAmmo() ? FColor{ 0, 0, 255, 255 } : white;
			if (getCurrentWeaponData::isReloading())
				wsprintf(buff, L"-- %d --", getCurrentWeaponData::ammo());
			else
				wsprintf(buff, L"%d", getCurrentWeaponData::ammo());
			Utils::drawText(buff, cA, 720.0f, 600.0f, 1, 2, that, 1.5f, 1.5f);
			if (!getCurrentWeaponData::isSingleShotWeapon())
			{
				wsprintf(buff, L"%d", getCurrentWeaponData::ammoCarried());
				Utils::drawText(buff, white, 720.0f, 622.0f, 1, 2, that, 1.0f, 1.0f);
			}

			// Flag
			if (getPlayerData::hasFlag())
				Utils::drawText(L"F L A G", { 168, 234, 168, 255 }, 720.0f, 180.0f, 1, 2, that, 2.0f, 2.0f);

			// Rage
			if (getPlayerData::isRaged())
				Utils::drawText(L"R A G E", { 0, 0, 255, 255 }, 720.0f, 220.0f, 1, 2, that, 2.0f, 2.0f);
		}
		else
		{
			if (myTeam != 255)
			{
				// Respawn timer
				int respawnTime = getPlayerData::respawnTime();
				if (respawnTime > 0)
				{
					wsprintf(buff, L"%d", respawnTime);
					Utils::drawText(buff, white, 720.0f, 340.0f, 1, 2, that, 1.5f, 1.5f);
				}
			}
		}
	}
}