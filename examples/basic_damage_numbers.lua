-- This function is called everytime a damage number should be created, instead of the original function
function onDamageNumberCreate(dam_nums, number, loc, is_shield)
   -- Create a new instance of DamageNumber. The default time that it takes before a damage number fades out is 1.70
   local num = DamageNumber(number, 1.70, loc, is_shield)
   -- Set the original color
   num.color = rgb(255, 255, 255)
   -- Add the new damage number to the original array
   dam_nums:add(num)
end

-- This function is called once per frame to update the attributes of the damage numbers and draw them
function onDamageNumberUpdate(dam_nums, hud, delta)
   local i = 0
   -- Loop over every damage numbers
   while i < dam_nums:size() do
      -- Get the current damage number we're working on
      local curr = dam_nums:get(i)
      -- Make time pass for the damage number
      curr.time = curr.time - delta
      -- If the damage number's timer is finished
      if curr.time <= 0 then
       -- Remove the damage number from the array and update the index
	 dam_nums:remove(i)
       -- This has to be done because the element at i+1 before the removal will move to index i
       -- So without this line there's a damage number that would not be treated when a damage number is removed
	 i = i - 1
      else
       -- If the damage number is still alive, we have to draw it, so we create a vector for its location
	 local loc = Vector(curr.location.x, curr.location.y, curr.location.z)
       -- Check that the location is not located behind the player, it would be useless to draw it there
	 if isOnScreen(hud, loc) then
          -- Project the world location to get the on-screen x and y coordinates of the damage number
	    loc = project(hud, loc)
          -- Set the depth of the number to the depth of the real location
	    loc.z = curr.location.w
          -- And finally draw the damage number to the screen using its color, location and a scale of 1
	    drawDamageNumber(hud, tostring(curr.number), curr.color, loc, 1, 1)
	 end
      end
      i = i + 1
   end
end
