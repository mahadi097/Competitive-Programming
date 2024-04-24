#include <bits/stdc++.h>
using namespace std;


//TEMPLATE
#define pb              push_back
#define mp              make_pair
#define ll              long long
#define ld              long double
#define pi              3.1415926536
#define mod             1000000007
#define newline         printf("\n")
#define printminusone   printf("-1\n")
#define scl1(n)         scanf("%lld", &n)
#define scl2(a, b)      scanf("%lld %lld", &a, &b)
#define printl(n)       printf("%lld\n", n)
#define scd1(n)         scanf("%lf", &n)
#define scd2(a, b)      scanf("%lf %lf", &a, &b)
#define printd(n)       printf("%lf\n", n)
#define printld(n)      printf("%Lf\n", n)
#define printcase       printf("Case %lld: ", i)
#define reversed(s)     reverse(s.begin(), s.end())
#define asorted(s)      sort(s.begin(), s.end())
#define dsorted(s)      sort(s.begin(), s.end(), cmp)
#define for0(i, n)      for (i = 0; i < n; i++)
#define for1(i, n)      for (i = 1; i <= n; i++)
#define pii             pair <ll, ll>
#define piii            pair <ll, pii>
#define SIZE            1005
#define INF             1000000005
#define F               first
#define S               second
#define FR              ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ms(arr, x)      memset(arr, x, sizeof arr)
#define bitcount(n)     __builtin_popcountll(n)

ll n1, n2;
bool vis[SIZE];
ll dis[SIZE];

bool st[SIZE];
vector <ll> prime;
void sieve() {
    ll i, j;

    for(i = 3; i*i < SIZE; i += 2) {
        if(!st[i]) {
            for(j = i*i; j < SIZE; j += i) st[j] = 1;
        }
    }

    prime.pb(2);
    for(i = 3; i < SIZE; i += 2) {
        if(!st[i]) prime.pb(i);
    }
}

vector <ll> factors;
void factorize(ll n) {
    ll sqrtn = sqrt(n);
    factors.clear();

    for(ll i = 0; i < prime.size() && prime[i] <= sqrtn && n > 1; i++) {
        if(n%prime[i] == 0) {
            factors.pb(prime[i]);

            while(n%prime[i] == 0) n /= prime[i];
        }
    }

    if(n > 1) factors.pb(n);
}

void bfs() {
    vis[n1] = 1;
    dis[n1] = 0;

    queue <ll> q;
    q.push(n1);

    ll u, v, i, t;

    while(!q.empty()) {
        u = q.front();
        q.pop();

        factorize(u);

        for0(i, factors.size()) {
            v = u + factors[i];

            if(v > n2 || u == factors[i]) continue;
            if(vis[v]) continue;

            vis[v] = 1;
            dis[v] = dis[u] + 1;
            q.push(v);
        }
    }
}

int main() {
    sieve();
    ll t = 0, n, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0;
    scl1(t);

    for1(i, t) {
        scl2(n1, n2);

        ms(vis, 0);
        ms(dis, 0);

        printcase;

        if(n1 == n2) {
            printf("0\n");
            continue;
        }
        if(n1 > n2) {
            printminusone;
            continue;
        }

        bfs();

        if(!vis[n2]) printminusone;
        else printl(dis[n2]);
    }

    return 0;
}

