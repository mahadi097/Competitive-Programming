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
const ll SIZE = 2e4+5;
const ll mod = 1e9+7;


ll n, need, a[105];
ll min_cost, min_coin;
ll dp1[105][SIZE];
ll dp2[105][SIZE];

ll solve(ll in, ll sum) {
    if(sum >= need) return 0;
    if(in == n+1) return INF;
    if(dp1[in][sum] != -1) return dp1[in][sum];

    ll p1(-INF), p2(-INF);

    p1 = solve(in+1, sum);
    p2 = a[in] + solve(in+1, sum+a[in]);

    return dp1[in][sum] = min(p1, p2);
}

ll solve2(ll in, ll sum) {
    if(sum == 0) return 0;
    if(in == n+1 || sum < 0) return INF;
    if(dp2[in][sum] != -1) return dp2[in][sum];

    ll p1(-INF), p2(-INF);

    p1 = solve2(in+1, sum);
    p2 = 1 + solve2(in+1, sum-a[in]);

    return dp2[in][sum] = min(p1, p2);
}

int main() {
    ll t = 0, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0;
    string s, s1, s2;

    scl1(t);

    while(t--) {
        scl2(need, n);
        for1(i, n) scl1(a[i]);

        ms(dp1, -1);
        ms(dp2, -1);

        min_cost = solve(1, 0);
        min_coin = solve2(1, min_cost);

        cout << min_cost << " " << min_coin << "\n";
    }

    return 0;
}

