local module = {}

module.name                        = "sqScoreboard"  -- This HAS to be the same as the filename minus the trailing .lua
module.opts                        = {}
module.opts.X_Position             = 50.0
module.opts.Y_Position             = 10.0
module.opts.Header_Background      = {}
module.opts.Header_Background[0]   = hud_colors and hud_colors.opts.Team_Background[0] or rgba(255, 23, 23, 150)
module.opts.Header_Background[1]   = hud_colors and hud_colors.opts.Team_Background[1] or rgba(158, 200, 222, 150)
module.opts.Header_Background[255] = rgba(0,0,0,150)
module.opts.Text                   = rgba(255,255,255,255)
module.opts.Text_Our_Name          = rgb(100,255,100)
module.opts.Background             = rgba(0,0,0,110)

local show = false
bindKey("Tab", Input.PRESSED, function() show = true end)
bindKey("Tab", Input.RELEASED, function() show = false end)

function module.draw(res_x, res_y)
	if show then
		local xpos = math.floor(module.opts.X_Position / 100 * res_x)
		local ypos = math.floor(module.opts.Y_Position / 100 * res_y)

		-- Generator status
		if hud_data.game_type == "TrGame_TRCTF" or hud_data.game_type == "TrGame_TrCTFBlitz" then
			-- Left
			if not game.isGenUp(0) then
				local repair_timer = game.genAutoRepairTime(0)
				if repair_timer > 0 then
					-- Display the remaining time until auto repair
					drawSmallText("Gen: " .. repair_timer, module.opts.Header_Background[0], xpos - 3, ypos - 12, 2, 1, 1)
				else
					-- Auto repairing is turned off, just display that the generator is down
					drawSmallText("Gen down", module.opts.Header_Background[0], xpos - 3, ypos - 12, 2, 1, 1)
				end
			end
			-- Right
			if not game.isGenUp(1) then
				local repair_timer = game.genAutoRepairTime(1)
				if repair_timer > 0 then
					-- Display the remaining time until auto repair
					drawSmallText("Gen: " .. repair_timer, module.opts.Header_Background[1], xpos + 403, ypos - 12, 2, 1, 1)
				else
					-- Auto repairing is turned off, just display that the generator is down
					drawSmallText("Gen down", module.opts.Header_Background[1], xpos + 403, ypos - 12, 2, 1, 1)
				end
			end
		end

		local players = game.players()

		local x_pos = xpos - 403
		local y_pos = ypos
		local textcolor

		for j = 0,2 do
			if j == 2 then
				local height = #players[0] > #players[1] and #players[0] or #players[1]

				j = 255
				x_pos = xpos - 203
				y_pos = ypos + 30 + 29 * height
			end

			-- Header, don't show for specs if there are none
			if j ~= 255 or #players[j] > 0 then
				drawRect(x_pos, y_pos, x_pos + 400, y_pos + 24, module.opts.Header_Background[j])
				drawSmallText("Rank",  module.opts.Text, x_pos + 45,  y_pos + 12, 2, 1, 1)
				drawSmallText("Name",  module.opts.Text, x_pos + 50,  y_pos + 12, 0, 1, 1)
				drawSmallText("Class", module.opts.Text, x_pos + 240, y_pos + 12, 0, 1, 1)
				drawSmallText("K",     module.opts.Text, x_pos + 290, y_pos + 12, 2, 1, 1)
				drawSmallText("A",     module.opts.Text, x_pos + 315, y_pos + 12, 2, 1, 1)
				drawSmallText("Score", module.opts.Text, x_pos + 365, y_pos + 12, 2, 1, 1)
				drawSmallText("P",     module.opts.Text, x_pos + 395, y_pos + 12, 2, 1, 1)
				y_pos = y_pos + 24
			end

			-- Players
			for i = 1,#players[j] do
				p = players[j][i]

				if hud_data.my_team == j and p.name == hud_data.my_name then
					textcolor = module.opts.Text_Our_Name
				else
					textcolor = module.opts.Text
				end

				drawRect(x_pos, y_pos, x_pos + 400, y_pos + 30, module.opts.Background)
				drawSmallText(i .. ".",  textcolor, x_pos + 5,   y_pos + 15, 0, 1, 1)
				drawSmallText(p.rank,    textcolor, x_pos + 45,  y_pos + 15, 2, 1, 1)
				drawSmallText(p.name,    textcolor, x_pos + 50,  y_pos + 15, 0, 1, 1)
				drawSmallText(p.class,   textcolor, x_pos + 240, y_pos + 15, 0, 1, 1)
				drawSmallText(p.kills,   textcolor, x_pos + 290, y_pos + 15, 2, 1, 1)
				drawSmallText(p.assists, textcolor, x_pos + 315, y_pos + 15, 2, 1, 1)
				drawSmallText(p.score,   textcolor, x_pos + 365, y_pos + 15, 2, 1, 1)
				drawSmallText(p.ping,    textcolor, x_pos + 395, y_pos + 15, 2, 1, 1)
				y_pos = y_pos + 29
			end

			x_pos = xpos + 3
			y_pos = ypos
		end
	end
end

return module
