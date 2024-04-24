#include <bits/stdc++.h>
using namespace std;


//TEMPLATE
#define pb              push_back
#define mp              make_pair
#define ll              long long
#define ld              long double
//#define pi              3.1415926536
#define pi              acos(-1)
#define newline         printf("\n")
#define printminusone   printf("-1\n")
#define scl1(n)         scanf("%lld", &n)
#define scl2(a, b)      scanf("%lld %lld", &a, &b)
#define scl3(a, b, c)   scanf("%lld %lld %lld", &a, &b, &c)
#define printl(n)       printf("%lld\n", n)
#define ssl1(str)       scanf(" %[^\n]", str)
#define scd1(n)         scanf("%lf", &n)
#define scd2(a, b)      scanf("%lf %lf", &a, &b)
#define printd(n)       printf("%lf\n", n)
#define printld(n)      printf("%Lf\n", n)
#define printcase       printf("Case %lld: ", i)
#define reversed(s)     reverse(s.begin(), s.end())
#define asort(s)        sort(s.begin(), s.end())
#define dsort(s)        sort(s.rbegin(), s.rend())
#define for0(i, n)      for (i = 0; i < n; i++)
#define for1(i, n)      for (i = 1; i <= n; i++)
#define fori(itt, stt)  for(auto itt = stt.begin(); itt != stt.end(); itt++)
#define pii             pair <ll, ll>
#define piii            pair <ll, pii>
#define F               first
#define S               second
#define FR              ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ms(arr, x)      memset(arr, x, sizeof arr)
#define bitcount(n)     __builtin_popcountll(n)
#define all(s)          s.begin(), s.end()

const ll INF = LLONG_MAX;
const ll SZ = 1e5+5;
const ll mod = 1e9+7;


ll n, a[SZ];
vector <ll> tree[SZ*4];

void build(ll node, ll r1, ll r2) {
    if(r1 == r2) {
        tree[node].pb(a[r1]);
        return;
    }

    ll bam = node*2;
    ll dan = bam + 1;

    ll mid = (r1 + r2) / 2;

    build(bam, r1, mid);
    build(dan, mid+1, r2);

    merge(all(tree[bam]), all(tree[dan]), back_inserter(tree[node]));
}

ll query(ll node, ll r1, ll r2, ll i, ll j, ll v) {
    ll bam = node*2;
    ll dan = bam + 1;

    if(r1 > j || r2 < i) return 0;
    if(r1 >= i && r2 <= j) {
        ll res = upper_bound(all(tree[node]), v) - tree[node].begin();
        return res;
    }

    ll mid = (r1 + r2) / 2;

    ll p1 = query(bam, r1, mid, i, j, v);
    ll p2 = query(dan, mid+1, r2, i, j, v);

    return (p1+p2);
}

ll bs(ll i, ll j, ll k) {
    ll st = -1e9, en = 1e9, res = -1;
    while(st <= en) {
        ll mid = (st + en) / 2;

        ll c = query(1, 1, n, i, j, mid);
        if(c >= k) {
            res = mid;
            en = mid - 1;
        }
        else st = mid + 1;
    }
    return res;
}

int main() {
    FR;
    ll t = 0, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0;
    string s, s1, s2;

    cin >> n >> q;
    for1(i, n) cin >> a[i];

    build(1, 1, n);

    while(q--) {
        cin >> i >> j >> k;

        cout << bs(i, j, k) << "\n";
    }

    return 0;
}

