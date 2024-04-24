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

vector <paired> source[SIZE], dest[SIZE];
ll src, des, node, edge;
ll dist_src[SIZE], dist_des[SIZE];

void clear_data();
void from_source();
void from_dest();

int main() {
    ll t, n, m, a, b, c, x, y, z, i, j, k;
    scand(t);

    while(t--) {
        clear_data();
        scand(node), scand(edge), scand(k), scand(src), scand(des);

        ll n1, n2, w;

        for1(i, edge) {
            scand(n1), scand(n2), scand(w);
            source[n1].pb(mp(n2, w));
            dest[n2].pb(mp(n1, w));
        }

        from_source();
        from_dest();

        ll cost = dist_src[des];

        for1(i, k) {
            scand(n1), scand(n2), scand(w);

            if(cost > (dist_src[n1] + dist_des[n2] + w)) {
                cost = dist_src[n1] + dist_des[n2] + w;
            }
            if(cost > (dist_src[n2] + dist_des[n1] + w)) {
                cost = dist_src[n2] + dist_des[n1] + w;
            }
        }

        if(cost == INF) {
            printminusone;
        }
        else {
            printd(cost);
        }
    }

    return 0;
}

void clear_data() {
    ll i;
    for0(i, SIZE) {
        source[i].clear();
        dest[i].clear();
        dist_src[i] = INF;
        dist_des[i] = INF;
    }
}

void from_source() {
    priority_queue < paired, vector<paired>, greater<paired> > pq;

    dist_src[src] = 0;
    pq.push(mp(dist_src[src], src));

    ll u, v, w, i;

    while(!pq.empty()) {
        u = pq.top().second;
        pq.pop();

        for0(i, source[u].size()) {
            v = source[u][i].first;
            w = source[u][i].second;

            if(dist_src[v] > (dist_src[u] + w)) {
                dist_src[v] = dist_src[u] + w;
                pq.push(mp(dist_src[v], v));
            }
        }
    }
}

void from_dest() {
    priority_queue < paired, vector<paired>, greater<paired> > pq;

    dist_des[des] = 0;
    pq.push(mp(dist_des[des], des));

    ll u, v, w, i;

    while(!pq.empty()) {
        u = pq.top().second;
        pq.pop();

        for0(i, dest[u].size()) {
            v = dest[u][i].first;
            w = dest[u][i].second;

            if(dist_des[v] > (dist_des[u] + w)) {
                dist_des[v] = dist_des[u] + w;
                pq.push(mp(dist_des[v], v));
            }
        }
    }
}
