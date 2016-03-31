function flag_status(x, y)
	-- Left team
	if not flag.isHome(left_team) then
		local return_time = flag.returnTime(left_team)

		if return_time > 0 then
			-- Flag is dropped, display the time until auto return
			drawText(return_time, team_colors_text[left_color], x - 99, y + 55, 1, 1.2) 
		else
			-- Flag is held, display the name of the holder in the enemies color
			drawText(flag.holderName(left_team), team_colors_text[right_color], x - 99, y + 55, 1, 1) 
		end
	end
	-- Right team
	if not flag.isHome(right_team) then
		local return_time = flag.returnTime(right_team)

		if return_time > 0 then
			-- Flag is dropped, display the time until auto return
			drawText(return_time, team_colors_text[right_color], x + 99, y + 55, 1, 1.2) 
		else
			-- Flag is held, display the name of the holder in the enemies color
			drawText(flag.holderName(right_team), team_colors_text[left_color], x + 99, y + 55, 1, 1) 
		end
	end
end
