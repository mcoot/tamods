function kda_ping(x, y)
	drawSmallText(player.kills() .. "/" .. player.deaths() .. "/" .. player.assists() .. " - " .. player.ping() .. " ms", text_color1, x, y, 0, 1, 1)
end
