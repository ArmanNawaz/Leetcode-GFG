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
    int sumRootToLeaf(TreeNode* root) {
        return solve(root, 0);
    }
private:
    int solve(TreeNode* root, int sum) {
        // Base case
        if(root == nullptr)
            return 0;
        //
        
        int rootValue = (sum << 1) | root-> val;
        if(root -> left == nullptr && root -> right == nullptr)
            return rootValue;
        
        return solve(root -> left, rootValue) + solve(root -> right, rootValue);
        
    }
};