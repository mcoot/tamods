local labels  = {'A','B','C','D','E'}

function cah_capture_points(x, y)
	local points = cah.pointsNum()

	for i=0,points-1 do
		local point_holder = cah.pointHolder(i)
		local color
		local label = cah.pointLabel(i)

		-- Figure out the holder of the point and which color it should have
		if point_holder == 255 then color = rgba(255, 255, 255, 120)
		elseif point_holder == left_team then color = team_colors_bg[left_color]
		else color = team_colors_bg[right_color] end

		drawRect(x + 38 * label + 3, y, x + 35 + 38 * label, y + 32, color)
		drawSmallText(labels[label+1], rgb(0, 0, 0), x + 38 * label + 19, y + 16, 1, 0, 1)
	end
end
