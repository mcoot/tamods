require("hud/variables")
require("hud/colors")
require("hud/widgets/arena_player_spawns")
require("hud/widgets/arena_round_scores")
require("hud/widgets/cah_capture_points")
require("hud/widgets/chat_vgs")
require("hud/widgets/flag_status")
require("hud/widgets/game_scores")
require("hud/widgets/game_timer")
require("hud/widgets/game_messages")
require("hud/widgets/generator_status")
require("hud/widgets/health_energy")
require("hud/widgets/kda_ping")
require("hud/widgets/kill_feed")
require("hud/widgets/kill_message_box")
require("hud/widgets/rabbit_leaderboard")
require("hud/widgets/spectators")
require("hud/widgets/vehicle_health_energy")
require("hud/widgets/weapon_list")

-- Toggle HUD bound to 'O'
bindKey("O", Input.PRESSED, function() if not viewPort.isMainMenuOpen() then show_hud = not show_hud end end)

function onDrawCustomHud(res_x, res_y)
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
	chat_vgs(12, res_y - 300)
	kill_feed(15, 15)
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
			generator_status(center_x, 0)
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
		if speed ~= 0 then
			drawText(speed .. " kph", text_color1, res_x - 280, res_y - 20, 2, 1)
		end

		health_energy(center_x, res_y - 35)

		-- Weapons and Ammo
		-- If the current gun is not ready to fire, draw an indicator around the crosshair
		if not currentWeapon.isReadyToFire() then
			local color = currentWeapon.isReloaded() and text_color3 or text_color1
			drawText("-        -", color, center_x, center_y, 1, 1.5)
		end
		-- Draw the ammo of the current weapon close to the crosshair
		if not currentWeapon.isPack() and (not in_vehicle or (in_vehicle and vehicle.ammo() < 0)) then
			drawSmallText(currentWeapon.ammo(), currentWeapon.isLowAmmo() and text_color3 or text_color1, center_x + 16, res_y * 0.6, 1, 1, 1)
		end

		weapon_list(2, center_y - 100)

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

console("potatoHud loaded")
