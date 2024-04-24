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
const ll SIZE = 1e6+5;
const ll mod = 1e9+7;

ll st[SIZE];
vector <ll> prime;
void sieve() {
    ll i, j;

    for(i = 3; i*i < SIZE; i += 2) {
        if(!st[i]) {
            for(j = i*i; j < SIZE; j += i) st[j] = 1;
        }
    }

    prime.pb(2);
    for(i = 3; i < SIZE; i += 2) {
        if(!st[i]) prime.pb(i);
    }
}

vector <pii> factors;
vector <ll> divi;
//set <ll> :: iterator it;

void factorize(ll n) {
    factors.clear();
    divi.clear();

    ll i, c, num = n;

    for(i = 0; prime[i]*prime[i] <= num && i < prime.size() && n > 1; i++) {
        if(n%prime[i] == 0) {
            c = 0;
            while(n%prime[i] == 0) {
                n /= prime[i];
                c++;
            }
            factors.pb(mp(prime[i], c));
        }
    }
    if(n > 1) factors.pb(mp(n, 1));
}

ll fs; ///FACTORS SIZE
ll area, min_div;

void get_div(ll i, ll val) {
    if(i == fs) {
        divi.pb(val);
        return;
    }

    ll j, t = factors[i].S;
    ll x = 1, y;

    for0(j, t+1) {
        get_div(i+1, val*x);
        x *= factors[i].F;
    }
}

int main() {
    sieve();
    ll t = 0, n, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0;
    scl1(t);

    for1(i, t) {
        scl2(area, min_div);
        factorize(area);

        fs = factors.size();

        get_div(0, 1);

        ans = 0;

        for0(j, divi.size()) {
            x = divi[j];
            y = area / x;

            if(x >= min_div && y >= min_div) ans++;
        }
        ans /= 2;

        printcase;
        printl(ans);
    }

    return 0;
}

