sqHud.game_type   = ""
sqHud.my_name     = "none"
sqHud.my_team     = 255
sqHud.left_team   = 0
sqHud.left_color  = 1
sqHud.right_team  = 1
sqHud.right_color = 0
sqHud.show_hud    = true

sqHud.set_variables = function()
	sqHud.game_type = game.type()
	sqHud.my_team = player.teamNum()
	sqHud.my_name = player.name()

	-- Our current team is left and blue, while the enemy is red and right
	-- While spectating (team 255) Blood Eagle is always left/red
	sqHud.left_team = sqHud.my_team == 1 and 1 or 0
	sqHud.left_color = sqHud.my_team == 255 and 0 or 1
	-- Right team is always the opposite of the left team
	sqHud.right_team = 1 - sqHud.left_team
	sqHud.right_color = 1 - sqHud.left_color
end
