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

int main() {
    ll t, n, m, a, b, c, d, x, y, z, i, j, k;
    scand(t);

    while(t--) {
        scand(d), scand(b);

        c = 1;
        n = (2 << (d-1)) - 1;

        while((c+c) <= n) {
            if(b%2 == 1) {
                c += c;
            }
            else {
                c += c + 1;
            }
            b = (b + 1) / 2;
        }

        printd(c);
    }
//    printminusone;

    return 0;
}

