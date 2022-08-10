# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def recurse(self, nums, start, end):
        if start >= end:
            return None
        
        mid = start + (end - start) // 2
        root = TreeNode(nums[mid])
        
        root.left = self.recurse(nums, start, mid)
        root.right = self.recurse(nums, mid + 1, end)
        
        return root
        
    
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        return self.recurse(nums, 0, len(nums))