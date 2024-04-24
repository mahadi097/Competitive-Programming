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
#define SIZE            305
#define INF             1000000005
#define F               first
#define S               second
#define FR              ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ms(arr, x)      memset(arr, x, sizeof arr)

ll dp1[SIZE][SIZE];
ll dp2[SIZE][SIZE][SIZE];
//ll dp3[SIZE][SIZE][SIZE];
ll n;
vector <ll> v;

ll solve1(ll val, ll amount) {
    if(val == 0) {
        if(amount == 0) return 1;
        return 0;
    }
    if(dp1[val][amount] != -1) return dp1[val][amount];

    ll t1 = 0;

    if(amount-val >= 0) t1 = solve1(val, amount-val);
    t1 += solve1(val-1, amount);

    return dp1[val][amount] = t1;
}

ll solve2(ll val, ll amount, ll coin) {
    if(coin < 0) return 0;
    if(val == 0) {
        if(amount == 0) return 1;
        return 0;
    }
    if(dp2[val][amount][coin] != -1) return dp2[val][amount][coin];

    ll t1 = 0;

    if(amount-val >= 0) t1 = solve2(val, amount-val, coin-1);
    t1 += solve2(val-1, amount, coin);

    return dp2[val][amount][coin] = t1;
}

//ll solve3(ll val, ll amount, ll coin) {
//    if(coin < 0) return 0;
//    if(val == 0) {
//        if(amount == 0 && coin == 0) return 1;
//        return 0;
//    }
//    if(dp3[val][amount][coin] != -1) return dp3[val][amount][coin];
//
//    ll t1 = 0;
//
//    if(amount-val >= 0) t1 = solve3(val, amount-val, coin-1);
//    t1 += solve3(val-1, amount, coin);
//
//    return dp3[val][amount][coin] = t1;
//}

int main() {
    ll t = 0, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0;
    ms(dp1, -1);
    ms(dp2, -1);
//    ms(dp3, -1);

    string s;

    while(getline(cin, s)) {
        stringstream ss(s);

        v.clear();

        while(ss >> n) v.pb(n);

        if(v.size() == 1) ans = solve1(v[0], v[0]);
        else if(v.size() == 2) {
            v[1] = min(v[0], v[1]);
            ans = solve2(v[0], v[0], v[1]);
        }
        else {
            ans = 0;
//            v[1] = min(v[0], v[1]);
            v[2] = min(v[0], v[2]);

            if(v[1] > v[0]) {
                printl(ans);
                continue;
            }

            x = solve2(v[0], v[0], v[1]-1);
            y = solve2(v[0], v[0], v[2]);
            ans = y - x;
        }

        printl(ans);
    }

    return 0;
}
