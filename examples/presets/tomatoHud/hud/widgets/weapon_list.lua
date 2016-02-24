function weapon_list(x, y)
	-- Heavy (ID 3) has 4 weapons, while light and medium have 3. All classes have belt items and packs
	local weapons = player.classId() == 3 and { 2,3,4,5,7,6 } or { 2,3,4,7,6 }
	local current = currentWeapon.equippedAt()
	local boxWidth = 80
	local boxHeight = 35
	local xStart = x
	
	-- Calculate total width needed
	for i, wep in ipairs(weapons) do
		if not ((wep == 6 and weapon.isPack(6)) or weapon.ammo(wep) == -1) then
			xStart = xStart - (math.max(getSmallTextSize(weapon.name(wep), 1).x + 4, boxWidth) + 4) / 2
		end
	end
	
	for i, wep in ipairs(weapons) do
		-- Don't list packs that don't consume ammo
		if not ((wep == 6 and weapon.isPack(6)) or weapon.ammo(wep) == -1) then
			local x_pos = xStart
			local y_pos = y - boxHeight
			local myWidth = math.max(getSmallTextSize(weapon.name(wep), 1).x + 4, boxWidth)
			xStart = xStart + myWidth + 4
			local color = text_color1
			if wep == current then
				y_pos = y_pos - 10
				color = rgba(255, 255, 0, 255)
			else
				color = weapon.isPassiveReady(wep) and rgba(255, 255, 255, 140) or text_color3
			end

			drawRect(x_pos, y_pos, x_pos + myWidth, y_pos + boxHeight, bg_color1)
			drawSmallText(weapon.name(wep), rgba(255, 255, 255, 200), x_pos + myWidth/2, y_pos + 8, 1, 0, 1) --wep == 6 and "Pack" or wep == 7 and "Belt" or i
			drawSmallText(wep == 6 and "Pack" or wep == 7 and "Belt" or i, rgba(255, 255, 255, 100), x_pos + 2, y_pos + boxHeight - 8, 0, 0, 1);
			drawText(weapon.ammoTotal(wep), color, x_pos + myWidth/2, y_pos + boxHeight - 8, 1, 1)

			if wep == 7 then
				for i = 0,player.numMines() - 1 do drawRect(x_pos + 9 + 7 * i, y_pos + 20, x_pos + 13 + 7 * i, y_pos + 24, rgba(255, 0, 0, 180)) end
			elseif wep == 6 then
				for i = 0,player.numDeployables() - 1 do drawRect(x_pos + 9 + 7 * i, y_pos + 20, x_pos + 13 + 7 * i, y_pos + 24, rgba(255, 0, 0, 180)) end
			end
		end
	end
end
