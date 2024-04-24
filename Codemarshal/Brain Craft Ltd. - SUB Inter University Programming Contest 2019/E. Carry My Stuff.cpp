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
const ll SIZE = 5e4+5;
const ll mod = 1e9+7;


vector <ll> pro[SIZE];
ll cus[SIZE];

int main() {
    ll t = 0, n, m, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0;
    string s, s1, s2;

    scl1(t);

    for1(i, t) {
        scl3(p, n, m);

        bool ok = 1;

        for1(j, p) pro[j].clear();

        for1(j, n) {
            scl2(x, y);
            pro[x].pb(y);
        }

        for1(j, m) scl1(cus[j]);

        for1(j, p) asorted(pro[j]);
        sort(cus+1, cus+m+1);

        ans = -INF;
        for1(j, p) {
            ll st, en;
            c = 0;

            for0(k, pro[j].size()) {
                st = c+1, en = m;
                c = -1;
                x = pro[j][k];

                while(st <= en) {
                    ll mid = (st + en) / 2;

                    if(cus[mid] >= x) {
                        c = mid;
                        en = mid - 1;
                    }
                    else st = mid + 1;
                }

                if(c == -1) {
                    ok = 0;
                    break;
                }

                ans = max(ans, cus[c]-x);
            }

            if(!ok) break;
        }

        printcase;
        if(ok) printl(ans);
        else printminusone;
    }

    return 0;
}

