# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def solve(self, root, partialSum):
        partialSum = partialSum * 10 + root.val
        
        if root.left == None and root.right == None:
            return partialSum
        
        summ = 0
        if root.left: 
            summ += self.solve(root.left, partialSum)
        if root.right:
            summ += self.solve(root.right, partialSum)
        return summ
        
        
        
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        return self.solve(root, 0)