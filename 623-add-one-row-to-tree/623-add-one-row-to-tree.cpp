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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        return solve(root, val, depth);
    }
private:
    TreeNode* solve(TreeNode* root, int val, int depth) {
        queue<TreeNode*> queue;
        queue.push(root);
        
        
        // if depth is 1 then new root will be changed to given val
        if(depth == 1) {
            TreeNode* newRoot = new TreeNode(val, root, nullptr);
            return newRoot;
        }
        
        int currDepth = 0;
        
        // is addition of row done
        bool isDone = false;
        
        while(!queue.empty() || !isDone) {
            int levelSize = queue.size();
            ++currDepth;
            while(levelSize--) {
                auto currNode = queue.front();
                queue.pop();
                
                // if the next level is the required depth
                if(currDepth == depth - 1) {
                    // creating tree nodes
                    TreeNode* leftNode = new TreeNode(val);
                    TreeNode* rightNode = new TreeNode(val);
                    
                    // preserving the left and right subtree
                    if(currNode -> left) leftNode -> left = currNode -> left;
                    if(currNode -> right) rightNode -> right = currNode -> right;
                    
                    // assigning new row to the left and right pointers
                    currNode -> left = leftNode;
                    currNode -> right = rightNode;
                    isDone = true;
                }
                if(currNode -> left) queue.push(currNode -> left);
                if(currNode -> right) queue.push(currNode -> right);
            }
        }
        return root;
    }
};