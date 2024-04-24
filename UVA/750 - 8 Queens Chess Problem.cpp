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

ll queen[9];
bool row[9], d1[18], d2[18];
ll c, x, y;

void nqueen(ll now) {
    if(now == 9) {
        ll i;

        printf("%2lld      ", c);
        c++;

        for1(i, 8) {
            (i == 8) ? printf("%lld\n", queen[i]) : printf("%lld ", queen[i]);
        }
        return;
    }

    if(now == y) nqueen(now+1);
    else {
        ll i;
        for1(i, 8) {
            if(row[i] || d1[i+now] || d2[8+i-now]) continue;

            queen[now] = i;
            row[i] = d1[i+now] = d2[8+i-now] = 1;

            nqueen(now+1);
            row[i] = d1[i+now] = d2[8+i-now] = 0;
        }
    }
}

int main() {
    ll t = 0, n, z, i, j, k, g, q, ans = 0, sum = 0;
    scl1(t);

    while(t--) {
        scl2(x, y);

        c = 1;
        memset(row, false, sizeof row);
        memset(d1, false, sizeof d1);
        memset(d2, false, sizeof d2);

        queen[y] = x;
        row[x] = d1[x+y] = d2[8+x-y] = 1;

        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");

        nqueen(1);

        if(t) newline;
    }


    return 0;
}

