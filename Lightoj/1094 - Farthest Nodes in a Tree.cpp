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
#define piii            pair <ll, paired>
#define SIZE            30005
#define INF             1000000005
#define F               first
#define S               second

ll node;
vector <pii> adj[SIZE];
vector <ll> dis(SIZE, INF);
ll longest_node, longest_path;

void dijkstra(ll src) {
    dis[src] = 0;

    priority_queue <pii, vector<pii>, greater<pii> > pq;
    pq.push(mp(dis[src], src));

    ll u, v, i, w;

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

    longest_node = src;
    longest_path = 0;

    for0(i, node) {
        if(dis[i] > longest_path) {
            longest_path = dis[i];
            longest_node = i;
        }
    }
}

int main() {
    ll t = 0, n, x, y, z, i, j, k, g, q, ans = 0, sum = 0, c = 0;
    scl1(t);

    for1(i, t) {
        scl1(node);

        for0(j, node) {
            adj[j].clear();
            dis[j] = INF;
        }

        for1(j, node-1) {
            cin >> x >> y >> z;

            adj[x].pb(mp(y, z));
            adj[y].pb(mp(x, z));
        }

        dijkstra(0);

        for0(j, node) {
            dis[j] = INF;
        }

        dijkstra(longest_node);

        printf("Case %lld: %lld\n", i, longest_path);
    }

    return 0;
}

