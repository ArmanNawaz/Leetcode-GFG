# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rob(self, root: Optional[TreeNode]) -> int:
        def solve(root, dp):
            if root == None:
                return 0
            
            if root in dp:
                return dp[root]
            
            pick = solve(root.left, dp) + solve(root.right, dp)
            
            notPick = root.val
            
            if root.left:
                notPick += solve(root.left.left, dp) + solve(root.left.right, dp)
            
            if root.right:
                notPick += solve(root.right.left, dp) + solve(root.right.right, dp)
            
            dp[root] = max(pick, notPick)
            return dp[root]
        
        dp = dict()
        return solve(root, dp)
            