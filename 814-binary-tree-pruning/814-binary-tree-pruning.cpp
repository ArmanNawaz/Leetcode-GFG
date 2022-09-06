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
    TreeNode* pruneTree(TreeNode* root) {
        return daily(root);
    }
private:
    TreeNode* daily(TreeNode* root) {
        if(root == nullptr) return root;
        
        root -> left = daily(root -> left);
        root -> right = daily(root -> right);
        
        if(root -> val == 1 || root -> left != nullptr || root -> right != nullptr)
            return root;
        
        return nullptr;
    }
};