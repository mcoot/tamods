local module = {}

module.name             		= "mcootSpeedbars"  -- This HAS to be the same as the filename minus the trailing .lua
module.opts            			= {}
module.opts.Y_Position			= 50
module.opts.Width		    	= 45
module.opts.Height				= 258
module.opts.Padding				= 2
module.opts.Fast_Cutoff_Proportion	= 0.8
module.opts.Fast_Color 			= rgba(230,30,30,150)
module.opts.Normal_Color		= rgba(150,200,200,150)
module.opts.Background_Color 	= rgba(0, 0, 0, 125)
module.opts.Box_Color 			= rgba(130,192,145,150)

function drawSpeedbar(x, y, curSpeed, pct, col, boxCol)
	drawRect(x, y, x + module.opts.Width, y + module.opts.Height, module.opts.Background_Color)
	drawBox(x - module.opts.Padding, y - module.opts.Padding, x + module.opts.Width + module.opts.Padding, y + module.opts.Height + module.opts.Padding, boxCol)
	
	local barChunkSize = (module.opts.Height + 3 * module.opts.Padding) / 10
	
	local i = 0.1
	local barLoc = y + module.opts.Height - module.opts.Padding
	while i < pct do
		drawRect(x + module.opts.Padding, math.max(y + module.opts.Padding, barLoc - barChunkSize), x + module.opts.Width - module.opts.Padding, barLoc, col)
		i = i + 0.1
		barLoc = barLoc - barChunkSize - module.opts.Padding
	end
	-- drawProgressBar(x + 4, y + 4, x + module.opts.Width - 4, y + module.opts.Height - 4, col, 0, pct)
	
	textSize = getSmallTextSize(curSpeed, 2)
	
	drawSmallText(curSpeed, col, x + module.opts.Width / 2, y + module.opts.Height + 2 + textSize.y / 2, enums.TEXT_ALIGN_CENTER, 1, 2)
end

function module.draw(res_x, res_y)
	if not hud_data.alive then return end
	if not hud_data.vehicle and not player.isSkiing() then return end

	local xpos = 25
	local yMiddle = math.floor(module.opts.Y_Position / 100 * res_y)
	local ypos = yMiddle - module.opts.Height / 2
	
	local curSpeed = hud_data.vehicle and vehicle.speed() or player.speed()
	local minVal = 50
	local maxVal = 300
	if skiBarMin and skiBarMax then
		minVal = skiBarMin
		maxVal = skiBarMax
	end	
	local pct = math.max(0, math.min(1, (curSpeed - minVal) / (maxVal - minVal)))
	
	local col = pct > module.opts.Fast_Cutoff_Proportion and module.opts.Fast_Color or module.opts.Normal_Color
	local boxCol = pct > module.opts.Fast_Cutoff_Proportion and module.opts.Fast_Color or module.opts.Box_Color
	
	drawSpeedbar(xpos, ypos, curSpeed, pct, col, boxCol)
	drawSpeedbar(res_x - xpos - module.opts.Width, ypos, curSpeed, pct, col, boxCol)
end

return module