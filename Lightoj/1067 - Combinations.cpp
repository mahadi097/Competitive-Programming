#include <bits/stdc++.h>
using namespace std;


//TEMPLATE
#define pb              push_back
#define mp              make_pair
#define ll              long long int
#define pi              3.1415926536
#define mod             1000003
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
#define SIZE            1000005
#define INF             1000000005

ll dr4[] = {0, 1, -1, 0, 0};
ll dc4[] = {0, 0, 0, 1, -1};

ll gcd(ll a, ll b) {
    if(b == 0) {
        return a;
    }
    return gcd(b, a%b);
}

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

ll mod_inverse(ll a) {
    ll g = ex_euclid(a, mod);
    return ((c1%mod) + mod) % mod;
}

ll fact[SIZE];
void factorial() {
    ll i;
    fact[0] = 1;
    for1(i, SIZE-1) {
        fact[i] = ((fact[i-1]%mod) * (i%mod)) % mod;
    }
}

int main() {
    factorial();
    ll t, n, r, x, y, z, i, j, k;
    scl1(t);

    for1(i, t) {
        scl2(n, r);

        x = mod_inverse(fact[r]);
        y = mod_inverse(fact[n-r]);

        z = ((fact[n]%mod) * (x%mod) * (y%mod)) % mod;

        printf("Case %lld: %lld\n", i, z);
    }

    return 0;
}


