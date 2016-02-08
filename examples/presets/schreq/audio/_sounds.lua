------------------------------------------------------------------------------
-- Sound modifications
------------------------------------------------------------------------------
--modifySoundRe("(\\.AmbientSound|CreditsSound|IdleProjectile|Speed_1P)", 1.0, 0.0)
modifySoundRe("(\\.AmbientSound|CreditsSound|IdleProjectile)", 1.0, 0.0)
--modifySoundRe("(NovaColt|Pistol)_3P_Fire", 0.8, 1.0)
--modifySoundRe("shotgun.*fire", 0.7, 1.2)
------------------------------------------------------------------------------


------------------------------------------------------------------------------
-- Hit and kill sounds
------------------------------------------------------------------------------
-- Whether or not to play custom hit sounds.
-- This can take the following values:
--  0: Off - Play the vanilla hit sounds.
--  1: Static custom hit sounds.
--  2: Dynamic pitch hit sounds. Pitch decreases with damage.
--  3: Dynamic pitch hit sounds. Pitch increases with damage.
hitSoundMode              = 2

-- The minimum pitch limit to play the hit sound at.
hitSoundPitchMin          = 0.6

-- The maximum pitch limit to play the hit sound at.
hitSoundPitchMax          = 1.4

-- The reference damage for calculating when to lower and when to raise
-- the pitch. At a value of 600, dealing 1200 damage would - depending on
-- the mode - play the hitsound at half (0.5) or double (2.0) pitch.
hitSoundDamageRef         = 600

-- Play the custom or the vanilla hit sound.
soundHit                  = preset .. "audio/hit.wav"

-- Play the custom or the vanilla headshot hit sound.
soundHeadShot             = preset .. "audio/headshot.wav"

-- Play a custom sound when you kill someone.
soundKill                 = preset .. "audio/kill.wav"

-- Play the custom or the vanilla airmail sound.
soundAirMail              = preset .. "audio/airmail.wav"

-- Play the custom or the vanilla blueplate sound.
soundBluePlate            = preset .. "audio/blueplate.wav"

-- This controls the volume of whichever hit sound is on.
volumeHit                 = 0.3

-- This controls the volume of whichever headshot sound is on.
volumeHeadShot            = 0.5

-- This controls the volume of the kill sound.
volumeKill                = 0.5

-- This controls the volume of whichever airmail sound is on.
volumeAirMail             = 1.0

-- This controls the volume of whichever blueplate sound is on.
volumeBluePlate           = 1.0
------------------------------------------------------------------------------


------------------------------------------------------------------------------
-- Accolade award sounds
--
-- Enable/disable custom sounds for accolade awards and set their volume.
------------------------------------------------------------------------------
-- Killing Spree Accolade.
soundStreak1              = preset .. "audio/streak1.wav"
volumeStreak1             = 0.15
-- Rampage Accolade.
soundStreak2              = preset .. "audio/streak2.wav"
volumeStreak2             = 0.15
-- Unstoppable Accolade.
soundStreak3              = preset .. "audio/streak3.wav"
volumeStreak3             = 0.15
-- Relentless Accolade.
soundStreak4              = preset .. "audio/streak4.wav"
volumeStreak4             = 0.15
-- The Slayer Accolade.
soundStreak5              = preset .. "audio/streak5.wav"
volumeStreak5             = 0.15

-- Double Kill Accolade.
soundMultiKill1           = preset .. "audio/multikill1.wav"
volumeMultiKill1          = 0.15
-- Triple Kill Accolade.
soundMultiKill2           = preset .. "audio/multikill2.wav"
volumeMultiKill2          = 0.15
-- Quatra Kill Accolade.
soundMultiKill3           = preset .. "audio/multikill3.wav"
volumeMultiKill3          = 0.15
-- Ultra Kill Accolade.
soundMultiKill4           = preset .. "audio/multikill4.wav"
volumeMultiKill4          = 0.15
-- Team Kill Accolade.
soundMultiKill5           = preset .. "audio/multikill5.wav"
volumeMultiKill5          = 0.15

-- First Blood Accolade.
soundFirstBlood           = preset .. "audio/firstblood.wav"
volumeFirstBlood          = 0.15
-- Headshot Accolade.
soundHeadShotKill         = preset .. "audio/headshotkill.wav"
volumeHeadShotKill        = 0.15
-- Artillery Shot Accolade.
soundArtilleryShot        = preset .. "audio/artilleryshot.wav"
volumeArtilleryShot       = 0.15
-- Martial Art Accolade.
soundMeleeKill            = preset .. "audio/meleekill.wav"
volumeMeleeKill           = 0.15
-- Road Kill Accolade.
soundRoadKill             = preset .. "audio/roadkill.wav"
volumeRoadKill            = 0.15
-- Fast Grab Accolade.
soundFastGrab             = ""
volumeFastGrab            = 0.15
------------------------------------------------------------------------------


------------------------------------------------------------------------------
-- Flag event sounds
--
-- Enable/disable custom sounds for flag events and set their volume.
------------------------------------------------------------------------------
-- Your flag grabbed.
soundFlagBlueGrab         = preset .. "audio/flagblue_grab.wav"
volumeFlagBlueGrab        = 0.3
-- Enemy flag grabbed.
soundFlagRedGrab          = preset .. "audio/flagred_grab.wav"
volumeFlagRedGrab         = 0.3
-- Your flag picked up.
soundFlagBluePickup       = preset .. "audio/flagblue_pickup.wav"
volumeFlagBluePickup      = 0.3
-- Enemy flag picked up.
soundFlagRedPickup        = preset .. "audio/flagred_pickup.wav"
volumeFlagRedPickup       = 0.3
-- Your flag captured.
soundFlagBlueCapture      = preset .. "audio/flagblue_capture.wav"
volumeFlagBlueCapture     = 0.3
-- Enemy flag captured.
soundFlagRedCapture       = preset .. "audio/flagred_capture.wav"
volumeFlagRedCapture      = 0.3
-- Your flag returned.
soundFlagBlueReturn       = preset .. "audio/flagblue_return.wav"
volumeFlagBlueReturn      = 0.3
-- Enemy flag returned.
soundFlagRedReturn        = preset .. "audio/flagred_return.wav"
volumeFlagRedReturn       = 0.3
-- Your flag dropped.
soundFlagBlueDrop         = preset .. "audio/flagblue_drop.wav"
volumeFlagBlueDrop        = 0.3
-- Enemy flag dropped.
soundFlagRedDrop          = preset .. "audio/flagred_drop.wav"
volumeFlagRedDrop         = 0.3
------------------------------------------------------------------------------