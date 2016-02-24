-- Message storage (chat and vgs)
local messages = {}
local messages_max = 4
local persistence = 12

-- Define some strings for the different kill types
kill_types = {"Blasted","Stickied","Squished","Knifed","Fell","Vehicle","Bullet","Sniped","Rekt","Headshot","Killed","Disked","Turret"}

function onAddToCombatLog(team, killer, kill_type, victim)
	-- team is the sum of:
	-- 0: killer is in our team
	-- 1: killer is in the enemy team
	-- 2: the death message is related to us
	local msg = {}
	msg.time = os.time()
	msg.is_dm = true

	-- We don't really need to display Suicide as killer
	if killer == "Suicide" then
		msg.text = victim .. " suicided"
	else
		msg.text = killer .. " |" .. kill_types[kill_type] .. "| " .. victim
	end

	if team > 1 then
		-- We are involved in this death message
		msg.color = rgb(255,255,0)
	else
		-- Others, figure out the corret team color
		msg.color = team == my_team and team_colors_text[right_color] or team_colors_text[left_color]
	end

	-- Append new messages to the end
	table.insert(messages, msg)

	-- Keep only n messages
	if #messages > messages_max then
		-- Remove the oldest message if we are over capacity (first element in the table)
		table.remove(messages, 1)
	end
end

function kill_feed(x, y)
	local i = 1
	while i <= #messages do
		local item = messages[i]
		if os.time() - item.time >= persistence then
			table.remove(messages, i)
		else
			local textsize = getSmallTextSize(item.text, 1)
			local y_pos = y - 22 * (i - 1)
			drawRect(x - 14 - textsize.x, y_pos, x, y_pos + 20, bg_color1)

			drawRect(x - 3, y_pos, x, y_pos + 20, item.color)
			drawSmallText(item.text, item.color, x - 8, y_pos + 11, 2, 1, 1)
			i = i + 1
		end
	end
end
