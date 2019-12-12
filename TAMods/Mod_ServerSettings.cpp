#include "Mods.h"

bool TrGame_TRCTF_PostBeginPlay(int ID, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
    ATrGame *game = (ATrGame *)dwCallingObject;

    if (game->WorldInfo && game->WorldInfo->NetMode == 0)
    {
        ATrServerSettingsInfo *settings = ((ATrGameReplicationInfo *)game->GameReplicationInfo)->r_ServerConfig;

        settings->RespawnTime = 0;
        settings->TeamAssignType = 1; // TAT_UNBALANCED

        settings->MaxSpeedWithFlagHeavy = g_config.maxSpeedWithFlag;
        settings->MaxSpeedWithFlagLight = g_config.maxSpeedWithFlag;
        settings->MaxSpeedWithFlagMedium = g_config.maxSpeedWithFlag;
        settings->DecelerationRateWithFlag = g_config.decelerationRateWithFlag;

        settings->bGeneratorAutoRegen = false;
        settings->bPoweredDeployables = false;

        settings->bFriendlyFire = true;
        settings->bFriendlyFireBaseAssets = true;
        settings->bFriendlyFireDeployables = true;
        
        game->ApplyServerSettings();
        game->m_bShouldAutoBalance = false;
    }

    return false;
}