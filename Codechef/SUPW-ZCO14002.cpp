#include <bits/stdc++.h>
using namespace std;


//TEMPLATE
#define pb              push_back
#define mp              make_pair
#define ll              long long int
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
#define reversed(s)     reverse(s.begin(), s.end())
#define asorted(s)      sort(s.begin(), s.end())
#define dsorted(s)      sort(s.begin(), s.end(), descending_func)
#define for0(i, n)      for (i = 0; i < n; i++)
#define for1(i, n)      for (i = 1; i <= n; i++)
#define paired          pair <ll, ll>
#define pii             pair <ll, paired>
#define SIZE            200005
#define INF             1000000005

ll dp[SIZE][3];
ll n;
ll a[SIZE];

ll solve(ll i, ll now) {
    if(now == 3) return INF;
    if(i == n+1) return 0;
    if(dp[i][now] != -1) return dp[i][now];

    ll x = a[i] + solve(i+1, 0);
    ll y = solve(i+1, now+1);

    return dp[i][now] = min(x, y);
}

int main() {
    ll t = 0, x, y, z, i, j, k, g, q, ans = 0, sum = 0;
    memset(dp, -1, sizeof dp);
    scl1(n);

    for1(i, n) scl1(a[i]);

    ans = solve(1, 0);

    printl(ans);

    return 0;
}

