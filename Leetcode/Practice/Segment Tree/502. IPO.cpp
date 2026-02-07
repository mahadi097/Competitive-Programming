class Solution {
private:
    int n;
    struct project {
        int p, c;
    };
    vector<project> a;

    int tree[300005];
    void build(int node, int r1, int r2) {
        if(r1 == r2) {
            tree[node] = r1;
            return;
        }

        int nodeL = node*2;
        int nodeR = nodeL + 1;
        int mid = (r1 + r2) / 2;

        build(nodeL, r1, mid);
        build(nodeR, mid+1, r2);

        int pL = a[tree[nodeL]].p;
        int pR = a[tree[nodeR]].p;

        tree[node] = (pL >= pR) ? tree[nodeL] : tree[nodeR];
    }

    int query(int node, int r1, int r2, int i, int j) {
        if(i > r2 or j < r1) return 0;
        if(r1 >= i and r2 <= j) return tree[node];

        int nodeL = node*2;
        int nodeR = nodeL + 1;
        int mid = (r1 + r2) / 2;

        int q1 = query(nodeL, r1, mid, i, j);
        int q2 = query(nodeR, mid+1, r2, i, j);

        int pL = a[q1].p, pR = a[q2].p;
        return pL >= pR ? q1 : q2;
    }

    void update(int node, int r1, int r2, int in) {
        if(in > r2 or in < r1) return;
        if(r1 >= in and r2 <= in) {
            tree[node] = 0;
            return;
        }

        int nodeL = node*2;
        int nodeR = nodeL + 1;
        int mid = (r1 + r2) / 2;

        update(nodeL, r1, mid, in);
        update(nodeR, mid+1, r2, in);

        int pL = a[tree[nodeL]].p;
        int pR = a[tree[nodeR]].p;

        tree[node] = (pL >= pR) ? tree[nodeL] : tree[nodeR];
    }

public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        n = profits.size();
        
        a.push_back({0, 0}); // for 1-based indexing
        for(int i = 0; i < n; i++) a.push_back({profits[i], capital[i]});

        sort(capital.begin(), capital.end());
        sort(a.begin()+1, a.end(), [](project p1, project p2) {
            return p1.c < p2.c;
        });

        build(1, 1, n);

        k = min(k, n);
        while(k--) {
            int r = upper_bound(capital.begin(), capital.end(), w) - capital.begin();
            int in = query(1, 1, n, 1, r);
     
            w += a[in].p;
            update(1, 1, n, in);
        }

        return w;
    }
};