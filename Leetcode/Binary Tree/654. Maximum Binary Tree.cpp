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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return solve(nums, 0, nums.size()-1);
    }

    TreeNode *solve(vector <int> &v, int st, int en) {
        if(st > en) return NULL;

        int mx = -1, mxIn = -1;

        for(int i = st; i <= en; i++) if(mx < v[i]) mx = v[i], mxIn = i;

        TreeNode *node = new TreeNode(mx);

        node->left = solve(v, st, mxIn-1);
        node->right = solve(v, mxIn+1, en);

        return node;
    }
};
