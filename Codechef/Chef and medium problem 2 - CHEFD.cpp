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
const ll SIZE = 1e5+5;
const ll mod = 1e9+7;

ll a[SIZE];
ll tree[SIZE*4][4], lazy[SIZE*4][4];

void propagate(ll node, ll r1, ll r2, ll k) {
    tree[node][k] += lazy[node][k];
    if(r1 != r2) {
        lazy[node*2][k] += lazy[node][k];
        lazy[node*2+1][k] += lazy[node][k];
    }
    lazy[node][k] = 0;
}

void update1(ll node, ll r1, ll r2, ll i, ll j, ll in) {
    ll bam = node*2;
    ll dan = bam + 1;

    ll k;
    for1(k, 3) if(lazy[node][k]) propagate(node, r1, r2, k);

    if(r1 > j || r2 < i) return;

    if(r1 >= i && r2 <= j) {
        tree[node][in]++;

        if(r1 != r2) {
            lazy[bam][in]++;
            lazy[dan][in]++;
        }
        return;
    }

    ll mid = (r1 + r2) / 2;

    update1(bam, r1, mid, i, j, in);
    update1(dan, mid+1, r2, i, j, in);
}

void update2(ll node, ll r1, ll r2, ll in) {
    ll bam = node*2;
    ll dan = bam + 1;

    ll k;
    for1(k, 3) if(lazy[node][k]) propagate(node, r1, r2, k);

    if(r1 > in || r2 < in) return;

    if(r1 == in && r2 == in) {
        for1(k, 3) tree[node][k] = 0;
        return;
    }

    ll mid = (r1 + r2) / 2;

    update2(bam, r1, mid, in);
    update2(dan, mid+1, r2, in);
}

ll get_node_num(ll node, ll r1, ll r2, ll in) {
    ll bam = node*2;
    ll dan = bam + 1;

    ll k;
    for1(k, 3) if(lazy[node][k]) propagate(node, r1, r2, k);

    if(r1 > in || r2 < in) return 0;
    if(r1 == in && r2 == in) return node;

    ll mid = (r1 + r2) / 2;

    ll p1 = get_node_num(bam, r1, mid, in);
    ll p2 = get_node_num(dan, mid+1, r2, in);

    return (p1+p2);
}

void solve(ll in, ll node) {
    while(a[in]%2 == 0 && tree[node][1]) {
        a[in] /= 2;
        tree[node][1]--;
    }
    while(a[in]%3 == 0 && tree[node][2]) {
        a[in] /= 3;
        tree[node][2]--;
    }
    while(a[in]%5 == 0 && tree[node][3]) {
        a[in] /= 5;
        tree[node][3]--;
    }
}

int main() {
    ll t = 0, n, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0;
    scl1(n);

    for1(i, n) scl1(a[i]);

    scl1(q);

    while(q--) {
        scl1(p);
        scl2(x, y);

        if(p == 1) {
            scl1(z);

            if(z == 2) update1(1, 1, n, x, y, 1);
            if(z == 3) update1(1, 1, n, x, y, 2);
            if(z == 5) update1(1, 1, n, x, y, 3);
        }
        else {
            update2(1, 1, n, x);
            a[x] = y;
        }
    }

    for1(i, n) {
        k = get_node_num(1, 1, n, i);
        solve(i, k);

        printf("%lld ", a[i]);
    }
    newline;

    return 0;
}

