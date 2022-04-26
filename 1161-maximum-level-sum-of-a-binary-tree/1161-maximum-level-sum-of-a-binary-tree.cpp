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
    int maxLevelSum(TreeNode* root) {
        return solve(root);
    }
private:
    int solve(TreeNode* root) {
        queue<TreeNode*> queue;
        queue.push(root);
        
        int sum = INT_MIN;
        int level = 0;
        int maxLevel;
        
        while(!queue.empty()) {
            int levelSize = queue.size();
            int levelSum = 0;
            ++level;
            while(levelSize--) {
                auto currNode = queue.front();
                queue.pop();
                levelSum += currNode -> val;
                
                if(currNode -> left != nullptr)
                    queue.push(currNode -> left);
                
                if(currNode -> right != nullptr)
                    queue.push(currNode -> right);
            }
            if(levelSum > sum) {
                sum = levelSum;
                maxLevel = level;
            }
        }
        return maxLevel;
    }
};