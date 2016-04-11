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

sqHud.game_messages = function(x, y)
	if game.realTimeSeconds() <= endtime then
		size = getSmallTextSize(msgtext, 1)
		drawRect(x - size.x / 2 - 5, y - 10, x + size.x / 2 + 5, y + 10, sqHud.bg_color2)
		drawSmallText(msgtext, sqHud.text_color4, x, y, 1, 1, 1)
	end
end	
