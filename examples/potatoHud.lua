-- Colors
cWhite  = rgba(255, 255, 255, 255)
cBlack  = rgba(0, 0, 0, 255)
cRed    = rgba(255, 0, 0, 255)
cBoxBG1 = rgba(0, 0, 0, 75)
cBoxBG2 = rgba(0, 0, 0, 50)

teamCols        = {}
teamCols[0]     = rgba(255, 23, 23, 150)
teamCols[1]     = rgba(158, 208, 212, 150)
teamTextCols    = {}
teamTextCols[0] = rgba(255, 23, 23, 255)
teamTextCols[1] = rgba(158, 208, 212, 255)

CaHPointLabels  = {'A','B','C','D','E'}

-- Toggle HUD bound to 'O'
showHud = true
bindKey("O", Input.PRESSED, function() if not viewPort.isMainMenuOpen() then showHud = not showHud end end)

-- Storage table for the death messages
deathMessagesMax = 6
deathMessages = {}

-- Define some strings for the different kill types
killTypes = {"Exploded","Stickied","Squished","Knifed","Fell","Vehicle","Bullet","Sniped","Rekt","Headshot","Killed","Disked","Turret"}

function onAddToCombatLog(team, killer, killType, victim)
	-- team is the sum of:
	-- 0: killer is in our team
	-- 1: killer is in the enemy team
	-- 2: the death message is related to us
	local t

	if killer == "Suicide" then
		t = { team, victim .. " suicided" }
	else
		t = { team, killer .. " [" .. killTypes[killType] .. "] " .. victim }
	end

	-- Append new messages to the end
	table.insert(deathMessages, t)

	-- Keep only n death messages
	if #deathMessages > deathMessagesMax then
		-- Remove the oldest death message (first element in the table)
		table.remove(deathMessages, 1)
	end
end

function onDrawCustomHud(resX, resY)
	-- Toggle HUD
	if not showHud or viewPort.isMainMenuOpen() then
		return
	end

	local centerX = resX / 2
	local centerY = resY / 2
	local gameType = game.type()
	local practiceMode = game.isOfflinePlay()	
	local myTeam = player.teamNum()
	local myName = player.name()

	-- Our current team is left and blue, while the enemy is red and right
	-- While spectating (team 255) Blood Eagle is always left/red
	local leftTeam = myTeam == 1 and 1 or 0
	local leftCol = myTeam == 255 and 0 or 1
	local rightTeam = 1 - leftTeam
	local rightCol = 1 - leftCol

	-- KDA and ping display
	drawSmallText(player.kills() .. "/" .. player.deaths() .. "/" .. player.assists() .. " - " .. player.ping() .. " ms", cWhite, 10, 15, 0, 1, 1)

	-- Death messages
	for i = 1,deathMessagesMax do
		if i <= #deathMessages then
			local team = deathMessages[i][1]
			local color = team > 1 and cWhite or teamTextCols[team]
			drawRect(resX - 350, 19 * i - 9, resX - 50, 9 + 19 * i, cBoxBG2)
			drawSmallText(deathMessages[i][2], color, resX - 200, 19 * i, 1, 1, 1)
		else
			break
		end
	end

	-- Draw the 128x40 timer background at the top-center of the screen
	drawRect(centerX - 64, 0, centerX + 64, 40, cBoxBG1)
	drawUTText(game.timeStr(), cWhite, resX / 2, 20, 1, 1, 1)

	-- Draw the currents game status like overtime, warmup etc.
	if game.isWarmUp() then
		drawRect(centerX - 35, 40, centerX + 35, 60, cBoxBG2)
		drawSmallText("WARMUP", cWhite, centerX, 50, 1, 1, 1)
	end

	-- Draw 70x40 team colored rectangles containing team score, not in rabbit though
	if gameType ~= "TrGame_TRRabbit" then
		-- Left
		drawRect(centerX - 134, 0, centerX - 64, 40, teamCols[leftCol])
		drawText(game.score(leftTeam), teamTextCols[leftCol], centerX - 99, 22, 1, 1.5)
		-- Right
		drawRect(centerX + 64, 0, centerX + 134, 40, teamCols[rightCol])
		drawText(game.score(rightTeam), teamTextCols[rightCol], centerX + 99, 22, 1, 1.5)
	end

	if gameType == "TrGame_TRCTF" or gameType == "TrGame_TrCTFBlitz" or gameType == "TrGame_TRTeamRabbit" then
		------------------------
		-- CTF, Blitz and TDM --
		------------------------

		-- Flag status, only if flags aren't home
		-- Left team
		if not flag.isHome(leftTeam) then
			local returnTime = flag.returnTime(leftTeam)

			if returnTime > 0 then
				-- Flag is dropped, display the time until auto return
				drawText(returnTime, teamTextCols[leftCol], centerX - 140, 22, 2, 1.2) 
			else
				-- Flag is held, display the name of the holder
				drawText(flag.holderName(leftTeam), teamTextCols[rightCol], centerX - 140, 22, 2, 1) 
			end
		end
		-- Right team
		if not flag.isHome(rightTeam) then
			local returnTime = flag.returnTime(rightTeam)

			if returnTime > 0 then
				-- Flag is dropped, display the time until auto return
				drawText(returnTime, teamTextCols[rightCol], centerX + 140, 22, 0, 1.2) 
			else
				-- Flag is held, display the name of the holder
				drawText(flag.holderName(rightTeam), teamTextCols[leftCol], centerX + 140, 22, 0, 1) 
			end
		end

		-- Generator status (not for TDM)
		if gameType == "TrGame_TRCTF" or gameType == "TrGame_TrCTFBlitz" then
			-- Left
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
			-- Right
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
	elseif gameType == "TrGame_TRRabbit" then
		------------
		-- Rabbit --
		------------

		-- Draw the current rabbit below the game timer, but only if it's not us
		if not player.hasFlag() then
			drawText(rabbit.rabbitName(), teamTextCols[0], centerX + 80, 22, 0, 1)
		end
		local myRank = player.rabbitRank()
		local y
		local color
		for i = 0,2 do
			name = rabbit.leaderBoardName(i)
			if name ~= "" then
				y = 28 * i + 50
				drawRect(45, y - 14, 305, y + 12, cBoxBG1)
				-- Different color if this is us
				color = i+1 == myRank and teamTextCols[1] or cWhite
				drawText(i+1 .. ". " .. name, color, 50, y, 0, 1)
				drawText(rabbit.leaderBoardScore(i), color, 300, y, 2, 1)
			end
		end
		-- If our rank is lower than 3, we are not on the leaderboard, so draw us and our rank below it
		if myRank > 3 then
			y = y + 28
			drawRect(45, y - 14, 305, y + 12, cBoxBG1)
			drawText(myRank .. ". " .. myName, teamTextCols[1], 50, y, 0, 1)
			drawText(player.score(), teamTextCols[1], 300, y, 2, 1)
		end
	elseif gameType == "TrGame_TrCaH" then
		----------------------
		-- Capture and Hold --
		----------------------
		local pointsNum = cah.pointsNum()

		local x = centerX + 150
		local y = 5 

		for i=0,pointsNum-1 do
			local pointHolder = cah.pointHolder(i)
			local color
			local label = cah.pointLabel(i)
			
			-- Figure out the holder of the point and which color it should have
			if pointHolder == 255 then color = rgba(255, 255, 255, 120)
			elseif pointHolder == leftTeam then color = teamCols[leftCol]
			else color = teamCols[rightCol] end

			drawRect(x + 38 * label + 3, y, x + 35 + 38 * label, y + 32, color)
			drawSmallText(CaHPointLabels[label+1], cBlack, x + 38 * label + 19, y + 16, 1, 0, 1)
		end
	elseif gameType == "TrGame_TrArena" then
		-----------
		-- Arena --
		-----------

		-- Round scores
		-- Left team
		drawRect(centerX - 113, 40, centerX - 86, 60, teamCols[leftCol])
		drawText(arena.roundScore(leftTeam), teamTextCols[leftCol], centerX - 99, 51, 1, 1)
		-- Right team
		drawRect(centerX + 86, 40, centerX + 113, 60, teamCols[rightCol])
		drawText(arena.roundScore(rightTeam), teamTextCols[rightCol], centerX + 99, 51, 1, 1)

		-- Draw a warning message if we have no respawns left
		if myTeam ~= 255 and not game.isWarmUp() and player.isAlive() and player.arenaSpawnsLeft() < 1 then
			drawText("Last live!", cRed, centerX, resY * 0.12, 1, 1.8)
		end

		-- Draw the lefts teams player mannequins when spawns are empty
		if game.score(leftTeam) < 1 then
			local x = centerX - 170
			local y = 10
			for i=0,7 do
				-- playerStatus returns a bitmask where:
				-- 0: no player, 1: player, 2: alive, 4: has spawns left
				local ps = arena.playerStatus(leftTeam, i)
				-- Don't draw anything if this slot has no player
				if ps > 0 then
					if ps == 1 then
						-- Player is benched, only draw an 'x'
						drawText("X", cWhite, x - 12, y + 14, 1, 1)
					else
						-- Player is alive, draw a square representing this player
						drawRect(x - 24, y, x, y + 24, teamCols[leftCol])
						-- Player has spawns left, draw a '1' inside his square
						if ps > 3 then
							drawText("1", teamTextCols[leftCol], x - 12, y + 14, 1, 1)
						end
					end
					x = x - 26
				end
			end
		end
		-- Draw the rights teams player mannequins when spawns are empty
		if game.score(rightTeam) < 1 then
			local x = centerX + 170
			local y = 10
			for i=0,7 do
				-- playerStatus returns a bitmask where:
				-- 0: no player, 1: player, 2: alive, 4: has spawns left
				local ps = arena.playerStatus(rightTeam, i)
				-- Don't draw anything if this slot has no player
				if ps > 0 then
					if ps == 1 then
						-- Player is benched, only draw an 'x'
						drawText("X", cWhite, x + 12, y + 14, 1, 1)
					else
						-- Player is alive, draw a square representing this player
						drawRect(x, y, x + 24, y + 24, teamCols[rightCol])
						-- Player has spawns left, draw a '1' inside his square
						if ps > 3 then
							drawText("1", teamTextCols[rightCol], x + 12, y + 14, 1, 1)
						end
					end
					x = x + 26
				end
			end
		end
	end
	-----------------
	-- Player info --
	-----------------
	if player.isAlive() then
		-- Store the relevant data
		local isVehicle = player.isVehicle()
		local health = player.health()
		local energy = player.energy()
		local speed = isVehicle and vehicle.speed() or player.speed()
		local healthPct = health / player.healthMax()
		local energyPct = player.energyPct()
		local healthCol = lerpColor(rgba(235, 22, 51, 255), rgba(195, 248, 212, 200), healthPct)
		local energyCol = rgba(161, 209, 213, 200)

		-- Health and energy
		-- Draw a border
		drawBox(centerX - 302, resY - 35, centerX - 2, resY - 10, healthCol)
		drawBox(centerX + 2, resY - 35, centerX + 302, resY - 10, energyCol)
		-- Draw 300x25 background rectangles
		drawRect(centerX - 302, resY - 35, centerX - 2, resY - 10, cBoxBG2)
		drawRect(centerX + 2, resY - 35, centerX + 302, resY - 10, cBoxBG2)
		-- Draw progress bars
		drawProgressBar(centerX - 298, resY - 31, centerX - 6, resY - 14, healthCol, 3, healthPct)
		drawProgressBar(centerX + 6, resY - 31, centerX + 298, resY - 14, energyCol, 1, energyPct)
		-- Draw the actual numbers
		drawUTText(health, healthCol, centerX - 10, resY - 55, 2, 2, 2)
		drawUTText(math.floor(energy), energyCol, centerX + 10, resY - 55, 0, 2, 2)

		-- Draw current speed (player or vehicle), but only when not 0
		if speed ~= 0 then
			drawText(speed .. " kph", cWhite, resX - 15, resY / 2, 2, 1)
		end

		-- Weapons and Ammo
		-- If the current gun is not ready to fire, draw an indicator around the crosshair
		if not currentWeapon.isReadyToFire() then
			local color = currentWeapon.isReloaded() and cRed or cWhite
			drawText("-        -", color, centerX, centerY, 1, 1.5)
		end
		-- Draw the ammo of the current weapon close to the crosshair
		if not currentWeapon.isPack() and (not isVehicle or (isVehicle and vehicle.ammo() < 0)) then
			drawSmallText(currentWeapon.ammo(), currentWeapon.isLowAmmo() and cRed or cWhite, resX / 2 + 16, resY * 0.6, 1, 1, 1)
		end

		-- Draw a list of all weapons, their ammo and reload status
		-- Heavy (ID 3) has 4 weapons, while light and medium have 3. All classes have belt items and packs
		local weapons = player.classId() == 3 and { 2,3,4,5,7,6 } or { 2,3,4,7,6 }
		local current = currentWeapon.equippedAt()

		for i, wep in ipairs(weapons) do
			if not ((wep == 6 and weapon.isPack(6)) or weapon.ammo(wep) == -1) then
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
				drawText(weapon.ammoTotal(wep), col, x + 74, y + 16, 2, 1)

				if wep == 7 then
					for i = 0,player.numMines() - 1 do drawRect(9 + x + 7 * i, 20 + y, 13 + x + 7 * i, 24 + y, teamCols[0]) end
				elseif wep == 6 then
					for i = 0,player.numDeployables() - 1 do drawRect(9 + x + 7 * i, 20 + y, 13 + x + 7 * i, 24 + y, teamCols[0]) end
				end
			end
		end

		-- Draw a message if we have the flag
		if player.hasFlag() then
			drawText("F L A G", rgb(168,234,168), centerX, resY * 0.12, 1, 1.8)
		end
		-- Draw a message if we have rage active
		if player.isRaged() then
			drawText("R A G E", cRed, centerX, resY * 0.16, 1, 1.8)
		end

		-- Vehicle display
		if isVehicle then
			local x = resX * 0.65
			local y = resY - 200
			local health    = vehicle.health()
			local healthPct = health / vehicle.healthMax()
			local energyPct = vehicle.energyPct()
			local energy    = math.floor(energyPct * 100)
			local healthCol = rgba(195, 248, 212, 200)
			local energyCol = rgba(161, 209, 213, 200)
			
			-- Health
			drawRect(x, y, x + 18, y + 88, cBoxBG1)
			drawBox(x, y, x + 18, y + 88, healthCol)
			drawProgressBar(x + 4, y + 4, x + 14, y + 84, healthCol, 0, healthPct)
			drawSmallText(health, healthCol, x + 9, y + 98, 1, 1, 1)
			-- Energy
			x = x + 35
			drawRect(x, y, x + 18, y + 88, cBoxBG1)
			drawBox(x, y, x + 18, y + 88, energyCol)
			drawProgressBar(x + 4, y + 4, x + 14, y + 84, energyCol, 0, energyPct)
			drawSmallText(energy, energyCol, x + 9, y + 98, 1, 1, 1)

			-- Ammo, not as gravcycle passenger (-1 ammo) or for the beowulf cannon (1 ammo)
			if vehicle.ammoMax() > 1 then
				drawSmallText(vehicle.ammo() .. "/" .. vehicle.ammoMax(), currentWeapon.isLowAmmo() and cRed or cWhite, resX / 2 + 16, resY * 0.6, 1, 1, 1)
			end
		end
	else
		local respawnTime = player.respawnTime()

		if respawnTime > 0 then
			drawText(respawnTime, cWhite, centerX, resY * 0.9, 1, 1.5)
		end
	end
end

console("potatoHud loaded")
