function health_energy(x, y)
	local health_pct = player.health() / player.healthMax()
	local color = lerpColor(health_color_low, health_color_full, health_pct)

	-- Draw borders
	drawBox(x - 302, y, x - 2, y + 25, color)
	drawBox(x + 2, y, x + 302, y + 25, energy_color)
	-- Draw 300x25 background rectangles
	drawRect(x - 302, y, x - 2, y + 25, bg_color2)
	drawRect(x + 2, y, x + 302, y + 25, bg_color2)
	-- Draw progress bars
	drawProgressBar(x - 298, y + 4, x - 6, y + 21, color, 3, health_pct)
	drawProgressBar(x + 6, y + 4, x + 298, y + 21, energy_color, 1, player.energyPct())
	-- Draw the actual numbers
	drawUTText(player.health(), color, x - 10, y - 20, 2, 2, 2)
	drawUTText(math.floor(player.energy()), energy_color, x + 10, y - 20, 0, 2, 2)
end
