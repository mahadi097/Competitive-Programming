#include <bits/stdc++.h>
using namespace std;


//TEMPLATE
#define pb              push_back
#define mp              make_pair
#define ll              long long
#define ld              long double
//#define pi              3.1415926536
#define pi              acos(-1)
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
#define asort(s)        sort(s.begin(), s.end())
#define dsort(s)        sort(s.rbegin(), s.rend())
#define for0(i, n)      for (i = 0; i < n; i++)
#define for1(i, n)      for (i = 1; i <= n; i++)
#define fori(itt, stt)  for(auto itt = stt.begin(); itt != stt.end(); itt++)
#define pii             pair <ll, ll>
#define piii            pair <ll, pii>
#define F               first
#define S               second
#define FR              ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ms(arr, x)      memset(arr, x, sizeof arr)
#define bitcount(n)     __builtin_popcountll(n)
#define all(s)          s.begin(), s.end()

const ll INF = LLONG_MAX;
const ll SZ = 1e7+5;
const ll mod = 1e9+7;


bool check(ll x, ll pos) {
    return (x & (1LL << pos));
}

ll set1(ll x, ll pos) {
    return (x | (1LL << pos));
}

ll in, mx, nxt[SZ][2], f[SZ*2], a[SZ];
vector <ll> adj[SZ];

void INSERT(ll x) {
    ll i, id, now = 0;

    for(i = 32; i >= 0; i--) {
        id = check(x, i);

        if(f[nxt[now][id]] == 0) {
            nxt[now][id] = ++in;
        }
        now = nxt[now][id];
        f[now]++;
    }
}


void dlt(ll x) {
    ll i, id, now = 0;

    for(i = 32; i >= 0; i--) {
        id = check(x, i);

        now = nxt[now][id];
        f[now]--;
    }
}

ll query(ll x) {
    ll i, id, now(0), v(0);

    for(i = 32; i >= 0; i--) {
        id = check(x, i) ^ 1;

        if(f[nxt[now][id]]) {
            v = set1(v, i);
            now = nxt[now][id];
        }
        else now = nxt[now][id^1];
    }

    return v;
}

void dfs(ll u, ll p) {
    mx = max(mx, query(a[u]));
    INSERT(a[u]);

    for(auto v: adj[u]) {
        if(v == p) continue;
        dfs(v, u);
    }
    dlt(a[u]);
}

int main() {
    FR;
    ll t = 0, n, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0;
    string s, s1, s2;

    cin >> n;
    for1(i, n) cin >> a[i];

    for1(i, n-1) {
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    dfs(1, 0);

    cout << mx << "\n";

    return 0;
}

