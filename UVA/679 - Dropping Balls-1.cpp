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
#define scand(n)        scanf("%lld", &n)
#define printd(n)       printf("%lld\n", n)
#define scandd(n)       scanf("%lf", &n)
#define printdd(n)      printf("%lf\n", n)
#define reversed(s)     reverse(s.begin(), s.end())
#define asorted(s)      sort(s.begin(), s.end())
#define dsorted(s)      sort(s.begin(), s.end(), descending_func)
#define for0(i, n)      for (i = 0; i < n; i++)
#define for1(i, n)      for (i = 1; i <= n; i++)
#define paired          pair <ll, ll>
#define pii             pair <ll, paired>
#define SIZE            100005
#define INF             1000000005

ll dr4[] = {0, 1, -1, 0, 0};
ll dc4[] = {0, 0, 0, 1, -1};

ll n;
ll bs(ll c, ll b);

int main() {
    ll t, m, a, b, c, d, x, y, z, i, j, k;
    scand(t);

    while(t--) {
        scand(d), scand(b);

        n = (2 << (d-1)) - 1;
        c = bs(1, b);

        printd(c);
    }
//    printminusone;

    return 0;
}

ll bs(ll c, ll b) {
    ll left = c * 2;
    ll right = left + 1;

    if(left <= n && right <= n) {
        if(b%2 == 0) {
            return bs(right, b/2);
        }
        else {
            return bs(left, (b/2)+1);
        }
    }
    return c;
}
