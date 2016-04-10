local module = {}

module.name             = "sqHealthEnergy"  -- This HAS to be the same as the filename minus the trailing .lua
module.opts             = {}
module.opts.X_Position  = 16.0
module.opts.Y_Position  = 77.0
module.opts.Width       = 195
module.opts.Height      = 28
module.opts.Full_Health = rgba(16,133,232,135)
module.opts.Low_Health  = rgb(255,0,0)
module.opts.Energy      = rgba(161,209,213,120)
module.opts.Background  = rgba(0,0,0,50)

function module.draw(res_x, res_y)
	if not hud_data.alive then return end

	local xpos = math.floor(module.opts.X_Position / 100 * res_x)
	local ypos = math.floor(module.opts.Y_Position / 100 * res_y)

	local health_pct = player.health() / player.healthMax()
	local hp_color = lerpColor(module.opts.Low_Health, module.opts.Full_Health, health_pct)
	local speed = hud_data.vehicle and vehicle.speed() or player.speed()

	drawRect(xpos, ypos, xpos + module.opts.Width + 65, ypos + module.opts.Height * 2, module.opts.Background)

	-- Health
	drawBox(xpos + 2, ypos + 2, xpos + module.opts.Width - 2, ypos + module.opts.Height - 2, hp_color)
	drawProgressBar(xpos + 5, ypos + 5, xpos + module.opts.Width - 5, ypos + module.opts.Height - 5, hp_color, 1, health_pct)
	drawUTText(player.health(), hp_color, xpos + module.opts.Width + 6, ypos + module.opts.Height / 2, 0, 0, 1)

	ypos = ypos + module.opts.Height

	-- Energy
	drawBox(xpos + 2, ypos + 2, xpos + module.opts.Width - 2, ypos + module.opts.Height - 2, module.opts.Energy)
	drawProgressBar(xpos + 5, ypos + 5, xpos + module.opts.Width - 5, ypos + module.opts.Height - 5, module.opts.Energy, 1, player.energyPct())
	drawUTText(speed, module.opts.Energy, xpos + module.opts.Width + 6, ypos + module.opts.Height / 2, 0, 0, 1)
end

return module
