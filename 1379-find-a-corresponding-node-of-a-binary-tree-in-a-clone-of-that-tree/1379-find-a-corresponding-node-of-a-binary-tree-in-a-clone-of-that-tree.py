# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def solve(self, root, target):
        if root == None:
            return root
        
        if root.val == target:
            return root
        
        left = self.solve(root.left, target)
        right = self.solve(root.right, target)
        
        if left == None:
            return right
        return left
        
        
    def getTargetCopy(self, original: TreeNode, cloned: TreeNode, target: TreeNode) -> TreeNode:
        return self.solve(cloned, target.val)