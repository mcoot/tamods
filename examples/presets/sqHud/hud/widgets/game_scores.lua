function game_scores(x, y)
	-- Left
	drawRect(x, y, x + 40, y + 20, team_colors_bg[left_color])
	drawSmallText(game.score(left_team), rgb(0,0,0), x + 19, y + 10, 1, 0, 1)
	-- Right
	drawRect(x, y + 20, x + 40, y + 40, team_colors_bg[right_color])
	drawSmallText(game.score(right_team), rgb(0,0,0), x + 19, y + 30, 1, 0, 1)
end
