# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def solve(self, root):
        if root == None:
            return
        
        self.solve(root.left)
        
        self.temp.right = TreeNode(root.val)
        self.temp = self.temp.right
        
        self.solve(root.right)
        
        
    def increasingBST(self, root: TreeNode) -> TreeNode:
        # Daily
        self.newRoot = TreeNode(-1)
        self.temp = self.newRoot
        
        self.solve(root)
        
        return self.newRoot.right