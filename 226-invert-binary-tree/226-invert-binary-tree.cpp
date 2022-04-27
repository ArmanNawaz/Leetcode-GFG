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
    TreeNode* invertTree(TreeNode* root) {
        return solve(root);
    }
private:
    TreeNode* solve(TreeNode* root) {
        if(root == nullptr)
            return root;
        
        queue<TreeNode*> queue;
        queue.push(root);
        
        while(!queue.empty()) {
            int levelSize = queue.size();
            
            while(levelSize--) {
                auto currNode = queue.front();
                queue.pop();
                
                auto temp = currNode -> left;
                currNode -> left = currNode -> right;
                currNode -> right = temp;
                
                
                if(currNode -> left != nullptr) queue.push(currNode -> left);
                if(currNode -> right != nullptr) queue.push(currNode -> right);
            }
        }
        return root;
    }
};