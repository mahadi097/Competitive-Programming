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
    TreeNode* balanceBST(TreeNode* root) {
        unbalancedBSTtoArray(root);

        sort(v.begin(), v.end());

        return arrayToBalancedBST(0, v.size()-1);
    }

    void unbalancedBSTtoArray(TreeNode *cur) {
        if(!cur) return;

        v.push_back(cur->val);

        unbalancedBSTtoArray(cur->left);
        unbalancedBSTtoArray(cur->right);
    }

     TreeNode *arrayToBalancedBST(int st, int en) {
        if(st > en) return NULL;

        int mid = (st + en) / 2;

        TreeNode *node = new TreeNode(v[mid]);

        node->left = arrayToBalancedBST(st, mid-1);
        node->right = arrayToBalancedBST(mid+1, en);

        return node;
    }
};
