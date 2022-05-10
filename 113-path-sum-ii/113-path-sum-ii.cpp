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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        return solve(root, targetSum);
    }
private:
    void backtrack(TreeNode* root, int& targetSum, vector<int>& partialAns, vector<vector<int>>& ans) {
        if(root == nullptr)
            return;
        
        targetSum -= root -> val;
        partialAns.push_back(root -> val);
        
        if(root -> left == nullptr && root -> right == nullptr) {
            if(targetSum == 0)
                ans.push_back(partialAns);
            
            targetSum += root -> val;
            partialAns.pop_back();
            return;
        }
        
        
        if(root -> left) backtrack(root -> left, targetSum, partialAns, ans);
        if(root -> right) backtrack(root -> right, targetSum, partialAns, ans);
        
        partialAns.pop_back();
        targetSum += root -> val;
        return;
    }
    
    
    vector<vector<int>> solve(TreeNode* root, int targetSum) {
        vector<int> partialAns;
        vector<vector<int>> ans;
        
        backtrack(root, targetSum, partialAns, ans);
        
        return ans;
    }
}; 