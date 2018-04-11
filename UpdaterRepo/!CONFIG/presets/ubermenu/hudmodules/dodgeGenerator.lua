local module = {}

module.name                      = "dodgeGenerator"  -- This HAS to be the same as the filename minus the trailing .lua
module.opts                      = {}         -- Options, you can add your own here
module.opts.X_Position           = 50      -- Position variables should be screen percentage based
module.opts.Y_Position           = 0
module.opts.Text                 = rgba(255,255,255,255)
module.opts.columnWidth          = 25
module.opts.x_genPadding         = 5
module.opts.y_genPadding         = 13
module.opts.x_generatorSize      = 20
module.opts.y_generatorSize      = 14
module.opts.bg_color             = rgba(0, 0, 0, 125)
module.opts.My_Gen_Color         = rgba(158, 200, 222, 255)
module.opts.My_Gen_Color_Down    = rgba(158, 200, 222, 75)
module.opts.Enemy_Gen_Color      = rgba(255, 23, 23, 255)
module.opts.Enemy_Gen_Color_Down = rgba(255, 23, 23, 75)


-- The drawing function for this module
function module.draw(res_x, res_y)
	if hud_data.game_type == "TrGame_TRCTF" or hud_data.game_type == "TrGame_TrCTFBlitz" or hud_data.game_type == "TrGame_TRTeamRabbit" then
		local xpos = math.floor(module.opts.X_Position / 100 * res_x)
		local ypos = math.floor(module.opts.Y_Position / 100 * res_y)
		drawRect(xpos - module.opts.columnWidth - module.opts.x_generatorSize - module.opts.x_genPadding - module.opts.x_genPadding, ypos, xpos - module.opts.columnWidth, ypos + module.opts.y_generatorSize + (module.opts.y_genPadding * 2), module.opts.bg_color)
		drawRect(xpos + module.opts.columnWidth, ypos, xpos + module.opts.columnWidth + module.opts.x_generatorSize + (module.opts.x_genPadding * 2), ypos + module.opts.y_generatorSize + (module.opts.y_genPadding * 2), module.opts.bg_color)
			
		-- Left
		if not game.isGenUp(hud_data.left_team) then
			local repair_timer = game.genAutoRepairTime(hud_data.left_team)
			
			if repair_timer > 0 then
				-- Display the remaining time until auto repair
				drawGenerator(xpos - module.opts.columnWidth - module.opts.x_generatorSize - module.opts.x_genPadding, ypos + module.opts.y_genPadding - 1, module.opts.My_Gen_Color_Down)
				drawUTText(repair_timer, hud_colors.opts.Team_Text[1], xpos - 40, ypos + 20, 1, 1, 0.5)
			else
				-- Auto repairing is turned off, just display that the generator is down
				drawGenerator(xpos - module.opts.columnWidth - module.opts.x_generatorSize - module.opts.x_genPadding, ypos + module.opts.y_genPadding - 1, module.opts.My_Gen_Color_Down)
			end
		else
			drawGenerator(xpos - module.opts.columnWidth - module.opts.x_generatorSize - module.opts.x_genPadding, ypos + module.opts.y_genPadding - 1, module.opts.My_Gen_Color)
		end
		-- Right
		if not game.isGenUp(hud_data.right_team) then
			local repair_timer = game.genAutoRepairTime(hud_data.right_team)
			
			if repair_timer > 0 then
				-- Display the remaining time until auto repair
				drawGenerator(xpos + module.opts.columnWidth + module.opts.x_genPadding, ypos + module.opts.y_genPadding - 1, module.opts.Enemy_Gen_Color_Down)
				drawUTText(repair_timer, hud_colors.opts.Team_Text[0], xpos + 40, ypos + 20, 1, 1, 0.5)
			else
				-- Auto repairing is turned off, just display that the generator is down
				drawGenerator(xpos + module.opts.columnWidth + module.opts.x_genPadding, ypos + module.opts.y_genPadding - 1, module.opts.Enemy_Gen_Color_Down)
			end
		
		else
			drawGenerator(xpos + module.opts.columnWidth + module.opts.x_genPadding, ypos + module.opts.y_genPadding - 1, module.opts.Enemy_Gen_Color)
		end
	end
end

return module
