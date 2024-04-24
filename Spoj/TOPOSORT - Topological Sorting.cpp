#include <bits/stdc++.h>
using namespace std;


//TEMPLATE
#define pb              push_back
#define mp              make_pair
#define ll              long long
#define ld              long double
//#define pi              3.1415926536
#define pi              acos(-1)
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
#define printcase       printf("Case %lld: ", i)
#define reversed(s)     reverse(s.begin(), s.end())
#define asort(s)        sort(s.begin(), s.end())
#define dsort(s)        sort(s.rbegin(), s.rend())
#define for0(i, n)      for (i = 0; i < n; i++)
#define for1(i, n)      for (i = 1; i <= n; i++)
#define fori(itt, stt)  for(auto itt = stt.begin(); itt != stt.end(); itt++)
#define pii             pair <ll, ll>
#define piii            pair <ll, pii>
#define F               first
#define S               second
#define FR              ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ms(arr, x)      memset(arr, x, sizeof arr)
#define bitcount(n)     __builtin_popcountll(n)

const ll INF = LLONG_MAX;
const ll SZ = 1e4+5;
const ll mod = 1e9+7;


vector <ll> adj[SZ];
ll cycle(0), vis[SZ];
vector <ll> ts;

void topsort(ll u) {
    if(vis[u] == 2 || cycle) return;
    if(vis[u] == 1) {
        cycle = 1;
        return;
    }
    vis[u] = 1;

    ll i, v;
    for0(i, adj[u].size()) {
        v = adj[u][i];
        topsort(v);
    }
    vis[u] = 2;

    if(!cycle) ts.pb(u);
}

int main() {
    ll t = 0, n, m, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0;
    string s, s1, s2;

    scl2(n, m);

    for1(i, m) {
        scl2(x, y);
        adj[x].pb(y);
    }

    for1(i, n) dsort(adj[i]);

    for(i = n; i >= 1; i--) {
        if(!vis[i]) topsort(i);
    }

    if(cycle) puts("Sandro fails.");
    else {
        for(i = n-1; i >= 0; i--) cout << ts[i] << " ";
        newline;
    }

    return 0;
}

