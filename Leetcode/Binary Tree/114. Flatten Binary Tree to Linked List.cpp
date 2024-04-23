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
    vector <TreeNode *> node;
    void flatten(TreeNode* root) {
        travarsePreOrder(root);
        node.push_back(NULL);

        for(int i = 0; i < node.size()-1; i++) {
            node[i]->left = NULL;
            node[i]->right = node[i+1];
        }
    }

    void travarsePreOrder(TreeNode * cur) {
        if(!cur) return;

        node.push_back(cur);
        travarsePreOrder(cur->left);
        travarsePreOrder(cur->right);
    }
};


