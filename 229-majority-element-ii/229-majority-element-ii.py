class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        ans = []
        hashMap = dict()
        n = len(nums)
        
        for x in nums:
            hashMap[x] = hashMap.get(x, 0) + 1
        
        for key, value in hashMap.items():
            if value > (n // 3):
                ans.append(key)
        
        return list(set(ans))