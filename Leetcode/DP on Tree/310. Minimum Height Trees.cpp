class Solution {
private:
    int minH;
    vector<int> height, mxDepth, mxDepth2;
    vector <vector<int>> adj;

    void init(int n, vector<vector<int>>& edges) {
        minH = 10001;
        height.resize(n);
        mxDepth.resize(n, 0), mxDepth2.resize(n, 0);

        adj.resize(n, vector<int>());
        for(auto edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
    }

    void dfs1(int u = 0, int p = 0) { // for calculating subtree
        for(auto v: adj[u]) {
            if(v == p) continue;
            dfs1(v, u);

            if((mxDepth[v] + 1) >= mxDepth[u]) {
                mxDepth2[u] = mxDepth[u];
                mxDepth[u] = mxDepth[v] + 1;
            }
            else if((mxDepth[v] + 1) > mxDepth2[u]) mxDepth2[u] = mxDepth[v] + 1;
        }
    }

    void dfs2(int u = 0, int p = 0, int toParentH = 0) { // rerooting every node to calculate height
        height[u] = max(toParentH, mxDepth[u]);
        minH = min(minH, height[u]);

        for(auto v: adj[u]) {
            if(v == p) continue;

            if((mxDepth[v] + 1) == mxDepth[u]) dfs2(v, u, max(toParentH, mxDepth2[u]) + 1);
            else dfs2(v, u, max(toParentH, mxDepth[u]) + 1);
        }
    }  

    vector<int> getMHTs(int n) {
        vector <int> mht;
        for(int i = 0; i < n; i++) {
            if(height[i] == minH) mht.push_back(i);
        }

        return mht;
    }

public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        init(n, edges);

        dfs1();
        dfs2();

        return getMHTs(n);
    }
};