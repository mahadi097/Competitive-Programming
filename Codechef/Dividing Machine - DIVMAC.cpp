#include <bits/stdc++.h>
using namespace std;


//TEMPLATE
#define pb              push_back
#define mp              make_pair
#define ll              long long
#define ld              long double
#define pi              3.1415926536
//#define mod             1000000007
#define newline         printf("\n")
#define printminusone   printf("-1\n")
#define scl1(n)         scanf("%lld", &n)
#define scl2(a, b)      scanf("%lld %lld", &a, &b)
#define printl(n)       printf("%lld\n", n)
#define scd1(n)         scanf("%lf", &n)
#define scd2(a, b)      scanf("%lf %lf", &a, &b)
#define printd(n)       printf("%lf\n", n)
#define printld(n)      printf("%Lf\n", n)
#define printcase       printf("Case %lld: ", i)
#define reversed(s)     reverse(s.begin(), s.end())
#define asorted(s)      sort(s.begin(), s.end())
#define dsorted(s)      sort(s.begin(), s.end(), cmp)
#define for0(i, n)      for (i = 0; i < n; i++)
#define for1(i, n)      for (i = 1; i <= n; i++)
#define pii             pair <ll, ll>
#define piii            pair <ll, pii>
//#define SIZE            100005
//#define INF             1000000005
#define F               first
#define S               second
#define FR              ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ms(arr, x)      memset(arr, x, sizeof arr)
#define bitcount(n)     __builtin_popcountll(n)

const ll INF = 1e18;
const ll SIZE1 = 1e6+5;
const ll SIZE2 = 1e5+5;
const ll mod = 1e9+7;

vector <ll> prime;
bool st[SIZE1];
void sieve() {
    ll i, j;

    for(i = 3; i*i < SIZE1; i += 2) {
        if(!st[i]) {
            for(j = i*i; j < SIZE1; j += i) st[j] = 1;
        }
    }

    prime.pb(2);
    for(i = 3; i < SIZE1; i += 2) {
        if(!st[i]) prime.pb(i);
    }
}

ll a[SIZE2];
deque <ll> dq[SIZE2];
ll tree[SIZE2*4];

void build(ll node, ll r1, ll r2) {
    if(r1 == r2) {
        if(dq[r1].size()) tree[node] = dq[r1][0];
        else tree[node] = 1;
        return;
    }

    ll bam = node*2;
    ll dan = bam + 1;

    ll mid = (r1 + r2) / 2;

    build(bam, r1, mid);
    build(dan, mid+1, r2);

    tree[node] = max(tree[bam], tree[dan]);
}

void update(ll node, ll r1, ll r2, ll i, ll j) {
    ll bam = node*2;
    ll dan = bam + 1;

    if(r1 > j || r2 < i || tree[node] == 1) return;
    if(r1 == r2) {
        dq[r1].pop_front();
        if(dq[r1].size()) tree[node] = dq[r1][0];
        else tree[node] = 1;
        return;
    }

    ll mid = (r1 + r2) / 2;

    update(bam, r1, mid, i, j);
    update(dan, mid+1, r2, i, j);

    tree[node] = max(tree[bam], tree[dan]);
}

ll query(ll node, ll r1, ll r2, ll i, ll j) {
    ll bam = node*2;
    ll dan = bam + 1;

    if(r1 > j || r2 < i) return 0;
    if(r1 >= i && r2 <= j) return tree[node];

    ll mid = (r1 + r2) / 2;

    ll p1 = query(bam, r1, mid, i, j);
    ll p2 = query(dan, mid+1, r2, i, j);

    return max(p1, p2);
}

int main() {
    sieve();
    ll t = 0, n, x, y, z, i, j, k, g, p, q, sum = 0, c = 0;
    scl1(t);

    while(t--) {
        scl2(n, q);

        for1(i, n) scl1(a[i]);

        for1(i, n) {
            x = a[i];
            dq[i].clear();

            for(j = 0; j < prime.size() && x > 1 && prime[j]*prime[j] <= a[i]; j++) {
                if(x%prime[j] == 0) {
                    while(x%prime[j] == 0) {
                        x /= prime[j];
                        dq[i].pb(prime[j]);
                    }
                }
            }

            if(x > 1) dq[i].pb(x);
        }

        build(1, 1, n);
        vector <ll> ans;

        while(q--) {
            scl1(p);
            scl2(x, y);

            if(!p) {
                update(1, 1, n, x, y);
            }
            else {
                c = query(1, 1, n, x, y);
                ans.pb(c);
            }
        }

        for0(i, ans.size()) {
            if(i > 0) printf(" ");
            printf("%lld", ans[i]);
        }
        newline;
    }

    return 0;
}

