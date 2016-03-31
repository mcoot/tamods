local textsize

local function wrap(string, size, linewidth)
	-- Returns a table of wrapped lines

	local lines = {}

	-- Return string as one line if the whole string fits
	if textsize(string, size).x <= linewidth then
		lines[1] = string
		return lines
	end

	-- Split the string into words
	local words = {}
	for w in string:gmatch("%S+") do table.insert(words, w) end

	-- Split words which are longer than a single line
	local j = 1
	while j <= #words do  -- Iterate words
		local width = textsize(words[j], 1).x

		if width > linewidth then
			-- Find where to split the word
			for char = 2,#words[j] do  -- Iterate characters
				if textsize(words[j]:sub(1, char), 1).x > linewidth then
					-- Add the trailing part as a new word after the current one
					table.insert(words, j + 1, words[j]:sub(char))
					-- Remove trailing part from the current word
					words[j] = words[j]:sub(1, char - 1)
					break
				end
			end
		end
		j = j + 1
	end

	local width = 0
	local line = 1

	local i = 1
	while i <= #words do  -- Iterate words
		local w  -- Current word

		if width == 0 then  -- First word of a line?
			-- The first word has to be added without a leading space
			w = words[i]
		else
			w = " " .. words[i]
		end

		local wordwidth = textsize(w, size).x

		-- Check if the current word would fit into the current line
		if width + wordwidth <= linewidth then
			-- It fits, append it to the current line
			if lines[line] then  -- Was this line started already?
				lines[line] = lines[line] .. w
			else
				lines[line] = w
			end
			width = width + wordwidth
			i = i + 1
		else
			-- It doesn't fit, start a new line
			width = 0
			line = line + 1
		end
	end

	return lines
end

function wrapUTText(string, fontsize, linewidth)
	textsize = getUTTextSize
	return wrap(string, fontsize, linewidth)
end

function wrapSmallText(string, fontsize, linewidth)
	textsize = getSmallTextSize
	return wrap(string, fontsize, linewidth)
end

function wrapText(string, fontsize, linewidth)
	textsize = getTextSize
	return wrap(string, fontsize, linewidth)
end
