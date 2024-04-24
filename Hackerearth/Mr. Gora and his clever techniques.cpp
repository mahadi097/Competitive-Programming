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
const ll SIZE = 6e5+5;
const ll mod = 1e9+7;

struct query_info {
    int t, x, y, k;
} qq[SIZE];

int a[SIZE];
vector <int> tree[SIZE*4];

void build(int node, int r1, int r2) {
    if(r1 == r2) {
        tree[node].pb(a[r1]);
        return;
    }

    int bam = node << 1;
    int dan = bam + 1;

    int mid = (r1 + r2) >> 1;

    build(bam, r1, mid);
    build(dan, mid+1, r2);

    tree[node].resize(tree[bam].size() + tree[dan].size());
    merge(tree[bam].begin(), tree[bam].end(), tree[dan].begin(), tree[dan].end(), tree[node].begin());

//    merge(tree[bam].begin(), tree[bam].end(), tree[dan].begin(), tree[dan].end(), back_inserter(tree[node]));
}

int query(int node, int r1, int r2, int i, int j, int type, int val) {
    int bam = node << 1;
    int dan = bam + 1;

    if(r1 > j || r2 < i) return 0;

    if(r1 >= i && r2 <= j) {
        if(type == 2) return lower_bound(tree[node].begin(), tree[node].end(), val) - tree[node].begin();
        else if(type == 3) {
            int r1 = lower_bound(tree[node].begin(), tree[node].end(), val) - tree[node].begin();
            int r2 = upper_bound(tree[node].begin(), tree[node].end(), val) - tree[node].begin();
            return (r2-r1);
        }
        else {
            int res = upper_bound(tree[node].begin(), tree[node].end(), val) - tree[node].begin();
            res = tree[node].size() - res;
            return res;
        }
    }

    int mid = (r1 + r2) >> 1;

    int p1 = query(bam, r1, mid, i, j, type, val);
    int p2 = query(dan, mid+1, r2, i, j, type, val);

    return (p1+p2);
}

int main() {
    FR;
    int t = 0, n = 0, i, k, q, ans = 0;

    cin >> q;

    for1(i, q) {
        cin >> t;
        qq[i].t = t;

        if(t == 1) {
            cin >> k;
            a[++n] = k;
        }
        else {
            cin >> qq[i].x >> qq[i].y >> qq[i].k;
        }
    }

    build(1, 1, n);

    for1(i, q) {
        if(qq[i].t != 1) {
            ans = query(1, 1, n, qq[i].x, qq[i].y, qq[i].t, qq[i].k);
            cout << ans << "\n";
        }
    }

    return 0;
}
