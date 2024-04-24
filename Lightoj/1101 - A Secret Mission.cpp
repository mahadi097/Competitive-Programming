#include <bits/stdc++.h>
using namespace std;


//TEMPLATE
#define pb              push_back
#define mp              make_pair
#define ll              long long
#define ld              long double
//#define pi              3.1415926536
#define pi              acos(-1)
//#define mod             1000000007
#define newline         printf("\n")
#define printminusone   printf("-1\n")
#define scl1(n)         scanf("%lld", &n)
#define scl2(a, b)      scanf("%lld %lld", &a, &b)
#define scl3(a, b, c)   scanf("%lld %lld %lld", &a, &b, &c)
#define printl(n)       printf("%lld\n", n)
#define ssl1(str)       scanf(" %[^\n]", str)
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
#define fori(itt, stt)  for(auto itt = stt.begin(); itt != stt.end(); itt++)
#define pii             pair <ll, ll>
#define piii            pair <ll, pii>
//#define SIZE            100005
//#define INF             1000000005
#define F               first
#define S               second
#define FR              ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ms(arr, x)      memset(arr, x, sizeof arr)
#define bitcount(n)     __builtin_popcountll(n)

const ll INF = LLONG_MAX;
const ll SIZE = 50000+5;
const ll mod = 1e9+7;


struct edge {
    ll u, v, w;
} road[100005];
vector <pii> adj[SIZE];
ll n, e;
ll par[SIZE];

bool cmp(edge a, edge b) {
    return (a.w < b.w);
}

ll Find(ll x) {
    if(par[x] == x) return x;
    return par[x] = Find(par[x]);
}

bool Union(ll a, ll b) {
    ll u = Find(a);
    ll v = Find(b);

    if(u != v) {
        par[v] = u;
        return 1;
    }
    return 0;
}

void kruskal() {
    sort(road+1, road+e+1, cmp);

    ll c = 0, i;
    bool ok;

    for1(i, n) {
        par[i] = i;
        adj[i].clear();
    }

    for1(i, e) {
        ok = Union(road[i].u, road[i].v);

        if(ok) {
            c++;
            adj[road[i].u].pb(mp(road[i].v, road[i].w));
            adj[road[i].v].pb(mp(road[i].u, road[i].w));
            if(c == n-1) break;
        }
    }
}

ll lg = 21;
ll anc[SIZE][21];
ll mx[SIZE][21];
ll lvl[SIZE];

bool check(ll x, ll pos) {
    return ((x >> pos) & 1LL);
}

void dfs(ll u, ll p, ll d, ll dan) {
    lvl[u] = d;
    anc[u][0] = p;
    mx[u][0] = dan;

    ll i, v, w;
    for0(i, adj[u].size()) {
        v = adj[u][i].F;
        w = adj[u][i].S;

        if(v == p) continue;

        dfs(v, u, d+1, w);
    }
}

void lca_build() {
    ll i, j, p;

    for1(i, lg-1) {
        for1(j, n) {
            p = anc[j][i-1];

            if(p != -1) {
                anc[j][i] = anc[p][i-1];
                mx[j][i] = max(mx[j][i-1], mx[p][i-1]);
            }
        }
    }
}

ll get_lca(ll u, ll v) {
    if(lvl[u] < lvl[v]) swap(u, v);

    ll i, diff = lvl[u] - lvl[v];
    ll res = -1;

    for0(i, lg) {
        if(check(diff, i)) {
            res = max(res, mx[u][i]);
            u = anc[u][i];
        }
    }

    if(u == v) return res;

    for(i = lg-1; i >= 0; i--) {
        if(anc[u][i] != anc[v][i] && anc[u][i] != -1) {
            res = max(res, max(mx[u][i], mx[v][i]));
            u = anc[u][i];
            v = anc[v][i];
        }
    }

    res = max(res, max(mx[u][0], mx[v][0]));
    return res;
}

int main() {
    ll t = 0, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0;
    string s, s1, s2;

    scl1(t);

    for1(i, t) {
        scl2(n, e);
        for1(j, e) scl3(road[j].u, road[j].v, road[j].w);

        kruskal();
        ms(anc, -1);
        ms(mx, -1);
        dfs(1, -1, 1, -1);
        lca_build();

        scl1(q);

        printcase;

        while(q--) {
            scl2(x, y);
            ans = get_lca(x, y);
            printl(ans);
        }
    }

    return 0;
}

