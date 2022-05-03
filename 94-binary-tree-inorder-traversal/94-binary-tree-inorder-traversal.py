# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        if root == None:
            return []
        
        stack = deque()
        ans = []
        
        curr = root
        
        while curr != None or stack:
            while curr != None:
                stack.append(curr)
                curr = curr.left
            
            currNode = stack.pop()
            ans.append(currNode.val)
            
            curr = currNode.right
            
        return ans
        
        
        