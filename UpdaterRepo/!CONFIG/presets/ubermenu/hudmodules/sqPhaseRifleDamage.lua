local module = {}

module.name            = "sqPhaseRifleDamage"  -- This HAS to be the same as the filename minus the trailing .lua
module.opts            = {}
module.opts.X_Position = 49.0
module.opts.Y_Position = 60.0
module.opts.Text       = rgba(255,255,255,255)

function module.draw(res_x, res_y)
	if not hud_data.alive then return end

	if currentWeapon.name() == "Phase Rifle" then
		local xpos = math.floor(module.opts.X_Position / 100 * res_x)
		local ypos = math.floor(module.opts.Y_Position / 100 * res_y)

		drawSmallText(math.ceil(player.energy() * 5.333), module.opts.Text, xpos, ypos, 2, 1, 1)
	end
end

return module
