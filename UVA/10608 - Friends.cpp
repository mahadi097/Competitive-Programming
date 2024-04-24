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
#define SIZE            30005

vector <ll> adj_list[SIZE];
bool visited[SIZE];
ll node, edge;
ll total;

void dfs(ll n);

int main() {
    ll t, n, i, j, k;
    scand(t);

    while(t--) {
        for1(i, SIZE) {
            adj_list[i].clear();
            visited[i] = false;
        }

        scand(node), scand(edge);

        ll n1, n2;
        for1(i, edge) {
            scand(n1), scand(n2);

            adj_list[n1].pb(n2);
            adj_list[n2].pb(n1);
        }

        ll maximum = 0;

        for1(i, node) {
            if(!visited[i]) {
                total = 0;

                dfs(i);
                maximum = max(maximum, total);
            }
        }
        printd(maximum);
    }

    return 0;
}

void dfs(ll n) {
    if(visited[n]) {
        return;
    }
    visited[n] = true;
    total++;

    ll i;

    for0(i, adj_list[n].size()) {
        dfs(adj_list[n][i]);
    }
}
