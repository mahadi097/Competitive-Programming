#include <bits/stdc++.h>
using namespace std;


//TEMPLATE
#define pb              push_back
#define mp              make_pair
#define ll              long long
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
#define printcase       printf("Case %lld: ", i)
#define reversed(s)     reverse(s.begin(), s.end())
#define asorted(s)      sort(s.begin(), s.end())
#define dsorted(s)      sort(s.begin(), s.end(), cmp)
#define for0(i, n)      for (i = 0; i < n; i++)
#define for1(i, n)      for (i = 1; i <= n; i++)
#define pii             pair <ll, ll>
#define piii            pair <ll, pii>
#define SIZE            50005
#define INF             1000000005
#define F               first
#define S               second
#define FR              ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ms(arr, x)      memset(arr, x, sizeof arr)
#define bitcount(n)     __builtin_popcountll(n)

struct info {
    ll sum, max_sum, prefix, suffix;
} tree[SIZE*4];
ll a[SIZE];

void build(ll node, ll r1, ll r2) {
    if(r1 == r2) {
        tree[node].sum = a[r1];
        tree[node].max_sum = a[r1];
        tree[node].prefix = a[r1];
        tree[node].suffix = a[r1];
        return;
    }

    ll bam = node*2;
    ll dan = bam + 1;

    ll mid = (r1 + r2) / 2;

    build(bam, r1, mid);
    build(dan, mid+1, r2);

    tree[node].sum = tree[bam].sum + tree[dan].sum;
    tree[node].prefix = max(tree[bam].prefix, tree[bam].sum+tree[dan].prefix);
    tree[node].suffix = max(tree[dan].suffix, tree[dan].sum+tree[bam].suffix);
    tree[node].max_sum = max(max(tree[bam].max_sum, tree[dan].max_sum), max(tree[node].sum, tree[bam].suffix+tree[dan].prefix));
}

info query(ll node, ll r1, ll r2, ll i, ll j) {
    if(r1 > j || r2 < i) {
        info p;
        p.sum = -1e9, p.max_sum = -1e9, p.prefix = -1e9, p.suffix = -1e9;
        return p;
    }
    if(r1 >= i && r2 <= j) return tree[node];

    ll bam = node*2;
    ll dan = bam + 1;

    ll mid = (r1 + r2) / 2;

    info p1 = query(bam, r1, mid, i, j);
    info p2 = query(dan, mid+1, r2, i, j);

    info p;
    p.sum = p1.sum + p2.sum;
    p.prefix = max(p1.prefix, p1.sum+p2.prefix);
    p.suffix = max(p2.suffix, p2.sum+p1.suffix);
    p.max_sum = max(max(p1.max_sum, p2.max_sum), max(p.sum, p1.suffix+p2.prefix));
    return p;
}

int main() {
    ll t = 0, n, x, y, z, i, j, k, g, p, q, sum = 0, c = 0;
    scl1(n);

    for1(i, n) scl1(a[i]);

    scl1(q);

    build(1, 1, n);

    while(q--) {
        scl2(x, y);

        info ans = query(1, 1, n, x, y);
        printl(ans.max_sum);
    }

    return 0;
}

