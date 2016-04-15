ubermenu_hudmodules = ubermenu_hudmodules or {}

hudmodules_path = (config.getPath() .. preset .. "/hudmodules/"):gsub("\\", "/")

-- Get a list of all available modules
local hudmodules_avail = {}

for i,v in ipairs(config.getFileList(preset .. "hudmodules")) do
	if v ~= "." and v ~= ".." then
		table.insert(hudmodules_avail, v)
	end
end

-- Load saved modules
for i = 1,#ubermenu_hudmodules do
	local module = dofile(hudmodules_path .. ubermenu_hudmodules[i].name .. ".lua")

	if type(module.opts) == "table" then
		-- Use variables from the config, but only if the module still has those variables
		for k,v in pairs(ubermenu_hudmodules[i].opts) do
			if module.opts[k] ~= nil then
				if type(v) == "table" then
					-- Nested tables
					for j = 1,#v do
						if module.opts[k][j] ~= nil then
							module.opts[k][j] = v[j]
						end
					end
				else
					-- Use values from config
					module.opts[k] = v
				end
			end
		end
	else
		module.opts = {}
	end

	ubermenu_hudmodules[i] = module
end

function draw_modules(res_x, res_y)
	hud_data             = {}
	hud_data.game_type   = game.type()
	hud_data.alive       = player.isAlive()
	hud_data.vehicle     = player.isVehicle()
	hud_data.my_name     = player.name()
	hud_data.my_team     = player.teamNum()
	hud_data.left_team   = hud_data.my_team == 1 and 1 or 0
	hud_data.left_color  = hud_data.my_team == 255 and 0 or 1
	hud_data.right_team  = 1 - hud_data.left_team
	hud_data.right_color = 1 - hud_data.left_color

	for i = 1,#ubermenu_hudmodules do
		if ubermenu_hudmodules[i].draw then
			ubermenu_hudmodules[i].draw(res_x, res_y)
		end
	end
end

function add_module(parent, item)
	table.insert(ubermenu_hudmodules, dofile(hudmodules_path .. item.title))
	hudMenu(nil, parent.parent)
	parent:go_parent()
end

function reorder_module(parent, item, up)
	local selected = parent.parent.selected - 2
	local toswitch = 0
	local tmp

	-- Are we already the first or last element, depending on direction
	if up and selected > 1 then
		toswitch = selected - 1
	elseif not up and selected < #ubermenu_hudmodules then
		toswitch = selected + 1
	end

	if toswitch > 0 then
		tmp = ubermenu_hudmodules[toswitch]
		ubermenu_hudmodules[toswitch] = ubermenu_hudmodules[selected]
		ubermenu_hudmodules[selected] = tmp
		parent:go_parent()
		parent.parent.selected = toswitch + 2
	end
end

function hudMenu(parent, m)
	m:clear()

	local sub = m:add_submenu({ title = "Add Module" })
	for i = 1,#hudmodules_avail do
		sub:add_item({ title = hudmodules_avail[i], func = add_module })
	end

	m:add_separator({})

	for i = 1,#ubermenu_hudmodules do
		sub = m:add_submenu({ title = i .. ". " .. ubermenu_hudmodules[i].name, varname = "ubermenu_hudmodules." .. i .. ".name" })
		local colors

		for k,v in kpairs(ubermenu_hudmodules[i].opts) do
			local title = tostring(k):gsub("_", " ")
			local varname = "ubermenu_hudmodules." .. i .. ".opts." .. k

			if type(v) == "table" then
				for k2,v2 in kpairs(v) do
					local title = (tostring(k) .. " " .. tostring(k2)):gsub("_", " ")

					if type(v2) == "userdata" then
						if not colors then colors = sub:add_submenu({ title = "Colors", position = 1 }) end
						colors:add_color({ title = title, varname = varname .. "." .. k2, default = v2 })
					elseif type(v2) == "number" then
						sub:add_variable({ title = title, varname = varname .. "." .. k2, default = v2, inc = 1 })
					else
						sub:add_variable({ title = title, varname = varname .. "." .. k2, default = v2 })
					end
				end
			elseif type(v) == "userdata" then
				if not colors then colors = sub:add_submenu({ title = "Colors", position = 1 }) end
				colors:add_color({ title = title, varname = varname, default = v })
			elseif type(v) == "number" then
				sub:add_variable({ title = title, varname = varname, default = v, inc = 1 })
			else
				sub:add_variable({ title = title, varname = varname, default = v })
			end
		end

		sub:add_separator({ title = "Order" })
		sub:add_item({ title = "Up",     func = function(parent, item) reorder_module(parent, item, true) end })
		sub:add_item({ title = "Down",   func = function(parent, item) reorder_module(parent, item, false) end })
		sub:add_separator({})
		sub:add_item({ title = "Delete", func = function(parent, item)
			-- Get the position in the xhair array from the varname
			local pos = tonumber(parent.varname:match("[.]([%d]+)[.]name"))
			-- Remove from loaded modules table
			table.remove(ubermenu_hudmodules, pos)
			parent:go_parent()
		end })
	end
end

local sub = ubermenu:add_submenu({ title = "HUD Maker", func = hudMenu })
ubermenu:add_draw_func(draw_modules)

-- Add items once so they get saved to config when saving without visiting this menu
hudMenu(ubermenu, sub)
sub = nil
