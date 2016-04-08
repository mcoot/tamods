local counter = {}
counter.blueplates = 0
counter.airmails = 0

-- Ctrl-R resets the counters
bindKey("R", Input.PRESSED,
	function(key, event, ctrl, shift, alt)
	   if ctrl and not viewPort.isMainMenuOpen() then
	      counter.blueplates = 0
		  counter.airmails = 0
	   end
	end
)

local onQueueAccoladeOld
if type(onQueueAccolade) == "function" then
	onQueueAccoladeOld = onQueueAccolade
end

function onQueueAccolade(icon_id, title, subtitle, is_badge)
	if onQueueAccoladeOld then onQueueAccoladeOld(icon_id, title, subtitle, is_badge) end

	--console(icon_id .. ": " .. title .. " (" .. subtitle .. ")")
	if icon_id == 68 then
		counter.blueplates = counter.blueplates + 1
	elseif icon_id == 53 then
		counter.airmails = counter.airmails + 1
	end
end

local lastFrameTime = 0.0

sqHud.stats = function(x, y)
	local time = game.realTimeSeconds()
	local fps = 1 / (time - lastFrameTime)

	lastFrameTime = time

	drawSmallText(math.floor(fps) .. " fps", sqHud.text_color1, x, y, 2, 1, 1)
	drawSmallText(player.ping() .. " ms", sqHud.text_color1, x, y + 16, 2, 1, 1)
	drawSmallText(player.kills() .. "/" .. player.deaths() .. "/" .. player.assists(), sqHud.text_color1, x, y + 32, 2, 1, 1)
	drawSmallText(counter.blueplates .. " bp " .. counter.airmails .. " am", sqHud.text_color1, x, y + 48, 2, 1, 1)
end
