game_type   = ""
my_name     = "none"
my_team     = 255
left_team   = 0
left_color  = 1
right_team  = 1
right_color = 0
show_hud    = true

function set_variables()
	game_type = game.type()
	my_team = player.teamNum()
	my_name = player.name()

	-- Our current team is left and blue, while the enemy is red and right
	-- While spectating (team 255) Blood Eagle is always left/red
	left_team = my_team == 1 and 1 or 0
	left_color = my_team == 255 and 0 or 1
	-- Right team is always the opposite of the left team
	right_team = 1 - left_team
	right_color = 1 - left_color
end
