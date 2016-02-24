-- Hide the standard crosshair while retaining the hit maker
showCrosshair = false

function crosshairs(x, y)

	-- If the current gun is not ready to fire, draw an indicator around the crosshair
	if not currentWeapon.isReadyToFire() then
		local color = currentWeapon.isReloaded() and text_color3 or text_color1
		drawSmallText("!              !", color, x, y, 1, 1, 1)
	end

	local retIndex = currentWeapon.reticuleIndex()
	-- Uncomment the line below to print the current reticule index to the console
	-- console(retIndex)

	if retIndex == 12 or retIndex == 22 then -- Snipers
		draw2dLine(0, y, x * 2, y, xhair_line_color)
		draw2dLine(x, 0, x, y * 2, xhair_line_color)
		drawRect(x - 2, y - 2, x + 1, y + 1, xhair_color)
	else
		if retIndex == 20 then -- Chain
			drawRect(x - 2, y - 2, x + 3, y + 3, rgb(0, 0, 0))
			drawRect(x - 1, y - 1, x + 2, y + 2, xhair_color)
		else
			-- Left
			drawRect(x - 7, y - 2, x - 2, y + 2, rgb(0, 0, 0))
			drawRect(x - 6, y - 1, x - 3, y + 1, rgb(255, 0, 0))
			-- Right
			drawRect(x + 2, y - 2, x + 7, y + 2, rgb(0, 0, 0))
			drawRect(x + 3, y - 1, x + 6, y + 1, rgb(255, 0, 0))
			-- Top
			drawRect(x - 2, y - 7, x + 2, y - 2, rgb(0, 0, 0))
			drawRect(x - 1, y - 6, x + 1, y - 3, rgb(255, 0, 0))
			-- Bottom
			drawRect(x - 2, y + 2, x + 2, y + 7, rgb(0, 0, 0))
			drawRect(x - 1, y + 3, x + 1, y + 6, rgb(255, 0, 0))
		end

		if retIndex == 16 then -- Mortar, Bolt, GL etc.
			-- Vertical line
			drawRect(x, y + 16, x + 1, y * 2 - 100, xhair_line_color)
		else
			-- Diagonal line
			draw2dLine(x + 15, y + 15, x + y - 100, y * 2 - 100, xhair_line_color)
		end

	end
end
