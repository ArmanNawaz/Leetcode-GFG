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
    ListNode* list;
    int n;
    
public:
    Solution(ListNode* head) {
        list = head;
        
        n = 0;
        // Find length of list
        while(head != nullptr){
            head = head -> next;
            ++n;
        }
    }
    
    int getRandom() {
        int idx = rand() % n;
        auto head = list;
        
        while(idx-- > 0) {
            head = head -> next;
        }
        return head -> val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */