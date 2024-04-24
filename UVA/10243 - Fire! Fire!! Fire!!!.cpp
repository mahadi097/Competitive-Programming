#include <bits/stdc++.h>
using namespace std;


//TEMPLATE
#define pb              push_back
#define mp              make_pair
#define ll              long long int
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
#define reversed(s)     reverse(s.begin(), s.end())
#define asorted(s)      sort(s.begin(), s.end())
#define dsorted(s)      sort(s.begin(), s.end(), descending_func)
#define for0(i, n)      for (i = 0; i < n; i++)
#define for1(i, n)      for (i = 1; i <= n; i++)
#define paired          pair <ll, ll>
#define pii             pair <ll, paired>
#define SIZE            1005
#define INF             1000000005
#define F               first
#define S               second

ll node;
vector <ll> adj[SIZE];
ll dp[SIZE][2];

ll dfs(ll n, ll p, ll covered) {
    if(dp[n][covered] != -1) return dp[n][covered];

    dp[n][covered] = covered;

    ll i, x;
    for0(i, adj[n].size()) {
        x = adj[n][i];

        if(x != p) {
            if(covered) dp[n][covered] += min(dfs(x, n, 1), dfs(x, n, 0));
            else dp[n][covered] += dfs(x, n, 1);
        }
    }
    return dp[n][covered];
}

int main() {
    ll t = 0, n, x, y, z, i, j, k, g, q, ans = 0, sum = 0, c = 0;

    while(scl1(node) && node) {
        ans = 1;
        for1(i, node) {
            dp[i][0] = -1;
            dp[i][1] = -1;
            adj[i].clear();
        }

        for1(i, node) {
            scl1(n);

            for1(j, n) {
                scl1(x);
                adj[i].pb(x);
            }
        }

        if(node == 1) {
            printl(ans);
            continue;
        }

        ans = min(dfs(1, 1, 1), dfs(1, 1, 0));
        printl(ans);
    }

    return 0;
}

