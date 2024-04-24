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
#define pii             pair <ll, ll>
#define piii            pair <ll, paired>
#define SIZE            100005
#define INF             1000000005
#define F               first
#define S               second

ll n, k;
ll dp[505][505];
ll a[505];

ll solve(ll idx, ll t) {
    if(idx == n+1) {
        if(t == k) return 0;
        else return INF;
    }
    if(t > k) return INF;
    if(dp[idx][t] != -1) return dp[idx][t];

    dp[idx][t] = INF;

    ll b = 0, w = 0;

    for(ll i = idx; i <= n; i++) {
        if(a[i] == 1) b++;
        else w++;

        dp[idx][t] = min(dp[idx][t], b*w + solve(i+1, t+1));
    }
    return dp[idx][t];
}

int main() {
    ll t = 0, x, y, z, i, j, g, q, ans = 0, sum = 0, c = 0;
    scl2(n, k);

    for1(i, n) scl1(a[i]);

    memset(dp, -1, sizeof dp);

    ans = solve(1, 0);

    printl(ans);

    return 0;
}

