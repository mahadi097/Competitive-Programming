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
const ll SIZE = 1e5+5;
const ll mod = 1e9+7;


ll a[SIZE];
vector <ll> adj[SIZE];
ll st[SIZE], en[SIZE], cnt;

void dfs(ll u, ll p) {
    st[u] = ++cnt;

    ll i, v, sz = adj[u].size();

    for0(i, sz) {
        v = adj[u][i];

        if(v == p) continue;

        dfs(v, u);
    }

    en[u] = cnt;
}

ll tree[SIZE*4];
ll lazy[SIZE*4];

void build(ll node, ll r1, ll r2) {
    if(r1 == r2) {
        tree[node] = 0;
        lazy[node] = 0;
        return;
    }

    ll bam = node*2;
    ll dan = bam + 1;

    ll mid = (r1 + r2) / 2;

    build(bam, r1, mid);
    build(dan, mid+1, r2);

    tree[node] = 0;
    lazy[node] = 0;
}

void propagate(ll node, ll r1, ll r2) {
    tree[node] += lazy[node];

    if(r1 != r2) {
        lazy[node*2] += lazy[node];
        lazy[node*2+1] += lazy[node];
    }
    lazy[node] = 0;
}

void update(ll node, ll r1, ll r2, ll i, ll j) {
    ll bam = node*2;
    ll dan = bam + 1;

    if(r1 > j || r2 < i) return;
    if(lazy[node]) propagate(node, r1, r2);
    if(r1 >= i && r2 <= j) {
        tree[node]++;

        if(r1 != r2) {
            lazy[bam]++;
            lazy[dan]++;
        }
        return;
    }

    ll mid = (r1 + r2) / 2;

    update(bam, r1, mid, i, j);
    update(dan, mid+1, r2, i, j);
}

ll query(ll node, ll r1, ll r2, ll i, ll j) {
    ll bam = node*2;
    ll dan = bam + 1;

    if(r1 > j || r2 < i) return 0;
    if(lazy[node]) propagate(node, r1, r2);
    if(r1 >= i && r2 <= j) return tree[node];

    ll mid = (r1 + r2) / 2;

    ll p1 = query(bam, r1, mid, i, j);
    ll p2 = query(dan, mid+1, r2, i, j);

    return (p1+p2);
}

int main() {
    ll t = 0, n, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0;
    string s, s1, s2;

    scl1(t);

    for1(i, t) {
        scl2(n, q);
        for1(j, n) scl1(a[j]);

        for1(j, n) {
            adj[j].clear();
            st[j] = 0;
            en[j] = 0;
        }
        cnt = 0;

        for1(j, n-1) {
            scl2(x, y);
            adj[x].pb(y);
            adj[y].pb(x);
        }

        dfs(1, 1);
        build(1, 1, n);

        while(q--) {
            scl1(x);
            update(1, 1, n, st[x], en[x]);
        }

        for1(j, n) {
            ans = query(1, 1, n, st[j], st[j]);
            ans %= 2;
            if(ans) a[j] ^= 1;
        }

        printcase;
        for1(j, n) {
            if(j == n) printf("%lld\n", a[j]);
            else printf("%lld ", a[j]);
        }
    }

    return 0;
}

