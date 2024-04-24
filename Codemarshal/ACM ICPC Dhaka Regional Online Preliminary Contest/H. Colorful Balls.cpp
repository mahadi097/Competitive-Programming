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
#define printcase       printf("Case %lld: ", k)
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
const ll SIZE = 1e5+5;
const ll mod = 1e9+7;


ll n, a[SIZE], dp[SIZE][6];

ll solve(ll in, ll st) {
    if(in == n+1) return 1;
    if(dp[in][st] != -1) return dp[in][st];

    ll res(0);

    if(a[in] != 4) res = solve(in+1, a[in]);
    else {
        if(in+1 <= n && a[in+1] != 4) {
            if(a[in+1] == 1) {
                if(st != 2) {
                    res += solve(in+1, 2);
                    res %= mod;
                }
                if(st != 3) {
                    res += solve(in+1, 3);
                    res %= mod;
                }
            }
            if(a[in+1] == 2) {
                if(st != 1) {
                    res += solve(in+1, 1);
                    res %= mod;
                }
                if(st != 3) {
                    res += solve(in+1, 3);
                    res %= mod;
                }
            }
            if(a[in+1] == 3) {
                if(st != 1) {
                    res += solve(in+1, 1);
                    res %= mod;
                }
                if(st != 2) {
                    res += solve(in+1, 2);
                    res %= mod;
                }
            }
        }
        else {
            if(st != 1) {
                res += solve(in+1, 1);
                res %= mod;
            }
            if(st != 2) {
                res += solve(in+1, 2);
                res %= mod;
            }
            if(st != 3) {
                res += solve(in+1, 3);
                res %= mod;
            }
        }
    }

    return dp[in][st] = res%mod;
}

int main() {
    ll t = 0, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0;
    string s, s1, s2;

    scl1(t);

    for1(k, t) {
        cin >> s;
        n = s.size();

        for0(i, n) {
            if(s[i] == 'R') a[i+1] = 1;
            else if(s[i] == 'B') a[i+1] = 2;
            else if(s[i] == 'G') a[i+1] = 3;
            else a[i+1] = 4;
        }

        for1(i, n) {
            for0(j, 6) dp[i][j] = -1;
        }

        ans = solve(1, 0);
        printcase;
        printl(ans);
    }

    return 0;
}

