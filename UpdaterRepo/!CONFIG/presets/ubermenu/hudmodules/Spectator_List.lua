local module = {}

module.name              	= "Spectator_List"
module.opts              	= {}
module.opts.X_Position		= 50.0
module.opts.Y_Position		= 85.0
module.opts.Color			= rgb(255, 255, 255)

function module.draw(res_x, res_y)
	local x = math.floor(module.opts.X_Position / 100 * res_x)
	local y = math.floor(module.opts.Y_Position / 100 * res_y)

	local color = hud_colors and hud_colors.opts.Team_Text[hud_data.left_color] or module.opts.Color
	
	if viewPort.isScoreboardOpen() then
		local spectator_list = game.spectators()

		-- Draw the list only if we actually have spectators
		if spectator_list == "" then
			drawText("No Spectators", color, x, y, 1, 1)
		else
			drawText("Specs " .. spectator_list, color, x, y, 1, 1)
		end
	end
end

return module
