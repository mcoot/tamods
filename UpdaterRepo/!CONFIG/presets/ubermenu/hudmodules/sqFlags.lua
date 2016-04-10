local module = {}

module.name            = "sqFlags"  -- This HAS to be the same as the filename minus the trailing .lua
module.opts            = {}
module.opts.X_Position = 56.03
module.opts.Y_Position = 0.0
module.opts.Background = rgba(0,0,0,50)

function module.draw(res_x, res_y)
	if hud_data.game_type ~= "TrGame_TRCTF" and
	   hud_data.game_type ~= "TrGame_TrCTFBlitz" and
	   hud_data.game_type ~= "TrGame_TRTeamRabbit"
	then return end

	local xpos = math.floor(module.opts.X_Position / 100 * res_x)
	local ypos = math.floor(module.opts.Y_Position / 100 * res_y)

	local left_text = ""
	local right_text = ""

	if not flag.isHome(hud_data.left_team) then
		if flag.holderName(hud_data.left_team) ~= "" then
			right_text = flag.holderName(hud_data.left_team)
		else
			left_text = flag.returnTime(hud_data.left_team)
		end
	end

	if not flag.isHome(hud_data.right_team) then
		if flag.holderName(hud_data.right_team) ~= "" then
			if left_text ~= "" then
				left_text = left_text .. " " .. flag.holderName(hud_data.right_team)
			else
				left_text = flag.holderName(hud_data.right_team)
			end
		else
			if right_text ~= "" then
				right_text = flag.returnTime(hud_data.right_team) .. " " .. right_text
			else
				right_text = flag.returnTime(hud_data.right_team)
			end
		end
	end

	if left_text ~= "" then
		size = getSmallTextSize(left_text, 1).x
		drawRect(xpos, ypos, xpos + size + 10, ypos + 20, module.opts.Background)
		drawSmallText(left_text, hud_colors and hud_colors.opts.Team_Text[hud_data.left_color] or rgb(255,255,255), xpos + 5, ypos + 11, 0, 1, 1) 
	end

	if right_text ~= "" then
		size = getSmallTextSize(right_text, 1).x
		drawRect(xpos, ypos + 20, xpos + size + 10, ypos + 40, module.opts.Background)
		drawSmallText(right_text, hud_colors and hud_colors.opts.Team_Text[hud_data.right_color] or rgb(255,255,255), xpos + 5, ypos + 31, 0, 1, 1) 
	end
end

return module
