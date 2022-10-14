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
    ListNode* deleteMiddle(ListNode* head) {
        if(head -> next == nullptr) {
            head = nullptr;
            return head;
        }
        
        int n = getLength(head);
        int mid = n / 2;
        int i = 0;
        auto tmp = head;
        
        while(i < mid - 1) {
            tmp = tmp -> next;
            ++i;
        }
        
        tmp -> next = tmp -> next -> next;
        return head;
    }
private:
    int getLength(ListNode* head) {
        auto tmp = head;
        int n = 0;
        
        while(tmp != nullptr) {
            tmp = tmp -> next;
            ++n;
        }
        return n;
    }
};