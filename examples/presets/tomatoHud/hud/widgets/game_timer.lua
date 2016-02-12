function game_timer(x, y)
	-- Draw the game time and it's background
	drawRect(x - 64, y, x + 64, y + 40, bg_color1)
	drawUTText(game.timeStr(), text_color1, x, y + 20, 1, 1, 1)

	-- Draw a warmup indicator below it
	if game.isWarmUp() then
		drawRect(x - 35, y + 40, x + 35, y + 60, bg_color2)
		drawSmallText("WARMUP", text_color1, x, y + 50, 1, 1, 1)
	end
end
