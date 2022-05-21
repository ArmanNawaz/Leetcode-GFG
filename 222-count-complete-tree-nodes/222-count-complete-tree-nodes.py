# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countNodes(self, root: Optional[TreeNode]) -> int:
        if root == None:
            return 0
        
        count = 0
        queue = deque()
        
        queue.append(root)
        
        while queue:
            currNode = queue.popleft()
            count += 1
            
            if currNode.left != None:
                queue.append(currNode.left)
            
            if currNode.right != None:
                queue.append(currNode.right)
                
        return count