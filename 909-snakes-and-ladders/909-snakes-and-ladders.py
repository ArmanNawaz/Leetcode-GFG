class Solution:
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        
        def findCoord(currPos, n):
            row = n - 1 - (currPos - 1) // n
            col = (currPos - 1) % n
            
            if row % 2 == n % 2:
                return [row, n - 1 - col]
            return [row, col]
        
        
        minSteps = -1
        n = len(board)
        start, end = 1, n * n
        
        visited = [[False] * n for _ in range(n)]
        # print(visited)
        queue = deque()
        
        visited[n - 1][0] = True
        queue.append(start)
        
        while queue:
            size = len(queue)
            minSteps += 1
            
            for i in range(size):
                currPos = queue.popleft()
                
                if currPos == end:
                    return minSteps
                
                for dice in range(1, 7):
                    if currPos + dice > end:
                        break
                        
                    nextRow, nextCol = findCoord(currPos + dice, n)
                    
                    if visited[nextRow][nextCol] == False:
                        visited[nextRow][nextCol] = True
                        
                        if board[nextRow][nextCol] != -1:
                            queue.append(board[nextRow][nextCol])
                            
                        else:
                            queue.append(currPos + dice)
        print(visited)
        return -1
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
        
        