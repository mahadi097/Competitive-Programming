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
#define found(s, x)       (s.find(x) != s.end())

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
const ll SZ = 1e5+5;
const ll mod = 1e9+7;


ll n;
struct data {
    ll h, c, id;
} b[SZ];
ll st[SZ], en[SZ], res[SZ];
ll tree[SZ*4];

struct cmp {
    bool operator()(data x, data y) {
        return x.h < y.h;
    }
};

ll query(ll node, ll r1, ll r2, ll i, ll j) {
    ll bam = node*2;
    ll dan = bam + 1;

    if(r1 > j || r2 < i) return 0;
    if(r1 >= i && r2 <= j) return tree[node];

    ll mid = (r1 + r2) / 2;

    ll p1 = query(bam, r1, mid, i, j);
    ll p2 = query(dan, mid+1, r2, i, j);

    return max(p1, p2);
}

void update(ll node, ll r1, ll r2, ll in, ll val) {
    ll bam = node*2;
    ll dan = bam + 1;

    if(r1 > in || r2 < in) return;
    if(r1 >= in && r2 <= in) {
        tree[node] = val;
        return;
    }

    ll mid = (r1 + r2) / 2;

    update(bam, r1, mid, in, val);
    update(dan, mid+1, r2, in, val);

    tree[node] = max(tree[bam], tree[dan]);
}


int main() {
    FR;
    ll cs = 0, tc = 1, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0, t = 0;
//    ll a, b, d;
    string s, s1, s2;

    cin1(tc);

    while(tc--) {
        cin1(n);
        for1(i, n) cin1(b[i].h);
        for1(i, n) {
            cin1(b[i].c);
            b[i].id = i;
        }

        stack <ll> qq;
        qq.push(0);

        for1(i, n) {
            while(qq.top() != 0 && b[qq.top()].h <= b[i].h) qq.pop();
            st[i] = qq.top() + 1;
            qq.push(i);
        }
        while(!qq.empty()) qq.pop();

        qq.push(n+1);
        b[n+1].h = 1e9;
        forb(i, n, 1) {
            while(qq.top() != n+1 && b[qq.top()].h <= b[i].h) qq.pop();
            en[i] = qq.top() - 1;
            qq.push(i);
        }

        sort(b+1, b+n+1, cmp());
        ms(tree, 0);

        for1(i, n) {
            j = b[i].id;
            p = query(1, 1, n, st[j], en[j]);
            c = p + b[i].c;
            res[j] = c;
            update(1, 1, n, j, c);
        }
        for1(i, n) {
            j = b[i].id;
            p = query(1, 1, n, st[j], en[j]);
            res[j] = p;
        }

        cin1(q);
        while(q--) {
            cin1(x);
            cot1(res[x]);
        }
    }

    return 0;
}

