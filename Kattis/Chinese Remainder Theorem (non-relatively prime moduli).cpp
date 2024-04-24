#include <bits/stdc++.h>
using namespace std;


//TEMPLATE
#define len(a)            (ll) a.size()
#define ms(a, x)          memset(a, x, sizeof a)
#define bitcount(n)       __builtin_popcountll(n)
#define FR                ios_base::sync_with_stdio(false);cin.tie(NULL)

#define cin1(a)           cin >> a
#define cin2(a, b)        cin >> a >> b
#define cin3(a, b, c)     cin >> a >> b >> c
#define cin4(a, b, c, d)  cin >> a >> b >> c >> d
#define cots(a)           cout << a << " "
#define cot1(a)           cout << a << "\n"
#define cot2(a, b)        cout << a << " " << b << "\n"
#define cot3(a, b, c)     cout << a << " " << b << " " << c << "\n"
#define cot4(a, b, c, d)  cout << a << " " << b << " " << c << " " << d << "\n"
#define cotcase(cs)       cout << "Case " << cs << ": "
#define yes               cout << "Yes\n"
#define no                cout << "No\n"
#define line              cout << "\n"

#define reversed(s)       reverse(s.begin(), s.end())
#define asort(s)          sort(s.begin(), s.end())
#define dsort(s)          sort(s.rbegin(), s.rend())
#define all(s)            s.begin(), s.end()
#define uniq(s)           s.resize(distance(s.begin(),unique(s.begin(), s.end())))
#define found(s, x)       (s.find(x) != s.end())

#define for0(i, n)        for (i = 0; i < n; i++)
#define for1(i, n)        for (i = 1; i <= n; i++)
#define fora(i, a, b)     for (i = a; i <= b; i++)
#define forb(i, b, a)     for (i = b; i >= a; i--)

#define ll                long long
#define pb                push_back
#define mp                make_pair
#define ld                long double
#define pii               pair <ll, ll>
#define piii              pair <ll, pii>
#define F                 first
#define S                 second
#define pi                acos(-1.0)

#define bug(args ...) cerr << __LINE__ << ": ", err(new istringstream(string(#args)), args), cerr << '\n'
void err(istringstream *iss) {}
template<typename T, typename... Args>
void err(istringstream *iss, const T a, const Args... args) {
    string _name;
    *iss >> _name;
    if (_name.back()==',') _name.pop_back();
    cerr << _name << " = " << fixed << setprecision(5) << a << "; ", err(iss, args...);
}

const ll INF = LLONG_MAX;
const ll SZ = 4e5+5;
const ll mod = 1e9+7;



string s, s1, s2;
ll n, k, ans = 0;
ll a[SZ];
//ll b[SZ];

ll c1, c2;
ll ex_euclid(ll a, ll b) {
    if(b == 0) {
        c1 = 1;
        c2 = 0;
        return a;
    }

    ll g = ex_euclid(b, a%b);

    ll x1 = c1;
    c1 = c2;
    c2 = x1 - c2 * (a/b);

    return g;
}

pii CRT_strong(vector <ll> a, vector <ll> m) { ///values of m are not necessarily pairwise co-prime.
    if(len(a) != len(m)) return {-1, -1};///invalid input

    ll n = len(a);

    ll a1 = a[0];
    ll m1 = m[0];

    ll x = a1, lc = m1; ///initial x & lcm

    for(ll i = 1; i < n; i++) {
        ll a2 = a[i];
        ll m2 = m[i];

        ll g = __gcd(m1, m2);
        ll mm1 = m1/g, mm2 = m2/g;

        ///merging two equations
        ll tmp_g = ex_euclid(mm1, mm2);
        ll p = c1, q = c2;

        if(a1%g != a2%g) return {-1, -1}; ///no solution

        lc = (m1 / g) * m2; /// lcm of m1 & m2

        x = ( ( (__int128) a1 * mm2 % lc * q % lc ) + ( (__int128) a2 * mm1 % lc * p % lc ) ) % lc; ///be careful about overflow
        if(x < 0) x += lc;

        ///merged equation
        a1 = x;
        m1 = lc;
    }

    return {x, lc};
}

int main() {
    FR;
    ll cs = 0, tc = 1, x, y, z, i, j, g, p, q, sum = 0, c = 0, t = 0;
//    ll a, b, d;
//    string s, s1, s2;

    cin1(tc);

    while(tc--) {
        vector <ll> a, m;

        cin4(x, y, p, q);

        a = {x, p};
        m = {y, q};

        auto ans = CRT_strong(a, m);
        (ans.F == -1) ? cot1("no solution") : cot2(ans.F, ans.S);
    }

    return 0;
}

