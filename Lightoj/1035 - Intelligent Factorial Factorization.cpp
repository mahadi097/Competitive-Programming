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
#define SIZE            105
#define INF             1000000005
#define F               first
#define S               second
#define FR              ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ms(arr, x)      memset(arr, x, sizeof arr)

bool st[SIZE];
vector <ll> prime;

void sieve() {
    prime.pb(2);

    ll i, j;

    for(i = 2; i < SIZE; i++) {
        if(!st[i]) {
            for(j = i*i; j < SIZE; j += i) {
                st[j] = 1;
            }
        }
    }

    for(i = 3; i < SIZE; i += 2) {
        if(!st[i]) prime.pb(i);
    }
}

set <ll> factors;
ll cnt[SIZE];

void facetorize(ll n) {
    ll sqrtn = sqrt(n);

    for(ll i = 0; prime[i] <= sqrtn && i < prime.size(); i++) {
        if(n%prime[i] == 0) {
            factors.insert(prime[i]);

            while(n%prime[i] == 0) {
                n /= prime[i];
                cnt[prime[i]]++;
            }
        }
    }
    if(n > 1) {
        factors.insert(n);
        cnt[n]++;
    }
}

int main() {
    sieve();
    ll t = 0, n, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0;
    scl1(t);

    for1(i, t) {
        scl1(n);

        factors.clear();
        ms(cnt, 0);

        for(x = 2; x <= n; x++) facetorize(x);

        printcase;
        printf("%lld = ", n);

        set <ll> :: iterator it;
        vector <ll> f;

        for(it = factors.begin(); it != factors.end(); it++) f.pb(*it);

        for0(j, f.size()) {
            if(j == f.size()-1) printf("%lld (%lld)\n", f[j], cnt[f[j]]);
            else printf("%lld (%lld) * ", f[j], cnt[f[j]]);
        }
    }

    return 0;
}

