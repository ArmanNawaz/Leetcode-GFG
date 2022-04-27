/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        return solve(root);
    }
private:
    Node* solve(Node* root) {
        if(root == nullptr)
            return root;
        queue<Node*> queue;
        queue.push(root);
        
        while(!queue.empty()) {
            int levelSize = queue.size();
            while(levelSize--) {
                auto currNode = queue.front();
                queue.pop();
                if(levelSize == 0) 
                    currNode -> next = nullptr;
                else 
                    currNode -> next = queue.front();
                
                if(currNode -> left != nullptr)
                    queue.push(currNode -> left);

                if(currNode -> right != nullptr)
                    queue.push(currNode -> right);
            }
        }
        return root;
    }
};