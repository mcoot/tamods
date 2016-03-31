require(preset .. "hud/variables")
require(preset .. "hud/colors")
require(preset .. "hud/elements/spectators")
require(preset .. "hud/elements/stats")
require(preset .. "hud/elements/crosshairs")
require(preset .. "hud/elements/weapon_list")


-- Toggle HUD bound to Ctrl-O
bindKey("O", Input.PRESSED,
	function(key, event, ctrl, shift, alt)
	   if ctrl and not viewPort.isMainMenuOpen() then
	      show_hud = not show_hud
	   end
	end
)

function onDrawCustomHud(res_x, res_y)
	local borderWidth = 10

	-- Toggle HUD
	if not show_hud or viewPort.isMainMenuOpen() then
		return
	end

	set_variables()
	local center_x = res_x / 2
	local center_y = res_y / 2

	-- Stopwatch
	if stopwatch.isRunning() then
		drawSmallText(stopwatch.timeStr(), text_color1, res_x - 140, 140, 0, 1, 1)
	end

	spectators(center_x, res_y * 0.85)
	stats(res_x - borderWidth, borderWidth)

	-----------------
	-- Player info --
	-----------------
	if player.isAlive() then
		-- Store the relevant data
		local in_vehicle = player.isVehicle()
		local speed = in_vehicle and vehicle.speed() or player.speed()

		crosshairs(center_x, center_y)
		weapon_list(center_x, res_y - borderWidth)
	end
end
