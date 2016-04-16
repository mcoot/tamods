function drawFlag(x, y, c)
	drawRect(x + 4, y - 2, x + 6, y + 20, c)
	
	drawRect(x + 8, y, x + 10, y + 2, c)
	drawRect(x, y, x + 2, y + 2, c)
	
	drawRect(x + 9, y + 2, x + 10, y + 10, c)
	drawRect(x, y + 2, x + 1, y + 10, c)
	
	drawRect(x + 6, y, x + 8, y + 10, c)
	drawRect(x + 2, y, x + 4, y + 10, c)
end

function drawGenerator(x, y, c)
	drawRect(x + 4, y, x + 15, y + 2, c)
	drawRect(x + 5, y + 13, x + 15, y + 14, c)
	--Bolt
	drawRect(x + 5, y + 2, x + 8, y + 3, c)
	drawRect(x + 12, y + 2, x + 15, y + 3, c)
	
	drawRect(x + 5, y + 3, x + 7, y + 4, c)
	drawRect(x + 11, y + 3, x + 15, y + 4, c)
	
	drawRect(x + 5, y + 4, x + 6, y + 5, c)
	drawRect(x + 10, y + 4, x + 15, y + 5, c)
	
	drawRect(x + 5, y + 8, x + 9, y + 9, c)
	
	drawRect(x + 5, y + 9, x + 9, y + 10, c)
	drawRect(x + 14, y + 9, x + 15, y + 10, c)
	
	drawRect(x + 5, y + 10, x + 8, y + 11, c)
	drawRect(x + 13, y + 10, x + 15, y + 11, c)
	
	drawRect(x + 5, y + 11, x + 8, y + 12, c)
	drawRect(x + 11, y + 11, x + 15, y + 12, c)
	
	drawRect(x + 5, y + 12, x + 7, y + 13, c)
	drawRect(x + 10, y + 12, x + 15, y + 13, c)
	
	--Left Buffer
	drawRect(x + 3, y + 4, x + 5, y + 14, c)
	--Right Buffer
	drawRect(x + 15, y + 4, x + 17, y + 14, c)
	
	
	--Left Curve
	drawRect(x + 3, y, x + 4, y + 1, c)
	drawRect(x + 2, y + 1, x + 4, y + 2, c)
	drawRect(x + 1, y + 2, x + 5, y + 4, c)
	--Right Curve
	drawRect(x + 15, y, x + 17, y + 1, c)
	drawRect(x + 15, y + 1, x + 18, y + 2, c)
	drawRect(x + 15, y + 2, x + 19, y + 4, c)
	
	--Left Fin
	drawRect(x, y + 4, x + 3, y + 6, c)
	drawRect(x, y + 8, x + 3, y + 10, c)
	drawRect(x, y + 12, x + 3, y + 14, c)
	
	--Right Fin
	drawRect(x + 17, y + 4, x + 20, y + 6, c)
	drawRect(x + 17, y + 8, x + 20, y + 10, c)
	drawRect(x + 17, y + 12, x + 20, y + 14, c)
end
	
function drawSkull(x, y, c)
	--Ya Face
	drawRect(x, y + 2, x + 4, y + 4, c)
	drawRect(x, y + 16, x + 4, y + 18, c)
	
	drawRect(x + 2, y, x + 4, y + 2, c)
	drawRect(x + 2, y + 18, x + 4, y + 20, c)
	
	drawRect(x + 4, y + 4, x + 6, y + 6, c)
	drawRect(x + 4, y + 14, x + 6, y + 16, c)
	
	drawRect(x + 6, y + 6, x + 8, y + 14, c)
	
	drawRect(x + 8, y + 4, x + 10, y + 8, c)
	drawRect(x + 8, y + 12, x + 10, y + 18, c)
	
	drawRect(x + 10, y + 4, x + 12, y + 8, c)
	drawRect(x + 10, y + 10, x + 12, y + 16, c)
	--Center
	drawRect(x + 12, y + 4, x + 14, y + 12, c)
	drawRect(x + 12, y + 14, x + 14, y + 18, c)
	--Center
	drawRect(x + 14, y + 4, x + 16, y + 8, c)
	drawRect(x + 14, y + 10, x + 16, y + 16, c)
	
	drawRect(x + 16, y + 4, x + 18, y + 8, c)
	drawRect(x + 16, y + 12, x + 18, y + 18, c)
	
	drawRect(x + 18, y + 6, x + 20, y + 14, c)
	
	drawRect(x + 20, y + 4, x + 22, y + 6, c)
	drawRect(x + 20, y + 14, x + 22, y + 16, c)
	
	drawRect(x + 22, y + 2, x + 26, y + 4, c)
	drawRect(x + 22, y + 16, x + 26, y + 18, c)
	
	drawRect(x + 22, y, x + 24, y + 2, c)
	drawRect(x + 22, y + 18, x + 24, y + 20, c)
end	