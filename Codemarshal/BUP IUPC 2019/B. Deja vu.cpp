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
#define cots(a)           cout << " " << a
#define cot1(a)           cout << a << "\n"
#define cot2(a, b)        cout << a << " " << b << "\n"
#define cot3(a, b, c)     cout << a << " " << b << " " << c << "\n"
#define cot4(a, b, c, d)  cout << a << " " << b << " " << c << " " << d << "\n"
#define cotcase(cs)       cout << "Case " << cs << ":"
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
const ll SZ = 1e3+5;
const ll mod = 1e9+7;



string s, s1, s2;
ll n, k, ans = 0;
ll a[SZ*100];
ll in[SZ];

bitset <SZ> st;
vector <ll> prime;
void sieve() {
    ll i, j;

    st[0] = st[1] = 1;
    for(i = 2; i*i < SZ; i++) {
        if(!st[i]) {
            for(j = i*i; j < SZ; j += i) st[j] = 1;
        }
    }

    prime.pb(2);
    for(i = 3; i < SZ; i += 2) {
        if(!st[i]) prime.pb(i);
    }

    for(auto p: prime) in[p] = ++k;
}

vector <pii> f;
void factorize(ll x) {

    for(ll i = 0; i < prime.size() && prime[i]*prime[i] <= x; i++) {
        if(x%prime[i] == 0) {
            ll c = 0;
            while(x%prime[i] == 0) {
                x /= prime[i];
                c++;
            }
            f.pb({ prime[i], c });
        }
    }
    if(x > 1) f.pb({x, 1});

}

ll tree[172][SZ*400];

void build(ll node, ll r1, ll r2) {
    if(r1 == r2) {
        for1(k, 170) tree[k][node] = 0;
        return;
    }

    ll bam = node*2;
    ll dan = node*2 + 1;

    ll mid = (r1 + r2) / 2;

    build(bam, r1, mid);
    build(dan, mid+1, r2);

    for1(k, 170) tree[k][node] = 0;
}

ll query(ll p, ll node, ll r1, ll r2, ll i, ll j) {
    if(i > r2 || j < r1) return 0;
    if(r1 >= i && r2 <= j) return tree[p][node];

    ll bam = node*2;
    ll dan = node*2 + 1;

    ll mid = (r1 + r2) / 2;

    ll p1 = query(p, bam, r1, mid, i, j);
    ll p2 = query(p, dan, mid+1, r2, i, j);

    return max(p1, p2);
}

ll QUERY(ll p, ll i, ll j) {
    return query(p, 1, 1, n, i, j);
}

void update(ll p, ll node, ll r1, ll r2, ll in, ll v) {
    if(in > r2 || in < r1) return;
    if(r1 >= in && r2 <= in) {
        tree[p][node] = v;
        return;
    }

    ll bam = node*2;
    ll dan = node*2 + 1;

    ll mid = (r1 + r2) / 2;

    update(p, bam, r1, mid, in, v);
    update(p, dan, mid+1, r2, in, v);

    tree[p][node] = max(tree[p][bam], tree[p][dan]);
}

void UPDATE(ll p, ll i, ll v) {
    update(p, 1, 1, n, i, v);
}

int main() {
    FR;
    sieve();
    ll cs = 0, tc = 1, x, y, z, i, j, g, p, q, sum = 0, c = 0, t = 0;
//    ll a, b, d;
//    string s, s1, s2;

//    bug(len(prime));

    cin1(tc);

    while(tc--) {
        cin2(n, q);

        for1(i, n) a[i] = 1;

        build(1, 1, n);

        unordered_map <ll, vector<ll>> sq;

        while(q--) {
            cin3(x, y, z);

            f.clear();
            factorize(z);

            for(auto pf: f) {
                if(pf.F > 1e3) {
                    auto ps = lower_bound(all(sq[pf.F]), x) - sq[pf.F].begin();

                    if(ps == len(sq[pf.F]) || sq[pf.F][ps] > y) {
                        a[y] = (a[y] * pf.F) % mod;
                        sq[pf.F].pb(y);
                    }

                    continue;
                }

                c = QUERY(in[pf.F], x, y);

                if(c < pf.S) {
                    t = QUERY(in[pf.F], y, y);
                    fora(i, t+1, pf.S) a[y] = (a[y] * pf.F) % mod;
                    UPDATE(in[pf.F], y, pf.S);
                }
            }

        }

        cotcase(++cs);
        for1(i, n) cots(a[i]);
        line;
    }

    return 0;
}

