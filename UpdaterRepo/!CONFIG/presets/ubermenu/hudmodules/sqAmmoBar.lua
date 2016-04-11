local module = {}

module.name                = "sqAmmoBar"  -- This HAS to be the same as the filename minus the trailing .lua
module.opts                = {}
module.opts.X_Position     = 63.0
module.opts.Y_Position     = 77.0
module.opts.Width          = 195
module.opts.Height         = 28
module.opts.Full_Ammo      = rgba(255,255,255,50)
module.opts.Empty_Ammo     = rgba(255,0,0,220)
module.opts.Reload_Cancel_Indicator = rgb(255,0,255)
module.opts.Background     = rgba(0,0,0,50)

function module.draw(res_x, res_y)
	if not hud_data.alive then return end

	local xpos = math.floor(module.opts.X_Position / 100 * res_x)
	local ypos = math.floor(module.opts.Y_Position / 100 * res_y)

	if currentWeapon.equippedAt() <= 5 then

		local ammo
		local ammo_carried
		local ammo_pct
		local ammo_text

		if currentWeapon.ammoMax() == 1 then
			ammo = currentWeapon.ammoTotal()
			ammo_carried = -1
			ammo_pct = ammo / (currentWeapon.ammoMaxCarried() + 1)
		else
			ammo = currentWeapon.ammo()
			ammo_carried = currentWeapon.ammoCarried()
			ammo_pct = ammo / currentWeapon.ammoMax()
		end

		local color

		if not currentWeapon.isReadyToFire() and currentWeapon.isReloaded() then
			color = module.opts.Reload_Cancel_Indicator
		else
			color = lerpColor(module.opts.Empty_Ammo, module.opts.Full_Ammo, ammo_pct)
		end

		if ammo_carried == -1 then
			ammo_text = ammo
		else
			ammo_text = ammo .. "/" .. ammo_carried
		end

		local size = getUTTextSize(ammo_text, 1)

		drawRect(xpos, ypos, xpos + module.opts.Width + size.x + 12, ypos + module.opts.Height, module.opts.Background)

		drawBox(xpos + 2, ypos + 2, xpos + module.opts.Width - 2, ypos + module.opts.Height - 2, color)
		drawProgressBar(xpos + 5, ypos + 5, xpos + module.opts.Width - 5, ypos + module.opts.Height - 5, color, 1, ammo_pct)
		drawUTText(ammo_text, color, xpos + module.opts.Width + 5, ypos + module.opts.Height / 2, 0, 0, 1)
	end
	drawRect(xpos, ypos + module.opts.Height, xpos + 55, ypos + module.opts.Height + 20, module.opts.Background)
	drawSmallText("Belt: " .. weapon.ammo(7), rgba(255,255,255, 80), xpos + 3, ypos + module.opts.Height + 10, 0, 0, 1)
end

return module
