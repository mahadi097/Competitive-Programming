#include <bits/stdc++.h>
using namespace std;


//TEMPLATE
#define pb              push_back
#define mp              make_pair
#define ll              long long int
#define pi              3.1415926536
#define mod             1000000007
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

ll dr4[] = {0, 1, -1, 0, 0};
ll dc4[] = {0, 0, 0, 1, -1};

ll big_mul(ll a, ll b, ll m) {
    if(b == 0) {
        return 0;
    }
    if(b%2 == 0) {
        ll r = big_mul(a, b/2, m);
        ll n = ((r%m) + (r%m)) % m;
        return n;
    }
    else {
        ll r = big_mul(a, b-1, m);
        ll n = ((a%m) + (r%m)) % m;
        return n;
    }
}

ll bigmod(ll x, ll y, ll m) {
    if(y == 0) {
        return 1;
    }
    if(y%2 == 0) {
        ll r = bigmod(x, y/2, m);
        ll n = big_mul(r, r, m);
        return n;
    }
    else {
        ll r = bigmod(x, y-1, m);
        ll n = big_mul(x, r, m);
        return n;
    }
}

int main() {
    ll t, n,  z, i, j, k;
    ll  m, x, y, ans;

    scand(t);

    for1(i, t) {
        scand(x), scand(y), scand(m);

        ans = bigmod(x, y, m);

//        ans = (ans + m) % m;

        printf("Case %lld: %lld\n", i, ans);
    }

    return 0;
}
