local module = {}
--Need a chat module installed to work, probably
module.name                        = "dodgeCappingBinds"  -- This HAS to be the same as the filename minus the trailing .lua
module.opts                        = {}         -- Options, you can add your own here
module.opts.X_Position             = 86      -- Position variables should be screen percentage based
module.opts.Y_Position             = 50
module.opts.smartSearch            = true
module.opts.Text                   = rgba(255, 255, 255, 255)
module.opts.TextSize               = 0.5
module.opts.TextShadowSize         = 1
module.opts.bindKeyStart           = "F4"
module.opts.bindKeyReset		   = "F5"
module.opts.Route_Record_Key       = "F6"
module.opts.Route_Record_Stop_Key  = "F7"
module.endTime                     = 0
module.countDown                   = false
module.capperFound                 = false
module.done                        = {}
module.done[25]                    = false
module.done[20]                    = false
module.done[15]                    = false
module.done[10]                    = false
module.done[5]                     = false

console("**** dodgeCappingBinds -- Make sure you have installed an ubermenu chat module so this works ****")

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
bindKey(module.opts.bindKeyReset, Input.PRESSED, 
	function() 
		module.countDown = false
		module.endTime = game.realTimeSeconds()
		teamsay("**** RESET ****")
	end)

bindKey(module.opts.Route_Record_Key, Input.PRESSED, function() module.recStart() end)
bindKey(module.opts.Route_Record_Stop_Key, Input.PRESSED, function() module.recStop() end)
	
	
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
		local xpos = math.floor(module.opts.X_Position / 100 * res_x)
		local ypos = math.floor(module.opts.Y_Position / 100 * res_y)
	
		if module.countDown == true then 
			checkTime()
		end
		if module.capperFound == true then
			if math.ceil(module.endTime - game.realTimeSeconds()) >= 0 then
				--str, col, x, y, align, shadowSize, 1.0f, size, 3
				drawUTText(math.ceil(module.endTime - game.realTimeSeconds()), module.opts.Text, xpos, ypos, 1, module.opts.TextShadowSize, module.opts.TextSize)
			else
				module.countDown = false
				module.capperFound = false
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
end

function module.recStop()
	stopwatch.stop()
	route.recStop()
	returnFlags()
end

return module
