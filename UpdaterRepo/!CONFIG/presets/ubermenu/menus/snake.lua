snake_opts = snake_opts or {}
snake_opts.boardx = snake_opts.boardx or 410
snake_opts.boardy = snake_opts.boardy or 130
snake_opts.boardsz = snake_opts.boardsz or 20
snake_opts.blocksz = snake_opts.blocksz or 10
snake_opts.speed = snake_opts.speed or 15  -- Blocks per second
snake_opts.playercol = snake_opts.playercol or rgba(100,255,90,255)
snake_opts.fruitcol = snake_opts.fruitcol or rgba(255,60,30,220)
snake_opts.boardcol = snake_opts.boardcol or rgba(0,0,0,135)

local snake_active = false
local snake_boardsz
local snake_x, snake_y
local snake_dir         -- 0 Right, 1 Down, 2 Left, 3 Up
local snake_dir_next
local snake_counter
local snake_speed       -- Blocks per second
local snake_lastupdate
local snake_fruitpos
local snake_paused
 
local snake_body = {}
local snake_dirlist = {     -- snake_dir + 1
	{x = 1, y = 0},
	{x = 0, y = 1},
	{x = -1, y = 0},
	{x = 0, y = -1}
}

function snakeStart()
	if not snake_active then
		bindKey("W", Input.PRESSED, function() snake_dir_next = 3 snake_paused = false end)
		bindKey("S", Input.PRESSED, function() snake_dir_next = 1 snake_paused = false end)
		bindKey("A", Input.PRESSED, function() snake_dir_next = 2 snake_paused = false end)
		bindKey("D", Input.PRESSED, function() snake_dir_next = 0 snake_paused = false end)
		snake_active = true
	end

	snake_paused = true
	snake_boardsz = snake_opts.boardsz
	snake_x = math.floor(snake_boardsz / 2)
	snake_y = math.floor(snake_boardsz / 2)
	snake_dir = math.random(0,3)
	snake_dir_next = snake_dir
	snake_body = {{x = snake_x, y = snake_y}}
	snake_counter = 0
	snake_speed = snake_opts.speed
	snake_lastupdate = 0
	snake_fruitpos = {x = math.random(snake_boardsz) - 1,
	                  y = math.random(snake_boardsz) - 1}
end

function snakeStop()
	if not snake_active then return end
	snake_active = false

	unbindKey("W", Input.PRESSED)
	unbindKey("S", Input.PRESSED)
	unbindKey("A", Input.PRESSED)
	unbindKey("D", Input.PRESSED)
end

local function snakeDrawBlock(x, y, col)
	x = snake_opts.boardx + x * snake_opts.blocksz
	y = snake_opts.boardy + y * snake_opts.blocksz
	drawRect(x, y, x + snake_opts.blocksz, y + snake_opts.blocksz, col)
end

local function snakeGameOver()
	print(string.format("Game over. You reached a score of %d", #snake_body))
	notify("Snake", string.format("Game over. You reached a score of %d", #snake_body))
	snakeStart()
end

local function snake()
	if not snake_active then return end

	local x = snake_opts.boardx
	local y = snake_opts.boardy
	local sz = snake_boardsz * snake_opts.blocksz
	drawRect(x, y, x + sz, y + sz, snake_opts.boardcol)

	local currTime = game.realTimeSeconds()
	if not snake_paused and currTime - snake_lastupdate > 1.0 / snake_speed then
		local head = snake_body[#snake_body]
		local next_dir = snake_dir_next
		if snake_dir - next_dir ~= -2 and snake_dir - next_dir ~= 2 then
			snake_dir = next_dir
		end
		local dir = snake_dirlist[snake_dir + 1]
		local newpos = {x = head.x + dir.x, y = head.y + dir.y}
		if (newpos.x < 0 or newpos.x >= snake_boardsz or
			newpos.y < 0 or newpos.y >= snake_boardsz) then
			snakeGameOver()
			return
		end
		for idx, pos in pairs(snake_body) do
			if newpos.x == pos.x and newpos.y == pos.y then
				snakeGameOver()
				return
			end
		end

		table.insert(snake_body, newpos)
		if newpos.x == snake_fruitpos.x and newpos.y == snake_fruitpos.y then
			snake_fruitpos = {x = math.random(snake_boardsz) - 1,
			y = math.random(snake_boardsz) - 1}
		else
			table.remove(snake_body, 1)
		end
		snake_lastupdate = currTime
	end

	for idx, pos in pairs(snake_body) do
		snakeDrawBlock(pos.x, pos.y, snake_opts.playercol)
	end
	snakeDrawBlock(snake_fruitpos.x, snake_fruitpos.y, snake_opts.fruitcol)
end

local sub = gamemenu:add_submenu({ title = "Snake" })
	sub:add_item({ title = "Start", func = snakeStart, description = "Use WASD to begin a game and change direction" })
	sub:add_item({ title = "Stop", func = snakeStop })
	sub:add_separator({})
	sub:add_variable({  title = "X Position", varname = "snake_opts.boardx",    default = 400, inc = 1 })
	sub:add_variable({  title = "Y Position", varname = "snake_opts.boardy",    default = 300, inc = 1 })
	sub:add_variable({  title = "Board Size", varname = "snake_opts.boardsz",   default = 20,  inc = 1, min = 2 })
	sub:add_variable({  title = "Block Size", varname = "snake_opts.blocksz",   default = 10,  inc = 1, min = 1 })
	sub:add_variable({  title = "Game Speed", varname = "snake_opts.speed",     default = 15,  inc = 1, min = 1, max = 50 })
	sub:add_separator({ title = "Colors" })
	sub:add_color({     title = "Snake",      varname = "snake_opts.playercol", default = rgba(100,255,90,255) })
	sub:add_color({     title = "Fruit",      varname = "snake_opts.fruitcol",  default = rgba(255,60,30,220) })
	sub:add_color({     title = "Background", varname = "snake_opts.boardcol",  default = rgba(0,0,0,135) })

ubermenu:add_draw_func(snake)

sub = nil
