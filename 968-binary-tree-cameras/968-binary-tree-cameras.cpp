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
    int minCameraCover(TreeNode* root) {
        return daily(root);
    }
private:
    // 1 -> Its leaf, camera needs to be installed on its parent
    // 0 -> camera present, leaf's parent
    // -1 -> already covered
    
    int dfs(TreeNode* root, int& count) {
        if(root == nullptr)
            return -1;
        
        int left = dfs(root -> left, count);
        int right = dfs(root -> right, count);
        
        if(left == 1 || right == 1) {
            ++count;
            return 0;
        }
        if(left == 0 || right == 0)
            return -1;
        return 1;
        
    }
    
    int daily(TreeNode* root) {
        int count = 0;
        int isLeaf = dfs(root, count);
        if(isLeaf == 1)
            ++count;
        return count;
    }
};