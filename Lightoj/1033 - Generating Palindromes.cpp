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
#define piii            pair <ll, pii>
#define SIZE            105
#define INF             1000000005
#define F               first
#define S               second
#define FR              ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ms(arr, x)      memset(arr, x, sizeof arr)

string s1, s2;
ll n;
ll dp[SIZE][SIZE];

ll lcs(ll i, ll j) {
    if(i == n || j == n) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i] == s2[j]) dp[i][j] = 1 + lcs(i+1, j+1);
    else dp[i][j] = max(lcs(i+1, j), lcs(i, j+1));

    return dp[i][j];
}

int main() {
    ll t = 0, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0;
    scl1(t);

    for1(i, t) {
        cin >> s1;

        n = s1.size();
        s2 = s1;
        reversed(s2);

        ms(dp, -1);

        ans = lcs(0, 0);
        ans = n - ans;

        printcase;
        printl(ans);
    }

    return 0;
}

