local module = {}

module.name                = "sqStats"  -- This HAS to be the same as the filename minus the trailing .lua
module.opts                = {}
module.opts.X_Position     = 99.4
module.opts.Y_Position     = 1.2
module.opts.Text           = rgba(255,255,255,255)
module.opts.Text_Alignment = 2

local counter = {}
counter.blueplates = 0
counter.airmails = 0

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

-- The drawing function for this module
function module.draw(res_x, res_y)
	local xpos = math.floor(module.opts.X_Position / 100 * res_x)
	local ypos = math.floor(module.opts.Y_Position / 100 * res_y)

	local time = game.realTimeSeconds()
	local fps = 1 / (time - lastFrameTime)
	local kills = player.kills()

	-- Reset counter for new rounds
	if counter.airmails > kills or counter.blueplates > kills then
		counter.airmails = 0
		counter.blueplates = 0
	end

	lastFrameTime = time

	drawSmallText(math.floor(fps) .. " fps", module.opts.Text, xpos, ypos, module.opts.Text_Alignment, 1, 1)
	drawSmallText(player.ping() .. " ms", module.opts.Text, xpos, ypos + 16, module.opts.Text_Alignment, 1, 1)
	drawSmallText(kills .. "/" .. player.deaths() .. "/" .. player.assists(), module.opts.Text, xpos, ypos + 32, module.opts.Text_Alignment, 1, 1)
	drawSmallText(counter.blueplates .. " bp " .. counter.airmails .. " am", module.opts.Text, xpos, ypos + 48, module.opts.Text_Alignment, 1, 1)
end

return module
