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

ll bs_low(ll a[], ll n, ll x, ll y);
ll bs_high(ll a[], ll n, ll x, ll y, ll low);

int main() {
    ll t, n, m, a, b, x, y, z, i, j, k, q;
    scand(t);

    for1(i, t) {
        scand(n), scand(q);

        ll point[n+1], c;
        for1(j, n) {
            scand(point[j]);
        }

        printf("Case %lld:\n", i);

        while(q--) {
            scand(x), scand(y);

            a = bs_low(point, n, x, y); //LOW INDEX
            b = bs_high(point, n, x, y, a); //HIGH INDEX

            b == 0 ? c = 1 : c = b - a + 1;
            if(a == 0 && b == 0) {
                c = 0;
            }
//            cout << a << " " << b << "\n";
            printd(c);
        }
    }

    return 0;
}

ll bs_low(ll a[], ll n, ll x, ll y) {
    ll st = 1, en = n, mid, low = 0;

    while(st <= en) {
        mid = (st + en) / 2;

        if(a[mid] >= x && a[mid] <= y) {
            low = mid;
//            cout << mid << " " << a[mid] << endl;
            en = mid - 1;
        }
        else if(a[mid] < x) {
            st = mid + 1;
        }
        else if(a[mid] > y) {
            en = mid - 1;
        }
    }

    return low;
}

ll bs_high(ll a[], ll n, ll x, ll y, ll low) {
    ll st = low+1, en = n, mid, high = 0;

    while(st <= en) {
        mid = (st + en) / 2;

        if(a[mid] > y) {
            en = mid - 1;
        }
        else if(a[mid] >= x && a[mid] <= y) {
            high = mid;
            st = mid + 1;
        }
        else {
            break;
        }
    }

    return high;
}
