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



int main() {
    ll t = 0, n, x, y, z, i, j, k, g, q, ans = 0, sum = 0;
    scl1(t);

    while(t--) {
        scl2(n, sum);

        ll a[n+1];
        for1(i, n) cin >> a[i];

        ans = 0, q = 0;
        ll st = 1, en = 1, s = 0;

        while(en <= n) {
            if(s+a[en] <= sum) {
                x = en - st + 1;
                s += a[en];

                if(x > q) {
                    q = x;
                    ans = s;
                }
                if(x == q) {
                    ans = min(ans, s);
                }
                en++;
            }
            else {
                if(st < en) {
                    s -= a[st];
                    st++;
                }
                if(st == en) {
                    st++;
                    en++;
                }
            }
        }

        cout << ans << " " << q << endl;
    }

    return 0;
}

