------------------------------------------------------------------------------
-- General options
------------------------------------------------------------------------------
-- Whether or not to show error notification popups in the upper left corner
-- of the screen.
showErrorNotifications    = true

-- Whether or not to show the weapon model in first person mode.
showWeapon                = true

-- Whether or not to show your current ammunition to the left of your
-- crosshair.
showFirstPersonAmmo       = false

-- Whether or not to show the crosshair. Disabling the crosshair will not
-- disable the hit marker.
showCrosshair             = false

-- This option can be used to change the size of the crosshair.
crosshairScale            = 1.0

-- The color of the crosshair. This only changes the colors of the white parts
-- of the default crosshairs.
--crosshairColor            = rgba(255, 255, 0, 255)

-- Whether or not to show the first person body mesh.
showBodyMesh              = false

-- Whether or not to use a custom weapon position.
customWeaponOffset        = true
-- The custom weapon position (Forward/Backward, Right/Left, Up/Down).
--weaponOffset              = Vector(24, -4, -8)
weaponOffset              = Vector(60, -5, -25)

-- Whether or not to use a custom postion for bullet spawns.
customBulletSpawnOffset   = false
-- The custom bullet spawn position (Forward/Backward, Right/Left, Up/Down).
bulletSpawnOffset         = Vector(180, 16, -60)

-- Console settings
consoleSize               = 0.75;
consoleTransparency       = 0.8;
------------------------------------------------------------------------------


------------------------------------------------------------------------------
-- Mouse sensitivity
--
-- For the most precision, use whole numbers only. Values below 1.0 should
-- be avoided in general.
------------------------------------------------------------------------------
-- Whether or not to use the Unreal Engine function to automatically scale
-- your mouse sensitivity to the current field of view.
useFOVScaling             = true
-- When FOVScaling is disabled, use this mouse sensitivity.
sens                      = 10.0
-- The mouse sensitivity when zooming (40 FOV).
sensZoom                  = 3.0
-- The mouse sensitivity with the magnified zoom (20 FOV).
sensZoooom                = 1.5
------------------------------------------------------------------------------


------------------------------------------------------------------------------
-- Damage numbers
------------------------------------------------------------------------------
-- Minimum amount of damage that has to be done before damage numbers show up.
damageNumbersLimit        = 80

-- Move the damage numbers left and right.
damageNumbersOffsetX      = 0.0

-- Move the damage numbers up and down.
damageNumbersOffsetY      = 0.0

-- The size of the damage numbers.
damageNumbersScale        = 1.0

-- Whether or not to show the total damage dealt within a certain timespan.
showDamageNumberStream    = false

-- If the damage numbers should show the amount of hits instead of the
-- damage done.
showChainBulletHitCount   = false

-- The timespan in seconds which has to pass without dealing any damage, for
-- the damage number stream or bullet hit count to reset.
damageNumberStreamTimeout = 0.8

-- Whether or not to automatically color damage numbers in random rainbow
-- colors.
showRainbow               = false

-- Show this string instead of the damage we have done.
damageNumberCustomText    = ""

-- The initial color taken by the damage numbers.
damageNumbersColorMin     = rgb(255, 255, 255)

-- The color that the damage numbers will take as they fade out.
damageNumbersColorMax     = rgb(248, 83, 83)

-- Revert to the old centered damage numbers for everything below 150 damage
revertOriginalDamageNumbers = true;
revertOriginalDamageNumbersThreshold = 150;
------------------------------------------------------------------------------


------------------------------------------------------------------------------
-- Chat colors
------------------------------------------------------------------------------
-- The text color of team mate chat messages in the console.
friendlyChatColor         = rgb(158, 208, 212)

-- The text color of enemy chat messages in the console.
enemyChatColor            = rgb(255, 111, 111)

-- The text color of team mate chat messages.
friendlyHUDChatColor      = rgb(158, 208, 211)

-- The text color of enemy chat messages.
enemyHUDChatColor         = rgb(249, 32, 32)
------------------------------------------------------------------------------


------------------------------------------------------------------------------
-- HUD items
------------------------------------------------------------------------------
-- The size of all IFF HUD items.
IFFScale                  = 0.85

-- Whether or not to display the flag base position icon.
showCTFBaseIcon           = true

-- Whether or not to display the flag icon when the flag is off-stand.
showFlagBaseIcon          = true

-- Whether or not to display the flag icon when the flag is home.
showFlagHomeBaseIcon      = true

-- Whether or not to display icons for deployable mines.
showMineIcon              = true

-- Whether or not to display the owner text for game mines.
showMineText              = false

-- Whether or not to display icons for dropped nugget pickups.
showNuggetIcon            = true

-- Whether or not to display icons for game objectives (base turrets,
-- player deployables, et cetera).
showObjectiveIcon         = true

-- Whether or not to display the name text for game objectives.
showObjectiveText         = false

-- Whether or not to display IFF icons,
showPlayerIcon            = true

-- Whether or not to display the sensor icon.
showSensorIcon            = true

-- Whether or not to display vehicle IFF icons.
showVehicleIcon           = true
------------------------------------------------------------------------------


------------------------------------------------------------------------------
-- IFF colors
------------------------------------------------------------------------------
-- Name color of players in your team.
friendlyColor             = rgba(119, 186, 255, 200)

-- IFF color of players in your team.
friendlyMarkerColor       = rgba(115, 225, 255, 0)

-- IFF color of mutual friends in the enemy team.
friendlyIsFMarkerColor    = rgba(81, 250, 85, 0)

-- Name color of enemy players.
--enemyColor                = rgba(248, 83, 83, 120)

-- IFF color of enemy players.
enemyMarkerColor          = rgba(255, 23, 23, 255)

-- IFF color of mutual friends in your team.
enemyIsFMarkerColor       = rgba(239, 164, 0, 255)
------------------------------------------------------------------------------


------------------------------------------------------------------------------
-- Ski bars
------------------------------------------------------------------------------
-- At or below this value the speed bar is completely empty.
skiBarMin                 = 30

-- At or above this speed the speed bar is completely full.
skiBarMax                 = 420
------------------------------------------------------------------------------


------------------------------------------------------------------------------
-- Magic chain
------------------------------------------------------------------------------
-- Whether or not to enable magic chain, showing the real location of
-- chain bullets.
useMagicChain             = false

-- Whether or not to use the default or smaller bullets.
useSmallBullets           = false

-- Whether or not to spawn bullets at the center of the screen or closer to
-- the weapon muzzle.
centerBulletSpawn         = false
-- 
-- Ping multiplier. Can be used to simulate different pings or to fine tune
-- the bullet location. A value of 0.5 would show bullet locations as half
-- your ping.
bulletPingMultiplier      = 1.0

-- Higher values spawn bullets farther away. Can be used with high pings so
-- bullets don't spawn behind you.
bulletSpawnDelay          = 0.0
------------------------------------------------------------------------------


------------------------------------------------------------------------------
-- Roam map variables
------------------------------------------------------------------------------
-- Whether or not to disable base turrets in roam map.
disableBaseTurrets        = true

-- Whether or not to disable powered blockers like the force fields on Bella
-- Omega and Permafrost.
disablePower              = true

-- Flag drag. Slowly decelerate to this speed when holding the flag.
-- 0 disables flag drag completely.
maxSpeedWithFlag          = 0

-- At what rate to decelerate to the maximum speed when holding the flag.
decelerationRateWithFlag  = 10
------------------------------------------------------------------------------


------------------------------------------------------------------------------
-- Route recording variables
------------------------------------------------------------------------------
-- The draw interval for the little dots indicating the route path.
-- 0 disables route drawing entirely and the minimum value is 100.
routeDrawInterval = 200

-- How transparent the route path is
routeDrawTransparency = 0.8

-- The draw interval of ETA in seconds.
-- 0 disables ETA drawing entirely.
routeDrawETAInterval = 5

-- Whether or not to lock your rotation to the replay or enable free-look.
routeReplayRotation = true

-- Whether or not to use smooth rotation.
routeCinematicMode = false
------------------------------------------------------------------------------


------------------------------------------------------------------------------
-- Stats
------------------------------------------------------------------------------
-- Whether or not to display stats in the console at the end of a match.
recordStats               = false
------------------------------------------------------------------------------
