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

ll dr4[] = {0, 1, -1, 0, 0};
ll dc4[] = {0, 0, 0, 1, -1};

vector <ll> adj[SIZE];
ll visit[SIZE][3];
ll node, edge, paisi;

void clear_data() {
    ll i;
    paisi = 0;
    memset(visit, 0, sizeof visit);
    for1(i, SIZE) {
        adj[i].clear();
    }
}

void dfs(ll n, ll now) {
    visit[n][now] = 1;

    now != 2 ? : paisi++;

    ll next = 1;
    if(now == 1) {
        next = 2;
    }

    ll v, i;

    for0(i, adj[n].size()) {
        v = adj[n][i];

        if(!visit[v][next]) {
            dfs(v, next);
        }
    }
}

int main() {
    ll t, n, m, a, b, x, y, z, i, j, k;
    scl1(t);

    for1(i, t) {
        clear_data();

        scl2(node, edge);

        for1(j, edge) {
            scl2(a, b);

            adj[a].pb(b);
            adj[b].pb(a);
        }

        dfs(1, 0);

        printf("Case %lld: %lld\n", i, paisi);
    }

    return 0;
}

