local module = {}

-- 95% of this code is stolen from dodgeHealthEnergy lol

module.name                  = "mcootVehicleHealthEnergy"  -- This HAS to be the same as the filename minus the trailing .lua
module.opts                  = {}
module.opts.X_Position       = 90.0
module.opts.Y_Position       = 90.0
module.opts.x_barSize        = 15
module.opts.y_barSize        = 20
module.opts.x_barPadding     = 2
module.opts.y_barPadding     = 2
module.opts.Show_Vehicle_Name = true
module.opts.Show_Vehicle_Seat = true
module.opts.Full_Health      = rgba(211,240,220,150)
module.opts.Low_Health       = rgba(230,30,30,150)
module.opts.Energy           = rgba(150,200,200,150)
module.opts.Background       = rgba(0,0,0,125)
module.opts.BackgroundHurt   = rgba(50,0,0,125)
module.opts.Box              = rgba(130,192,145,150)
module.hp_color              = module.opts.Full_Health
module.Background            = module.opts.Full_Health
module.boxColor              = module.opts.Full_Health

function module.draw(res_x, res_y)
	if not hud_data.alive or not player.isVehicle() then 
		return 
	end
	
	local xright = math.floor(module.opts.X_Position / 100 * res_x)
	local xpos = xright - ((module.opts.x_barSize + module.opts.x_barPadding) * 10) - module.opts.x_barPadding - 90
	local ypos = math.floor(module.opts.Y_Position / 100 * res_y)
	
	local v_health_pct = vehicle.health() / vehicle.healthMax()
	local i = 0.1
	local healthBarLoc = xright - module.opts.x_barPadding
	-- Health
	if v_health_pct <= 1 then
		if v_health_pct <= 0.2 then 
			module.hp_color = module.opts.Low_Health
			module.Background = module.opts.BackgroundHurt
			module.boxColor = module.opts.Low_Health
		else
			module.hp_color = module.opts.Full_Health
			module.Background = module.opts.Background
			module.boxColor = module.opts.Box
		end
		
		drawRect(xpos - module.opts.x_barPadding, ypos - module.opts.y_barPadding, xpos + ((module.opts.x_barSize + module.opts.x_barPadding) * 10) + module.opts.x_barPadding + 90, ypos + ((module.opts.y_barSize + (module.opts.y_barPadding * 2)) * 2), module.Background)
		drawBox(xpos - module.opts.x_barPadding, ypos - module.opts.y_barPadding, xpos + ((module.opts.x_barSize + module.opts.x_barPadding) * 10) + (module.opts.x_barPadding * 2) + 90, ypos + ((module.opts.y_barSize + (module.opts.y_barPadding * 2)) * 2), module.boxColor)
		
		repeat
				drawRect(healthBarLoc - module.opts.x_barSize, ypos + module.opts.y_barPadding, healthBarLoc, ypos + module.opts.y_barSize, module.hp_color)
				healthBarLoc = healthBarLoc - module.opts.x_barSize - module.opts.x_barPadding
				i = i + 0.1
		until i >= v_health_pct
		drawSmallText(vehicle.health(), module.hp_color, xpos, ypos + module.opts.y_barPadding + (module.opts.y_barSize / 2), 0, 1, 2)
	end
	
	
	-- Energy
	local energyBarLoc = xright - module.opts.x_barPadding
	local j = 0.1
	while j < vehicle.energyPct() do
			drawRect(energyBarLoc - module.opts.x_barSize, ypos + module.opts.y_barSize + (module.opts.y_barPadding * 2), energyBarLoc, ypos + (module.opts.y_barSize * 2) + (module.opts.y_barPadding * 2), module.opts.Energy)
			j = j + 0.1
			energyBarLoc = energyBarLoc - module.opts.x_barSize - module.opts.x_barPadding
	end
	drawSmallText(math.floor(vehicle.energyPct()*100), module.opts.Energy, xpos, ypos  + module.opts.y_barSize + (module.opts.y_barPadding * 2) + (module.opts.y_barSize / 2), 0, 1, 2)
	
	local vNameText = ""
	if module.opts.Show_Vehicle_Name then vNameText = vehicle.name() end
	if module.opts.Show_Vehicle_Seat then vNameText = vNameText .. " / " .. vehicle.seatName() end
	drawSmallText(vNameText, module.opts.Full_Health, xright, ypos - 20, 2, 1, 2)
end

return module