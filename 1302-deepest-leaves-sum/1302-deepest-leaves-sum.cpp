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
    int deepestLeavesSum(TreeNode* root) {
        return solve(root);
    }
private:
    int solve(TreeNode* root) {
        int sum = 0;
        queue<TreeNode*> queue;
        queue.push(root);
        
        while(!queue.empty()) {
            int levelSize = queue.size();
            int nodeVal = 0;
            bool flag = true;
            
            while(levelSize--) {
                auto currNode = queue.front();
                queue.pop();
                
                nodeVal += currNode -> val;
                if(currNode -> left != nullptr) {
                    queue.push(currNode -> left);
                    flag = false;
                }
                
                if(currNode -> right != nullptr) {
                    queue.push(currNode -> right);
                    flag = false;
                }
            }
            if(flag)
                sum += nodeVal;
        }
        return sum;
    }
};