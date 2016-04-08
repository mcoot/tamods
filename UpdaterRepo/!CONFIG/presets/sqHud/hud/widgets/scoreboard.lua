local show = false

bindKey("Tab", Input.PRESSED, function() show = true end)
bindKey("Tab", Input.RELEASED, function() show = false end)

sqHud.scoreboard = function(x, y)
	if show then
		-- Generator status
		if sqHud.game_type == "TrGame_TRCTF" or sqHud.game_type == "TrGame_TrCTFBlitz" then
			-- Left
			if not game.isGenUp(0) then
				local repair_timer = game.genAutoRepairTime(0)
				if repair_timer > 0 then
					-- Display the remaining time until auto repair
					drawSmallText("Gen: " .. repair_timer, sqHud.team_colors_text[0], x + 400, y - 12, 2, 1, 1)
				else
					-- Auto repairing is turned off, just display that the generator is down
					drawSmallText("Gen down", sqHud.team_colors_text[0], x + 400, y - 12, 2, 1, 1)
				end
			end
			-- Right
			if not game.isGenUp(1) then
				local repair_timer = game.genAutoRepairTime(1)
				if repair_timer > 0 then
					-- Display the remaining time until auto repair
					drawSmallText("Gen: " .. repair_timer, sqHud.team_colors_text[1], x + 806, y - 12, 2, 1, 1)
				else
					-- Auto repairing is turned off, just display that the generator is down
					drawSmallText("Gen down", sqHud.team_colors_text[1], x + 806, y - 12, 2, 1, 1)
				end
			end
		end

		local players = game.players()

		local x_pos = x
		local y_pos = y
		local textcolor

		for j = 0,2 do
			if j == 2 then
				local height = #players[0] > #players[1] and #players[0] or #players[1]

				j = 255
				x_pos = x + 203
				y_pos = y + 30 + 29 * height
			end

			-- Header, don't show for specs if there are none
			if j ~= 255 or #players[j] > 0 then
				drawRect(x_pos, y_pos, x_pos + 400, y_pos + 24, sqHud.team_colors_bg[j])
				drawSmallText("Rank", sqHud.text_color1, x_pos + 45, y_pos + 12, 2, 1, 1)
				drawSmallText("Name", sqHud.text_color1, x_pos + 50, y_pos + 12, 0, 1, 1)
				drawSmallText("Class", sqHud.text_color1, x_pos + 240, y_pos + 12, 0, 1, 1)
				drawSmallText("K", sqHud.text_color1, x_pos + 290, y_pos + 12, 2, 1, 1)
				drawSmallText("A", sqHud.text_color1, x_pos + 315, y_pos + 12, 2, 1, 1)
				drawSmallText("Score", sqHud.text_color1, x_pos + 365, y_pos + 12, 2, 1, 1)
				drawSmallText("P", sqHud.text_color1, x_pos + 395, y_pos + 12, 2, 1, 1)
				y_pos = y_pos + 24
			end

			-- Players
			for i = 1,#players[j] do
				p = players[j][i]

				if sqHud.my_team == j and p.name == sqHud.my_name then
					textcolor = rgb(100,255,100)
				else
					textcolor = sqHud.text_color1
				end

				drawRect(x_pos, y_pos, x_pos + 400, y_pos + 30, sqHud.bg_color1)
				drawSmallText(i .. ".", textcolor, x_pos + 5, y_pos + 15, 0, 1, 1)
				drawSmallText(p.rank, textcolor, x_pos + 45, y_pos + 15, 2, 1, 1)
				drawSmallText(p.name, textcolor, x_pos + 50, y_pos + 15, 0, 1, 1)
				drawSmallText(p.class, textcolor, x_pos + 240, y_pos + 15, 0, 1, 1)
				drawSmallText(p.kills, textcolor, x_pos + 290, y_pos + 15, 2, 1, 1)
				drawSmallText(p.assists, textcolor, x_pos + 315, y_pos + 15, 2, 1, 1)
				drawSmallText(p.score, textcolor, x_pos + 365, y_pos + 15, 2, 1, 1)
				drawSmallText(p.ping, textcolor, x_pos + 395, y_pos + 15, 2, 1, 1)
				y_pos = y_pos + 29
			end

			x_pos = x + 406
			y_pos = y
		end
	end
end
