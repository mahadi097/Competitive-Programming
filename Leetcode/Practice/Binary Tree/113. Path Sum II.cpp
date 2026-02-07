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
    vector <vector<int>> ans;

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector <int> v;
        solve(root, v, 0, targetSum);
        return ans;
    }

    void solve(TreeNode* cur, vector <int> &v, int sum, int tarSum) {
        if(!cur) return;

        v.push_back(cur->val);

        if(!cur->left and !cur->right and sum+cur->val == tarSum) ans.push_back(v);

        solve(cur->left, v, sum+cur->val, tarSum);
        solve(cur->right, v, sum+cur->val, tarSum);

        v.pop_back();
    }
};
