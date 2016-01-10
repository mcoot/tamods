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

bindKey("Insert", Input.RELEASED, stopwatch.toggle)
bindKey("Home", Input.RELEASED, recStart)
bindKey("End", Input.RELEASED, recStop)