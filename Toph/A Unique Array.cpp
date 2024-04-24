#include <bits/stdc++.h>
using namespace std;


//TEMPLATE
#define pb              push_back
#define mp              make_pair
#define ll              long long
#define ld              long double
#define pi              3.1415926536
//#define mod             1000000007
#define newline         printf("\n")
#define printminusone   printf("-1\n")
#define scl1(n)         scanf("%lld", &n)
#define scl2(a, b)      scanf("%lld %lld", &a, &b)
#define printl(n)       printf("%lld\n", n)
#define scd1(n)         scanf("%lf", &n)
#define scd2(a, b)      scanf("%lf %lf", &a, &b)
#define printd(n)       printf("%lf\n", n)
#define printld(n)      printf("%Lf\n", n)
#define printcase       printf("Case %lld:\n", i)
#define reversed(s)     reverse(s.begin(), s.end())
#define asorted(s)      sort(s.begin(), s.end())
#define dsorted(s)      sort(s.begin(), s.end(), cmp)
#define for0(i, n)      for (i = 0; i < n; i++)
#define for1(i, n)      for (i = 1; i <= n; i++)
#define fori(itt, stt)  for(itt = stt.begin(); itt != stt.end(); itt++)
#define pii             pair <ll, ll>
#define piii            pair <ll, pii>
//#define SIZE            100005
//#define INF             1000000005
#define F               first
#define S               second
#define FR              ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ms(arr, x)      memset(arr, x, sizeof arr)
#define bitcount(n)     __builtin_popcountll(n)

const ll INF = 1e18;
const ll SIZE = 1e5+5;
const ll mod = 1e9+7;

ll n, a[SIZE];
ll tree[SIZE*4];

void build(ll node, ll r1, ll r2) {
    if(r1 == r2) {
        tree[node] = 1;
        return;
    }

    ll bam = node*2;
    ll dan = bam + 1;

    ll mid = (r1 + r2) / 2;

    build(bam, r1, mid);
    build(dan, mid+1, r2);

    tree[node] = tree[bam] + tree[dan];
}

void update (ll node, ll r1, ll r2, ll in) {
    ll bam = node*2;
    ll dan = bam + 1;

    if(r1 > in || r2 < in) return;
    if(r1 == in && r2 == in) {
        tree[node] = 0;
        return;
    }

    ll mid = (r1 + r2) / 2;

    update(bam, r1, mid, in);
    update(dan, mid+1, r2, in);

    tree[node] = tree[bam] + tree[dan];
}

ll query(ll node, ll r1, ll r2, ll i, ll j) {
    ll bam = node*2;
    ll dan = bam + 1;

    if(r1 > j || r2 < i) return 0;
    if(r1 >= i && r2 <= j) return tree[node];

    ll mid = (r1 + r2) / 2;

    ll p1 = query(bam, r1, mid, i, j);
    ll p2 = query(dan, mid+1, r2, i, j);

    return (p1+p2);
}

ll find_in(ll lagbe) {
    ll st = 1, en = n;
    ll ans;

    while(st <= en) {
        ll mid = (st + en) / 2;

        ll t = query(1, 1, n, 1, mid);

        if(t >= lagbe) {
            ans = mid;
            en = mid - 1;
        }
        else st = mid + 1;
    }
    return ans;
}

int main() {
    ll t = 0, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0;
    scl1(t);

    for1(i, t) {
        scl2(n, q);

        for1(j, n) scl1(a[j]);

        ll size_now = n;

        build(1, 1, n);

        printcase;

        for1(j, q) {
            scl2(x, y);
            x++;

            if(size_now == 1) {
                ans = 1;
                printl(ans);
                continue;
            }

            if(j == 1) {
                a[x] = y;
                for1(k, n) {

                    for(x = k+1; x <= n; x++) {
                        if(a[x] != a[k]) break;

                        update(1, 1, n, x);
                    }
                    k = x-1;
                }

                ans = tree[1];
                printl(ans);

                size_now = tree[1];

                continue;
            }

            if(x == 1) {
                p = find_in(1);
                a[p] = y;
                z = find_in(2);

                if(a[p] == a[z]) update(1, 1, n, z);
            }
            else if(x == size_now) {
                p = find_in(size_now);
                a[p] = y;
                z = find_in(size_now-1);

                if(a[p] == a[z]) update(1, 1, n, z);
            }
            else {
                p = find_in(x);
                a[p] = y;

                z = find_in(x-1);
                c = find_in(x+1);

                if(a[p] == a[z] && a[p] == a[c]) {
                    update(1, 1, n, z);
                    update(1, 1, n, c);
                }
                else if(a[p] == a[z]) update(1, 1, n, z);
                else if(a[p] == a[c]) update(1, 1, n, c);
            }

            ans = tree[1];
            printl(ans);

            size_now = tree[1];
        }
    }

    return 0;
}

