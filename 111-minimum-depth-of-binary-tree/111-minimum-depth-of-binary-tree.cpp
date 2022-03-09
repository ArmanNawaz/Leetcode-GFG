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
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        return solve(root);
    }
private:
    int solve(TreeNode* root) {
        queue<TreeNode*> queue;
        queue.push(root);
        
        int depth = 0;
        while(!queue.empty()) {
            int levelSize = queue.size();
            
            ++depth;
            
            while(levelSize--) {
                auto curr = queue.front();
                queue.pop();
                
                if(curr -> left == nullptr && curr -> right == nullptr)
                    return depth;
                if(curr -> left) queue.push(curr -> left);
                if(curr -> right) queue.push(curr -> right);
            }
        }
        return 0;
    }
};