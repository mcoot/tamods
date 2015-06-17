local damage_str = ""
local speed = 0.1
local target_loc

local color_list = {rgb(255, 0, 0), rgb(255, 127, 0), rgb(255, 255, 0), rgb(127, 255, 0),
		    rgb(0, 255, 0), rgb(0, 255, 127), rgb(0, 255, 255), rgb(0, 127, 255),
		    rgb(0, 0, 255), rgb(127, 0, 255), rgb(255, 0, 255), rgb(255, 0, 127)}
local color_idx = 0
local max_time = 1.70
local max_dist = 100

local custom_array = {}

function lerp(a, b, x)
   return a + (b - a) * x
end

function vectorLerp(start, target, x)
   local v = Vector4(0, 0, 0, 0)
   v.x = lerp(start.x, target.x, x)
   v.y = lerp(start.y, target.y, x)
   v.z = lerp(start.z, target.z, x)
   v.w = lerp(start.w, target.w, x)
   return v
end

function onDamageNumberCreate(dam_nums, number, loc, is_shield)
   local num
   target_loc = loc
   color_idx = color_idx + 1
   if dam_nums:size() > 0 then
      num = dam_nums:get(0)
      num.time = max_time
      num.color = color_list[color_idx % 12 + 1]
      damage_str = damage_str .. "ol"
   else
      num = DamageNumber(0, max_time, loc, is_shield)
      num.color = color_list[color_idx % 12 + 1]
      dam_nums:add(num)
      damage_str = "lol"
   end
   num = DamageNumber(number, max_time, loc, is_shield)
   num.color = color_list[color_idx % 12 + 1]
   num.color.a = 127
   table.insert(custom_array, 1, math.random() * math.pi * 2)
   dam_nums:add(num)
end

function onDamageNumberUpdate(dam_nums, hud, delta)
   local i = 0
   while i < dam_nums:size() do
      local curr = dam_nums:get(i)
      curr.time = curr.time - delta
      if curr.time <= 0 then
	 dam_nums:remove(i)
	 if i > 0 then
	    table.remove(custom_array, 1)
	 end
	 i = i - 1
      else
	 if i == 0 then
	    curr.location = vectorLerp(curr.location, target_loc, speed)
	 end
	 local loc = Vector(curr.location.x, curr.location.y, curr.location.z)
	 if isOnScreen(hud, loc) then
	    loc = project(hud, loc)
	    if i > 0 then
	       local dist = max_dist * (max_time - curr.time) / max_time
	       loc.x = loc.x + math.cos(custom_array[i]) * dist
	       loc.y = loc.y + math.sin(custom_array[i]) * dist
	    end
	    loc.z = curr.location.w
	    if i == 0 then
	       drawDamageNumber(hud, damage_str, curr.color, loc, 1, 1)
	    else
	       drawDamageNumber(hud, curr.number, curr.color, loc, 1, 1)
	    end
	 end
      end
      i = i + 1
   end
end
