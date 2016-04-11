require(preset .. "hud/variables")
require(preset .. "hud/colors")
require(preset .. "hud/widgets/arena_player_spawns")
require(preset .. "hud/widgets/arena_round_scores")
require(preset .. "hud/widgets/cah_capture_points")
require(preset .. "hud/widgets/chat_vgs")
require(preset .. "hud/widgets/flag_status")
require(preset .. "hud/widgets/game_scores")
require(preset .. "hud/widgets/game_timer")
require(preset .. "hud/widgets/game_messages")
require(preset .. "hud/widgets/generator_status")
require(preset .. "hud/widgets/health_energy")
require(preset .. "hud/widgets/healthbars")
require(preset .. "hud/widgets/kda_ping")
require(preset .. "hud/widgets/kill_feed")
require(preset .. "hud/widgets/kill_message_box")
require(preset .. "hud/widgets/rabbit_leaderboard")
require(preset .. "hud/widgets/spectators")
require(preset .. "hud/widgets/vehicle_health_energy")
require(preset .. "hud/widgets/weapon_list")
require(preset .. "hud/widgets/speed_bar")

-- Toggle HUD bound to Ctrl-O
bindKey("O", Input.PRESSED,
	function(key, event, ctrl, shift, alt)
	   if ctrl and not viewPort.isMainMenuOpen() then
	      show_hud = not show_hud
	   end
	end
)

local onDrawCustomHudOld
if type(onDrawCustomHud) == "function" then
	onDrawCustomHudOld = onDrawCustomHud
end

function onDrawCustomHud(res_x, res_y)
	if onDrawCustomHudOld then onDrawCustomHudOld(res_x, res_y) end

	local borderWidth = 20;

	-- Toggle HUD
	if not show_hud or viewPort.isMainMenuOpen() then
		return
	end

	set_variables()
	local center_x = res_x / 2
	local center_y = res_y / 2

	-- Stopwatch
	if stopwatch.isRunning() then
		drawSmallText(stopwatch.timeStr(), text_color1, res_x - 140, 140, 0, 1, 1)
	end

	spectators(center_x, res_y * 0.85)
	game_messages(center_x, 150)
	chat_vgs(borderWidth, borderWidth + 100)
	kill_feed(borderWidth, res_y - borderWidth - 300)
	kill_message_box(center_x, res_y * 0.82)
	kda_ping(res_x - 120, res_y - 10)

	game_timer(center_x, 0)

	-- Draw 70x40 team colored rectangles containing team score, not in rabbit though
	if game_type ~= "TrGame_TRRabbit" then
		game_scores(center_x, 0)
	end

	if game_type == "TrGame_TRCTF" or game_type == "TrGame_TrCTFBlitz" or game_type == "TrGame_TRTeamRabbit" then

		flag_status(center_x, 0)

		-- Generator status (not in TDM)
		if game_type ~= "TrGame_TRTeamRabbit" then
			--generator_status(center_x, 0)
		end

	elseif game_type == "TrGame_TRRabbit" then

		rabbit_leaderboard(res_x - 300, 36)
		-- Draw the current rabbit next to the game timer, but only if it's not us
		if not player.hasFlag() then
			drawText(rabbit.rabbitName(), team_colors_text[0], center_x + 80, 22, 0, 1)
		end

	elseif game_type == "TrGame_TrCaH" then

		cah_capture_points(center_x + 150, 5)

	elseif game_type == "TrGame_TrArena" then

		-- Round scores
		arena_round_scores(center_x, 40)
		-- Player spawns
		arena_player_spawns(center_x, 10)
		-- Draw a warning message if we have no respawns left
		if my_team ~= 255 and not game.isWarmUp() and player.isAlive() and player.arenaSpawnsLeft() < 1 then
			drawText("Last live!", text_color3, center_x, res_y * 0.12, 1, 1.8)
		end

	end

	-----------------
	-- Player info --
	-----------------
	if player.isAlive() then
		-- Store the relevant data
		local in_vehicle = player.isVehicle()
		local speed = in_vehicle and vehicle.speed() or player.speed()

		-- Draw current speed (player or vehicle), but only when not 0
		-- if speed ~= 0 then
			-- drawText(speed .. " kph", text_color1, res_x - 280, res_y - 20, 2, 1)
		-- end
		
		-- Draw speed bars above the minimum speed
		if speed >= skiBarMin then
			speed_bar(borderWidth, center_y)
			--speed_bar(res_x - borderWidth - 25, center_y)
		end

		-- Draw the ammo of the current weapon close to the crosshair
		-- if not currentWeapon.isPack() and (not in_vehicle or (in_vehicle and vehicle.ammo() < 0)) then
			-- drawSmallText(currentWeapon.ammo(), currentWeapon.isLowAmmo() and text_color3 or text_color1, center_x + 16, res_y * 0.6, 1, 1, 1)
		-- end

		health_energy(borderWidth, res_y - borderWidth)
		weapon_list(center_x, res_y - borderWidth)

		-- Draw a message if we have the flag
		if player.hasFlag() then
			drawText("F L A G", rgb(168,234,168), res_x - 25, center_y - 80, 2, 1.8)
		end
		-- Draw a message if we have rage active
		if player.isRaged() then
			drawText("R A G E", text_color3, res_x - 25, center_y - 40, 2, 1.8)
		end

		-- Vehicle display
		if in_vehicle then

			vehicle_health_energy(res_x * 0.65, res_y - 200)

			-- Ammo, not as gravcycle passenger (-1 ammo) or for the beowulf cannon (1 ammo)
			if vehicle.ammoMax() > 1 then
				drawSmallText(vehicle.ammo() .. "/" .. vehicle.ammoMax(), currentWeapon.isLowAmmo() and text_color3 or text_color1, center_x + 16, res_y * 0.6, 1, 1, 1)
			end

		end
	else
		local respawn_time = player.respawnTime()

		if respawn_time > 0 then
			drawText(respawn_time, text_color1, center_x, res_y * 0.9, 1, 1.5)
		end
	end
end
