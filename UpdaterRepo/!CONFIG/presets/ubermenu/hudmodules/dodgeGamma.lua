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

bindKey(module.opts.bindKeyMinus, Input.PRESSED, gammaMinus)
bindKey(module.opts.bindKeyMinus, Input.REPEAT, gammaMinus)
bindKey(module.opts.bindKeyPlus, Input.PRESSED, gammaPlus)
bindKey(module.opts.bindKeyPlus, Input.REPEAT, gammaPlus)
bindKey(module.opts.bindKeyToggle, Input.PRESSED, gammaToggle)

return module
