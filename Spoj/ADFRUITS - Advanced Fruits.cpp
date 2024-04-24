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
#define dsorted(s)      sort(s.begin(), s.end(), cmp)
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
#define bitcount(n)     __builtin_popcountll(n)

ll dp[SIZE][SIZE];
ll n1, n2;
string s1, s2;
string ans;

ll lcs(ll i, ll j) {
    if(i == n1 || j == n2) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i] == s2[j]) dp[i][j] = 1 + lcs(i+1, j+1);
    else {
        ll p1 = lcs(i+1, j);
        ll p2 = lcs(i, j+1);
        dp[i][j] = max(p1, p2);
    }

    return dp[i][j];
}

void shortest_name(ll i, ll j) {
    if(i == n1) {
        for( ; j < n2; j++) ans += s2[j];
        return;
    }
    if(j == n2) {
        for( ; i < n1; i++) ans += s1[i];
        return;
    }

    if(s1[i] == s2[j]) {
        ans += s1[i];
        shortest_name(i+1, j+1);
    }
    else {
        if(dp[i+1][j] >= dp[i][j+1]) {
            ans += s1[i];
            shortest_name(i+1, j);
        }
        else {
            ans += s2[j];
            shortest_name(i, j+1);
        }
    }
}

int main() {
    ll t = 0, n, x, y, z, i, j, k, g, p, q, sum = 0, c = 0;

    while(cin >> s1 >> s2) {
        n1 = s1.size();
        n2 = s2.size();

        ms(dp, -1);

        ans.clear();

        t = lcs(0, 0);
//        printl(t);

        shortest_name(0, 0);

        cout << ans << "\n";
    }

    return 0;
}

