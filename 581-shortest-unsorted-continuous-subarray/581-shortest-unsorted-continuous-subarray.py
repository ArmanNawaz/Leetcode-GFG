class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        start, end = len(nums), 0
        
        stack = deque()
        
        for i in range(len(nums)):
            while stack and nums[stack[-1]] > nums[i]:
                start = min(start, stack.pop())
            stack.append(i)
        
        stack = deque()
        
        for i in range(len(nums) - 1, -1, -1):
            while stack and nums[stack[-1]] < nums[i]:
                end = max(end, stack.pop())
            stack.append(i)
        
        ans = end - start + 1
        
        if ans < 0:
            return 0
        return ans
        