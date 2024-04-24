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
#define SIZE            100005
#define INF             1000000005
#define F               first
#define S               second
#define FR              ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ms(arr, x)      memset(arr, x, sizeof arr)
#define bitcount(n)     __builtin_popcountll(n)

ll par[30];

ll Find(ll x) {
    if(par[x] == x) return x;
    return par[x] = Find(par[x]);
}

void Union(ll a, ll b) {
    ll u = Find(a);
    ll v = Find(b);

    if(u == v) return;
    par[u] = v;
}

int main() {
    ll t = 0, n, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0;
    scl1(t);

    string s;

    while(t--) {
        cin >> s;

        n = s[0] - 'A' + 1;

        for1(i, n) par[i] = i;

        cin.ignore();
        while(getline(cin, s) && s != "") {
            x = s[0] - 'A' + 1;
            y = s[1] - 'A' + 1;
//            cout << x << " " << y << endl;

            Union(x, y);
        }

        set <ll> subset;

        for1(i, n) {
            p = Find(i);
//            printl(p);
            subset.insert(p);
        }

        ans = subset.size();
        printl(ans);
        if(t) newline;
    }

    return 0;
}

