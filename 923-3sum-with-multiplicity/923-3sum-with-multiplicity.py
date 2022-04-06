class Solution:
    def threeSumMulti(self, arr: List[int], target: int) -> int:
        arr.sort()
        ans = 0
        mod = 1e9 + 7
        
        for i in range(len(arr) - 2):
            l = i + 1
            r = len(arr) - 1
            
            while l < r:
                add = arr[i] + arr[l] + arr[r]
                
                if add < target:
                    l += 1
                elif add > target:
                    r -= 1
                else:
                    count1, count2 = 1, 1
                    
                    while l < r and arr[l] == arr[l + 1]:
                        l += 1
                        count1 += 1
                    while l < r and arr[r] == arr[r - 1]:
                        r -= 1
                        count2 += 1
                    
                    if l == r:
                        ans = ans + (count1 * (count1 - 1) // 2) % mod
                        ans = ans % mod
                    else:
                        ans = ans + (count1 * count2) % mod
                        ans = ans % mod
                    l += 1
                    r -= 1
        return int(ans)