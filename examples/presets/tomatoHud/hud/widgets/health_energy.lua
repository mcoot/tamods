function health_energy(x, y)
	local health_pct = player.health() / player.healthMax()
	local color = health_color_full
	if health_pct < 0.25 then
		color = health_color_low
	end
	local barWidth = 300
	local barHeight = 25
	local numSegments = 10

	-- Draw borders
	drawBox(x, y - barHeight * 2 - 4, x + barWidth, y - barHeight - 4, health_energy_color_border)
	drawBox(x, y - barHeight, x + barWidth, y, health_energy_color_border)
	-- Draw 300x25 background rectangles
	drawRect(x, y - barHeight * 2 - 4, x + barWidth, y - barHeight - 4, bg_color2)
	drawRect(x, y - barHeight, x + barWidth, y, bg_color2)
	-- Draw progress bars
	drawProgressBar(x + 2, y - barHeight * 2 - 4 + 2, x + barWidth - 2, y - barHeight - 4 - 2, color, 1, health_pct)
	drawProgressBar(x + 2, y - barHeight + 2, x + barWidth - 2, y - 2, energy_color, 1, player.energyPct())
	-- Draw segments
	for i=1,numSegments-1,1 do
		draw2dLine(x + i*(barWidth/numSegments), y - barHeight * 2 - 4, x + i*(barWidth/numSegments), y - barHeight - 4, health_energy_color_border)
		draw2dLine(x + i*(barWidth/numSegments), y - barHeight, x + i*(barWidth/numSegments), y, health_energy_color_border)
	end
	
	-- Draw the actual numbers
	drawUTText(player.health(), color, x + barWidth + 2, y - barHeight * 2 - 4 + barHeight/2, 0, 1, 1)
	drawUTText(math.floor(player.energy()), energy_color, x + barWidth + 2, y - barHeight/2, 0, 1, 1)
end
