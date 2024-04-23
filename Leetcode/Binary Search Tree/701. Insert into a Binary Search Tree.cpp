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
    TreeNode *rootNode;

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        rootNode = root;
        solve(root, NULL, val, 0);

        return rootNode;
    }

    void solve(TreeNode *cur, TreeNode *prv, int val, int side) {
        if(!cur) {
            TreeNode *newNode = new TreeNode(val);

            if(prv) side == 1 ? prv->left = newNode : prv->right = newNode;
            else rootNode = newNode;

            return;
        }

        if(val < cur->val) solve(cur->left, cur, val, 1);
        else solve(cur->right, cur, val, 2);
    }
};
