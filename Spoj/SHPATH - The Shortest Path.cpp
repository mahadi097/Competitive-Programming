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

vector <paired> adj_list[SIZE];
map <string, ll> city;
ll node, neighbour;
ll dis[SIZE];

void dijkstra(ll n);
void clear_data();

int main() {
    ll t, n, m, a, b, c, x, y, z, i, j, k;
    ll n1, n2, w;
    string name, s1, s2;
    scand(t);

    while(t--) {
        clear_data();

        scand(node);
        i = 0;

       for1(j, node) {
            cin >> name >> neighbour;
            city[name] = ++i;

            while(neighbour--) {
                scand(n2), scand(w);

                adj_list[i].pb(mp(n2, w));
            }
        }


        scand(n);
        while(n--) {
            cin >> s1 >> s2;

            dijkstra(city[s1]);

            printd(dis[city[s2]]);

            for1(j, node) {
                dis[j] = INF;
            }
        }
    }

    return 0;
}

void clear_data() {
    ll i;
    for0(i, SIZE) {
        adj_list[i].clear();
        dis[i] = INF;
    }
}

void dijkstra(ll n) {
    priority_queue <paired, vector <paired>, greater<paired> > pq;

    dis[n] = 0;
    pq.push(mp(dis[n], n));

    ll u, v, w, i;

    while(!pq.empty()) {
        u = pq.top().second;
        pq.pop();

        for0(i, adj_list[u].size()) {
            v = adj_list[u][i].first;
            w = adj_list[u][i].second;

            if(dis[v] > (dis[u]+w)) {
                dis[v] = dis[u] + w;
                pq.push(mp(dis[v], v));
            }
        }
    }

}
