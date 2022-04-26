# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isCompleteTree(self, root: Optional[TreeNode]) -> bool:
        queue = deque()
        queue.append(root)
        
        while queue:
            levelSize = len(queue)
            
            for _ in range(levelSize):
                currNode = queue.popleft()
                
                if currNode == None:
                    if len(queue) != 0 and queue[0] != None:
                        return False
                else:
                    queue.append(currNode.left)
                    queue.append(currNode.right)
        return True