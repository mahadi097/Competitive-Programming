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
#define SIZE            100005
#define INF             1000000005
#define F               first
#define S               second
#define FR              ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ms(arr, x)      memset(arr, x, sizeof arr)

struct query {
    ll l, r, id;
} q[50005];
ll ans[50005];

ll n, total_q, block;
ll l, r, mx_cnt;
ll a[SIZE];
ll cnt[SIZE];
ll cnt_cnt[SIZE];

bool cmp(query a, query b) {
    ll l1 = a.l / block;
    ll l2 = b.l / block;

    if(l1 == l2) return a.r < b.r;
    return l1 < l2;
}

void add(ll in) {
    cnt_cnt[cnt[a[in]]]--;
    cnt[a[in]]++;
    cnt_cnt[cnt[a[in]]]++;
    mx_cnt = max(mx_cnt, cnt[a[in]]);
}

void remove(ll in) {
    cnt_cnt[cnt[a[in]]]--;
    cnt[a[in]]--;
    cnt_cnt[cnt[a[in]]]++;
    if(cnt_cnt[mx_cnt] == 0) mx_cnt--;
}

int main() {
    ll t = 0, x, y, z, i, j, k, g, p, sum = 0, c = 0;
    scl1(t);

    for1(i, t) {
        scl2(n, c);
        scl1(total_q);

        block = sqrt(n);
        l = 0, r = -1, mx_cnt = 0;
        ms(cnt, 0);
        ms(cnt_cnt, 0);

        for0(j, n) scl1(a[j]);

        for0(j, total_q) {
            scl2(q[j].l, q[j].r);
            q[j].l--, q[j].r--;
            q[j].id = j;
        }
        sort(q, q+total_q, cmp);

        for0(j, total_q) {
            while(l > q[j].l) add(--l);
            while(r < q[j].r) add(++r);
            while(l < q[j].l) remove(l++);
            while(r > q[j].r) remove(r--);
            ans[q[j].id] = mx_cnt;
        }

        printcase;
        for0(j, total_q) printl(ans[j]);
    }

    return 0;
}

