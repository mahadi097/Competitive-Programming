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
#define SIZE            1005
#define INF             1000000005

ll n;
ll dp[SIZE][35];
ll price[SIZE], weight[SIZE];

ll knapsack(ll i, ll w, ll cap) {
    if(i == n+1) return 0;
    if(dp[i][w] != -1) return dp[i][w];

    ll p1 = 0, p2 = 0;

    if((w + weight[i]) <= cap) {
        p1 = price[i] + knapsack(i+1, w+weight[i], cap);
    }
    p2 = knapsack(i+1, w, cap);

    dp[i][w] = max(p1, p2);

    return dp[i][w];
}

int main() {
    ll t = 0, x, y, z, i, j, k, g, q, ans = 0, sum = 0;
    scl1(t);

    while(t--) {
        ans = 0;

        scl1(n);

        for1(i, n) {
            scl2(price[i], weight[i]);
        }

        scl1(g);

        for1(i, g) {
            memset(dp, -1, sizeof dp);
            scl1(x);

            ans += knapsack(1, 0, x);
        }
        printl(ans);
    }

    return 0;
}

