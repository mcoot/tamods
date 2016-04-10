local module = {}

module.name            = "sqIFF_Healthbars"  -- This HAS to be the same as the filename minus the trailing .lua
module.opts            = {}
module.opts.Offset_Y   = 0
module.opts.Width      = 45
module.opts.Height     = 4
module.opts.Background = rgba(0,0,0,75)

local onDrawHealthBarOld
if type(onDrawHealthBar) == "function" then
	onDrawHealthBarOld = onDrawHealthBar
end

function onDrawHealthBar(x, y, friendly, value)
	if onDrawHealthBarOld then onDrawHealthBarOld(x, y, friendly, value) end

	if value == 0 then
		return
	end

	local color = hud_colors and (hud_colors.opts.Team_Background[friendly and 1 or 0]) or rgb(255,255,255) 

	x = x - module.opts.Width / 2
	y = y - module.opts.Height / 2 + module.opts.Offset_Y
	drawRect(x, y, x + module.opts.Width, y + module.opts.Height, module.opts.Background)
	drawProgressBar(x + 1, y + 1, x - 1 + module.opts.Width, y - 1 + module.opts.Height, color, 1, value)
end

return module
