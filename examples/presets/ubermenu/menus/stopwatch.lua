local sub = ubermenu:add_submenu({ title = "Stopwatch" })
	sub:add_item({ title = "Start", func = stopwatch.start })
	sub:add_item({ title = "Stop",  func = stopwatch.stop })

sub = nil
