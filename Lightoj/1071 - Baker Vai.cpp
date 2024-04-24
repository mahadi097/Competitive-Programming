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
#define scl3(a, b, c)   scanf("%lld %lld %lld", &a, &b, &c)
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
#define fori(itt, stt)  for(auto itt = stt.begin(); itt != stt.end(); itt++)
#define pii             pair <ll, ll>
#define piii            pair <ll, pii>
//#define SIZE            100005
//#define INF             1000000005
#define F               first
#define S               second
#define FR              ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ms(arr, x)      memset(arr, x, sizeof arr)
#define bitcount(n)     __builtin_popcountll(n)

const ll INF = 1e16;
const ll SIZE = 100+5;
const ll mod = 1e9+7;


ll dp[SIZE][SIZE][SIZE];
ll a[SIZE][SIZE];
ll r, c;

ll solve(ll i, ll j, ll k) {
    if(i < 1 || i > r || j < 1 || j > c) return 0;
    if(i == r && j == c && k == c) return a[i][j];
    if(dp[i][j][k] != -1) return dp[i][j][k];

    ll c1, c2, t, t1(0), t2(0), res(0);

    for(c2 = k; c2 <= c; c2++) {
        t2 += a[i][c2];
        t1 = 0;
        for(c1 = j; c1 < k; c1++) {
            t1 += a[i][c1];
            t = t1 + t2 + solve(i+1, c1, c2);
            res = max(res, t);
        }
    }

    return dp[i][j][k] = res;
}

int main() {
    ll t = 0, n, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0;
    string s, s1, s2;

    scl1(t);

    for1(i, t) {
        scl2(r, c);
        for1(j, r) for1(k, c) scl1(a[j][k]);

        ms(dp, -1);

        ans = solve(1, 1, 2);

        printcase;
        printl(ans);
    }

    return 0;
}

