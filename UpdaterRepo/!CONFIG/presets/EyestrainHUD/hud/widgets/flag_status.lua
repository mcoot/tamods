function flag_status(x, y)
	-- Left team
	if not flag.isHome(left_team) then
		local return_time = flag.returnTime(left_team)

		if return_time > 0 then
			local textsize = getSmallTextSize("Away: " .. return_time, 1)
			local y_pos = y + 1
			drawRect(x + 17, y_pos - 1, x + textsize.x + 28, y_pos + 24, bg_color1)
			drawRect(x - 8, y_pos - 1, x + 17, y_pos + 24, rgba(0, 0, 0, 200))
			draw2dLine(x + 10, y_pos + 3, x + 2, y_pos + 20, rgb(64, 64, 64))
			draw2dLine(x + 9, y_pos + 3, x + 1, y_pos + 20, rgb(64, 64, 64))
			drawRect(x - 2, y_pos + 3, x + 2, y_pos + 10, rgb(64, 64, 64))
			drawRect(x + 2, y_pos + 2, x + 6, y_pos + 9, rgb(64, 64, 64))
			drawRect(x + 6, y_pos + 3, x + 7, y_pos + 7, rgb(64, 64, 64))
			drawRect(x + 7, y_pos + 3, x + 8, y_pos + 6, rgb(64, 64, 64))
			drawSmallText("Away: " .. return_time, text_color1, x + 22, y_pos + 11, 0, 1, 1) 
		else
			local flag_holder_left_size = getSmallTextSize(flag.holderName(left_team), 1)
			local y_pos = y + 1
			drawRect(x + 17, y_pos - 1, x + flag_holder_left_size.x + 28, y_pos + 24, bg_color1)
			drawRect(x - 8, y_pos - 1, x + 17, y_pos + 24, rgba(0, 0, 0, 200))
			draw2dLine(x + 10, y_pos + 3, x + 2, y_pos + 20, team_colors_text[right_color])
			draw2dLine(x + 9, y_pos + 3, x + 1, y_pos + 20, team_colors_text[right_color])
			drawRect(x - 2, y_pos + 3, x + 2, y_pos + 10, team_colors_text[right_color])
			drawRect(x + 2, y_pos + 2, x + 6, y_pos + 9, team_colors_text[right_color])
			drawRect(x + 6, y_pos + 3, x + 7, y_pos + 7, team_colors_text[right_color])
			drawRect(x + 7, y_pos + 3, x + 8, y_pos + 6, team_colors_text[right_color])
			drawSmallText(flag.holderName(left_team), team_colors_text[right_color], x + 22, y + 12, 0, 1, 1) 
		end
	else
			local y_pos = y + 1
			drawRect(x + 17, y_pos - 1, x + 36 + 28, y_pos + 24, bg_color1)
			drawRect(x - 8, y_pos - 1, x + 17, y_pos + 24, rgba(0, 0, 0, 200))
			draw2dLine(x + 10, y_pos + 3, x + 2, y_pos + 20, rgb(160, 160, 160))
			draw2dLine(x + 9, y_pos + 3, x + 1, y_pos + 20, rgb(160, 160, 160))
			drawRect(x - 2, y_pos + 3, x + 2, y_pos + 10, rgb(160, 160, 160))
			drawRect(x + 2, y_pos + 2, x + 6, y_pos + 9, rgb(160, 160, 160))
			drawRect(x + 6, y_pos + 3, x + 7, y_pos + 7, rgb(160, 160, 160))
			drawRect(x + 7, y_pos + 3, x + 8, y_pos + 6, rgb(160, 160, 160))
			drawSmallText("Home", text_color1, x + 22, y_pos + 11, 0, 1, 1) 
	end
	-- Right team
	if not flag.isHome(right_team) then
		local return_time = flag.returnTime(right_team)

		if return_time > 0 then
			-- Flag is dropped, display the time until auto return
			local textsize = getSmallTextSize("Away: " .. return_time, 1)
			local y_pos = y + 29
			drawRect(x + 17, y_pos - 1, x + textsize.x + 28, y_pos + 24, bg_color1)
			drawRect(x - 8, y_pos - 1, x + 17, y_pos + 24, rgba(0, 0, 0, 200))
			draw2dLine(x + 10, y_pos + 3, x + 2, y_pos + 20, rgb(64, 64, 64))
			draw2dLine(x + 9, y_pos + 3, x + 1, y_pos + 20, rgb(64, 64, 64))
			drawRect(x - 2, y_pos + 3, x + 2, y_pos + 10, rgb(64, 64, 64))
			drawRect(x + 2, y_pos + 2, x + 6, y_pos + 9, rgb(64, 64, 64))
			drawRect(x + 6, y_pos + 3, x + 7, y_pos + 7, rgb(64, 64, 64))
			drawRect(x + 7, y_pos + 3, x + 8, y_pos + 6, rgb(64, 64, 64))
			drawSmallText("Away: " .. return_time, text_color1, x + 22, y_pos + 11, 0, 1, 1)  
		else
			local flag_holder_right_size = getSmallTextSize(flag.holderName(right_team), 1)
			local y_pos = y + 29
			drawRect(x + 17, y_pos - 1, x + flag_holder_right_size.x + 28, y_pos + 24, bg_color1)
			drawRect(x - 8, y_pos - 1, x + 17, y_pos + 24, rgba(0, 0, 0, 200))
			draw2dLine(x + 10, y_pos + 3, x + 2, y_pos + 20, team_colors_text[left_color])
			draw2dLine(x + 9, y_pos + 3, x + 1, y_pos + 20, team_colors_text[left_color])
			drawRect(x - 2, y_pos + 3, x + 2, y_pos + 10, team_colors_text[left_color])
			drawRect(x + 2, y_pos + 2, x + 6, y_pos + 9, team_colors_text[left_color])
			drawRect(x + 6, y_pos + 3, x + 7, y_pos + 7, team_colors_text[left_color])
			drawRect(x + 7, y_pos + 3, x + 8, y_pos + 6, team_colors_text[left_color])
			
			drawSmallText(flag.holderName(right_team), team_colors_text[left_color], x + 22, y_pos + 11, 0, 1, 1) 
		end
	else
			local y_pos = y + 29
			drawRect(x + 17, y_pos - 1, x + 36 + 28, y_pos + 24, bg_color1)
			drawRect(x - 8, y_pos - 1, x + 17, y_pos + 24, rgba(0, 0, 0, 200))
			draw2dLine(x + 10, y_pos + 3, x + 2, y_pos + 20, rgb(160, 160, 160))
			draw2dLine(x + 9, y_pos + 3, x + 1, y_pos + 20, rgb(160, 160, 160))
			drawRect(x - 2, y_pos + 3, x + 2, y_pos + 10, rgb(160, 160, 160))
			drawRect(x + 2, y_pos + 2, x + 6, y_pos + 9, rgb(160, 160, 160))
			drawRect(x + 6, y_pos + 3, x + 7, y_pos + 7, rgb(160, 160, 160))
			drawRect(x + 7, y_pos + 3, x + 8, y_pos + 6, rgb(160, 160, 160))
			drawSmallText("Home", text_color1, x + 22, y_pos + 11, 0, 1, 1) 
	end
		
		
end
