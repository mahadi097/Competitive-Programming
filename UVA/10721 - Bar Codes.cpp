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
const ll SIZE = 55;
const ll mod = 1e9+7;


ll n, k, m;
ll dp[SIZE][SIZE][SIZE];

ll solve(ll rem, ll mx, ll bar) {
    if(bar == 0 && rem == 0) return 1;
    if(bar && rem == 0) return 0;
    if(dp[rem][bar][mx] != -1) return dp[rem][bar][mx];

    ll i, res(0);

    for1(i, mx) {
        if(rem-i >= 0) res += solve(rem-i, mx, bar-1);
    }

    return dp[rem][bar][mx] = res;
}

int main() {
    ll t = 0, x, y, z, i, j, g, p, q, ans = 0, sum = 0, c = 0;
    string s, s1, s2;

    ms(dp, -1);

    while(scl3(n, k, m) == 3) {
        ans = solve(n, m, k);
        printl(ans);
    }

    return 0;
}

