class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ans = []
        
        i, n = 0, len(nums)
        
        # iterate all the elements
        while i < n:
            j, k = i + 1, n - 1
            
            # find the required sum in nums[i + 1: ]
            while j < k:
                _sum = nums[i] + nums[j] + nums[k]
                
                if _sum < 0:
                    j += 1
                    
                elif _sum > 0:
                    k -= 1
                    
                else:
                    ans.append([nums[i], nums[j], nums[k]])
                    
                    # if the array contains duplicates
                    # move the next different element
                    pre, nxt = nums[j], nums[k]
                    while j < n and k > i and pre == nums[j] and nxt == nums[k]:
                        j += 1
                        k -= 1
            # move to the next different element
            tmp = nums[i]
            while i < n and tmp == nums[i]:
                i += 1
                
        return ans