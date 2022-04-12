# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    
    def __init__(self, head: Optional[ListNode]):
        self.list = head
        
    def getRandom(self) -> int:
        head = self.list
        r = head.val
        n = 1
        head = head.next
        
        while head != None:
            if(random.randint(0, n) == 0):
                r = head.val
            head = head.next
            n += 1
        return r


# Your Solution object will be instantiated and called as such:
# obj = Solution(head)
# param_1 = obj.getRandom()