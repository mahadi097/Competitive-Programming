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
#define SIZE            1000005
#define INF             1000000005

ll phi[SIZE];
ll mark[SIZE];

void sieve_phi();

int main() {
    sieve_phi();

    ll t, n, m, a, b, c, x, y, z, i, j, k;
    scand(t);

    while(t--) {
        scand(n);

        printd(phi[n]);
    }

    return 0;
}

void sieve_phi() {
    ll i, j, k;

    for1(i, SIZE-1) {
        phi[i] = i;
    }

    mark[1] = 1;

    for(i = 2; i < SIZE; i++) {
        if(!mark[i]) {
            for(j = i; j < SIZE; j += i) {
                mark[j] = i;

                phi[j] -= phi[j] / i;
            }
        }
    }
}
