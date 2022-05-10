class Solution:
    def dfs(self, k, target, start, end, partialAns, ans):
        # base case
        # If no more elements can be chosen
        if k == 0:
            # if target is achieved
            if target == 0:
                ans.append(partialAns[:])
            return
        
        # check all the elements
        for num in range(start, end):
            # include this element in answer
            partialAns.append(num)
            
            # make recursive call for next element
            # decreasing the number of elements to be picked and target Value
            self.dfs(k - 1, target - num, num + 1, end, partialAns, ans)
            
            # Remove the included element - backtracking step
            partialAns.pop() 
        
        return       
        
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        start, end = 1, 10
        
        partialAns, ans = [], []
        
        self.dfs(k, n, start, end, partialAns, ans)
        
        return ans
        
        