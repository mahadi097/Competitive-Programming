#include <bits/stdc++.h>
using namespace std;


//TEMPLATE
#define pb              push_back
#define mp              make_pair
#define ll              long long
#define ld              long double
//#define pi              3.1415926536
#define pi              acos(-1)
//#define mod             1000000007
#define newline         printf("\n")
#define printminusone   printf("-1\n")
#define scl1(n)         scanf("%lld", &n)
#define scl2(a, b)      scanf("%lld %lld", &a, &b)
#define scl3(a, b, c)   scanf("%lld %lld %lld", &a, &b, &c)
#define printl(n)       printf("%lld\n", n)
#define ssl1(str)       scanf(" %[^\n]", str)
#define scd1(n)         scanf("%lf", &n)
#define scd2(a, b)      scanf("%lf %lf", &a, &b)
#define printd(n)       printf("%lf\n", n)
#define printld(n)      printf("%Lf\n", n)
#define printcase       printf("Case %lld: ", i)
#define reversed(s)     reverse(s.begin(), s.end())
#define asorted(s)      sort(s.begin(), s.end())
#define dsorted(s)      sort(s.begin(), s.end(), cmp)
#define for0(i, n)      for (i = 0; i < n; i++)
#define for1(i, n)      for (i = 1; i <= n; i++)
#define fori(itt, stt)  for(itt = stt.begin(); itt != stt.end(); itt++)
#define pii             pair <ll, ll>
#define piii            pair <ll, pii>
//#define SIZE            100005
//#define INF             1000000005
#define F               first
#define S               second
#define FR              ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ms(arr, x)      memset(arr, x, sizeof arr)
#define bitcount(n)     __builtin_popcountll(n)

const ll INF = 1e18;
const ll SIZE = 1125;
const ll mod = 1e9+7;


ll sz;
bool st[SIZE];
vector <ll> prime;
void sieve() {
    ll i, j;

    for(i = 3; i*i < SIZE; i += 2) {
        if(!st[i]) {
            for(j = i*i; j < SIZE; j += i) st[j] = 1;
        }
    }

    prime.pb(2);
    for(i = 3; i < SIZE; i += 2) {
        if(!st[i]) prime.pb(i);
    }
    sz = prime.size();
}

ll n, k;
ll dp[200][SIZE][16];

ll solve(ll in, ll rem, ll cnt) {
    if(cnt == 0) return (rem == 0);
    if(rem <= 0 || in == sz) return 0;
    if(dp[in][rem][cnt] != -1) return dp[in][rem][cnt];

    ll p1 = solve(in+1, rem, cnt);
    ll p2 = solve(in+1, rem-prime[in], cnt-1);

    return dp[in][rem][cnt] = (p1+p2);
}

int main() {
    sieve();
    ms(dp, -1);
    ll t = 0, x, y, z, i, j, g, p, q, ans = 0, sum = 0, c = 0;
    string s, s1, s2;

    while(scl2(n, k)) {
        if(!n && !k) break;

        ans = solve(0, n, k);
        printl(ans);
    }

    return 0;
}

