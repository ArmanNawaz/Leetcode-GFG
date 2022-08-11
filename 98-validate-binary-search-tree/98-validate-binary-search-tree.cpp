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
    bool isValidBST(TreeNode* root) {
        return bruteForce(root);
    }
private:   
    bool bruteForce(TreeNode* root) {
        vector<int> inorder;
        getInorder(root, inorder);
        
        for(int i = 0; i < inorder.size() - 1; ++i) {
            if(inorder[i] >= inorder[i + 1])
                return false;
        }
        return true;
    }
    
    void getInorder(TreeNode* root, vector<int>& inorder) {
        if(root) {
            getInorder(root -> left, inorder);
            inorder.push_back(root -> val);
            getInorder(root -> right, inorder);
        }
    }
    
    
    
    
    
    bool solve(TreeNode* root) {
        if(root == nullptr)
            return true;
         
        if((root -> left != nullptr && root -> val <= root -> left -> val) || (root -> right != nullptr && root -> val >= root -> right -> val))
            return false;
        
        return solve(root -> left) && solve(root -> right);
    }
};