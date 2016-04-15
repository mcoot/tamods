require("lib/menu")
require("lib/kpairs")
require("lib/xhair_factory")
require("lib/geometry")
preset = "presets/ubermenu/"

function file_exists(name)
	local f = io.open(name,"r")
	if f ~= nil then io.close(f) return true else return false end
end

if file_exists(config.getPath() .. preset .. "config/config.lua") then
	require(preset .. "config/config")
end

bindKey("F1",                Input.PRESSED,  function() ubermenu:toggle() end)
bindKey("Up",                Input.PRESSED,  function() ubermenu:go_prev() end)
bindKey("Down",              Input.PRESSED,  function() ubermenu:go_next() end)
bindKey("Up",                Input.REPEAT,   function() ubermenu:go_prev() end)
bindKey("Down",              Input.REPEAT,   function() ubermenu:go_next() end)
bindKey("Left",              Input.PRESSED,  function() ubermenu:go_parent() end)
bindKey("Right",             Input.PRESSED,  function() ubermenu:go_enter() end)
bindKey("MouseScrollUp",     Input.PRESSED,  function() ubermenu:increment_var() end)
bindKey("MouseScrollDown",   Input.PRESSED,  function() ubermenu:decrement_var() end)
bindKey("MiddleMouseButton", Input.PRESSED,  function() ubermenu:reset_var() end)

-- Set parameters for menu creation
params = { title = "Ubermenu", config = preset .. "config/config.lua" }

-- Load saved style settings
if ubermenu ~= nil and ubermenu.opts ~= nil then
	for k,v in pairs(ubermenu.opts) do
		params[k] = v
	end
end

-- Create our main menu
ubermenu = menu.create(params)
params = nil

if ubermenu.opts.help ~= false then
	ubermenu:add_item({ title = "Help", description = "F1: Toggle Menu\n"
	                                               .. "Arrow Keys: Menu navigation\n"
	                                               .. "Mousewheel Up: Increase value\n"
	                                               .. "Mousewheel Down: Decrease value\n"
	                                               .. "Middle Mouse Button: Reset variable to its default value\n \n"
	                                               .. "Pressing Right Arrow Key on a variable will open the\nconsole for setting its value" })
	ubermenu:add_separator({})
end

require(preset .. "menus/xhairs")
require(preset .. "menus/hudmodules")
ubermenu:add_separator({})

require(preset .. "menus/stopwatch")
require(preset .. "menus/routes")
require(preset .. "menus/roammap")
require(preset .. "menus/players")
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
		sub1:add_color({ title = "Header Text",             varname = "ubermenu.opts.fg_header", default = ubermenu.opts.fg_header })
		sub1:add_color({ title = "Header Background",       varname = "ubermenu.opts.bg_header", default = ubermenu.opts.bg_header })
		sub1:add_color({ title = "Separator Text",          varname = "ubermenu.opts.fg_sep",    default = ubermenu.opts.fg_sep })

	sub:add_separator({})
	sub:add_variable({ title = "X Position",           varname = "ubermenu.opts.x",            default = ubermenu.opts.x,            inc = 1 })
	sub:add_variable({ title = "Y Position",           varname = "ubermenu.opts.y",            default = ubermenu.opts.y,            inc = 1 })
	sub:add_variable({ title = "Item Width",           varname = "ubermenu.opts.item_width",   default = ubermenu.opts.item_width,   inc = 1, min = 10 })
	sub:add_variable({ title = "Item Height",          varname = "ubermenu.opts.item_height",  default = ubermenu.opts.item_height,  inc = 1, min = 2 })
	sub:add_variable({ title = "Item Padding",         varname = "ubermenu.opts.item_padding", default = ubermenu.opts.item_padding, inc = 1 })
	local desc = "This is a description text example so you can position\nthe description box"
	sub:add_variable({ title = "Description Offset X", varname = "ubermenu.opts.desc_x",       default = ubermenu.opts.desc_x,       inc = 1, description = desc })
	sub:add_variable({ title = "Description Offset Y", varname = "ubermenu.opts.desc_y",       default = ubermenu.opts.desc_y,       inc = 1, description = desc })
	sub:add_separator({})
	sub:add_variable({ title = "Display Main Menu Help", varname = "ubermenu.opts.help", default = true })

require(preset .. "menus/tamods")
require(preset .. "menus/presets")

ubermenu:add_separator({})
ubermenu:add_item({ title = "Reload Config", func = function() openConsole("/reloadconfig") end })
ubermenu:add_item({ title = "Save Config", func = function() ubermenu:write_config() config.reloadVariables() end })

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
