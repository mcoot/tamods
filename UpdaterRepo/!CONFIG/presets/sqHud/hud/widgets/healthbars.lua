local onDrawHealthBarOld
if type(onDrawHealthBar) == "function" then
	onDrawHealthBarOld = onDrawHealthBar
end

function onDrawHealthBar(x, y, friendly, value)
	if onDrawHealthBarOld then onDrawHealthBarOld(x, y, friendly, value) end

	if value == 0 then
		return
	end
	drawRect(x - 21, y - 2, x + 21, y + 2, sqHud.bg_color1)
	drawProgressBar(x - 20, y - 1, x + 20, y + 1, sqHud.team_colors_bg[friendly and 1 or 0], 1, value)
end
