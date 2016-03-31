-- Message storage (chat and vgs)
local messages = {}
local messages_max = 5
local persistence = 12

function onChatMessage(team, channel, sender, text, is_vgs)
	local msg = {}
	msg.time = os.time()

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
		msg.color = team_colors_text[left_color]
	elseif team ~= 255 then
		-- Global messages
		if my_team == 255 then
			msg.color = team_colors_text[team]
		else
			msg.color = team_colors_text[team == my_team and left_color or right_color]
		end
	else
		-- Spectator and other messages
		msg.color = text_color1
	end

	if is_vgs then
		msg.color = team_colors_vgs[team == my_team and left_color or right_color]
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

function chat_vgs(x, y)
	local i = 1
	while i <= #messages do
		local item = messages[i]
		if os.time() - item.time >= persistence then
			table.remove(messages, i)
		else
			local size = getSmallTextSize(item.text, 1)
			drawRect(x, y + 22 * i, x + 14 + size.x, y + 20 + 22 * i, bg_color1)

			drawRect(x, y + 22 * i, x + 3, y + 20 + 22 * i, item.color)
			drawSmallText(item.text, item.color, x + 8, y + 11 + 22 * i, 0, 1, 1)
			i = i + 1
		end
	end
end
