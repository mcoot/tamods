ubermenu_xhairs = ubermenu_xhairs or {}

function draw_xhairs(res_x, res_y)
	if #ubermenu_xhairs == 0 then return end

	local x = res_x / 2
	local y = res_y / 2

	if #ubermenu_xhairs > 0 then
		local ret = currentWeapon.reticuleIndex()
		local ready = currentWeapon.isReadyToFire()
		local reloading = currentWeapon.isReloading()
		local reloaded = currentWeapon.isReloaded()
		local lowammo = currentWeapon.isLowAmmo()

		for i = 1,#ubermenu_xhairs do
			local item = ubermenu_xhairs[i]
			local show = item.show["all"] or
			           ((item.show["ready"]     and ready) or
			            (item.show["reloading"] and reloading) or
			            (item.show["reloaded"]  and reloaded) or
			            (item.show["lowammo"]   and lowammo))

			if item.show["invert"] then
				show = not show
			end
			-- Only show for the selected reticules and weapon statuses
			if item.show["ret" .. ret] and show then
				if item.type == "cross" then
					xhair_cross(x, y, item.color, item.strength, item.length, item.gap)
				elseif item.type == "dot" then
					xhair_dot(x, y, item.color, item.size)
				elseif item.type == "rect" then
					drawRect(x + item.x, y + item.y, x + item.x + item.width, y + item.y + item.height, item.color)
				elseif item.type == "line" then
					draw2dLine(x + item.x1, y + item.y1, x + item.x2, y + item.y2, item.color)
				end
			end
		end
	end
end

function add_cross(parent, item)
	table.insert(ubermenu_xhairs, { type = "cross", strength = 3, length = 20, gap = 6, color = rgb(255,255,255), show = {} })
	xhairMenu(nil, parent)
end

function add_dot(parent, item)
	table.insert(ubermenu_xhairs, { type = "dot", size = 5, color = rgb(255,255,255), show = {} })
	xhairMenu(nil, parent)
end

function add_rect(parent, item)
	table.insert(ubermenu_xhairs, { type = "rect", height = 250, width = 1, x = 0, y = 80, color = rgb(255,255,255), show = {} })
	xhairMenu(nil, parent)
end

function add_line(parent, item)
	table.insert(ubermenu_xhairs, { type = "line", x1 = 30, y1 = 30, x2 = 300, y2 = 300, color = rgb(255,255,255), show = {} })
	xhairMenu(nil, parent)
end

function add_vis_menu(menu)
	local status = { all       = "All",
	                 ready     = "Ready To Fire",
	                 reloading = "Reloading",
	                 reloaded  = "Reloaded (Reload Canceling)",
	                 lowammo   = "Low Ammo" }

	local rets = {  [0] = "Vehicles",
	                [1] = "Spinfusors",
	                [8] = "Arching Projectile Weapons",
	               [10] = "Shotguns / Flak / EFG",
                   [12] = "Sniper Rifles Unscoped / Targeting Laser",
                   [15] = "Pistols / Shocklance / Knifes",
                   [16] = "Mortars / Grenade Launchers",
                   [17] = "Melee / Belt Items",
                   [20] = "Chainguns",
                   [21] = "BXT-1 Zoom",
                   [22] = "Phase Rifle Zoom",
                   [24] = "Plasma Guns" }

	local sub = menu:add_submenu({ title = "Show for..." })

	for k,v in kpairs(status) do
		local varname = menu.varname:match("(.+)[.][%w]+$") .. ".show." .. k
		if menu:get_var(varname) == nil then
			sub:add_variable({ title = v, varname = varname, value = true, default = true })
		else
			sub:add_variable({ title = v, varname = varname, default = true })
		end
	end

	local varname = menu.varname:match("(.+)[.][%w]+$") .. ".show.invert"
	local desc = "Invert the above selection.\nCan for example be used to only show a crosshair when\nthe current weapon is NOT ready to fire"
	if menu:get_var(varname) == nil then
		sub:add_variable({ title = "Invert", varname = varname, value = false, default = false, description = desc })
	else
		sub:add_variable({ title = "Invert", varname = varname, default = false, description = desc })
	end

	sub:add_separator({})

	for k,v in pairs(rets) do
		local varname = menu.varname:match("(.+)[.][%w]+$") .. ".show.ret" .. k
		if menu:get_var(varname) == nil then
			sub:add_variable({ title = v, varname = varname, value = true, default = true })
		else
			sub:add_variable({ title = v, varname = varname, default = true })
		end
	end
	return sub
end

function reorder_widget(parent, item, up)
	local selected = parent.parent.selected - 5
	local toswitch = 0
	local tmp

	-- Are we already the first or last element, depending on direction
	if up and selected > 1 then
		toswitch = selected - 1
	elseif not up and selected < #ubermenu_xhairs then
		toswitch = selected + 1
	end

	if toswitch > 0 then
		tmp = ubermenu_xhairs[toswitch]
		ubermenu_xhairs[toswitch] = ubermenu_xhairs[selected]
		ubermenu_xhairs[selected] = tmp
		parent:go_parent()
		parent.parent.selected = toswitch + 5
	end
end

function xhairMenu(parent, m)
	m:clear()

	m:add_item({ title = "Add Cross",     func = add_cross })
	m:add_item({ title = "Add Dot",       func = add_dot })
	m:add_item({ title = "Add Rectangle", func = add_rect })
	m:add_item({ title = "Add Line",      func = add_line })
	m:add_separator({})

	for i = 1,#ubermenu_xhairs do
		local sub
		if ubermenu_xhairs[i].type == "cross" then
			sub = m:add_submenu({ title = i .. ". Cross",     varname = "ubermenu_xhairs." .. i .. ".type" })
			sub:add_variable({    title = "Line Strength",    varname = "ubermenu_xhairs." .. i .. ".strength", default = 3,  min = 1, max = 3, inc = 1 })
			sub:add_variable({    title = "Line Length",      varname = "ubermenu_xhairs." .. i .. ".length",   default = 20, min = 1, inc = 1 })
			sub:add_variable({    title = "Inner Gap Size",   varname = "ubermenu_xhairs." .. i .. ".gap",      default = 6,  min = 0, inc = 1 })
			sub:add_color({       title = "Color",            varname = "ubermenu_xhairs." .. i .. ".color",    default = rgb(255,255,255) })
		elseif ubermenu_xhairs[i].type == "dot" then
			sub = m:add_submenu({ title = i .. ". Dot",       varname = "ubermenu_xhairs." .. i .. ".type" })
			sub:add_variable({    title = "Size",             varname = "ubermenu_xhairs." .. i .. ".size",  default = 5, min = 1, max = 7, inc = 1 })
			sub:add_color({       title = "Color",            varname = "ubermenu_xhairs." .. i .. ".color", default = rgb(255,255,255) })
		elseif ubermenu_xhairs[i].type == "rect" then                               
			sub = m:add_submenu({ title = i .. ". Rectangle", varname = "ubermenu_xhairs." .. i .. ".type" })
			sub:add_variable({    title = "Height",           varname = "ubermenu_xhairs." .. i .. ".height", default = 250, min = 1, inc = 1 })
			sub:add_variable({    title = "Width",            varname = "ubermenu_xhairs." .. i .. ".width",  default = 1, min = 1, inc = 1 })
			sub:add_variable({    title = "X-Offset",         varname = "ubermenu_xhairs." .. i .. ".x",      default = 0, inc = 1 })
			sub:add_variable({    title = "Y-Offset",         varname = "ubermenu_xhairs." .. i .. ".y",      default = 80, inc = 1 })
			sub:add_color({       title = "Color",            varname = "ubermenu_xhairs." .. i .. ".color",  default = rgb(255,255,255) })
		elseif ubermenu_xhairs[i].type == "line" then                             
			sub = m:add_submenu({ title = i .. ". Line",      varname = "ubermenu_xhairs." .. i .. ".type" })
			sub:add_variable({    title = "Start X",          varname = "ubermenu_xhairs." .. i .. ".x1",    default = 30,  inc = 1 })
			sub:add_variable({    title = "Start Y",          varname = "ubermenu_xhairs." .. i .. ".y1",    default = 30,  inc = 1 })
			sub:add_variable({    title = "End X",            varname = "ubermenu_xhairs." .. i .. ".x2",    default = 300, inc = 1 })
			sub:add_variable({    title = "End Y",            varname = "ubermenu_xhairs." .. i .. ".y2",    default = 300, inc = 1 })
			sub:add_color({       title = "Color",            varname = "ubermenu_xhairs." .. i .. ".color", default = rgb(255,255,255) })
		end

		-- Set title
		if ubermenu_xhairs[i].name ~= nil and #ubermenu_xhairs[i].name > 0 then
			sub.title = i .. ". " .. ubermenu_xhairs[i].name
		end
		sub:add_variable({ title = "Name", position = 1, varname = "ubermenu_xhairs." .. i .. ".name", default = "" })

		add_vis_menu(sub)
		sub:add_separator({ title = "Order" })
		sub:add_item({ title = "Up",     func = function(parent, item) reorder_widget(parent, item, true) end })
		sub:add_item({ title = "Down",   func = function(parent, item) reorder_widget(parent, item, false) end })
		sub:add_separator({})
		sub:add_item({ title = "Delete", func = function(parent, item)
			-- Get the position in the xhair array from the varname
			table.remove(ubermenu_xhairs, parent.varname:match("[.]([%d]+)"))
			parent:go_parent()
		end })
	end
end

local sub = ubermenu:add_submenu({ title = "Crosshair Maker", func = xhairMenu })
ubermenu:add_draw_func(draw_xhairs)

-- Add items once so they get saved to config when saving without visiting this menu
xhairMenu(ubermenu, sub)
sub = nil
