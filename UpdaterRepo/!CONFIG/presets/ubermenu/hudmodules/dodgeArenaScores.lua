local module = {}

module.name                     = "dodgeArenaScores"  -- This HAS to be the same as the filename minus the trailing .lua
module.opts                     = {}         -- Options, you can add your own here
module.opts.X_Position          = 50      -- Position variables should be screen percentage based
module.opts.Y_Position          = 0
module.opts.Text                = rgba(255,255,255,255)
module.opts.columnWidth         = 25
module.opts.iconWidth           = 26
module.opts.iconHeight          = 20
module.opts.x_iconPadding       = 4
module.opts.y_iconPadding       = 10
module.opts.bg_color            = rgba(0, 0, 0, 125)
module.opts.Enemy_Color         = rgba(255, 23, 23, 255)
module.opts.My_Color            = rgba(158, 200, 222, 255)
module.opts.Enable_Icons        = true

-- The drawing function for this module
function module.draw(res_x, res_y)
	if hud_data.game_type == "TrGame_TrArena" then 
		local xpos = math.floor(module.opts.X_Position / 100 * res_x)
		local ypos = math.floor(module.opts.Y_Position / 100 * res_y)
		local i = 0
		local j = 0
		
		--Logic Variables
		local x_iconArea = module.opts.iconWidth + (module.opts.x_iconPadding * 2)
		local y_iconArea = module.opts.iconHeight + (module.opts.y_iconPadding * 2)
		local x_iconSectorR = xpos + module.opts.columnWidth + 12 + 16 + (5 * 3)
		local x_iconSectorL = xpos - module.opts.columnWidth - 12 - 16 - (5 * 3) - x_iconArea
		
		local myScore = game.score(hud_data.left_team)
		local enemyScore = game.score(hud_data.right_team)
		
		--Draw Enemy Lives
		drawRect(xpos + module.opts.columnWidth, ypos, xpos + module.opts.columnWidth + 12 + 5, ypos + y_iconArea, module.opts.bg_color)
		drawSmallText(arena.roundScore(hud_data.right_team), module.opts.Enemy_Color, xpos + module.opts.columnWidth + 5, ypos + module.opts.iconHeight, 0, 1, 1)

		drawRect(xpos + module.opts.columnWidth + 12 + 5, ypos, xpos + module.opts.columnWidth + 12 + 16 + (5 * 3), ypos + y_iconArea, module.opts.bg_color)
		drawSmallText(enemyScore, module.opts.Enemy_Color, xpos + module.opts.columnWidth + 12 + (5 * 2), ypos + module.opts.iconHeight, 0, 1, 1)
		
		if module.opts.Enable_Icons == true then
			while i < enemyScore do
				drawRect(x_iconSectorR, ypos, x_iconSectorR + x_iconArea, ypos + y_iconArea, module.opts.bg_color)
				drawSkull(x_iconSectorR + module.opts.x_iconPadding, ypos + module.opts.y_iconPadding, module.opts.Enemy_Color)
				i = i + 1
				x_iconSectorR = x_iconSectorR + x_iconArea
				if x_iconSectorR + x_iconArea > res_x then
					i = enemyScore
				end
			end
		end
		--Draw Team Lives
		drawRect(xpos - module.opts.columnWidth - 12 - 5, ypos, xpos - module.opts.columnWidth, ypos + y_iconArea, module.opts.bg_color)
		drawSmallText(arena.roundScore(hud_data.left_team), module.opts.My_Color, xpos - module.opts.columnWidth - 12, ypos + module.opts.iconHeight, 0, 1, 1)

		drawRect(xpos - module.opts.columnWidth - 12 - 16 - (5 * 3), ypos, xpos - module.opts.columnWidth - 12 - 5, ypos + y_iconArea, module.opts.bg_color)
		drawSmallText(myScore, module.opts.My_Color, xpos - module.opts.columnWidth - 12 - 16 - (5 * 2), ypos + module.opts.iconHeight, 0, 1, 1)
		
		if module.opts.Enable_Icons == true then
			while j < myScore do
				drawRect(x_iconSectorL, ypos, x_iconSectorL + x_iconArea, ypos + y_iconArea, module.opts.bg_color)
				drawSkull(x_iconSectorL + module.opts.x_iconPadding, ypos + module.opts.y_iconPadding, module.opts.My_Color)
				j = j + 1
				x_iconSectorL = x_iconSectorL - x_iconArea
				if x_iconSectorL < 0 then
					j = myScore
				end
			end
		end

	end
end

return module
