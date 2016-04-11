local module = {}

module.name            = "sqArenaLastLive"  -- This HAS to be the same as the filename minus the trailing .lua
module.opts            = {}
module.opts.X_Position = 50.0
module.opts.Y_Position = 24.0
module.opts.String     = "Last live!"
module.opts.Text       = rgba(0,255,255,255)
module.opts.Background = rgba(0,0,0,120)

function module.draw(res_x, res_y)
	if hud_data.game_type ~= "TrGame_TrArena" then return end

	-- Draw a warning message if we have no respawns left
	if hud_data.my_team ~= 255 and not game.isWarmUp() and hud_data.alive and player.arenaSpawnsLeft() < 1 then
		local xpos = math.floor(module.opts.X_Position / 100 * res_x)
		local ypos = math.floor(module.opts.Y_Position / 100 * res_y)

		local size = getSmallTextSize(module.opts.String, 1).x / 2 + 8
		drawRect(xpos - size, ypos, xpos + size, ypos + 26, module.opts.Background)
		drawSmallText(module.opts.String, module.opts.Text, xpos, ypos + 13, 1, 1, 1)
	end
end

return module
