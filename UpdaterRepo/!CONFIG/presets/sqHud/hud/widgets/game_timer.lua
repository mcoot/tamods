sqHud.game_timer = function(x, y)
	-- Draw the game time and it's background
	drawRect(x - 40, y, x + 40, y + 40, sqHud.bg_color1)
	drawUTText(game.timeStr(), sqHud.text_color1, x, y + 20, 1, 1, 1)

	-- Draw a warmup indicator below it
	if game.isWarmUp() then
		drawRect(x - 35, y + 40, x + 35, y + 60, sqHud.bg_color2)
		drawSmallText("WARMUP", sqHud.text_color1, x, y + 50, 1, 1, 1)
	end
end
