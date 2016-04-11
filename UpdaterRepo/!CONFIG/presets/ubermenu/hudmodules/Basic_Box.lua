local module = {}

module.name                = "Basic_Box"  -- This HAS to be the same as the filename minus the trailing .lua
module.opts                = {}
module.opts.X_Position     = 50.0
module.opts.Y_Position     = 30.0
module.opts.Width          = 50.0
module.opts.Height         = 100.0
module.opts.Hide_When_Dead = true
module.opts.Color          = rgba(0,0,0,255)

function module.draw(res_x, res_y)
	if module.opts.Hide_When_Dead and not hud_data.alive then return end

	local xpos = math.floor(module.opts.X_Position / 100 * res_x)
	local ypos = math.floor(module.opts.Y_Position / 100 * res_y)

	drawBox(xpos, ypos, xpos + module.opts.Width, ypos + module.opts.Height, module.opts.Color)
end

return module
