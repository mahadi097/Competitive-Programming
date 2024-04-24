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
const ll SIZE = 50005;
const ll mod = 1e9+7;

set <ll> s;
set <ll> :: iterator it;
vector <ll> adj[SIZE];
ll n, path[SIZE], par[SIZE];
bool vis[SIZE], ok[SIZE];
ll dis[SIZE];

void bfs() {
    ms(dis, 0);
    ms(vis, 0);
    ms(par, 0);

    dis[path[1]] = 0;
    vis[path[1]] = 1;
    par[path[1]] = path[1];

    queue <ll> q;
    q.push(path[1]);

    ll u, v, i;

    while(!q.empty()) {
        u = q.front();
        q.pop();

        for0(i, adj[u].size()) {
            v = adj[u][i];

            if(vis[v]) continue;

            vis[v] = 1;
            dis[v] = dis[u] + 1;
            par[v] = u;
            q.push(v);
        }
    }
}

int main() {
    ll t = 0, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0;
    scl1(t);

    for1(i, t) {
        s.clear();
        ms(ok, 0);

        scl1(n);

        for1(j, n) {
            scl1(path[j]);
            s.insert(path[j]);
        }

        for(it = s.begin(); it != s.end(); it++) adj[*it].clear();

        for(j = 2; j <= n; j++) {
            adj[path[j-1]].pb(path[j]);
            adj[path[j]].pb(path[j-1]);
        }

        for1(j, n) {
            if(ok[path[j]]) continue;

            asorted(adj[path[j]]);
            ok[path[j]] = 1;
        }

        bfs();

        p = path[n];
        vector <ll> ways;

        while(par[p] != p) {
            ways.pb(p);
            p = par[p];
        }
        ways.pb(path[1]);

        printcase;
        c = ways.size();
        for(j = c-1; j >= 0; j--) {
            if(j == 0) printf("%lld\n", ways[j]);
            else printf("%lld ", ways[j]);
        }
    }

    return 0;
}

