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
#define SIZE            100005
#define INF             1000000005
#define F               first
#define S               second
#define FR              ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ms(arr, x)      memset(arr, x, sizeof arr)
#define bitcount(n)     __builtin_popcountll(n)

struct edge {
    ll u, v, w;

} adj[SIZE];
ll n, e;
ll par[SIZE];

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

pii kruskal() {
    sort(adj+1, adj+e+1, cmp);

    ll i, u, v, best = 0, worst = 0;
    ll c = 0;
    bool ok;

    for0(i, n+1) par[i] = i;
    for1(i, e) {
        ok = Union(adj[i].u, adj[i].v);

        if(ok) {
            c++;
            best += adj[i].w;
            if(c == n) break;
        }
    }

    for0(i, n+1) par[i] = i;
    c = 0;
    for(i = e; i >= 1; i--) {
        ok = Union(adj[i].u, adj[i].v);

        if(ok) {
            c++;
            worst += adj[i].w;
            if(c == n) break;
        }
    }

//    cout << best << " " << worst << endl;

    return mp(best, worst);
}

int main() {
    ll t = 0, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0;
    scl1(t);

    for1(i, t) {
        scl1(n);

        e = 0;

        while((cin >> x >> y >> z) && (x || y || z)) {
            adj[++e].u = x;
            adj[e].v = y;
            adj[e].w = z;
        }

        pii pp = kruskal();

        printcase;
        if((pp.F+pp.S)%2 == 0) printf("%lld\n", (pp.F+pp.S)/2);
        else printf("%lld/2\n", (pp.F+pp.S));
    }

    return 0;
}

