# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def deepestLeavesSum(self, root: Optional[TreeNode]) -> int:
        queue = deque()
        res = 0
        queue.append(root)
        
        while queue:
            levelSize = len(queue)
            levelSum = 0
            flag = True
            
            for _ in range(levelSize):
                currNode = queue.popleft()
                levelSum += currNode.val
                
                if currNode.left != None:
                    queue.append(currNode.left)
                    flag = False
                if currNode.right != None:
                    queue.append(currNode.right)
                    flag = False
            if flag:
                res += levelSum
        return res
                