#include <bits/stdc++.h>
using namespace std;


//TEMPLATE
#define pb              push_back
#define mp              make_pair
#define ll              long long
#define ld              long double
#define pi              3.1415926536
//#define mod             1000000007
#define newline         printf("\n")
#define printminusone   printf("-1\n")
#define scl1(n)         scanf("%lld", &n)
#define scl2(a, b)      scanf("%lld %lld", &a, &b)
#define printl(n)       printf("%lld\n", n)
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
const ll SIZE = 1e5+5;
const ll mod = 1e9+7;

ll n1, n2, n3;
string s1, s2, s3;
ll dp[52][52][52];

ll lcs(ll i, ll j, ll k) {
    if(i == n1) return 0;
    if(j == n2) return 0;
    if(k == n3) return 0;
    if(dp[i][j][k] != -1) return dp[i][j][k];

    if(s1[i] == s2[j] && s1[i] == s3[k]) dp[i][j][k] = 1 + lcs(i+1, j+1, k+1);
    else {
        ll p1 = lcs(i+1, j, k);
        p1 = max(p1, lcs(i, j+1, k));
        p1 = max(p1, lcs(i, j, k+1));
        p1 = max(p1, lcs(i+1, j+1, k));
        p1 = max(p1, lcs(i+1, j, k+1));
        p1 = max(p1, lcs(i, j+1, k+1));
        dp[i][j][k] = p1;
    }

    return dp[i][j][k];
}

int main() {
    ll t = 0, n, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0;
    scl1(t);

    for1(i, t) {
        cin >> s1 >> s2 >> s3;

        n1 = s1.size();
        n2 = s2.size();
        n3 = s3.size();

        ms(dp, -1);

        ans = lcs(0, 0, 0);
        printcase;
        printl(ans);
    }

    return 0;
}

