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

ll search_low(ll arr[], ll n, ll x);
ll search_high(ll arr[], ll n, ll x);

int main() {
    ll t, n, m, a, b, c, x, y, z, i, j, k;
    scand(n);

    ll height[n];
    for0(i, n) {
        scand(height[i]);
    }

    scand(m);
    while(m--) {
        scand(x);
        a = search_low(height, n, x);
        b = search_high(height, n, x);

        a == -1 ? printf("X ") : printf("%lld ", a);
        b == -1 ? printf("X\n") : printf("%lld\n", b);
    }

    return 0;
}

ll search_low(ll arr[], ll n, ll x) {
    ll st = 0, en = n-1;
    ll mid, ans = - 1;

    while(st <= en) {
        mid = (st + en) / 2;

        if(arr[mid] >= x) {
            en = mid - 1;
        }
        else if(arr[mid] < x) {
            ans = arr[mid];
            st = mid + 1;
        }
    }
    return ans;
}
ll search_high(ll arr[], ll n, ll x) {
    ll st = 0, en = n-1;
    ll mid, ans = - 1;

    while(st <= en) {
        mid = (st + en) / 2;

        if(arr[mid] <= x) {
            st = mid + 1;
        }
        else if(arr[mid] > x) {
            ans = arr[mid];
            en = mid - 1;
        }
    }
    return ans;
}
