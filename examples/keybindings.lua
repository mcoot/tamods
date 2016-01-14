local g_hud = nil
local key_pressed = nil
local key_timer = 0

function onDamageNumberUpdate(overheads, hud, time)
   g_hud = hud
   if key_timer > 0 then
      drawDamageNumber(g_hud, key_pressed, rgb(255, 0, 0), Vector(400, 100, 0), 1, 1)
      key_timer = key_timer - 1
   end
end

-- General hook, every input event passes through here
function onInputEvent(key, event)
   if g_hud and (event == Input.PRESSED or event == Input.RELEASED) then
      local event_name
      if event == Input.PRESSED then
         event_name = "pressed"
      else
         event_name = "released"
      end
      key_pressed = key .. " " .. event_name
      key_timer = 100
   end
end

-- Individual hook for when the "L" key is released
-- Only activated once because the function is unbound
bindKey("L", Input.RELEASED,
        function(key, event)
           print ("L Released")
           unbindKey("L", 1)
        end
)

-- Bind save
bindKey("F1", Input.RELEASED, state.save)
bindKey("F2", Input.RELEASED, state.recall)
bindKey("F3", Input.RELEASED, stopwatch.toggle)

-- Print the original binds for wasd to the console
-- The console is not working when the dll is just injected to use /rc to see it
list = searchTribesInputCommands("gba_(moveforward$|backward$|strafe(left|right)$)")
for key,bind in pairs(list) do
   print(bind.name .. " -> " .. bind.command)
end
