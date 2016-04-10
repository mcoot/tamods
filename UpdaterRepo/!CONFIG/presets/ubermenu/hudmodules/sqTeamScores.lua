local module = {}

module.name            = "sqTeamScores"  -- This HAS to be the same as the filename minus the trailing .lua
module.opts            = {}
module.opts.X_Position = 52.9
module.opts.Y_Position = 0.0
module.opts.Text       = rgb(0,0,0)
module.opts.Width      = 45

function module.draw(res_x, res_y)
	if hud_data.game_type == "TrGame_TRRabbit" then return end

	local xpos = math.floor(module.opts.X_Position / 100 * res_x)
	local ypos = math.floor(module.opts.Y_Position / 100 * res_y)

	-- Left
	drawRect(xpos, ypos, xpos + module.opts.Width, ypos + 20, hud_colors and hud_colors.opts.Team_Background[hud_data.left_color] or rgb(0,0,255))
	drawSmallText(game.score(hud_data.left_team), module.opts.Text, xpos + module.opts.Width / 2, ypos + 10, 1, 0, 1)
	-- Right
	drawRect(xpos, ypos + 20, xpos + module.opts.Width, ypos + 40, hud_colors and hud_colors.opts.Team_Background[hud_data.right_color] or rgb(255,0,0))
	drawSmallText(game.score(hud_data.right_team), module.opts.Text, xpos + module.opts.Width / 2, ypos + 30, 1, 0, 1)
end

return module
