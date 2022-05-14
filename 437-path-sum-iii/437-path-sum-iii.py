# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __recurse(self, root, targetSum):
        if root == None:
            return
        
        self.__path.append(root.val)
        
        _sum = 0
        for i in range(len(self.__path) - 1, -1, -1):
            _sum += self.__path[i]
            if _sum == targetSum:
                self.__count += 1
        
        self.__recurse(root.left, targetSum)
        self.__recurse(root.right, targetSum)
        
        self.__path.pop()        
        
        
    def __bruteForce(self, root, targetSum):
        self.__count = 0
        self.__path = list()
        self.__recurse(root, targetSum)
        return self.__count
    
    
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        return self.__bruteForce(root, targetSum)
        