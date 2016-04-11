local module = {}

module.name             = "sqArenaSpawns"  -- This HAS to be the same as the filename minus the trailing .lua
module.opts             = {}
module.opts.X_Position  = 23.0
module.opts.Y_Position  = 1.0
module.opts.Team_Margin = 40
module.opts.Crossed_Off = rgba(255,255,255,255)

function module.draw(res_x, res_y)
	if hud_data.game_type ~= "TrGame_TrArena" then return end

	local xpos = math.floor(module.opts.X_Position / 100 * res_x)
	local ypos = math.floor(module.opts.Y_Position / 100 * res_y)

	-- Draw the lefts teams player mannequins when spawns are emptypos
	if game.score(hud_data.left_team) < 1 then
		local x_pos = xpos - module.opts.Team_Margin / 2
		for i=0,7 do
			-- playerStatus returns a bitmask where:
			-- 0: no player, 1: player, 2: alive, 4: has spawns left
			local status = arena.playerStatus(hud_data.left_team, i)
			-- Don't draw anyposthing if this slot has no player
			if status > 0 then
				if status == 1 then
					-- player is benched, onlypos draw an 'x'
					drawText("X", module.opts.Crossed_Off, x_pos - 12, ypos + 14, 1, 1)
				else
					-- player is alive, draw a square representing this player
					drawRect(x_pos - 24, ypos, x_pos, ypos + 24, hud_colors and hud_colors.opts.Team_Background[hud_data.left_color] or rgb(0,0,255))
					-- player has spawns left, draw a '1' inside his square
					if status > 3 then
						drawText("1", hud_colors and hud_colors.opts.Team_Text[hud_data.left_color] or rgb(0,0,255), x_pos - 12, ypos + 14, 1, 1)
					end
				end
				x_pos = x_pos - 26
			end
		end
	end
	-- Draw the rights teams player mannequins when spawns are emptypos
	if game.score(hud_data.right_team) < 1 then
		local x_pos = xpos + module.opts.Team_Margin / 2
		for i=0,7 do
			-- playerStatus returns a bitmask where:
			-- 0: no player, 1: player, 2: alive, 4: has spawns left
			local status = arena.playerStatus(hud_data.right_team, i)
			-- Don't draw anyposthing if this slot has no player
			if status > 0 then
				if status == 1 then
					-- player is benched, onlypos draw an 'x'
					drawText("X", module.opts.Crossed_Off, x_pos + 12, ypos + 14, 1, 1)
				else
					-- player is alive, draw a square representing this player
					drawRect(x_pos, ypos, x_pos + 24, ypos + 24, hud_colors and hud_colors.opts.Team_Background[hud_data.right_color], rgb(255,0,0))
					-- player has spawns left, draw a '1' inside his square
					if status > 3 then
						drawText("1", hud_colors and hud_colors.opts.Team_Text[hud_data.right_color] or rgb(255,0,0), x_pos + 12, ypos + 14, 1, 1)
					end
				end
				x_pos = x_pos + 26
			end
		end
	end
end

return module
