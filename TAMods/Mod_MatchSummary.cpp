#include "Mods.h"

void TrSummaryHelper_GetRankFromXP(UTrSummaryHelper* that, UTrSummaryHelper_execGetRankFromXP_Parms* params, UClass** result) {
	*result = Data::getRankByXp(params->XP);
}

static void generatePlayerSummary(UGFxTrMenuMoviePlayer* mp, UGFxTrScene_PlayerSummary* p, ATrPlayerController* pc) {
	if (!pc->PlayerReplicationInfo) return;
	ATrPlayerReplicationInfo* pri = (ATrPlayerReplicationInfo*)pc->PlayerReplicationInfo;

	p->PlayerID = pri->PlayerID;
	p->Kills = pri->Kills;
	p->Deaths = pri->Deaths;
	p->Assists = pri->m_nAssists;
	p->Credits = pri->m_nCreditsEarned;
	p->PlayerName = pri->PlayerName;

	// TODO: XP
	
	if (mp->PlayerProfile) {
		int newTotalXp = Data::getXpFromPlayerProfile(mp->PlayerProfile);

		p->RankBase = g_GlobalState.matchStartXp;
		p->RankGained = newTotalXp - g_GlobalState.matchStartXp;
		p->XPBase = p->RankGained;
	}

	// TODO: First Win of the Day

	// TODO: Accolades and awards

	p->AddMiscData();
}

static void generateMatchSummary(UGFxTrMenuMoviePlayer* mp, UGFxTrScene_MatchSummary* m, ATrPlayerController* pc) {
	if (!pc->myHUD || !pc->WorldInfo || !pc->WorldInfo->GRI) return;

	ATrGameReplicationInfo* gri = (ATrGameReplicationInfo*)pc->WorldInfo->GRI;
	ATrHUD* hud = (ATrHUD*)pc->myHUD;

	m->WinningTeam = hud->m_nWinningTeam;
	m->MatchDuration = gri->ElapsedTime;

	m->Team1Score = (int)gri->Teams.GetStd(0)->Score;
	m->Team2Score = (int)gri->Teams.GetStd(1)->Score;

	// Reverse look up map id by name
	std::string mapName = Utils::f2std(pc->WorldInfo->GetMapName(true));
	int mapId = 0;
	for (auto& it : Data::map_id_to_filename) {
		if (mapName == it.second) {
			mapId = it.first;
			break;
		}
	}

	if (mapId != 0) {
		m->MatchMapId = mapId;
	}

	// TODO: Accolades and awards
}

bool TrPlayerController_ClientFadeToSummary(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult) {
	if (g_TAServerControlClient.isKnownToBeModded() && Utils::tr_pc && Utils::tr_menuMovie) {
		UGFxTrScene_PlayerSummary* p = Utils::tr_menuMovie->PlayerSummaryScene;
		UGFxTrScene_MatchSummary* m = Utils::tr_menuMovie->MatchSummaryScene;

		// Get all data
		generatePlayerSummary(Utils::tr_menuMovie, p, Utils::tr_pc);
		generateMatchSummary(Utils::tr_menuMovie, m, Utils::tr_pc);

		// Tell the UI it is ready to go
		p->eventSummaryReady();
		m->eventSummaryReady();

		Utils::tr_menuMovie->TweenPlayerSummary();
	}

	return true;
}