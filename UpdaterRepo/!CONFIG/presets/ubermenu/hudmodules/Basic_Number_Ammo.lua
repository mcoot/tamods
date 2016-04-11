local module = {}

module.name               = "Basic_Number_Ammo"  -- This HAS to be the same as the filename minus the trailing .lua
module.opts               = {}
module.opts.X_Position    = 50.0
module.opts.Y_Position    = 30.0
module.opts.Alignment     = 0
module.opts.Size          = 1
module.opts.Font          = 1
module.opts.Shadow_Size   = 1
module.opts.Dynamic_Color = true
module.opts.Full          = rgba(255,255,255,255)
module.opts.Low           = rgba(255,0,0,255)
module.opts.Reloaded      = rgba(0,255,0,255)

function module.draw(res_x, res_y)
	if not hud_data.alive then return end

	local xpos = math.floor(module.opts.X_Position / 100 * res_x)
	local ypos = math.floor(module.opts.Y_Position / 100 * res_y)
	local val
	local pct
	if currentWeapon.ammoMax() == 1 then
		val = currentWeapon.ammoTotal()
		pct = val / (currentWeapon.ammoMaxCarried() + 1)
	else
		val = currentWeapon.ammo()
		pct = val / currentWeapon.ammoMax()
	end

	local color
	if module.opts.Dynamic_Color then
		if not currentWeapon.isReadyToFire() and currentWeapon.isReloaded() then
			color = module.opts.Reloaded
		else
			color = lerpColor(module.opts.Low, module.opts.Full, pct)
		end
	else
		color = module.opts.Full
	end

	if module.opts.Font == 1 then
		drawUTText(val, color, xpos, ypos, module.opts.Alignment, module.opts.Shadow_Size, module.opts.Size)
	elseif module.opts.Font == 2 then
		drawSmallText(val, color, xpos, ypos, module.opts.Alignment, module.opts.Shadow_Size, module.opts.Size)
	else
		drawText(val, color, xpos, ypos, module.opts.Alignment, module.opts.Size)
	end
end

return module
