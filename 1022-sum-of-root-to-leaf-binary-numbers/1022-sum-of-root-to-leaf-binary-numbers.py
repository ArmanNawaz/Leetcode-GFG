# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def solve(self, root, currSum = 0):
        if root == None:
            return 0
        
        rootSum = (currSum << 1) + root.val
        
        if root.left == None and root.right == None:
            return rootSum
        
        return self.solve(root.left, rootSum) + self.solve(root.right, rootSum)
    
    def sumRootToLeaf(self, root: Optional[TreeNode]) -> int:
        return self.solve(root)
    