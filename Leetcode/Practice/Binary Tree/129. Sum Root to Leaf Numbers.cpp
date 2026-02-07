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
    int sum = 0;

    int sumNumbers(TreeNode* root) {
        solve(root, 0);

        return sum;
    }

    void solve(TreeNode *cur, int v) {
        if(!cur) return;
        if(!cur->left and !cur->right) {
            int nowV = v * 10 + cur->val;
            sum += nowV;
            return;
        }

        solve(cur->left, (v*10)+cur->val);
        solve(cur->right, (v*10)+cur->val);
    }
};
