local module = {}

module.name            = "mcootChargeBar"  -- This HAS to be the same as the filename minus the trailing .lua
module.opts            = {}
module.opts.X_Position = 40.0
module.opts.Y_Position = 50.0
module.opts.Width 	   = 20
module.opts.Height	   = 60
module.opts.Segment_Thickness  = 3
module.opts.Segment_Spacing	   = 1
module.opts.Background_Color   = rgba(96 ,  96,  96, 96)
module.opts.Segment_Color	   = rgba(255,   0,   0, 164)
module.opts.Text_Color         = rgba(255, 255, 255, 255)

function module.draw(res_x, res_y)
	if not hud_data.alive then return end
	
	local xpos = math.floor(module.opts.X_Position / 100 * res_x)
	local ypos = math.floor(module.opts.Y_Position / 100 * res_y) - module.opts.Height / 2
	local width = module.opts.Width
	local height = module.opts.Height

	local isSniper = currentWeapon.name() == "BXT1 Rifle" or currentWeapon.name() == "BXT-1A Rifle" or currentWeapon.name() == "Phase Rifle" or currentWeapon.name() == "SAP20"
	local onlyShowZoomed = currentWeapon.name() == "BXT1 Rifle" or currentWeapon.name() == "BXT-1A Rifle"
	
	-- Only show charge for BXT while zoomed, but always show for Phase
	if onlyShowZoomed and not currentWeapon.isZoomed() then return end
	
	local damage = 0
	local progress = 0
	if isSniper then
		progress = currentWeapon.sniperChargePct()
		damage = currentWeapon.sniperDamage()
	else
		progress = currentWeapon.laserTargeterChargePct()
	end
	
	-- For laser, only show the bar when there is some charge
	if not isSniper and progress == 0 then return end
	
	-- Draw the progress bar background
	drawRect(xpos, ypos, xpos + width, ypos + height, module.opts.Background_Color)
	-- Draw the filled segments
	local c = 0.0
	local i = 0
	while c < progress do
		local y = ypos + height - 1 - i * (module.opts.Segment_Thickness + module.opts.Segment_Spacing)
		drawRect(xpos + 1, y - module.opts.Segment_Thickness, xpos + width - 1, y, module.opts.Segment_Color)
		i = i + 1
		c = c + (module.opts.Segment_Thickness + module.opts.Segment_Spacing) / (height - 2)
	end
	
	-- If a sniper rifle, draw the damage as text
	if isSniper then
		textSize = getSmallTextSize(math.ceil(damage), 1)
		drawSmallText(math.ceil(damage), module.opts.Text_Color, xpos + width / 2, ypos - textSize.y, enums.TEXT_ALIGN_CENTER, 1, 1)
	end
end

return module
