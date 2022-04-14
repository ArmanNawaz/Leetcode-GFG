# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getInorder(self, root, inorder):
        if root:
            self.getInorder(root.left, inorder)
            inorder.append(root.val)
            self.getInorder(root.right, inorder)
            
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        
        # BruteForce
        inorder = []
        self.getInorder(root, inorder)
        
        for i in range(len(inorder) - 1):
            if inorder[i] >= inorder[i + 1]:
                return False
        return True
        
        