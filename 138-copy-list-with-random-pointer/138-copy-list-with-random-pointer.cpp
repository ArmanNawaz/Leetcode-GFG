/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* orig = head;
        
        if(head == nullptr) return nullptr;
        
        // Step 1
        // Create duplicate nodes in original list
        while(orig != nullptr){
            Node* newNode = new Node(orig -> val);
            newNode -> next = orig -> next;
            orig -> next = newNode;
            orig = newNode -> next;
        }
        
        // Step 2
        // Update random pointers
        Node* temp = head;
        while(temp!=nullptr){
            if(temp -> random != nullptr)
                temp -> next -> random = temp -> random -> next;
            else
                temp -> next -> random = nullptr;
            temp = temp -> next -> next;
        }
        
        // Step 3
        // Separate both the lists
        Node* result = head -> next;
        orig = head;
        temp = result;
        while(orig != nullptr){
            orig -> next = orig -> next -> next;
            if(temp -> next == nullptr)
                temp -> next = nullptr;
            else
                temp -> next = temp -> next -> next;
            orig = orig -> next;
            temp = temp -> next;
        }
        
        return result;
        
    }
};