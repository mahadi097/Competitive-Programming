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
#define SIZE            7500
#define INF             1000000005

ll dp[6][SIZE];
ll coin[] = {1, 5, 10, 25, 50};

ll solve(ll i, ll amount) {
    if(i == 5) {
        if(amount == 0) return 1;
        else return 0;
    }

    if(dp[i][amount] != -1) return dp[i][amount];
    ll t1 = 0, t2 = 0;

    if(amount-coin[i] >= 0) t1 = solve(i, amount-coin[i]);
    t2 = solve(i+1, amount);
    return dp[i][amount] = t1 + t2;
}

int main() {
    ll t = 0, n, x, y, z, i, j, k, g, q, ans = 0, sum = 0;
    memset(dp, -1, sizeof dp);

    while(scl1(sum) == 1) {
        ans = solve(0, sum);

        printl(ans);
    }

    return 0;
}

