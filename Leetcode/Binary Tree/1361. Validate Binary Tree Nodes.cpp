class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector <bool> vis(n, 0);
        queue <int > q;
        q.push(0);
        vis[0] = 1;

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            int leftNode = leftChild[u];
            int rightNode = rightChild[u];

            if(leftNode != -1) {
                if(vis[leftNode]) return 0;

                vis[leftNode] = 1;
                q.push(leftNode);
            }

            if(rightNode != -1) {
                if(vis[rightNode]) return 0;

                vis[rightNode] = 1;
                q.push(rightNode);
            }
        }

        for(int i = 0; i < n; i++) if(!vis[i]) return 0;

        return 1;
    }
};


