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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return channaSir(root, p, q);
        // return solve(root, p, q);
    }
private:
    // Channa Sir
    TreeNode* channaSir(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || root == p || root == q)
            return root;
        auto left = channaSir(root -> left, p, q);
        auto right = channaSir(root -> right, p, q);
        if(left == nullptr) return right;
        if(right == nullptr) return left;
        return root;
        
        
    }
    
    
    // Aakash Sir
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr)
            return nullptr;
        
        if(root -> val == p -> val || root -> val == q -> val)
            return root;
        
        auto left = solve(root -> left, p, q);
        auto right = solve(root -> right, p, q);
        
        if(left != nullptr and right != nullptr)
            return root;
        
        if(left != nullptr)
            return left;
        else
            return right;
    }
};