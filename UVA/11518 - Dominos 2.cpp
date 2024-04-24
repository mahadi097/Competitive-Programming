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

ll gcd(ll x, ll y) {
    if(y == 0) {
        return x;
    }
    return gcd(y, x%y);
}

ll node, edge, porse;
bool visited[SIZE];
vector <ll> domino[SIZE];

void clear_data() {
    porse = 0;
    ll i;
    for0(i, SIZE) {
        visited[i] = false;
        domino[i].clear();
    }
}

void dfs_mari(ll n) {
    if(visited[n]) {
        return;
    }
    visited[n] = true;
    porse++;

    ll i;
    for0(i, domino[n].size()) {
        dfs_mari(domino[n][i]);
    }
}

int main() {
    ll t, n, m, a, b, x, y, z, i, j, k;
    scand(t);

    while(t--) {
        clear_data();

        scand(node), scand(edge), scand(n);

        for1(i, edge) {
            scand(a), scand(b);
            domino[a].pb(b);
        }
        for1(i, n) {
            scand(x);

            dfs_mari(x);
        }

        printd(porse);
    }

    return 0;
}

