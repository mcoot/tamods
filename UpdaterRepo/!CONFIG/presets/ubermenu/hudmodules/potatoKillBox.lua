local module = {}

module.name            = "potatoKillBox"  -- This HAS to be the same as the filename minus the trailing .lua
module.opts            = {}
module.opts.X_Position = 50.0
module.opts.Y_Position = 77.0
module.opts.Text       = rgba(255,255,255,200)
module.opts.Name_Text  = rgba(255,80,80,255)
module.opts.Background = rgba(0,135,0,150)
module.opts.Min_Width  = 220
module.opts.Min_Height = 100
module.opts.Box_Lifetime = 3

local endtime = nil
local killtext = nil
local victim = nil

local onKillMessageOld
if type(onKillMessage) == "function" then
	onKillMessageOld = onKillMessage
end

-- This is called by the game whenever we kill somebody
function onKillMessage(text, name)
	if onKillMessageOld then onKillMessageOld(text, name) end

	killtext = text
	victim = name
	endtime = game.realTimeSeconds() + module.opts.Box_Lifetime
end

function module.draw(res_x, res_y)
	if endtime == nil then return end

	-- Only show new messages
	if game.realTimeSeconds() <= endtime then
		local xpos = math.floor(module.opts.X_Position / 100 * res_x)
		local ypos = math.floor(module.opts.Y_Position / 100 * res_y)
		local size = getTextSize(victim, 1.3)

		size.x = math.max(module.opts.Min_Width, size.x + 20)
		size.y = math.max(module.opts.Min_Height, size.y + 20)

		drawRect(xpos - size.x / 2, ypos, xpos + size.x / 2, ypos + size.y, module.opts.Background)
		drawText(victim, module.opts.Name_Text, xpos, ypos + size.y / 2, 1, 1.3)
		drawSmallText(killtext, module.opts.Text, xpos - size.x / 2 + 5, ypos + 9, 0, 1, 1)
	else
		endtime = nil
	end
end

return module
