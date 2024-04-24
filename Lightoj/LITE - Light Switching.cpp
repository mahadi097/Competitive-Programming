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

ll a[SIZE];
struct info {
    ll res, lazy;
} tree[SIZE*4];

void update(ll node, ll r1, ll r2, ll i, ll j) {
    if(r1 > j || r2 < i) return;
    if(r1 >= i && r2 <= j) {
        tree[node].lazy ^= 1;
        tree[node].res = (r2 - r1 + 1) - tree[node].res;
        return;
    }

    ll bam = node*2;
    ll dan = bam + 1;

    ll mid = (r1 + r2) / 2;

    update(bam, r1, mid, i, j);
    update(dan, mid+1, r2, i, j);

    tree[node].res = tree[bam].res + tree[dan].res;
    if(tree[node].lazy) tree[node].res = (r2 - r1 + 1) - tree[node].res;
}

ll query(ll node, ll r1, ll r2, ll i, ll j, ll carry) {
    if(r1 > j || r2 < i) return 0;
    if(r1 >= i && r2 <= j) {
        if(carry) return ((r2 - r1 + 1) - tree[node].res);
        return tree[node].res;
    }

    ll bam = node*2;
    ll dan = bam + 1;

    ll mid = (r1 + r2) / 2;

    ll p1 = query(bam, r1, mid, i, j, carry^tree[node].lazy);
    ll p2 = query(dan, mid+1, r2, i, j, carry^tree[node].lazy);

    return (p1+p2);
}

int main() {
    ll t = 0, n, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0;
    scl2(n, q);

    while(q--) {
        scl1(c);

        if(!c) {
            scl2(i, j);
            update(1, 1, n, i, j);
        }
        else {
            scl2(i, j);
            ans = query(1, 1, n, i, j, 0);
            printl(ans);
        }
    }

    return 0;
}

