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
#define pii             pair <ll, ll>
#define piii            pair <ll, pii>
#define SIZE            105
#define INF             1000000005
#define F               first
#define S               second

ll city;
vector <piii> adj[SIZE];
ll c1, c2;

void dfs1(ll n, ll p) {
    if(n == 1) return;

    ll i, v, cost, st;

    for0(i, adj[n].size()) {
        v = adj[n][i].first;

        if(v != p) {
            st = adj[n][i].second.first;
            cost = adj[n][i].second.second;

            if(st == 2) {
                c1 += cost;
            }
            dfs1(v, n);
        }
    }
}

void dfs2(ll n, ll p) {
    if(n == 1) return;

    ll i, v, cost, st;

    for0(i, adj[n].size()) {
        v = adj[n][i].first;

        if(v != p) {
            st = adj[n][i].second.first;
            cost = adj[n][i].second.second;

            if(st == 2) {
                c2 += cost;
            }
            dfs2(v, n);
        }
    }
}

int main() {
    ll t = 0, n, x, y, z, i, j, k, g, q, ans = 0, sum = 0, c = 0;
    scl1(t);

    for1(i, t) {
        scl1(city);

        for1(j, city) {
            adj[j].clear();
        }

        for1(j, city) {
            cin >> x >> y >> z;

            adj[x].pb(mp(y, mp(1, z)));
            adj[y].pb(mp(x, mp(2, z)));
        }

        c1 = 0, c2 = 0;

        ll v1 = adj[1][0].first;
        ll v2 = adj[1][1].first;

        x = adj[1][0].second.first;
        y = adj[1][1].second.first;

        if(x == 2) c1 += adj[1][0].second.second;
        if(y == 2) c2 += adj[1][1].second.second;
//
//        cout << v1 << " " << v2 << " " << x << " " << y << "\n";
//        cout << c1 << " " << c2 << "\n";

        dfs1(v1, 1);
        dfs2(v2, 1);

        ans = min(c1, c2);

        printf("Case %lld: %lld\n", i, ans);
    }

    return 0;
}

