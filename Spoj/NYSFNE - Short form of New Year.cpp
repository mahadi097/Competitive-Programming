#include <bits/stdc++.h>
using namespace std;


//TEMPLATE
#define pb              push_back
#define mp              make_pair
#define ll              long long int
#define pi              3.1415926536
#define mod             100
#define newline         printf("\n")
#define printminusone   printf("-1\n")
#define scand(n)        scanf("%lld", &n)
#define printd(n)       printf("%lld\n", n)
#define scandd(n)       scanf("%lf", &n)
#define printdd(n)      printf("%lf\n", n)
#define reversed(s)     reverse(s.begin(), s.end())
#define asorted(s)      sort(s.begin(), s.end())
#define dsorted(s)      sort(s.begin(), s.end(), descending_func)
#define for0(i, n)      for (i = 0; i < n; i++)
#define for1(i, n)      for (i = 1; i <= n; i++)
#define paired          pair <ll, ll>
#define pii             pair <ll, paired>
#define SIZE            100005
#define INF             1000000005

ll bmod(ll x, ll y);

int main() {
    ll t, n, a, b, c, x, y, z, i, j, k;

    while(cin >> x >> y) {
        n = bmod(x, y);

        if((n/10) == 0) {
            printf("0");
        }

        printd(n);
    }

    return 0;
}

ll bmod(ll x, ll y) {
    if(y == 0) {
        return 1;
    }

    if(y%2 == 0) {
        ll r = bmod(x, y/2);
        ll n = ((r%mod) * (r%mod)) % mod;
        return n;
    }
    else {
        ll r = bmod(x, y-1);
        ll n = ((x%mod) * (r%mod)) % mod;
        return n;
    }
}
