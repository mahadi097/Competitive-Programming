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
    vector<TreeNode*> generateTrees(int n) {
        vector <TreeNode *> roots;

        solve(roots, 0, n-1, NULL, 0, NULL, n);

        return roots;
    }

    bool check(int x, int pos) {
        return (x & (1 << pos));
    }

    int set1(int x, int pos) {
        return (x | (1 << pos));
    }

    void solve(vector <TreeNode *> &roots, int st, int en, TreeNode *prv, int msk, TreeNode *root, int n) {
        if(msk == (1<<n)-1) {
            roots.push_back(root);
            return;
        }
        if(st > en) return;

        for(int i = st; i <= en; i++) {
            int newMsk = msk;
            newMsk = set1(newMsk, i);
            TreeNode *cur = new TreeNode(i+1);

            if(!root) {
                root = cur;
                solve(roots, st, i-1, cur, newMsk, root, n);
                solve(roots, i+1, en, cur, newMsk, root, n);
                root = NULL;
                continue;
            }

            if(i < prv->val) {
                prv->left = cur;

                solve(roots, st, i-1, cur, newMsk, root, n);
                solve(roots, i+1, en, cur, newMsk, root, n);

                prv->left = NULL;
            }
            else {
                prv->right = cur;

                solve(roots, st, i-1, cur, newMsk, root, n);
                solve(roots, i+1, en, cur, newMsk, root, n);

                prv->right = NULL;
            }
        }
    }
};
