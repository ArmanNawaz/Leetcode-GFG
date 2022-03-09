# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        if root == None:
            return 0
        queue = deque()
        
        queue.append(root)
        
        depth = 0
        while len(queue) > 0:
            levelSize = len(queue)
            depth += 1
            for i in range(levelSize):
                curr = queue.popleft()
                
                if curr.left == None and curr.right == None:
                    return depth
                if curr.left: queue.append(curr.left)
                if curr.right: queue.append(curr.right)
                    
        