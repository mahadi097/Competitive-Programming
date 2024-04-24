#include <bits/stdc++.h>
using namespace std;


//TEMPLATE
#define pb              push_back
#define mp              make_pair
#define ll              long long
#define ld              long double
//#define pi              3.1415926536
#define pi              acos(-1)
//#define mod             1000000007
#define newline         printf("\n")
#define printminusone   printf("-1\n")
#define scl1(n)         scanf("%lld", &n)
#define scl2(a, b)      scanf("%lld %lld", &a, &b)
#define scl3(a, b, c)   scanf("%lld %lld %lld", &a, &b, &c)
#define printl(n)       printf("%lld\n", n)
#define ssl1(str)       scanf(" %[^\n]", str)
#define scd1(n)         scanf("%lf", &n)
#define scd2(a, b)      scanf("%lf %lf", &a, &b)
#define printd(n)       printf("%lf\n", n)
#define printld(n)      printf("%Lf\n", n)
#define printcase       printf("Case %lld: ", i)
#define reversed(s)     reverse(s.begin(), s.end())
#define asorted(s)      sort(s.begin(), s.end())
#define dsorted(s)      sort(s.begin(), s.end(), cmp)
#define for0(i, n)      for (i = 0; i < n; i++)
#define for1(i, n)      for (i = 1; i <= n; i++)
#define fori(itt, stt)  for(itt = stt.begin(); itt != stt.end(); itt++)
#define pii             pair <ll, ll>
#define piii            pair <ll, pii>
//#define SIZE            100005
//#define INF             1000000005
#define F               first
#define S               second
#define FR              ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ms(arr, x)      memset(arr, x, sizeof arr)
#define bitcount(n)     __builtin_popcountll(n)

const ll INF = 1e18;
const ll SIZE = 1e4+5;
const ll mod = 1e9+7;

ll n, cap;
ll dp[102][10002];
ll p[102], w[102], c[102];

ll solve(ll in, ll amount) {
    if(in == n+1) return 0;
    if(dp[in][amount] != -1) return dp[in][amount];

    ll p1(0), p2(0);

    if((amount+w[in]) <= cap) p1 = p[in] + solve(in, amount+w[in]);
    p2 = solve(in+1, amount);

    return dp[in][amount] = max(p1, p2);
}

int main() {
    ll t = 0, x, y, z, i, j, k, g, q, ans = 0, sum = 0;
    scl1(t);

    for1(i, t) {
        scl2(n, cap);

        ms(dp, -1);
        sum = 0;

        for1(j, n) {
            scl3(p[j], c[j], w[j]);

            sum += (c[j] * w[j]);
        }
        cap -= sum;

        printcase;

        if(cap < 0) {
            printf("Impossible\n");
            continue;
        }

        ans = solve(1, 0);
        printl(ans);
    }

    return 0;
}

