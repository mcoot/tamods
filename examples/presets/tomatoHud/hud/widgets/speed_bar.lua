function speed_bar(x, y)
	local barWidth = 25
	local barHeight = 200
	local precision = 200
	local speed_pct = math.min(math.floor(precision * (player.speed() - skiBarMin)/(skiBarMax - skiBarMin))/precision, 1)
	
	drawRect(x, y - barHeight/2, x + barWidth, y + barHeight/2, bg_color2)
	drawProgressBar(x, y - barHeight/2, x + barWidth, y + barHeight/2, speed_color, 0, speed_pct)
	drawBox(x, y - barHeight/2, x + barWidth, y + barHeight/2, health_energy_color_border)
	drawText(player.speed(), speed_color, x + barWidth/2, y - barHeight/2 - 10, 1, 1, 1)
end