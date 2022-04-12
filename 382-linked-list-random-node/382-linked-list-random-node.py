# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    
    def __init__(self, head: Optional[ListNode]):
        self.list = head
        n = 0
        
        while head:
            head = head.next;
            n += 1
        self.n = n
        
    def getRandom(self) -> int:
        idx = random.randint(0, self.n - 1)
        head = self.list
        
        while idx > 0:
            head = head.next
            idx -= 1
        return head.val


# Your Solution object will be instantiated and called as such:
# obj = Solution(head)
# param_1 = obj.getRandom()