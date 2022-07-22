/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *dummy1 = new ListNode(-1);
        ListNode *dummy2 = new ListNode(-1);
        if(head == nullptr || head->next == nullptr ) return head;
        ListNode *d1 = dummy1, *d2 = dummy2;
        
        ListNode* temp = head;
        while(temp!=nullptr){
            if(temp->val < x){
                d1->next = new ListNode(temp->val);
                d1 = d1->next;
            }
            else{
                d2->next = new ListNode(temp->val);
                d2 = d2->next;
            }
            temp = temp -> next;
        }
        
        d1->next = dummy2->next;
        return dummy1->next;
    }
};