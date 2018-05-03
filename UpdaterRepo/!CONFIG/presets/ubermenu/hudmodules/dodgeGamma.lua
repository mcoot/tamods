local module = {}
--Need a chat module installed to work, probably
module.name                 = "dodgeGamma"  -- This HAS to be the same as the filename minus the trailing .lua
module.opts                 = {}         -- Options, you can add your own here
module.opts.bindKeyMinus    = "B"
module.opts.bindKeyPlus     = "N"
module.opts.bindKeyToggle   = "M"
module.opts.current_gamma   = 2.2
module.opts.toggle_gamma_amount   = 1.2
module.gamma_low = false
 
local binded = false

function gammaPlus()
    module.opts.current_gamma = module.opts.current_gamma + 0.1
    setGamma(module.opts.current_gamma)
end
 
function gammaMinus()
    module.opts.current_gamma = module.opts.current_gamma - 0.1
    setGamma(module.opts.current_gamma)
end
 
function gammaToggle()
    module.opts.current_gamma = module.gamma_low and module.opts.current_gamma + module.opts.toggle_gamma_amount or module.opts.current_gamma - module.opts.toggle_gamma_amount
    module.gamma_low = not module.gamma_low
    setGamma(module.opts.current_gamma)
end

function setGamma(passedGamma)
	if passedGamma < 0.5 then
		module.opts.current_gamma = 0.5
		gamma(0.5)
	elseif passedGamma > 3 then
		module.opts.current_gamma = 3
		gamma(3)
	else
		gamma(passedGamma)
	end
end


-- The drawing function for this module
function module.draw(res_x, res_y)
	
	if hud_data.game_type == "TrGame_TRCTF" or hud_data.game_type == "TrGame_TrCTFBlitz" or hud_data.game_type == "TrGame_TRTeamRabbit" then


		if binded == false then
			if module.opts.bindKeyMinus ~= "" then
				bindKey(module.opts.bindKeyMinus, Input.PRESSED, gammaMinus)
			end
			if module.opts.bindKeyPlus ~= "" then
				bindKey(module.opts.bindKeyPlus, Input.PRESSED, gammaPlus)
			end
			if module.opts.Route_Record_Save_Key ~= "" then
				bindKey(module.opts.bindKeyToggle, Input.PRESSED, gammaToggle)
			end
			binded = true
		end
	end
end

return module