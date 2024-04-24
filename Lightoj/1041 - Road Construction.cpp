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
#define SIZE            55
#define INF             1000000005
#define F               first
#define S               second
#define FR              ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ms(arr, x)      memset(arr, x, sizeof arr)
#define bitcount(n)     __builtin_popcountll(n)

struct edge {
    string u, v;
    ll w;
} adj[SIZE];
ll n, e;
set <string> s;
map <string, string> par;

bool cmp(edge a, edge b) {
    return a.w < b.w;
}

string Find(string x) {
    if(par[x] == x) return x;
    return par[x] = Find(par[x]);
}

bool Union(string a, string b) {
    string u = Find(a);
    string v = Find(b);

    if(u != v) {
        par[v] = u;
        return 1;
    }
    return 0;
}

ll kruskal() {
    sort(adj+1, adj+e+1, cmp);

    n = s.size();

    set <string> :: iterator it;
    for(it = s.begin(); it != s.end(); it++) par[*it] = *it;

    ll i, c = 0, t = 0;

    for1(i, e) {
        bool ok = Union(adj[i].u, adj[i].v);
        if(ok) {
            c++;
            t += adj[i].w;
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
        scl1(e);

        s.clear();

        for1(j, e) {
            cin >> adj[j].u >> adj[j].v >> adj[j].w;
            s.insert(adj[j].u);
            s.insert(adj[j].v);
        }

        ans = kruskal();
        printcase;
        if(ans == -1) printf("Impossible\n");
        else printl(ans);
    }

    return 0;
}

