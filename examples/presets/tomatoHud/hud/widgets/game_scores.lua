function game_scores(x, y)
	-- Left
	drawRect(x - 134, y, x - 64, y + 40, team_colors_bg[left_color])
	drawText(game.score(left_team), team_colors_text[left_color], x - 99, y + 22, 1, 1.5)
	-- Right
	drawRect(x + 64, y, x + 134, y + 40, team_colors_bg[right_color])
	drawText(game.score(right_team), team_colors_text[right_color], x + 99, y + 22, 1, 1.5)
end
