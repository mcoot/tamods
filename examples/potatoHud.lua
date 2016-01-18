cWhite = rgba(255, 255, 255, 255)
cRed = rgba(255, 0, 0, 255)
cBoxBG1 = rgba(0, 0, 0, 75)
cBoxBG2 = rgba(0, 0, 0, 50)

teamCols = {}
teamCols[0] = rgba(255, 23, 23, 150)
teamCols[1] = rgba(158, 208, 212, 150)
teamTextCols = {}
teamTextCols[0] = rgba(255, 23, 23, 255)
teamTextCols[1] = rgba(158, 208, 212, 255)

function onDrawCustomHud(resX, resY)
	local centerX = resX / 2
	local centerY = resY / 2
	local gameType = game.type()
	local practiceMode = game.isOfflinePlay()	
	local myTeam = player.teamNum()

	-- Draw a 128x40 timer background at the top-center of the screen
	drawRect(centerX - 64, 0, centerX + 64, 40, cBoxBG1)
	drawText(game.timeStr(), cWhite, resX / 2, 22, 1, 0, 1.7)

	-- Our current team is left and blue, while the enemy is red and right
	-- While spectating (team 255) Blood Eagle is always left
	local leftTeam = myTeam == 1 and 1 or 0
	local leftCol = myTeam == 255 and 0 or 1
	local rightTeam = 1 - leftTeam
	local rightCol = 1 - leftCol

	-- Draw 70x40 team colored score backgrounds
	-- Left
	drawRect(centerX - 134, 0, centerX - 64, 40, teamCols[leftCol])
	drawText(game.score(leftTeam), teamTextCols[leftCol], centerX - 99, 22, 1, 0, 1.5)
	-- Right
	drawRect(centerX + 64, 0, centerX + 134, 40, teamCols[rightCol])
	drawText(game.score(1 - leftTeam), teamTextCols[rightCol], centerX + 99, 22, 1, 0, 1.5)

	-- Draw gametype specific info like score, flag status etc.
	if gameType == "TrGame_TRCTF" or gameType == "TrGame_TrCTFBlitz" then
		-- Flag status, only if flags aren't home
		if not flag.isHome(leftTeam) then
			local returnTime = flag.returnTime(leftTeam)

			if returnTime > 0 then
				-- Flag is dropped, display the time until auto return
				drawText(returnTime, teamTextCols[leftCol], centerX - 140, 22, 2, 0, 1.2) 
			else
				-- Flag is held, display the name of the holder
				drawText(flag.holderName(leftTeam), teamTextCols[rightCol], centerX - 140, 22, 2, 0, 1) 
			end
		end
		if not flag.isHome(rightTeam) then
			local returnTime = flag.returnTime(rightTeam)

			if returnTime > 0 then
				-- Flag is dropped, display the time until auto return
				drawText(returnTime, teamTextCols[rightCol], centerX + 140, 22, 0, 0, 1.2) 
			else
				-- Flag is held, display the name of the holder
				drawText(flag.holderName(rightTeam), teamTextCols[leftCol], centerX + 140, 22, 0, 0, 1) 
			end
		end

		-- Generator status
		if not game.isGenUp(leftTeam) then
			local genTimer = game.genAutoRepairTime(leftTeam)
			if genTimer > 0 then
				-- Display the remaining time until auto repair
				drawSmallText(genTimer, teamTextCols[leftCol], centerX - 99, 50, 1, 1, 1)
			else
				-- Auto repairing is turned off, just display that the generator is down
				drawSmallText("No Power", teamTextCols[leftCol], centerX - 99, 50, 1, 1, 1)
			end
		end
		if not game.isGenUp(rightTeam) then
			local genTimer = game.genAutoRepairTime(rightTeam)
			if genTimer > 0 then
				-- Display the remaining time until auto repair
				drawSmallText(genTimer, teamTextCols[rightCol], centerX + 99, 50, 1, 1, 1)
			else
				-- Auto repairing is turned off, just display that the generator is down
				drawSmallText("No Power", teamTextCols[rightCol], centerX + 99, 50, 1, 1, 1)
			end
		end
	end

	-- Player info
	if player.isAlive() then
		-- Debugging
		--string = "Ready:" .. (currentWeapon.isReadyToFire() and "y" or "n") .. " Reloading:" .. (currentWeapon.isReloading(n) and "y" or "n") .. " LowAmmo:" .. (currentWeapon.isLowAmmo(n) and "y" or "n") .. " ammo:" .. currentWeapon.ammo() .. " ammoMax:" .. currentWeapon.ammoMax() .. " ammoCarried:" .. currentWeapon.ammoCarried(n) .. " ammoMaxCarried:" .. currentWeapon.ammoMaxCarried() .. " ammoTotal:" .. currentWeapon.ammoTotal(n)
		--n = 7
		--string = "Ready:" .. (weapon.isReadyToFire(n) and "y" or "n") .. " Reloading:" .. (weapon.isReloading(n) and "y" or "n") .. " LowAmmo:" .. (weapon.isLowAmmo(n) and "y" or "n") .. " ammo:" .. weapon.ammo(n) .. " ammoMax:" .. weapon.ammoMax(n) .. " ammoCarried:" .. weapon.ammoCarried(n) .. " ammoMaxCarried:" .. weapon.ammoMaxCarried(n) .. " ammoTotal:" .. weapon.ammoTotal(n)
		--drawSmallText(string , cWhite, centerX, 150, 1, 1, 1)
		--n = 6
		--string = "Ready:" .. (weapon.isReadyToFire(n) and "y" or "n") .. " Reloading:" .. (weapon.isReloading(n) and "y" or "n") .. " LowAmmo:" .. (weapon.isLowAmmo(n) and "y" or "n") .. " ammo:" .. weapon.ammo(n) .. " ammoMax:" .. weapon.ammoMax(n) .. " ammoCarried:" .. weapon.ammoCarried(n) .. " ammoMaxCarried:" .. weapon.ammoMaxCarried(n) .. " ammoTotal:" .. weapon.ammoTotal(n)
		--drawSmallText(string , cWhite, centerX, 165, 1, 1, 1)

		-- Store the relevant data
		local health = player.health()
		local energy = player.energy()
		local speed = player.speed()
		local healthPct = health / player.healthMax()
		local energyPct = player.energyPct()
		local healthCol = lerpColor(rgba(235, 22, 51, 255), rgba(195, 248, 212, 200), healthPct)
		local energyCol = rgba(161, 209, 213, 200)

		-- Draw 300x25 background rectangles for health and energy
		drawRect(centerX - 302, resY - 35, centerX - 2, resY - 10, cBoxBG2)
		drawRect(centerX + 2, resY - 35, centerX + 302, resY - 10, cBoxBG2)
		-- Draw a border around them
		drawBox(centerX - 302, resY - 35, centerX - 2, resY - 10, cBoxBG1)
		drawBox(centerX + 2, resY - 35, centerX + 302, resY - 10, cBoxBG1)
		-- Draw progress bars
		drawProgressBar(centerX - 300, resY - 33, centerX - 4, resY - 12, healthCol, 3, healthPct)
		drawProgressBar(centerX + 4, resY - 33, centerX + 300, resY - 12, energyCol, 1, energyPct)
		-- Draw the actual numbers
		drawText(health, healthCol, centerX - 10, resY - 55, 2, 0, 2)
		drawText(math.floor(energy), energyCol, centerX + 10, resY - 55, 0, 0, 2)

		-- Draw current speed, but only when not standing still
		local speed = player.speed()
		if speed ~= 0 then
			drawText(speed .. " kph", cWhite, resX - 15, resY / 2, 2, 0, 1)
		end

		-- Weapons and Ammo
		-- If the current gun is not ready to fire, draw a red square at the middle of the screen
		if currentWeapon.isReloading() then
			drawRect(centerX - 2, centerY - 2, centerX + 3, centerY + 3, cRed)
		end
		-- Draw the ammo of the current weapon close to the crosshair
		if not currentWeapon.isPack() then
			drawSmallText(currentWeapon.ammo(), currentWeapon.isLowAmmo() and cRed or cWhite, resX / 2 + 16, resY * 0.6, 1, 1, 1)
		end

		-- Draw a list of all weapons, their ammo and reload status
		-- Heavy (ID 3) has 4 weapons, while light and medium have 3. All classes have belt items and packs
		local weapons = player.classId() == 3 and { 2,3,4,5,7,6 } or { 2,3,4,7,6 }
		local current = currentWeapon.equippedAt()
	
		for i, wep in ipairs(weapons) do
			if not (wep == 6 and weapon.isPack(6)) then
				local x
				local y = (resY / 2 - 100) + 30 * i
				local col = cWhite
				if wep == current then
					x = 10
					col = rgba(255, 255, 0, 255)
				else
					x = 0
					col = weapon.isPassiveReady(wep) and rgba(255, 255, 255, 140) or cRed
				end

				drawRect(4 + x, y, 80 + x, 28 + y, cBoxBG1)
				drawSmallText(wep == 6 and "Pack" or wep == 7 and "Belt" or i, rgba(255, 255, 255, 100), 8 + x, 10 + y, 0, 0, 1)
				drawText(weapon.ammoTotal(wep), col, x + 74, y + 16, 2, 0, 1)
				
				if wep == 7 then
					for i = 0,player.numMines() - 1 do drawRect(9 + x + 7 * i, 20 + y, 13 + x + 7 * i, 24 + y, teamCols[0]) end
				elseif wep == 6 then
					for i = 0,player.numDeployables() - 1 do drawRect(9 + x + 7 * i, 20 + y, 13 + x + 7 * i, 24 + y, teamCols[0]) end
				end
			end
		end

		-- Draw a message if we have the flag
		if player.hasFlag() then
			drawText("F L A G", rgb(168,234,168), centerX, resY * 0.15, 1, 0, 1.8)
		end
		-- Draw a message if we have rage active
		if player.isRaged() then
			drawText("R A G E", cRed, centerX, resY * 0.20, 1, 0, 1.8)
		end
	else
		respawnTime = player.respawnTime()

		if respawnTime > 0 then
			drawText(respawnTime, cWhite, centerX, resY * 0.9, 1, 0, 1.5)
		end
	end
end
