local module = {}

module.name            = "sqRespawnTime"  -- This HAS to be the same as the filename minus the trailing .lua
module.opts            = {}
module.opts.X_Position = 50.0
module.opts.Y_Position = 91.0
module.opts.Text       = rgba(255,255,255,255)

function module.draw(res_x, res_y)
	if hud_data.alive then return end

	local xpos = math.floor(module.opts.X_Position / 100 * res_x)
	local ypos = math.floor(module.opts.Y_Position / 100 * res_y)
	local time = player.respawnTime()

	if time > 0 then
		drawUTText(time, module.opts.Text, xpos, ypos, 1, 1, 1)
	end
end

return module
