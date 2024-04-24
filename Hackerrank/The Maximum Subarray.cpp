#include <bits/stdc++.h>
using namespace std;


//TEMPLATE
#define pb              push_back
#define mp              make_pair
#define ll              long long
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
#define printcase       printf("Case %lld: ", i)
#define reversed(s)     reverse(s.begin(), s.end())
#define asorted(s)      sort(s.begin(), s.end())
#define dsorted(s)      sort(s.begin(), s.end(), descending_func)
#define for0(i, n)      for (i = 0; i < n; i++)
#define for1(i, n)      for (i = 1; i <= n; i++)
#define pii             pair <ll, ll>
#define piii            pair <ll, pii>
#define SIZE            100005
#define INF             1000000005
#define F               first
#define S               second
#define FR              ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ms(arr, x)      memset(arr, x, sizeof arr)

ll dp[SIZE], a[SIZE];

int main() {
    ll t = 0, n, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0;
    scl1(t);

    while(t--) {
        scl1(n);
        for1(i, n) scl1(a[i]);

        ll mx = -INF;
        sum = 0;
        ans = -INF;

        for1(i, n) {
            if(dp[i-1]+a[i] >= a[i]) dp[i] = dp[i-1] + a[i];
            else dp[i] = a[i];

            ans = max(ans, dp[i]);

            if(a[i] >= 0) sum += a[i];
            mx = max(mx, a[i]);
        }

        if(mx < 0) cout << mx << " " << mx << "\n";
        else cout << ans << " " << sum << "\n";
    }

    return 0;
}

