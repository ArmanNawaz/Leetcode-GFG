class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        row, col = len(heights), len(heights[0])
        
        effort = [[float('inf')] * col for _ in range(row)]
        directions = [0, -1, 0, 1, 0]
        queue = deque()
        
        queue.append((0, 0))
        effort[0][0] = 0
        
        while queue:
            currCell = queue.popleft()
            
            for i in range(4):
                x = currCell[0] + directions[i]
                y = currCell[1] + directions[i + 1]
                
                if x < 0 or y < 0 or x >= row or y >= col:
                    continue
                
                if effort[x][y] <= effort[currCell[0]][currCell[1]]:
                    continue
                    
                cellDiff = abs(heights[x][y] - heights[currCell[0]][currCell[1]])
                
                routeEffort = max(effort[currCell[0]][currCell[1]], cellDiff)
                
                effort[x][y] = min(effort[x][y], routeEffort)
                
                queue.append((x, y))
                
        return effort[row - 1][col - 1]
                
            
            