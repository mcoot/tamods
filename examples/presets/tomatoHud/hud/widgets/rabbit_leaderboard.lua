function rabbit_leaderboard(x, y)
	local my_rank = player.rabbitRank()
	local color = text_color1
	local inTop3 = false
	for i = 0,2 do
		local name = rabbit.leaderBoardName(i)
		if name ~= "" then
			y = y + 28 * i
			drawRect(x, y, x + 260, y + 26, bg_color1)
			-- Different color if this is us
			if name == my_name then
				color = team_colors_text[1]
				inTop3 = true
			end
			drawText(i+1 .. ". " .. name, color, x + 5, y + 14, 0, 1)
			drawText(rabbit.leaderBoardScore(i), color, x + 255, y + 14, 2, 1)
		end
	end
	-- Draw us and our rank below the main leaderboard if we aren't in the top3 
	if not inTop3 then
		y = y + 28
		drawRect(x, y, x + 260, y + 26, bg_color1)
		drawText(my_rank .. ". " .. player.name(), team_colors_text[1], x + 5, y + 14, 0, 1)
		drawText(player.score(), team_colors_text[1], x + 255, y + 14, 2, 1)
	end
end
