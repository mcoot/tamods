function generator_status(x, y)
	if game_type == "TrGame_TRCTF" or game_type == "TrGame_TrCTFBlitz" then
		-- Left
		if not game.isGenUp(0) then
			local repair_timer = game.genAutoRepairTime(0)
			if repair_timer > 0 then
				-- Display the remaining time until auto repair
				drawUTText("Gen: " .. repair_timer, team_colors_text[0], x - 200, y, 1, 1, 1)
			else
				-- Auto repairing is turned off, just display that the generator is down
				drawUTText("Gen down", team_colors_text[0], x - 200, y, 1, 1, 1)
			end
		end
		-- Right
		if not game.isGenUp(1) then
			local repair_timer = game.genAutoRepairTime(1)
			if repair_timer > 0 then
				-- Display the remaining time until auto repair
				drawUTText("Gen: " .. repair_timer, team_colors_text[1], x + 200, y, 1, 1, 1)
			else
				-- Auto repairing is turned off, just display that the generator is down
				drawUTText("Gen down", team_colors_text[1], x + 200, y, 1, 1, 1)
			end
		end
	end
end
