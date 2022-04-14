# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        queue = deque()
        maxWidth = 1
        
        queue.append((root, 0))
        
        
        while queue:
            start = queue[0][1]
            end = queue[-1][1]
            
            levelSize = len(queue)
            # print(start, end)
            maxWidth = max(maxWidth, end - start + 1)
            
            for i in range(levelSize):
                currNode = queue.popleft()
                
                idx = currNode[1] - start
                
                if currNode[0].left != None:
                    queue.append((currNode[0].left, 2 * idx))
                
                if currNode[0].right != None:
                    queue.append((currNode[0].right, 2 * idx + 1))
        return maxWidth
            