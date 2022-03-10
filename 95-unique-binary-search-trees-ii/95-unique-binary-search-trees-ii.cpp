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
    vector<TreeNode*> generateTrees(int n) {
        return solve(1, n);
    }
private:
    vector<TreeNode*> solve(int i, int j) {
        vector<TreeNode*> result;

        if(i > j) {
            result.push_back(nullptr);
            return result;
        }
        for(int k = i; k <= j; ++k) {
            auto left = solve(i, k-1);
            auto right = solve(k+1, j);
            for(int i1 = 0; i1 < left.size(); ++i1) {
                for(int i2 = 0; i2 < right.size(); ++i2) {
                    auto tree = new TreeNode(k);
                    tree -> left = left[i1];
                    tree -> right = right[i2];
                    result.push_back(tree);
                }
            }
        }
        return result;
    }
};