local module = {}

module.name = "mcootKillNotifications"  -- This HAS to be the same as the filename minus the trailing .lua
module.opts = {}
module.opts.Show_Kill_Notifications = true
module.opts.Feed_X_Position = 50      -- Position variables should be screen percentage based
module.opts.Feed_Y_Position = 70
module.opts.Feed_Limit = 5
module.opts.Feed_Time = 5
module.opts.Use_Small_Text = false
module.opts.Text_Size = 1

local feed = {}

local kill_types = {"Exploded","Stickied","Squished","Meleed","Fell","Vehicle","Chained","Sniped","Rekt","Headshot","Killed","Disked","Turretted","Credit for"}
local team_names = {"Blood Eagle", "Diamond Sword", "Unknown"}

local onAddToCombatLogOld
if type(onAddToCombatLog) == "function" then
	onAddToCombatLogOld = onAddToCombatLog
end

function onAddToCombatLog(killer_team, killer, kill_type, victim, victim_team)
	if onAddToCombatLogOld then onAddToCombatLogOld(killer_team, killer, kill_type, victim, victim_team) end

	if killer ~= hud_data.my_name then
		return	
	end
	
	
	local msg = {}
	msg.time = game.realTimeSeconds()
	msg.player = victim
	msg.team = team_names[killer_team]
	msg.isEnemy = not (victim_team == hud_data.my_team)
	msg.type = kill_types[kill_type]
	table.insert(feed, msg)
	
	-- Message limit
	if #feed > module.opts.Feed_Limit then
		table.remove(feed, 1)
	end
end

local onKillMessageOld
if type(onKillMessage) == "function" then
	onKillMessageOld = onKillMessage
end

function onKillMessage(text, name)
	if onKillMessageOld then onKillMessageOld(text, name) end
	
	-- if text == "Kill credit for" then
		-- onAddToCombatLog(hud_data.my_team + 2, hud_data.my_name, 14, name, 1 - hud_data.my_team)
	-- end
end

function draw_killnotifs(res_x, res_y)
	local xBasePos = math.floor(module.opts.Feed_X_Position / 100 * res_x)
	local yBasePos = math.floor(module.opts.Feed_Y_Position / 100 * res_y)
	local i = 1
	while i <= #feed do
		local item = feed[i]
		if game.realTimeSeconds() - item.time >= module.opts.Feed_Time or game.realTimeSeconds() - item.time < 0 then
			table.remove(feed, i)
		else
			local infoText = item.type .. " "
			local nameText = item.player
			
			local infoSize = getTextSize(infoText, module.opts.Text_Size)
			local nameSize = getTextSize(nameText, module.opts.Text_Size)
			
			if module.opts.Use_Small_Text then
				local infoSize = getSmallTextSize(infoText, module.opts.Text_Size)
				local nameSize = getSmallTextSize(nameText, module.opts.Text_Size)
			end
			
			
			local nameColor = rgb(255, 255, 255)
			if item.isEnemy then
				nameColor = hud_colors and hud_colors.opts.Team_Text[0] or rgba(255, 23, 23, 255)
			else
				nameColor = hud_colors and hud_colors.opts.Team_Text[1] or rgba(158, 200, 222, 255)
			end
			
			local xPos = xBasePos - (infoSize.x + nameSize.x) / 2
			local yPos = yBasePos + (math.max(infoSize.y, nameSize.y) + 5) * i
			
			if module.opts.Use_Small_Text then
				drawSmallText(infoText, rgb(255, 255, 255), xPos, yPos, 1, 1, module.opts.Text_Size)
				drawSmallText(nameText, nameColor, xPos + infoSize.x, yPos, 1, 1, module.opts.Text_Size)
			else
				drawText(infoText, rgb(255, 255, 255), xPos, yPos, 0, module.opts.Text_Size)
				drawText(nameText, nameColor, xPos + infoSize.x, yPos, 0, module.opts.Text_Size)
			end
			
		end
		i = i + 1
	end
end

function module.draw(res_x, res_y)
	draw_killnotifs(res_x, res_y)
end

return module