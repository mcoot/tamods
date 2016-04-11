local module = {}

module.name              = "sqGameTime"  -- This HAS to be the same as the filename minus the trailing .lua
module.opts              = {}
module.opts.X_Position   = 47.3
module.opts.Y_Position   = 0.0
module.opts.Text         = rgb(255,255,255)
module.opts.Background_1 = rgba(0,0,0,75)
module.opts.Background_2 = rgba(0,0,0,50)

function module.draw(res_x, res_y)
	local xpos = math.floor(module.opts.X_Position / 100 * res_x)
	local ypos = math.floor(module.opts.Y_Position / 100 * res_y)

	-- Draw the game time and it's background
	drawRect(xpos, ypos, xpos + 80, ypos + 40, module.opts.Background_1)
	drawUTText(game.timeStr(), module.opts.Text, xpos + 40, ypos + 20, 1, 1, 1)

	-- Draw a warmup indicator below it
	if game.isWarmUp() then
		drawRect(xpos + 5, ypos + 40, xpos + 75, ypos + 60, module.opts.Background_2)
		drawSmallText("WARMUP", module.opts.Text, xpos + 40, ypos + 50, 1, 1, 1)
	end
end

return module
