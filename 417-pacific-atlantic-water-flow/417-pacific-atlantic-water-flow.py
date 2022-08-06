class Solution:
    def dfs(self, row, col, prev, ocean, heights):
        if row < 0 or row >= len(heights) or col < 0 or col >= len(heights[0]):
            return
        
        if heights[row][col] < prev or ocean[row][col]:
            return
        
        ocean[row][col] = True
        
        for dirs in self.directions:
            self.dfs(row + dirs[0], col + dirs[1], heights[row][col], ocean, heights)
            
        return       
    
    
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        self.directions = [[0, 1], [0, -1], [1, 0], [-1, 0]]
        
        rows, cols = len(heights), len(heights[0])
        pacific = [[False] * cols for _ in range(rows)]
        atlantic = [[False] * cols for _ in range(rows)]
        
        for col in range(cols):
            self.dfs(0, col, -float('inf'), pacific, heights)
            self.dfs(rows - 1, col, -float('inf'), atlantic, heights)
            
        for row in range(rows):
            self.dfs(row, 0, -float('inf'), pacific, heights)
            self.dfs(row, cols - 1, -float('inf'), atlantic, heights)
        
        ans = []
        
        for i in range(rows):
            for j in range(cols):
                if pacific[i][j] and atlantic[i][j]:
                    ans.append([i ,j])
        
        return ans
        