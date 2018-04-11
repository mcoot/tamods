local module = {}
--Need a chat module installed to work, probably
module.name                        = "dodgeServerAdminBinds"  -- This HAS to be the same as the filename minus the trailing .lua
module.opts                        = {}         -- Options, you can add your own here
module.opts.Bind_Key_End_Map       = "F2"
module.opts.Map_0_Bind_Key         = "F3" -- Arx Example
module.opts.Map_0_Code             = "1456" -- Arx Example
module.opts.Map_1_Bind_Key         = "" -- "/sc map next " Example
module.opts.Map_1_Code             = "" -- "/sc map next " Example
module.opts.Map_2_Bind_Key         = ""
module.opts.Map_2_Cod              = ""
module.opts.Map_3_Bind_Key         = ""
module.opts.Map_3_Code             = ""
module.opts.Map_4_Bind_Key         = ""
module.opts.Map_4_Code             = ""
module.opts.Map_5_Bind_Key         = ""
module.opts.Map_5_Code             = ""
module.opts.Map_6_Bind_Key         = ""
module.opts.Map_6_Code             = ""
module.opts.Map_7_Bind_Key         = ""
module.opts.Map_7_Code             = ""
module.opts.Map_8_Bind_Key         = ""
module.opts.Map_8_Code             = ""
module.opts.Map_9_Bind_Key         = ""
module.opts.Map_9_Code             = ""

local msgs = {
	"CTF Map Codes",
	"1456 - Arx Novena",
	"1447 - Katabatic",
	"1457 - Drydock",
	"1538 - Dangerous Crossing",
	"1462 - Crossfire",
	"1523 - Sunstar",
	"1534 - Permafrost",
	"1551 - Bella Omega NS",
	"1573 - Bella Omega",
	"1514 - Canyon Crusade Revival",
	"1512 - Tartarus",
	"1516 - Raindance",
	"1522 - Stonehenge",
	"1493 - Temple Ruins",
	"1543 - Blueshift",
	"1553 - Terminus",
	"1554 - Icecoaster",
	"1555 - Perdition"
}

local binded = false

consoleRGB(msgs[1], rgb(255,255,0))

for msgCount = 2, #msgs do
  consoleRGB(msgs[msgCount], rgb(0,255,255))
end


function module.draw(res_x, res_y)
	if binded == false then
		if module.opts.Bind_Key_End_Map ~= "" then
			bindKey(module.opts.Bind_Key_End_Map, Input.PRESSED, function() openConsole("/sc map end") end)
		end
		if module.opts.Map_0_Bind_Key ~= "" then
			bindKey(module.opts.Map_0_Bind_Key, Input.PRESSED, function() openConsole("/sc map next " .. module.opts.Map_0_Code) end)
		end
		if module.opts.Map_1_Bind_Key ~= "" then
			bindKey(module.opts.Map_1_Bind_Key, Input.PRESSED, function() openConsole("/sc map next " .. module.opts.Map_1_Code) end)
		end
		if module.opts.Map_2_Bind_Key ~= "" then
			bindKey(module.opts.Map_2_Bind_Key, Input.PRESSED, function() openConsole("/sc map next " .. module.opts.Map_2_Code) end)
		end
		if module.opts.Map_3_Bind_Key ~= "" then
			bindKey(module.opts.Map_3_Bind_Key, Input.PRESSED, function() openConsole("/sc map next " .. module.opts.Map_3_Code) end)
		end
		if module.opts.Map_4_Bind_Key ~= "" then
			bindKey(module.opts.Map_4_Bind_Key, Input.PRESSED, function() openConsole("/sc map next " .. module.opts.Map_4_Code) end)
		end
		if module.opts.Map_5_Bind_Key ~= "" then
			bindKey(module.opts.Map_5_Bind_Key, Input.PRESSED, function() openConsole("/sc map next " .. module.opts.Map_5_Code) end)
		end
		if module.opts.Map_6_Bind_Key ~= "" then
			bindKey(module.opts.Map_6_Bind_Key, Input.PRESSED, function() openConsole("/sc map next " .. module.opts.Map_6_Code) end)
		end
		if module.opts.Map_7_Bind_Key ~= "" then
			bindKey(module.opts.Map_7_Bind_Key, Input.PRESSED, function() openConsole("/sc map next " .. module.opts.Map_7_Code) end)
		end
		if module.opts.Map_8_Bind_Key ~= "" then
			bindKey(module.opts.Map_8_Bind_Key, Input.PRESSED, function() openConsole("/sc map next " .. module.opts.Map_8_Code) end)
		end
		if module.opts.Map_9_Bind_Key	~= "" then
			bindKey(module.opts.Map_9_Bind_Key, Input.PRESSED, function() openConsole("/sc map next " .. module.opts.Map_9_Code) end)
		end
		binded = true
	end
end

return module
