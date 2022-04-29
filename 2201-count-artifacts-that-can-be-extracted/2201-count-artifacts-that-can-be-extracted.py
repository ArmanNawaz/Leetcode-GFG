class Solution:
    def digArtifacts(self, n: int, artifacts: List[List[int]], dig: List[List[int]]) -> int:
        digSet = set()
        
        for each in dig:
            digSet.add(tuple(each))
            
        ans = 0
        
        for point in artifacts:
            point1 = point[ : 2]
            point2 = point[2 : ]
            
            completeVisit = True
            
            for x in range(point1[0], point2[0] + 1):
                for y in range(point1[1], point2[1] + 1):
                    if (x, y) not in digSet:
                        completeVisit = False
            if completeVisit:
                ans += 1
        
        return ans