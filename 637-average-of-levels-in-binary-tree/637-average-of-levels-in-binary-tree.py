# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        queue = deque()
        ans = []
        
        queue.append(root)
        
        while queue:
            levelSize = len(queue)
            levelSum = 0
            
            for _ in range(levelSize):
                currNode = queue.popleft()
                
                levelSum += currNode.val
                
                if currNode.left != None:
                    queue.append(currNode.left)
                if currNode.right != None:
                    queue.append(currNode.right)
            ans.append(levelSum / levelSize)
        return ans