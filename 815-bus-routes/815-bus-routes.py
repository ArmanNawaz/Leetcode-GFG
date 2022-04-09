class Solution:
    def numBusesToDestination(self, routes: List[List[int]], source: int, target: int) -> int:
        hashMap = dict()
        n = len(routes)
        
        for i in range(n):
            for j in range(len(routes[i])):
                stopNo = routes[i][j]
                
                if stopNo not in hashMap:
                    hashMap[stopNo] = list()
                    
                hashMap[stopNo].append(i)
        
        queue = deque()
        busVisited = set()
        stopVisited = set()
        level = -1
        
        queue.append(source)        
        stopVisited.add(source)
        
        while queue:
            size = len(queue)
            level += 1
            
            for i in range(size):
                currBusStop = queue.popleft()
                
                if currBusStop == target:
                    return level
                
                buses = hashMap[currBusStop]
                
                for bus in buses:
                    if bus not in busVisited:
                        
                        for busStop in routes[bus]:
                            
                            if busStop not in stopVisited:
                                queue.append(busStop)
                                stopVisited.add(busStop)
                    busVisited.add(bus)
        return -1
                
                    