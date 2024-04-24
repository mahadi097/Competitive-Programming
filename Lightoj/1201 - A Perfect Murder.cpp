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
#define printcase       printf("Case %lld: ", i)
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
const ll SIZE = 1e3+5;
const ll mod = 1e9+7;

bool vis[SIZE];
vector <ll> adj[SIZE];
ll dp[SIZE][2];

void dfs(ll u, ll p) {
    vis[u] = 1;

    ll i, v;
    ll child_nimu = 0, child_nimuna = 0;

    for0(i, adj[u].size()) {
        v = adj[u][i];

        if(v == p) continue;

        dfs(v, u);

        child_nimu += dp[v][0];
        child_nimuna += dp[v][1];
    }

    dp[u][1] = child_nimu;
    dp[u][0] = max(1+child_nimuna, child_nimu);
}

int main() {
    ll t = 0, n, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0;
    string s, s1, s2;

    scl1(t);

    for1(i, t) {
        scl2(n, c);

        ans = 0;
        for1(j, n) {
            adj[j].clear();
            dp[j][0] = dp[j][1] = 0;
            vis[j] = 0;
        }

        for1(j, c) {
            scl2(x, y);
            adj[x].pb(y);
            adj[y].pb(x);
        }

        for1(j, n) {
            if(!vis[j]) {
                dfs(j, j);
                ans += dp[j][0];
            }
        }

        printcase;
        printl(ans);
    }

    return 0;
}

