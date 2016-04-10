local module = {}

module.name            = "sqArenaScore"  -- This HAS to be the same as the filename minus the trailing .lua
module.opts            = {}
module.opts.X_Position = 49.0
module.opts.Y_Position = 60.0
module.opts.Text       = rgba(255,255,255,255)

function module.draw(res_x, res_y)
	if hud_data.game_type ~= "TrGame_TrArena" then return end

	local xpos = math.floor(module.opts.X_Position / 100 * res_x)
	local ypos = math.floor(module.opts.Y_Position / 100 * res_y)

	--- Round score
	-- Left team
	drawRect(x, y, x + 25, y + 20, sqHud.team_colors_bg[sqHud.left_color])
	drawText(arena.roundScore(sqHud.left_team), sqHud.team_colors_text[sqHud.left_color], x + 12, y + 11, 1, 1)
	-- Right team
	drawRect(x, y + 20, x + 25, y + 40, sqHud.team_colors_bg[sqHud.right_color])
	drawText(arena.roundScore(sqHud.right_team), sqHud.team_colors_text[sqHud.right_color], x + 12, y + 31, 1, 1)

	-- Draw the lefts teams player mannequins when spawns are empty
	if game.score(sqHud.left_team) < 1 then
		local x_pos = x - 170
		for i=0,7 do
			-- playerStatus returns a bitmask where:
			-- 0: no player, 1: player, 2: alive, 4: has spawns left
			local status = arena.playerStatus(sqHud.left_team, i)
			-- Don't draw anything if this slot has no player
			if status > 0 then
				if status == 1 then
					-- Player is benched, only draw an 'x'
					drawText("X", sqHud.text_color1, x_pos - 12, y + 14, 1, 1)
				else
					-- Player is alive, draw a square representing this player
					drawRect(x_pos - 24, y, x_pos, y + 24, sqHud.team_colors_bg[sqHud.left_color])
					-- Player has spawns left, draw a '1' inside his square
					if status > 3 then
						drawText("1", sqHud.team_colors_text[sqHud.left_color], x_pos - 12, y + 14, 1, 1)
					end
				end
				x_pos = x_pos - 26
			end
		end
	end
	-- Draw the rights teams player mannequins when spawns are empty
	if game.score(sqHud.right_team) < 1 then
		local x_pos = x + 170
		for i=0,7 do
			-- playerStatus returns a bitmask where:
			-- 0: no player, 1: player, 2: alive, 4: has spawns left
			local status = arena.playerStatus(sqHud.right_team, i)
			-- Don't draw anything if this slot has no player
			if status > 0 then
				if status == 1 then
					-- Player is benched, only draw an 'x'
					drawText("X", sqHud.text_color1, x_pos + 12, y + 14, 1, 1)
				else
					-- Player is alive, draw a square representing this player
					drawRect(x_pos, y, x_pos + 24, y + 24, sqHud.team_colors_bg[sqHud.right_color])
					-- Player has spawns left, draw a '1' inside his square
					if status > 3 then
						drawText("1", sqHud.team_colors_text[sqHud.right_color], x_pos + 12, y + 14, 1, 1)
					end
				end
				x_pos = x_pos + 26
			end
		end
	end
end

return module
