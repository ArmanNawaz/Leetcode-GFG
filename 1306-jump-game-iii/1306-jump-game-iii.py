class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        # Rahul Sir - BFS
        
        queue = deque()
        
        queue.append(start)
        
        while len(queue) > 0:
            idx = queue.popleft()
            
            if arr[idx] == 0: return True
            if arr[idx] < 0: continue
            
            if idx + arr[idx] < len(arr): queue.append(idx + arr[idx])
            if idx - arr[idx] >= 0: queue.append(idx - arr[idx])
            
            arr[idx] *= -1
            
        return False
        