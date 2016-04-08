function playerMenu(parent, menu)
	menu:clear()

	players = game.players()

	for j = 0,2 do
		if j == 2 then j = 255 end

		if j == 0 then menu:add_separator({ title = "Blood Eagle" })
		elseif j == 1 then menu:add_separator({ title = "Diamond Sword" })
		else menu:add_separator({ title = "Spectators" }) end

		if #players[j] > 0 then
			for i = 1,#players[j] do
				local sub = menu:add_submenu({ title = players[j][i].name })
					local name = players[j][i].name:gsub("(%S+ )(.*)", "%2")
					sub:add_item({ title = "/votekick", func = function() openConsole("/votekick " .. name) end })
					sub:add_item({ title = "/mute", func = function() openConsole("/mute " .. name) end })
					sub:add_item({ title = "/unmute", func = function() openConsole("/unmute " .. name) end })
					sub:add_item({ title = "/report", func = function() openConsole("/report " .. name) end })
					sub:add_item({ title = "/sc player Kick", func = function() openConsole("/sc player kick " .. name) end })
					sub:add_item({ title = "/sc player Ban",  func = function() openConsole("/sc player ban " .. name) end })
			end
		else
			menu:add_item({ title = "None" })
		end
	end
end

ubermenu:add_submenu({ title = "Players", func = playerMenu })
