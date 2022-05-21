# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root == None:
            return root
        
        queue = deque()
        queue.append(root)
        
        ans = []
        
        flag = True  # True -> left-right, False -> right-left
        while queue:
            levelSize = len(queue)
            
            levelNodes = []
            for _ in range(levelSize):
                currNode = queue.popleft()
                
                levelNodes.append(currNode.val)
                
                if currNode.left:
                    queue.append(currNode.left)
                if currNode.right:
                    queue.append(currNode.right)
                    
            if flag:
                ans.append(levelNodes)
            else:
                ans.append(levelNodes[::-1])
            flag = not flag
        return ans
                
            