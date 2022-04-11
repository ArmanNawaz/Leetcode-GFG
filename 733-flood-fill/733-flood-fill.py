class Solution:
    def dfs(self, x, y, newColor, visited, image):
        visited[x][y] = True
        oldColor = image[x][y]
        image[x][y] = newColor
        
        if (x >= 1) and (not visited[x - 1][y]) and (image[x - 1][y] == oldColor):
            self.dfs(x - 1, y, newColor, visited, image)
            
        if (x < len(image) - 1) and (not visited[x + 1][y]) and (image[x + 1][y] == oldColor):
            self.dfs(x + 1, y, newColor, visited, image)
        
        if (y >= 1) and (not visited[x][y - 1]) and (image[x][y - 1] == oldColor):
            self.dfs(x, y - 1, newColor, visited, image)
        
        if (y < len(image[0]) - 1) and (not visited[x][y + 1]) and (image[x][y + 1] == oldColor):
            self.dfs(x, y + 1, newColor, visited, image)
            
        
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        
        visited = [[False] * len(image[0]) for _ in range(len(image))]
        self.dfs(sr, sc, newColor, visited, image)
        
        return image