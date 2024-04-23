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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector <vector<int>> ans;
        if(!root) return ans;

        int curLvl = -1;
        vector <int> nodes;
        unordered_map <TreeNode*, int> lvl;
        queue <TreeNode*> q;
        TreeNode* cur = root;

        q.push(cur);

        while(!q.empty()) {
            auto node = q.front();
            q.pop();

//            cout << node->val << " " << lvl[node] << endl;

            if(lvl[node] != curLvl) {

                if(curLvl != -1) {
                    ans.push_back(nodes);
                    nodes.clear();
                }
                curLvl = lvl[node];
            }

            nodes.push_back(node->val);

            if(node->left) {
                lvl[node->left] = lvl[node] + 1;
                q.push(node->left);
            }
            if(node->right) {
                lvl[node->right] = lvl[node] + 1;
                q.push(node->right);
            }
        }
        ans.push_back(nodes);

        return ans;
    }
};
