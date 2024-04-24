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
const ll SIZE = 3e5+5;
const ll mod = 1e9+7;


ll com[22][22];
void cal_ncr() {
    ll i, j;

    com[0][0] = 1;
    for(i = 1; i < 22; i++) {
        for(j = 0; j <= i; j++) {
            if(j == 0) com[i][j] = 1;
            else com[i][j] = com[i-1][j] + com[i-1][j-1];
        }
    }
}

ll dp[22];
ll derrangement(ll n) {
    if(n == 2 || n == 0) return 1;
    if(n == 1) return 0;
    if(dp[n] != -1) return dp[n];

    dp[n] = (n-1) * (derrangement(n-2) + derrangement(n-1));
    return dp[n];
}

int main() {
    ll t = 0, n, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0;
    string s, s1, s2;

    cal_ncr();
    ms(dp, -1);
    derrangement(21);

    while(scl2(n, k) == 2) {
        ans = 0;

        for(i = 0; i <= k; i++) {
            t = com[n][i] * derrangement(n-i);
//            cout << com[n][i] << " " << derrangement(n-i) << endl;
            ans += t;
        }

        printl(ans);
    }



    return 0;
}

