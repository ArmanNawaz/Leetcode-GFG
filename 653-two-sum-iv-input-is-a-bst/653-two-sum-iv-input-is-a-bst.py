# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorder(self, root, arr):
        if root == None:
            return
        self.inorder(root.left, arr)
        arr.append(root.val)
        self.inorder(root.right, arr)
        
        
    def findTarget(self, root: Optional[TreeNode], k: int) -> bool:
        arr = []
        self.inorder(root, arr)
        
        i, j = 0, len(arr) - 1
        
        while i < j:
            _sum = arr[i] + arr[j]
            
            if _sum < k:
                i += 1
            elif _sum > k:
                j -= 1
            else:
                return True
        return False