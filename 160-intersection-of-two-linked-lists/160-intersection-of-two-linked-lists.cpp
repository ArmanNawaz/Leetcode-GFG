/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        return twoptr(headA, headB);
    }
private:
    ListNode *twoptr(ListNode *headA, ListNode *headB){
        int n = 0, m = 0;
        ListNode *ptr1, *ptr2;
        ptr1 = headA;
        ptr2 = headB;
        
        while(ptr1 != NULL){
            n++;
            ptr1 = ptr1 -> next;
        }
        
        while(ptr2 != NULL){
            m++;
            ptr2 = ptr2 -> next;
        }
        ptr1 = headA;
        ptr2 = headB;
        
        while(n > m){
            ptr1 = ptr1 -> next;
            n--;
        }
        
        while(m > n){
            ptr2 = ptr2 -> next;
            m--;
        }
        
        while(ptr1 != ptr2){
            ptr1 = ptr1 -> next;
            ptr2 = ptr2 -> next;
        }
        return ptr1;
        
    }
};