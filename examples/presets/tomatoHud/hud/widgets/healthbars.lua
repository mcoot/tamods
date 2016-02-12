function onDrawHealthBar(x, y, friendly, value)
	if value == 0 then
		return
	end
	drawRect(x - 21, y - 2, x + 21, y + 2, bg_color1)
	drawProgressBar(x - 20, y - 1, x + 20, y + 1, team_colors_bg[friendly and 1 or 0], 1, value)
end
