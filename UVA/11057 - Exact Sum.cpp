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

ll b1, b2;
void find_books(ll book[], ll n, ll money);

int main() {
    ll t, n, m, a, b, c, x, y, z, i, j, k;

    while(scand(n) == 1) {
        ll book[n];
        for0(i, n) {
            scand(book[i]);
        }
        sort(book, book+n);

        ll money;
        scand(money);

        find_books(book, n, money);

        printf("Peter should buy books whose prices are %lld and %lld.\n\n", b1, b2);
    }

    return 0;
}

void find_books(ll book[], ll n, ll money) {
    ll mid, i, j;
    ll x1, x2;
    ll st, enn = n-1, en;

    for0(i, n) {
        x1 = book[i];
        x2 = money - x1;

        st = i+1, en = enn;

        while(st <= en) {
            mid = (st + en) / 2;

            if(book[mid] == x2) {
                b1 = x1;
                b2 = x2;
                enn = mid - 1;
                break;
            }
            else if(book[mid] > x2) {
                en = mid - 1;
            }
            else {
                st = mid + 1;
            }
        }
    }
}
