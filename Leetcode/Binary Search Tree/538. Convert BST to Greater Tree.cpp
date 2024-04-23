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
    TreeNode* convertBST(TreeNode* root) {
        int tmp = solve(root, 0);
        return root;
    }

    int solve(TreeNode *curNode, int sumUp) {
    	if(!curNode) return 0;

        int t2 = solve(curNode->right, sumUp);
        int t1 = solve(curNode->left, sumUp+curNode->val+t2);

        int v = curNode->val;
        curNode->val += (sumUp + t2);

        return (t1 + v + t2);
    }
};


