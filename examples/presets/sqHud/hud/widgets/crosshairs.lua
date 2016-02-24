-- Hide the standard crosshair while retaining the hit maker
showCrosshair = false

function crosshairs(x, y)
	local color

	-- If the current gun is not ready to fire, draw an indicator around the crosshair
	if currentWeapon.isReadyToFire() then
		color = xhair_color
	else
		color = rgb(255, 0, 0)
	end

	local retIndex = currentWeapon.reticuleIndex()
	-- Uncomment the line below to print the current reticule index to the console
	--console(retIndex)

	if retIndex == 21 or retIndex == 22 then -- Snipers
		draw2dLine(0, y + 1, x * 2, y + 1, xhair_line_color)
		draw2dLine(x + 1, 0, x + 1, y * 2, xhair_line_color)
		dot_5x5(x, y, color)
	else
		if retIndex == 20 or retIndex == 12 then -- Chain and Sniper no-scope
			dot_5x5(x, y, color)
		else
			cross_3(x, y, color, 6, 2)
		end

		if retIndex == 16 then -- Mortar, Bolt, GL etc.
			-- Long vertical line
			drawRect(x, y + 16, x + 1, y * 2 - 130, xhair_line_color)
		elseif retIndex ~= 1 then
			-- Shorter vertical line
			drawRect(x, y + 16, x + 1, y + 200, xhair_line_color)
		end

	end
end
