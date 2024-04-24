#include <bits/stdc++.h>
using namespace std;


//TEMPLATE
#define pb              push_back
#define mp              make_pair
#define ll              long long int
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
#define reversed(s)     reverse(s.begin(), s.end())
#define asorted(s)      sort(s.begin(), s.end())
#define dsorted(s)      sort(s.begin(), s.end(), descending_func)
#define for0(i, n)      for (i = 0; i < n; i++)
#define for1(i, n)      for (i = 1; i <= n; i++)
#define pii             pair <string, ll>
#define piii            pair <ll, paired>
#define SIZE            100005
#define INF             1000000005
#define F               first
#define S               second

ll n;
string ans;

string bfs() {
    queue <pii> q;
    q.push(mp("1", 1));

    ll val, i;
    string s;

    while(!q.empty()) {
        s = q.front().first;
        val = q.front().second;
        q.pop();

        if(val%n == 0) return s;

        val %= n;

        q.push(mp(s+"0", val*10));
        q.push(mp(s+"1", val*10+1));
    }
}

int main() {
    ll t = 0, x, y, z, i, j, k, g, q, sum = 0, c = 0;
    scl1(t);

    while(t--) {
        scl1(n);

        ans = bfs();

        cout << ans << "\n";
    }

    return 0;
}
