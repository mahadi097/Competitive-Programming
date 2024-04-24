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

vector <ll> adj_list[SIZE];
bool visited[SIZE];

void dfs(ll n);

int main() {
    ll t, n, m, a, b, r, c, x, y, z, i, j, k;
    scand(r), scand(c);

    char grid[r+1][c+1];

    n = 1;

    for1(i, r) {
        for1(j, c) {
            cin >> grid[i][j];

            if(grid[i][j] == 'S') {
                adj_list[n].pb(n+c);
                adj_list[n+c].pb(n);
            }
            else if(grid[i][j] == 'N') {
                adj_list[n].pb(n-c);
                adj_list[n-c].pb(n);
            }
            else if(grid[i][j] == 'W') {
                adj_list[n].pb(n-1);
                adj_list[n-1].pb(n);
            }
            else if(grid[i][j] == 'E') {
                adj_list[n].pb(n+1);
                adj_list[n+1].pb(n);
            }
            n++;
        }
    }

    t = 0;

    for1(i, r*c) {
        if(!visited[i]) {
            t++;
            dfs(i);
        }
    }

    printd(t);

    return 0;
}

void dfs(ll n) {
    if(visited[n]) {
        return;
    }

    visited[n] = true;

    ll i;

    for0(i, adj_list[n].size()) {
        dfs(adj_list[n][i]);
    }
}
