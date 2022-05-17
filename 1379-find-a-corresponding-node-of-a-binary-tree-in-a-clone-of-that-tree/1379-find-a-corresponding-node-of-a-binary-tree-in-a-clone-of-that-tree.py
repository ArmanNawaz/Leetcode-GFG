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
    
    def daily(self, rootOriginal, rootCloned, target):
        if rootOriginal == None:
            return rootOriginal
        
        if rootOriginal == target:
            return rootCloned
        
        left = self.daily(rootOriginal.left, rootCloned.left, target)
        right = self.daily(rootOriginal.right, rootCloned.right, target)
        
        if left == None:
            return right
        return left
        
        
    def getTargetCopy(self, original: TreeNode, cloned: TreeNode, target: TreeNode) -> TreeNode:
        return self.daily(original, cloned, target)
        # return self.solve(cloned, target.val)