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
const ll SIZE = 2e3+5;
const ll mod = 1e9+7;

ll r, c;
string s[2005];
ll his_mat[SIZE][SIZE];
ll his[SIZE];
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

    if(his[tree[bam]] <= his[tree[dan]]) tree[node] = tree[bam];
    else tree[node] = tree[dan];
}

ll query(ll node, ll r1, ll r2, ll i, ll j) {
    if(r1 > j || r2 < i) return INF;
    if(r1 >= i && r2 <= j) return tree[node];

    ll bam = node*2;
    ll dan = bam + 1;

    ll mid = (r1 + r2) / 2;

    ll p1 = query(bam, r1, mid, i, j);
    ll p2 = query(dan, mid+1, r2, i, j);

    if(p1 == INF) return p2;
    if(p2 == INF) return p1;

    if(his[p1] <= his[p2]) return p1;
    else return p2;
}

ll solve(ll r1, ll r2) {
    if(r1 > r2) return 0;
    if(r1 == r2) return his[r1];

    ll in = query(1, 1, c, r1, r2);
    ll ln = (r2 - r1 + 1) * his[in];

    ll p1 = solve(r1, in-1);
    ll p2 = solve(in+1, r2);

    return max(max(p1, p2), ln);
}

int main() {
    ll t = 0, n, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0;
    scl1(t);

    for1(i, t) {
        scl2(r, c);

        for1(j, r) cin >> s[j];

        ans = 0;

        for1(j, r) {
            for1(k, c) {
                if(s[j][k-1] == '1') his_mat[j][k] = 0;
                else his_mat[j][k] = his_mat[j-1][k] + 1;
                his[k] = his_mat[j][k];
            }

            build(1, 1, c);
            ans = max(ans, solve(1, c));
        }

        printcase;
        printl(ans);
    }

    return 0;
}

