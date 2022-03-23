# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        
        def height(root):
            nonlocal diameter
            if root == None:
                return 0
            
            leftHeight = height(root.left)
            rightHeight = height(root.right)
            
            currHeight = leftHeight + rightHeight
            diameter = max(currHeight, diameter)
            
            return max(leftHeight, rightHeight) + 1
        
        diameter = 0
        height(root)
        return diameter