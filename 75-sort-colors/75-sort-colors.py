class Solution:
    def sortColors(self, nums: List[int]) -> None:
        n = len(nums)
        start, mid, end = 0, 0, n - 1
        
        while start <= end:      
            if nums[start] == 0:
                nums[start], nums[mid] = nums[mid], nums[start]
                mid += 1
                start += 1
                
            elif nums[start] == 2:
                nums[start], nums[end] = nums[end], nums[start]
                end -= 1
                
            else:
                start += 1
        