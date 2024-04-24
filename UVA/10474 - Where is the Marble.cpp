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

ll khojo(ll num[], ll n, ll x);

int main() {
    ll t, n, m, a, b, x, y, z, i, j = 1, k, q;

    while((cin >> n >> q) && n && q) {

        ll num[n+1];
        for1(i, n) {
            scand(num[i]);
        }
        sort(num+1, num+n+1);

        printf("CASE# %lld:\n", j);

        while(q--) {
            scand(x);

            m = khojo(num, n, x);

            m == -1 ? printf("%lld not found\n", x) : printf("%lld found at %lld\n", x, m);
        }

        j++;
    }

    return 0;
}

ll khojo(ll num[], ll n, ll x) {
    ll st = 1, en = n, mid, paisi = -1;

    while(st <= en) {
        mid = (st + en) / 2;

        if(num[mid] == x) {
            paisi = mid;
            en = mid - 1;
        }
        else if(num[mid] > x) {
            en = mid - 1;
        }
        else {
            st = mid + 1;
        }
    }

    return paisi;
}
