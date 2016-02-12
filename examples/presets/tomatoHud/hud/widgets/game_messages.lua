local endtime = 0
local msgtext = nil

-- This is called by the game whenever we receive a game message
function onGameMessage(text, persistence)
	msgtext = text
	endtime = os.time() + persistence
end

function game_messages(x, y)
	if os.time() <= endtime then
		drawText(msgtext, text_color4, x, y, 1, 1.3)
	end
end	
