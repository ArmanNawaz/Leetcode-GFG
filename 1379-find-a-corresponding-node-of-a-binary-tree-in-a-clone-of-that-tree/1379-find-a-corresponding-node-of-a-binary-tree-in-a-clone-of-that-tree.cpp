/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return solve(cloned, target -> val);
    }
private:
    TreeNode* solve(TreeNode* root, int target) {
        if(root == nullptr)
            return nullptr;
        if(root -> val == target)
            return root;
        
        auto left = solve(root -> left, target);
        auto right = solve(root -> right, target);
        
        if(left == nullptr)
            return right;
        return left;
    }
};