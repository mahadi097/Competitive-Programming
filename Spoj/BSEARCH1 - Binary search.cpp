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

ll binary_search_func(ll a[], ll l, ll r, ll x);

int main() {
    ll t, n, q, i, j, k;
    scand(n), scand(q);

    ll a[n];
    for0(i, n) {
        scand(a[i]);
    }

    ll result, x;

    while(q--) {
        scand(x);

        result = binary_search_func(a, 0, n-1, x);
        result == -1 ? printminusone : printd(result);
    }

    return 0;
}

ll binary_search_func(ll a[], ll l, ll r, ll x) {
    ll mid_index, ret = -1;

    while(l <= r) {
        mid_index = (l+r) / 2;

        if(x == a[mid_index]) {
            ret = mid_index;
            r = mid_index - 1;
        }
        else if(x < a[mid_index]) {
            r = mid_index - 1;
        }
        else if(x > a[mid_index]) {
            l = mid_index + 1;
        }
    }

    return ret;
}
