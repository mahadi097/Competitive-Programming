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
#define SIZE            1000001
#define INF             1000000005

ll dr4[] = {0, 1, -1, 0, 0};
ll dc4[] = {0, 0, 0, 1, -1};

ll gcd(ll x, ll y) {
    if(y == 0) {
        return x;
    }
    return gcd(y, x%y);
}

bool st[SIZE];

bool solve(ll n, ll m) {
    ll x, y, z, i, j, k;
    bool conflict = false;
    memset(st, false, sizeof(st));

    for1(i, n) {
        scand(x), scand(y);

        if(!conflict) {
            for(j = x+1; j <= y; j++) {
                if(!st[j]) {
                    st[j] = true;
                }
                else {
                    conflict = true;
                    break;
                }
            }
        }
    }

    for1(i, m) {
        scand(x), scand(y), scand(z);

        if(!conflict) {
            while(x < SIZE && y < SIZE) {
                for(j = x+1; j <= y; j++) {
                    if(!st[j]) {
                        st[j] = true;
                    }
                    else {
                        conflict = true;
                        break;
                    }
                }
                x += z, y += z;
            }
        }
    }

    return conflict;
}

int main() {
    ll t, n, m, a, b, x, y, z, i, j, k;

    while((scanf("%lld %lld", &n, &m)) && (n || m)) {
        bool conflict = solve(n, m);

        if(!conflict) {
            printf("NO CONFLICT\n");
        }
        else {
            printf("CONFLICT\n");
        }
    }

    return 0;
}

