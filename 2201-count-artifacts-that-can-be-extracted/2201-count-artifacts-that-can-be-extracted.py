class Solution:
    def digArtifacts(self, n: int, artifacts: List[List[int]], dig: List[List[int]]) -> int:
        digSet = set()
        
        # create set for given dig points to have constant time lookup for any coordinate
        for each in dig:
            digSet.add(tuple(each))
            
        ans = 0
        
        # iterate through the artifacts
        for point in artifacts:
            
            point1 = point[ : 2] # starting cell
            point2 = point[2 : ] # ending cell
            
            # initially assume that we can visit all cells in current rectangle
            completeVisit = True
            
            # iterate through each rectangle of the current artifact
            for x in range(point1[0], point2[0] + 1):
                for y in range(point1[1], point2[1] + 1):
                    
                    # If current cell cannot be digged then break immediately
                    if (x, y) not in digSet:
                        completeVisit = False
                        
            # If all the cells can be visited, increment the answer
            if completeVisit:
                ans += 1
        
        return ans