#include <bits/stdc++.h>
using namespace std;


//TEMPLATE
#define pb              push_back
#define mp              make_pair
#define ll              long long
#define ld              long double
#define pi              3.1415926536
//#define mod             1000000007
#define newline         printf("\n")
#define printminusone   printf("-1\n")
#define scl1(n)         scanf("%lld", &n)
#define scl2(a, b)      scanf("%lld %lld", &a, &b)
#define printl(n)       printf("%lld\n", n)
#define scd1(n)         scanf("%lf", &n)
#define scd2(a, b)      scanf("%lf %lf", &a, &b)
#define printd(n)       printf("%lf\n", n)
#define printld(n)      printf("%Lf\n", n)
#define printcase       printf("Case %lld:\n", i)
#define reversed(s)     reverse(s.begin(), s.end())
#define asorted(s)      sort(s.begin(), s.end())
#define dsorted(s)      sort(s.begin(), s.end(), cmp)
#define for0(i, n)      for (i = 0; i < n; i++)
#define for1(i, n)      for (i = 1; i <= n; i++)
#define pii             pair <ll, ll>
#define piii            pair <ll, pii>
//#define SIZE            100005
//#define INF             1000000005
#define F               first
#define S               second
#define FR              ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ms(arr, x)      memset(arr, x, sizeof arr)
#define bitcount(n)     __builtin_popcountll(n)

const ll INF = 1e18;
const ll SIZE = 1e5+5;
const ll mod = 1e9+7;

vector <ll> adj[SIZE];
ll s[SIZE], salary[SIZE];
ll st[SIZE], en[SIZE];
ll idx;
ll tree_sum[SIZE*4], tree_min[SIZE*4];
ll lazy[SIZE*4];

void dfs(ll u) {
    st[u] = ++idx;
    salary[idx] = s[u];

    ll i, v;
    for0(i, adj[u].size()) {
        v = adj[u][i];
        dfs(v);
    }
    en[u] = idx;
}

void build(ll node, ll r1, ll r2) {
    if(r1 == r2) {
        tree_min[node] = salary[r1];
        tree_sum[node] = salary[r1];
        lazy[node] = 0;
        return;
    }

    ll bam = node*2;
    ll dan = bam + 1;

    ll mid = (r1 + r2) / 2;

    build(bam, r1, mid);
    build(dan, mid+1, r2);

    tree_min[node] = min(tree_min[bam], tree_min[dan]);
    tree_sum[node] = tree_sum[bam] + tree_sum[dan];
    lazy[node] = 0;
}

void propagate(ll node, ll r1, ll r2) {
    tree_sum[node] += (r2 - r1 + 1) * lazy[node];
    tree_min[node] += lazy[node];

    if(r1 != r2) {
        lazy[node*2] += lazy[node];
        lazy[node*2+1] += lazy[node];
    }
    lazy[node] = 0;
}

void update(ll node, ll r1, ll r2, ll i, ll j, ll val) {
    ll bam = node*2;
    ll dan = bam + 1;

    if(lazy[node]) propagate(node, r1, r2);
    if(r1 > j || r2 < i) return;
    if(r1 >= i && r2 <= j) {
        tree_sum[node] += (r2 - r1 + 1) * val;
        tree_min[node] += val;

        if(r1 != r2) {
            lazy[bam] += val;
            lazy[dan] += val;
        }
        return;
    }

    ll mid = (r1 + r2) / 2;

    update(bam, r1, mid, i, j, val);
    update(dan, mid+1, r2, i, j, val);

    tree_sum[node] = tree_sum[bam] + tree_sum[dan];
    tree_min[node] = min(tree_min[bam], tree_min[dan]);
}

ll query_sum(ll node, ll r1, ll r2, ll i, ll j) {
    ll bam = node*2;
    ll dan = bam + 1;

    if(lazy[node]) propagate(node, r1, r2);
    if(r1 > j || r2 < i) return 0;
    if(r1 >= i && r2 <= j) return tree_sum[node];

    ll mid = (r1 + r2) / 2;

    ll p1 = query_sum(bam, r1, mid, i, j);
    ll p2 = query_sum(dan, mid+1, r2, i, j);

    return(p1+p2);
}

ll query_min(ll node, ll r1, ll r2, ll i, ll j) {
    ll bam = node*2;
    ll dan = bam + 1;

    if(lazy[node]) propagate(node, r1, r2);
    if(r1 > j || r2 < i) return INF;
    if(r1 >= i && r2 <= j) return tree_min[node];

    ll mid = (r1 + r2) / 2;

    ll p1 = query_min(bam, r1, mid, i, j);
    ll p2 = query_min(dan, mid+1, r2, i, j);

    return min(p1, p2);
}

int main() {
    ll t = 0, n, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0;
    scl1(t);

    for1(i, t) {
        scl2(n, q);

        idx = 0;
        for1(j, n) adj[j].clear();

        for1(j, n) {
            scl2(p, s[j]);

            if(j == 1) continue;
            adj[p].pb(j);
        }

        dfs(1);
        build(1, 1, n);

        printcase;
        while(q--) {
            scl2(c, x);

            if(c == 1) {
                ans = query_sum(1, 1, n, st[x], en[x]);
                printl(ans);
            }
            else {
                c = query_min(1, 1, n, st[x], en[x]);
                c = min(c, 1000LL);
                update(1, 1, n, st[x], en[x], c);
            }
        }
    }

    return 0;
}

