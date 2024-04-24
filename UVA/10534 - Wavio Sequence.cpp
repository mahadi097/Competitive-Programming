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
#define dsorted(s)      sort(s.begin(), s.end(), descending_func)
#define for0(i, n)      for (i = 0; i < n; i++)
#define for1(i, n)      for (i = 1; i <= n; i++)
#define pii             pair <ll, ll>
#define piii            pair <ll, pii>
#define SIZE            10005
#define INF             1000000005
#define F               first
#define S               second
#define FR              ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ms(arr, x)      memset(arr, x, sizeof arr)

ll n, seq[SIZE];
ll lcs[SIZE], lds[SIZE];

ll solve() {
    vector <ll> in1(n+1);

    ll i, val, in;

    in1[0] = -INF;
    for1(i, n) in1[i] = INF;

    for1(i, n) {
        val = seq[i];

        in = lower_bound(in1.begin(), in1.end(), val) - in1.begin();

        in1[in] = val;
        lcs[i] = in;
    }

    vector <ll> in2(n+1);

    in2[0] = -INF;
    for1(i, n) in2[i] = INF;

    for(i = n; i >= 1; i--) {
        val = seq[i];

        in = lower_bound(in2.begin(), in2.end(), val) - in2.begin();

        in2[in] = val;
        lds[i] = in;
    }

    ll mx_len = 0;

    for1(i, n) {
        val = min(lcs[i], lds[i]);
        val = (val * 2) - 1;
//        cout << lcs[i] << " " << lds[i] << "\n";

        mx_len = max(mx_len, val);
    }

    return mx_len;
}

int main() {
    ll t = 0, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0;

    while(scl1(n) == 1) {
        for1(i, n) scl1(seq[i]);

        ans = solve();

        printl(ans);
    }


    return 0;
}

