#include <bits/stdc++.h>
using namespace std;


//TEMPLATE
#define pb              push_back
#define mp              make_pair
#define ll              long long int
#define pi              3.1415926536
#define mod             100
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
#define SIZE            100000000
#define INF             1000000005

ll dr4[] = {0, 1, -1, 0, 0};
ll dc4[] = {0, 0, 0, 1, -1};

ll gcd(ll x, ll y) {
    if(y == 0) {
        return x;
    }
    return gcd(y, x%y);
}

bool check(ll n, ll pos) {
    return (n & (1LL << pos));
}
ll set1(ll n, ll pos) {
    return (n |= (1LL << pos));
}

ll status[SIZE/64+5];

void bit_sieve();

int main() {
    bit_sieve();
    ll t, n, m, a, b, x, y, z, i, j, k;

    printf("2\n");
    n = 1;
    for(i = 3; i <= SIZE; i += 2) {
        if(!check(status[i/64], i%64)) {
            n++;
            if(n%mod == 1) {
                printd(i);
            }
        }
    }

    return 0;
}

void bit_sieve() {
    ll i, j;

    for(i = 3; i*i < SIZE; i+= 2) {
        if(check(status[i/64], i%64) == 0) {
            for(j = i*i; j < SIZE; j += 2*i) {
                status[j/64] = set1(status[j/64], j%64);
            }
        }
    }
}
