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
class Solution {
public:
    int maxDepth(TreeNode* root) {
        return solve(root);
        // return recursion(root);
    }
private:
    int solve(TreeNode* root) {
        if(root == nullptr) return 0;
        if(root -> left == nullptr && root -> right == nullptr) return 1;
        
        queue<TreeNode*> queue;
        
        queue.push(root);
        int depth = 0;
        
        while(!queue.empty()) {
            int levelSize = queue.size();
            ++depth;
            
            while(levelSize--) {
                auto curr = queue.front();
                queue.pop();
                
                if(curr -> left != nullptr) queue.push(curr -> left);
                if(curr -> right != nullptr) queue.push(curr -> right);
            }
        }
        return depth;
    }
    
    
    int recursion(TreeNode* root){
        if(root == nullptr) return 0;
        
        return 1 + max(recursion(root -> left), recursion(root -> right));
    }
};