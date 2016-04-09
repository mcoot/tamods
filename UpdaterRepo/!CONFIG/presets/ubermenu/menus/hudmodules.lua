ubermenu_hudmodules = ubermenu_hudmodules or {}

hudmodules_path = (config.getPath() .. preset .. "/hudmodules/"):gsub("\\", "/")

-- Get a list of all available modules
local hudmodules_avail = {}
for m in io.popen("dir \"" .. hudmodules_path .. "\\*.lua\" /b"):lines() do
	table.insert(hudmodules_avail, m)
end

-- Load saved modules
for i = 1,#ubermenu_hudmodules do
	local module = dofile(hudmodules_path .. ubermenu_hudmodules[i].name .. ".lua")
	module.opts = ubermenu_hudmodules[i].opts
	ubermenu_hudmodules[i] = module
end

function draw_widgets(res_x, res_y)
	hud_data             = {}
	hud_data.game_type   = game.type()
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

function add_widget(parent, item)
	table.insert(ubermenu_hudmodules, dofile(hudmodules_path .. item.title))
	hudMenu(nil, parent.parent)
end

function hudMenu(parent, m)
	m:clear()

	local sub = m:add_submenu({ title = "Add Module" })
		for i = 1,#hudmodules_avail do
			sub:add_item({ title = hudmodules_avail[i], func = add_widget })
		end

	m:add_separator({})

	for i = 1,#ubermenu_hudmodules do
		sub = m:add_submenu({ title = i .. ". " .. ubermenu_hudmodules[i].name, varname = "ubermenu_hudmodules." .. i .. ".name" })
		for k,v in kpairs(ubermenu_hudmodules[i].opts) do
			local title = tostring(k):gsub("_", " ")
			local varname = "ubermenu_hudmodules." .. i .. ".opts." .. k

			if type(v) == "table" then
				for k2,v2 in kpairs(v) do
					local title = (tostring(k) .. " " .. tostring(k2)):gsub("_", " ")

					if type(v2) == "userdata" then
						sub:add_color({    title = title, varname = varname .. "." .. k2, default = v2 })
					elseif type(v2) == "number" then
						sub:add_variable({ title = title, varname = varname .. "." .. k2, default = v2, inc = 1 })
					else
						sub:add_variable({ title = title, varname = varname .. "." .. k2, default = v2 })
					end
				end
			elseif type(v) == "userdata" then
				sub:add_color({    title = title, varname = varname, default = v })
			elseif type(v) == "number" then
				sub:add_variable({ title = title, varname = varname, default = v, inc = 1 })
			else
				sub:add_variable({ title = title, varname = varname, default = v })
			end
		end

		sub:add_separator({})
		sub:add_item({ title = "Delete", func = function(parent, item)
			-- Get the position in the xhair array from the varname
			local pos = tonumber(parent.varname:match("[.]([%d]+)[.]name"))
			-- Remove from loaded widgets table
			table.remove(ubermenu_hudmodules, pos)
			parent:go_parent()
		end })
	end
end

local sub = ubermenu:add_submenu({ title = "HUD Maker", func = hudMenu })
ubermenu:add_draw_func(draw_widgets)

-- Add items once so they get saved to config when saving without visiting this menu
hudMenu(ubermenu, sub)
sub = nil