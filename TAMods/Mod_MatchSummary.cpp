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
	p->TopPlayedClass = 0;

	// TODO: XP
	
	int newTotalXp = 0;
	if (mp->PlayerProfile) {
		newTotalXp = Data::getXpFromPlayerProfile(mp->PlayerProfile);
	}
	p->RankBase = g_GlobalState.matchStartXp;
	p->RankGained = newTotalXp - g_GlobalState.matchStartXp;
	p->XPBase = p->RankGained;
	p->XPPerf = 1;
	p->XPVIP = 1;
	p->XPBoost = 1;
	p->EarnedBadgeValue = 1;

	// TODO: First Win of the Day


	// TODO: Accolades, awards and badges
	// Always add match finished accolade
	// Summary screen breaks with no accolades!
	FPropertyPair matchFinishedPair = { CONST_STAT_ACO_GAME_COMPLETE, 1 };
	p->accoladeData.Add(matchFinishedPair);
	// Add earned accolades
	Logger::log("Accolades: %d", g_GlobalState.accoladesThisMatch.size());
	for (auto& it : g_GlobalState.accoladesThisMatch) {
		FPropertyPair accPair = { it.first, it.second.Count };
		p->accoladeData.Add(accPair);
	}
	
	// Clear out accolades now they've been sent to the summary
	g_GlobalState.accoladesThisMatch.clear();

	//FPropertyPair acc1 = { 203030, 1 };
	//FPropertyPair acc2 = { 203031, 1 };
	//FPropertyPair acc3 = { 203044, 1 };
	//FPropertyPair acc4 = { 203045, 1 };

	//p->accoladeData.Add(acc1);
	//p->accoladeData.Add(acc2);
	//p->accoladeData.Add(acc3);
	//p->accoladeData.Add(acc4);

	//FPropertyPair award1 = { 204001, 2750 };
	//FPropertyPair award2 = { 204007, 104 };
	//FPropertyPair award3 = { 204013, 19 };
	//FPropertyPair award4 = { 204014, 81 };
	//FPropertyPair award5 = { 204015, 237 };

	//p->AwardData.Add(award1);
	//p->AwardData.Add(award2);
	//p->AwardData.Add(award3);
	//p->AwardData.Add(award4);
	//p->AwardData.Add(award5);
}

static void generateMatchSummary(UGFxTrMenuMoviePlayer* mp, UGFxTrScene_MatchSummary* m, ATrPlayerController* pc) {
	if (!pc->myHUD || !pc->WorldInfo || !pc->WorldInfo->GRI) return;

	ATrGameReplicationInfo* gri = (ATrGameReplicationInfo*)pc->WorldInfo->GRI;
	ATrHUD* hud = (ATrHUD*)pc->myHUD;

	m->WinningTeam = hud->m_nWinningTeam;
	// TODO: Fix time, it currently includes warmup
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
	if (!g_TAServerControlClient.isKnownToBeModded()) {
		return false;
	}

	if (!Utils::tr_pc || !Utils::tr_menuMovie) {
		Utils::tr_menuMovie->ASC_LoadPlayerSummary();
		return true;
	}

	Utils::tr_menuMovie->PlayerSummaryScene->bFirstWin = Utils::tr_pc->r_bDailyCompleted;

	UGFxTrScene_PlayerSummary* p = Utils::tr_menuMovie->PlayerSummaryScene;
	UGFxTrScene_MatchSummary* m = Utils::tr_menuMovie->MatchSummaryScene;

	// Clear out any old summary
	// Manually clear out the arrays to avoid crashes
	p->AwardData.Clear();
	p->accoladeData.Clear();
	p->eventClearSummary();

	m->MVPAwards.Clear();
	m->MVPAccolades.Clear();
	m->eventClearSummary();

	// Get all data
	generatePlayerSummary(Utils::tr_menuMovie, p, Utils::tr_pc);
	generateMatchSummary(Utils::tr_menuMovie, m, Utils::tr_pc);

	// Tell the UI it is ready to go
	p->eventSummaryReady();
	m->eventSummaryReady();

	// Force loading
	return true;
}

void GFxTrMenuMoviePlayer_TweenPlayerSummary(UGFxTrMenuMoviePlayer* that, UGFxTrMenuMoviePlayer_execTweenPlayerSummary_Parms* params) {
	// Blackhole the normal tween, it's happening too early
	//that->ActionScriptVoid(L"loadAccoladeData");
	//that->ActionScriptVoid(L"animateXpBar");
}

static int dataLoadDelegatesRemaining = 3;
static void handlePlayerSummaryDataLoadFunc(UGFxTrScene_PlayerSummary* that) {
	if (!g_TAServerControlClient.isKnownToBeModded() || !Utils::tr_pc || !that->Outer) return;

	UGFxTrMenuMoviePlayer* mp = (UGFxTrMenuMoviePlayer*)that->Outer;
	if (dataLoadDelegatesRemaining <= 1) {
		// Reset counter for next map
		dataLoadDelegatesRemaining = 3;
		// Last delegate, so ready to start player summary tween
		mp->ActionScriptVoid(L"asc_TweenPlayerSummary");
	}
	else {
		// Wait until other data load delegates are done
		dataLoadDelegatesRemaining--;
	}
}

bool GFxTrScene_PlayerSummary_LoadPlayerAccoladeData(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult) {
	UGFxTrScene_PlayerSummary* that = (UGFxTrScene_PlayerSummary*)dwCallingObject;
	handlePlayerSummaryDataLoadFunc(that);

	return true;
}

bool GFxTrScene_PlayerSummary_LoadPlayerMiscData(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult) {
	UGFxTrScene_PlayerSummary* that = (UGFxTrScene_PlayerSummary*)dwCallingObject;
	handlePlayerSummaryDataLoadFunc(that);

	return true;
}

bool GFxTrScene_PlayerSummary_LoadPlayerStatsData(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult) {
	UGFxTrScene_PlayerSummary* that = (UGFxTrScene_PlayerSummary*)dwCallingObject;
	handlePlayerSummaryDataLoadFunc(that);

	return true;
}

bool GFxTrScene_PlayerSummary_LoadXPData(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult) {
	// This one doesn't seem to actually happen
	UGFxTrScene_PlayerSummary* that = (UGFxTrScene_PlayerSummary*)dwCallingObject;
	handlePlayerSummaryDataLoadFunc(that);

	return true;
}