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
const ll SIZE = 1e5+5;
const ll mod = 1e9+7;

const ll lg = 19;
ll n;
vector <pii> adj[SIZE];
ll anc[SIZE][lg];
ll mx[SIZE][lg], mn[SIZE][lg];
ll lvl[SIZE];

bool check(ll x, ll pos) {
    return ((x >> pos) & 1LL);
}

void dfs(ll u, ll p, ll d, ll r) {
    lvl[u] = d;
    anc[u][0] = p;
    mx[u][0] = r;
    mn[u][0] = r;

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
                mn[j][i] = min(mn[j][i-1], mn[p][i-1]);
            }
        }
    }
}

pii get_lca(ll u, ll v) {
    if(lvl[u] < lvl[v]) swap(u, v);

    ll i, diff = lvl[u] - lvl[v];
    ll mnn = INF, mxx = -INF;

    for0(i, lg) {
        if(check(diff, i)) {
            mxx = max(mxx, mx[u][i]);
            mnn = min(mnn, mn[u][i]);
            u = anc[u][i];
        }
    }

    if(u == v) return mp(mnn, mxx);

    for(i = lg-1; i >= 0; i--) {
        if(anc[u][i] != anc[v][i] && anc[u][i] != -1) {
            mxx = max(mxx, max(mx[u][i], mx[v][i]));
            mnn = min(mnn, min(mn[u][i], mn[v][i]));
            u = anc[u][i];
            v = anc[v][i];
        }
    }

    if(anc[u][0] != -1) {
        mxx = max(mxx, mx[u][0]);
        mnn = min(mnn, mn[u][0]);
    }
    if(anc[v][0] != -1) {
        mxx = max(mxx, mx[v][0]);
        mnn = min(mnn, mn[v][0]);
    }

    return mp(mnn, mxx);
}

int main() {
    ll t = 0, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0;
    string s, s1, s2;

    scl1(t);

    for1(i, t) {
        scl1(n);

        for1(j, n) adj[j].clear();
        ms(anc, -1);
//        ms(mx, -1);
//        ms(mn, -1);

        for1(j, n-1) {
            scl3(x, y, z);
            adj[x].pb(mp(y, z));
            adj[y].pb(mp(x, z));
        }

        dfs(1, -1, 1, 0);
        lca_build();

        scl1(q);

        printcase;

        while(q--) {
            scl2(x, y);
            pii pp = get_lca(x, y);

            printf("%lld %lld\n", pp.F, pp.S);
        }
    }

    return 0;
}

