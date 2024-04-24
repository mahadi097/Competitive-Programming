#include <bits/stdc++.h>
using namespace std;


//TEMPLATE
#define pb              push_back
#define mp              make_pair
#define ll              long long
#define ld              long double
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
#define printld(n)      printf("%Lf\n", n)
#define printcase       printf("Case %lld: ", i)
#define reversed(s)     reverse(s.begin(), s.end())
#define asorted(s)      sort(s.begin(), s.end())
#define dsorted(s)      sort(s.begin(), s.end(), cmp)
#define for0(i, n)      for (i = 0; i < n; i++)
#define for1(i, n)      for (i = 1; i <= n; i++)
#define pii             pair <ll, ll>
#define piii            pair <ll, pii>
#define SIZE            1005
#define INF             1000000005
#define F               first
#define S               second
#define FR              ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ms(arr, x)      memset(arr, x, sizeof arr)
#define bitcount(n)     __builtin_popcountll(n)

ll avg, money, cnt;
vector <ll> adj[SIZE];
bool vis[SIZE];
ll a[SIZE];

void dfs(ll u) {
    if(vis[u]) return;

    vis[u] = 1;
    money += a[u];
    cnt++;

    ll i, v;
    for0(i, adj[u].size()) {
        v = adj[u][i];
        dfs(v);
    }
}

int main() {
    ll t = 0, n, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0;
    scl1(t);

    for1(i, t) {
        scl2(n, q);

        sum = 0, avg = 0;
        for1(j, n) adj[j].clear();
        ms(vis, 0);

        for1(j, n) {
            scl1(a[j]);
            sum += a[j];
        }

        for1(j, q) {
            scl2(x, y);
            adj[x].pb(y);
            adj[y].pb(x);
        }

        printcase;

        if(sum%n != 0) {
            printf("No\n");
            continue;
        }

        avg = sum / n;

        bool st = 1;

        for1(j, n) {
            if(!vis[j]) {
                money = 0, cnt = 0;
                dfs(j);

                if(money%cnt != 0) {
                    st = 0;
                    break;
                }

                c = money / cnt;
                if(avg != c) {
                    st = 0;
                    break;
                }
            }
        }

        if(st) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}

