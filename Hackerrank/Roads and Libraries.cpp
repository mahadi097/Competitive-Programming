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
bool vis[SIZE];
ll cr, cl;
ll city, road, cost, min_road;

void clear_data(ll n) {
    ll i;
    cost = 0;
    for1(i, n) {
        adj[i].clear();
        vis[i] = false;
    }
}

void dfs(ll n) {
    if(vis[n]) return;

    vis[n] = true;
    min_road++;

    ll i;
    for0(i, adj[n].size()) {
        dfs(adj[n][i]);
    }
}

int main() {
    ll t = 0, n, x, y, z, i, j, k, g, q, ans = 0, sum = 0;
    scl1(t);

    while(t--) {
        scl2(city, road);
        scl2(cl, cr);

        clear_data(city);

        for1(i, road) {
            scl2(x, y);

            adj[x].pb(y);
            adj[y].pb(x);
        }

        if(cl <= cr) {
            cost = city * cl;
            printl(cost);
            continue;
        }

        for1(i, city) {
            if(!vis[i]) {
                min_road = 0;
                cost += cl;

                dfs(i);

                min_road--;
                cost += (min_road * cr);
            }
        }
        printl(cost);
    }

    return 0;
}

