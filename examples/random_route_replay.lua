function playRandomEnemyRoute()
   local routes = routeGetEnemyRoutes()
   local count = 0
   local chosen_index = 0
   for a, b in pairs(routes) do
      count = count + 1
   end
   chosen_index = math.floor(math.random() * count)
   count = 0
   for route_index, name in pairs(routes) do
      if count == chosen_index then
         routeEnableBot(true)
         routeLoad(route_index)
         replay()
         return
      end
      count = count + 1
   end
end
