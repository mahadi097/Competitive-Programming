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

ll find_nod(ll num) {
    ll i, c, nod = 1;
    ll sqrtn = sqrt(num);

    for(i = 0; i < prime.size() && prime[i] <= sqrtn; i++) {
        if(num%prime[i] == 0) {
            c = 0;

            while(num%prime[i] == 0) {
                num /= prime[i];
                c++;
            }
            nod *= (c + 1);
        }
    }

    if(num != 1) return nod*2;
    return nod;
}

vector <ll> seq;
ll cum[SIZE];
bool ok[SIZE];

void gen_seq() {
    seq.pb(1);

    ll i = 0;

    while(seq[i] < SIZE) {
        ok[seq[i]] = 1;
        ll val = seq[i] + find_nod(seq[i]);
        seq.pb(val);
        i++;
    }

    for1(i, SIZE-1) cum[i] = cum[i-1] + ok[i];
}

int main() {
    sieve();
    gen_seq();
    ll t = 0, n, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0;

    scl1(t);

    for1(i, t) {
        scl2(x, y);

        ans = cum[y] - cum[x-1];
        printcase;
        printl(ans);
    }

    return 0;
}

