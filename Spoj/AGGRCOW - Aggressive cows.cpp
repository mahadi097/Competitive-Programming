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
#define SIZE            100005
#define INF             1000000005

ll dr4[] = {0, 1, -1, 0, 0};
ll dc4[] = {0, 0, 0, 1, -1};

/**https://www.topcoder.com/community/data-science/data-science-tutorials/binary-search/**/

ll khuija_ber_kori(ll n, ll x, ll a[]) {
    ll mid, low = a[1]-a[0], high = a[n-1]-a[0];
    ll total, current, i;

    while(low <= high) {
        mid = (low + high) / 2;

        total = 1;
        current = a[0];

        for1(i, n-1) {
            if((a[i]-current) >= mid) {
                total++;
                current = a[i];
            }
        }

        if(total >= x) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return high;
}

int main() {
    ll t, n, m, x, y, z, i, j, k, g, q, ans, sum = 0;
    scl1(t);

    while(t--) {
        scl2(n, x);

        ll a[n];
        for0(i, n) {
            scl1(a[i]);
        }
        sort(a, a+n);

        ans = khuija_ber_kori(n, x, a);

        printl(ans);
    }

    return 0;
}

