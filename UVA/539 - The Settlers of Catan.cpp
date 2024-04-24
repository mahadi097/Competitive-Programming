#include <bits/stdc++.h>
using namespace std;


//TEMPLATE
#define pb              push_back
#define mp              make_pair
#define ll              long long
#define ld              long double
//#define pi              3.1415926536
#define pi              acos(-1)
//#define mod             1000000007
#define newline         printf("\n")
#define printminusone   printf("-1\n")
#define scl1(n)         scanf("%lld", &n)
#define scl2(a, b)      scanf("%lld %lld", &a, &b)
#define scl3(a, b, c)   scanf("%lld %lld %lld", &a, &b, &c)
#define printl(n)       printf("%lld\n", n)
#define ssl1(str)       scanf(" %[^\n]", str)
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
#define fori(itt, stt)  for(itt = stt.begin(); itt != stt.end(); itt++)
#define pii             pair <ll, ll>
#define piii            pair <ll, pii>
//#define SIZE            100005
//#define INF             1000000005
#define F               first
#define S               second
#define FR              ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ms(arr, x)      memset(arr, x, sizeof arr)
#define bitcount(n)     __builtin_popcountll(n)

const ll INF = 1e18;
const ll SIZE = 28;
const ll mod = 1e9+7;


bool road[SIZE][SIZE];
bool vis[SIZE][SIZE];
ll n, m, ans;

void dfs(ll u, ll ln) {
    ans = max(ans, ln);

    ll i;
    for0(i, n) {
        if(road[u][i] && !vis[u][i]) {
            vis[u][i] = 1;
            vis[i][u] = 1;
            dfs(i, ln+1);
            vis[u][i] = 0;
            vis[i][u] = 0;
        }
    }
//    ans = max(ans, ln);
}

int main() {
    ll t = 0, x, y, z, i, j, k, g, p, q, sum = 0, c = 0;
    string s, s1, s2;

    while(scl2(n, m)) {
        if(!n && !m) break;

        for0(i, n) {
            for0(j, n) {
                road[i][j] = 0;
                road[j][i] = 0;
            }
        }

        for1(i, m) {
            scl2(x, y);
            road[x][y] = 1;
            road[y][x] = 1;
        }

        ans = 0;
        for0(i, n) {
            ms(vis, 0);
            dfs(i, 0);
//            printl(ans);
        }

        printl(ans);
    }

    return 0;
}

