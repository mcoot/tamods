local outline = rgba(0, 0, 0, 128)

function dot_1x1(x, y, color)
	drawRect(x - 1, y - 1, x + 2, y + 2, outline)
	drawRect(x, y, x + 1, y + 1, color)
end

function dot_2x2(x, y, color)
	drawRect(x - 2, y - 2, x + 2, y + 2, outline)
	drawRect(x - 1, y - 1, x + 1, y + 1, color)
end

function dot_3x3(x, y, color)
	drawRect(x - 2, y - 1, x + 3, y + 2, outline)
	drawRect(x - 1, y - 2, x + 2, y + 3, outline)
	drawRect(x - 1, y - 1, x + 2, y + 2, color)
end

function dot_4x4(x, y, color)
	drawRect(x - 2, y - 2, x + 2, y + 2, outline)
	drawRect(x - 3, y - 1, x + 3, y + 1, outline)
	drawRect(x - 1, y - 3, x + 1, y + 3, outline)
	drawRect(x - 2, y - 1, x + 2, y + 1, color)
	drawRect(x - 1, y - 2, x + 1, y + 2, color)
end
function dot_5x5(x, y, color)
	drawRect(x - 3, y - 2, x + 4, y + 3, outline)
	drawRect(x - 2, y - 3, x + 3, y + 4, outline)
	drawRect(x - 2, y - 1, x + 3, y + 2, color)
	drawRect(x - 1, y - 2, x + 2, y + 3, color)
end
function dot_6x6(x, y, color)
	drawRect(x - 3, y - 3, x + 3, y + 3, outline)
	drawRect(x - 4, y - 1, x + 4, y + 1, outline)
	drawRect(x - 1, y - 4, x + 1, y + 4, outline)
	drawRect(x - 2, y - 2, x + 2, y + 2, color)
	drawRect(x - 3, y - 1, x + 3, y + 1, color)
	drawRect(x - 1, y - 3, x + 1, y + 3, color)
end
function dot_7x7(x, y, color)
	drawRect(x - 3, y - 3, x + 4, y + 4, outline)
	drawRect(x - 4, y - 1, x + 5, y + 2, outline)
	drawRect(x - 1, y - 4, x + 2, y + 5, outline)
	drawRect(x - 2, y - 2, x + 3, y + 3, color)
	drawRect(x - 3, y - 1, x + 4, y + 2, color)
	drawRect(x - 1, y - 3, x + 2, y + 4, color)
end

function cross_1(x, y, color, size, gap_size)
	if gap_size > 0 then
		-- Top
		drawRect(x - 1, y - size - 1, x + 2, y - gap_size + 1, outline)
		drawRect(x,     y - size,     x + 1, y - gap_size,     color)
		-- Right
		drawRect(x + gap_size,     y - 1, x + size + 2, y + 2, outline)
		drawRect(x + gap_size + 1, y,     x + size + 1, y + 1, color)
		-- Bottom
		drawRect(x - 1, y + gap_size,     x + 2, y + size + 2, outline)
		drawRect(x,     y + gap_size + 1, x + 1, y + size + 1, color)
		-- Left
		drawRect(x - size - 1, y - 1, x - gap_size + 1, y + 2, outline)
		drawRect(x - size,     y,     x - gap_size,     y + 1, color)
	else
		drawRect(x - size - 1, y - 1,        x + size + 2, y + 2,        outline)
		drawRect(x - 1,        y - size - 1, x + 2,        y + size + 2, outline)
		drawRect(x - size,     y,            x + size + 1, y + 1,        color)
		drawRect(x,            y - size,     x + 1,        y + size + 1, color)
	end
end

function cross_2(x, y, color, size, gap_size)
	if gap_size > 0 then
		-- Top, Right, Bottom, Left
		drawRect(x - 2, y - size - 1, x + 2, y - gap_size + 1, outline)
		drawRect(x + gap_size - 1, y - 2, x + size + 1, y + 2, outline)
		drawRect(x - 2, y + gap_size - 1, x + 2, y + size + 1, outline)
		drawRect(x - size - 1, y - 2, x - gap_size + 1, y + 2, outline)
		-- Top, Right, Bottom, Left
		drawRect(x - 1, y - size, x + 1, y - gap_size, color)
		drawRect(x + gap_size, y - 1, x + size, y + 1, color)
		drawRect(x - 1, y + gap_size, x + 1, y + size, color)
		drawRect(x - size, y - 1, x - gap_size, y + 1, color)
	else
		drawRect(x - size - 1, y - 2,        x + size + 1, y + 2,        outline)
		drawRect(x - 2,        y - size - 1, x + 2,        y + size + 1, outline)
		drawRect(x - size,     y - 1,        x + size,     y + 1,        color)
		drawRect(x - 1,        y - size,     x + 1,        y + size,     color)
	end
end

function cross_3(x, y, color, size, gap_size)
	if gap_size > 0 then
		-- Top, Right, Bottom, Left
		drawRect(x - 2,        y - size - 1, x + 3,            y - gap_size + 1, outline)
		drawRect(x + gap_size, y - 2,        x + size + 2,     y + 3,            outline)
		drawRect(x - 2,        y + gap_size, x + 3,            y + size + 2,     outline)
		drawRect(x - size - 1, y - 2,        x - gap_size + 1, y + 3,            outline)
		-- Top, Right, Bottom, Left
		drawRect(x - 1,            y - size,         x + 2,        y - gap_size, color)
		drawRect(x + gap_size + 1, y - 1,            x + size + 1, y + 2,        color)
		drawRect(x - 1,            y + gap_size + 1, x + 2,        y + size + 1, color)
		drawRect(x - size,         y - 1,            x - gap_size, y + 2,        color)
	else
		drawRect(x - size - 1, y - 2,        x + size + 2, y + 3,        outline)
		drawRect(x - 2,        y - size - 1, x + 3,        y + size + 2, outline)
		drawRect(x - size,     y - 1,        x + size + 1, y + 2,        color)
		drawRect(x - 1,        y - size,     x + 2,        y + size + 1, color)
	end
end

function xhair_dot(x, y, color, size)
	if size == 1 then
		dot_1x1(x, y, color)
	elseif size == 2 then
		dot_2x2(x, y, color)
	elseif size == 3 then
		dot_3x3(x, y, color)
	elseif size == 4 then
		dot_4x4(x, y, color)
	elseif size == 5 then
		dot_5x5(x, y, color)
	elseif size == 6 then
		dot_6x6(x, y, color)
	else
		dot_7x7(x, y, color)
	end
end

function xhair_cross(x, y, color, size, length, gap_size)
	if size == 1 then
		cross_1(x, y, color, length, gap_size)
	elseif size == 2 then
		cross_2(x, y, color, length, gap_size)
	else
		cross_3(x, y, color, length, gap_size)
	end
end

function xhair_test()
	local color = rgb(255, 255, 255)
	dot_1x1(20, 60, color)
	dot_2x2(30, 60, color)
	dot_3x3(41, 60, color)
	dot_4x4(55, 60, color)
	dot_5x5(70, 60, color)
	dot_6x6(85, 60, color)
	dot_7x7(100, 60, color)
	for i=2,18 do
		cross_1(10 + 3 * i * i, 100, color, i, 0)
		cross_1(10 + 3 * i * i, 150, color, i, i / 2)

		cross_2(10 + 3 * i * i, 200, color, i, 0)
		cross_2(10 + 3 * i * i, 250, color, i, i / 2)

		cross_3(10 + 3 * i * i, 300, color, i, 0)
		cross_3(10 + 3 * i * i, 350, color, i, i / 2)
	end
end
