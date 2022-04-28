class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        row, col = len(heights), len(heights[0])
        
        # Effort matrix which stores effort for (x, y) cell from (0, 0)
        # initally all efforts are maximum
        effort = [[float('inf')] * col for _ in range(row)]
        
        # All four directions
        directions = [0, -1, 0, 1, 0]
        queue = deque()
        
        # Start with (0, 0)
        queue.append((0, 0))
        effort[0][0] = 0
        
        while queue:
            currCell = queue.popleft()
            
            # Iterate for all four directions
            for i in range(4):
                
                # indices for adjacent cells
                x = currCell[0] + directions[i]
                y = currCell[1] + directions[i + 1]
                
                # If indices are not feasible then continue
                if x < 0 or y < 0 or x >= row or y >= col:
                    continue
                
                # If effort for (x, y) is already less then continue
                if effort[x][y] <= effort[currCell[0]][currCell[1]]:
                    continue
                
                # Cell difference for current cell and its adjacent cell
                cellDiff = abs(heights[x][y] - heights[currCell[0]][currCell[1]])
                
                # maximum route effort for current cell
                routeEffort = max(effort[currCell[0]][currCell[1]], cellDiff)
                
                # Update to minimum effort
                effort[x][y] = min(effort[x][y], routeEffort)
                
                # Enqueue the adjacent cell
                queue.append((x, y))
        
        # Return the value of last cell
        return effort[row - 1][col - 1]
                
            
            