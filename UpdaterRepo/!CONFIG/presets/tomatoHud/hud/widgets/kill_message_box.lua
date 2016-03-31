local endtime = 0
local killtext = nil
local victim = nil
local persistence = 3

-- This is called by the game whenever we kill somebody
function onKillMessage(text, name)
	killtext = text
	victim = name
	endtime = os.time() + persistence
end

function kill_message_box(x, y)
	-- Only show new messages
	if os.time() <= endtime then
		local textsize = getTextSize(victim, 1.3)
		drawRect(x - 25 - textsize.x / 2, y, x + 25 + textsize.x / 2, y + 70, bg_color3)
		drawBox(x - 25 - textsize.x / 2, y, x + 25 + textsize.x / 2 + 2, y + 70, rgb(0, 0, 0))
		drawText(victim, text_color2, x, y + 40, 1, 1.3)
		drawSmallText(killtext, text_color1, x - 20 - textsize.x / 2, y + 9, 0, 1, 1)
	end
end
