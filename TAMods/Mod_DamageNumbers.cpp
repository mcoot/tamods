#include "Mods.h"

bool TrPC_ClientShowOverheadNumber(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	ATrPlayerController *that = (ATrPlayerController *)dwCallingObject;

	// Store the current clock time to compare with the last hit
	clock_t curClock = clock();

	// If more than half a second has passed since the last hit, the stream has ended
	bool stream_ended = ((double)(curClock-g_config.lastDamageNumberShowEventTime) > (CLOCKS_PER_SEC*g_config.damageNumberStreamingResetTime));

	g_config.lastDamageNumberShowEventTime = curClock;

	// Reset the damage stream if the stream has ended
	if (stream_ended) {
		g_config.damageNumberStreamValue = 0;
		g_config.damageNumberStreamCount = 0;
	}
	
	if (g_config.showDamageNumberStream) {
		// Set the damage number to the streamed value if damage streaming is on
		g_config.damageNumberStreamValue += ((ATrPlayerController_execClientShowOverheadNumber_Parms *)pParams)->NumberToShow;
		((ATrPlayerController_execClientShowOverheadNumber_Parms *)pParams)->NumberToShow = g_config.damageNumberStreamValue;
	}

	if (g_config.showChainBulletHitCount) {
		g_config.damageNumberStreamCount++;
		((ATrPlayerController_execClientShowOverheadNumber_Parms *)pParams)->NumberToShow = g_config.damageNumberStreamCount;
	}

	if (((ATrPlayerController_execClientShowOverheadNumber_Parms *)pParams)->NumberToShow <= g_config.damageNumbersLimit)
		return (true);
	return (false);
}
