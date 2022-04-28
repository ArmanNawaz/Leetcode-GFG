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
    int findBottomLeftValue(TreeNode* root) {
        return solve(root);
    }
private:
    int solve(TreeNode* root) {
        queue<TreeNode*> queue;
        queue.push(root);
        int ans = root -> val;
        
        while(!queue.empty()) {
            int levelSize = queue.size();
            
            for(int i = 0; i < levelSize; ++i) {
                auto currNode = queue.front();
                queue.pop();
                
                if(i == 0)
                    ans = currNode -> val;
                if(currNode -> left != nullptr) queue.push(currNode -> left);
                if(currNode -> right != nullptr) queue.push(currNode -> right);
            }
        }
        return ans;
    }
};