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
    ll t = 0, n, m, x, y, z, i, j, k, g, q, ans = 0, sum = 0,c = 0;
    scl1(t);

    for1(i, t) {
        scl2(n, g);
        scl1(k);

        ll a[n+1];
        a[1] = 1, a[2] = 2, a[3] = 3;

        for(j = 4; j <= n; j++) {
            a[j] = (a[j-1] + a[j-2] + a[j-3]) % g + 1;
        }

        ll st = 1, en = 1;

        ans = INF, c = 0;
        map <ll, ll> m;
        if(a[en] <= k) {
            m[a[en]] = 1;
            c++;
        }

        while(en <= n) {
            if(c < k) {
                en++;

                if(a[en] <= k) {
                    if(!m[a[en]]) c++;
                    m[a[en]]++;
                }
            }
            else {
                x = en - st + 1;
                ans = min(ans, x);

//                cout << st << " " << en << endl;

                if(a[st] <= k) {
                    m[a[st]]--;
                    if(!m[a[st]]) c--;
                }
                st++;
            }
        }

        printf("Case %lld: ", i);
        if(ans == INF) {
            cout << "sequence nai\n";
        }
        else {
            cout << ans << endl;
        }
    }

    return 0;
}

