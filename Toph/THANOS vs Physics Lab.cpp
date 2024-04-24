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
const ll SIZE = 3e5+5;
const ll mod = 1e9+7;


ll string_to_num(string s) {
    stringstream ss(s);
    ll num;
    ss >> num;

    return num;
}

int main() {
    ll t = 0, n, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0;
    string s, s1, s2;

    vector <ll> v;
    vector <char> op;

    scl1(t);

    for1(i, t) {
        cin >> s;

        n = s.size();
        v.clear();
        op.clear();
        bool f = 0;

        for0(j, n) {
            if(s[j] >= '0' && s[j] <= '9') {

                s1.clear();
                for(k = j; k < n; k++) {
                    if(s[k] >= '0' && s[k] <= '9') {
                        s1 += s[k];
                    }
                    else break;
                }

                x = string_to_num(s1);
                if(f) v.pb(-x);
                else v.pb(x);
//                printl(x);

                j = k-1;
                f = 0;
            }
            else {
                if(s[j] == '-') {
                    f = 1;
                    if(j == 0) continue;
                    op.pb('+');
                }
                else {
                    if(j == 0) continue;
                    op.pb(s[j]);
                }
            }
        }

        for0(j, op.size()) {
            if(op[j] == '/') {
                x = v[j] / v[j+1];
                v.erase(v.begin()+j+1);
                op.erase(op.begin()+j);
                v[j] = x;
                j--;
            }
        }

        for0(j, op.size()) {
            if(op[j] == '*') {

                x = v[j] * v[j+1];
                v.erase(v.begin()+j+1);
                op.erase(op.begin()+j);
                v[j] = x;
                j--;
            }
        }


        ans = 0;
        for0(j, v.size()) {
            ans += v[j];
        }

        printcase;
        printl(ans);
    }

    return 0;
}

