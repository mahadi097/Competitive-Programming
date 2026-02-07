class Solution {
private:
    int n;
    struct Basket {
        int cap, in;
    };
    vector<Basket> b;
    struct Pos {
        int mnIn, mnInPos;
    };
    vector<Pos> tree;

    void build(int node, int r1, int r2) {
        if (r1 == r2) {
            tree[node].mnIn = b[r1].in;
            tree[node].mnInPos = r1;
            return;
        }
        
        int nodeL = node * 2;
        int nodeR = nodeL + 1;
        int mid = (r1 + r2) / 2;

        build(nodeL, r1, mid);
        build(nodeR, mid+1, r2);

        if (tree[nodeL].mnIn < tree[nodeR].mnIn) tree[node] = tree[nodeL];
        else tree[node] = tree[nodeR];
    }

    Pos query(int node, int r1, int r2, int i, int j) {
        if (i > r2 or j < r1) return {n, n};
        if (r1 >= i and r2 <= j) return tree[node];

        int nodeL = node * 2;
        int nodeR = nodeL + 1;
        int mid = (r1 + r2)/ 2;

        auto qL = query(nodeL, r1, mid, i, j);
        auto qR = query(nodeR, mid+1, r2, i, j);

        if (qL.mnIn < qR.mnIn) return qL;
        else return qR;
    }

    void update(int node, int r1, int r2, int in) {
        if(in > r2 or in < r1) return;
        if(r1 >= in and r2 <= in) {
            tree[node].mnIn = n;
            tree[node].mnInPos = r1;
            return;
        }

        int nodeL = node * 2;
        int nodeR = nodeL + 1;
        int mid = (r1 + r2)/ 2;

        update(nodeL, r1, mid, in);
        update(nodeR, mid+1, r2, in);

        if (tree[nodeL].mnIn < tree[nodeR].mnIn) tree[node] = tree[nodeL];
        else tree[node] = tree[nodeR];
    }

public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        n = baskets.size();
        b.resize(n);
        tree.resize(n*4+5);

        for (int i = 0; i < n; i++) {
            b[i].cap = baskets[i];
            b[i].in = i;
        }

        sort(b.begin(), b.end(), [](Basket b1, Basket b2) {
            return b1.cap < b2.cap;
        });

        build(1, 0, n-1);

        int ans = 0;
        for (int f: fruits) {
           int in = lower_bound(b.begin(), b.end(), f, [](const Basket& b1, int value) {
                return b1.cap < value;
            }) - b.begin();

            if (in == n) { ans++; continue; }

            auto q = query(1, 0, n-1, in, n-1);

            if (q.mnIn == n) ans++;
            else update(1, 0, n-1, q.mnInPos);
        }

        return ans;
    }
};