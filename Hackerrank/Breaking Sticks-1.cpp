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
#define SIZE            1000005
#define INF             1000000005
#define F               first
#define S               second
#define FR              ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ms(arr, x)      memset(arr, x, sizeof arr)
#define bitcount(n)     __builtin_popcountll(n)

bool st[SIZE];
vector <ll> prime;
void sieve() {
    ll i, j;
    prime.pb(2);

    for(i = 3; i*i < SIZE; i += 2) {
        if(!st[i]) {
            for(j = i*i; j < SIZE; j += i) st[j] = 1;
        }
    }

    for(i = 3; i < SIZE; i += 2) {
        if(!st[i]) prime.pb(i);
    }
}

vector <ll> parts;
void factorize(ll n) {
    ll i;
    ll sqrtn = sqrt(n);

    for(i = 0; prime[i] <= sqrtn && i < prime.size() && n > 1; i++) {
        if(n%prime[i] == 0) {
            while(n%prime[i] == 0) {
                parts.pb(prime[i]);
                n /= prime[i];
            }
        }
    }
    if(n > 1) parts.pb(n);
}

int main() {
    sieve();
    ll t = 0, n, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0;
    scl1(n);

    while(n--) {
        scl1(x);

        sum = 1;
        t = 1;
        parts.clear();

        factorize(x);
        p = parts.size();

        for(i = p-1; i >= 0; i--) {
            t *= parts[i];
            sum += t;
        }

        ans += sum;
    }

    printl(ans);

    return 0;
}

