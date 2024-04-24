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

    while(scl2(n, sum) == 2) {
        ll a[n+1];
        for1(i, n) cin >> a[i];

        t = a[1];
        ll st = 1, en = 1;
        ans = n + 1;


        while(en <= n) {
            if(t >= sum) {
                x = en - st + 1;
                ans = min(ans, x);

//                if(st == en) break;

                if(st < en) {
                    t -= a[st];
                    st++;
                }
            }
            else {
                en++;
                if(en <= n) {
                    t += a[en];
                }
            }
        }

        if(ans == n+1) {
            printf("0\n");
            continue;
        }

        printl(ans);
    }

    return 0;
}

