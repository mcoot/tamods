local module = {}

module.name                  = "sqKillFeed"  -- This HAS to be the same as the filename minus the trailing .lua
module.opts                  = {}
module.opts.X_Position       = 1.0
module.opts.Y_Position       = 47.0
module.opts.Our_Name         = rgb(255,255,0)
module.opts.Background       = rgba(0,0,0,75)
module.opts.Message_Amount   = 5
module.opts.Message_Lifetime = 5

-- Message storage (chat and vgs)
local messages = {}

-- Define some strings for the different kill types
local kill_types = {"Blasted","Stickied","Squished","Knifed","Fell","Vehicle","Bullet","Sniped","Rekt","Headshot","Killed","Disked","Turret","Claimed"}

local onAddToCombatLogOld
if type(onAddToCombatLog) == "function" then
	onAddToCombatLogOld = onAddToCombatLog
end

function onAddToCombatLog(killer_team, killer, kill_type, victim, victim_team)
	if onAddToCombatLogOld then onAddToCombatLogOld(killer_team, killer, kill_type, victim, victim_team) end
	-- team is the sum of:
	-- 0: BE
	-- 1: DS
	-- 2: Our name
	if not killer or #killer == 0 then
		return
	end

	local msg = {}
	msg.time = game.realTimeSeconds()

	-- We don't really need to display Suicide as killer
	if killer == "Suicide" then
		msg.killer = ""
		msg.killtype = ""
		msg.victim = victim .. " suicided"
	elseif killer == "Blood Eagle" or killer == "Diamond Sword" then  -- Base turrets
		local team = victim_team
		if victim_team > 1 then team = team - 2 end
		killer_team = 1 - team  -- Opposite of the victims team
		msg.killer = "Base Turret"
		msg.killtype = " " .. kill_types[kill_type] .. " "
		msg.victim = victim
	else
		msg.killer = killer
		msg.killtype = " " .. kill_types[kill_type] .. " "
		msg.victim = victim
	end

	-- Set colors
	if my_team == 255 then
		msg.kcolor = hud_colors and hud_colors.opts.Team_Text[killer_team] or rgb(255,255,255)
		msg.vcolor = hud_colors and hud_colors.opts.Team_Text[victim_team] or rgb(255,255,255)
	else
		if killer_team > 1 then
			-- We killed someone
			msg.kcolor = module.opts.Our_Name
		else
			msg.kcolor = hud_colors and
			             hud_colors.opts.Team_Text[killer_team == hud_data.my_team and hud_data.left_color or hud_data.right_color] or
			             rgb(255,255,255)
		end

		if victim_team > 1 then
			-- We got killed
			msg.vcolor = module.opts.Our_Name
		else
			msg.vcolor = hud_colors and
			             hud_colors.opts.Team_Text[victim_team == hud_data.my_team and hud_data.left_color or hud_data.right_color] or
			             rgb(255,255,255)
		end
	end

	-- Append new messages to the end
	table.insert(messages, msg)

	-- Keep only n messages
	if #messages > module.opts.Message_Amount then
		-- Remove the oldest message if we are over capacity (first element in the table)
		table.remove(messages, 1)
	end
end

local onKillMessageOld
if type(onKillMessage) == "function" then
	onKillMessageOld = onKillMessage
end

function onKillMessage(text, name)
	if onKillMessageOld then onKillMessageOld(text, name) end

	if text == "Kill credit for" then
		onAddToCombatLog(hud_data.my_team + 2, hud_data.my_name, 14, name, 1 - hud_data.my_team)
	end
end

-- The drawing function for this module
function module.draw(res_x, res_y)
	local xpos = math.floor(module.opts.X_Position / 100 * res_x)
	local ypos = math.floor(module.opts.Y_Position / 100 * res_y)

	local x_pos
	local y_pos = ypos
	local textsize

	local i = 1
	while i <= #messages do
		local item = messages[i]

		if game.realTimeSeconds() - item.time >= time or game.realTimeSeconds() - item.time <= 0 then
			table.remove(messages, i)
		else
			x_pos = xpos + 8

			textsize = getSmallTextSize(item.killer, 1)
			drawRect(xpos, y_pos, x_pos + textsize.x, y_pos + 20, module.opts.Background)
			drawSmallText(item.killer, item.kcolor, x_pos, y_pos + 11, 0, 1, 1)
			x_pos = x_pos + textsize.x

			textsize = getSmallTextSize(item.killtype, 1)
			drawRect(x_pos, y_pos, x_pos + textsize.x, y_pos + 20, module.opts.Background)
			drawSmallText(item.killtype, rgb(160,160,160), x_pos, y_pos + 11, 0, 1, 1)
			x_pos = x_pos + textsize.x

			textsize = getSmallTextSize(item.victim, 1)
			drawRect(x_pos, y_pos, x_pos + textsize.x + 8, y_pos + 20, module.opts.Background)
			drawSmallText(item.victim, item.vcolor, x_pos, y_pos + 11, 0, 1, 1)

			drawRect(xpos, y_pos, xpos + 3, y_pos + 20, item.kcolor)

			i = i + 1
			y_pos = y_pos + 22
		end
	end
end

return module
