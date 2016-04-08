sqHud.arena_round_scores = function(x, y)
	-- Left team
	drawRect(x, y, x + 25, y + 20, sqHud.team_colors_bg[sqHud.left_color])
	drawText(arena.roundScore(sqHud.left_team), sqHud.team_colors_text[sqHud.left_color], x + 12, y + 11, 1, 1)
	-- Right team
	drawRect(x, y + 20, x + 25, y + 40, sqHud.team_colors_bg[sqHud.right_color])
	drawText(arena.roundScore(sqHud.right_team), sqHud.team_colors_text[sqHud.right_color], x + 12, y + 31, 1, 1)
end
