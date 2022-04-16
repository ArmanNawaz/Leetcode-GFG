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
        
        self.solve(root.right)
        
        self.valSum += root.val
        root.val = self.valSum
        
        self.solve(root.left)
        
        
    def convertBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        # Daily
        self.valSum = 0
        self.solve(root)
        
        return root
        