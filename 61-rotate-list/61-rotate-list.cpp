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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0) return head;
        if(head == nullptr || head -> next == nullptr) return head;
        
        return solve(head, k);
    }
private:
    int getLen(ListNode* head) {
        if(head == nullptr) return 0;
        if(head -> next == nullptr) return 0;
        
        ListNode* temp = head;
        int len = 0;
        while(temp != nullptr) {
            ++len;
            temp = temp -> next;
        }
        return len;
    }
    
    ListNode* rotate(ListNode* head) {
        
        ListNode *prev = head, *curr = head -> next;
        
        while(curr -> next != nullptr){
            prev = curr;
            curr = curr -> next;
        }
        curr -> next = head;
        prev -> next = nullptr;
        return curr;
    }
    
    ListNode* solve(ListNode* head, int k) {
        int len = getLen(head);
        
        k = k % len;
        ListNode* newHead = head;
        
        for(int i = 0; i < k; ++i)
            newHead = rotate(newHead);
        return newHead;
    }
};