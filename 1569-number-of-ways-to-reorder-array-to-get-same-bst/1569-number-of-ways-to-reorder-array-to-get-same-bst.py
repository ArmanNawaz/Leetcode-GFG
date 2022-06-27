class Solution:
    def numOfWays(self, nums: List[int]) -> int:
        
        def solve(arr):
            mod = 1000000007
            if len(arr) <= 2:
                return 1
            
            l, r = [], []
            
            root = arr[0]
            n = len(arr)
            for i in range(1, n):
                if arr[i] < root:
                    l.append(arr[i])
                else:
                    r.append(arr[i])
                
            left = solve(l)
            right = solve(r)
            
            return (math.factorial(n - 1) * left * right // (math.factorial(len(l)) * math.factorial(len(r)))) % mod
        
        return int(solve(nums)) - 1

        