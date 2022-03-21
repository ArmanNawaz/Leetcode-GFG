class Solution:
    def shortestPath(self, grid: List[List[int]], k: int) -> int:
        # Aakash Sir
        
        rows = len(grid)
        cols = len(grid[0])
        
        queue = deque()
        state = (0, 0, k)
        queue.append((state, 0))
            
        visited = set([state])
        
        directions = [[-1, 0], [1, 0], [0, -1], [0, 1]]
        
        while queue:
            state, steps = queue.popleft()
            row, col, rem_obs = state
            
            if row == rows - 1 and col == cols - 1:
                return steps
            
            
            for direction in directions:
                new_row, new_col = row + direction[0], col + direction[1]
                
                if new_row < 0 or new_row >= rows or new_col < 0 or new_col >= cols:
                    continue
                
                new_obs = rem_obs - grid[new_row][new_col]
                newState = (new_row, new_col, new_obs)
                
                if new_obs >= 0 and newState not in visited:
                    queue.append((newState, steps + 1))
                    visited.add(newState)
        return -1
        