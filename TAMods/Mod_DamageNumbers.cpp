#include "Mods.h"


bool TrPC_ClientShowOverheadNumber(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	ATrPlayerController *that = (ATrPlayerController *)dwCallingObject;

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
		g_config.damageNumberStreamValue += ((ATrPlayerController_execClientShowOverheadNumber_Parms *)pParams)->NumberToShow;
		((ATrPlayerController_execClientShowOverheadNumber_Parms *)pParams)->NumberToShow = g_config.damageNumberStreamValue;
	}

	//Count for rainbow int
	if (g_config.showRainbow == true){
		if (g_config.rainbowBulletInt <= 12){
			g_config.rainbowBulletInt++;
		}
		else
		{
			g_config.rainbowBulletInt = 0;
		}
	}
	
	g_config.damageNumberStreamCount++;

	if (g_config.showChainBulletHitCount) {
		((ATrPlayerController_execClientShowOverheadNumber_Parms *)pParams)->NumberToShow = g_config.damageNumberStreamCount;
	}

	if (((ATrPlayerController_execClientShowOverheadNumber_Parms *)pParams)->NumberToShow <= g_config.damageNumbersLimit)
		return (true);
	return (false);
}

