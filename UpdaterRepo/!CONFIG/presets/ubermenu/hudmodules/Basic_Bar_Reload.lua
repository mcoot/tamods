local module = {}

module.name               = "Basic_Bar_Reload"  -- This HAS to be the same as the filename minus the trailing .lua
module.opts               = {}
module.opts.X_Position    = 50.0
module.opts.Y_Position    = 30.0
module.opts.Direction     = 1
module.opts.Width         = 185
module.opts.Height        = 20
module.opts.Dynamic_Color = true
module.opts.Full          = rgba(255,255,255,255)
module.opts.Low           = rgba(255,0,0,255)
module.opts.Reloaded      = rgba(0,255,0,255)
module.opts.Background    = rgba(0,0,0,120)

local timestamp

function module.draw(res_x, res_y)
	if not hud_data.alive or not currentWeapon.isReloading() then
		timestamp = nil
		return
	end

	local xpos = math.floor(module.opts.X_Position / 100 * res_x)
	local ypos = math.floor(module.opts.Y_Position / 100 * res_y)

	if not timestamp then
		timestamp = game.timeSeconds()
	end
	local pct = (game.timeSeconds() - timestamp) / currentWeapon.reloadTimeFull()

	local color
	if module.opts.Dynamic_Color then
		if timestamp and currentWeapon.isReloaded() then
			color = module.opts.Reloaded
		else
			color = lerpColor(module.opts.Low, module.opts.Full, pct)
		end
	else
		color = module.opts.Full
	end

	drawRect(       xpos,
	                ypos,
	                xpos + module.opts.Width,
	                ypos + module.opts.Height,
	                module.opts.Background
	)
	drawProgressBar(xpos,
	                ypos,
	                xpos + module.opts.Width,
	                ypos + module.opts.Height,
	                color,
	                module.opts.Direction,
	                pct
	)
end

return module
