class Solution {
private:
    vector <int> dis, sub;
    vector <vector<int>> adj;

    void init(int n, vector<vector<int>>& edges) {
        dis.resize(n, 0);
        sub.resize(n, 1);
        adj.resize(n);

        for(auto edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
    } 

    void dfs1(int u = 0, int p = 0) {
        for(auto v: adj[u]) {
            if(v == p) continue;

            dfs1(v, u);
            sub[u] += sub[v];
            dis[u] += (dis[v] + sub[v]);
        }
    }

    void dfs2(int n, int u = 0, int p = 0) {
        if(u != 0) {
            int remNodes = n - sub[u];
            dis[u] += (dis[p] - dis[u] - sub[u]) + remNodes;
        }

        for(auto v: adj[u]) {
            if(v == p) continue;

            dfs2(n, v, u);
        }
    }

public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        init(n, edges);

        dfs1();
        dfs2(n);

        return dis;
    }
};