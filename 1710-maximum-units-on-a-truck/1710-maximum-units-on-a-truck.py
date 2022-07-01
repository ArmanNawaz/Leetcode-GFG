class Solution:
    def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
        boxTypes.sort(key = lambda x: x[1], reverse = True)
        
        ans = 0
        
        for types in boxTypes:
            boxesChoosen = min(types[0], truckSize)
            units = types[1]
            
            ans += boxesChoosen * units
            truckSize -= boxesChoosen
            
            if truckSize == 0:
                break
        return ans
            
            