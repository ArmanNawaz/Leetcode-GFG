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
    vector<int> largestValues(TreeNode* root) {
        return solve(root);
    }
    
private:
    vector<int> solve(TreeNode* root) {
        if(root == nullptr)
            return {};
        queue<TreeNode*> queue;
        vector<int> ans;
        
        queue.push(root);
        
        while(!queue.empty()) {
            int levelSize = queue.size();
            int maxElem = INT_MIN;
            
            while(levelSize--) {
                auto currNode = queue.front();
                queue.pop();
                
                maxElem = max(maxElem, currNode -> val);
                
                if(currNode -> left != nullptr)
                    queue.push(currNode -> left);
                if(currNode -> right != nullptr)
                    queue.push(currNode -> right);
            }
            ans.push_back(maxElem);
        }
        return ans;
    }
};