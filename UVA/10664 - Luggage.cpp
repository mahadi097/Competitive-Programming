
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
#define paired          pair <ll, ll>
#define pii             pair <ll, paired>
#define SIZE            100005
#define INF             1000000005

ll sum, n;
ll dp1[25][205], dp2[25][205];
ll weight[25];
bool pos;

ll knapsack(ll i, ll w) {
    if(i == n+1) return 0;
    if(dp1[i][w] != -1) return dp1[i][w];
    if(dp2[i][w] != -1) return dp2[i][w];

    dp1[i][w] = weight[i] + knapsack(i+1, w+weight[i]);
    if(w == sum) pos = true;

    dp2[i][w] = knapsack(i+1, w);
    if(w == sum) pos = true;

    return pos;
}

int main() {
    ll t = 0, x, y, z, i, j, k, g, q, ans = 0;
    scl1(t);
    cin.ignore();

    while(t--) {
        sum = 0;
        memset(dp1, -1, sizeof dp1);
        memset(dp2, -1, sizeof dp2);
        memset(weight, 0, sizeof weight);
        pos = false;

        string s;
        getline(cin, s);

        stringstream ss(s);
        i = 1;

        while(ss >> weight[i]) {
            sum += weight[i];
            i++;
        }
        n = i - 1;

        if(sum%2) {
            cout << "NO\n";
            continue;
        }

        sum /= 2;

        ans = knapsack(1, 0);

        if(ans) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }

    return 0;
}

