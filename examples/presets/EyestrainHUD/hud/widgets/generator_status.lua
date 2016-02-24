function generator_status(x, y)
	-- Left
	if not game.isGenUp(left_team) then
		local repair_timer = game.genAutoRepairTime(left_team)
		if repair_timer > 0 then
			-- Display the remaining time until auto repair
			drawSmallText(repair_timer, team_colors_text[left_color], x - 58, y + 35, 1, 1, 1)
		else
			-- Auto repairing is turned off, just display that the generator is down
			drawSmallText("No Power", team_colors_text[left_color], x - 58, y + 35, 1, 1, 1)
		end
	end
	-- Right
	if not game.isGenUp(right_team) then
		local repair_timer = game.genAutoRepairTime(right_team)
		if repair_timer > 0 then
			-- Display the remaining time until auto repair
			drawSmallText(repair_timer, team_colors_text[right_color], x + 58, y + 35, 1, 1, 1)
		else
			-- Auto repairing is turned off, just display that the generator is down
			drawSmallText("No Power", team_colors_text[right_color], x + 58, y + 35, 1, 1, 1)
		end
	end
end
