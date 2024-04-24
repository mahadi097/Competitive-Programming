#include <bits/stdc++.h>
using namespace std;


//TEMPLATE
#define pb              push_back
#define mp              make_pair
#define ll              long long
#define ld              long double
//#define pi              3.1415926536
#define pi              acos(-1)
//#define mod             1000000007
#define newline         printf("\n")
#define printminusone   printf("-1\n")
#define scl1(n)         scanf("%lld", &n)
#define scl2(a, b)      scanf("%lld %lld", &a, &b)
#define printl(n)       printf("%lld\n", n)
#define ssl1(str)       scanf(" %[^\n]", str)
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
#define fori(itt, stt)  for(itt = stt.begin(); itt != stt.end(); itt++)
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
const ll SIZE = 5e4+5;
const ll mod = 1e9+7;

ll a[SIZE];
ll tree_mx[SIZE*4], tree_mn[SIZE*4];
vector <ll> tree2[SIZE*4], tree3[SIZE*4];

void build(ll node, ll r1, ll r2) {
    if(r1 == r2) {
        tree_mx[node] = a[r1];
        tree_mn[node] = a[r1];
        tree2[node].pb(a[r1]);
        tree3[node].pb(a[r1]);
        return;
    }

    ll bam = node*2;
    ll dan = bam + 1;

    ll mid = (r1 + r2) / 2;

    build(bam, r1, mid);
    build(dan, mid+1, r2);

    tree_mx[node] = max(tree_mx[bam], tree_mx[dan]);
    tree_mn[node] = min(tree_mn[bam], tree_mn[dan]);

    tree2[node].resize(tree2[bam].size() + tree2[dan].size());
    merge(tree2[bam].begin(), tree2[bam].end(), tree2[dan].begin(), tree2[dan].end(), tree2[node].begin());

    tree3[node].resize(tree3[bam].size() + tree3[dan].size());
    ll i;
    for0(i, tree2[node].size()) {
        if(i == 0) tree3[node][i] = tree2[node][i];
        else tree3[node][i] = tree3[node][i-1] + tree2[node][i];
    }
}

ll query_mx(ll node, ll r1, ll r2, ll i, ll j) {
    ll bam = node*2;
    ll dan = bam + 1;

    if(r1 > j || r2 < i) return 0;
    if(r1 >= i && r2 <= j) return tree_mx[node];

    ll mid = (r1 + r2) / 2;

    ll p1 = query_mx(bam, r1, mid, i, j);
    ll p2 = query_mx(dan, mid+1, r2, i, j);

    return max(p1, p2);
}

ll query_mn(ll node, ll r1, ll r2, ll i, ll j) {
    ll bam = node*2;
    ll dan = bam + 1;

    if(r1 > j || r2 < i) return INF;
    if(r1 >= i && r2 <= j) return tree_mn[node];

    ll mid = (r1 + r2) / 2;

    ll p1 = query_mn(bam, r1, mid, i, j);
    ll p2 = query_mn(dan, mid+1, r2, i, j);

    return min(p1, p2);
}

ll query2(ll node, ll r1, ll r2, ll i, ll j, ll val) {
    ll bam = node*2;
    ll dan = bam + 1;

    if(r1 > j || r2 < i) return 0;
    if(r1 >= i && r2 <= j) {
        ll x, y, sz = tree3[node].size();
        ll pos = lower_bound(tree2[node].begin(), tree2[node].end(), val) - tree2[node].begin();

        if(pos == 0) x = 0;
        else {
            x = tree3[node][pos-1];
            x = (val * pos) - x;
        }

        pos = upper_bound(tree2[node].begin(), tree2[node].end(), val) - tree2[node].begin();
        if(pos == sz) y = 0;
        else if(pos == 0) {
            y = tree3[node][sz-1];
            y = y - (val * sz);
        }
        else {
            y = tree3[node][sz-1] - tree3[node][pos-1];
            ll t = sz - pos;
            y = y - (val * t);
        }

//        cout << r1 << " " << r2 << " ";
//        cout << val << " ";
//        cout << x << " " << y << endl;

        return (x+y);
    }

    ll mid = (r1 + r2) / 2;

    ll p1 = query2(bam, r1, mid, i, j, val);
    ll p2 = query2(dan, mid+1, r2, i, j, val);

    return (p1+p2);
}

int main() {
    ll t = 0, n, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0;
    scl1(t);

    while(t--) {
        scl2(n, q);

        for1(i, n) scl1(a[i]);

        build(1, 1, n);

        while(q--) {
            scl2(x, y);

            ans = INF;

            ll st = query_mn(1, 1, n, x, y);
            ll en = query_mx(1, 1, n, x, y);

            j = st, k = en;

            while(st <= en) {
                ll mid = (st + en) / 2;

                p = query2(1, 1, n, x, y, mid);
//                newline;

                if(p < ans) {
                    ans = p;
//                    cout << p << " " << mid << endl;
                    st = mid + 1;
                }
                else en = mid - 1;
            }
            c = ans;
//            newline;
//            newline;
//            printl(ans);

            ans = INF;
            st = j, en = k;
            while(st <= en) {
                ll mid = (st + en) / 2;

                p = query2(1, 1, n, x, y, mid);

                if(p < ans) {
                    ans = p;
                    en = mid - 1;
                }
                else st = mid + 1;
            }

            ans = min(ans, c);

            printl(ans);
        }
    }

    return 0;
}

