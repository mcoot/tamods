local lightWeapons = {
		{["class"]="Light", ["name"]="Light Spinfusor"},
		{["class"]="Light", ["name"]="Dueling Spinfusor"},
		{["class"]="Light", ["name"]="Stealth Spinfusor"},
		{["class"]="Light", ["name"]="Bolt Launcher"},
		{["class"]="Light", ["name"]="Light Twinfusor"},
		{["class"]="Light", ["name"]="Blinksfusor"},
		{["class"]="Light", ["name"]="Light Grenade Launcher"},
		{["class"]="Light", ["name"]="Jackal"},
		{["class"]="Light", ["name"]="BXT1 Rifle"},
		{["class"]="Light", ["name"]="BXT1A Rifle"},
		{["class"]="Light", ["name"]="Phase Rifle"},
		{["class"]="Light", ["name"]="SAP20 Rifle"},
		{["class"]="Light", ["name"]="Falcon"},
		{["class"]="Light", ["name"]="Light Assault Rifle"},
		{["class"]="Light", ["name"]="Sparrow"},
		{["class"]="Light", ["name"]="Throwing Knives"},
		{["class"]="Light", ["name"]="Rhino SMG"},
		{["class"]="Light", ["name"]="Arctic Rhino SMG"},
		{["class"]="Light", ["name"]="SN7 Silenced Pistol"},
		{["class"]="Light", ["name"]="Arctic SN7 Silenced Pistol"},
		{["class"]="Light", ["name"]="Shotgun"},
		{["class"]="Light", ["name"]="Holdout Shotgun"},
		{["class"]="Light", ["name"]="Accurized Shotgun"},
		{["class"]="Light", ["name"]="Shocklance"}
	}
	local mediumWeapons = {
		{["class"]="Medium", ["name"]="Spinfusor"},
		{["class"]="Medium", ["name"]="Thumper"},
		{["class"]="Medium", ["name"]="Thumper D"},
		{["class"]="Medium", ["name"]="Thumper DX"},
		{["class"]="Medium", ["name"]="Twinfusor"},
		{["class"]="Medium", ["name"]="Arx Buster"},
		{["class"]="Medium", ["name"]="Dust Devil"},
		{["class"]="Medium", ["name"]="Grenade Launcher"},
		{["class"]="Medium", ["name"]="Improved Repair Tool"},
		{["class"]="Medium", ["name"]="Long Range Repair Tool"},
		{["class"]="Medium", ["name"]="ELF Projector"},
		{["class"]="Medium", ["name"]="Assault Rifle"},
		{["class"]="Medium", ["name"]="Gast Rifle"},
		{["class"]="Medium", ["name"]="NJ4 SMG"},
		{["class"]="Medium", ["name"]="Desert NJ4 SMG"},
		{["class"]="Medium", ["name"]="NJ5-b"},
		{["class"]="Medium", ["name"]="TCN4 SMG"},
		{["class"]="Medium", ["name"]="TCN4 Rockwind SMG"},
		{["class"]="Medium", ["name"]="TC24"},
		{["class"]="Medium", ["name"]="Plasma Gun"},
		{["class"]="Medium", ["name"]="Nova Blaster"},
		{["class"]="Medium", ["name"]="Eagle Pistol"},
		{["class"]="Medium", ["name"]="Sawed-off Shotgun"},
		{["class"]="Medium", ["name"]="Flak Cannon"}
	}
	local heavyWeapons = {
		{["class"]="Heavy", ["name"]="Spinfusor MKD"},
		{["class"]="Heavy", ["name"]="Spinfusor MK-X"},
		{["class"]="Heavy", ["name"]="Heavy Spinfusor"},
		{["class"]="Heavy", ["name"]="Devastator Spinfusor"},
		{["class"]="Heavy", ["name"]="Heavy Bolt Launcher"},
		{["class"]="Heavy", ["name"]="Heavy Blinksfusor"},
		{["class"]="Heavy", ["name"]="Heavy Twinfusor"},
		{["class"]="Heavy", ["name"]="Fusion Mortar"},
		{["class"]="Heavy", ["name"]="Fusion Mortar Deluxe"},
		{["class"]="Heavy", ["name"]="MIRV Launcher"},
		{["class"]="Heavy", ["name"]="Saber Launcher"},
		{["class"]="Heavy", ["name"]="Titan Launcher"},
		{["class"]="Heavy", ["name"]="Gladiator"},
		{["class"]="Heavy", ["name"]="Chain Gun"},
		{["class"]="Heavy", ["name"]="Chain Cannon"},
		{["class"]="Heavy", ["name"]="X1 LMG"},
		{["class"]="Heavy", ["name"]="Nova Colt"},
		{["class"]="Heavy", ["name"]="Nova Blaster MX"},
		{["class"]="Heavy", ["name"]="Automatic Shotgun"},
		{["class"]="Heavy", ["name"]="The Hammer"},
		{["class"]="Heavy", ["name"]="EFG"}
	}


function modelReplacement(parent, menu)
	menu:clear()
	
	local subLight = menu:add_submenu({ title = "Replace Light Model" })
	local subMedium = menu:add_submenu({ title = "Replace Medium Model" })
	local subHeavy = menu:add_submenu({ title = "Replace Heavy Model" })
	for k,v in pairs(lightWeapons) do 
		local original = v
		local subWeapon = subLight:add_submenu({ title = "Replace " .. original.name })

			local subLight1 = subWeapon:add_submenu({ title = "Replace " .. original.name .. " with Light Model" })
			local subMedium1 = subWeapon:add_submenu({ title = "Replace " .. original.name .. " with Medium Model" })
			local subHeavy1 = subWeapon:add_submenu({ title = "Replace " .. original.name .. " with Heavy Model" })

			for l,b in pairs(lightWeapons) do 
				local new = b
				if(new.name ~= original.name) then
					local subWeapon1 = subLight1:add_submenu({ title = new.name .. " replaces " .. original.name })
					local updateAnim = subWeapon1:add_submenu({ title = "Update animations"}) 
						updateAnim:add_item({title = "Replace Projectile" , func = function() 
							setWeaponModel(original.class, original.name, new.class, new.name, true) 
							setProjectile(original.class, original.name, cloneProjectile(getProjectile(new.class, new.name)))
							end})
						updateAnim:add_item({title = "Keep Projectile" , func = function() setWeaponModel(original.class, original.name, new.class, new.name, true) end})
					local keepAnim = subWeapon1:add_submenu({ title = "Keep animations"}) 
						keepAnim:add_item({title = "Replace Projectile" , func = function() 
							setWeaponModel(original.class, original.name, new.class, new.name, false) 
							setProjectile(original.class, original.name, cloneProjectile(getProjectile(new.class, new.name)))
							end})
						keepAnim:add_item({title = "Keep Projectile" , func = function() setWeaponModel(original.class, original.name, new.class, new.name, false) end})
				
				end
			end
			for l,b in pairs(mediumWeapons) do 
				local new = b
				if(new.name ~= original.name) then
					local subWeapon1 = subMedium1:add_submenu({ title = new.name .. " replaces " .. original.name })
					local updateAnim = subWeapon1:add_submenu({ title = "Update animations"}) 
						updateAnim:add_item({title = "Replace Projectile" , func = function() 
							setWeaponModel(original.class, original.name, new.class, new.name, true) 
							setProjectile(original.class, original.name, cloneProjectile(getProjectile(new.class, new.name)))
							end})
						updateAnim:add_item({title = "Keep Projectile" , func = function() setWeaponModel(original.class, original.name, new.class, new.name, true) end})
					local keepAnim = subWeapon1:add_submenu({ title = "Keep animations"}) 
						keepAnim:add_item({title = "Replace Projectile" , func = function() 
							setWeaponModel(original.class, original.name, new.class, new.name, false) 
							setProjectile(original.class, original.name, cloneProjectile(getProjectile(new.class, new.name)))
							end})
						keepAnim:add_item({title = "Keep Projectile" , func = function() setWeaponModel(original.class, original.name, new.class, new.name, false) end})
				
				end
			end
			for l,b in pairs(heavyWeapons) do 
				local new = b
				if(new.name ~= original.name) then
					local subWeapon1 = subHeavy1:add_submenu({ title = new.name .. " replaces " .. original.name })
					local updateAnim = subWeapon1:add_submenu({ title = "Update animations"}) 
						updateAnim:add_item({title = "Replace Projectile" , func = function() 
							setWeaponModel(original.class, original.name, new.class, new.name, true) 
							setProjectile(original.class, original.name, cloneProjectile(getProjectile(new.class, new.name)))
							end})
						updateAnim:add_item({title = "Keep Projectile" , func = function() setWeaponModel(original.class, original.name, new.class, new.name, true) end})
					local keepAnim = subWeapon1:add_submenu({ title = "Keep animations"}) 
						keepAnim:add_item({title = "Replace Projectile" , func = function() 
							setWeaponModel(original.class, original.name, new.class, new.name, false) 
							setProjectile(original.class, original.name, cloneProjectile(getProjectile(new.class, new.name)))
							end})
						keepAnim:add_item({title = "Keep Projectile" , func = function() setWeaponModel(original.class, original.name, new.class, new.name, false) end})
				
				end
			end
	end

	for k,v in pairs(mediumWeapons) do 
		local original = v
		local subWeapon = subMedium:add_submenu({ title = "Replace " .. original.name })

			local subLight1 = subWeapon:add_submenu({ title = "Replace " .. original.name .. " with Light Model" })
			local subMedium1 = subWeapon:add_submenu({ title = "Replace " .. original.name .. " with Medium Model" })
			local subHeavy1 = subWeapon:add_submenu({ title = "Replace " .. original.name .. " with Heavy Model" })

			for l,b in pairs(lightWeapons) do 
				local new = b
				if(new.name ~= original.name) then
					local subWeapon1 = subLight1:add_submenu({ title = new.name .. " replaces " .. original.name })
					local updateAnim = subWeapon1:add_submenu({ title = "Update animations"}) 
						updateAnim:add_item({title = "Replace Projectile" , func = function() 
							setWeaponModel(original.class, original.name, new.class, new.name, true) 
							setProjectile(original.class, original.name, cloneProjectile(getProjectile(new.class, new.name)))
							end})
						updateAnim:add_item({title = "Keep Projectile" , func = function() setWeaponModel(original.class, original.name, new.class, new.name, true) end})
					local keepAnim = subWeapon1:add_submenu({ title = "Keep animations"}) 
						keepAnim:add_item({title = "Replace Projectile" , func = function() 
							setWeaponModel(original.class, original.name, new.class, new.name, false) 
							setProjectile(original.class, original.name, cloneProjectile(getProjectile(new.class, new.name)))
							end})
						keepAnim:add_item({title = "Keep Projectile" , func = function() setWeaponModel(original.class, original.name, new.class, new.name, false) end})
				
				end
			end
			for l,b in pairs(mediumWeapons) do 
				local new = b
				if(new.name ~= original.name) then
					local subWeapon1 = subMedium1:add_submenu({ title = new.name .. " replaces " .. original.name })
					local updateAnim = subWeapon1:add_submenu({ title = "Update animations"}) 
						updateAnim:add_item({title = "Replace Projectile" , func = function() 
							setWeaponModel(original.class, original.name, new.class, new.name, true) 
							setProjectile(original.class, original.name, cloneProjectile(getProjectile(new.class, new.name)))
							end})
						updateAnim:add_item({title = "Keep Projectile" , func = function() setWeaponModel(original.class, original.name, new.class, new.name, true) end})
					local keepAnim = subWeapon1:add_submenu({ title = "Keep animations"}) 
						keepAnim:add_item({title = "Replace Projectile" , func = function() 
							setWeaponModel(original.class, original.name, new.class, new.name, false) 
							setProjectile(original.class, original.name, cloneProjectile(getProjectile(new.class, new.name)))
							end})
						keepAnim:add_item({title = "Keep Projectile" , func = function() setWeaponModel(original.class, original.name, new.class, new.name, false) end})
				
				end
			end
			for l,b in pairs(heavyWeapons) do 
				local new = b
				if(new.name ~= original.name) then
					local subWeapon1 = subHeavy1:add_submenu({ title = new.name .. " replaces " .. original.name })
					local updateAnim = subWeapon1:add_submenu({ title = "Update animations"}) 
						updateAnim:add_item({title = "Replace Projectile" , func = function() 
							setWeaponModel(original.class, original.name, new.class, new.name, true) 
							setProjectile(original.class, original.name, cloneProjectile(getProjectile(new.class, new.name)))
							end})
						updateAnim:add_item({title = "Keep Projectile" , func = function() setWeaponModel(original.class, original.name, new.class, new.name, true) end})
					local keepAnim = subWeapon1:add_submenu({ title = "Keep animations"}) 
						keepAnim:add_item({title = "Replace Projectile" , func = function() 
							setWeaponModel(original.class, original.name, new.class, new.name, false) 
							setProjectile(original.class, original.name, cloneProjectile(getProjectile(new.class, new.name)))
							end})
						keepAnim:add_item({title = "Keep Projectile" , func = function() setWeaponModel(original.class, original.name, new.class, new.name, false) end})
				
				end
			end
	end

	for k,v in pairs(heavyWeapons) do 
		local original = v
		local subWeapon = subHeavy:add_submenu({ title = "Replace " .. original.name })

			local subLight1 = subWeapon:add_submenu({ title = "Replace " .. original.name .. " with Light Model" })
			local subMedium1 = subWeapon:add_submenu({ title = "Replace " .. original.name .. " with Medium Model" })
			local subHeavy1 = subWeapon:add_submenu({ title = "Replace " .. original.name .. " with Heavy Model" })

			for l,b in pairs(lightWeapons) do 
				local new = b
				if(new.name ~= original.name) then
					local subWeapon1 = subLight1:add_submenu({ title = new.name .. " replaces " .. original.name })
					local updateAnim = subWeapon1:add_submenu({ title = "Update animations"}) 
						updateAnim:add_item({title = "Replace Projectile" , func = function() 
							setWeaponModel(original.class, original.name, new.class, new.name, true) 
							setProjectile(original.class, original.name, cloneProjectile(getProjectile(new.class, new.name)))
							end})
						updateAnim:add_item({title = "Keep Projectile" , func = function() setWeaponModel(original.class, original.name, new.class, new.name, true) end})
					local keepAnim = subWeapon1:add_submenu({ title = "Keep animations"}) 
						keepAnim:add_item({title = "Replace Projectile" , func = function() 
							setWeaponModel(original.class, original.name, new.class, new.name, false) 
							setProjectile(original.class, original.name, cloneProjectile(getProjectile(new.class, new.name)))
							end})
						keepAnim:add_item({title = "Keep Projectile" , func = function() setWeaponModel(original.class, original.name, new.class, new.name, false) end})
				
				end
			end
			for l,b in pairs(mediumWeapons) do 
				local new = b
				if(new.name ~= original.name) then
					local subWeapon1 = subMedium1:add_submenu({ title = new.name .. " replaces " .. original.name })
					local updateAnim = subWeapon1:add_submenu({ title = "Update animations"}) 
						updateAnim:add_item({title = "Replace Projectile" , func = function() 
							setWeaponModel(original.class, original.name, new.class, new.name, true) 
							setProjectile(original.class, original.name, cloneProjectile(getProjectile(new.class, new.name)))
							end})
						updateAnim:add_item({title = "Keep Projectile" , func = function() setWeaponModel(original.class, original.name, new.class, new.name, true) end})
					local keepAnim = subWeapon1:add_submenu({ title = "Keep animations"}) 
						keepAnim:add_item({title = "Replace Projectile" , func = function() 
							setWeaponModel(original.class, original.name, new.class, new.name, false) 
							setProjectile(original.class, original.name, cloneProjectile(getProjectile(new.class, new.name)))
							end})
						keepAnim:add_item({title = "Keep Projectile" , func = function() setWeaponModel(original.class, original.name, new.class, new.name, false) end})
				
				end
			end
			for l,b in pairs(heavyWeapons) do 
				local new = b
				if(new.name ~= original.name) then
					local subWeapon1 = subHeavy1:add_submenu({ title = new.name .. " replaces " .. original.name })
					local updateAnim = subWeapon1:add_submenu({ title = "Update animations"}) 
						updateAnim:add_item({title = "Replace Projectile" , func = function() 
							setWeaponModel(original.class, original.name, new.class, new.name, true) 
							setProjectile(original.class, original.name, cloneProjectile(getProjectile(new.class, new.name)))
							end})
						updateAnim:add_item({title = "Keep Projectile" , func = function() setWeaponModel(original.class, original.name, new.class, new.name, true) end})
					local keepAnim = subWeapon1:add_submenu({ title = "Keep animations"}) 
						keepAnim:add_item({title = "Replace Projectile" , func = function() 
							setWeaponModel(original.class, original.name, new.class, new.name, false) 
							setProjectile(original.class, original.name, cloneProjectile(getProjectile(new.class, new.name)))
							end})
						keepAnim:add_item({title = "Keep Projectile" , func = function() setWeaponModel(original.class, original.name, new.class, new.name, false) end})
				
				end
			end
	end
end

function projReplacement(parent, menu)
	menu:clear()
	
	local subLight = menu:add_submenu({ title = "Replace Light Projectile" })
	local subMedium = menu:add_submenu({ title = "Replace Medium Projectile" })
	local subHeavy = menu:add_submenu({ title = "Replace Heavy Projectile" })
	for k,v in pairs(lightWeapons) do 
		local original = v
		local subWeapon = subLight:add_submenu({ title = "Replace " .. original.name })

			local subLight1 = subWeapon:add_submenu({ title = "Replace " .. original.name .. " with Light Projectile" })
			local subMedium1 = subWeapon:add_submenu({ title = "Replace " .. original.name .. " with Medium Projectile" })
			local subHeavy1 = subWeapon:add_submenu({ title = "Replace " .. original.name .. " with Heavy Projectile" })

			for l,b in pairs(lightWeapons) do 
				local new = b
				if(new.name ~= original.name) then
					local subWeapon1 = subLight1:add_item({ title = new.name .. " replaces " .. original.name , func = function() 
						setProjectile(original.class, original.name, cloneProjectile(getProjectile(new.class, new.name)))
						end
						})
				end
			end
			for l,b in pairs(mediumWeapons) do 
				local new = b
				if(new.name ~= original.name) then
					local subWeapon1 = subMedium1:add_item({ title = new.name .. " replaces " .. original.name, func = function() 
						setProjectile(original.class, original.name, cloneProjectile(getProjectile(new.class, new.name)))
						end
						})
				end
			end
			for l,b in pairs(heavyWeapons) do 
				local new = b
				if(new.name ~= original.name) then
					local subWeapon1 = subHeavy1:add_item({ title = new.name .. " replaces " .. original.name , func = function() 
						setProjectile(original.class, original.name, cloneProjectile(getProjectile(new.class, new.name)))
						end
						})
				end
			end
	end

	for k,v in pairs(mediumWeapons) do 
		local original = v
		local subWeapon = subMedium:add_submenu({ title = "Replace " .. original.name })

			local subLight1 = subWeapon:add_submenu({ title = "Replace " .. original.name .. " with Light Projectile" })
			local subMedium1 = subWeapon:add_submenu({ title = "Replace " .. original.name .. " with Medium Projectile" })
			local subHeavy1 = subWeapon:add_submenu({ title = "Replace " .. original.name .. " with Heavy Projectile" })

			for l,b in pairs(lightWeapons) do 
				local new = b
				if(new.name ~= original.name) then
					local subWeapon1 = subLight1:add_item({ title = new.name .. " replaces " .. original.name , func = function() 
						setProjectile(original.class, original.name, cloneProjectile(getProjectile(new.class, new.name)))
						end
						})
				end
			end
			for l,b in pairs(mediumWeapons) do 
				local new = b
				if(new.name ~= original.name) then
					local subWeapon1 = subMedium1:add_item({ title = new.name .. " replaces " .. original.name , func = function() 
						setProjectile(original.class, original.name, cloneProjectile(getProjectile(new.class, new.name)))
						end
						})
				end
			end
			for l,b in pairs(heavyWeapons) do 
				local new = b
				if(new.name ~= original.name) then
					local subWeapon1 = subHeavy1:add_item({ title = new.name .. " replaces " .. original.name , func = function() 
						setProjectile(original.class, original.name, cloneProjectile(getProjectile(new.class, new.name)))
						end
						})
				end
			end
	end


	for k,v in pairs(heavyWeapons) do 
		local original = v
		local subWeapon = subHeavy:add_submenu({ title = "Replace " .. original.name })

			local subLight1 = subWeapon:add_submenu({ title = "Replace " .. original.name .. " with Light Projectile" })
			local subMedium1 = subWeapon:add_submenu({ title = "Replace " .. original.name .. " with Medium Projectile" })
			local subHeavy1 = subWeapon:add_submenu({ title = "Replace " .. original.name .. " with Heavy Projectile" })

			for l,b in pairs(lightWeapons) do 
				local new = b
				if(new.name ~= original.name) then
					local subWeapon1 = subLight1:add_item({ title = new.name .. " replaces " .. original.name , func = function() 
						setProjectile(original.class, original.name, cloneProjectile(getProjectile(new.class, new.name)))
						end
						})
				end
			end
			for l,b in pairs(mediumWeapons) do 
				local new = b
				if(new.name ~= original.name) then
					local subWeapon1 = subMedium1:add_item({ title = new.name .. " replaces " .. original.name , func = function() 
						setProjectile(original.class, original.name, cloneProjectile(getProjectile(new.class, new.name)))
						end
						})
				end
			end
			for l,b in pairs(heavyWeapons) do 
				local new = b
				if(new.name ~= original.name) then
					local subWeapon1 = subHeavy1:add_item({ title = new.name .. " replaces " .. original.name , func = function() 
						setProjectile(original.class, original.name, cloneProjectile(getProjectile(new.class, new.name)))
						end
						})
				end
			end
	end
end
ubermenu:add_submenu({ title = "Model Replacement", func = modelReplacement })
ubermenu:add_submenu({ title = "Projectile Replacement", func = projReplacement  })
