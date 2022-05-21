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
    int countNodes(TreeNode* root) {
        return solve(root);
    }
private:
    int solve(TreeNode* root) {
        if(root == nullptr)
            return 0;
        
        queue<TreeNode*> queue;
        queue.push(root);
        int count = 0;
        
        while(!queue.empty()) {
            auto currNode = queue.front();
            queue.pop();
            
            ++count;
            if(currNode -> left) queue.push(currNode -> left);
            if(currNode -> right) queue.push(currNode -> right);
        }
        return count;
    }
};