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
#define SIZE            1000005
#define INF             1000000005

ll dp[SIZE];
ll a[SIZE];
bool vis[SIZE];
ll n, k, last;

ll forward_phase(ll i) {
    if(i > n) return 0;
    if(dp[i] != -INF) return dp[i];

    ll x = forward_phase(i+1);
    ll y = forward_phase(i+2);

    dp[i] = a[i] + max(x, y);
    return dp[i];
}

int main() {
    ll t = 0, x, y, z, i, j, g, q, ans = 0, sum = 0;
    scl2(n, k);

    for1(i, n) scl1(a[i]);

    for1(i, n) dp[i] = -INF;

    ans = forward_phase(k);
    printl(ans);
    printl(last);

    return 0;
}

