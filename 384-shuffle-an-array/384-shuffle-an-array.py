class Solution:

    def __init__(self, nums: List[int]):
        self.arr = nums[:]
        self.originalArr = nums[:]
        
    def reset(self) -> List[int]:
        self.arr = self.originalArr[:]
        return self.arr

    def shuffle(self) -> List[int]:
        if len(self.arr) > 0:
            self.recurse(self.arr, len(self.arr))
        return self.arr
        
        
    def recurse(self, arr, n):
        if n <= 1:
            return 1
        idx = random.randint(0, n - 1)
        self.arr[idx], self.arr[n - 1] = self.arr[n - 1], self.arr[idx]
        self.recurse(self.arr, n - 1)


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()