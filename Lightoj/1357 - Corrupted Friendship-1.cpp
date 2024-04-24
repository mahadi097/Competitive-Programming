#include <bits/stdc++.h>
using namespace std;


//TEMPLATE
#define pb              push_back
#define mp              make_pair
#define ll              long long
#define ld              long double
#define pi              3.1415926536
#define mod             1000000007
#define newline         printf("\n")
#define printminusone   printf("-1\n")
#define scl1(n)         scanf("%lld", &n)
#define scl2(a, b)      scanf("%lld %lld", &a, &b)
#define printl(n)       printf("%lld\n", n)
#define scd1(n)         scanf("%lf", &n)
#define scd2(a, b)      scanf("%lf %lf", &a, &b)
#define printd(n)       printf("%lf\n", n)
#define printld(n)      printf("%Lf\n", n)
#define printcase       printf("Case %lld: ", i)
#define reversed(s)     reverse(s.begin(), s.end())
#define asorted(s)      sort(s.begin(), s.end())
#define dsorted(s)      sort(s.begin(), s.end(), cmp)
#define for0(i, n)      for (i = 0; i < n; i++)
#define for1(i, n)      for (i = 1; i <= n; i++)
#define pii             pair <ll, ll>
#define piii            pair <ll, pii>
#define SIZE            100005
#define INF             1000000005
#define F               first
#define S               second
#define FR              ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ms(arr, x)      memset(arr, x, sizeof arr)
#define bitcount(n)     __builtin_popcountll(n)

vector <ll> adj[SIZE];
ll dis[SIZE];
ll sub_tree[SIZE];
ll n;

void clear_data() {
    ll i;
    for1(i, n) {
        adj[i].clear();
        dis[i] = 0;
        sub_tree[i] = 0;
    }
}

void dfs(ll u, ll p) {
    sub_tree[u] = 1;

    ll i, v;

    for0(i, adj[u].size()) {
        v = adj[u][i];
        dfs(v, u);
        sub_tree[u] += sub_tree[v];
    }
}

void bfs() {
    dis[1] = 0;

    queue <ll> q;
    q.push(1);

    ll i, u, v;

    while(!q.empty()) {
        u = q.front();
        q.pop();

        for0(i, adj[u].size()) {
            v = adj[u][i];

            dis[v] = dis[u] + 1;
            q.push(v);
        }
    }
}

int main() {
    ll t = 0, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0;
    scl1(t);

    for1(i, t) {
        scl1(n);

        clear_data();

        for1(j, n-1) {
            scl2(x, y);
            adj[x].pb(y);
        }

        dfs(1, 1);

        bfs();

        ans = 0;

        for1(j, n) {
            p = sub_tree[j] + dis[j];
            ans += (n - p);
        }
        ans /= 2;

        printcase;
        printf("%lld %lld\n", n-1, ans);
    }

    return 0;
}

