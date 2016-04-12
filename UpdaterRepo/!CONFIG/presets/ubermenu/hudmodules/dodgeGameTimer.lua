local module = {}

module.name              = "dodgeGameTimer"  -- This HAS to be the same as the filename minus the trailing .lua
module.opts              = {}         -- Options, you can add your own here
module.opts.X_Position   = 50      -- Position variables should be screen percentage based
module.opts.Y_Position   = 0
module.opts.Text         = rgba(255,255,255,255)
module.opts.bg_color = rgba(0, 0, 0, 125)

-- The drawing function for this module
function module.draw(res_x, res_y)
	local xpos = math.floor(module.opts.X_Position / 100 * res_x)
	local ypos = math.floor(module.opts.Y_Position / 100 * res_y)
	
	-- Draw the game time and it's background
	drawRect(xpos - 25, ypos, xpos + 25, ypos + 40, module.opts.bg_color)
	drawSmallText(game.timeStr(), module.opts.Text, xpos, ypos + 20, 1, 1, 1)

	-- Draw a warmup indicator below it
	if game.isWarmUp() then
		drawRect(xpos - 35, ypos - 200, xpos + 35, ypos - 220, module.opts.bg_color)
		drawSmallText("WARMUP", module.opts.Text, xpos, ypos - 210, 1, 1, 1)
	end
end

return module