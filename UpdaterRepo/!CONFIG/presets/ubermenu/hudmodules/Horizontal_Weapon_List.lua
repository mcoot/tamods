local module = {}

module.name              = "Horizontal_Weapon_List"
module.opts              = {}
module.opts.X_Position   = 50.0
module.opts.Y_Position   = 99.0

module.opts.Background_Color		= rgba(0, 0, 0, 75)
module.opts.Box_Height				= 35
module.opts.Box_Minimum_Width		= 80
module.opts.Box_Maximum_Width		= 120
module.opts.Weapon_Name_Text_Size	= 1.0
module.opts.Weapon_Name_Color		= rgba(255, 255, 255, 200)
module.opts.Weapon_Number_Color		= rgba(255, 255, 255, 100)
module.opts.Ammo_Color_Selected		= rgba(64, 255, 255, 255)
module.opts.Ammo_Color_Unselected	= rgb(255, 255, 255)
module.opts.Ammo_Color_Reloading 	= rgb(255, 0, 0)
module.opts.Deployable_Color		= rgba(255, 0, 0, 180)
module.opts.Shorten_Weapon_Names	= true


function get_weapon_name_abbr(weaponName)
	local shortWepNames = {}
	shortWepNames["Light Grenade Launcher"] = "Light GL"
	shortWepNames["Grenade Launcher"] = "GL"
	shortWepNames["Anti-Personnel Grenade"] = "AP Grenade"
	shortWepNames["Light Assault Rifle"] = "LAR"
	shortWepNames["Heavy Bolt Launcher"] = "Heavy Bolt"
	shortWepNames["Automatic Shotgun"] = "Auto Shotgun"
	
	if shortWepNames[weaponName] ~= nil then
		return shortWepNames[weaponName]
	end
	return weaponName
end

function module.draw(res_x, res_y)
	local x = math.floor(module.opts.X_Position / 100 * res_x)
	local y = math.floor(module.opts.Y_Position / 100 * res_y)
	
	-- Heavy (ID 3) has 4 weapons, while light and medium have 3. All classes have belt items and packs
	local weapons = player.classId() == 3 and { 2,3,4,5,7,6 } or { 2,3,4,7,6 }
	local current = currentWeapon.equippedAt()
	local boxWidth = module.opts.Box_Minimum_Width
	local boxMaxWidth = module.opts.Box_Maximum_Width
	local boxHeight = module.opts.Box_Height
	local xStart = x
	
	
	-- Calculate total width needed
	for i, wep in ipairs(weapons) do
		if not ((wep == 6 and weapon.isPack(6)) or weapon.ammo(wep) == -1) then
			xStart = xStart - (math.max(getSmallTextSize(get_weapon_name_abbr(weapon.name(wep)), 1).x + 4, boxWidth) + 4) / 2
		end
	end
	
	for i, wep in ipairs(weapons) do
		-- Don't list packs that don't consume ammo
		if not ((wep == 6 and weapon.isPack(6)) or weapon.ammo(wep) == -1) then
			local x_pos = xStart
			local y_pos = y - boxHeight
			
			-- Try to prevent super wide boxes if shorten names is enabled
			local wepString = module.opts.Shorten_Weapon_Names and get_weapon_name_abbr(weapon.name(wep)) or weapon.name(wep)
			local myWidth = math.max(getSmallTextSize(wepString, module.opts.Weapon_Name_Text_Size).x + 4, boxWidth)
			
			xStart = xStart + myWidth + 4
			local color = module.opts.Ammo_Color_Unselected
			if wep == current then
				y_pos = y_pos - 10
				color = module.opts.Ammo_Color_Selected
			else
				color = weapon.isPassiveReady(wep) and module.opts.Ammo_Color_Unselected or module.opts.Ammo_Color_Reloading
			end

			drawRect(x_pos, y_pos, x_pos + myWidth, y_pos + boxHeight, module.opts.Background_Color)
		
			drawSmallText(wepString, module.opts.Weapon_Name_Color, x_pos + myWidth/2, y_pos + 8, 1, 0, module.opts.Weapon_Name_Text_Size)
			drawSmallText(wep == 6 and "Pack" or wep == 7 and "Belt" or i, module.opts.Weapon_Number_Color, x_pos + 2, y_pos + boxHeight - 8, 0, 0, 1);
			drawText(weapon.ammoTotal(wep), color, x_pos + myWidth/2, y_pos + boxHeight - 8, 1, 1)

			if wep == 7 then
				for i = 0,player.numMines() - 1 do drawRect(x_pos + 9 + 7 * i, y_pos + 20, x_pos + 13 + 7 * i, y_pos + 24, module.opts.Deployable_Color) end
			elseif wep == 6 then
				for i = 0,player.numDeployables() - 1 do drawRect(x_pos + 9 + 7 * i, y_pos + 20, x_pos + 13 + 7 * i, y_pos + 24, module.opts.Deployable_Color) end
			end
		end
	end
end

return module
