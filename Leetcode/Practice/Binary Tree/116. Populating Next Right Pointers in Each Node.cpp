/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node *lvl[5000];

    Node* connect(Node* root) {
        solve(root, 0);

        return root;
    }

    void solve(Node *cur, int d) {
        if(!cur) return;

        if(lvl[d]) cur->next = lvl[d];
        lvl[d] = cur;

        solve(cur->right, d+1);
        solve(cur->left, d+1);
    }
};
