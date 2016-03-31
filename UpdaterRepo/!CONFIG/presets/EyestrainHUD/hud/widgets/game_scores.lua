function game_scores(x, y)
	-- Left
	drawRect(x, y, x + 25, y + 25, rgb(0, 0, 0))
	drawSmallText(game.score(left_team), rgb(255, 255, 255), x + 12, y + 12, 1, 1, 1)
	drawBox(x + 2, y + 2, x + 23, y + 23, team_colors_bg[left_color])
	-- Right
	drawRect(x, y + 28, x + 25, y + 53, rgb(0, 0, 0))
	drawSmallText(game.score(right_team), rgb(255, 255, 255), x + 12, y + 40, 1, 1, 1)
	drawBox(x + 2, y + 30, x + 23, y + 51, team_colors_bg[right_color])
end
