# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        if root == None:
            return []
        ans = []

        queue = deque()
        queue.append(root)

        while len(queue) > 0:
            levelSize = len(queue)

            for i in range(levelSize):
                curr = queue.popleft()
                if curr.left: queue.append(curr.left)
                if curr.right: queue.append(curr.right)

                if i == levelSize - 1:
                    ans.append(curr.val)
        return ans
        