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
const ll SIZE = 2e5+5;
const ll mod = 1e9+7;


vector <ll> zero;
ll a[SIZE];
ll pro[SIZE];
ll cum[SIZE];

ll c1, c2;
ll ex_euclid(ll a, ll b) {
    if(b == 0) {
        c1 = 1;
        c2 = 0;
        return a;
    }

    ll g = ex_euclid(b, a%b);

    ll x1 = c1;
    c1 = c2;
    c2 = x1 - c2 * (a/b);

    return g;
}

ll mod_inverse(ll a, ll m) {
    ll g = ex_euclid(a, m);

    return ((c1%m) + m) % m;
}

int main() {
    ll t = 0, n, x, y, z, i, j, k, g = 1, p, q, r, ans = 0, sum = 0, c = 0;
    string s, s1, s2;

    scl2(n, k);
    for1(i, n) {
        scl1(a[i]);
        if(a[i] < 0) a[i] += (100 * mod);
        if(a[i] == 0) {
            zero.pb(i);
            a[i] = 1;
        }
        a[i] %= mod;
    }

    c = 1;
    for1(i, k) {
        c = (c%mod * a[i]%mod) % mod;
    }

    pro[k] = c;
    for(i = k+1; i <= n; i++) {
        pro[i] = (pro[i-1]%mod * a[i]%mod) % mod;
//        printl(pro[i]);
    }


    cum[k] = pro[k];
    for(i = k+1; i <= n; i++) {
        cum[i] = (cum[i-1]%mod + pro[i]%mod) % mod;
//        printl(cum[i]);
    }


    p = lower_bound(zero.begin(), zero.end(), 1) - zero.begin();
    if(p != zero.size()) {
        if(zero[p] > k) {
            ans = cum[zero[p]-1];
        }
    }
    else ans = cum[n];

//    printl(ans);
//    printl(cum[n]);

    for(i = 2, j = k, x = 1; i+k-1 <= n; i++, j++, x++) {
        g = (g%mod * a[x]%mod) % mod;

        p = lower_bound(zero.begin(), zero.end(), i) - zero.begin();

        if(p != zero.size()) {
            if(zero[p] > i+k-1) {
                r = cum[zero[p]-1];
            }
            else continue;
        }
        else r = cum[n];

        t = (r%mod - cum[j]%mod) % mod;
        if(t < 0) t += (100 * mod);
        t %= mod;

        c = mod_inverse(g, mod);

        sum = (t%mod * c%mod) % mod;

        ans = (ans%mod + sum%mod) % mod;

//        cout << r << " " << cum[j] << endl;
//        cout << i << " " << sum << " " << t << " " << c << endl;
    }

    printl(ans);

    return 0;
}

//9 4
//6 8 9 12 4 3 0 9 5
