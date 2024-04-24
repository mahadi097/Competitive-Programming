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
#define SIZE            1000005
#define INF             1000000005

ll f, s, g, up, down;
ll dis[SIZE];
bool visited[SIZE];

void bfs();

int main() {
    ll t, n, m, a, b, c, x, y, z, i, j, k;
    cin >> f >> s >> g >> up >> down;

    bfs();

    if(dis[g] == 0 && g != s) {
        cout << "use the stairs\n";
        return 0;
    }

    printd(dis[g]);

    return 0;
}

void bfs() {
    queue <ll> q;

    dis[s] = 0;

    visited[s] = true;
    q.push(s);

    ll u, v, i;

    while(!q.empty()) {
        u = q.front();
        q.pop();

        if((u + up) <= f) {
            v = u + up;
            if(!visited[v]) {
                visited[v] = true;
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
        if((u - down) >= 1) {
            v = u - down;
            if(!visited[v]) {
                visited[v] = true;
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
}
