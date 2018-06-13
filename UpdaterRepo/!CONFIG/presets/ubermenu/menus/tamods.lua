local tamodsmenu = ubermenu:add_submenu({ title = "TAMods Settings" })
	local sub1 = tamodsmenu:add_submenu({ title = "Damage Numbers" })
		sub1:add_variable({ title = "Display Limit",             varname = "damageNumbersLimit",                   default = 0,     min = 0,   inc = 1, description = "Only show damage numbers when doing at least this\namount of damage\n \nDefault: 0  Minimum: 0" })
		sub1:add_variable({ title = "Horizontal Offset",         varname = "damageNumbersOffsetX",                 default = 0.0,              inc = 1.0 })
		sub1:add_variable({ title = "Vertical Offset",           varname = "damageNumbersOffsetY",                 default = 0.0,              inc = 1.0 })
		sub1:add_variable({ title = "Scale",                     varname = "damageNumbersScale",                   default = 1.0,   min = 0.0, inc = 0.1 })
		sub1:add_variable({ title = "Center Position",           varname = "revertOriginalDamageNumbers",          default = false, description = "Revert damage numbers back to the old pre-OOTB\nposition\n \nDefault: false" })
		sub1:add_variable({ title = "Center Position Threshold", varname = "revertOriginalDamageNumbersThreshold", default = 150,   min = 0,   inc = 1, description = "Revert damage numbers back to the old pre-OOTB\nposition for damage below this threshold\n \nDefault: 150  Minimum: 0" })
		sub1:add_variable({ title = "Stream Numbers",            varname = "showDamageNumberStream",               default = false, description = "Show total damage done instead of per shot damage\n \nDefalt: false" })
		sub1:add_variable({ title = "Show Hit Count",            varname = "showChainBulletHitCount",              default = false, description = "Show hit count instead of per shot damage\n \nDefault: false" })
		sub1:add_variable({ title = "Stream Timeout",            varname = "damageNumberStreamTimeout",            default = 0.5,   min = 0.1, inc = 0.1, description = "Reset the total damage/hit count after not landing a hit\nfor this duration\n \nDefault: 0.5 seconds" })
		sub1:add_variable({ title = "Custom Text",               varname = "damageNumberCustomText",               default = "", description = "Show custom text instead of damage\n \nDefault: Empty" })
		sub1:add_variable({ title = "Use Rainbow",               varname = "showRainbow",                          default = false, description = "Show damage numbers in random rainbow colors\n \nDefault: false" })
		sub1:add_color({    title = "Start Color",               varname = "damageNumbersColorMin",                default = rgb(255,255,255,255), description = "The starting color when a damage number appears\n \nDefault: rgba(255, 255, 255, 255)" })
		sub1:add_color({    title = "End Color",                 varname = "damageNumbersColorMax",                default = rgb(248,83,83,255), description = "Blend to this color the older the damage number gets\n \nDefault: rgba(248, 83, 83, 255)" })
		sub1:add_separator({})
		sub1:add_item({ title = "Apply", func = config.reloadVariables })

	local sub1 = tamodsmenu:add_submenu({ title = "Gameplay" })
		sub1:add_variable({ title = "Show Weapon",              varname = "showWeapon",         default = true })
		sub1:add_variable({ title = "Show Body",                varname = "showBodyMesh",       default = true })
		sub1:add_variable({ title = "Use FOV Scaling",          varname = "useFOVScaling",      default = true, description = "Disabling this option can improve precision when using\nwhole numbers as sensitivity\n \nDefault: true" })
		sub1:add_variable({ title = "Sensitivity",              varname = "sens",               default = 10.0, min = 0.0, inc = 0.1, description = "The mouse sensitivity for when FOV scaling is disabled\n \nDefault: 10.0" })
		sub1:add_variable({ title = "Zoomed Sensitivity",       varname = "sensZoom",           default = 5.0, min = 0.0,  inc = 0.1, description = "The mouse sensitivity in the first zoom level for when\nFOV scaling is disabled\n \nDefault: 5.0" })
		sub1:add_variable({ title = "Zoomedx2 Sensitivity",     varname = "sensZoooom",         default = 2.0, min = 0.0,  inc = 0.1, description = "The mouse sensitivity in the second zoom level for\nwhen FOV scaling is disabled\n \nDefault: 2.0" })
		sub1:add_variable({ title = "Use Custom Weapon Offset", varname = "customWeaponOffset", default = false })
		sub1:add_fvector({  title = "Weapon Offset",            varname = "weaponOffset",       default = Vector(0.0, 0.0, 0.0), inc = 0.2, description = "The weapon model position\n \nDefault: Vector(0.0, 0.0, 0.0)" })
		sub1:add_separator({})
		sub1:add_item({ title = "Apply", func = config.reloadVariables })

	local sub1 = tamodsmenu:add_submenu({ title = "HUD" })
		local sub2 = sub1:add_submenu({ title = "Crosshair" })
			sub2:add_variable({ title = "Show Stock Crosshairs", varname = "showCrosshair",  default = true, description = "In contrast to disabling the crosshair through the T:A\noptions menu, this hides crosshairs only and keeps hit\nmarkers\n \nDefault: false" })
			sub2:add_variable({ title = "Scale",                 varname = "crosshairScale", default = 1.0, min = 0.0, inc = 0.5 })
			sub2:add_color({    title = "Color",                 varname = "crosshairColor", default = rgba(255,255,255,255) })
			sub2:add_separator({})
			sub2:add_item({ title = "Apply", func = config.reloadVariables })
		local sub2 = sub1:add_submenu({ title = "Chat" })
			sub2:add_color({ title = "Friendly Console Color",   varname = "friendlyChatColor",    default = rgb(158, 208, 212) })
			sub2:add_color({ title = "Enemy Console Color",      varname = "enemyChatColor",       default = rgb(255, 111, 111) })
			sub2:add_color({ title = "Whispers Console Color",   varname = "whisperChatColor",     default = rgb(207, 165, 101) })
			sub2:add_color({ title = "Friendly HUD Color",       varname = "friendlyHUDChatColor", default = rgb(158, 208, 211) })
			sub2:add_color({ title = "Enemy HUD Color",          varname = "enemyHUDChatColor",    default = rgb(249, 32, 32) })
			sub2:add_separator({})
			sub2:add_item({ title = "Apply", func = config.reloadVariables })
		local sub2 = sub1:add_submenu({ title = "Markers" })
			sub2:add_color({ title = "Teammate Name Color",      varname = "friendlyColor",          default = rgb(119, 186, 255) })
			sub2:add_color({ title = "Enemy Name Color",         varname = "enemyColor",             default = rgb(248, 83, 83) })
			sub2:add_color({ title = "Teammate Marker Color",    varname = "friendlyMarkerColor",    default = rgb(115, 225, 255) })
			sub2:add_color({ title = "Enemy Marker Color",       varname = "enemyMarkerColor",       default = rgb(255, 23, 23) })
			sub2:add_color({ title = "Teammate Friend Marker",   varname = "friendlyIsFMarkerColor", default = rgb(81, 250, 85) })
			sub2:add_color({ title = "Enemy Friend Marker",      varname = "enemyIsFMarkerColor",    default = rgb(239, 164, 0) })
			sub2:add_separator({})
			sub2:add_item({ title = "Apply", func = config.reloadVariables })
		local sub2 = sub1:add_submenu({ title = "Speed Counter" })
			sub2:add_variable({ title = "Minimal value",         varname = "skiBarMin", default = 30,  min = 0, inc = 1 })
			sub2:add_variable({ title = "Maximal value",         varname = "skiBarMax", default = 300, min = 0, inc = 1 })
			sub2:add_separator({})
			sub2:add_item({ title = "Apply", func = config.reloadVariables })
		local sub2 = sub1:add_submenu({ title = "Stopwatch" })
			sub2:add_variable({ title = "Stop On Cap",           varname = "stopwatchStopOnCap",     default = false })
			sub2:add_variable({ title = "Stop On Death",         varname = "stopwatchStopOnDeath",   default = true })
			sub2:add_variable({ title = "Notifications",         varname = "stopwatchNotifications", default = true })
			sub2:add_separator({})
			sub2:add_item({ title = "Apply", func = config.reloadVariables })
		local sub2 = sub1:add_submenu({ title = "Icons" })
			sub2:add_variable({ title = "Show Objectives",       varname = "showObjectiveIcon",    default = true })
			sub2:add_variable({ title = "Show Objective Text",   varname = "showObjectiveText",    default = true })
			sub2:add_variable({ title = "Show Flag Base",        varname = "showFlagBaseIcon",     default = true })
			sub2:add_variable({ title = "Show Flag Home Base",   varname = "showFlagHomeBaseIcon", default = true })
			sub2:add_variable({ title = "Show CTF Base",         varname = "showCTFBaseIcon",      default = true })
			sub2:add_variable({ title = "Show Nuggets",          varname = "showNuggetIcon",       default = true })
			sub2:add_variable({ title = "Show Players",          varname = "showPlayerIcon",       default = true })
			sub2:add_variable({ title = "Show Vehicles",         varname = "showVehicleIcon",      default = true })
			sub2:add_variable({ title = "Show Mines",            varname = "showMineIcon",         default = true })
			sub2:add_variable({ title = "Show Mine Text",        varname = "showMineText",         default = true })
			sub2:add_variable({ title = "Show Sensors",          varname = "showSensorIcon",       default = true })
			sub2:add_separator({})
			sub2:add_item({ title = "Apply", func = config.reloadVariables })
		local sub2 = sub1:add_submenu({ title = "Misc" })
			sub2:add_variable({ title = "General IFF Scale",     varname = "IFFScale",            default = 1.0, min = 0.0, inc = 0.5, description = "Scaling for all IFF icons\n \nDefault: 1.0" })
			sub2:add_variable({ title = "Always Show Ammo",      varname = "showFirstPersonAmmo", default = false })
			sub2:add_variable({ title = "Console Size",          varname = "consoleSize",         default = 0.75, min = 0.0, max = 1.0, inc = 0.01 })
			sub2:add_variable({ title = "Console Transparency",  varname = "consoleTransparency", default = 0.8,  min = 0.0, max = 1.0, inc = 0.01 })
			sub2:add_variable({ title = "Mute All VGS",          varname = "muteVGS",             default = false })
			sub2:add_separator({})
			sub2:add_item({ title = "Apply", func = config.reloadVariables })

	local sub1 = tamodsmenu:add_submenu({ title = "Magic Chain" })
		sub1:add_variable({ title = "Use Magic Chain",        varname = "useMagicChain",           default = false })
		sub1:add_variable({ title = "Use Small Bullets",      varname = "useSmallBullets",         default = false })
		sub1:add_variable({ title = "Center Bullets",         varname = "centerBulletSpawn",       default = false })
		sub1:add_variable({ title = "Ping Multiplier",        varname = "bulletPingMultiplier",    default = 1.0, min = 0.0, inc = 0.1 })
		sub1:add_variable({ title = "Spawn Delay",            varname = "bulletSpawnDelay",        default = 0.0, min = 0.0, inc = 0.1 })
		sub1:add_variable({ title = "Use Custom Spawn",       varname = "customBulletSpawnOffset", default = false })
		sub1:add_fvector({  title = "Custom Spawn Offset",    varname = "bulletSpawnOffset",       default = Vector(180.0, 0.0, 0.0), inc = 0.5 })
		sub1:add_separator({})
		sub1:add_item({ title = "Apply", func = config.reloadVariables })

	local sub1 = tamodsmenu:add_submenu({ title = "Roam Map" })
		sub1:add_variable({ title = "Disable Base Turrets",   varname = "disableBaseTurrets",       default = false })
		sub1:add_variable({ title = "Disable Power",          varname = "disablePower",             default = false })
		sub1:add_variable({ title = "Show Saved Locations",   varname = "showSavedLocations",       default = true })
		sub1:add_variable({ title = "Max Speed With Flag",    varname = "maxSpeedWithFlag",         default = 0, min = 0, inc = 1 })
		sub1:add_variable({ title = "Deceleration With Flag", varname = "decelerationRateWithFlag", default = 10, inc = 1 })
		sub1:add_separator({})
		sub1:add_item({ title = "Apply", func = config.reloadVariables })

	local sub1 = tamodsmenu:add_submenu({ title = "Route Recording" })
		sub1:add_variable({ title = "Draw Interval",          varname = "routeDrawInterval",     default = 500, min = 100, inc = 100, description = "This determines the distance between the individual\nlittle route dots. Lower values results in a more tightly\ndrawn path\n \nDefault: 500 ms  Minimum: 100 ms" })
		sub1:add_variable({ title = "Draw Transparency",      varname = "routeDrawTransparency", default = 0.8, min = 0.0, max = 1.0, inc = 0.01 })
		sub1:add_variable({ title = "ETA Draw Interval",      varname = "routeDrawETAInterval",  default = 5,   min = 0, inc = 1, description = "At which interval to draw times until grab\n \nDefault: 5 seconds" })
		sub1:add_variable({ title = "Replay With Rotation",   varname = "routeReplayRotation",   default = true })
		sub1:add_variable({ title = "Smooth Replay",          varname = "routeCinematicMode",    default = false })
		sub1:add_separator({})
		sub1:add_item({ title = "Apply", func = config.reloadVariables })

	local sub1 = tamodsmenu:add_submenu({ title = "Sounds" })
		sub1:add_variable({ title = "Hit Sound Pitch Mode", varname = "hitSoundMode",      default = 1,   min = 1, max = 3, inc = 1, description = "How to play hit sounds\n \n1: Static pitch\n2: Pitch decreases with damage\n3: Pitch increases with damage\n \nDefault: 1  Minimum: 1  Maximum: 3" })
		sub1:add_variable({ title = "Hit Sound Min Pitch",  varname = "hitSoundPitchMin",  default = 0.4, min = 0.0, inc = 0.1, description = "The lowest pitch hit sounds will ever be played at\n \nDefault: 0.4" })
		sub1:add_variable({ title = "Hit Sound Max Pitch",  varname = "hitSoundPitchMax",  default = 1.6, min = 0.0, inc = 0.1, description = "The highest pitch hit sounds will ever be played at\n \nDefault: 1.6" })
		sub1:add_variable({ title = "Damage Reference",     varname = "hitSoundDamageRef", default = 600, min = 0,   inc = 10, description = "Used to calculate when and by how much to change\nthe pitch. Setting this to 600 would mean doing 600\ndamage would give pitch 1.0. Doing 1200, depending on\nmode, would result in 0.5 or 2.0 pitch\n \nDefault: 600" })
		sub1:add_separator({})

		local sounds = {
			{ title = "Hits and Kills", sounds = {
				{ title = "Hit",                  varname = "Hit",             default = 0.55 },
				{ title = "Headshot",             varname = "HeadShot",        default = 0.55 },
				{ title = "Kill",                 varname = "Kill",            default = 0.55 },
				{ title = "Air Mail",             varname = "AirMail",         default = 0.55 },
				{ title = "Blue Plate",           varname = "BluePlate",       default = 0.55 },
				{ title = "First Blood",          varname = "FirstBlood",      default = 0.5  },
				{ title = "Headshot Kill",        varname = "HeadShotKill",    default = 0.5  },
				{ title = "Artillery Shot",       varname = "ArtilleryShot",   default = 0.5  },
				{ title = "Melee Kill",           varname = "MeleeKill",       default = 0.5  },
				{ title = "Roadkill",             varname = "RoadKill",        default = 0.5  }
			}},
			{ title = "Sprees and Multi Kills", sounds = {
				{ title = "Killing Spree",        varname = "Streak1",         default = 0.5  },
				{ title = "Rampage",              varname = "Streak2",         default = 0.5  },
				{ title = "Relentless",           varname = "Streak3",         default = 0.5  },
				{ title = "Unstoppable",          varname = "Streak4",         default = 0.5  },
				{ title = "The Slayer",           varname = "Streak5",         default = 0.5  },
				{ title = "Double Kill",          varname = "MultiKill1",      default = 0.5  },
				{ title = "Triple Kill",          varname = "MultiKill2",      default = 0.5  },
				{ title = "Quatra Kill",          varname = "MultiKill3",      default = 0.5  },
				{ title = "Ultra Kill",           varname = "MultiKill4",      default = 0.5  },
				{ title = "Team Kill",            varname = "MultiKill5",      default = 0.5  }
			}},
			{ title = "Flag Events", sounds = {
				{ title = "Fast Grab",            varname = "FastGrab",        default = 0.5  },
				{ title = "Our Flag Grabbed",     varname = "FlagBlueGrab",    default = 0.5  },
				{ title = "Enemy Flag Grabbed",   varname = "FlagRedGrab",     default = 0.5  },
				{ title = "Our Flag Picked Up",   varname = "FlagBluePickup",  default = 0.5  },
				{ title = "Enemy Flag Picked Up", varname = "FlagRedPickup",   default = 0.5  },
				{ title = "Our Flag Captured",    varname = "FlagBlueCapture", default = 0.5  },
				{ title = "Enemy Flag Captured",  varname = "FlagRedCapture",  default = 0.5  },
				{ title = "Our Flag Returned",    varname = "FlagBlueReturn",  default = 0.5  },
				{ title = "Enemy Flag Returned",  varname = "FlagRedReturn",   default = 0.5  },
				{ title = "Our Flag Dropped",     varname = "FlagBlueDrop",    default = 0.5  },
				{ title = "Enemy Flag Dropped",   varname = "FlagRedDrop",     default = 0.5  }
			}}
		}
		local files = config.getFileList("examples/sounds")

		for i = 1,3 do
			local sub2 = sub1:add_submenu({ title = sounds[i].title })
			for j = 1,#sounds[i].sounds do
				local sub3 = sub2:add_submenu({ title = sounds[i].sounds[j].title })
					sub3:add_variable({ title = "Volume", varname = "volume" .. sounds[i].sounds[j].varname, default = sounds[i].sounds[j].default, inc = 0.1 })
					sub3:add_variable({ title = "File",   varname = "sound"  .. sounds[i].sounds[j].varname, default = "" })
					local sub4 = sub3:add_submenu({ title = "Select File" })
					for i = 1,#files do
						if files[i] ~= "." and files[i] ~= ".." then
							sub4:add_item({ title = files[i], func = function(parent, item)
								parent:set_var(parent.parent.items[2].varname, "examples/sounds/" .. item.title)
								parent:go_parent()
								parent:go_prev()
							end })
						end
					end
					sub3:add_separator({})
					sub3:add_item({ title = "Apply", func = function() config.reloadVariables() reloadSounds() end })
			end
		end

		sub1:add_separator({})
		sub1:add_item({ title = "Apply", func = function() config.reloadVariables() reloadSounds() end })

	tamodsmenu:add_variable({ title = "Record Stats", varname = "recordStats", default = false })
	tamodsmenu:add_variable({ title = "Record Game Stats", varname = "recordTeamStats", default = false })
	tamodsmenu:add_variable({ title = "Save Stats", varname = "saveStats", default = false })
	tamodsmenu:add_variable({ title = "Save Game Stats", varname = "saveTeamStats", default = false })
	tamodsmenu:add_separator({})
	tamodsmenu:add_item({ title = "Apply", func = config.reloadVariables })

sub1 = nil
sub2 = nil
