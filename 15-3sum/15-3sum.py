class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        n = len(nums)
        ans = []
        for i in range(n):
            j = i + 1
            k = n - 1
            
            while j < k:
                res = []
                s = nums[i] + nums[j] + nums[k]
                if s == 0:
                    res.append(nums[i])
                    res.append(nums[j])
                    res.append(nums[k])
                    j += 1
                    k -= 1
                elif s > 0:
                    k -= 1
                else:
                    j += 1
                if len(res) != 0 and res not in ans:
                    ans.append(res)
                
        return ans
            