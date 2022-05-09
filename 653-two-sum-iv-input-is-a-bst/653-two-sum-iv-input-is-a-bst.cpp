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
    bool findTarget(TreeNode* root, int k) {
        return bruteForce(root, k);
    }
private:
    void inorder(TreeNode* root, vector<int>& arr) {
        if(root == nullptr)
            return;
        inorder(root -> left, arr);
        arr.push_back(root -> val);
        inorder(root -> right, arr);
    }
    
    bool bruteForce(TreeNode* root, int k) {
        vector<int> arr;
        inorder(root, arr);
        
        int n = arr.size();
        int i = 0, j = n - 1;
        
        while(i < j) {
            int sum = arr[i] + arr[j];
            if(sum < k)
                ++i;
            else if(sum > k) 
                --j;
            else
                return true;
        }
        return false;
    }
};