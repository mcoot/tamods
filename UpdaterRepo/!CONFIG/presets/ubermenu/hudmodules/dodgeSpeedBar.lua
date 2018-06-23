local module = {}

module.name                = "dodgeSpeedBar"  -- This HAS to be the same as the filename minus the trailing .lua
module.opts                = {}
module.opts.X1_Position     = 0.3
module.opts.Y1_Position     = 56
module.opts.X2_Position     = 99.7
module.opts.Y2_Position     = 56
module.opts.Segments       = 10
module.opts.Margin         = 1
module.opts.Width          = 12
module.opts.Height         = 25
module.opts.minSpeed       = -1
module.opts.Dynamic_Color  = true
module.opts.Full           = rgba(138,43,226,255)
module.opts.Low            = rgba(0, 255, 255,80)
module.opts.Empty_Segments = rgba(0,0,0,120)

function module.draw(res_x, res_y)
	if not hud_data.alive then return end

	local x1pos = math.floor(module.opts.X1_Position / 100 * res_x)
	local y1pos = math.floor(module.opts.Y1_Position / 100 * res_y)
	local x2pos = math.floor(module.opts.X2_Position / 100 * res_x)
	local y2pos = math.floor(module.opts.Y2_Position / 100 * res_y)
	local val = hud_data.vehicle and vehicle.speed() or player.speed()
	local pct = skiBarMax and val / skiBarMax or val / 300

	local color
	local segments = math.ceil(module.opts.Segments * pct)

	if(val > module.opts.minSpeed) then 
		for i = 1,module.opts.Segments do
			color = lerpColor(module.opts.Low, module.opts.Full, i / module.opts.Segments)
			if i > segments then color = module.opts.Empty_Segments end

			drawRect(x1pos, y1pos, x1pos + module.opts.Width + ((module.opts.Segments - i) * 2), y1pos + module.opts.Height, color)
			drawRect(x2pos - module.opts.Width - ((module.opts.Segments - i) * 2), y2pos, x2pos, y2pos + module.opts.Height, color)
			
			y1pos = y1pos - module.opts.Margin - module.opts.Height
			y2pos = y2pos - module.opts.Margin - module.opts.Height
		end
	end


end

return module
