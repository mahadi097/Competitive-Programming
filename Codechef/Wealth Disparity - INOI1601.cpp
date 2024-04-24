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
#define SIZE            100005
#define INF             1000000005

vector <ll> adj[SIZE];
ll a[SIZE];
ll node, st_node;
ll ans;

void dfs(ll n, ll maxi) {
    maxi = max(maxi, a[n]);
    ans = max(ans, maxi-a[n]);

    ll i, x;
    for0(i, adj[n].size()) {
        x = adj[n][i];

        dfs(x, maxi);
    }
}

int main() {
    ll t = 0, n, x, y, z, i, j, k, g, sum = 0, maxi = -INF;

    scl1(node);

    for1(i, node) scl1(a[i]);
    for1(i, node) {
        scl1(x);

        if(x == -1) {
            st_node = i;
            continue;
        }

        adj[x].pb(i);
    }

    dfs(st_node, maxi);

    printl(ans);

    return 0;
}

