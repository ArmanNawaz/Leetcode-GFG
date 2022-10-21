class Solution:
    def numOfSubarrays(self, arr: List[int]) -> int:
        evenCount = 0
        oddCount = 0
        
        if arr[0] % 2 == 0:
            evenCount = 1
        else:
            oddCount = 1
        
        ans = oddCount
        mod = int(1e9 + 7)
        
        for i in range(1, len(arr)):
            if arr[i] % 2 == 0:
                evenCount += 1
            else:
                tmp = oddCount
                oddCount = evenCount + 1
                evenCount = tmp
            ans = (ans + oddCount) % mod
        
        return ans
        