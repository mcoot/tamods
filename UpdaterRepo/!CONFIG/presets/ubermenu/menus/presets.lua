local preset = preset

if file_exists(config.getPath() .. preset .. "config/presets.lua") then
	require(preset .. "config/presets")
end

local presets = {}

local function generateList()
	presets = {}

	-- Get a list of all available and already loaded presets
	for i,v in ipairs(config.getFileList("presets")) do
		if v ~= "." and v ~= ".." then
			if package.loaded["presets/" .. v .. "/preset"] ~= nil then
				presets[v] = true
			else
				presets[v] = false
			end
		end
	end

	-- Don't list ourselves
	presets.ubermenu = nil
end

generateList()

function savePresetConfig()
	local path = config.getPath() .. preset .. "config/presets.lua"
	local cfg = io.open(path:gsub("\\", "/"), "w")
	local title = ubermenu.title or "Menu"

	if not cfg then 
		consoleRGB(title .. " error: could not open presets.lua for writing", rgb(255,0,0))
		notify(title .. " error", "Could not open presets.lua for writing")
		return
	end

	for k,v in pairs(presets) do
		if v then
			cfg:write("require(\"presets/" .. k .. "/preset\")")
		end
	end

	notify(title or "Menu", "Preset Selection saved")
	cfg:close()
end

function presetMenu(parent, menu)
	menu:clear()
	menu:add_item({ title = "Help", description = "In order to properly unload presets you removed from\n\"Loaded Presets\", you have to press\n\"Save Preset Selection\" and then reload the config.\nTo just discard the changes you've made, reload the\nconfig without saving" })
	menu:add_separator({ title = "Loaded Presets" })
	menu:add_separator({ title = "Available Presets" })
	for k,v in kpairs(presets) do
		if v then
			-- Loaded preset
			menu:add_item({ title = k, position = 3, func = function()
				presets[k] = false
				presetMenu(parent, menu)
			end })
		else
			-- Not loaded preset
			menu:add_item({ title = k, func = function()
				require("presets/" .. k .. "/preset")
				config.reloadVariables()
				presets[k] = true
				presetMenu(parent, menu)
			end })
		end
	end
	menu:add_separator({})
	menu:add_item({ title = "Save Preset Selection", func = savePresetConfig })
	menu:add_item({ title = "Reload Config", func = function() openConsole("/reloadconfig") end })
end

local sub = ubermenu:add_submenu({ title = "Presets" })
presetMenu(ubermenu, sub)

sub = nil
