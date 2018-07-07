local module = {}

module.name               		= "mcootRabbitScoreboard"  -- This HAS to be the same as the filename minus the trailing .lua
module.opts 					= {}
module.opts.Offset_X  			= 5
module.opts.Offset_Y   			= 5
module.opts.Use_UT_Text			= true
module.opts.Use_Small_Text		= false
module.opts.FirstPlace_Size		= 2
module.opts.SecondPlace_Size	= 1.5
module.opts.ThirdPlace_Size		= 1
module.opts.MyPlace_Size		= 0.8
module.opts.Show_Ranking		= true
module.opts.Ranking_Size		= 2
module.opts.Background			= rgba(0,0,0,125)
module.opts.Box_Padding			= 10
module.opts.Box              	= rgba(130,192,145,150)
module.opts.NameColor 			= rgb(158, 208, 212)
module.opts.SelfColor 			= rgb(255,255,0)

function getAnyTextSize(text, size, xScale, yScale)
	local xs = xScale or 1
	local ys = yScale or 1
	local res= {}
	if module.opts.Use_UT_Text then
		res = getUTTextSizeScaled(text, 2, size / 2)
	elseif module.opts.Use_Small_Text then
		res = getSmallTextSize(text, size)
	else
		res = getTextSize(text, size)
	end
	res.x = res.x * xs
	res.y = res.y * ys
	return res
end

function drawAnyText(text, color, x, y, align, size)
	if module.opts.Use_UT_Text then
		drawUTTextScaled(text, color, x, y, align, 1, 2, size / 2)
	elseif module.opts.Use_Small_Text then
		drawSmallText(text, color, x, y, align, 1, size)
	else
		drawText(text, color, x, y, align, size)
	end
end

function module.draw(res_x, res_y)
	if game.type() ~= "TrGame_TRRabbit" then return end
	
	textSizes = {}
	textSizes[0] = module.opts.FirstPlace_Size
	textSizes[1] = module.opts.SecondPlace_Size
	textSizes[2] = module.opts.ThirdPlace_Size
	textSizes[3] = module.opts.MyPlace_Size
	
	local xPos = math.floor(module.opts.Offset_X / 100 * res_x)
	local yPos = math.floor(module.opts.Offset_Y / 100 * res_y)
	
	local totalBoxSize = {}
	totalBoxSize.x = 0
	totalBoxSize.y = 0
	for i = 0,2 do
		local threeDigitScoreSize = getAnyTextSize("100", textSizes[i], 1.0, 1.1)
		local nameTextSize = getAnyTextSize(rabbit.leaderBoardName(i), textSizes[i], 1.0, 1.1)
		local scoreTextSize = getAnyTextSize(rabbit.leaderBoardScore(i), textSizes[i], 1.0, 1.1)
		totalBoxSize.y = totalBoxSize.y + math.max(nameTextSize.y, scoreTextSize.y)
		totalBoxSize.x = math.max(totalBoxSize.x, nameTextSize.x + math.max(scoreTextSize.x, threeDigitScoreSize.x))
	end
	if true or player.rabbitRank() > 3 then
		local threeDigitScoreSize = getAnyTextSize("100", textSizes[3], 1.0, 1.1)
		local nameTextSize = getAnyTextSize(player.name(), textSizes[3], 1.0, 1.1)
		local scoreTextSize = getAnyTextSize(player.rabbitRank(), textSizes[3], 1.0, 1.1) 
		totalBoxSize.y = totalBoxSize.y + math.max(nameTextSize.y, scoreTextSize.y)
		totalBoxSize.x = math.max(totalBoxSize.x, nameTextSize.x + math.max(scoreTextSize.x, threeDigitScoreSize.x))
	end
	totalBoxSize.x = totalBoxSize.x + 25
	
	local xRightPos = xPos + totalBoxSize.x
	
	-- Draw the leaderboard background
	drawRect(xPos - module.opts.Box_Padding, yPos - (getAnyTextSize(rabbit.leaderBoardName(0), textSizes[0], 1.0, 1.1).y / 2), xPos + totalBoxSize.x + module.opts.Box_Padding, yPos + totalBoxSize.y, module.opts.Background)
	drawBox(xPos - module.opts.Box_Padding, yPos - (getAnyTextSize(rabbit.leaderBoardName(0), textSizes[0], 1.0, 1.1).y / 2), xPos + totalBoxSize.x + module.opts.Box_Padding, yPos + totalBoxSize.y, module.opts.Box)
	
	-- Draw the leaderboard positions
	curYPos = yPos
	for i = 0,2 do
		local nameTextSize = getAnyTextSize(rabbit.leaderBoardName(i), textSizes[i], 1.0, 1.1)
		local scoreTextSize = getAnyTextSize(rabbit.leaderBoardScore(i), textSizes[i], 1.0, 1.1)
		local nameText = rabbit.leaderBoardName(i)
		local scoreText = rabbit.leaderBoardName(i) == "" and "" or rabbit.leaderBoardScore(i)
		local txtColor = rabbit.leaderBoardName(i) == player.name() and module.opts.SelfColor or module.opts.NameColor
		
		drawAnyText(nameText, txtColor, xPos, curYPos, enums.TEXT_ALIGN_LEFT, textSizes[i])
		drawAnyText(scoreText, txtColor, xRightPos, curYPos, enums.TEXT_ALIGN_RIGHT, textSizes[i])
		curYPos = curYPos + (getAnyTextSize("AygT", textSizes[i], 1.0, 1.1).y)
	end
	if player.rabbitRank() > 3 then
		drawAnyText(player.name(), module.opts.SelfColor, xPos, curYPos, enums.TEXT_ALIGN_LEFT, textSizes[3])
		drawAnyText(player.score(), module.opts.SelfColor, xRightPos, curYPos, enums.TEXT_ALIGN_RIGHT, textSizes[3])
		curYPos = curYPos + (getAnyTextSize("AygT", textSizes[3], 1.0, 1.1).y)
	end
	
	-- Draw the current rank
	local curRank = player.rabbitRank() + 1
	if module.opts.Show_Ranking then
		local onesPlace = curRank % 10
		local tensPlace = math.floor(curRank / 10) % 10
		local ordinalSuffix = "th"
		if tensPlace ~= 1 then
			if onesPlace == 1 then ordinalSuffix = "st" end
			if onesPlace == 2 then ordinalSuffix = "nd" end
			if onesPlace == 3 then ordinalSuffix = "rd" end
		end
		local rankNumSize = getAnyTextSize(curRank, module.opts.Ranking_Size, 1.1, 1.1)
		local rankOrdSize = getAnyTextSize(ordinalSuffix, module.opts.Ranking_Size / 2, 1.0, 1.1)
		local totalRankWidth = rankNumSize.x + rankOrdSize.x
		-- Draw rank
		drawAnyText(curRank, module.opts.SelfColor, xPos + totalBoxSize.x / 2 - (totalRankWidth / 2), yPos + totalBoxSize.y + (rankNumSize.y / 2), enums.TEXT_ALIGN_LEFT, module.opts.Ranking_Size)
		drawAnyText(ordinalSuffix, module.opts.SelfColor, xPos + totalBoxSize.x / 2 - (totalRankWidth / 2) + rankNumSize.x, yPos + totalBoxSize.y + (rankNumSize.y / 3), enums.TEXT_ALIGN_LEFT, module.opts.Ranking_Size / 2)
		
	end
end

return module