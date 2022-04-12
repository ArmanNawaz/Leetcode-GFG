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
    
public:
    Solution(ListNode* head) {
        list = head;
    }
    
    int getRandom() {
        auto head = list;
        int r = head -> val;
        int n = 1;
        head = head -> next;
        
        while(head) {
            if(rand() % (n + 1) == 0)
                r = head -> val;
            head = head -> next;
            ++n;
        }
        return r;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */