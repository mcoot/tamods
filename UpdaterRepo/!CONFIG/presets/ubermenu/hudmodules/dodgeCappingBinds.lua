local module = {}
--Need a chat module installed to work, probably
module.name                        = "dodgeCappingBinds"  -- This HAS to be the same as the filename minus the trailing .lua
module.opts                        = {}         -- Options, you can add your own here
module.opts.X_Position             = 86      -- Position variables should be screen percentage based
module.opts.Y_Position             = 50
module.opts.smartSearch            = true
module.opts.Timer_Text             = rgba(255, 255, 255, 255)
module.opts.Timer_Text_Size        = 1
module.opts.Timer_Text_ShadowSize  = 1
module.opts.Timer_Small            = true
module.opts.bindKeyStart           = "F4"
module.opts.bindKeyReset		   = "F5"
module.opts.enableRecordingBinds   = true
module.opts.Route_Record_Key       = "F6"
module.opts.Route_Record_Stop_Key  = "F7"
module.opts.Route_Record_Save_Key  = "F8"
module.opts.Route_Record_Reset_Key = "F9"
module.endTime                     = 0
module.countDown                   = false
module.capperFound                 = false
module.done                        = {}
module.done[25]                    = false
module.done[20]                    = false
module.done[15]                    = false
module.done[10]                    = false
module.done[5]                     = false
module.RecStatus				   = "Nope"
module.alertTime                   = 0
module.alertActive                 = false

--Chat Module
module.opts.Use_Dodges_Chat_Module = true
module.opts.Chat_X_Position        = 1.0
module.opts.Chat_Y_Position        = 16.0
module.opts.Chat_Private_Message   = rgb(207,165,101)
module.opts.Chat_Background        = rgba(0,0,0,75)
module.opts.Chat_Message_Amount    = 5
module.opts.Chat_Lifetime          = 12
module.opts.VGS_Lifetime           = 12
module.opts.Chat_Small             = false

local messages = {}
local binded = false

console("**** Please enable the Global_Colors Module, Thanks for reading ****")

	
local onChatMessageOld
if type(onChatMessage) == "function" then
	onChatMessageOld = onChatMessage
end

function onChatMessage(team, channel, sender, text, is_vgs)
	if onChatMessageOld then onChatMessageOld(team, channel, sender, text, is_vgs) end
	if module.opts.smartSearch == true and channel == 3 then
		if text == "**** 30 ****" then
			module.capperFound = true
			module.endTime = game.realTimeSeconds() + 30
		elseif text == "**** RESET ****" then
			module.capperFound = false
		end
	end
	
	if module.opts.Use_Dodges_Chat_Module == true then
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
			msg.color = module.opts.Chat_Private_Message
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
		if #messages > module.opts.Chat_Message_Amount then
			-- Remove the oldest message if we are over capacity (first element in the table)
			table.remove(messages, 1)
		end
	end
end

function checkTime()
	if math.ceil(module.endTime - game.realTimeSeconds()) == 25 and module.done[25] == false then
		teamsay("**** 25 ****")
		module.done[25] = true
	elseif math.ceil(module.endTime - game.realTimeSeconds()) == 20 and module.done[20] == false then
		teamsay("**** 20 ****")
		module.done[20] = true
	elseif math.ceil(module.endTime - game.realTimeSeconds()) == 15 and module.done[15] == false then
		teamsay("**** 15 ****")
		module.done[15] = true
	elseif math.ceil(module.endTime - game.realTimeSeconds()) == 10 and module.done[10] == false then
		teamsay("**** 10 ****")
		module.done[10] = true
	elseif math.ceil(module.endTime - game.realTimeSeconds()) == 5 and module.done[5] == false then
		teamsay("**** 05 ****")
		module.done[5] = true
	elseif math.ceil(module.endTime - game.realTimeSeconds()) < 0 then
		module.countDown = false
		module.capperFound = false
	end
end
-- The drawing function for this module
function module.draw(res_x, res_y)
	
	if hud_data.game_type == "TrGame_TRCTF" or hud_data.game_type == "TrGame_TrCTFBlitz" or hud_data.game_type == "TrGame_TRTeamRabbit" then

		if binded == false then
			if module.opts.Route_Record_Key ~= "" then
				bindKey(module.opts.Route_Record_Key, Input.PRESSED, function() module.recStart() end)
			end
			if module.opts.Route_Record_Stop_Key ~= "" then
				bindKey(module.opts.Route_Record_Stop_Key, Input.PRESSED, function() module.recStop() end)
			end
			if module.opts.Route_Record_Save_Key ~= "" then
				bindKey(module.opts.Route_Record_Save_Key, Input.PRESSED, function() openConsole("/routesave YOUR_DESCRIPTION_HERE") end)
			end
			if module.opts.Route_Record_Reset_Key ~= "" then
				bindKey(module.opts.Route_Record_Reset_Key, Input.PRESSED, function() module.recReset() end)
			end
			if module.opts.bindKeyStart ~= "" then
				bindKey(module.opts.bindKeyStart, Input.PRESSED, 
					function() 
						module.countDown = true
						module.endTime = game.realTimeSeconds() + 30
						teamsay("**** 30 ****")
						module.done[25] = false
						module.done[20] = false
						module.done[15] = false
						module.done[10] = false
						module.done[5]  = false
					end)
			end
			if module.opts.bindKeyReset ~= "" then
				bindKey(module.opts.bindKeyReset, Input.PRESSED, 
					function() 
						module.countDown = false
						module.endTime = game.realTimeSeconds()
						teamsay("**** RESET ****")
					end)
			end
			binded = true
		end

		local xpos = math.floor(module.opts.X_Position / 100 * res_x)
		local ypos = math.floor(module.opts.Y_Position / 100 * res_y)
	
		if module.countDown == true then 
			checkTime()
		end
		if module.capperFound == true then
			if math.ceil(module.endTime - game.realTimeSeconds()) >= 0 then
				--str, col, x, y, align, shadowSize, 1.0f, size, 3
				if module.opts.Timer_Small == true then
					drawSmallText(math.ceil(module.endTime - game.realTimeSeconds()), module.opts.Timer_Text, xpos, ypos, 1, module.opts.Timer_Text_ShadowSize, module.opts.Timer_Text_Size)
				else
					drawText(math.ceil(module.endTime - game.realTimeSeconds()), module.opts.Timer_Text, xpos, ypos, module.opts.Timer_Text_ShadowSize, module.opts.Timer_Text_Size)
				end
			else
				module.countDown = false
				module.capperFound = false
			end
		end
		if module.RecStatus == "Recording" then
			drawUTText(module.RecStatus, rgb(255,0,0), math.floor(1 / 2 * res_x), math.floor(1 / 10 * res_y), 1, 1, 4)
		elseif module.alertActive == true then
			drawUTText(module.RecStatus, rgb(255,0,0), math.floor(1 / 2 * res_x), math.floor(1 / 10 * res_y), 1, 1, 4)
			if math.ceil(module.alertTime - game.realTimeSeconds()) < 0 then
				module.alertActive = false
			end
		end
		
	end
	if module.opts.Use_Dodges_Chat_Module == true then
		local xChatpos = math.floor(module.opts.Chat_X_Position / 100 * res_x)
		local yChatpos = math.floor(module.opts.Chat_Y_Position / 100 * res_y)
		local y_pos = yChatpos
		--CHAT
		local i = 1
		while i <= #messages do
			local item = messages[i]
			local time = item.vgs and module.opts.VGS_Lifetime or module.opts.Chat_Lifetime
			if game.realTimeSeconds() - item.time >= time or game.realTimeSeconds() - item.time < 0 then
				table.remove(messages, i)
			else
				local size = getSmallTextSize(item.text, 1)
				if module.opts.Chat_Small == true then
					drawSmallText(item.text, item.color, xChatpos + 8, y_pos + 11, 0, 1, 1)
					drawRect(xChatpos, y_pos, xChatpos + 14 + size.x, y_pos + 20, module.opts.Chat_Background)
					drawRect(xChatpos, y_pos, xChatpos + 3, y_pos + 20, item.color)
				else
					drawText(item.text, item.color, xChatpos, y_pos + 11, 0, 1)
				end
				i = i + 1
				y_pos = y_pos + 22
			end
		end
	end
end

--Recording Functions
function module.recStart()
	state.tp()
	stopwatch.start()
	route.recStart()
	returnFlags()
	module.RecStatus = "Recording"
end

function module.recStop()
	stopwatch.stop()
	route.recStop()
	returnFlags()
	module.RecStatus = "Recording Stopped"
	module.alert()
end

function module.alert()
	module.alertTime = game.realTimeSeconds() + 2
	module.alertActive = true
end

function module.recReset()
	module.RecStatus = "Route Reset"
	module.alert()
	route.reset()
end

return module
