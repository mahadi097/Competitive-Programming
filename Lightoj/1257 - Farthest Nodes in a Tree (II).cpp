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
#define fori(itt, stt)  for(itt = stt.begin(); itt != stt.end(); itt++)
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
const ll SIZE = 3e4+5;
const ll mod = 1e9+7;

vector <pii> adj[SIZE];
ll in[SIZE], out[SIZE];
ll dp[SIZE];

void clear_data() {
    ll i;
    for0(i, SIZE) adj[i].clear();
    ms(dp, 0);
    ms(in, 0);
    ms(out, 0);
}

void dfs1(ll u, ll p) {
    ll i, v, w;

    for0(i, adj[u].size()) {
        v = adj[u][i].F;
        w = adj[u][i].S;

        if(v == p) continue;

        dfs1(v, u);

        in[u] = max(in[u], w+in[v]);
    }
}

void dfs2(ll u, ll p) {
    ll i, v, w;
    ll mx, mx1 = -1, mx2 = -1;

    for0(i, adj[u].size()) {
        v = adj[u][i].F;
        w = adj[u][i].S;

        if(v == p) continue;

        if((in[v]+w) >= mx1) {
            mx2 = mx1;
            mx1 = in[v] + w;
        }
        else if((in[v]+w) > mx2) mx2 = in[v] + w;
    }

    for0(i, adj[u].size()) {
        v = adj[u][i].F;
        w = adj[u][i].S;

        if(v == p) continue;

        mx = mx1;
        if(mx == (in[v]+w)) mx = mx2;

        out[v] = max(w+out[u], w+mx);

        dfs2(v, u);
    }
}

int main() {
    ll t = 0, n, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0;
    scl1(t);

    for1(i, t) {
        clear_data();

        scl1(n);

        for1(j, n-1) {
            scl2(x, y);
            scl1(z);

            adj[x].pb(mp(y, z));
            adj[y].pb(mp(x, z));
        }

        dfs1(0, 0);
        dfs2(0, 0);

        printcase;
        for0(j, n) {
            dp[j] = max(in[j], out[j]);
//            cout << in[j] << " " << out[j] << endl;
            printl(dp[j]);
        }
    }

    return 0;
}
