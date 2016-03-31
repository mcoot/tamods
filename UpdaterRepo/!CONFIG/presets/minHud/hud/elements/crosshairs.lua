-- Hide the standard crosshair while retaining the hit maker
showCrosshair = false

function cross_dot(x, y, color, outline, size)
	drawRect(x - size/2 - 1, y - size/2 - 1, x + size/2 + 2, y + size/2 + 2, outline)
	drawRect(x - size/2, y - size/2, x + size/2 + 1, y + size/2 + 1, color)
end

function cross_1(x, y, color, outline, size, gap_size)
	if gap_size > 0 then
		-- Top
		drawRect(x - 1, y - size - 1, x + 1, y - gap_size + 1, outline)
		drawRect(x,     y - size,     x, y - gap_size,     color)
		-- Right
		drawRect(x + gap_size,     y - 1, x + size + 2, y + 1, outline)
		drawRect(x + gap_size + 1, y,     x + size + 1, y, color)
		-- Bottom
		drawRect(x - 1, y + gap_size,     x + 1, y + size + 2, outline)
		drawRect(x,     y + gap_size + 1, x, y + size + 1, color)
		-- Left
		drawRect(x - size - 1, y - 1, x - gap_size + 1, y + 1, outline)
		drawRect(x - size,     y,     x - gap_size,     y, color)
	else
		drawRect(x - size - 1, y - 1,        x + size + 2, y + 2,        outline)
		drawRect(x - 1,        y - size - 1, x + 2,        y + size + 2, outline)
		drawRect(x - size,     y,            x + size + 1, y + 1,        color)
		drawRect(x,            y - size,     x + 1,        y + size + 1, color)
	end
end

function cross_1_orig(x, y, color, outline, size, gap_size)
	if gap_size > 0 then
		-- Top
		drawRect(x - 1, y - size - 1, x + 2, y - gap_size + 1, outline)
		drawRect(x,     y - size,     x + 1, y - gap_size,     color)
		-- Right
		drawRect(x + gap_size,     y - 1, x + size + 2, y + 2, outline)
		drawRect(x + gap_size + 1, y,     x + size + 1, y + 1, color)
		-- Bottom
		drawRect(x - 1, y + gap_size,     x + 2, y + size + 2, outline)
		drawRect(x,     y + gap_size + 1, x + 1, y + size + 1, color)
		-- Left
		drawRect(x - size - 1, y - 1, x - gap_size + 1, y + 2, outline)
		drawRect(x - size,     y,     x - gap_size,     y + 1, color)
	else
		drawRect(x - size - 1, y - 1,        x + size + 2, y + 2,        outline)
		drawRect(x - 1,        y - size - 1, x + 2,        y + size + 2, outline)
		drawRect(x - size,     y,            x + size + 1, y + 1,        color)
		drawRect(x,            y - size,     x + 1,        y + size + 1, color)
	end
end

function crosshairs(x, y)
	local colCross = color_xhair
	local colDot = color_xhair
	local colOutline = color_xhair_outline
	
	-- If the current gun is not ready to fire, draw an indicator around the crosshair
	if not currentWeapon.isReadyToFire() then
		local color = currentWeapon.isReloaded() and text_color3 or text_color1
		colDot = color
	end

	local retIndex = currentWeapon.reticuleIndex()
	
	if retIndex == 21 or retIndex == 22 then -- Snipers
		draw2dLine(0, y, x * 2, y, colOutline)
		draw2dLine(x, 0, x, y * 2, colOutline)
		cross_dot(x, y, colDot, colOutline, 1)
	else
		-- Dot
		cross_dot(x, y, colDot, colOutline, 1)
		if retIndex ~= 20 then -- Not chain
			-- Left
			-- drawRect(x - 6, y - 1, x - 3, y + 1, xhair_line_color)
			-- drawRect(x - 6, y - 1, x - 3, y + 1, xhair_color)
			-- -- Right
			-- drawRect(x + 3, y - 1, x + 6, y + 1, xhair_color)
			-- -- Top
			-- drawRect(x - 1, y - 6, x + 1, y - 3, xhair_color)
			-- -- Bottom
			-- drawRect(x - 1, y + 3, x + 1, y + 6, xhair_color)
			--cross_1(x+1, y+1, rgb(0, 255, 0), colCross, 34, 11)
			cross_1_orig(x, y, colCross, colOutline, 34, 11)
		end

		if retIndex == 16 then -- Mortar, Bolt, GL etc.
			-- Vertical line
			--drawRect(x, y + 40, x + 1, y * 2 - 130, colOutline)
		end
	end
end
