-- Message storage (chat and vgs)
local messages = {}
local messages_max = 5
local persistence = 12

-- Define some strings for the different kill types
kill_types = {"Blasted","Stickied","Squished","Knifed","Fell","Vehicle","Bullet","Sniped","Rekt","Headshot","Killed","Disked","Turret","Claimed"}

function onAddToCombatLog(killer_team, killer, kill_type, victim, victim_team)
	-- team is the sum of:
	-- 0: BE
	-- 1: DS
	-- 2: Our name
	local msg = {}
	msg.time = os.time()

	-- We don't really need to display Suicide as killer
	if killer == "Suicide" then
		msg.killer = ""
		msg.killtype = ""
		msg.victim = victim .. " suicided"
	else
		msg.killer = killer
		msg.killtype = " " .. kill_types[kill_type] .. " "
		msg.victim = victim
	end

	-- Set colors
	if my_team == 255 then
		msg.kcolor = team_colors_text[killer_team]
		msg.vcolor = team_colors_text[victim_team]
	else
		if killer_team > 1 then
			-- We killed someone
			msg.kcolor = rgb(255,255,0)
		else
			msg.kcolor = team_colors_text[killer_team == my_team and left_color or right_color]
		end

		if victim_team > 1 then
			-- We got killed
			msg.vcolor = rgb(255,255,0)
		else
			msg.vcolor = team_colors_text[victim_team == my_team and left_color or right_color]
		end
	end

	-- Append new messages to the end
	table.insert(messages, msg)

	-- Keep only n messages
	if #messages > messages_max then
		-- Remove the oldest message if we are over capacity (first element in the table)
		table.remove(messages, 1)
	end
end

function onKillMessage(text, name)
	if text == "Kill credit for" then
		onAddToCombatLog(my_team + 2, my_name, 14, name, 1 - my_team)
	end
end

function kill_feed(x, y)
	local i = 1
	while i <= #messages do
		local item = messages[i]

		if os.time() - item.time >= persistence then
			table.remove(messages, i)
		else
			local x_pos = x + 8
			local y_pos = y + 22 * (i - 1)
			local textsize

			textsize = getSmallTextSize(item.killer, 1)
			drawRect(x, y_pos, x_pos + textsize.x, y_pos + 20, bg_color1)
			drawSmallText(item.killer, item.kcolor, x_pos, y_pos + 11, 0, 1, 1)
			x_pos = x_pos + textsize.x

			textsize = getSmallTextSize(item.killtype, 1)
			drawRect(x_pos, y_pos, x_pos + textsize.x, y_pos + 20, bg_color1)
			drawSmallText(item.killtype, rgb(160,160,160), x_pos, y_pos + 11, 0, 1, 1)
			x_pos = x_pos + textsize.x

			textsize = getSmallTextSize(item.victim, 1)
			drawRect(x_pos, y_pos, x_pos + textsize.x + 8, y_pos + 20, bg_color1)
			drawSmallText(item.victim, item.vcolor, x_pos, y_pos + 11, 0, 1, 1)

			drawRect(x, y_pos, x + 3, y_pos + 20, item.kcolor)

			i = i + 1
		end
	end
end
