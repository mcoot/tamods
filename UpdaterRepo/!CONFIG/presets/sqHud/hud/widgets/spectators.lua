function spectators(x, y)
	local spectator_list = game.spectators()

	-- Draw the list only if we actually have spectators
	if spectator_list ~= "" then
		drawText("Specs " .. spectator_list, text_color1, x, y, 1, 1)
	end
end
