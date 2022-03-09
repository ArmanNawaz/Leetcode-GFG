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
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr)
            return {};
        return solve(root);
    }
private:
    vector<int> solve(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> queue;
        queue.push(root);
        
        while(!queue.empty()) {
            int levelSize = queue.size();
            
            for(int i = 0; i < levelSize; ++i) {
                auto curr = queue.front();
                queue.pop();
                if(curr -> left) queue.push(curr -> left);
                if(curr -> right) queue.push(curr -> right);
                if(i == levelSize - 1) ans.push_back(curr -> val);
            }
        }
        return ans;
    }
};