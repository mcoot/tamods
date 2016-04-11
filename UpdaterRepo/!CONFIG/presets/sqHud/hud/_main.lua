require(sqHud.preset .. "hud/variables")
require(sqHud.preset .. "hud/colors")
require(sqHud.preset .. "hud/widgets/ammo")
require(sqHud.preset .. "hud/widgets/arena_player_spawns")
require(sqHud.preset .. "hud/widgets/arena_round_scores")
require(sqHud.preset .. "hud/widgets/cah_capture_points")
require(sqHud.preset .. "hud/widgets/chat_vgs")
require(sqHud.preset .. "hud/widgets/flag_status")
require(sqHud.preset .. "hud/widgets/game_scores")
require(sqHud.preset .. "hud/widgets/game_timer")
require(sqHud.preset .. "hud/widgets/game_messages")
require(sqHud.preset .. "hud/widgets/health_energy")
require(sqHud.preset .. "hud/widgets/healthbars")
require(sqHud.preset .. "hud/widgets/kill_feed")
require(sqHud.preset .. "hud/widgets/rabbit_leaderboard")
require(sqHud.preset .. "hud/widgets/scoreboard")
require(sqHud.preset .. "hud/widgets/stats")
require(sqHud.preset .. "hud/widgets/vehicle_health_energy")

-- Toggle HUD bound to Ctrl-O
bindKey("O", Input.PRESSED,
	function(key, event, ctrl, shift, alt)
	   if ctrl and not viewPort.isMainMenuOpen() then
	      sqHud.show_hud = not sqHud.show_hud
	   end
	end
)

local onDrawCustomHudOld
if type(onDrawCustomHud) == "function" then
	onDrawCustomHudOld = onDrawCustomHud
end

sqHud.draw = function(res_x, res_y)
	if onDrawCustomHudOld then onDrawCustomHudOld(res_x, res_y) end

	-- Toggle HUD
	if not sqHud.show_hud or viewPort.isMainMenuOpen() then
		return
	end

	sqHud.set_variables()
	local center_x = res_x / 2
	local center_y = res_y / 2

	-- Stopwatch
	if stopwatch.isRunning() then
		drawSmallText(stopwatch.timeStr(), sqHud.text_color1, res_x - 140, 140, 0, 1, 1)
	end

	sqHud.stats(res_x - 20, 20)
	sqHud.game_messages(center_x, 150)
	sqHud.chat_vgs(15, res_y - 140)
	sqHud.kill_feed(15, center_y - 200)

	sqHud.game_timer(center_x, 0)

	-- Draw 70x40 team colored rectangles containing team score, not in rabbit though
	if sqHud.game_type ~= "TrGame_TRRabbit" then
		sqHud.game_scores(center_x + 40, 0)
	end

	if sqHud.game_type == "TrGame_TRCTF" or sqHud.game_type == "TrGame_TrCTFBlitz" or sqHud.game_type == "TrGame_TRTeamRabbit" then

		sqHud.flag_status(center_x + 80, 0)

	elseif sqHud.game_type == "TrGame_TRRabbit" then

		sqHud.rabbit_leaderboard(36, 36)
		-- Draw the current rabbit next to the game timer, but only if it's not us
		if not player.hasFlag() then
			drawText(rabbit.rabbitName(), sqHud.team_colors_text[0], center_x + 80, 22, 0, 1)
		end

	elseif sqHud.game_type == "TrGame_TrCaH" then

		sqHud.cah_capture_points(center_x + 90, 8)

	elseif sqHud.game_type == "TrGame_TrArena" then

		-- Round scores
		sqHud.arena_round_scores(center_x - 65, 0)
		-- Player spawns
		sqHud.arena_player_spawns(center_x, 10)
		-- Draw a warning message if we have no respawns left
		if sqHud.my_team ~= 255 and not game.isWarmUp() and player.isAlive() and player.arenaSpawnsLeft() < 1 then
			drawRect(center_x - 35, 40, center_x + 35, 60, sqHud.bg_color2)
			drawSmallText("Last live!", sqHud.text_color3, center_x, 50, 1, 1, 1)
		end

	end

	-----------------
	-- Player info --
	-----------------
	if player.isAlive() then
		-- Store the relevant data
		local in_vehicle = player.isVehicle()

		-- Draw the current amount of charged damage for the phase rifle
		if currentWeapon.name() == "Phase Rifle" then
			drawSmallText(math.ceil(player.energy() * 5.333), sqHud.text_color1, center_x - 16, res_y * 0.6, 2, 1, 1)
		end

		sqHud.health_energy(center_x - 500, center_y + 300)
		sqHud.ammo(center_x + 200, center_y + 300)

		-- Draw a message if we have the flag
		if player.hasFlag() then
			drawRect(res_x - 165, center_y - 90, res_x - 108, center_y - 70, sqHud.bg_color1)
			drawSmallText("F L A G", rgb(168,234,168), res_x - 160, center_y - 80, 0, 1, 1)
		end
		-- Draw a message if we have rage active
		if player.isRaged() then
			drawRect(res_x - 165, center_y - 68, res_x - 108, center_y - 48, sqHud.bg_color1)
			drawSmallText("R A G E", sqHud.text_color3, res_x - 160, center_y - 58, 0, 1, 1)
		end

		-- Vehicle display
		if in_vehicle then

			sqHud.vehicle_health_energy(center_x - 25, res_y - 200)

			-- Ammo, not as gravcycle passenger (-1 ammo) or for the beowulf cannon (1 ammo)
			if vehicle.ammoMax() > 1 then
				drawSmallText(vehicle.ammo() .. "/" .. vehicle.ammoMax(), sqHud.text_color1, center_x + 16, res_y * 0.6, 0, 1, 1)
			end

		end
	else
		local respawn_time = player.respawnTime()

		if respawn_time > 0 then
			drawText(respawn_time, sqHud.text_color1, center_x, res_y * 0.9, 1, 1.5)
		end
	end
	sqHud.scoreboard(center_x - 403, 200)
end

if type(ubermenu) == "table" and ubermenu.isroot then
	onDrawCustomHudOld = nil
	ubermenu:add_draw_func(sqHud.draw)
else
	onDrawCustomHud = sqHud.draw
end
