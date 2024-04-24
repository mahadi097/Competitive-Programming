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
#define SIZE            105
#define INF             1000000005

ll dr4[] = {0, 1, -1, 0, 0};
ll dc4[] = {0, 0, 0, 1, -1};

ll gcd(ll x, ll y) {
    if(y == 0) {
        return x;
    }
    return gcd(y, x%y);
}

ll node, edge, st;
ll max_length, min_in;
ll dis[SIZE];
bool visited[SIZE];

vector <ll> rasta[SIZE];

void clear_data() {
    ll i;
    max_length = 0, min_in = SIZE;
    for0(i, SIZE) {
        dis[i] = 0;
        visited[i] = false;
        rasta[i].clear();
    }
}

void bfs_mari() {
    queue <ll> q;
    q.push(st);
    dis[st] = 0;
    visited[st] = true;

    ll i, u, v;

    while(!q.empty()) {
        u = q.front();
        q.pop();

        for0(i, rasta[u].size()) {
            v = rasta[u][i];

            if(!visited[v] || ((dis[u]+1) >= dis[v])) {
                dis[v] = dis[u] + 1;
                visited[v] = true;
                max_length = max(max_length, dis[v]);
                q.push(v);
            }
        }
    }

    for1(i, node) {
        if(max_length == dis[i] && visited[i]) {
            min_in = i;
            break;
        }
    }
}

int main() {
    ll t, n, m, a, b, x, y, z, i = 1, j, k;

    while((scand(node) == 1) && node) {
        clear_data();

        scand(st);

        while((scanf("%lld %lld", &a, &b) == 2) && (a || b)) {
            rasta[a].pb(b);
        }

        bfs_mari();

        printf("Case %lld: The longest path from %lld has length %lld, finishing at %lld.\n\n", i, st, max_length, min_in);
        i++;
    }

    return 0;
}

