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
#define fori(itt, stt)  for(auto itt = stt.begin(); itt != stt.end(); itt++)
#define pii             pair <ll, ll>
#define piii            pair <ll, pii>
//#define SIZE            100005
//#define INF             1000000005
#define F               first
#define S               second
#define FR              ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ms(arr, x)      memset(arr, x, sizeof arr)
#define bitcount(n)     __builtin_popcountll(n)

const ll INF = LLONG_MAX;
const ll SIZE = 32;
const ll mod = 1e9+7;


ll n, w;
ll a[SIZE];
vector <ll> sub1, sub2;

void solve(ll pos, ll val, ll sz, ll seg) {
    if(pos == sz) {
        if(seg == 1) sub1.pb(val);
        else sub2.pb(val);
        return;
    }

    solve(pos+1, val, sz, seg);
    solve(pos+1, val+a[pos], sz, seg);
}

ll bs(ll val) {
    ll st = 0, en = sub2.size();
    en--;
    ll t = 0;

    while(st <= en) {
        ll mid = (st + en) / 2;

        if(sub2[mid] <= val) {
            t = mid;
            st = mid + 1;
        }
        else en = mid - 1;
    }

    return t+1;
}

int main() {
    ll t = 0, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0;
    string s, s1, s2;

    scl1(t);

    for1(i, t) {
        scl2(n, w);
        for1(j, n) scl1(a[j]);

        sub1.clear();
        sub2.clear();
        ans = 0;

        c = n/2;
        solve(1, 0, c+1, 1);
        solve(c+1, 0, n+1, 2);

        asorted(sub2);

        for0(j, sub1.size()) {
            x = w - sub1[j];
            if(x >= 0) {
                ans += bs(x);
            }
        }

        printcase;
        printl(ans);
    }

    return 0;
}

