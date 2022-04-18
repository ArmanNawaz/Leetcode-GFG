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
        
        if self.k == 1:
            self.ans = root.val
        self.k -= 1
        
        self.solve(root.right)
        
        
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        # Daily
        self.ans = 0
        self.k = k
        self.solve(root)
        return self.ans
        