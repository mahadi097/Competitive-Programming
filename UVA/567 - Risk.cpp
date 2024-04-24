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
#define SIZE            25
#define INF             1000000005

ll dr4[] = {0, 1, -1, 0, 0};
ll dc4[] = {0, 0, 0, 1, -1};

vector <ll> adj[SIZE];
ll vis[SIZE];
ll dis[SIZE];
ll st, en;

void clear_data() {
    ll i;
    memset(vis, 0, sizeof vis);
    memset(dis, 0, sizeof dis);
    for0(i, SIZE) {
        adj[i].clear();
    }
}

ll bfs() {
    vis[st] = st;
    dis[st] = 0;

    queue <ll> q;
    q.push(st);

    ll u, v, i;

    while(!q.empty()) {
        u = q.front();
        q.pop();

        for0(i, adj[u].size()) {
            v = adj[u][i];

            if(!vis[v]) {
                vis[v] = 1;
                dis[v] = dis[u] + 1;

                q.push(v);

                if(v == en) {
                    return dis[v];
                }
            }
        }
    }
}

int main() {
    ll t, n, m, x, y, z, i, j, k, g, q, ans, sum = 0;
    i = 0, t = 1;

    while(scl1(x) != EOF) {
        i++;

        for1(j, x) {
            scl1(m);

            adj[i].pb(m);
            adj[m].pb(i);
        }

        if(i == 19) {
            scl1(n);

            printf("Test Set #%lld\n", t);

            for1(j, n) {
                scl2(st, en);
                memset(vis, 0, sizeof vis);

                ans = bfs();

                printf("%2lld to %2lld: %lld\n", st, en, ans);
            }
            newline;

            clear_data();
            i = 0;
            t++;
        }
    }

    return 0;
}

