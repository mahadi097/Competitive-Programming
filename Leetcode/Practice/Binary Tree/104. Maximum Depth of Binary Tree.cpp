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
    int maxDepth(TreeNode* root) {
      return solve(root, 1);
    }

    int solve(TreeNode *cur, int depth) {
      if(!cur) return depth-1;

      int leftDepth = solve(cur->left, depth+1);
      int rightDepth = solve(cur->right, depth+1);

      return max(leftDepth, rightDepth);
    }
};