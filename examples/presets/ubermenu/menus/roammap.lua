local sub = ubermenu:add_submenu({ title = "Roam Map" })
	sub1 = sub:add_submenu({ title = "Save State" })
		for i = 1,9 do sub1:add_item({ title = "Slot #" .. i, func = function() state.saveTo(i) end }) end

		sub1:add_separator({})
		sub1:add_item({ title = "Reset", func = state.reset })

	sub1 = sub:add_submenu({ title = "Restore State" })
		for i = 1,9 do sub1:add_item({ title = "Slot #" .. i, func = function() state.recallTo(i) end }) end

		sub1:add_separator({})
		sub1:add_item({ title = "Reset", func = state.reset() })

	sub1 = sub:add_submenu({ title = "Teleport" })
		for i = 1,9 do sub1:add_item({ title = "Slot #" .. i, func = function() state.tpTo(i) end }) end

		sub1:add_separator({})
		sub1:add_item({ title = "Reset", func = state.reset })

	sub:add_separator({})
	sub:add_item({ title = "Load Spawn Points", func = function() state.setToSpawns() end })
	sub:add_item({ title = "Reset", func = state.reset })

	sub:add_separator({})
	sub:add_item({ title = "Toggle Base Turrets", func = function() toggleTurrets() end })
	sub:add_item({ title = "Toggle Power", func = togglePower })
	sub:add_item({ title = "Return Flags", func = returnFlags })

sub = nil
sub1 = nil
