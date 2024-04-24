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
const ll SIZE = 1e3+5;
const ll mod = 1e9+7;

ll n, k;
ll a[SIZE];

bool ok (ll cost) {
    ll i, c = 1, t = 0;

    for1(i, n) {
        if(a[i] > cost) return 0;
        if(t+a[i] <= cost) {
            t += a[i];
        }
        else {
            t = a[i];
            c++;
        }
    }
    return (c <= k);
}

int main() {
    ll t = 0, x, y, z, i, j, g, p, q, ans = 0, sum = 0, c = 0;
    scl1(t);

    for1(i, t) {
        scl2(n, k);
        n++, k++;

        for1(j, n) scl1(a[j]);

        ll st = 1, en = 1e5;

        while(st <= en) {
            ll mid = (st + en) / 2;

            if(ok(mid)) {
                ans = mid;
                en = mid - 1;
            }
            else st = mid + 1;
        }

        c = 1, sum = 0;
        vector <ll> day;

        for1(j, n) {
            if(sum+a[j] <= ans) sum += a[j];
            else {
                day.pb(sum);
                sum = a[j];
                c++;
            }
            if(n-j == k-c) {
                day.pb(sum);
                for(j = j+1; j <= n; j++) day.pb(a[j]);
                break;
            }
        }

        printcase;
        printl(ans);
        for0(j, k) printl(day[j]);
    }

    return 0;
}

