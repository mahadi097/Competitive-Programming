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
    int K, ans;

    int kthSmallest(TreeNode* root, int k) {
        K = k;
        solve(root);

        return ans;
    }

    void solve(TreeNode* root) {
        if(!root or !K) return;

        solve(root->left);

        if(K) {
            K--;
            if(!K) {
                ans = root->val;
                return;
            }

            solve(root->right);
        }
    }
};
