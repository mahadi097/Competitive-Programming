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
#define SIZE            30005
#define INF             1000000005
#define F               first
#define S               second
#define FR              ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ms(arr, x)      memset(arr, x, sizeof arr)
#define bitcount(n)     __builtin_popcountll(n)

ll n, a[SIZE];
ll tree[SIZE*4];

void build(ll node, ll r1, ll r2) {
    if(r1 == r2) {
        tree[node] = r1;
        return;
    }

    ll bam = node*2;
    ll dan = bam + 1;

    ll mid = (r1 + r2) / 2;

    build(bam, r1, mid);
    build(dan, mid+1, r2);

    if(a[tree[bam]] < a[tree[dan]]) tree[node] = tree[bam];
    else tree[node] = tree[dan];
}

ll query(ll node, ll r1, ll r2, ll i, ll j) {
    if(r1 > j || r2 < i) return INF;
    if(r1 >= i && r2 <= j) return tree[node];

    ll bam = node*2;
    ll dan = bam + 1;

    ll mid = (r1 + r2) / 2;

    ll in1 = query(bam, r1, mid, i, j);
    ll in2 = query(dan, mid+1, r2, i, j);

    if(in1 == INF) return in2;
    if(in2 == INF) return in1;
    if(a[in1] < a[in2]) return in1;
    else return in2;
}

ll solve(ll r1, ll r2) {
    if(r1 > r2) return 0;
    if(r1 == r2) return a[r1];

    ll in = query(1, 1, n, r1, r2);
    ll ln = (r2 - r1 + 1) * a[in];

    ll p1 = solve(r1, in-1);
    ll p2 = solve(in+1, r2);

    return max(max(p1, p2), ln);
}

int main() {
    ll t = 0, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0;
    scl1(t);

    for1(i, t) {
        scl1(n);
        for1(j, n) scl1(a[j]);

        build(1, 1, n);

        ans = solve(1, n);

        printcase;
        printl(ans);
    }


    return 0;
}

