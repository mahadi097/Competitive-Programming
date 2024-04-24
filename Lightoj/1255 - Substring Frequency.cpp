#include <bits/stdc++.h>
using namespace std;


//TEMPLATE
#define pb              push_back
#define mp              make_pair
#define ll              int
#define ld              long double
//#define pi              3.1415926536
#define pi              acos(-1)
//#define mod             1000000007
#define newline         printf("\n")
#define printminusone   printf("-1\n")
#define scl1(n)         scanf("%d", &n)
#define scl2(a, b)      scanf("%lld %lld", &a, &b)
#define scl3(a, b, c)   scanf("%lld %lld %lld", &a, &b, &c)
#define printl(n)       printf("%d\n", n)
#define ssl1(str)       scanf(" %[^\n]", str)
#define scd1(n)         scanf("%lf", &n)
#define scd2(a, b)      scanf("%lf %lf", &a, &b)
#define printd(n)       printf("%lf\n", n)
#define printld(n)      printf("%Lf\n", n)
#define printcase       printf("Case %d: ", i)
#define reversed(s)     reverse(s.begin(), s.end())
#define asorted(s)      sort(s.begin(), s.end())
#define dsorted(s)      sort(s.begin(), s.end(), cmp)
#define for0(i, n)      for (i = 0; i < n; i++)
#define for1(i, n)      for (i = 1; i <= n; i++)
#define fori(itt, stt)  for(auto itt = stt.begin(); itt != stt.end(); itt++)
#define pii             pair <ll, ll>
#define piii            pair <ll, pii>
//#define SIZE            100005
//#define INF             1000000005
#define F               first
#define S               second
#define FR              ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ms(arr, x)      memset(arr, x, sizeof arr)
#define bitcount(n)     __builtin_popcountll(n)

const ll INF = LLONG_MAX;
const ll SZ = 1e6+5;
const ll mod = 1e9+7;

const ll p1 = 37;
const ll p2 = 137;
const ll mod1 = 277;
const ll mod2 = 1e4+7;

ll pw1[SZ], pw2[SZ];
ll h1[3][SZ], h2[3][SZ]; ///1-BASED INDEX
ll szs[3]; ///SIZE OF STRING ID: 0,1,2,3...

void cal_pwr() {
    pw1[0] = pw2[0] = 1;
    for(ll i = 1; i < SZ; i++) {
        pw1[i] = (pw1[i-1]%mod1 * p1%mod1) % mod1;
        pw2[i] = (pw2[i-1]%mod2 * p2%mod2) % mod2;
    }
}

void build_hash(string s, ll id) {
    ll i, sz = s.size();
    szs[id] = sz;

    h1[id][0] = h2[id][0] = 0;
    for0(i, sz) {
        h1[id][i+1] = ((h1[id][i] * p1)%mod1 + s[i]) % mod1;
        h2[id][i+1] = ((h2[id][i] * p2)%mod2 + s[i]) % mod2;
    }
}

pii get_hash(ll l, ll r, ll id) {
    ll v1 = (h1[id][r] - (h1[id][l-1] * pw1[r-l+1])%mod1) % mod1;
    if(v1 < 0) v1 += mod1;

    ll v2 = (h2[id][r] - (h2[id][l-1] * pw2[r-l+1])%mod2) % mod2;
    if(v2 < 0) v2 += mod2;

    return mp(v1, v2);
}

ll check_sub(ll id1, ll id2) {
    if(szs[id1] < szs[id2]) return 0;

    ll sz1 = szs[id1];
    ll sz2 = szs[id2];
    ll c(0);

    for(ll i = sz2; i <= sz1; i++) {
        pii p = get_hash(i-sz2+1, i, id1);
        if(p.F == h1[id2][sz2] && p.S == h2[id2][sz2]) c++;
    }

    return c;
}

int main() {
    cal_pwr();
    ll t = 0, n, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0;
    string s, s1, s2;

    scl1(t);

    for1(i, t) {
        cin >> s >> s1;
        build_hash(s, 0);
        build_hash(s1, 1);
        c = check_sub(0, 1);

        printcase;
        printl(c);
    }

    return 0;
}

