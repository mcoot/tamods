local sub = ubermenu:add_submenu({ title = "Server Management" })
	local sub1 = sub:add_submenu({ title = "Arena" })
		sub1:add_item({ title = "Air Arena",              func = function() openConsole("/sc map next 1495") end })
		sub1:add_item({ title = "Fraytown",               func = function() openConsole("/sc map next 1545") end })
		sub1:add_item({ title = "Hinterlands",            func = function() openConsole("/sc map next 1533") end })
		sub1:add_item({ title = "Lava Arena",             func = function() openConsole("/sc map next 1498") end })
		sub1:add_item({ title = "Undercroft",             func = function() openConsole("/sc map next 1546") end })
		sub1:add_item({ title = "Walled In",              func = function() openConsole("/sc map next 1497") end })
		sub1:add_item({ title = "Whiteout",               func = function() openConsole("/sc map next 1544") end })

	local sub1 = sub:add_submenu({ title = "Blitz" })
		sub1:add_item({ title = "Arx Novena",             func = function() openConsole("/sc map next 2566") end })
		sub1:add_item({ title = "Bella Omega",            func = function() openConsole("/sc map next 1550") end })
		sub1:add_item({ title = "Blueshift",              func = function() openConsole("/sc map next 1552") end })
		sub1:add_item({ title = "Canyon Crusade Revival", func = function() openConsole("/sc map next 1549") end })
		sub1:add_item({ title = "Crossfire",              func = function() openConsole("/sc map next 1542") end })
		sub1:add_item({ title = "Drydock",                func = function() openConsole("/sc map next 2599") end })
		sub1:add_item({ title = "Hellfire",               func = function() openConsole("/sc map next 1561") end })
		sub1:add_item({ title = "Katabatic",              func = function() openConsole("/sc map next 2598") end })

	local sub1 = sub:add_submenu({ title = "Capture and Hold" })
		sub1:add_item({ title = "Canyon Crusade Revival", func = function() openConsole("/sc map next 1548") end })
		sub1:add_item({ title = "Drydock Night",          func = function() openConsole("/sc map next 1530") end })
		sub1:add_item({ title = "Katabatic",              func = function() openConsole("/sc map next 1521") end })
		sub1:add_item({ title = "Outskirts 3P",           func = function() openConsole("/sc map next 1526") end })
		sub1:add_item({ title = "Raindance",              func = function() openConsole("/sc map next 1528") end })
		sub1:add_item({ title = "Sulfurcove",             func = function() openConsole("/sc map next 1535") end })
		sub1:add_item({ title = "Tartarus",               func = function() openConsole("/sc map next 1537") end })

	local sub1 = sub:add_submenu({ title = "Capture the Flag" })
		sub1:add_item({ title = "Arx Novena",             func = function() openConsole("/sc map next 1456") end })
		sub1:add_item({ title = "Bella Omega",            func = function() openConsole("/sc map next 1573") end })
		sub1:add_item({ title = "Bella Omega NS",         func = function() openConsole("/sc map next 1551") end })
		sub1:add_item({ title = "Blueshift",              func = function() openConsole("/sc map next 1543") end })
		sub1:add_item({ title = "Canyon Crusade Revival", func = function() openConsole("/sc map next 1514") end })
		sub1:add_item({ title = "Crossfire",              func = function() openConsole("/sc map next 1462") end })
		sub1:add_item({ title = "Dangerous Crossing",     func = function() openConsole("/sc map next 1538") end })
		sub1:add_item({ title = "Drydock",                func = function() openConsole("/sc map next 1457") end })
		sub1:add_item({ title = "Hellfire",               func = function() openConsole("/sc map next 1560") end })
		sub1:add_item({ title = "Icecoaster",             func = function() openConsole("/sc map next 1554") end })
		sub1:add_item({ title = "Katabatic",              func = function() openConsole("/sc map next 1447") end })
		sub1:add_item({ title = "Perdition",              func = function() openConsole("/sc map next 1555") end })
		sub1:add_item({ title = "Permafrost",             func = function() openConsole("/sc map next 1534") end })
		sub1:add_item({ title = "Raindance",              func = function() openConsole("/sc map next 1516") end })
		sub1:add_item({ title = "Stonehenge",             func = function() openConsole("/sc map next 1522") end })
		sub1:add_item({ title = "Sunstar",                func = function() openConsole("/sc map next 1523") end })
		sub1:add_item({ title = "Tartarus",               func = function() openConsole("/sc map next 1512") end })
		sub1:add_item({ title = "Temple Ruins",           func = function() openConsole("/sc map next 1493") end })
		sub1:add_item({ title = "Terminus",               func = function() openConsole("/sc map next 1553") end })

	local sub1 = sub:add_submenu({ title = "Rabbit" })
		sub1:add_item({ title = "Crossfire",              func = function() openConsole("/sc map next 1464") end })
		sub1:add_item({ title = "Inferno",                func = function() openConsole("/sc map next 1491") end })
		sub1:add_item({ title = "Nightabatic",            func = function() openConsole("/sc map next 1494") end })
		sub1:add_item({ title = "Outskirts",              func = function() openConsole("/sc map next 1458") end })
		sub1:add_item({ title = "Quicksand",              func = function() openConsole("/sc map next 1461") end })
		sub1:add_item({ title = "Sulfur Cove",            func = function() openConsole("/sc map next 1496") end })

	local sub1 = sub:add_submenu({ title = "Team Deathmatch" })
		sub1:add_item({ title = "Crossfire",              func = function() openConsole("/sc map next 1482") end })
		sub1:add_item({ title = "Drydock Night",          func = function() openConsole("/sc map next 1480") end })
		sub1:add_item({ title = "Inferno",                func = function() openConsole("/sc map next 1487") end })
		sub1:add_item({ title = "Miasma",                 func = function() openConsole("/sc map next 1536") end })
		sub1:add_item({ title = "Nightabatic",            func = function() openConsole("/sc map next 1485") end })
		sub1:add_item({ title = "Outskirts",              func = function() openConsole("/sc map next 1490") end })
		sub1:add_item({ title = "Quicksand",              func = function() openConsole("/sc map next 1484") end })
		sub1:add_item({ title = "Sulfur Cove",            func = function() openConsole("/sc map next 1488") end })

	sub:add_separator({})
	sub:add_item({ title = "End Current Map",             func = function() openConsole("/sc map end") end })
	sub:add_item({ title = "Skip Warmup",                 func = function() openConsole("/sc map start") end })

	sub:add_separator({ title = "Player" })
	sub:add_item({ title = "Kick",                       func = function() openConsole("/sc player kick ") end })
	sub:add_item({ title = "Ban",                        func = function() openConsole("/sc player ban ") end })
	sub:add_item({ title = "List",                       func = function() openConsole("/sc player list") end })
	sub:add_item({ title = "Spectators",                 func = function() openConsole("/sc player specs") end })

	sub:add_separator({ title = "Server" })
	sub:add_item({ title = "Login",                      func = function() openConsole("/sc login ") end })
	sub:add_item({ title = "Select",                     func = function() openConsole("/sc select ") end })
	sub:add_item({ title = "Status",                     func = function() openConsole("/sc server status") end })
	sub:add_item({ title = "Start",                      func = function() openConsole("/sc server start") end })
	sub:add_item({ title = "Stop",                       func = function() openConsole("/sc server stop") end })
	sub:add_item({ title = "Shutdown",                   func = function() openConsole("/sc map shutdown") end })

sub = nil
sub1 = nil
