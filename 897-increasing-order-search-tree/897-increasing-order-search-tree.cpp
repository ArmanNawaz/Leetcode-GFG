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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* newRoot = new TreeNode(-1);
        TreeNode* temp = newRoot;
        
        solve(root, temp);
        return newRoot -> right;
    }
private:
    // Daily
    void solve(TreeNode* root, TreeNode*& newRoot) {
        if(root == nullptr)
            return;
        solve(root -> left, newRoot);
        
        newRoot -> right = new TreeNode(root -> val);
        newRoot = newRoot -> right;
        
        solve(root -> right, newRoot);
    }
};