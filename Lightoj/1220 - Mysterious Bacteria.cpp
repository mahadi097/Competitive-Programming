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
#define SIZE            100005
#define INF             1000000005
#define F               first
#define S               second
#define FR              ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ms(arr, x)      memset(arr, x, sizeof arr)
#define bitcount(n)     __builtin_popcountll(n)

ll gcd(ll x, ll y) {
    if(y == 0) return x;
    return gcd(y, x%y);
}

bool st[SIZE];
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

ll factorize(ll n) {
    ll g, c;
    bool st = 0;
    bool neg = (n < 0);
    if(neg) n *= -1;

    ll sqrtn = sqrt(n);

    for(ll i = 0; i < prime.size() && prime[i] <= sqrtn && n > 1; i++) {
        if(n%prime[i] == 0) {
            c = 0;
            while(n%prime[i] == 0) {
                n /= prime[i];
                c++;
            }

            if(!st) {
                g = c;
                st = 1;
            }
            else g = gcd(g, c);
        }
    }

    if(n > 1) g = 1;
    if(neg) {
        while(g%2 == 0) g /= 2;
    }
    return g;
}

int main() {
    sieve();
    ll t = 0, n, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0;
    scl1(t);

    for1(i, t) {
        scl1(n);

        ans = factorize(n);
        printcase;
        printl(ans);
    }

    return 0;
}

