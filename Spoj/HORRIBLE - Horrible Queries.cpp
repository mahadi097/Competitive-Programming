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
    ll sum, lazy;
} tree[SIZE*4];

void update(ll node, ll r1, ll r2, ll i, ll j, ll val) {
    if(i > r2 || j < r1) return;
    if(r1 >= i && r2 <= j) {
        tree[node].sum += (val * (r2 - r1 + 1));
        tree[node].lazy += val;
        return;
    }

    ll bam = node*2;
    ll dan = node*2 + 1;

    ll mid = (r1 + r2) / 2;

    update(bam, r1, mid, i, j, val);
    update(dan, mid+1, r2, i, j, val);

    tree[node].sum = tree[bam].sum + tree[dan].sum + tree[node].lazy * (r2 - r1 + 1);
}

ll query(ll node, ll r1, ll r2, ll i, ll j, ll carry) {
    if(i > r2 || j < r1) return 0;
    if(r1 >= i && r2 <= j) return tree[node].sum + carry * (r2 - r1 + 1);

    ll bam = node*2;
    ll dan = node*2 + 1;

    ll mid = (r1 + r2) / 2;

    ll p1 = query(bam, r1, mid, i, j, carry+tree[node].lazy);
    ll p2 = query(dan, mid+1, r2, i, j, carry+tree[node].lazy);

    return (p1+p2);
}

int main() {
    ll t = 0, n, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0;
    scl1(t);

    while(t--) {
        scl2(n, q);

        for1(i, n*4) {
            tree[i].sum = 0;
            tree[i].lazy = 0;
        }

        while(q--) {
            scl1(p);
            scl2(x, y);

            switch(p) {
            case 0:
                scl1(z);
                update(1, 1, n, x, y, z);
                break;
            case 1:
                ans = query(1, 1, n, x, y, 0);
                printl(ans);
                break;
            }
        }
    }

    return 0;
}

