function arena_round_scores(x, y)
	-- Left team
	drawRect(x, y, x + 25, y + 20, team_colors_bg[left_color])
	drawText(arena.roundScore(left_team), team_colors_text[left_color], x + 12, y + 11, 1, 1)
	-- Right team
	drawRect(x, y + 20, x + 25, y + 40, team_colors_bg[right_color])
	drawText(arena.roundScore(right_team), team_colors_text[right_color], x + 12, y + 31, 1, 1)
end
