#include "Mods.h"

static bool midairKill = false;

void playHitSound(bool bShieldDamage, int *dmg)
{
	static clock_t lastHitSound = 0;
	static unsigned int totalDamage = 0;

	if (!g_config.s_hitSound.audioAvailable() ||
		g_config.hitSoundMode < 1 ||
		!dmg ||
		*dmg <= 0 ||
		bShieldDamage)
		return;

	if ((double)(clock() - lastHitSound) < (CLOCKS_PER_SEC*0.05))
		totalDamage += *dmg;
	else
		totalDamage = *dmg;

	lastHitSound = clock();

	float pitch = 1.0f;

	if (g_config.hitSoundMode > 1)
	{
		// high damage --> low pitch
		if (g_config.hitSoundMode == 2)
			pitch = (float)g_config.hitSoundDamageRef / (float)totalDamage;
		// high damage --> high pitch
		else if (g_config.hitSoundMode >= 3)
			pitch = (float)totalDamage / (float)g_config.hitSoundDamageRef;

		if (pitch > g_config.hitSoundPitchMax)
			pitch = g_config.hitSoundPitchMax;
		else if (pitch < g_config.hitSoundPitchMin)
			pitch = g_config.hitSoundPitchMin;
	}
	g_config.s_hitSound.Play(pitch);
}

void playHeadShotSound()
{
	if (g_config.s_headShot.audioAvailable())
		g_config.s_headShot.Play();
}

bool TrPC_ClientPlayBluePlateImpact(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	midairKill = true;

	if(g_config.recordStats == true) g_stats.midairKills++;

	if (g_config.s_bluePlate.audioAvailable())
	{
		g_config.s_hitSound.Stop();
		g_config.s_bluePlate.Play();
		return true;
	}
	return false;
}

bool TrPC_ClientPlayAirMailImpact(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	midairKill = true;

	if (g_config.recordStats == true) g_stats.midairKills++;

	if (g_config.s_airMail.audioAvailable())
	{
		g_config.s_hitSound.Stop();
		g_config.s_airMail.Play();
		return true;
	}
	return false;
}

bool TrPRI_ReplicatedEvent(int id, UObject *dwCallingObject, UFunction* pFunction, void* pParams, void* pResult)
{
	ATrPlayerReplicationInfo *pri = (ATrPlayerReplicationInfo *)dwCallingObject;
	ATrPlayerReplicationInfo_eventReplicatedEvent_Parms *params = (ATrPlayerReplicationInfo_eventReplicatedEvent_Parms *)pParams;

	if (pri->IsLocalPlayerPRI() && std::string(params->VarName.GetName()) == "m_nKills")
	{
		if (g_config.s_killSound.audioAvailable() && !midairKill)
		{
			g_config.s_hitSound.Stop();
			g_config.s_killSound.Play();
		}
		else
			midairKill = false;
	}
	return false;
}