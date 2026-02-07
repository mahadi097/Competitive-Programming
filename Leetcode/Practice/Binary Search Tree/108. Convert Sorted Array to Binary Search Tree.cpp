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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(nums, 0, nums.size()-1);
    }

    TreeNode *solve(vector <int> a, int st, int en) {
        if(st > en) return NULL;
        int mid = (st + en) / 2;
        TreeNode *curRoot = new TreeNode(a[mid]);

        curRoot->left = solve(a, st, mid-1);
        curRoot->right = solve(a, mid+1, en);

        return curRoot;
    }
};
