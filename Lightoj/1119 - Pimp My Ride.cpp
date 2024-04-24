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
#define SIZE            100005
#define INF             1000000005
#define F               first
#define S               second
#define FR              ios_base::sync_with_stdio(false);cin.tie(NULL)

ll price[15][15];
ll dp[1<<14+5];
ll n;

bool check(ll x, ll pos) {
    return (x & (1LL << pos));
}

ll set1(ll x, ll pos) {
    return (x = x | (1LL << pos));
}

ll solve(ll msk) {
    if(msk == (1<<n)-1) return 0;
    if(dp[msk] != -1) return dp[msk];

    ll mn = INF, t = 0;
    ll i, j;

    for0(i, n) {
        if(check(msk, i) == 0) {
            t = price[i][i];

            for0(j, n) {
                if(i == j) continue;
                if(check(msk, j) == 1) {
                    t += price[i][j];
                }
            }
            t += solve(set1(msk, i));
            mn = min(mn, t);
        }
    }

    return dp[msk] = mn;
}

int main() {
    ll t = 0, x, y, z, i, j, k, g, q, ans = 0, sum = 0, c = 0;
    scl1(t);

    for1(i, t) {
        scl1(n);

        memset(dp, -1, sizeof dp);

        for0(j, n) {
            for0(k, n) scl1(price[j][k]);
        }

        ans = solve(0);
        printcase;
        printl(ans);
    }

    return 0;
}

