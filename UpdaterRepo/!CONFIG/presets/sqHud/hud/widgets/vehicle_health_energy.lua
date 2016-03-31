function vehicle_health_energy(x, y)
	local health     = vehicle.health()
	local health_pct = health / vehicle.healthMax()
	local energy_pct = vehicle.energyPct()
	local energy     = math.floor(energy_pct * 100)

	-- Health
	drawRect(x, y, x + 18, y + 88, bg_color1)
	drawBox(x, y, x + 18, y + 88, health_color_full)
	drawProgressBar(x + 2, y + 3, x + 14, y + 85, health_color_full, 0, health_pct)
	drawSmallText(health, health_color_full, x + 9, y + 98, 1, 1, 1)
	-- Energy
	x = x + 35
	drawRect(x, y, x + 18, y + 88, bg_color1)
	drawBox(x, y, x + 18, y + 88, energy_color)
	drawProgressBar(x + 2, y + 3, x + 14, y + 85, energy_color, 0, energy_pct)
	drawSmallText(energy, energy_color, x + 9, y + 98, 1, 1, 1)
end
