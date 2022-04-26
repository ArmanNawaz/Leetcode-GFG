# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        if root == None:
            return []
        queue = deque()
        ans = []
        
        queue.append(root)
        
        while queue:
            levelSize = len(queue)
            maxElem = -float('inf')
            
            for _ in range(levelSize):
                currNode = queue.popleft()
                
                maxElem = max(maxElem, currNode.val)
                
                if currNode.left != None:
                    queue.append(currNode.left)
                if currNode.right != None:
                    queue.append(currNode.right)
            ans.append(maxElem)
        return ans
        