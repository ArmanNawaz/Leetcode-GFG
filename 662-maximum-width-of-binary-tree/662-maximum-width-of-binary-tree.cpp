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
    int widthOfBinaryTree(TreeNode* root) {
        return solve(root);
    }
private:
    int solve(TreeNode* root) {
        int maxWidth = 1;
        
        queue<pair<TreeNode*, long long>> queue;
        queue.push({root, 0});
        
        while(!queue.empty()) {
            int levelSize = queue.size();
            int start = queue.front().second;
            int end = queue.back().second;
            
            maxWidth = max(maxWidth, end - start + 1);
                
            while(levelSize--) {
                auto currNode = queue.front();
                queue.pop();
                
                int idx = currNode.second - start;
                
                if(currNode.first -> left != nullptr)
                    queue.push({currNode.first -> left, (long long)2 * idx});
                if(currNode.first -> right != nullptr)
                    queue.push({currNode.first -> right, (long long)2 * idx + 1});
            }
        }
        return maxWidth;
        
    }
};