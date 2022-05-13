"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if root == None:
            return root
        
        queue = deque()
        queue.append(root)
        
        while queue:
            levelSize = len(queue)
            
            for i in range(levelSize):
                currNode = queue.popleft()
                
                if currNode.left: queue.append(currNode.left)
                if currNode.right: queue.append(currNode.right)
                    
                if i != levelSize - 1:
                    currNode.next = queue[0]
        return root