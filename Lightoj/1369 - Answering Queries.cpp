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
#define printcase       printf("Case %lld:\n", i)
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

ll tree[SIZE*4];
ll n, a[SIZE];

void build(ll node, ll r1, ll r2) {
    if(r1 == r2) {
        ll add = (n - r1) * a[r1];
        ll sub = (r1 - 1) * a[r1];
        tree[node] = add - sub;
        return;
    }

    ll bam = node*2;
    ll dan = bam + 1;
    ll mid = (r1 + r2) / 2;

    build(bam, r1, mid);
    build(dan, mid+1, r2);

    tree[node] = tree[bam] + tree[dan];
}

void update(ll node, ll r1, ll r2, ll in, ll val) {
    if(r1 > in || r2 < in) return;
    if(r1 == in && r2 == in) {
        ll add = (n - r1) * val;
        ll sub = (r1 - 1) * val;
        tree[node] = add - sub;
        return;
    }

    ll bam = node*2;
    ll dan = bam + 1;
    ll mid = (r1 + r2) / 2;

    update(bam, r1, mid, in, val);
    update(dan, mid+1, r2, in, val);

    tree[node] = tree[bam] + tree[dan];
}

int main() {
    ll t = 0, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0;
    scl1(t);

    for1(i, t) {
        scl2(n, q);

        for1(j, n) scl1(a[j]);

        build(1, 1, n);

        printcase;

        while(q--) {
            scl1(p);

            if(!p) {
                scl2(x, y);
                update(1, 1, n, x+1, y);
            }
            else printl(tree[1]);
        }
    }

    return 0;
}

