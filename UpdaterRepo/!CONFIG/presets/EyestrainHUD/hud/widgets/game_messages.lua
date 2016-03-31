local endtime = 0
local msgtext = nil

-- This is called by the game whenever we receive a game message
function onGameMessage(text, persistence)
	msgtext = text
	endtime = os.time() + persistence
end

function game_messages(x, y)
	if os.time() <= endtime then
		--drawRect(x - (textsize.x/2), y - 12, x + (textsize.x/2), y + 12, bg_colors1)
		local textsize = getSmallTextSize(msgtext, 1)
		drawRect(x - textsize.x/2 - 8, y - 12, x + textsize.x/2 + 8, y + 12, bg_color1)
		drawSmallText(msgtext, text_color4, x, y, 1, 1, 1)
	end
end	
