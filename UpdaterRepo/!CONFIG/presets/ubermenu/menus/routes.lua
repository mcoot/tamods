function routeMenu(m, all)
	m:clear()

	if all then
		route.getAll()
	else
		route.getEnemy()
	end
	routes = route.getTable()

	if #routes > 0 then
		for i = 1,#routes do
			name = routes[i]:gsub("^[^_]+_", "")
			name = name:gsub(".route$", "")
			m:add_item({ title = name, func = function()
				route.load(m.selected)
				--route.replayStart(0)
			end })
		end
	else
		m:add_item({ title = "No routes" })
	end

	m:add_separator({})
	m:add_item({ title = "Reset", func = route.reset })
end
function routeMenuAll(parent, item) routeMenu(item, true) end
function routeMenuEnemy(parent, item) routeMenu(item, false) end

route_start_time = 0

local sub = ubermenu:add_submenu({ title = "Routes" })
	sub:add_submenu({ title = "All Routes",   func = routeMenuAll })
	sub:add_submenu({ title = "Enemy Routes", func = routeMenuEnemy })

	sub:add_separator({ title = "Replaying" })
	sub:add_variable({ title = "Start Time", varname = "route_start_time", default = 0, min = 0, inc = 1 })
	sub:add_item({ title = "Start Replay",    func = function() route.replayStart(route_start_time) end })
	sub:add_item({ title = "Stop Replay",     func = route.replayStop })
	sub:add_separator({})
	sub:add_item({ title = "Enable Bot",      func = function() route.enableBot(true) end })
	sub:add_item({ title = "Disable Bot",     func = function() route.enableBot(false) end })

	sub:add_separator({ title = "Recording" })
	sub:add_item({ title = "Start Recording", func = route.recStart })
	sub:add_item({ title = "Stop Recording",  func = route.recStop })
	sub:add_item({ title = "Save Route",      func = function() openConsole("/routesave YOUR_DESCRIPTION_HERE") end })

	sub:add_separator({})
	sub:add_item({ title = "Reset", func = route.reset })

sub = nil
