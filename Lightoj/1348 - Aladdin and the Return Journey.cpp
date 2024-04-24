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
#define printcase       printf("Case %lld:\n", i)
#define reversed(s)     reverse(s.begin(), s.end())
#define asorted(s)      sort(s.begin(), s.end())
#define dsorted(s)      sort(s.begin(), s.end(), cmp)
#define for0(i, n)      for (i = 0; i < n; i++)
#define for1(i, n)      for (i = 1; i <= n; i++)
#define fori(itt, stt)  for(auto itt = stt.begin(); itt != stt.end(); itt++)
#define pii             pair <ll, ll>
#define piii            pair <ll, pii>
//#define SIZE            100005
//#define INF             1000000005
#define F               first
#define S               second
#define FR              ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ms(arr, x)      memset(arr, x, sizeof arr)
#define bitcount(n)     __builtin_popcountll(n)

const ll INF = LLONG_MAX;
const ll SIZE = 30000+5;
const ll mod = 1e9+7;


ll n, cnt, lg = 21;
vector <ll> adj[SIZE];
ll par[SIZE][21];
ll lvl[SIZE];
ll st[SIZE], en[SIZE];
ll num[SIZE];
ll a[SIZE], gen[SIZE];
ll tree[SIZE*4];
struct data {
    ll prv, now;
} lazy[SIZE*4];

void dfs(ll u, ll p) {
    lvl[u] = lvl[p] + 1;
    par[u][0] = p;
    st[u] = ++cnt;
    num[cnt] = u;
    gen[u] = gen[p] + a[u];

    ll i, v;
    for0(i, adj[u].size()) {
        v = adj[u][i];

        if(v == p) continue;

        dfs(v, u);
    }

    en[u] = cnt;
}

void build(ll node, ll r1, ll r2) {
    ll bam = node*2;
    ll dan = bam + 1;

    if(r1 == r2) {
        tree[node] = gen[num[r1]];
        lazy[node].prv = lazy[node].now = 0;
        return;
    }

    ll mid = (r1 + r2) / 2;

    build(bam, r1, mid);
    build(dan, mid+1, r2);

    tree[node] = tree[bam] + tree[dan];
    lazy[node].prv = lazy[node].now = 0;
}

void propagate(ll node, ll r1, ll r2) {
    tree[node] -= ((r2 - r1 + 1) * lazy[node].prv);
    tree[node] += ((r2 - r1 + 1) * lazy[node].now);

    if(r1 != r2) {
        lazy[node*2].prv += lazy[node].prv;
        lazy[node*2+1].prv += lazy[node].prv;
        lazy[node*2].now += lazy[node].now;
        lazy[node*2+1].now += lazy[node].now;
    }
    lazy[node].prv = lazy[node].now = 0;
}

void update(ll node, ll r1, ll r2, ll i, ll j, ll now, ll pre) {
    ll bam = node*2;
    ll dan = bam + 1;

    if(lazy[node].prv || lazy[node].now) propagate(node, r1, r2);
    if(r1 > j || r2 < i) return;
    if(r1 >= i && r2 <= j) {
        tree[node] -= ((r2 - r1 + 1) * pre);
        tree[node] += ((r2 - r1 + 1) * now);

        if(r1 != r2) {
            lazy[bam].prv += pre;
            lazy[dan].prv += pre;
            lazy[bam].now += now;
            lazy[dan].now += now;
        }
        return;
    }

    ll mid = (r1 + r2) / 2;

    update(bam, r1, mid, i, j, now, pre);
    update(dan, mid+1, r2, i, j, now, pre);

    tree[node] = tree[bam] + tree[dan];
}

ll query(ll node, ll r1, ll r2, ll in) {
    ll bam = node*2;
    ll dan = bam + 1;

    if(lazy[node].prv || lazy[node].now) propagate(node, r1, r2);
    if(r1 > in || r2 < in) return 0;
    if(r1 >= in && r2 <= in) return tree[node];

    ll mid = (r1 + r2) / 2;

    ll p1 = query(bam, r1, mid, in);
    ll p2 = query(dan, mid+1, r2, in);

    return (p1+p2);
}

bool check(ll x, ll pos) {
    return((x >> pos) & 1LL);
}

void lca_build() {
    ll i, j, p;

    for1(i, lg-1) {
        for1(j, n) {
            p = par[j][i-1];
            if(p != -1) par[j][i] = par[p][i-1];
        }
    }
}

ll get_lca(ll u, ll v) {
    if(lvl[u] < lvl[v]) swap(u, v);

    ll i, diff = lvl[u] - lvl[v];

    for0(i, lg) {
        if(check(diff, i)) u = par[u][i];
    }

    if(u == v) return u;

    for(i = lg-1; i >= 0; i--) {
        if(par[u][i] != par[v][i] && par[u][i] != -1) {
            u = par[u][i];
            v = par[v][i];
        }
    }

    return par[u][0];
}

ll get_num(ll u, ll v) {
    if(lvl[u] < lvl[v]) swap(u, v);

    ll lca = get_lca(u, v);

    ll t1 = query(1, 1, n, st[lca]);
    ll t2 = query(1, 1, n, st[u]);
    ll t3 = query(1, 1, n, st[v]);

//    cout << t2 << " " << t3 << " " << lca << endl;

    ll res = t2 + t3 - (2*t1) + a[lca];
    return res;
}

int main() {
    ll t = 0, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0;
    string s, s1, s2;

    scl1(t);

    for1(i, t) {
        scl1(n);

        cnt = 0;
        for1(j, n) adj[j].clear();

        for1(j, n) scl1(a[j]);
        for1(j, n-1) {
            scl2(x, y);
            x++, y++;
            adj[x].pb(y);
            adj[y].pb(x);
        }

        ms(par, -1);
        dfs(1, -1);
//        par[1][0] = -1;
        build(1, 1, n);
        lca_build();

        scl1(q);

        printcase;
        while(q--) {
            scl3(p, x, y);
            if(p == 0) {
                x++, y++;
                ans = get_num(x, y);
                printl(ans);
            }
            else {
                x++;
                p = a[x];
                a[x] = y;
                update(1, 1, n, st[x], en[x], y, p);
            }
        }
    }

    return 0;
}

