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
private: 
    TreeNode* solve(TreeNode* node, int target) {
        if(!node) return NULL;

        node->left = solve(node->left, target);
        node->right = solve(node->right, target);

        if(!node->left and !node->right and node->val == target) return NULL;

        return node;
    }

public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return solve(root, target);
    }
};