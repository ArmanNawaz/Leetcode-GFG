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
    int getDecimalValue(ListNode* head) {
        return solve(head);
    }
private:
    int solve(ListNode* head){
        int ans = 0;
        ListNode* temp = head;
        
        // Traverse all the nodes
        while(temp != nullptr){
            
            // adding the node value at last bit of answer
            ans = (ans << 1) | (temp -> val);
            temp = temp -> next;
        }
        return ans;
    }
};