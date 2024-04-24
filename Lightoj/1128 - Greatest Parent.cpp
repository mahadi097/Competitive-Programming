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


ll n, lg = 21;
ll anc[SIZE][21];
ll a[SIZE];
vector <ll> adj[SIZE];
ll lvl[SIZE];

bool check(ll x, ll pos) {
    return ((x >> pos) && 1LL);
}

void dfs(ll u, ll p, ll d) {
    lvl[u] = d;
    anc[u][0] = p;

    ll i, v;
    for0(i, adj[u].size()) {
        v = adj[u][i];
        dfs(v, u, d+1);
    }
}

void lca_build() {
    ll i, j, p;

    for1(i, lg-1) {
        for1(j, n) {
            p = anc[j][i-1];
            if(p != -1) anc[j][i] = anc[p][i-1];
        }
    }
}

ll get_ancestor(ll u, ll val) {
    ll i, p, t = -1;

    for(i = lg-1; i >= 0; i--) {
        p = anc[u][i];
        if(p != -1) {
            if(a[p] >= val) u = p;
        }
    }

    return u;
}

int main() {
    ll t = 0, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0;
    string s, s1, s2;

    scl1(t);

    for1(i, t) {
        scl2(n, q);

        for1(j, n) adj[j].clear();

        a[1] = 1;
        for1(j, n-1) {
            scl2(x, y);
            adj[x+1].pb(j+1);
            a[j+1] = y;
        }

        ms(anc, -1);
        dfs(1, -1, 1);
        lca_build();

        printcase;

        while(q--) {
            scl2(x, y);
            ans = get_ancestor(x+1, y) - 1;
            printl(ans);
        }
    }

    return 0;
}
