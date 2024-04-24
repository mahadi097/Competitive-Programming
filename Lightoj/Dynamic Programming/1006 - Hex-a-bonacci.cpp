#include <bits/stdc++.h>
using namespace std;


//TEMPLATE
#define pb              push_back
#define mp              make_pair
#define ll              long long int
#define pi              3.1415926536
#define mod             10000007
#define newline         printf("\n")
#define printminusone   printf("-1\n")
#define scl1(n)         scanf("%lld", &n)
#define scl2(a, b)      scanf("%lld %lld", &a, &b)
#define printl(n)       printf("%lld\n", n)
#define scd1(n)         scanf("%lf", &n)
#define scd2(a, b)      scanf("%lf %lf", &a, &b)
#define printd(n)       printf("%lf\n", n)
#define reversed(s)     reverse(s.begin(), s.end())
#define asorted(s)      sort(s.begin(), s.end())
#define dsorted(s)      sort(s.begin(), s.end(), descending_func)
#define for0(i, n)      for (i = 0; i < n; i++)
#define for1(i, n)      for (i = 1; i <= n; i++)
#define paired          pair <ll, ll>
#define pii             pair <ll, paired>
#define SIZE            10005
#define INF             1000000005

ll dp[SIZE];
ll a[6];
//ll a, b, c, d, e, f;

ll solve(ll n) {
    if(n == 0) return a[0];
    if(n == 1) return a[1];
    if(n == 2) return a[2];
    if(n == 3) return a[3];
    if(n == 4) return a[4];
    if(n == 5) return a[5];

    if(dp[n]) return dp[n];

    dp[n] = (solve(n-1) % mod + solve(n-2) % mod + solve(n-3) % mod + solve(n-4) % mod + solve(n-5) % mod + solve(n-6) % mod) % mod;
    return dp[n];
}

int main() {
    ll t, n, x, y, z, i, j, k, g, q, ans = 0, sum = 0;
    scl1(t);

    for1(i, t) {
        for0(j, 6) {
            scl1(a[j]);
        }
        scl1(n);

        memset(dp, 0, sizeof dp);

        ans = solve(n) % mod;

        printf("Case %lld: %lld\n", i, ans);
    }


    return 0;
}

