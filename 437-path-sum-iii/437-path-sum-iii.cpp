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
    int pathSum(TreeNode* root, int targetSum) {
        return bruteForce(root, targetSum);
    }
private:
    void recurse(TreeNode* root, int targetSum, int& count, vector<int>& path) {
        // base case
        if(root == nullptr)
            return;        
        
        path.push_back(root -> val);
        
        unsigned long int sum = 0;
        for(int i = path.size() - 1; i >= 0; --i) {
            sum += path[i];
            if(sum == targetSum)
                ++count;
        }
        recurse(root -> left, targetSum, count, path);
        recurse(root -> right, targetSum, count, path);
        
        path.pop_back();
    }
    
    
    
    int bruteForce(TreeNode* root, int targetSum) {
        int count = 0;
        vector<int> path;
        recurse(root, targetSum, count, path);
        return count;
    }
};