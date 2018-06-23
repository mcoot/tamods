local module = {}

module.name            = "indiIFF_Healthbars"  -- This HAS to be the same as the filename minus the trailing .lua
module.opts            = {}
module.opts.Offset_Y   = 0
module.opts.Width      = 45
module.opts.Height     = 4
module.opts.Full_Health = rgba(57,255,20,255)
module.opts.Low_Health  = rgb(255,0,0)
module.opts.Background = rgba(0,0,0,75)
module.opts.UseSmallText = false

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
	local hp_color = lerpColor(module.opts.Low_Health, module.opts.Full_Health, value)

	x = x - module.opts.Width / 2
	y = y - module.opts.Height / 2 + module.opts.Offset_Y
	
	if module.opts.UseSmallText then
		drawSmallText(math.ceil(value*100), hp_color, x + module.opts.Width + 20, y + module.opts.Height+2,1,1,1)
	else
		drawText(math.ceil(value*100), hp_color, x + module.opts.Width + 20, y + module.opts.Height+2,1,1,1)
	end
	
	drawRect(x, y, x + module.opts.Width, y + module.opts.Height, module.opts.Background)
	drawProgressBar(x + 1, y + 1, x - 1 + module.opts.Width, y - 1 + module.opts.Height, color, 1, value)
	
	
end

return module
