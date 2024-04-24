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
#define SIZE            100005
#define INF             1000000005
#define F               first
#define S               second
#define FR              ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ms(arr, x)      memset(arr, x, sizeof arr)

struct info {
    ll one, two, three;
} tree[SIZE*4];
ll lazy[SIZE*4];

void build(ll node, ll r1, ll r2) {
    if(r1 == r2) {
        tree[node].one = 0;
        tree[node].two = 0;
        tree[node].three = 1;
        lazy[node] = 0;
        return;
    }

    ll bam = node*2;
    ll dan = bam + 1;

    ll mid = (r1 + r2) / 2;

    build(bam, r1, mid);
    build(dan, mid+1, r2);

    tree[node].one = 0;
    tree[node].two = 0;
    tree[node].three = (r2 - r1 + 1);
    lazy[node] = 0;
}

void propagate(ll node, ll r1, ll r2) {
    ll x, y, z, i, t;
    t = lazy[node] % 3;

    for1(i, t) {
        x = tree[node].one;
        y = tree[node].two;
        z = tree[node].three;

        tree[node].one = y;
        tree[node].two = z;
        tree[node].three = x;
    }

    if(r1 != r2) {
        lazy[node*2] += lazy[node];
        lazy[node*2+1] += lazy[node];
    }
    lazy[node] = 0;
}

void update(ll node, ll r1, ll r2, ll i, ll j) {
    ll bam = node*2;
    ll dan = bam + 1;
    ll x, y, z;

    if(lazy[node] != 0) propagate(node, r1, r2);

    if(r1 > j || r2 < i) return;
    if(r1 >= i && r2 <= j) {
        x = tree[node].one;
        y = tree[node].two;
        z = tree[node].three;

        tree[node].one = y;
        tree[node].two = z;
        tree[node].three = x;

        if(r1 != r2) {
            lazy[bam]++;
            lazy[dan]++;
        }
        return;
    }

    ll mid = (r1 + r2) / 2;

    update(bam, r1, mid, i, j);
    update(dan, mid+1, r2, i, j);

    tree[node].one = tree[bam].one + tree[dan].one;
    tree[node].two = tree[bam].two + tree[dan].two;
    tree[node].three = tree[bam].three + tree[dan].three;
}

ll query(ll node, ll r1, ll r2, ll i, ll j) {
    ll bam = node*2;
    ll dan = bam + 1;

    if(r1 > j || r2 < i) return 0;
    if(lazy[node] != 0) propagate(node, r1, r2);

    if(r1 >= i && r2 <= j) return tree[node].three;

    ll mid = (r1 + r2) / 2;

    ll p1 = query(bam, r1, mid, i, j);
    ll p2 = query(dan, mid+1, r2, i, j);

    return (p1 + p2);
}

int main() {
    ll t = 0, n, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0;
    scl1(t);

    for1(i, t) {
        scl2(n, q);

        build(1, 1, n);

        printcase;

        while(q--) {
            scl1(p);
            scl2(x, y);

            if(!p) update(1, 1, n, x+1, y+1);
            else {
                ans = query(1, 1, n, x+1, y+1);
                printl(ans);
            }
        }
    }

    return 0;
}

