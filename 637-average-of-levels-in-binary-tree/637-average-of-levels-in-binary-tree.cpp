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
    vector<double> averageOfLevels(TreeNode* root) {
        return solve(root);
    }
private:
    vector<double> solve(TreeNode* root) {
        queue<TreeNode*> queue;
        vector<double> ans;
        
        queue.push(root);
        
        while(!queue.empty()) {
            int levelSize = queue.size();
            double levelSum = 0;
            int n = levelSize;
            
            while(levelSize--) {
                auto currNode = queue.front();
                queue.pop();
                
                levelSum += currNode -> val;
                
                if(currNode -> left != nullptr)
                    queue.push(currNode -> left);
                if(currNode -> right != nullptr)
                    queue.push(currNode -> right);
            }
            ans.push_back(levelSum/n);
        }
        return ans;
    }
};