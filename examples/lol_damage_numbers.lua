-- The text string that will be printed, this is what will be used to store the "lolol"
local damage_str = ""
-- The moving speed of the "lolol" when moving towards the next hit location
local speed = 0.1
-- The next hit location
local target_loc

-- List of values used to cycle through rainbow colors
local color_list = {rgb(255, 0, 0), rgb(255, 127, 0), rgb(255, 255, 0), rgb(127, 255, 0),
		    rgb(0, 255, 0), rgb(0, 255, 127), rgb(0, 255, 255), rgb(0, 127, 255),
		    rgb(0, 0, 255), rgb(127, 0, 255), rgb(255, 0, 255), rgb(255, 0, 127)}
-- The current index in the rainbow color
local color_idx = 0
-- The time before the numbers disappear
local max_time = 1.70
-- The distance that the damage numbers moving in a random direction will travel
local max_dist = 100

-- The array containing the random direction of the damage numbers
local custom_array = {}

-- Utility function of linear interpolation, used to smoothly move the text from one hit to another
function lerp(a, b, x)
   return a + (b - a) * x
end

-- Same as the lerp function, but interpolating vectors
function vectorLerp(start, target, x)
   local v = Vector4(0, 0, 0, 0)
   v.x = lerp(start.x, target.x, x)
   v.y = lerp(start.y, target.y, x)
   v.z = lerp(start.z, target.z, x)
   v.w = lerp(start.w, target.w, x)
   return v
end

-- Called when a damage number should be created
function onDamageNumberCreate(dam_nums, number, loc, is_shield)
   local num
   -- Update the hit location
   target_loc = loc
   -- Cycle through the rainbow colors
   color_idx = color_idx + 1
   -- The next block is executed if there's at least 1 damage number already existing
   -- This means that we should add "lol" to the existing string instead of creating a new one
   if dam_nums:size() > 0 then
      -- Retrieve the main damage number corresponding to the "lolol"
      num = dam_nums:get(0)
      -- Reset its timer so that it doesn't fade away as long as you hit
      num.time = max_time
      -- Change its color to the new rainbow color
      -- Note the "+ 1" at the end, it's because lua arrays are indexed starting at 1 and not 0
      num.color = color_list[color_idx % 12 + 1]
      -- We add another "ol" to the string so that it grows on each hit
      damage_str = damage_str .. "ol"
   -- This happen if no damage number exists
   else
      -- Create a new damage number for the "lolol"
      -- The value doesn't matter because we'll print a bunch of "lol"s, so we can just put 0 or anything
      num = DamageNumber(0, max_time, loc, is_shield)
      -- Set its color to the new rainbow color
      num.color = color_list[color_idx % 12 + 1]
      -- Add the damage number to the list
      dam_nums:add(num)
      -- Set the initial string to "lol"
      damage_str = "lol"
   end
   -- This is the added damage numbers that goes into random directions
   num = DamageNumber(number, max_time, loc, is_shield)
   -- Set the rainbow color
   num.color = color_list[color_idx % 12 + 1]
   -- Set its transparency to half
   num.color.a = 127
   -- Add a new random rotation to our custom list
   table.insert(custom_array, 1, math.random() * math.pi * 2)
   -- Add the damage number to the list of damage numbers
   dam_nums:add(num)
end

-- Called each frame to update and draw the damage numbers
function onDamageNumberUpdate(dam_nums, hud, delta)
   local i = 0
   -- Cycle through the existing damage numbers
   -- We use a "while" instead of a "for" because "for" has a fixed range, and in our case we might need to remove some values and change the range
   while i < dam_nums:size() do
      -- Get the current damage number
      local curr = dam_nums:get(i)
      -- Update the timer of the number
      curr.time = curr.time - delta
      -- If the timer is finished
      if curr.time <= 0 then
	 -- Remove the damage number from the list
	 dam_nums:remove(i)
	 -- And remove the random rotation if it's a damage number and not the one corresponding to the "lol"s
	 -- This one is always at the index 0 because it's the first that we add in onDamageNumberCreate
	 if i > 0 then
	    table.remove(custom_array, 1)
	 end
	 -- Decrease the index counter so that we don't miss a damage number
	 i = i - 1

      -- This happens if the timer is not finished
      else
	 -- If we are currently updating the string and not the random numbers
	 -- Interpolate its location to smoothly go to the next hit location
	 if i == 0 then
	    curr.location = vectorLerp(curr.location, target_loc, speed)
	 end
	 -- Create a Vector for the number location
	 -- We have to do this because "isOnScreen" takes a Vector but curr.location is a Vector4, with depth information
	 local loc = Vector(curr.location.x, curr.location.y, curr.location.z)
	 -- Check if the number is not behind the player where it would be useless to draw it
	 if isOnScreen(hud, loc) then
	    -- Project the location to get the coordinates on the screen of the number
	    loc = project(hud, loc)
	    -- In case we're handling the random numbers and not the string
	    if i > 0 then
	       -- Move the number in the defined random direction
	       local dist = max_dist * (max_time - curr.time) / max_time
	       loc.x = loc.x + math.cos(custom_array[i]) * dist
	       loc.y = loc.y + math.sin(custom_array[i]) * dist
	    end
	    -- Set the 2D screen-location depth to the 3D world-location depth
	    loc.z = curr.location.w
	    -- If we're handling the string, draw the string
	    if i == 0 then
	       drawDamageNumber(hud, damage_str, curr.color, loc, 1, 1)
	    -- Otherwise we're dealing with numbers, so draw the actual number value
	    else
	       drawDamageNumber(hud, curr.number, curr.color, loc, 1, 1)
	    end
	 end
      end
      i = i + 1
   end
end
