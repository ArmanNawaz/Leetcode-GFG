# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        queue = deque()
        maxSum = -float('inf')
        maxLevel = 0
        level = 0
        
        queue.append(root)
        
        while queue:
            levelSize = len(queue)
            level += 1
            levelSum = 0
            
            for _ in range(levelSize):
                currNode = queue.popleft()
                
                levelSum += currNode.val
                
                if currNode.left != None:
                    queue.append(currNode.left)
                    
                if currNode.right != None:
                    queue.append(currNode.right)
            if levelSum > maxSum:
                maxSum = levelSum
                maxLevel = level
        return maxLevel