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
#define SIZE            105
#define INF             1000000005

ll cell, edge, last, timer;
vector <paired> adj[SIZE];
vector <ll> dis(SIZE, INF);

void dijkstra(ll n) {
    priority_queue <paired, vector<paired>, greater<paired> > pq;

    dis[n] = 0;
    pq.push(mp(0, n));

    ll u, v, w, i;

    while(!pq.empty()) {
        u = pq.top().second;
        pq.pop();

        for0(i, adj[u].size()) {
            v = adj[u][i].first;
            w = adj[u][i].second;

            if(dis[v] > (dis[u] + w)) {
                dis[v] = dis[u] + w;

                pq.push(mp(dis[v], v));
            }
        }
    }
}

int main() {
    ll t = 0, n, x, y, z, i, j, k, g, q, ans = 0, sum = 0;
    scl2(cell, last);
    scl2(timer, edge);

    for1(i, edge) {
        scl2(x, y);
        scl1(z);

        adj[x].pb(mp(y, z));
        adj[y].pb(mp(x, z));
    }

    for1(i, cell) {
        for1(j, cell) {
            dis[j] = INF;
        }
        dijkstra(i);

        if(dis[last] <= timer) {
            t++;
        }
    }

    printl(t);

    return 0;
}

