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
#define printcase       printf("Case %lld:\n", i)
#define reversed(s)     reverse(s.begin(), s.end())
#define asorted(s)      sort(s.begin(), s.end())
#define dsorted(s)      sort(s.begin(), s.end(), cmp)
#define for0(i, n)      for (i = 0; i < n; i++)
#define for1(i, n)      for (i = 1; i <= n; i++)
#define pii             pair <ll, ll>
#define piii            pair <ll, pii>
#define SIZE            150005
#define INF             1000000005
#define F               first
#define S               second
#define FR              ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ms(arr, x)      memset(arr, x, sizeof arr)
#define bitcount(n)     __builtin_popcountll(n)

ll tree[SIZE*4];
ll lazy[SIZE*4];
map <ll, ll> cnt;
set <ll> s;
ll a[SIZE], b[SIZE], point[SIZE];

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

    if(lazy[node] != 0) propagate(node, r1, r2);

    if(r1 > j || r2 < i) return;
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

ll query(ll node, ll r1, ll r2, ll in) {
    ll bam = node*2;
    ll dan = bam + 1;

    if(r1 > in || r2 < in) return 0;
    if(lazy[node] != 0) propagate(node, r1, r2);

    if(r1 == in && r2 == in) return tree[node];

    ll mid = (r1 + r2) / 2;

    ll p1 = query(bam, r1, mid, in);
    ll p2 = query(dan, mid+1, r2, in);

    return (p1+p2);
}

int main() {
    ll t = 0, n, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0;
    scl1(t);

    for1(i, t) {
        scl2(n, q);

        ms(tree, 0);
        ms(lazy, 0);
        s.clear();
        cnt.clear();

        for1(j, n) {
            scl2(a[j], b[j]);
            s.insert(a[j]);
            s.insert(b[j]);
        }

        for1(j, q) {
            scl1(point[j]);
            s.insert(point[j]);
        }

        set <ll> :: iterator it;
        p = 0;
        for(it = s.begin(); it != s.end(); it++) {
            cnt[*it] = ++p;
        }

        for1(j, n) {
            update(1, 1, p, cnt[a[j]], cnt[b[j]]);
        }

        printcase;
        for1(j, q) {
            ans = query(1, 1, p, cnt[point[j]]);
            printl(ans);
        }
    }

    return 0;
}

