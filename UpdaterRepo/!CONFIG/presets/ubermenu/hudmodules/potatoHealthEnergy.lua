local module = {}

module.name             = "potatoHealthEnergy"  -- This HAS to be the same as the filename minus the trailing .lua
module.opts             = {}
module.opts.X_Position  = 50.0
module.opts.Y_Position  = 97.0
module.opts.Width       = 300
module.opts.Height      = 25
module.opts.Full_Health = rgba(195,248,212,200)
module.opts.Low_Health  = rgb(235,22,51)
module.opts.Energy      = rgba(161,209,213,200)
module.opts.Background  = rgba(0,0,0,50)

function module.draw(res_x, res_y)
	if not hud_data.alive then return end

	local xpos = math.floor(module.opts.X_Position / 100 * res_x)
	local ypos = math.floor(module.opts.Y_Position / 100 * res_y)

	local health_pct = player.health() / player.healthMax()
	local color = lerpColor(module.opts.Low_Health, module.opts.Full_Health, health_pct)

	-- Draw borders
	drawBox(xpos - module.opts.Width - 2, ypos, xpos - 2, ypos + module.opts.Height, color)
	drawBox(xpos + 2, ypos, xpos + 2 + module.opts.Width, ypos + module.opts.Height, module.opts.Energy)
	-- Draw 300x25 background rectangles
	drawRect(xpos - module.opts.Width - 2, ypos, xpos - 2, ypos + module.opts.Height, module.opts.Background)
	drawRect(xpos + 2, ypos, xpos + 2 + module.opts.Width, ypos + module.opts.Height, module.opts.Background)
	-- Draw progress bars
	drawProgressBar(xpos - module.opts.Width + 2, ypos + 4, xpos - 6, ypos + module.opts.Height - 4, color, 3, health_pct)
	drawProgressBar(xpos + 6, ypos + 4, xpos + module.opts.Width - 2, ypos + module.opts.Height - 4, module.opts.Energy, 1, player.energyPct())
	-- Draw the actual numbers
	drawUTText(player.health(), color, xpos - 10, ypos - 20, 2, 2, 2)
	drawUTText(math.floor(player.energy()), module.opts.Energy, xpos + 10, ypos - 20, 0, 2, 2)
end

return module
