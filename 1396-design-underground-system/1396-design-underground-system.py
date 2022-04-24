class UndergroundSystem:

    def __init__(self):
        self.ckin = dict()
        self.totalTime = dict()

    def checkIn(self, id: int, stationName: str, t: int) -> None:
        self.ckin[id] = (stationName, t)

    def checkOut(self, id: int, stationName: str, t: int) -> None:
        route = self.ckin[id][0] + '-' + stationName
        startTime = self.ckin[id][1]
        
        if route not in self.totalTime:
            self.totalTime[route] = list()
            
        self.totalTime[route].append(t - startTime)

    def getAverageTime(self, startStation: str, endStation: str) -> float:
        route = startStation + '-' + endStation
        
        return sum(self.totalTime[route]) / len(self.totalTime[route])


# Your UndergroundSystem object will be instantiated and called as such:
# obj = UndergroundSystem()
# obj.checkIn(id,stationName,t)
# obj.checkOut(id,stationName,t)
# param_3 = obj.getAverageTime(startStation,endStation)