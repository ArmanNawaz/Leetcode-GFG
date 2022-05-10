# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def backtrack(self, root, targetSum):
        
        # include the current root value
        targetSum -= root.val
        self.partialAns.append(root.val)
        
        # if we are at leaf node
        if root.left == None and root.right == None:
            
            # if path sum is equal to targetSum
            if targetSum == 0:
                self.ans.append(self.partialAns[:])
            
            # now pop the leaf element
            # this operation is done here because we are returning from here
            # and control is not reaching line - 37, 38 for the same
            targetSum += root.val
            self.partialAns.pop()
            return
        
        # if left subtree is not none
        if root.left != None:
            self.backtrack(root.left, targetSum)
        
        # if right subtree is not none
        if root.right != None:
            self.backtrack(root.right, targetSum)
        
        # backtracking step
        targetSum += root.val
        self.partialAns.pop()
        
        
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        if root == None:
            return []
        
        self.partialAns = []
        self.ans = []
        
        self.backtrack(root, targetSum)
        
        return self.ans