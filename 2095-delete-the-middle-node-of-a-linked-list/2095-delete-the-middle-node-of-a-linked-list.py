# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def getLength(self, head):
        tmp = head
        n = 0
        
        while tmp != None:
            tmp = tmp.next
            n += 1
            
        return n
        
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        
        if head.next == None:
            return None
        
        n = self.getLength(head)
        mid = n // 2
        i = 0
        tmp = head
        
        while i < mid - 1:
            tmp = tmp.next
            i += 1
        
        tmp.next = tmp.next.next
        
        return head
        