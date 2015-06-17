local damageNumbersColorMin = rgb(255, 255, 255)
local damageNumbersShieldColorMin = rgb(255, 255, 255)

function dist(v1, v2)
   local x = v2.x - v1.x
   local y = v2.y - v1.y
   local z = v2.z - v1.z
   return math.sqrt(x*x + y*y + z*z)
end

function onDamageNumberCreate(dam_nums, number, loc, is_shield)
   local num = DamageNumber(number, 1.70, loc, is_shield)
   num.color = rgb(255, 255, 255)
   dam_nums:add(num)
end

function onDamageNumberUpdate(dam_nums, hud, delta)
   local i = 0
   local player = getPlayerPos(hud)
   while i < dam_nums:size() do
      local curr = dam_nums:get(i)
      -- curr.time = curr.time - delta
      if curr.time <= 0 then
	 dam_nums:remove(i)
	 i = i - 1
      else
	 local loc = Vector(curr.location.x, curr.location.y, curr.location.z)
	 if isOnScreen(hud, loc) then
	    local d = dist(loc, player)
	    local maxd = 10000.0
	    if d > maxd then
	       curr.scale = 0
	    else
	       curr.scale = ((maxd - d) / maxd)
	    end
	    loc = project(hud, loc)
	    loc.z = curr.location.w
	    drawDamageNumber(hud, tostring(curr.number), curr.color, loc, curr.scale, curr.scale)
	 end
      end
      i = i + 1
   end
end
