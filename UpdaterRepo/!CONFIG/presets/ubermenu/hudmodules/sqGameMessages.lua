local module = {}

module.name            = "sqGameMessages"  -- This HAS to be the same as the filename minus the trailing .lua
module.opts            = {}
module.opts.X_Position = 50.0
module.opts.Y_Position = 15.0
module.opts.Text       = rgba(210,255,200,255)
module.opts.Background = rgba(0,0,0,75)

local endtime = 0
local msgtext = ""

local onGameMessageOld
if type(onGameMessage) == "function" then
	onGameMessageOld = onGameMessage
end

-- This is called by the game whenever we receive a game message
function onGameMessage(text, persistence)
	if onGameMessageOld then onGameMessageOld(text, persistence) end

	msgtext = text
	endtime = game.realTimeSeconds() + persistence
end

function module.draw(res_x, res_y)
	if game.realTimeSeconds() <= endtime then
		local xpos = math.floor(module.opts.X_Position / 100 * res_x)
		local ypos = math.floor(module.opts.Y_Position / 100 * res_y)

		size = getSmallTextSize(msgtext, 1).x
		drawRect(xpos - size / 2 - 5, ypos, xpos + size / 2 + 5, ypos + 20, module.opts.Background)
		drawSmallText(msgtext, module.opts.Text, xpos, ypos + 10, 1, 1, 1)
	end
end

return module
