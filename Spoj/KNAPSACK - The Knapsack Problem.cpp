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
#define SIZE            2005
#define INF             1000000005

ll dp[SIZE][SIZE];
ll cap, items;
ll sizee[SIZE], value[SIZE];

ll knapsack(ll i, ll s) {
    if(i == items+1) return 0;
    if(dp[i][s] != -1) return dp[i][s];

    ll v1 = 0, v2;
    if((s + sizee[i]) <= cap) {
        v1 = value[i] + knapsack(i+1, s+sizee[i]);
    }
    v2 = knapsack(i+1, s);

    dp[i][s] = max(v1, v2);
    return dp[i][s];
}

int main() {
    ll t = 0, n, x, y, z, i, j, k, g, q, ans = 0, sum = 0;
    memset(dp, -1, sizeof dp);

    scl2(cap, items);

    for1(i, items) {
        scl2(sizee[i], value[i]);
    }

    ans = knapsack(1, 0);
    printl(ans);

    return 0;
}

