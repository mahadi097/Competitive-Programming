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
#define SIZE            205
#define INF             1000000005

vector <ll> row[SIZE];
ll n;
ll dp[SIZE][SIZE];

ll climb(ll i, ll j, ll c) {
    if(i >= 1 && i <= ((n*2)-1) && j >= 0 && (j+1) <= row[c].size()) {
        if(dp[i][j] != -1) return dp[i][j];

        ll val = -INF;

        if(c < n) {
            val = max(val, climb(i+1, j, c+1) + row[i][j]);
            val = max(val, climb(i+1, j+1, c+1) + row[i][j]);
        }
        else {
            val = max(val, climb(i+1, j, c+1) + row[i][j]);
            val = max(val, climb(i+1, j-1, c+1) + row[i][j]);
        }
        return dp[i][j] = val;
    }
    else return 0;
}

int main() {
    ll t = 0, x, y, z, i, j, k, g, q, ans = 0, sum = 0, c;
    scl1(t);

    for1(i, t) {
        for1(j, SIZE) row[j].clear();
        memset(dp, -1, sizeof dp);

        scl1(n);

        for1(j, n) {
            for1(k, j) {
                scl1(x);
                row[j].pb(x);
            }
        }
        for(j = n+1, c = 1; c <= n-1; j++, c++) {
            for1(k, n-c) {
                scl1(x);
                row[j].pb(x);
            }
        }


        ans = climb(1, 0, 1);
        printf("Case %lld: %lld\n", i, ans);
    }

    return 0;
}

