function arena_round_scores(x, y)
	-- Left team
	drawRect(x - 113, y, x - 86, y + 20, team_colors_bg[left_color])
	drawText(arena.roundScore(left_team), team_colors_text[left_color], x - 99, y + 11, 1, 1)
	-- Right team
	drawRect(x + 86, y, x + 113, y + 20, team_colors_bg[right_color])
	drawText(arena.roundScore(right_team), team_colors_text[right_color], x + 99, y + 11, 1, 1)
end
