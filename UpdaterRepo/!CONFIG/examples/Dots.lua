damageNumberStreamTimeout = damageNumberStreamTimeout and damageNumberStreamTimeout or 0.5
damageNumbersOffsetX = damageNumbersOffsetX and damageNumbersOffsetX or 0
damageNumbersOffsetY = damageNumbersOffsetY and damageNumbersOffsetY or 0
damageNumbersScale = damageNumbersScale and damageNumbersScale or 1
damageNumberCustomText = damageNumberCustomText and damageNumberCustomText or ""
damageNumbersColorMin = damageNumbersColorMin and damageNumbersColorMin or rgb(255, 255, 255)
damageNumbersColorMax = damageNumbersColorMax and damageNumbersColorMax or rgb(248, 83, 83)
damageNumbersLimit = damageNumbersLimit and damageNumbersLimit or 0

local m_fOverheadNumberZSpeed = 170.0
local m_OverheadNumberColorShieldMin = rgb(255, 255, 255)
local m_OverheadNumberColorShieldMax = rgb(83, 83, 255)
local m_fOverheadNumberTotalTime = 1.70
local m_fOverheadNumberFadeTime = 1.30
local m_fOverheadNumberScaleTime = 0.450
local m_fOverheadNumberMaxScaleAmount = 0.650
local m_fOverheadNumberColorizeTimeMin = 0.250
local m_fOverheadNumberColorizeTimeMax = 0.50

-- Linear interpolation utility function
function lerp(a, b, x)
   return a + (b - a) * x
end

-- Simple number creation, just add the number to the list
function onDamageNumberCreate(dam_nums, number, loc, is_shield)
   local num = DamageNumber(number, m_fOverheadNumberTotalTime, loc, is_shield)
   num.color = damageNumbersColorMin
   dam_nums:add(num)
end

-- Numbers update, most of the code is there to match HiRez's implementation
function onDamageNumberUpdate(dam_nums, hud, delta)
   local i = 0
   while i < dam_nums:size() do
      local curr = dam_nums:get(i)
      curr.time = curr.time - delta
      if curr.time <= 0 then
	 dam_nums:remove(i)
	 i = i - 1
      else
	 local accu_time = 1.70 - curr.time
	 if curr.number > damageNumbersLimit then
	    curr.location.z = curr.location.z + delta * m_fOverheadNumberZSpeed
	 end
	 if accu_time > m_fOverheadNumberColorizeTimeMax then
	    if curr.shieldDamage then
	       curr.color = m_OverheadNumberColorShieldMax
	    else
	       curr.color = damageNumbersColorMax
	    end
	 else
	    if accu_time > m_fOverheadNumberColorizeTimeMin and m_fOverheadNumberColorizeTimeMin < m_fOverheadNumberColorizeTimeMax then
	       local alpha = (m_fOverheadNumberColorizeTimeMin - (m_fOverheadNumberColorizeTimeMax - accu_time)) / (m_fOverheadNumberColorizeTimeMax - m_fOverheadNumberColorizeTimeMin)
	       local cmin, cmax

	       if curr.shieldDamage then
		  cmin = m_OverheadNumberColorShieldMin
		  cmax = m_OverheadNumberColorShieldMax
	       else
		  cmin = damageNumbersColorMin
		  cmax = damageNumbersColorMax
	       end
	       curr.color.r = math.floor(lerp(cmin.r, cmax.r, alpha))
	       curr.color.g = math.floor(lerp(cmin.g, cmax.g, alpha))
	       curr.color.b = math.floor(lerp(cmin.b, cmax.b, alpha))
	    end
	 end

	 if curr.time < m_fOverheadNumberFadeTime and m_fOverheadNumberFadeTime > 0 then
	    curr.color.a = math.floor((curr.time / m_fOverheadNumberFadeTime) * 255.0)
	 end

	 if accu_time < m_fOverheadNumberScaleTime then
	    local peak = m_fOverheadNumberScaleTime / 2.0
	    if accu_time < peak then
	       curr.scale = 1.0 + ((accu_time / peak) * m_fOverheadNumberMaxScaleAmount)
	    else
	       curr.scale = 1.0 + ((1.0 - ((accu_time - (m_fOverheadNumberScaleTime - peak)) / (m_fOverheadNumberScaleTime - peak))) * m_fOverheadNumberMaxScaleAmount)
	    end
	 elseif curr.scale ~= 1.0 then
	    curr.scale = 1.0
	 end
	 
	 local loc = Vector(curr.location.x, curr.location.y, curr.location.z)
	 if isOnScreen(hud, loc) then
	    loc = project(hud, loc)
	    loc.z = curr.location.w
	    if curr.shieldDamage then
	       loc.y = loc.y - 20.0
	    end

	    curr.scale = curr.scale * damageNumbersScale
	    loc.x = loc.x + damageNumbersOffsetX
	    loc.y = loc.y + damageNumbersOffsetY

	    -- Custom part, in this case draw a dot instead of the number if it's under the threshold
	    local str = "."
	    if curr.number > damageNumbersLimit then
	       str = tostring(curr.number)
	    end
	    drawDamageNumber(hud, str, curr.color, loc, curr.scale, curr.scale)
	 end
      end
      i = i + 1
   end
end
