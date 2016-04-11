local module = {}

module.name            = "sqStopwatch"  -- This HAS to be the same as the filename minus the trailing .lua
module.opts            = {}
module.opts.X_Position = 40.0
module.opts.Y_Position = 0.8
module.opts.Text       = rgba(180,255,0,255)
module.opts.Background = rgba(0,0,0,100)

function module.draw(res_x, res_y)
	if not stopwatch.isRunning() then return end

	local xpos = math.floor(module.opts.X_Position / 100 * res_x)
	local ypos = math.floor(module.opts.Y_Position / 100 * res_y)

	drawRect(xpos, ypos, xpos + 85, ypos + 26, module.opts.Background)
	drawSmallText(stopwatch.timeStr(), module.opts.Text, xpos + 8, ypos + 13, 0, 1, 1)
end

return module
