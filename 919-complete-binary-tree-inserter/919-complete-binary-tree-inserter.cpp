/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class CBTInserter {
    TreeNode* root_;
public:
    CBTInserter(TreeNode* root) {
        root_ = root;
    }
    
    int insert(int val) {
        TreeNode* node = new TreeNode(val);
        
        queue<TreeNode*> queue;
        
        queue.push(root_);
        
        while(!queue.empty()) {
            auto currNode = queue.front();
            queue.pop();
            
            if(currNode -> left == nullptr){
                currNode -> left = node;
                return currNode -> val;
            }
            else
                queue.push(currNode -> left);
            
            if(currNode -> right == nullptr){
                currNode -> right = node;
                return currNode -> val;
            }
            else
                queue.push(currNode -> right);
                                    
        }
        return -1;
            
    }
    
    TreeNode* get_root() {
        return root_;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */