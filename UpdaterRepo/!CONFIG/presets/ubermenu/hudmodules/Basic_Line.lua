local module = {}

module.name                = "Basic_Line"  -- This HAS to be the same as the filename minus the trailing .lua
module.opts                = {}
module.opts.Start_X        = 30.0
module.opts.Start_Y        = 30.0
module.opts.End_X          = 50.0
module.opts.End_Y          = 40.0
module.opts.Hide_When_Dead = true
module.opts.Color          = rgb(0,0,0)

function module.draw(res_x, res_y)
	if module.opts.Hide_When_Dead and not hud_data.alive then return end

	local x1 = math.floor(module.opts.Start_X / 100 * res_x)
	local y1 = math.floor(module.opts.Start_Y / 100 * res_y)
	local x2 = math.floor(module.opts.End_X / 100 * res_x)
	local y2 = math.floor(module.opts.End_Y / 100 * res_y)

	draw2dLine(x1, y1, x2, y2, module.opts.Color)
end

return module
