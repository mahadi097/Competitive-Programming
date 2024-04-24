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
#define SIZE            10000005

int main() {
    ll t, n, q, i, j, k;
    scand(n);

    ll a[n];
    for0(i, n) {
        scand(a[i]);
        if(i == 0) {
            continue;
        }

        a[i] += a[i-1];
    }

    scand(q);

    while(q--) {
        scand(i), scand(j);

        if(i == 0) {
            printd(a[j]);
        }
        else {
            printd(a[j]-a[i-1]);
        }
    }

    return 0;
}

