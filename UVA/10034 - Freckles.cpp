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
#define pii             pair <double, double>
#define piii            pair <ll, pii>
#define SIZE            10005
#define INF             1000000005
#define F               first
#define S               second
#define FR              ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ms(arr, x)      memset(arr, x, sizeof arr)
#define bitcount(n)     __builtin_popcountll(n)

struct edge {
    double x1, x2, y1, y2, ln;
} adj[SIZE];
ll n, e;
double xx[105], yy[105];
map <pii, pii> par;

bool cmp(edge a, edge b) {
    return a.ln < b.ln;
}

pii Find(pii x) {
    if(par[x] == x) return x;
    return par[x] = Find(par[x]);
}

bool Union(pii a, pii b) {
    pii u = Find(a);
    pii v = Find(b);

    if(u != v) {
        par[v] = u;
        return 1;
    }
    return 0;
}

double kruskal() {
    ll i, j, c = 0;
    e = 0;
    double sum = 0.0;

    for1(i, n) {
        for(j = i+1; j <= n; j++) {
            double ln = sqrt( (xx[i] - xx[j])*(xx[i] - xx[j]) + (yy[i] - yy[j])*(yy[i] - yy[j]) );
            adj[++e].x1 = xx[i];
            adj[e].x2 = xx[j];
            adj[e].y1 = yy[i];
            adj[e].y2 = yy[j];
            adj[e].ln = ln;
        }
    }
    sort(adj+1, adj+e+1, cmp);

    for1(i, n) par[mp(xx[i], yy[i])] = mp(xx[i], yy[i]);

    for1(i, e) {
        bool ok = Union(mp(adj[i].x1, adj[i].y1), mp(adj[i].x2, adj[i].y2));

        if(ok) {
            c++;
            sum += adj[i].ln;
            if(c == (n-1)) break;
        }
    }

    return sum;
}

int main() {
    ll t = 0, x, y, z, i, j, k, g, p, q, sum = 0, c = 0;
    scl1(t);

    while(t--) {
        scl1(n);

        for1(i, n) scd2(xx[i], yy[i]);

        double ans = kruskal();
        printf("%.2lf\n", ans);
        if(t) newline;
    }

    return 0;
}

