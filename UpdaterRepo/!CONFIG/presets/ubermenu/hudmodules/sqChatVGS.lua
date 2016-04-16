local module = {}

module.name                  = "sqChatVGS"  -- This HAS to be the same as the filename minus the trailing .lua
module.opts                  = {}
module.opts.X_Position       = 1.0
module.opts.Y_Position       = 89.0
module.opts.Private_Message  = rgb(207,165,101)
module.opts.Background       = rgba(0,0,0,75)
module.opts.Message_Amount   = 5
module.opts.Chat_Lifetime    = 12
module.opts.VGS_Lifetime     = 3

-- Message storage (chat and vgs)
local messages = {}

local onChatMessageOld
if type(onChatMessage) == "function" then
	onChatMessageOld = onChatMessage
end

function onChatMessage(team, channel, sender, text, is_vgs)
	if onChatMessageOld then onChatMessageOld(team, channel, sender, text, is_vgs) end

	local msg = {}
	msg.time = game.realTimeSeconds()
	msg.vgs = is_vgs

	-- Message format
	if is_vgs then
		msg.text = sender .. " " .. text
	else
		msg.text = sender .. "> " .. text
	end

	if channel == 6 then
		-- Private messages
		msg.color = module.opts.Private_Message
	elseif channel == 3 then
		-- Team messages
		msg.text = "[TEAM] " .. msg.text
		msg.color = hud_colors and hud_colors.opts.Team_Text[hud_data.left_color] or rgb(255,255,255)
	elseif team ~= 255 then
		-- Global messages
		if hud_data.my_team == 255 then
			msg.color = hud_colors and hud_colors.opts.Team_Text[team] or rgb(255,255,255)
		else
			msg.color = hud_colors and
			            hud_colors.opts.Team_Text[team == hud_data.my_team and hud_data.left_color or hud_data.right_color] or
			            rgb(255,255,255)
		end
	else
		-- Spectator and other messages
		msg.color = hud_colors and hud_colors.opts.Team_Text[255] or rgb(255,255,255)
	end

	if is_vgs then
		msg.color = hud_colors and
		            hud_colors.opts.Team_VGS[team == hud_data.my_team and hud_data.left_color or hud_data.right_color] or
		            rgb(255,255,255)
	end

	-- Also draw the message to the console
	consoleRGB(os.date("[%X] ") .. msg.text, msg.color)

	-- Append new messages to the end
	table.insert(messages, msg)

	-- Keep only n messages
	if #messages > module.opts.Message_Amount then
		-- Remove the oldest message if we are over capacity (first element in the table)
		table.remove(messages, 1)
	end
end

-- The drawing function for this module
function module.draw(res_x, res_y)
	local xpos = math.floor(module.opts.X_Position / 100 * res_x)
	local ypos = math.floor(module.opts.Y_Position / 100 * res_y)

	local y_pos = ypos
	local i = 1
	while i <= #messages do
		local item = messages[i]
		local time = item.vgs and module.opts.VGS_Lifetime or module.opts.Chat_Lifetime
		if game.realTimeSeconds() - item.time >= time or game.realTimeSeconds() - item.time < 0 then
			table.remove(messages, i)
		else
			local size = getSmallTextSize(item.text, 1)
			drawRect(xpos, y_pos, xpos + 14 + size.x, y_pos + 20, module.opts.Background)
			drawRect(xpos, y_pos, xpos + 3, y_pos + 20, item.color)
			drawSmallText(item.text, item.color, xpos + 8, y_pos + 11, 0, 1, 1)
			i = i + 1
			y_pos = y_pos + 22
		end
	end
end

return module
