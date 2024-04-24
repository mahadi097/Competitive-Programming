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
#define scand(n)        scanf("%lld", &n)
#define printd(n)       printf("%lld\n", n)
#define scandd(n)       scanf("%lf", &n)
#define printdd(n)      printf("%lf\n", n)
#define reversed(s)     reverse(s.begin(), s.end())
#define asorted(s)      sort(s.begin(), s.end())
#define dsorted(s)      sort(s.begin(), s.end(), descending_func)
#define for0(i, n)      for (i = 0; i < n; i++)
#define for1(i, n)      for (i = 1; i <= n; i++)
#define paired          pair <ll, ll>
#define pii             pair <ll, paired>
#define SIZE            5005
#define INF             1000000005

vector <paired> adj_list[SIZE];
ll dis[SIZE][2];
ll node, edge;

void clear_data();
void dijkstra(ll n);

int main() {
    ll t, n, m, a, b, c, x, y, z, i, j, k;
    scand(t);

    for1(i, t) {
        clear_data();

        scand(node), scand(edge);

        ll n1, n2, w;

        for1(j, edge) {
            scand(n1), scand(n2), scand(w);

            adj_list[n1].pb(mp(n2, w));
            adj_list[n2].pb(mp(n1, w));
        }

        dijkstra(1);

        cout << "Case " << i << ": " << dis[node][1] << endl;
    }

    return 0;
}

void clear_data() {
    ll i;
    for1(i, SIZE-1) {
        adj_list[i].clear();
        dis[i][0] = INF;
        dis[i][1] = INF;
    }
}

void dijkstra(ll n) {
    priority_queue <pii, vector<pii>, greater<pii> > pq;

    ll num = 0;
    dis[n][0] = 0;
    pq.push(mp(dis[n][0], mp(n, num)));

    ll u, v, i, w;

    while(!pq.empty()) {
        u = pq.top().second.first;
        num = pq.top().second.second;
        pq.pop();

        for0(i, adj_list[u].size()) {
            v = adj_list[u][i].first;
            w = adj_list[u][i].second;

            if(dis[v][0] > (dis[u][num] + w)) {
                dis[v][1] = dis[v][0];
                dis[v][0] = dis[u][num] + w;

                pq.push(mp(dis[v][0], mp(v, 0)));
                pq.push(mp(dis[v][1], mp(v, 1)));
            }

            else if( (dis[v][0] < dis[u][num] + w) && (dis[v][1] > dis[u][num] + w) ) {
                dis[v][1] = dis[u][num] + w;
                pq.push(mp(dis[v][1], mp(v, 1)));
            }
        }
    }
}
