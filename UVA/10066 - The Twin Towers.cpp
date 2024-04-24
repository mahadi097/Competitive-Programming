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
#define piii            pair <ll, paired>
#define SIZE            105
#define INF             1000000005
#define F               first
#define S               second
#define FR              ios_base::sync_with_stdio(false);cin.tie(NULL)

ll n1, n2;
ll dp[SIZE][SIZE];
ll t1[SIZE], t2[SIZE];

ll lcs(ll i, ll j) {
    if(i == n1+1 || j == n2+1) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    if(t1[i] == t2[j]) dp[i][j] = 1 + lcs(i+1, j+1);
    else {
        ll p1 = lcs(i+1, j);
        ll p2 = lcs(i, j+1);
        dp[i][j] = max(p1, p2);
    }

    return dp[i][j];
}

int main() {
    ll t = 1, n, x, y, z, i, j, k, g, q, ans = 0, sum = 0, c = 0;

    while(scl2(n1, n2) && n1 && n2) {

        memset(dp, -1, sizeof dp);

        for1(i, n1) scl1(t1[i]);
        for1(i, n2) scl1(t2[i]);

        ans = lcs(1, 1);

        printf("Twin Towers #%lld\n", t);
        printf("Number of Tiles : %lld\n\n", ans);

        t++;
    }

    return 0;
}

