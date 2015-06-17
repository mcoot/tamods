damageNumbersLimit = 0
showDamageNumberStream = false
showRainbow = false

-- HUD Modifications
showObjectiveIcon = false
showCTFBaseIcon = false
showFlagBaseIcon = true
showNuggetIcon = true
showPlayerIcon = true
showVehicleIcon = true

-- Use rgba() if you want alpha
red = rgb(255, 0, 0)
damageNumbersColorMin = rgb(0, 255, 0)
damageNumbersColorMax = red

-- crosshairs with an 's' when specifying two crosshairs
setCrosshairs("SEN", "SAP20", crosshairs("SMG", "SAP20"))

-- crosshair without 's' when specifying only one
chain = crosshair("chain")
setCrosshairs("SEN", "BXT1A", chain)
setCrosshairs("SEN", "Nova", chain)
setCrosshairs("BRT", "Spin", chain)
setCrosshairs("BRT", "Colt", chain)

setLoadout("SLD", 1, "Offense", equipment("AR", "Thumper DX", "Grenade", "Utility", "Looter", "QD"))
