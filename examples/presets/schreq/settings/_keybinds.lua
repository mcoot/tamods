function replayStart()
	stopwatch.start()
	route.replayStart(0.0)
	returnFlags()
end

function recStart()
	state.tp()
	stopwatch.start()
	route.recStart()
	returnFlags()
end

function recStop()
	stopwatch.stop()
	route.recStop()
	returnFlags()
end

local currentRoute = 0
function nextRoute()
	local count = route.getAll()

	if currentRoute < count then
		currentRoute = currentRoute + 1
	else
		currentRoute = 1
	end

	route.load(currentRoute)
end

function prevRoute()
	local count = route.getAll()
	
	if currentRoute > count or currentRoute <= 1 then
		currentRoute = count
	else
		currentRoute = currentRoute - 1
	end

	route.load(currentRoute)
end

function randomEnemyRoute()
	local count = route.getEnemy()

	if count > 0 then
		local rand = math.random(count)
		route.enableBot(true)
		returnFlags()
		route.load(rand)
		route.replayStart(0.0)
	else
		notify("TAMods error", "No enemy routes found")
	end
end

bindKey("Insert", Input.PRESSED, stopwatch.toggle)
bindKey("Delete", Input.PRESSED, randomEnemyRoute)
bindKey("Home", Input.PRESSED, recStart)
bindKey("End", Input.PRESSED, recStop)
bindKey("PageUp", Input.PRESSED, nextRoute)
bindKey("PageDown", Input.PRESSED, prevRoute)
