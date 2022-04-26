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
    bool isCompleteTree(TreeNode* root) {
        return solve(root);
    }
private:
    bool solve(TreeNode* root) {
        queue<TreeNode*> queue;
        queue.push(root);
        
        while(!queue.empty()) {
            int levelSize = queue.size();
            
            while(levelSize--) {
                auto currNode = queue.front();
                queue.pop();
                if(currNode == nullptr){
                    if(!queue.empty() && queue.front() != nullptr){
                        return false;
                    }
                }
                else{
                    queue.push(currNode -> left);
                    queue.push(currNode -> right);
                }
            }
        }
        return true;
    }
};