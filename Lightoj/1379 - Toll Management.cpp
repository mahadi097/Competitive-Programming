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
#define SIZE            10005
#define INF             1000000005

ll dr4[] = {0, 1, -1, 0, 0};
ll dc4[] = {0, 0, 0, 1, -1};

ll node, edge, st, en, tk;
vector < vector<paired> > road(SIZE);
vector < vector<paired> > rev_road(SIZE);
vector <ll> dis;
vector <ll> rev_dis;

ll solve();
void clear_data();
vector <ll> dijkstra(ll n, vector <vector<paired> > &adj);

int main() {
    ll t, n, m, a, b, x, y, z, i, j, k;
    scand(t);

    for1(i, t) {
        clear_data();

        scand(node), scand(edge), scand(st), scand(en), scand(tk);

        ll n1, n2, w;

        for1(j, edge) {
            scand(n1), scand(n2), scand(w);

            road[n1].pb(mp(n2, w));
            rev_road[n2].pb(mp(n1, w));
        }

        dis = dijkstra(st, road);
        rev_dis = dijkstra(en, rev_road);

        printf("Case %lld: ", i);

        ll best = solve();
        printd(best);
    }

    return 0;
}

void clear_data() {
    ll i;
    dis.clear();
    rev_road.clear();
    for0(i, SIZE) {
        road[i].clear();
        rev_road[i].clear();
    }
}

ll solve() {
    ll i, j, u, v, w;

    ll best = -1;

    for1(i, node) {
        u = i;
        for0(j, road[i].size()) {
            v = road[i][j].first;
            w = road[i][j].second;

            if(tk >= (dis[u] + w + rev_dis[v])) {
                best = max(best, w);
            }
        }
    }

    return best;
}

vector <ll> dijkstra(ll n, vector < vector<paired> > &adj) {
    priority_queue <paired, vector<paired>, greater<paired> > pq;

    ll u, v, i, w;
    vector <ll> d(node+1, INF);

    d[n] = 0;

    pq.push(mp(d[n], n));

    while(!pq.empty()) {
        u = pq.top().second;
        pq.pop();

        for0(i, adj[u].size()) {
            v = adj[u][i].first;
            w = adj[u][i].second;

            if(d[v] > (d[u] + w)) {
                d[v] = d[u] + w;
                pq.push(mp(d[v], v));
            }
        }
    }

    return d;
}
