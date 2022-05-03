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
    vector<int> inorderTraversal(TreeNode* root) {
        return solve(root);
    }
private:
    vector<int> solve(TreeNode* root) {
        stack<TreeNode*> stack;
        vector<int> ans;
        TreeNode* tmp = root;
        
        while(tmp != nullptr || !stack.empty()) {
            while(tmp != nullptr) {
                stack.push(tmp);
                tmp = tmp -> left;
            }
            tmp = stack.top();
            stack.pop();
            ans.push_back(tmp -> val);
            
            tmp = tmp -> right;
        }
        return ans;
    }
};