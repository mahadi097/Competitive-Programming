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
#define SIZE            1005
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
            for(j = i*i; j < SIZE; j += i) st[j] = 1;
        }
    }
    for(i = 3; i < SIZE; i += 2) if(!st[i]) prime.pb(i);
}

ll facetorize(ll n) {
    ll sqrtn = sqrt(n);
    ll i, j, total_div = 1, c;

    for(i = 0; i < prime.size() && prime[i] <= sqrtn; i++) {
        if(n%prime[i] == 0) {
            c = 0;

            while(n%prime[i] == 0) {
                n /= prime[i];
                c++;
            }

            total_div *= (c + 1);
        }
    }
    if(n > 1) total_div *= 2;

    return total_div;
}

vector <pii> num_div;

void cal_div() {
    ll x, i, j;

    for1(x, 1000) {
        ll t = facetorize(x);
        num_div.pb(mp(x, t));
//        cout << x << " " << t << "\n";
    }
}

bool cmp(pii a, pii b) {
    if(a.second == b.second) return a.first > b.first;
    return a.second < b.second;
}

ll order[SIZE];

int main() {
    sieve();
    cal_div();
    ll t = 0, n, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0;

    sort(num_div.begin(), num_div.end(), cmp);

    for0(i, 1000) order[i+1] = num_div[i].first;

    scl1(t);

    for1(i, t) {
        scl1(n);

        printcase;
        printl(order[n]);
    }

    return 0;
}

