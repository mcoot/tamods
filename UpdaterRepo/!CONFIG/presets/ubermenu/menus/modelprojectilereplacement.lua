local lightWeapons = {
		{["class"]="Light", ["name"]="Light Spinfusor", ["exists"]=true},
		{["class"]="Light", ["name"]="Dueling Spinfusor", ["exists"]=false},
		{["class"]="Light", ["name"]="Stealth Spinfusor", ["exists"]=false},
		{["class"]="Light", ["name"]="Bolt Launcher", ["exists"]=true},
		{["class"]="Light", ["name"]="Light Twinfusor", ["exists"]=true},
		{["class"]="Light", ["name"]="Blinksfusor", ["exists"]=true},
		{["class"]="Light", ["name"]="Light Grenade Launcher", ["exists"]=true},
		{["class"]="Light", ["name"]="Jackal", ["exists"]=true},
		{["class"]="Light", ["name"]="BXT1 Rifle", ["exists"]=true},
		{["class"]="Light", ["name"]="BXT1A Rifle", ["exists"]=false},
		{["class"]="Light", ["name"]="Phase Rifle", ["exists"]=true},
		{["class"]="Light", ["name"]="SAP20 Rifle", ["exists"]=false},
		{["class"]="Light", ["name"]="Falcon", ["exists"]=true},
		{["class"]="Light", ["name"]="Light Assault Rifle", ["exists"]=true},
		{["class"]="Light", ["name"]="Sparrow", ["exists"]=true},
		{["class"]="Light", ["name"]="Throwing Knives", ["exists"]=true},
		{["class"]="Light", ["name"]="Rhino SMG", ["exists"]=false},
		{["class"]="Light", ["name"]="Arctic Rhino SMG", ["exists"]=false},
		{["class"]="Light", ["name"]="SN7 Silenced Pistol", ["exists"]=false},
		{["class"]="Light", ["name"]="Arctic SN7 Silenced Pistol", ["exists"]=false},
		{["class"]="Light", ["name"]="Shotgun", ["exists"]=true},
		{["class"]="Light", ["name"]="Holdout Shotgun", ["exists"]=false},
		{["class"]="Light", ["name"]="Accurized Shotgun", ["exists"]=false},
		{["class"]="Light", ["name"]="Shocklance", ["exists"]=true}
	}
	local mediumWeapons = {
		{["class"]="Medium", ["name"]="Spinfusor", ["exists"]=true},
		{["class"]="Medium", ["name"]="Thumper", ["exists"]=true},
		{["class"]="Medium", ["name"]="Thumper D", ["exists"]=false},
		{["class"]="Medium", ["name"]="Thumper DX", ["exists"]=true},
		{["class"]="Medium", ["name"]="Twinfusor", ["exists"]=true},
		{["class"]="Medium", ["name"]="Blinksfusor", ["exists"]=true},
		{["class"]="Medium", ["name"]="Arx Buster", ["exists"]=true},
		{["class"]="Medium", ["name"]="Dust Devil", ["exists"]=false},
		{["class"]="Medium", ["name"]="Grenade Launcher", ["exists"]=true},
		{["class"]="Medium", ["name"]="Improved Repair Tool", ["exists"]=true},
		{["class"]="Medium", ["name"]="Long Range Repair Tool", ["exists"]=true},
		{["class"]="Medium", ["name"]="ELF Projector", ["exists"]=true},
		{["class"]="Medium", ["name"]="Assault Rifle", ["exists"]=true},
		{["class"]="Medium", ["name"]="Gast Rifle", ["exists"]=false},
		{["class"]="Medium", ["name"]="NJ4 SMG", ["exists"]=true},
		{["class"]="Medium", ["name"]="Desert NJ4 SMG", ["exists"]=false},
		{["class"]="Medium", ["name"]="NJ5-b", ["exists"]=true},
		{["class"]="Medium", ["name"]="TCN4 SMG", ["exists"]=false},
		{["class"]="Medium", ["name"]="TCN4 Rockwind SMG", ["exists"]=false},
		{["class"]="Medium", ["name"]="TC24", ["exists"]=false},
		{["class"]="Medium", ["name"]="Plasma Gun", ["exists"]=true},
		{["class"]="Medium", ["name"]="Nova Blaster", ["exists"]=true},
		{["class"]="Medium", ["name"]="Eagle Pistol", ["exists"]=true},
		{["class"]="Medium", ["name"]="Sawed-off Shotgun", ["exists"]=true},
		{["class"]="Medium", ["name"]="Flak Cannon", ["exists"]=true}
	}
	local heavyWeapons = {
		{["class"]="Heavy", ["name"]="Spinfusor MKD", ["exists"]=false},
		{["class"]="Heavy", ["name"]="Spinfusor MK-X", ["exists"]=false},
		{["class"]="Heavy", ["name"]="Heavy Spinfusor", ["exists"]=true},
		{["class"]="Heavy", ["name"]="Devastator Spinfusor", ["exists"]=false},
		{["class"]="Heavy", ["name"]="Heavy Bolt Launcher", ["exists"]=true},
		{["class"]="Heavy", ["name"]="Heavy Blinksfusor", ["exists"]=true},
		{["class"]="Heavy", ["name"]="Heavy Twinfusor", ["exists"]=true},
		{["class"]="Heavy", ["name"]="Fusion Mortar", ["exists"]=true},
		{["class"]="Heavy", ["name"]="Fusion Mortar Deluxe", ["exists"]=false},
		{["class"]="Heavy", ["name"]="MIRV Launcher", ["exists"]=true},
		{["class"]="Heavy", ["name"]="Saber Launcher", ["exists"]=true},
		{["class"]="Heavy", ["name"]="Titan Launcher", ["exists"]=false},
		{["class"]="Heavy", ["name"]="Gladiator", ["exists"]=true},
		{["class"]="Heavy", ["name"]="Chain Gun", ["exists"]=true},
		{["class"]="Heavy", ["name"]="Chain Cannon", ["exists"]=false},
		{["class"]="Heavy", ["name"]="X1 LMG", ["exists"]=true},
		{["class"]="Heavy", ["name"]="Nova Colt", ["exists"]=true},
		{["class"]="Heavy", ["name"]="Nova Blaster MX", ["exists"]=true},
		{["class"]="Heavy", ["name"]="Automatic Shotgun", ["exists"]=true},
		{["class"]="Heavy", ["name"]="The Hammer", ["exists"]=false},
		{["class"]="Heavy", ["name"]="EFG", ["exists"]=true}
	}


function modelReplacement(parent, menu)
	menu:clear()
	
	local subLight = menu:add_submenu({ title = "Replace Light Model" })
	local subMedium = menu:add_submenu({ title = "Replace Medium Model" })
	local subHeavy = menu:add_submenu({ title = "Replace Heavy Model" })
	for k,v in pairs(lightWeapons) do 
		local original = v
		if(original.exists) then 
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
		
	end

	for k,v in pairs(mediumWeapons) do 
		local original = v
		if(original.exists) then 
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
	end

	for k,v in pairs(heavyWeapons) do 
		local original = v

		if(original.exists) then 
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
end

function projReplacement(parent, menu)
	menu:clear()
	
	local subLight = menu:add_submenu({ title = "Replace Light Projectile" })
	local subMedium = menu:add_submenu({ title = "Replace Medium Projectile" })
	local subHeavy = menu:add_submenu({ title = "Replace Heavy Projectile" })
	for k,v in pairs(lightWeapons) do 
		local original = v

		if(original.exists) then 
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
	end

	for k,v in pairs(mediumWeapons) do 
		local original = v

		if(original.exists) then 
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
	end


	for k,v in pairs(heavyWeapons) do 
		local original = v

		if(original.exists) then 
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
end
ubermenu:add_submenu({ title = "Model Replacement", func = modelReplacement })
ubermenu:add_submenu({ title = "Projectile Replacement", func = projReplacement  })
