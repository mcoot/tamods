local module = {}

module.name              = "Example"  -- This HAS to be the same as the filename minus the trailing .lua
module.opts              = {}         -- Options, you can add your own here
module.opts.Text_To_Show = "Example"  -- Proper capitalization and underscores make the variable names pretty in the menu
module.opts.X_Position   = 50.0       -- Position variables should be screen percentage based
module.opts.Y_Position   = 25.0
module.opts.Text_Size    = 2
module.opts.Color        = rgba(0,255,0,255)

--[[
	For use in the draw function, frequently used data is available
	in the hud_data table, so it only has to be received once.

	Following variables are available:
	hud_data.game_type
	hud_data.alive
	hud_data.vehicle
	hud_data.my_name
	hud_data.my_team
	hud_data.left_team
	hud_data.left_color
	hud_data.right_team
	hud_data.right_color
]]--

-- The drawing function for this module
function module.draw(res_x, res_y)
	local xpos = math.floor(module.opts.X_Position / 100 * res_x)
	local ypos = math.floor(module.opts.Y_Position / 100 * res_y)

	-- Try to use the global color module and fall back
	-- to our own color option if it isn't loaded
	local color = hud_colors and hud_colors.opts.Team_Text[hud_data.left_color] or module.opts.Color

	drawUTText(module.opts.Text_To_Show, color, xpos, ypos, 1, 1, module.opts.Text_Size)
end

return module
