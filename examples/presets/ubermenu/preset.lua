require("lib/menu")
require("lib/xhair_factory")
preset = "presets/ubermenu/"

bindKey("F1",                Input.PRESSED,  function() ubermenu:toggle() end)
bindKey("Up",                Input.PRESSED,  function() ubermenu:go_prev() end)
bindKey("Down",              Input.PRESSED,  function() ubermenu:go_next() end)
bindKey("Up",                Input.REPEAT,   function() ubermenu:go_prev() end)
bindKey("Down",              Input.REPEAT,   function() ubermenu:go_next() end)
bindKey("Left",              Input.PRESSED,  function() ubermenu:go_parent() end)
bindKey("Right",             Input.PRESSED,  function() ubermenu:go_enter() end)
bindKey("SpaceBar",          Input.PRESSED,  function() ubermenu:increment_var() end)
bindKey("SpaceBar",          Input.REPEAT,   function() ubermenu:increment_var() end)
bindKey("MouseScrollUp",     Input.PRESSED,  function() ubermenu:increment_var() end)
bindKey("MouseScrollDown",   Input.PRESSED,  function() ubermenu:decrement_var() end)
bindKey("MiddleMouseButton", Input.PRESSED,  function() ubermenu:reset_var() end)

-- Set parameters for menu creation
params = { title = "Ubermenu", config = "config.lua" }

-- Load saved style settings
if ubermenu ~= nil and ubermenu.opts ~= nil then
	for k,v in pairs(ubermenu.opts) do
		params[k] = v
	end
end

-- Create our main menu
ubermenu = menu.create(params)

require(preset .. "menus/xhairs")
require(preset .. "menus/stopwatch")
require(preset .. "menus/routes")
require(preset .. "menus/roammap")
require(preset .. "menus/sc")

gamemenu = ubermenu:add_submenu({ title = "Games" })
require(preset .. "menus/snake")

ubermenu:add_separator({})
local sub = ubermenu:add_submenu({ title = "Menu Settings" })
	local sub1 = sub:add_submenu({ title = "Colors" })
		sub1:add_color({ title = "Item Text",               varname = "ubermenu.opts.fg",        default = ubermenu.opts.fg })
		sub1:add_color({ title = "Item Text (Non Default)", varname = "ubermenu.opts.fg_var",    default = ubermenu.opts.fg_var })
		sub1:add_color({ title = "Item Background",         varname = "ubermenu.opts.bg",        default = ubermenu.opts.bg })
		sub1:add_color({ title = "Selected Text",           varname = "ubermenu.opts.fg_sel",    default = ubermenu.opts.fg_sel })
		sub1:add_color({ title = "Selected Background",     varname = "ubermenu.opts.bg_sel",    default = ubermenu.opts.bg_sel })
		sub1:add_color({ title = "Description Text",        varname = "ubermenu.opts.fg_desc",   default = ubermenu.opts.fg_desc })
		sub1:add_color({ title = "Description Background",  varname = "ubermenu.opts.bg_desc",   default = ubermenu.opts.bg_desc })
		sub1:add_color({ title = "Header Text",             varname = "ubermenu.opts.fg_header", default = ubermenu.opts.fg_header })
		sub1:add_color({ title = "Header Background",       varname = "ubermenu.opts.bg_header", default = ubermenu.opts.bg_header })
		sub1:add_color({ title = "Separator Text",          varname = "ubermenu.opts.fg_sep",    default = ubermenu.opts.fg_sep })

	sub:add_separator({})
	sub:add_variable({ title = "X Position",   varname = "ubermenu.opts.x",            default = ubermenu.opts.x,            inc = 1 })
	sub:add_variable({ title = "Y Position",   varname = "ubermenu.opts.y",            default = ubermenu.opts.y,            inc = 1 })
	sub:add_variable({ title = "Item Width",   varname = "ubermenu.opts.item_width",   default = ubermenu.opts.item_width,   inc = 1, min = 10 })
	sub:add_variable({ title = "Item Height",  varname = "ubermenu.opts.item_height",  default = ubermenu.opts.item_height,  inc = 1, min = 2 })
	sub:add_variable({ title = "Item Padding", varname = "ubermenu.opts.item_padding", default = ubermenu.opts.item_padding, inc = 1 })

require(preset .. "menus/tamods")

ubermenu:add_separator({})
ubermenu:add_submenu({ title = "Presets" })

ubermenu:add_separator({})
ubermenu:add_item({ title = "Reload Settings", func = function() openConsole("/reloadconfig") end })
ubermenu:add_item({ title = "Save Settings", func = function() ubermenu:write_config() end })

ubermenu:add_separator({})
ubermenu:add_exit({ title = "Close" })

-- We don't need the references anymore
sub = nil
sub1 = nil

local onDrawCustomHudOld
if type(onDrawCustomHud) == "function" then
	onDrawCustomHudOld = onDrawCustomHud
end

function onDrawCustomHud(res_x, res_y)
	if onDrawCustomHudOld then onDrawCustomHudOld(res_x, res_y) end
	ubermenu:draw()
end

console("Preset \"ubermenu\" loaded")
