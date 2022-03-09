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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head -> next == nullptr) return head;
        return solve(head);
        // return bruteforce(head);
    }
private:
    ListNode* bruteforce(ListNode* head) {
        
        map<int, int> hashMap;
        ListNode* temp = head;
        
        while(temp != nullptr) {
            hashMap[temp->val]++;
            temp = temp -> next;
        }
        
        ListNode* newHead = new ListNode(-1);
        temp = newHead;
        
        for(auto x: hashMap) {
            if(x.second == 1) {
                temp -> next = new ListNode(x.first);
                temp = temp->next;
            }
        }
        return newHead -> next;
    }
    ListNode* solve(ListNode* head) {
        
        ListNode* newHead = new ListNode(-1);
        newHead -> next = head;
        ListNode* temp = newHead;
        
        while(temp != nullptr && temp->next != nullptr) {
            
            bool isDuplicate = false;
            ListNode *t = temp -> next;
            
            while(t -> next != nullptr && t -> val == t -> next -> val) {
                t = t -> next;
                isDuplicate = true;
            }
            
            if(isDuplicate)
                temp -> next = t -> next;
            else
                temp = temp -> next;
                
        }
        return newHead -> next;
    }
};