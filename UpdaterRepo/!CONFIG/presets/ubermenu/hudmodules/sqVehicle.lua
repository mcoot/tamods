local module = {}

module.name                = "sqVehicle"  -- This HAS to be the same as the filename minus the trailing .lua
module.opts                = {}
module.opts.X_Position     = 48.15
module.opts.Y_Position     = 88.0
module.opts.Text           = rgba(255,255,255,255)
module.opts.Background     = rgba(0,0,0,75)
module.opts.Health         = rgba(72,191,129,180)
module.opts.Energy         = rgba(161,209,213,160)

-- The drawing function for this module
function module.draw(res_x, res_y)
	if not hud_data.vehicle then return end

	local xpos = math.floor(module.opts.X_Position / 100 * res_x)
	local ypos = math.floor(module.opts.Y_Position / 100 * res_y)

	local health     = vehicle.health()
	local health_pct = health / vehicle.healthMax()
	local energy_pct = vehicle.energyPct()
	local energy     = math.floor(energy_pct * 100)

	-- Ammo, not as gravcycle passenger (-1 ammo) or for the beowulf cannon (1 ammo)
	if vehicle.ammoMax() > 1 then
		drawSmallText(vehicle.ammo() .. "/" .. vehicle.ammoMax(), module.opts.Text, xpos + 28, ypos, 1, 1, 1)
	end

	ypos = ypos + 12
	-- Health
	drawRect(xpos, ypos, xpos + 18, ypos + 88, module.opts.Background)
	drawBox(xpos, ypos, xpos + 18, ypos + 88, module.opts.Health)
	drawProgressBar(xpos + 3, ypos + 3, xpos + 15, ypos + 85, module.opts.Health, 0, health_pct)
	drawSmallText(health, module.opts.Health, xpos + 9, ypos + 98, 1, 1, 1)
	-- Energy
	xpos = xpos + 35
	drawRect(xpos, ypos, xpos + 18, ypos + 88, module.opts.Background)
	drawBox(xpos, ypos, xpos + 18, ypos + 88, module.opts.Energy)
	drawProgressBar(xpos + 3, ypos + 3, xpos + 15, ypos + 85, module.opts.Energy, 0, energy_pct)
	drawSmallText(energy, module.opts.Energy, xpos + 9, ypos + 98, 1, 1, 1)
end

return module
