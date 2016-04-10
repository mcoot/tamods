local module = {}

module.name            = "sqFlagIndicator"  -- This HAS to be the same as the filename minus the trailing .lua
module.opts            = {}
module.opts.X_Position = 50.0
module.opts.Y_Position = 7.0
module.opts.String     = "Flag!"
module.opts.Text       = rgba(60,255,120,255)
module.opts.Background = rgba(0,0,0,120)

function module.draw(res_x, res_y)
	if not hud_data.alive then return end

	if player.hasFlag() then
		local xpos = math.floor(module.opts.X_Position / 100 * res_x)
		local ypos = math.floor(module.opts.Y_Position / 100 * res_y)

		local size = getSmallTextSize(module.opts.String, 1).x / 2 + 8
		drawRect(xpos - size, ypos, xpos + size, ypos + 26, module.opts.Background)
		drawSmallText(module.opts.String, module.opts.Text, xpos, ypos + 13, 1, 1, 1)
	end
end

return module
