#include <bits/stdc++.h>
using namespace std;


//TEMPLATE
#define pb                push_back
#define mp                make_pair
#define ll                long long
#define ld                long double
#define pii               pair <ll, ll>
#define piii              pair <ll, pii>
#define F                 first
#define S                 second

#define newline           printf("\n")
#define minusone          printf("-1\n")
#define zeroo             printf("0\n")
#define scl1(a)           scanf("%lld", &a)
#define scl2(a, b)        scanf("%lld %lld", &a, &b)
#define scl3(a, b, c)     scanf("%lld %lld %lld", &a, &b, &c)
#define prl1(a)           printf("%lld\n", a)
#define prl2(a, b)        printf("%lld %lld\n", a, b)
#define ssl1(s)           scanf(" %[^\n]", s)
#define scd1(a)           scanf("%lf", &a)
#define scd2(a, b)        scanf("%lf %lf", &a, &b)
#define prd(a)            printf("%lf\n", a)
#define prld(a)           printf("%Lf\n", a)
#define prcase(cs)        printf("Case %lld: ", cs)
#define cin1(a)           cin >> a
#define cin2(a, b)        cin >> a >> b
#define cin3(a, b, c)     cin >> a >> b >> c
#define cin4(a, b, c, d)  cin >> a >> b >> c >> d
#define cot1(a)           cout << a << "\n"
#define cot2(a, b)        cout << a << " " << b << "\n"
#define cot3(a, b, c)     cout << a << " " << b << " " << c << "\n"
#define cot4(a, b, c, d)  cout << a << " " << b << " " << c << " " << d << "\n"
#define cotline           cout << "\n"
#define cotminus          cout << "-1\n"
#define cot0              cout << "0\n"
#define cotyes            cout << "YES\n"
#define cotno             cout << "NO\n"
#define cotcase(cs)       cout << "Case " << cs << ": "

#define reversed(s)       reverse(s.begin(), s.end())
#define asort(s)          sort(s.begin(), s.end())
#define dsort(s)          sort(s.rbegin(), s.rend())
#define all(s)            s.begin(), s.end()
#define uniq(s)           s.resize(distance(s.begin(),unique(s.begin(), s.end())))
#define found(s, x)       s.find(x) != s.end()

#define for0(i, n)        for (i = 0; i < n; i++)
#define for1(i, n)        for (i = 1; i <= n; i++)
#define fora(i, a, b)     for (i = a; i <= b; i++)
#define forb(i, b, a)     for (i = b; i >= a; i--)
#define fori(it, s)       for(auto it = s.begin(); it != s.end(); it++)

#define FR                ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ms(a, x)          memset(a, x, sizeof a)
#define bitcount(n)       __builtin_popcountll(n)

//#define pi              3.1415926536
#define pi                acos(-1)

const ll INF = LLONG_MAX;
const ll SZ = 4e5+5;
const ll mod = 1e9+7;


ll n, b, k;
ll dp[(1LL<<16LL)+5][22];
string s;
unordered_map <char, ll> m;

void pre_cal() {
    ll c;
    for(char cc = '0', c = 0; cc <= '9'; cc++, c++) m[cc] = c;
    for(char cc = 'A', c = 10; cc <= 'F'; cc++, c++) m[cc] = c;
}

bool check(ll x, ll pos) {
    return (x & (1LL << pos));
}

ll set1(ll x, ll pos) {
    return (x | (1LL << pos));
}

ll solve(ll msk, ll r) {
    if(msk == (1<<n)-1) return (r == 0);
    if(dp[msk][r] != -1) return dp[msk][r];

    ll i, x, res(0);

    for0(i, n) {
        if(check(msk, i)) continue;

        x = ((r * b) + m[s[i]]) % k;
        res += solve(set1(msk, i), x);
    }

    return dp[msk][r] = res;
}


int main() {
//    FR;
    pre_cal();
    ll cs = 0, tc = 1, x, y, z, i, j, g, p, q, ans = 0, sum = 0, c = 0, t = 0;
//    ll a, b, d;
    string s1, s2;

    cin1(tc);

    while(tc--) {
        cin3(b, k, s);
        n = s.size();

        ms(dp, -1);

        cotcase(++cs);
        cot1(solve(0, 0));
    }

    return 0;
}

