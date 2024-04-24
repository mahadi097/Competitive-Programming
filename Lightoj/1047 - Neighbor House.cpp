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
#define SIZE            100005
#define INF             1000000005

ll house[21][4];
ll dp[21][4];
ll n;

ll solve(ll i, ll j) {
    if(i >= 1 && i <= n && j >= 1 && j <= 3) {
        if(dp[i][j] != -1) return dp[i][j];

        ll val = INF;

        if(j == 1) {
            val = min(val, solve(i+1, j+1) + house[i][j]);
            val = min(val, solve(i+1, j+2) + house[i][j]);
        }
        if(j == 2) {
            val = min(val, solve(i+1, j+1) + house[i][j]);
            val = min(val, solve(i+1, j-1) + house[i][j]);
        }
        if(j == 3) {
            val = min(val, solve(i+1, j-1) + house[i][j]);
            val = min(val, solve(i+1, j-2) + house[i][j]);
        }

        return dp[i][j] = val;
    }
    else {
        return 0;
    }
}

int main() {
    ll t = 0, x, y, z, i, j, k, g, q, ans = 0, sum = 0;
    scl1(t);

    for1(i, t) {
        memset(dp, -1, sizeof dp);
        scl1(n);

        for1(j, n) {
            cin >> house[j][1] >> house[j][2] >> house[j][3];
        }

        ans = solve(1, 1);
        ans = min(ans, solve(1, 2));
        ans = min(ans, solve(1, 3));

        printf("Case %lld: %lld\n", i, ans);
    }

    return 0;
}

