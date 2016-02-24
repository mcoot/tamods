function speedometer(x, y)
	local barWidth = 10
	local barHeight = 200
	local precision = 200
	local speed_pct = math.min(math.floor(precision * (player.speed() - skiBarMin)/(skiBarMax - skiBarMin))/precision, 1)
	local speed_color = lerpColor(rgb(255, 255, 0), rgb(255, 0, 0), speed_pct)
	
	drawRect(x - 6, y - barHeight/2 - 6, x + barWidth + 6, y + barHeight/2 + 6, rgb(0, 0, 0))
	drawProgressBar(x, y - barHeight/2, x + barWidth, y + barHeight/2, speed_color, 0, speed_pct)
	drawBox(x - 4, y - barHeight/2 - 4, x + barWidth + 4, y + barHeight/2 + 4, speed_color)
	
	drawRect(x - 46, y - 12, x - 6, y + 12, bg_color1)
	drawSmallText(player.speed(), speed_color, x - 23, y, 1, 1, 1)
end