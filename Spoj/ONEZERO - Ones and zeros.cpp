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
#define paired          pair <string, ll>
#define pii             pair <ll, paired>
#define SIZE            100005
#define INF             1000000005

string bfs(ll n) {
    queue <paired> q;
    q.push(mp("1", 1));

    string x;
    ll y, i, a, b;

    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        if(y%n == 0) {
            return x;
        }

        a = ((y % n) * 10) % n;
        b = ((y % n) * 10 + 1) % n;

        q.push(mp(x+"0", a));
        q.push(mp(x+"1", b));
    }
}

int main() {
    ll t, n, x, y, z, i, j, k, g, q, sum = 0;
    scl1(t);

    while(t--) {
        scl1(n);

        string ans = bfs(n);

        cout << ans << endl;
    }

    return 0;
}

