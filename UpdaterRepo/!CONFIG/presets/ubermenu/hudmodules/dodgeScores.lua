local module = {}

module.name                     = "dodgeScores"  -- This HAS to be the same as the filename minus the trailing .lua
module.opts                     = {}         -- Options, you can add your own here
module.opts.X_Position          = 50      -- Position variables should be screen percentage based
module.opts.Y_Position          = 0
module.opts.Text                = rgba(255,255,255,255)
module.opts.columnWidth         = 55
module.opts.flagWidth           = 10
module.opts.flagHeight          = 20
module.opts.x_flagPadding       = 5
module.opts.y_flagPadding       = 10
module.opts.bg_color            = rgba(0, 0, 0, 125)
module.opts.flag_color          = {}
module.opts.flag_color[0]       = rgba(255, 23, 23, 255)
module.opts.flag_color[1]       = rgba(255, 23, 23, 0)
module.opts.flag_color[2]       = rgba(158, 200, 222, 255)
module.opts.flag_color[3]       = rgba(158, 200, 222, 0)
module.opts.Enable_Icons        = true

-- The drawing function for this module
function module.draw(res_x, res_y)
	if hud_data.game_type == "TrGame_TRCTF" or hud_data.game_type == "TrGame_TrCTFBlitz" or hud_data.game_type == "TrGame_TRTeamRabbit" then
		local xpos = math.floor(module.opts.X_Position / 100 * res_x)
		local ypos = math.floor(module.opts.Y_Position / 100 * res_y)
		local k = 0
		local i = 0
		local j = 0
		
		--Logic Variables
		local x_flagArea = module.opts.flagWidth + (module.opts.x_flagPadding * 2)
		local y_flagArea = module.opts.flagHeight + (module.opts.y_flagPadding * 2)
		local x_FlagSectorR = xpos + module.opts.columnWidth
		local x_FlagSectorL = xpos - module.opts.columnWidth - x_flagArea

		--Draw Enemy Flags
		if module.opts.Enable_Icons == true then
			while i < game.score(hud_data.right_team) do
				drawRect(x_FlagSectorR, ypos, x_FlagSectorR + x_flagArea, ypos + y_flagArea, module.opts.bg_color)
				drawFlag(x_FlagSectorR + module.opts.x_flagPadding, ypos + module.opts.y_flagPadding, module.opts.flag_color[0])
				i = i + 1
				x_FlagSectorR = x_FlagSectorR + x_flagArea
			end
		end
		--Draw Enemy Flag Holder
		if not flag.isHome(hud_data.left_team) then
			local return_time = flag.returnTime(hud_data.left_team)
			local afc = lerpColor(module.opts.flag_color[1], module.opts.flag_color[0], return_time / 40)
			local holding = lerpColor(module.opts.flag_color[1], module.opts.flag_color[0], 0.4)	
			
			drawRect(x_FlagSectorR, ypos, x_FlagSectorR + x_flagArea, ypos + y_flagArea, module.opts.bg_color)
			
			if return_time > 0 then
				local textsize = getSmallTextSize(return_time, 1)
				drawFlag(x_FlagSectorR + module.opts.x_flagPadding, ypos + module.opts.y_flagPadding, afc)
				drawSmallText(return_time, module.opts.Text, x_FlagSectorR, ypos + module.opts.flagHeight, 0, 1, 1) 
			else
				local flag_holder_left_size = getSmallTextSize(flag.holderName(hud_data.left_team), 1)
				drawRect(x_FlagSectorR + x_flagArea, ypos, x_FlagSectorR + flag_holder_left_size.x + x_flagArea + module.opts.x_flagPadding, ypos + y_flagArea, module.opts.bg_color)
				drawSmallText(flag.holderName(hud_data.left_team), module.opts.flag_color[0], x_FlagSectorR + x_flagArea, ypos + 20, 0, 1, 1) 
				drawFlag(x_FlagSectorR + module.opts.x_flagPadding, ypos + module.opts.y_flagPadding, holding)
			end
		end
		
		if module.opts.Enable_Icons == true then
			--Draw Team Flags
			while j < game.score(hud_data.left_team) do
				drawRect(x_FlagSectorL, ypos, x_FlagSectorL + x_flagArea, ypos + y_flagArea, module.opts.bg_color)
				drawFlag(x_FlagSectorL + module.opts.x_flagPadding, ypos + module.opts.y_flagPadding, module.opts.flag_color[2])
				j = j + 1
				x_FlagSectorL = x_FlagSectorL - x_flagArea
			end
		end
		--Draw Team Flag Holder
		if not flag.isHome(hud_data.right_team) then
			local return_time = flag.returnTime(hud_data.right_team)
			local afc = lerpColor(module.opts.flag_color[3], module.opts.flag_color[2], return_time / 40)
			local holding = lerpColor(module.opts.flag_color[3], module.opts.flag_color[2], 0.4)
			
			drawRect(x_FlagSectorL, ypos, x_FlagSectorL + x_flagArea, ypos + y_flagArea, module.opts.bg_color)
			
			if return_time > 0 then
				local textsize = getSmallTextSize(return_time, 1)
				drawFlag(x_FlagSectorL + module.opts.x_flagPadding, ypos + module.opts.y_flagPadding, afc)
				drawSmallText(return_time, module.opts.Text, x_FlagSectorL + x_flagArea - 2, ypos + 20, 2, 1, 1)
			else
				local flag_holder_left_size = getSmallTextSize(flag.holderName(hud_data.right_team), 1)
				drawRect(x_FlagSectorL - flag_holder_left_size.x - module.opts.x_flagPadding, ypos, x_FlagSectorL, ypos + y_flagArea, module.opts.bg_color)
				drawSmallText(flag.holderName(hud_data.right_team), module.opts.flag_color[2], x_FlagSectorL, ypos + 20, 2, 1, 1) 
				drawFlag(x_FlagSectorL + module.opts.x_flagPadding, ypos + module.opts.y_flagPadding, holding)
			end
		end
	end
end

return module
