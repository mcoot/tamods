sqHud.game_scores = function(x, y)
	-- Left
	drawRect(x, y, x + 40, y + 20, sqHud.team_colors_bg[sqHud.left_color])
	drawSmallText(game.score(sqHud.left_team), rgb(0,0,0), x + 19, y + 10, 1, 0, 1)
	-- Right
	drawRect(x, y + 20, x + 40, y + 40, sqHud.team_colors_bg[sqHud.right_color])
	drawSmallText(game.score(sqHud.right_team), rgb(0,0,0), x + 19, y + 30, 1, 0, 1)
end
