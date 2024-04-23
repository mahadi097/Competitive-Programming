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
    vector <int> v;
    bool done[105] = {0};

    vector<int> rightSideView(TreeNode* root) {
        solve(root, 0);

        return v;
    }

    void solve(TreeNode *cur, int d) {
        if(!cur) return;

        if(!done[d]) {
            done[d] = 1;
            v.push_back(cur->val);
        }

        solve(cur->right, d+1);
        solve(cur->left, d+1);
    }
};
