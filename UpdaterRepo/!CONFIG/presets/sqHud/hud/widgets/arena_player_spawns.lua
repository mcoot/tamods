sqHud.arena_player_spawns = function(x, y)
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
