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

function onQueueAccolade(icon_id, title, subtitle, is_badge)
	--console(icon_id .. ": " .. title .. " (" .. subtitle .. ")")
	if icon_id == 68 then
		counter.blueplates = counter.blueplates + 1
	elseif icon_id == 53 then
		counter.airmails = counter.airmails + 1
	end
end

local lastFrameTime = 0.0

function stats(x, y)
	local time = game.realTimeSeconds()
	local fps = 1 / (time - lastFrameTime)

	lastFrameTime = time

	drawSmallText(math.floor(fps) .. " fps", text_color1, x, y, 2, 1, 1)
	drawSmallText(player.ping() .. " ms", text_color1, x, y + 16, 2, 1, 1)
	drawSmallText(player.kills() .. "/" .. player.deaths() .. "/" .. player.assists(), text_color1, x, y + 32, 2, 1, 1)
	drawSmallText(counter.blueplates .. " bp " .. counter.airmails .. " am", text_color1, x, y + 48, 2, 1, 1)
end
