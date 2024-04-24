#include <bits/stdc++.h>
using namespace std;


//TEMPLATE
#define pb              push_back
#define mp              make_pair
#define ll              long long
#define ld              long double
#define pi              3.1415926536
//#define mod             1000000007
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
//#define SIZE            100005
//#define INF             1000000005
#define F               first
#define S               second
#define FR              ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ms(arr, x)      memset(arr, x, sizeof arr)
#define bitcount(n)     __builtin_popcountll(n)

const ll INF = 1e18;
const ll SIZE = 2505;
const ll mod = 1e9+7;

struct edge {
    ll u, v, w;
} adj[SIZE];
ll n, e;
ll par[55];

bool cmp(edge a, edge b) {
    return (a.w < b.w);
}

ll Find(ll x) {
    if(par[x] == x) return x;
    return par[x] = Find(par[x]);
}

bool Union(ll a, ll b) {
    ll u = Find(a);
    ll v = Find(b);

    if(u != v) {
        par[v] = u;
        return 1;
    }
    return 0;
}

ll kruskal() {
    sort(adj+1, adj+e+1, cmp);

    ll i, t = 0, c = 0;

    for1(i, n) par[i] = i;

    for1(i, e) {
        bool ok = Union(adj[i].u, adj[i].v);
        if(ok) {
            t += adj[i].w;
            c++;
            if(c == (n-1)) break;
        }
    }

    if(c == n-1) return t;
    return -1;
}

int main() {
    ll t = 0, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0;
    scl1(t);

    for1(i, t) {
        scl1(n);

        ans = 0;
        e = 0;
        sum = 0;

        for1(j, n) {
            for1(k, n) {
                scl1(x);

                if(x == 0) continue;

                if(k == j) {
                    ans += x;
                    continue;
                }

                sum += x;

                adj[++e].u = j;
                adj[e].v = k;
                adj[e].w = x;
            }
        }

        c = kruskal();

        printcase;

        if(c == -1) {
            printminusone;
            continue;
        }

        ans += (sum - c);
        printl(ans);
    }

    return 0;
}

