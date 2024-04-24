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

ll val[1005], dp[1005];
ll n;

ll lis(ll idx) {
    if(dp[idx] != -1) return dp[idx];
    ll maxi = 0;

    for(ll i = idx+1; i <= n; i++) {
        if(val[i] <= val[idx]) {
            ll longest = lis(i);

            if(longest > maxi) maxi = longest;
        }
    }
    dp[idx] = maxi + 1;
    return dp[idx];
}

int main() {
    ll t = 1, x, y, z, i, j, k, g, q, ans = 0, sum = 0, c = 0;

    while(scl1(x) == 1) {
        if(x == -1) return 0;

        memset(dp, -1, sizeof dp);

        if(t > 1) newline;

        val[1] = x;
        n = 1;

        while(scl1(x) == 1) {
            if(x == -1) break;
            n++;
            val[n] = x;
        }

        ans = 0;

        for1(i, n) {
            x = lis(i);

            ans = max(ans, x);
        }

        printf("Test #%lld:\n", t);
        printf("  maximum possible interceptions: %lld\n", ans);
        t++;
    }

    return 0;
}

