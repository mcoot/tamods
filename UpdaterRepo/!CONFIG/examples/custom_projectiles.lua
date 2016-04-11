function printModuleArray(arr, mod_type)
   print(string.format("    %d %s found", arr:size(), mod_type))
   for i=0, arr:size() - 1 do
      local mod = arr:get(i)
      print(string.format("      %s %d: %s", mod_type, i, mod:getFullName()))
      if mod:getClassName() == "ParticleModuleColor" then
	 -- This module is usually used for bullets, things with fixed colors
	 -- Cast the ParticleModule to ParticleModuleColor
	 mod = cast.ParticleModuleColor(mod)
	 local color = mod.StartColor
	 print(string.format("      Color module: %d entries", color.LookupTable:size()))
	 -- Print the initial color to the console
	 print(string.format("      (r=%.3f, g=%.3f, b=%.3f)", color.LookupTable:get(2), color.LookupTable:get(3), color.LookupTable:get(4)))
	 -- The colors used are floating point colors, so normal white is (1.0, 1.0, 1.0)
	 -- (15.0, 15.0, 15.0) is equivalent of normal white, with a brightness of 15
	 -- Uncomment the following lines to replace the projectile color with bright white
	 -- color.LookupTable:set(2, 15.0)
	 -- color.LookupTable:set(3, 15.0)
	 -- color.LookupTable:set(4, 15.0)
      elseif mod:getClassName() == "ParticleModuleColorOverLife" then
	 -- This module is usually used for trails and anything that changes color
	 -- Cast the ParticleModule to ParticleModuleColorOverLife
	 mod = cast.ParticleModuleColorOverLife(mod)
	 local tab = mod.ColorOverLife.LookupTable
	 print(string.format("      ColorOverLife module: %d entries", tab:size()))
	 -- Print the values
	 for c=2, tab:size() - 1 do
	    print("      " .. tostring(tab:get(c)))
	 end
      end
   end
end

-- This function will print a lto of information about a projectile to the console
-- It will also set the projectile color to bright white if the uncomment the 3 lines in printModuleArray
function printParticleSystem(proj)
   if not proj then
      return
   end
   print(proj:getFullName())
   print(proj.emitters:size() .. " emitters found")
   for em=0, proj.emitters:size() - 1 do
      local emitter = proj.emitters:get(em)
      print(string.format("  Emitter %d", em))
      print(string.format("  %d LODLevels found", emitter.LODLevels:size()))
      for lodi=0, emitter.LODLevels:size() - 1 do
	 local lod = emitter.LODLevels:get(lodi)
	 print(string.format("    LODLevel %d", lodi))
	 -- Check modules used for creation and update
	 printModuleArray(lod.spawnModules, "SpawnModules")
	 printModuleArray(lod.updateModules, "UpdateModules")
      end
   end
end

-- example use:
-- printParticleSystem(getProjectile("SLD", "AR"))
