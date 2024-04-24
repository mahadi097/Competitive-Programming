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

ll dp[52][52][102];
ll a[52], b[52], n;

bool cmp(ll x, ll y) {
    return x > y;
}

ll solve(ll i, ll j, ll p) {
    if(i == n+1 || j == n+1) return p;
    if(dp[i][j][p] != -1) return dp[i][j][p];

    ll draw = 0, win = 0;

    ll st = j, en = n;

    while(st <= en) {
        ll mid = (st + en) / 2;

        if(b[mid] <= a[i]) {
            draw = mid;
            en = mid - 1;
        }
        else st = mid + 1;
    }
    if(b[draw] != a[i]) draw = 0;

    st = j, en = n;
    while(st <= en) {
        ll mid = (st + en) / 2;

        if(b[mid] < a[i]) {
            win = mid;
            en = mid - 1;
        }
        else st = mid + 1;
    }

    ll p1, p2;

    if(!draw) p1 = solve(i+1, j+1, p);
    else p1 = solve(i+1, draw+1, p+1);

    if(!win) p2 = p;
    else p2 = solve(i+1, win+1, p+2);

    return dp[i][j][p] = max(p1, p2);
}

int main() {
    ll t = 0, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0;
    scl1(t);

    for1(i, t) {
        scl1(n);

        for1(j, n) scl1(a[j]);
        for1(j, n) scl1(b[j]);

        sort(a+1, a+n+1, cmp);
        sort(b+1, b+n+1, cmp);

        ms(dp, -1);

        ans = solve(1, 1, 0);
        printcase;
        printl(ans);
    }

    return 0;
}

