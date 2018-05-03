local module = {}

module.name                        = "dodgeScoreboard"  -- This HAS to be the same as the filename minus the trailing .lua
module.opts                        = {}
module.opts.X_Position             = 50.0
module.opts.Y_Position             = 10.0
module.opts.Header_Background      = {}
module.opts.Header_Background[0]   = hud_colors and hud_colors.opts.Team_Background[0] or rgba(255, 23, 23, 150)
module.opts.Header_Background[1]   = hud_colors and hud_colors.opts.Team_Background[1] or rgba(158, 200, 222, 150)
module.opts.Header_Background[255] = rgba(0,0,0,150)
module.opts.Text                   = rgba(255,255,255,255)
module.opts.Text_Our_Name          = rgb(100,255,100)
module.opts.Background             = rgba(0,0,0,110)

local show = false
bindKey("Tab", Input.PRESSED, function() show = true end)
bindKey("Tab", Input.RELEASED, function() show = false end)

function rankToColor(rankToConvert)
	local textcolor = rgb(255,255,255)

	if rankToConvert > 49 then
		textcolor = rgb(0,200,255)
	elseif rankToConvert > 44 then
		textcolor = rgb(0,255,255)
	elseif rankToConvert > 34 then
		textcolor = rgb(125,125,125)
	elseif rankToConvert > 24 then
		textcolor = rgb(255,215,0)
	elseif rankToConvert > 9 then
		textcolor = rgb(205,205,205)
	else
		textcolor = rgb(204,102,0)
	end
	return textcolor
end

function classToColor(classToConvert)
	local textcolor = rgb(255,255,255)

	if classToConvert == "LHT" then
		textcolor = rgb(255,255,255)
	elseif classToConvert == "MED" then
		textcolor = rgb(125,125,125)
	else 
		textcolor = rgb(0,0,0)
	end

	return textcolor
end

function killsToColor(killsToConvert)
	local textcolor = rgb(255,255,255)
	if killsToConvert > 0 then
		if killsToConvert < 50 then
			local val = killsToConvert * 5
			textcolor = rgb(255,255 - val,255 - val)
		else
			textcolor = rgb(255,0,0)
		end
	end
	return textcolor
end

function pingToColor(pingToConvert)
	local textcolor = rgb(255,51,51)
	if pingToConvert < 29 then
		textcolor = rgb(51,255,51)
	elseif pingToConvert < 30 then
		textcolor = rgb(255,255,51)
	elseif pingToConvert < 85 then
		textcolor = rgb(255,285 - pingToConvert,51)
	else
		textcolor = rgb(255,51,51)
	end
	return textcolor
end

function module.draw(res_x, res_y)
	if show then
		local xpos = math.floor(module.opts.X_Position / 100 * res_x)
		local ypos = math.floor(module.opts.Y_Position / 100 * res_y)

		local players = game.players()

		local x_pos = xpos - 606
		local y_pos = ypos
		local textcolor
		local revertcolor

		for j = 0,2 do
			if j == 2 then
				local height = #players[0] > #players[1] and #players[0] or #players[1]

				j = 255
				x_pos = xpos - 203
				y_pos = ypos + 30 + 29 * height
			end

			-- Header, don't show for specs if there are none
			if j ~= 255 or #players[j] > 0 then
				drawRect(x_pos, y_pos, x_pos + 600, y_pos + 24, module.opts.Header_Background[j])
				--drawSmallText("Rank",  module.opts.Text, x_pos + 45,  y_pos + 12, 2, 1, 1)
				drawText("Rank",  module.opts.Text, x_pos + 5, y_pos + 12, 0, 1)
				--drawSmallText("Name",  module.opts.Text, x_pos + 50,  y_pos + 12, 0, 1, 1)
				drawText("Name",  module.opts.Text, x_pos + 60, y_pos + 12, 0, 1)
				--drawSmallText("Class", module.opts.Text, x_pos + 240, y_pos + 12, 0, 1, 1)
				drawText("Class",  module.opts.Text, x_pos + 300, y_pos + 12, 0, 1)
				--drawSmallText("K",     module.opts.Text, x_pos + 290, y_pos + 12, 2, 1, 1)
				drawText("K",  module.opts.Text, x_pos + 380, y_pos + 12, 0, 1)
				--drawSmallText("A",     module.opts.Text, x_pos + 315, y_pos + 12, 2, 1, 1)
				drawText("A",  module.opts.Text, x_pos + 430, y_pos + 12, 0, 1)
				--drawSmallText("Score", module.opts.Text, x_pos + 365, y_pos + 12, 2, 1, 1)
				drawText("Score",  module.opts.Text, x_pos + 470, y_pos + 12, 0, 1)
				--drawSmallText("P",     module.opts.Text, x_pos + 395, y_pos + 12, 2, 1, 1)
				drawText("Ping",  module.opts.Text, x_pos + 555, y_pos + 12, 0, 1)
				y_pos = y_pos + 24
			end

			-- Players
			for i = 1,#players[j] do
				p = players[j][i]


				drawRect(x_pos, y_pos, x_pos + 600, y_pos + 30, module.opts.Background)
				--drawSmallText(p.rank,    textcolor, x_pos + 45,  y_pos + 15, 2, 1, 1)

				textcolor = rankToColor(p.rank)
				drawText(p.rank,  textcolor, x_pos + 5, y_pos + 15, 0, 1)
				
				if hud_data.my_team == j and p.name == hud_data.my_name then
					textcolor = module.opts.Text_Our_Name
				else
					textcolor = module.opts.Text 
				end
				
				--drawSmallText(p.name,    textcolor, x_pos + 50,  y_pos + 15, 0, 1, 1)
				drawText(p.name,  textcolor, x_pos + 60, y_pos + 15, 0, 1)
				--drawSmallText(p.class,   textcolor, x_pos + 240, y_pos + 15, 0, 1, 1)
				textcolor = classToColor(p.class)
				drawText(p.class,  textcolor, x_pos + 300, y_pos + 15, 0, 1)
				textcolor = module.opts.Text 
				--drawSmallText(p.kills,   textcolor, x_pos + 290, y_pos + 15, 2, 1, 1)
				textcolor = killsToColor(p.kills)
				drawText(p.kills,  textcolor, x_pos + 380, y_pos + 15, 0, 1)
				textcolor = module.opts.Text 
				--drawSmallText(p.assists, textcolor, x_pos + 315, y_pos + 15, 2, 1, 1)
				drawText(p.assists,  textcolor, x_pos + 430, y_pos + 15, 0, 1)
				--drawSmallText(p.score,   textcolor, x_pos + 365, y_pos + 15, 2, 1, 1)
				drawText(p.score,  textcolor, x_pos + 470, y_pos + 15, 0, 1)
				textcolor = pingToColor(p.ping)
				--drawSmallText(p.ping,    textcolor, x_pos + 395, y_pos + 15, 2, 1, 1)
				drawText(p.ping,  textcolor, x_pos + 555, y_pos + 15, 0, 1)
				y_pos = y_pos + 29
				if(i == 7) then
					drawRect(x_pos, y_pos, x_pos + 600, y_pos + 1, rgb(0,255,255))
					y_pos = y_pos + 1
				end
			end

			x_pos = xpos + 3
			y_pos = ypos
		end
	end
end

return module
