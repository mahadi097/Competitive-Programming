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
const ll SIZE = 3e5+5;
const ll mod = 1e9+7;


ll dp[42][302][302];
ll n, total;
ll a[42], b[42];

ll solve(ll in, ll x, ll y) {
    if(x*x+y*y == total*total) return 0;
    if(in == n+1) return INF;
    if(dp[in][x][y] != -1) return dp[in][x][y];

    ll res, p(INF);

    for(ll t = 0; ; t++) {
        ll x1 = x + (a[in]*t);
        ll y1 = y + (b[in]*t);

        if(x1*x1+y1*y1 <= total*total) res = t + solve(in+1, x1, y1);
        else break;

        p = min(p, res);
    }

    return dp[in][x][y] = p;
}

int main() {
    ll t = 0, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0;
    string s, s1, s2;

    scl1(t);

    while(t--) {
        scl2(n, total);
        for1(i, n) scl2(a[i], b[i]);

        ms(dp, -1);

        ans = solve(1, 0, 0);

        if(ans >= INF) puts("not possible");
        else printl(ans);
    }

    return 0;
}

