local module = {}

module.name                     = "sqPotatoWeaponBar"  -- This HAS to be the same as the filename minus the trailing .lua
module.opts                     = {}
module.opts.X_Position          = 0.0
module.opts.Y_Position          = 48.0
module.opts.Slot_Width          = 65
module.opts.Slot_Height         = 26
module.opts.Margin              = 2
module.opts.Current_Slot_Offset = 15
module.opts.Slot_Number         = rgba(255,255,255,100)
module.opts.Current_Slot        = rgba(255,255,0,255)
module.opts.Reloading_Slot      = rgba(255,0,0,255)
module.opts.Normal_Slot         = rgba(255,255,255,140)
module.opts.Deployable          = rgba(255,0,0,180)
module.opts.Background          = rgba(0,0,0,120)

function module.draw(res_x, res_y)
	if not hud_data.alive then return end

	local xpos = math.floor(module.opts.X_Position / 100 * res_x)
	local ypos = math.floor(module.opts.Y_Position / 100 * res_y)

	-- Heavy (ID 3) has 4 weapons, while light and medium have 3. All classes have belt items and packs
	local weapons = player.classId() == 3 and { 2,3,4,5,7,6 } or { 2,3,4,7,6 }
	local current = currentWeapon.equippedAt()

	for i,wep in ipairs(weapons) do
		-- Don't list packs that don't consume ammo
		if not (wep == 6 and weapon.isPack(6)) or weapon.ammo(wep) == -1 then
			local x
			local y = ypos + (module.opts.Slot_Height + module.opts.Margin) * (i - 1)
			local color
			if wep == current then
				x = xpos + module.opts.Current_Slot_Offset
				color = module.opts.Current_Slot
			else
				x = xpos
				color = weapon.isPassiveReady(wep) and module.opts.Normal_Slot or module.opts.Reloading_Slot
			end

			drawRect(x, y, x + module.opts.Slot_Width, y + module.opts.Slot_Height, module.opts.Background)
			drawSmallText(wep == 6 and "Pack" or wep == 7 and "Belt" or i, module.opts.Slot_Number, x + 5, y + 10, 0, 0, 1)
			drawText(weapon.ammoTotal(wep), color, x + module.opts.Slot_Width - 5, y + module.opts.Slot_Height / 2, 2, 1)

			if wep == 6 then
				for i = 0,player.numDeployables() - 1 do drawRect(x + 5 + 7 * i, y + module.opts.Slot_Height - 8, x + 9 + 7 * i, y + module.opts.Slot_Height - 4, module.opts.Deployable) end
			end
		end
	end
end

return module
