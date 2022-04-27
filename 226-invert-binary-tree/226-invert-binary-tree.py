# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if root == None:
            return root
        
        queue = deque()
        queue.append(root)
        
        while queue:
            levelSize = len(queue)
            
            for _ in range(levelSize):
                currNode = queue.popleft()
                
                currNode.left, currNode.right = currNode.right, currNode.left
                
                if currNode.left != None: queue.append(currNode.left)
                if currNode.right != None: queue.append(currNode.right)
        return root
        