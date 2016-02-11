#include "Mods.h"

unsigned char nHitEnemyHeadshot = 0;

static void TrHUD_addOverheadNumber(ATrHUD *that, int value, FVector4 loc, bool is_shield)
{
	FOverheadNumber overhead(value, that->m_fOverheadNumberTotalTime, loc, is_shield);
	overhead.CurrentColor = is_shield ? that->m_OverheadNumberColorShieldMin : that->m_OverheadNumberColorMin;
	that->m_OverheadNumbers.Add(overhead);
}

bool TrPC_ClientShowOverheadNumber(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	ATrPlayerController *that = (ATrPlayerController *)dwCallingObject;
	ATrPlayerController_execClientShowOverheadNumber_Parms *params = (ATrPlayerController_execClientShowOverheadNumber_Parms *)pParams;
	FVector4 loc(params->WorldLocation.X, params->WorldLocation.Y, params->WorldLocation.Z, params->fScreenDepth);

	if (g_config.revertOriginalDamageNumbers)
		loc.Z -= ((UTrDmgType_Bullet *)UTrDmgType_Bullet::StaticClass()->Default)->m_v2DDamageNumbersMinMaxZ.X;

	// Hit sounds
	playHitSound((bool)params->bShieldDamage, &params->NumberToShow);

	// Headshots
	if (nHitEnemyHeadshot != that->r_nHitEnemyHeadshot)
	{
		playHeadShotSound();
		nHitEnemyHeadshot = that->r_nHitEnemyHeadshot;
	}

	//Stats Stuff, TODO this should be hooked onto event TakeDamage instead
	if (g_config.recordStats == true){
		g_stats.bulletsHit++;
	}

	if (loc.W == 0.0f)
		loc.W = params->WorldLocation.Z;

	if (that->myHUD && g_config.onDamageNumberCreate && !g_config.onDamageNumberCreate->isNil() && g_config.onDamageNumberCreate->isFunction())
	{
		TArray<FOverheadNumber> *overheads = &((ATrHUD *)that->myHUD)->m_OverheadNumbers;
		try
		{
			(*g_config.onDamageNumberCreate)(overheads, params->NumberToShow, loc, (bool) params->bShieldDamage);
		}
		catch (const LuaException &e)
		{
			Utils::console("LuaException: %s", e.what());
		}
		return true;
	}

	// Store the current clock time to compare with the last hit
	clock_t curClock = clock();

	// If more than half a second has passed since the last hit, the stream has ended
	bool stream_ended = ((double)(curClock-g_config.lastDamageNumberShowEventTime) > (CLOCKS_PER_SEC*g_config.damageNumberStreamTimeout));

	g_config.lastDamageNumberShowEventTime = curClock;

	// Reset the damage stream if the stream has ended
	if (stream_ended) {
		g_config.damageNumberStreamValue = 0;
		g_config.damageNumberStreamCount = 0;
	}
	
	if (g_config.showDamageNumberStream) {
		// Set the damage number to the streamed value if damage streaming is on
		g_config.damageNumberStreamValue += params->NumberToShow;
		params->NumberToShow = g_config.damageNumberStreamValue;
	}

	//Count for rainbow int
	if (g_config.showRainbow == true)
		g_config.rainbowBulletInt = (g_config.rainbowBulletInt + 1) % 12;
	
	g_config.damageNumberStreamCount++;

	if (g_config.showChainBulletHitCount) 
		params->NumberToShow = g_config.damageNumberStreamCount;

	if (params->NumberToShow <= g_config.damageNumbersLimit)
		return true;
	TrHUD_addOverheadNumber((ATrHUD *)that->myHUD, params->NumberToShow, loc, params->bShieldDamage);
	return true;
}

