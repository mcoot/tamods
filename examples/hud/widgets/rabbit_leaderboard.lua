function rabbit_leaderboard(x, y)
	local my_rank = player.rabbitRank()
	local color
	for i = 0,2 do
		local name = rabbit.leaderBoardName(i)
		if name ~= "" then
			y = y + 28 * i
			drawRect(x, y, x + 260, y + 26, bg_color1)
			-- Different color if this is us
			color = my_rank == i+1 and team_colors_text[1] or text_color1
			drawText(i+1 .. ". " .. name, color, x + 5, y + 14, 0, 1)
			drawText(rabbit.leaderBoardScore(i), color, x + 255, y + 14, 2, 1)
		end
	end
	-- Draw us and our rank below the main leaderboard if we aren't in the top3 
	if my_rank > 3 then
		y = y + 28
		drawRect(x, y, x + 260, y + 26, bg_color1)
		drawText(my_rank .. ". " .. player.name(), team_colors_text[1], x + 5, y + 14, 0, 1)
		drawText(player.score(), team_colors_text[1], x + 255, y + 14, 2, 1)
	end
end
