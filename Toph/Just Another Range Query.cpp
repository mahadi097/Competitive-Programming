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

map <ll, ll> tree;
map <ll, ll> lazy;

void propagate(ll node, ll r1, ll r2) {
    tree[node] += (r2 - r1 + 1) * lazy[node];

    if(r1 != r2) {
        tree[node*2] += lazy[node];
        tree[node*2+1] += lazy[node];
    }
    lazy[node] = 0;
}

void update(ll node, ll r1, ll r2, ll i, ll j, ll val) {
    ll bam = node*2;
    ll dan = bam + 1;

    if(lazy[node]) propagate(node, r1, r2);
    if(r1 > j || r2 < i) return;
    if(r1 >= i && r2 <= j) {
        tree[node] += (r2 - r1 + 1) * val;
        if(r1 != r2) {
            lazy[bam] += val;
            lazy[dan] += val;
        }
        return;
    }

    ll mid = (r1 + r2) / 2;

    update(bam, r1, mid, i, j, val);
    update(dan, mid+1, r2, i, j, val);

    tree[node] = tree[bam] + tree[dan];
}

ll query(ll node, ll r1, ll r2, ll i, ll j) {
    ll bam = node*2;
    ll dan = bam + 1;

    if(lazy[node]) propagate(node, r1, r2);
    if(r1 > j || r2 < i) return 0;
    if(r1 >= i && r2 <= j) return tree[node];

    ll mid = (r1 + r2) / 2;

    ll p1 = query(bam, r1, mid, i, j);
    ll p2 = query(dan, mid+1, r2, i, j);

    return (p1+p2);
}

int main() {
    ll t = 0, n, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0;
    scl2(n, q);

    while(q--) {
        scl1(t);
        scl2(x, y);

        if(t == 1) {
            scl1(z);

            update(1, 1, n, x, y, z);
        }
        else {
            ans = query(1, 1, n, x, y);

            c = x-1;

            sum = (y * (y+1)) / 2;
            c = (c * (c+1)) / 2;
            sum -= c;

            ans = c - ans;
            printl(ans);
        }
    }

    return 0;
}

