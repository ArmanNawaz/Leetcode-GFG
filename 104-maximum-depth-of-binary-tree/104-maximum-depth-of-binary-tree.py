# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if root == None:
            return 0
        if root.left == None and root.right == None:
            return 1
        
        queue = deque()
        
        queue.append(root)
        
        depth = 0
        while len(queue):
            levelSize = len(queue)
            
            depth += 1
            
            for i in range(levelSize):
                curr = queue.popleft()
                
                if curr.left != None: queue.append(curr.left)
                if curr.right != None: queue.append(curr.right)
        return depth