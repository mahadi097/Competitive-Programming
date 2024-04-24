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
#define pii             pair <ll, ll>
#define piii            pair <ll, paired>
#define SIZE            100005
#define INF             1000000005
#define F               first
#define S               second

ll dp[32][1005];
ll dir[32][1005];
ll gold[32], dep[32], dep1[32];
ll w, cap, n;
vector <ll> idx;

ll knapsack(ll i, ll t) {
    if(i == n+1) return 0;
    if(dp[i][t] != -1) return dp[i][t];

    ll p1 = 0, p2 = 0;

    if((t + dep1[i]) <= cap) p1 = gold[i] + knapsack(i+1, t+dep1[i]);
    p2 = knapsack(i+1, t);

    if(p1 >= p2) {
        dir[i][t] = 1;
        dp[i][t] = p1;
    }
    else {
        dir[i][t] = 2;
        dp[i][t] = p2;
    }

    return dp[i][t];
}

void get_path(ll i, ll t) {
//    if(i == n+1) return;
    if(dir[i][t] == -1) return;

    if(dir[i][t] == 1) {
        idx.pb(i);
        get_path(i+1, t+dep1[i]);
    }
    else get_path(i+1, t);
}

int main() {
    ll t = 0, x, y, z, i, j, k, g, q, ans = 0, sum = 0, c = 0;

    while(scl2(cap, w) == 2) {
        memset(dp, -1, sizeof dp);
        memset(dir, -1, sizeof dir);
        idx.clear();

        if(t >= 1) newline;

        scl1(n);

        for1(i, n) {
            scl2(dep[i], gold[i]);
            dep1[i] = 3 * dep[i] * w;
        }

        ans = knapsack(1, 0);

        printl(ans);

        get_path(1, 0);

        c = idx.size();

        printl(c);

        for0(i, c) {
            cout << dep[idx[i]] << " " << gold[idx[i]] << "\n";
        }
        t++;
    }

    return 0;
}

