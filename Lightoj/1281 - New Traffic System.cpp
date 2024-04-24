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
#define SIZE            100005
#define INF             1000000005

vector <paired> OLD[SIZE];
vector <paired> NEW[SIZE];
ll dis[SIZE][11];
ll node, edge, d;

void clear_data();
void dijkstra(ll n);

int main() {
    ll t, n, m, a, b, c, x, y, z, i, j, k;
    scand(t);

    for1(i, t) {
        clear_data();
        scand(node), scand(edge), scand(k), scand(d);

        ll n1, n2, w;

        for1(j, edge) {
            scand(n1), scand(n2), scand(w);

            OLD[n1].pb(mp(n2, w));
//            OLD[n2].pb(mp(n1, w));
        }
        for1(j, k) {
            scand(n1), scand(n2), scand(w);

            NEW[n1].pb(mp(n2, w));
//            NEW[n2].pb(mp(n1, w));
        }

        dijkstra(0);

        ll shortest = INF;

        for0(j, d+1) {
            shortest = min(shortest, dis[node-1][j]);
//            printd(dis[node-1][j]);
        }

        if(shortest == INF) {
            cout << "Case " << i << ": " << "Impossible\n";
        }
        else {
            cout << "Case " << i << ": " << shortest << "\n";
        }
    }

    return 0;
}

void clear_data() {
    ll i, j;
    for0(i, SIZE) {
        OLD[i].clear();
        NEW[i].clear();

        for0(j, 11) {
            dis[i][j] = INF;
        }
    }
}

void dijkstra(ll n) {
    priority_queue <pii, vector <pii>, greater<pii> > pq;

    ll u, v, i, j, w, st, used = 0;

    dis[n][used] = 0;
    pq.push(mp(dis[n][used], mp(n, used)));

    while(!pq.empty()) {
        u = pq.top().second.first;
        used = pq.top().second.second;
        pq.pop();

        for0(i, OLD[u].size()) {
            v = OLD[u][i].first;
            w = OLD[u][i].second;

            if(dis[v][used] > (dis[u][used] + w)) {
                dis[v][used] = dis[u][used] + w;
                pq.push(mp(dis[v][used], mp(v, used)));
            }
        }

        for0(i, NEW[u].size()) {
            v = NEW[u][i].first;
            w = NEW[u][i].second;

            if((dis[v][used+1] > (dis[u][used] + w)) && ((used+1) <= d) ) {
                dis[v][used+1] = dis[u][used] + w;
                pq.push(mp(dis[v][used+1], mp(v, used+1)));
            }
        }
    }
}
