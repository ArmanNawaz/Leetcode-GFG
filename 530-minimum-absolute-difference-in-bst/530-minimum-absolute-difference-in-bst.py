# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getInorder(self, root, ans):
        if root == None:
            return
        self.getInorder(root.left, ans)
        ans.append(root.val)
        self.getInorder(root.right, ans)
        
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        arr = []
        self.getInorder(root, arr)
        
        ans = float('inf')
        
        for i in range(1, len(arr)):
            ans = min(ans, arr[i] - arr[i - 1])
        return ans