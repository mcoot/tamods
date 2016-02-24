function health_energy(x, y)
	local health_pct = player.health() / player.healthMax()
	local color = lerpColor(health_color_low, health_color_full, health_pct)
	
	-- Black backgrounds
	drawRect(x, y, x + 304, y + 19, rgb(0, 0, 0))
	drawRect(x, y + 22, x + 304, y + 41, rgb(0, 0, 0))
	-- Draw borders
	drawBox(x + 2, y + 2, x + 302, y + 17, color)
	drawBox(x + 2, y + 24, x + 302, y + 39, energy_color)
	-- Draw progress bars
	drawProgressBar(x + 6, y + 6, x + 298, y + 13, color, 1, health_pct)
	drawProgressBar(x + 6, y + 28, x + 298, y + 35, energy_color, 1, player.energyPct())
	-- Draw the actual numbers
	drawRect(x + 304, y, x + 355, y + 19, bg_color1)
	drawRect(x + 304, y + 22, x + 355, y + 41, bg_color1)
	
	drawSmallText(player.health(), color, x + 329, y + 9, 1, 1, 1)
	drawSmallText(math.floor(player.energy()), energy_color, x + 329, y + 31, 1, 1, 1)
end
