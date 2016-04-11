local hpStart = player.healthMax()
local enStart = player.energy()
local endTime = 0
local timerOn = false
local status = false

function setTimer()
	endTime = os.clock() + 14
	timerOn = true
end

--check if the player takes damage
function damageCheck()
	--doesn't show timer if player is full hp, has the flag, or has rage
	if player.health() < player.healthMax() and not player.hasFlag() and not player.isRaged() then
		--turns timer on if hit while shield are on
		if player.isShielded() and player.energy() < enStart - 5 then
			setTimer()
		end
		--turns timer on if health goes down
		if player.health() < hpStart then
			setTimer()
		end
		--checks if you drop the flag or lose rage
		if player.hasFlag() ~= status and player.isRaged() ~= status then
			setTimer()
		end
		--turns timer off if you use an invo station
		if player.health() > hpStart and player.health() < hpStart + 100 then
			timerOn = false
		end
		hpStart = player.health()
		enStart = player.energy()
		
	else
		timerOn = false
	end
	if player.hasFlag() or player.isRaged() then
		status = true
	else
		status = false
	end
end

function regenTimer(x, y)
	damageCheck()
	if timerOn == true then
		local color = lerpColor(rgb(255,0,0), rgb(255,255,255), math.ceil(endTime - os.clock()) / 14)
		if math.ceil(endTime - os.clock()) < 0 then
			timerOn = false
		else
			local precision = 200
			local regen_pct = math.min(math.floor(precision * (endTime - os.clock())/(14))/precision, 1)
			drawRect(x, y, x + 304, y + 6, rgba(0, 0, 0, 255))
			drawProgressBar(x + 2, y + 2, x + 302, y + 4, rgb(255, 255, 255),3,regen_pct)
			--drawText(math.ceil(endTime - os.clock()), color, x, y, 2, 2)
		end
	end	
end