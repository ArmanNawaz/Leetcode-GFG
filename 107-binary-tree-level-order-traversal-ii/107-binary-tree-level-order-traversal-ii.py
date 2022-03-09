# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrderBottom(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root == None:   # Base case
            return []
        queueAns = deque()
        queue = deque()
        
        queue.append(root)
        
        while len(queue) > 0:
            levelSize = len(queue)  # Max Number of elements in current level
            currList = []   # Elements of each level
            
            for i in range(levelSize):  
                curr = queue.popleft()
                
                currList.append(curr.val)
                
                if curr.left:
                    queue.append(curr.left)
                if curr.right:
                    queue.append(curr.right)
                    
            queueAns.appendleft(currList)  # Append to front
        
        ans = []
        while len(queueAns) > 0:
            ans.append(queueAns.popleft())
        return ans
        
        