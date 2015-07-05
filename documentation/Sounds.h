/** @file */

/**
A permanently muted player, with individual options to mute different kind of messages
*/
struct MutedPlayer
{
	/**
	The username of the player
	*/
	string username;
	/**
	If the chat messages of the player should be muted
	*/
	bool muteText;
	/**
	If VGS of the player should be muted
	*/
	bool muteVGS;
	/**
	If PMs of the player should be muted
	*/
	bool muteDirectMessage;
};

/**
Create a MutedPlayer object muting everything for a given player

@param username	The name of the player to mute
@return			The created MutedPlayer object
*/
MutedPlayer mplayer(string username);

/**
Create a custom MutedPlayer object for a given player

@param username	The name of the player to mute
@param vgs		If the player's VGS should be muted
@param text		If the player's text messages should be muted
@param pm		If the player's private messages should be muted
@return			The created MutedPlayer object
*/
MutedPlayer mplayer_custom(string username, bool vgs, bool text, bool pm);

/**
Mute a player using the given MutedPlayer object

@param muted_player	The object to use to mute the player
*/
void mutePlayer(MutedPlayer muted_player);

/**
The mode to use for custom hitsounds

The custom sound has to be located in your config folder, in the "sounds" subfolder as "hit.wav"

0: no custom hitsounds, use default one

1: static custom hitsound, at 1.0 pitch

2: dynamic custom hitsounds, depending on the damage dealt. Higher damage results in lower pitch

3: reverse dynamic custom hitsounds, depending on the damage dealt. Higher damage results in lower pitch
*/
number hitSoundMode;

/**
If a custom sound should be used for air mails

The sound has to be in yout config folder, in the "sounds" subfolder as "airmail.wav"
*/
boolean customAirMailSound;

/**
If a custom sound should be used for blue plates

The sound has to be in yout config folder, in the "sounds" subfolder as "blueplate.wav"
*/
boolean customBluePlateSound;

/**
The minimal pitch used for the dynamic hitsounds
*/
number hitSoundPitchMin;

/**
The maximal pitch used for the dynamic hitsounds
*/
number hitSoundPitchMax;

/**
Reference damage, used for dynamic hitsounds pitch computation

The default value is at 600
*/
number hitSoundDamageRef;

/**
The volume used to play hitsounds, used by both vanilla and custom sounds

Set this value to 0 to disable hitsounds
*/
number volumeHitSound;

/**
The volume used to play headshots
*/
number volumeHeadShot;

/**
The volume used to play the blue plate sound
*/
number volumeBluePlate;

/**
The volume used to play the air mail sound
*/
number volumeAirMail;
