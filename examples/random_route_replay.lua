function playRandomEnemyRoute()
   local routes = route.getEnemyRoutes()
   local count = 0
   local chosen_index = 0
   for a, b in pairs(routes) do
      count = count + 1
   end
   chosen_index = math.floor(math.random() * count)
   count = 0
   for route_index, name in pairs(routes) do
      if count == chosen_index then
         route.enableBot(true)
         route.load(route_index)
         route.replayStart(0.0)
         return
      end
      count = count + 1
   end
end
