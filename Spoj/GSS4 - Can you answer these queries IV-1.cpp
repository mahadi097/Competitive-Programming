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
#define printcase       printf("Case #%lld:\n", t)
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

ll a[SIZE];
ll tree[SIZE*4];
ll lazy[SIZE*4];

void build(ll node, ll r1, ll r2) {
    if(r1 == r2) {
        tree[node] = a[r1];
        lazy[node] = a[r1];
        if(tree[node] == 1) lazy[node] = 0;
        return;
    }

    ll bam = node*2;
    ll dan = bam + 1;

    ll mid = (r1 + r2) / 2;

    build(bam, r1, mid);
    build(dan, mid+1, r2);

    tree[node] = tree[bam] + tree[dan];
    lazy[node] = lazy[bam] + lazy[dan];
}

void update(ll node, ll r1, ll r2, ll i, ll j) {
    if(r1 > j || r2 < i || lazy[node] == 0) return;
    if(r1 == r2) {
        tree[node] = sqrt(tree[node]);
        if(tree[node] == 1) lazy[node] = 0;
        return;
    }

    ll bam = node*2;
    ll dan = bam + 1;

    ll mid = (r1 + r2) / 2;

    update(bam, r1, mid, i, j);
    update(dan, mid+1, r2, i, j);

    tree[node] = tree[bam] + tree[dan];
    lazy[node] = lazy[bam] + lazy[dan];
}

ll query(ll node, ll r1, ll r2, ll i, ll j) {
    if(r1 > j || r2 < i) return 0;
    if(r1 >= i && r2 <= j) return tree[node];

    ll bam = node*2;
    ll dan = bam + 1;

    ll mid = (r1 + r2) / 2;

    ll p1 = query(bam, r1, mid, i, j);
    ll p2 = query(dan, mid+1, r2, i, j);

    return (p1+p2);
}

int main() {
    ll t = 0, n, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0;

    while(scl1(n) == 1) {
        for1(i, n) scl1(a[i]);

        build(1, 1, n);

        scl1(q);

        t++;
        printcase;

        while(q--) {
            scl1(c);
            scl2(x, y);

            if(x > y) swap(x, y);

            if(!c) update(1, 1, n, x, y);
            else {
                ans = query(1, 1, n, x, y);
                printl(ans);
            }
        }
        newline;
    }

    return 0;
}

