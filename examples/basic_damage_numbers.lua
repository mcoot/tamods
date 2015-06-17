function onDamageNumberCreate(dam_nums, number, loc, is_shield)
   local num = DamageNumber(number, 1.70, loc, is_shield)
   num.color = rgb(255, 255, 255)
   dam_nums:add(num)
end

function onDamageNumberUpdate(dam_nums, hud, delta)
   local i = 0
   while i < dam_nums:size() do
      local curr = dam_nums:get(i)
      curr.time = curr.time - delta
      if curr.time <= 0 then
	 dam_nums:remove(i)
	 i = i - 1
      else
	 local loc = Vector(curr.location.x, curr.location.y, curr.location.z)
	 if isOnScreen(hud, loc) then
	    loc = project(hud, loc)
	    loc.z = curr.location.w
	    drawDamageNumber(hud, tostring(curr.number), curr.color, loc, 1, 1)
	 end
      end
      i = i + 1
   end
end
