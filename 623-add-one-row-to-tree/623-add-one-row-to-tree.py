# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def addOneRow(self, root: Optional[TreeNode], val: int, depth: int) -> Optional[TreeNode]:
        
        if depth == 1:
            newRoot = TreeNode(val, root)
            return newRoot
        
        currDepth = 0
        queue = deque()
        queue.append(root)
        
        isDone = False
        while queue or not isDone:
            levelSize = len(queue)
            currDepth += 1
            
            for _ in range(levelSize):
                currNode = queue.popleft()
                
                if currDepth == depth - 1:
                    leftNode = TreeNode(val, currNode.left, None)
                    rightNode = TreeNode(val, None, currNode.right)
                    
                    currNode.left = leftNode
                    currNode.right = rightNode
                    
                    isDone = True
                
                if currNode.left:
                    queue.append(currNode.left)
                
                if currNode.right:
                    queue.append(currNode.right)
        return root
                    
        