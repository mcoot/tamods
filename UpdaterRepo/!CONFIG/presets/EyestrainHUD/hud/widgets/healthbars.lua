function onDrawHealthBar(x, y, friendly, value)
	if value == 0 then
		return
	end
	drawRect(x - 21, y - 3, x + 21, y + 3, rgb(0, 0, 0))
	drawProgressBar(x - 20, y - 2, x + 20, y + 2, team_colors_bg[friendly and 1 or 0], 1, value)
end
