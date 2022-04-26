# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class CBTInserter:
    
    def __init__(self, root: Optional[TreeNode]):
        self.root = root

    def insert(self, val: int) -> int:
        queue = deque()
        queue.append(self.root)
        
        node = TreeNode(val)
        
        while queue:
            currNode = queue.popleft()
            
            if currNode.left == None:
                currNode.left = node
                return currNode.val
            else:
                queue.append(currNode.left)
                
            if currNode.right == None:
                currNode.right = node
                return currNode.val
            else:
                queue.append(currNode.right)
            
            
    def get_root(self) -> Optional[TreeNode]:
        return self.root


# Your CBTInserter object will be instantiated and called as such:
# obj = CBTInserter(root)
# param_1 = obj.insert(val)
# param_2 = obj.get_root()