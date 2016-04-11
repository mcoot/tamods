local module = {}

module.name            = "sqArenaRoundScores"  -- This HAS to be the same as the filename minus the trailing .lua
module.opts            = {}
module.opts.X_Position = 56.09
module.opts.Y_Position = 0.0
module.opts.Width      = 25
module.opts.Height     = 20
module.opts.Text       = rgba(255,255,255,255)

function module.draw(res_x, res_y)
	if hud_data.game_type ~= "TrGame_TrArena" then return end

	local xpos = math.floor(module.opts.X_Position / 100 * res_x)
	local ypos = math.floor(module.opts.Y_Position / 100 * res_y)

	-- Left team
	drawRect(xpos,
	         ypos,
	         xpos + module.opts.Width,
	         ypos + module.opts.Height,
	         hud_colors and hud_colors.opts.Team_Background[hud_data.left_color] or rgb(0,0,255)
	)
	drawText(arena.roundScore(hud_data.left_team),
	         hud_colors and hud_colors.opts.Team_Text[hud_data.left_color] or rgb(0,0,255),
	         xpos + module.opts.Width / 2,
	         ypos + module.opts.Height / 2 + 2,
	         1, 1
	)

	ypos = ypos + module.opts.Height

	-- Right team
	drawRect(xpos,
	         ypos,
	         xpos + module.opts.Width,
	         ypos + module.opts.Height,
	         hud_colors and hud_colors.opts.Team_Background[hud_data.right_color] or rgb(255,0,0)
	)
	drawText(arena.roundScore(hud_data.right_team),
	         hud_colors and hud_colors.opts.Team_Text[hud_data.right_color] or rgb(255,0,0),
	         xpos + module.opts.Width / 2,
	         ypos + module.opts.Height / 2 + 2,
	         1, 1
	)
end

return module
