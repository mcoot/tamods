sqHud.ammo = function(x, y)
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
			color = rgb(0,255,0)
		else
			color = lerpColor(rgba(255,0,0,220), rgba(255,255,255,50), ammo_pct)
		end

		if ammo_carried == -1 then
			ammo_text = ammo
		else
			ammo_text = ammo .. "/" .. ammo_carried
		end

		local size = getUTTextSize(ammo_text, 1)

		drawRect(x - 2, y - 2, x + 206 + size.x, y + 28, sqHud.bg_color2)

		drawBox(x, y, x + 191, y + 26, color)
		drawProgressBar(x + 3, y + 3, x + 188, y + 23, color, 1, ammo_pct)
		drawUTText(ammo_text, color, x + 198, y + 13, 0, 0, 1)
	end
	drawRect(x - 2, y + 28, x + 55, y + 46, sqHud.bg_color2)
	drawSmallText("Belt: " .. weapon.ammo(7), rgba(255,255,255, 80), x + 3, y + 37, 0, 0, 1)
end
