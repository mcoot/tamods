function playRandomEnemyRoute()
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

bindKey("Delete", Input.PRESSED, playRandomEnemyRoute)
