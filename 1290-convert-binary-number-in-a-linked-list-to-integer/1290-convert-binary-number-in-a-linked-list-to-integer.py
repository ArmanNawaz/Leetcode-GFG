# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        ans = 0
        
        temp = head
        
        # Traverse all nodes of list
        while temp != None:
            
            # Add the bit at the last position of ans bit
            ans = (ans << 1) | temp.val
            temp = temp.next
        return ans