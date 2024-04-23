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
    TreeNode *leftNode = NULL, *rightNode = NULL, *rootNode = NULL;

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;

        rootNode = root;

        solve(root, key, NULL, 0);

        if(!rootNode) return rootNode;

        if(!leftNode or !rightNode) return rootNode;

        solve2(leftNode);

        return rootNode;
    }

    void solve(TreeNode *cur, int key, TreeNode *parNode, int side) {
        if(!cur) return;

        if(cur->val == key) {
            if(!cur->left and !cur->right) {
                if(!parNode) rootNode = NULL;
                else {
                    if(side == 1) parNode->left = NULL;
                    else parNode->right = NULL;
                }
            }
            else if(cur->left and cur->right) {
                if(!parNode) rootNode = cur->left;
                else {
                    if(side == 1) parNode->left = cur->left;
                    else parNode->right = cur->left;
                }

                leftNode = cur->left;
                rightNode = cur->right;
            }
            else {
                if(cur->left) {
                    if(!parNode) rootNode = cur->left;
                    else {
                        if(side == 1) parNode->left = cur->left;
                        else parNode->right = cur->left;
                    }
                }
                else {
                    if(!parNode) rootNode = cur->right;
                    else {
                        if(side == 1) parNode->left = cur->right;
                        else parNode->right = cur->right;
                    }
                }
            }

            return;
        }

        solve(cur->left, key, cur, 1);
        solve(cur->right, key, cur, 2);
    }

    void solve2(TreeNode *cur) {
        if(!cur->right) {
            cur->right = rightNode;
            return;
        }

        solve2(cur->right);
    }
};
