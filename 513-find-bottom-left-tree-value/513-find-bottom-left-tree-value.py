# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findBottomLeftValue(self, root: Optional[TreeNode]) -> int:
        queue = deque()
        queue.append(root)
        ans = root.val
        
        while queue:
            levelSize = len(queue)
            
            for i in range(levelSize):
                currNode = queue.popleft()
                
                if i == 0:
                    ans = currNode.val
                
                if currNode.left != None: queue.append(currNode.left)
                if currNode.right != None: queue.append(currNode.right)
        return ans