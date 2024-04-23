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
    vector <vector<int>> res;
    queue<int> lvlOdd[2005];
    stack<int> lvlEven[2005];

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        traverse(root, 1);

        for(int i = 1; i <= 2000; i++) {
            vector <int> tmp;

            if(i & 1) {
                if(lvlOdd[i].empty()) break;

                while(!lvlOdd[i].empty()) {
                    int v = lvlOdd[i].front();
                    tmp.push_back(v);
                    lvlOdd[i].pop();
                }
            }
            else {
                if(lvlEven[i].empty()) break;

                while(!lvlEven[i].empty()) {
                    int v = lvlEven[i].top();
                    tmp.push_back(v);
                    lvlEven[i].pop();
                }
            }

            if(tmp.empty()) break;

            res.push_back(tmp);
        }

        return res;
    }

    void traverse(TreeNode *cur, int lvl) {
        if(!cur) return;

        if(lvl & 1) lvlOdd[lvl].push(cur->val);
        else lvlEven[lvl].push(cur->val);

        traverse(cur->left, lvl+1);
        traverse(cur->right, lvl+1);
    }
};
