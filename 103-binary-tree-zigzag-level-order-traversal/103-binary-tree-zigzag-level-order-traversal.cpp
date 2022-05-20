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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        return solve(root);
    }
private:
    vector<vector<int>> solve(TreeNode* root) {
        if(root == nullptr)
            return {};
        
        vector<vector<int>> result;
        
        queue<TreeNode*> queue;
        queue.push(root);
        int flag = true; // false means left -> right \\ true means right -> left
        
        while(!queue.empty()) {
            int levelSize = queue.size();
            vector<int> levelValues;
            while(levelSize--) {
                auto currNode = queue.front();
                queue.pop();
                levelValues.push_back(currNode -> val);
                if(currNode -> left != nullptr) 
                    queue.push(currNode -> left);
                     
                if(currNode -> right != nullptr) 
                    queue.push(currNode -> right);
                
            }
            // if flag is false then we have to s
            if(!flag)
                reverse(levelValues.begin(), levelValues.end());
            result.push_back(levelValues);
            flag = !flag;
        }
        return result;
     }
};