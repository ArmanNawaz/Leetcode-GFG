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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        return solveBFS(root);
    }
private:
    vector<vector<int>> solveBFS(TreeNode* root) {
        queue<TreeNode*> queue;
        queue.push(root);
        vector<vector<int>> ans;  // Answer
        
        while(!queue.empty()) {
            
            int levelSize = queue.size();  // max number of elements in current level
            vector<int> currList;
            while(levelSize--) {
                
                auto curr = queue.front();
                queue.pop(); 
                
                currList.push_back(curr -> val);
                
                if(curr -> left) queue.push(curr->left);
                if(curr -> right) queue.push(curr->right);
            }
            
            ans.push_back(currList);
        }
        return ans;
    }
};







