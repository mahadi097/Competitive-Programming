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
#define SIZE            200005
#define INF             1000000005
#define F               first
#define S               second
#define FR              ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ms(arr, x)      memset(arr, x, sizeof arr)

struct query {
    ll l, r, id;
} q[SIZE];
ll ans[SIZE];
ll cnt[1000005];

ll n, total_q, block_size;
ll l = 0, r = -1, total = 0;
ll a[30005];

bool cmp(query a, query b) {
    ll block_a = a.l / block_size;
    ll block_b = b.l / block_size;

    if(block_a == block_b) return a.r < b.r;
    return block_a < block_b;
}

void add(ll in) {
    cnt[a[in]]++;
    if(cnt[a[in]] == 1) total++;
}

void remove(ll in) {
    cnt[a[in]]--;
    if(cnt[a[in]] == 0) total--;
}

int main() {
    ll t = 0, x, y, z, i, j, k, g, p, c = 0;
    scl1(n);

    for0(i, n) scl1(a[i]);

    block_size = sqrt(n);

    scl1(total_q);

    for0(i, total_q) {
        scl2(x, y);
        x--, y--;
        q[i].l = x, q[i].r = y;
        q[i].id = i;
    }
    sort(q, q+total_q, cmp);

    for0(i, total_q) {
        while(l > q[i].l) add(--l);
        while(r < q[i].r) add(++r);
        while(l < q[i].l) remove(l++);
        while(r > q[i].r) remove(r--);
        ans[q[i].id] = total;
    }

    for0(i, total_q) {
        printl(ans[i]);
    }

    return 0;
}

