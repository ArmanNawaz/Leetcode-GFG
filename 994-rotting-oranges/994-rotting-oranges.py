class Node:
    def __init__(self, x, y, time):
        self.x = x
        self.y = y
        self.time = time

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        # Aakash Sir
        
        rows = len(grid)    # Number of rows
        cols = len(grid[0])  # Number of columns
        
        queue = deque()
        
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 2:
                    node = Node(i, j, 0)
                    queue.append(node)
        
        ans  = 0
        
        while len(queue):
            
            currNode = queue.popleft()
            x, y, time = currNode.x, currNode.y, currNode.time
            
            if x >= 1 and grid[x - 1][y] == 1:
                grid[x - 1][y] = 2
                node = Node(x - 1, y, time + 1)
                queue.append(node)
                ans = time + 1                
            
            if x < rows - 1 and grid[x + 1][y] == 1:
                grid[x + 1][y] = 2
                node = Node(x + 1, y, time + 1)
                queue.append(node)
                ans = time + 1
            
            if y >= 1 and grid[x][y - 1] == 1:
                grid[x][y - 1] = 2
                node = Node(x, y - 1, time + 1)
                queue.append(node)
                ans = time + 1
                
            if y < cols - 1 and grid[x][y + 1] == 1:
                grid[x][y + 1] = 2
                node = Node(x, y + 1, time + 1)
                queue.append(node)
                ans = time + 1
        
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 1:
                    return -1
        return ans
            