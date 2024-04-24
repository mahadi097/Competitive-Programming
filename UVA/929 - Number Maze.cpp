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
#define SIZE            1005
#define INF             1000000005

ll dr4[] = {0, 1, -1, 0, 0};
ll dc4[] = {0, 0, 0, 1, -1};

bool valid(ll i, ll j);
void clear_data();
void dijkstra();

ll r, c;
ll maze[SIZE][SIZE];
ll dis[SIZE][SIZE];

int main() {
    ll t, n, m, a, b, x, y, z, i, j, k;
    scand(t);

    while(t--) {
        clear_data();

        scand(r);
        scand(c);

        for1(i, r) {
            for1(j, c) {
                scand(maze[i][j]);
            }
        }

        dijkstra();

        printd(dis[r][c]);
    }

    return 0;
}

bool valid(ll i, ll j) {
    return (i >= 1 && i <= r && j >= 1 && j <= c);
}

void clear_data() {
    ll i, j;
    for1(i, SIZE-1) {
        for1(j, SIZE-1) {
            dis[i][j] = INF;
        }
    }
}

void dijkstra() {
    priority_queue <pii, vector<pii>, greater<pii> > pq;

    dis[1][1] = maze[1][1];
    pq.push(mp(dis[1][1], mp(1, 1)));

    ll u, v, i, x, y, w;
    paired p;

    while(!pq.empty()) {
        p = pq.top().second;
        pq.pop();

        for1(i, 4) {
            x = p.first + dr4[i];
            y = p.second + dc4[i];

            if(valid(x, y)) {
                w = maze[x][y];

                if(dis[x][y] > (dis[p.first][p.second] + w)) {
                    dis[x][y] = dis[p.first][p.second] + w;

                    pq.push(mp(dis[x][y], mp(x, y)));
                }
            }
        }
    }
}
