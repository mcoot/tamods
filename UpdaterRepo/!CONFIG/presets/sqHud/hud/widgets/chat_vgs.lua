-- Message storage (chat and vgs)
local messages = {}
local messages_max = 5
local persistence = 12
local vgs_persistence = 4

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
		msg.color = rgb(207,165,101) 
	elseif channel == 3 then
		-- Team messages
		msg.text = "[TEAM] " .. msg.text
		msg.color = sqHud.team_colors_text[sqHud.left_color]
	elseif team ~= 255 then
		-- Global messages
		if sqHud.my_team == 255 then
			msg.color = sqHud.team_colors_text[team]
		else
			msg.color = sqHud.team_colors_text[team == sqHud.my_team and sqHud.left_color or sqHud.right_color]
		end
	else
		-- Spectator and other messages
		msg.color = sqHud.text_color1
	end

	if is_vgs then
		msg.color = sqHud.team_colors_vgs[team == sqHud.my_team and sqHud.left_color or sqHud.right_color]
	end

	-- Also draw the message to the console
	consoleRGB(os.date("[%X] ") .. msg.text, msg.color)

	-- Append new messages to the end
	table.insert(messages, msg)

	-- Keep only n messages
	if #messages > messages_max then
		-- Remove the oldest message if we are over capacity (first element in the table)
		table.remove(messages, 1)
	end
end

sqHud.chat_vgs = function(x, y)
	local y_pos = y
	local i = 1
	while i <= #messages do
		local item = messages[i]
		local time = item.vgs and vgs_persistence or persistence
		if game.realTimeSeconds() - item.time >= time then
			table.remove(messages, i)
		else
			local size = getSmallTextSize(item.text, 1)
			drawRect(x, y_pos, x + 14 + size.x, y_pos + 20, sqHud.bg_color1)
			drawRect(x, y_pos, x + 3, y_pos + 20, item.color)
			drawSmallText(item.text, item.color, x + 8, y_pos + 11, 0, 1, 1)
			i = i + 1
			y_pos = y_pos + 22
		end
	end
end
