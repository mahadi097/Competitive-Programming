#include <bits/stdc++.h>
using namespace std;


//TEMPLATE
#define pb                push_back
#define mp                make_pair
#define ll                int
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
const ll SZ = 4e5+5;
const ll mod = 1e9+7;


ll n;
//ll a[SZ];
//ll b[SZ];



int main() {
    FR;
    ll cs = 0, tc = 1, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0, t = 0;
//    ll a, b, d;
    string s, s1, s2;

    cin1(tc);

    while(tc--) {
        cin3(s, k, s1);

        n = s.size();
        c = count(all(s), '?');
        s2.clear();
        asort(s1);
        j = -1, t = k;

        for0(i, n) {
            if(s[i] != '?') {
                s2.pb(s[i]);
                continue;
            }

            s2.pb(s1[++j]);
            t--, c--;

            if(t == c) continue;
            if(c == 0) {
                while(1) {
                    s2.pb(s1[++j]);
                    if(j == k-1) break;
                }
                continue;
            }

            if(s[i+1] == '?' || s[i+1] < s1[j+1]) continue;

            while(t > c && s[i+1] > s1[j+1]) {
                s2.pb(s1[++j]);
                t--;
            }

            if(t == c || s[i+1] != s1[j+1]) continue;

            p = -1;
            fora(x, i+1, n-1) {
                if(s[i+1] != s[x]) {
                    p = x;
                    break;
                }
            }

            if(p == -1) continue;

            if(s[p] == '?' || s[p] < s[i+1]) {
                fora(x, i+1, p-1) s2.pb(s[x]);
                i = p-1;
                continue;
            }

            while(t > c && s1[j+1] == s[i+1]) {
                s2.pb(s1[++j]);
                t--;
            }

            fora(x, i+1, p-1) s2.pb(s[x]);
            i = p-1;
        }

        cot1(s2);
    }

    return 0;
}

