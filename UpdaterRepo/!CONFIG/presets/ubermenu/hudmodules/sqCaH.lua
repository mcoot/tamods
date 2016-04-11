local module = {}

module.name              = "sqCaH"  -- This HAS to be the same as the filename minus the trailing .lua
module.opts              = {}
module.opts.X_Position   = 13.0
module.opts.Y_Position   = 0.0
module.opts.Text         = rgb(0,0,0)
module.opts.Point_Width  = 38
module.opts.Point_Height = 38
module.opts.Margin       = 3

local labels  = {'A','B','C','D','E'}

function module.draw(res_x, res_y)
	if hud_data.game_type ~= "TrGame_TrCaH" then return end

	local xpos = math.floor(module.opts.X_Position / 100 * res_x)
	local ypos = math.floor(module.opts.Y_Position / 100 * res_y)

	local points = cah.pointsNum()

	for i=0,points-1 do
		local point_holder = cah.pointHolder(i)
		local color
		local label = cah.pointLabel(i)

		x = xpos + (module.opts.Margin + module.opts.Point_Width) * label

		-- Figure out the holder of the point and which color it should have
		if point_holder == 255 then
			color = hud_colors and hud_colors.opts.Team_Background[255] or rgba(255,255,255,120)
		elseif point_holder == hud_data.left_team then
			color = hud_colors and hud_colors.opts.Team_Background[hud_data.left_color] or rgb(0,0,255)
		else
			color = hud_colors and hud_colors.opts.Team_Background[hud_data.right_color] or rgb(255,0,0)
		end

		drawRect(x, ypos, x + module.opts.Point_Width, ypos + module.opts.Point_Height, color)
		drawSmallText(labels[label+1], module.opts.Text, x + module.opts.Point_Width / 2, ypos + module.opts.Point_Height / 2, 1, 0, 1)
	end
end

return module
