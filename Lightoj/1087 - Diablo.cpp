#include <bits/stdc++.h>
using namespace std;


//TEMPLATE
#define pb              push_back
#define mp              make_pair
#define ll              long long
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
#define printcase       printf("Case %lld:\n", i)
#define reversed(s)     reverse(s.begin(), s.end())
#define asorted(s)      sort(s.begin(), s.end())
#define dsorted(s)      sort(s.begin(), s.end(), cmp)
#define for0(i, n)      for (i = 0; i < n; i++)
#define for1(i, n)      for (i = 1; i <= n; i++)
#define pii             pair <ll, ll>
#define piii            pair <ll, pii>
#define SIZE            150005
#define INF             1000000005
#define F               first
#define S               second
#define FR              ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ms(arr, x)      memset(arr, x, sizeof arr)
#define bitcount(n)     __builtin_popcountll(n)

ll a[SIZE];
ll tree[SIZE*4];

void build(ll node, ll r1, ll r2) {
    if(r1 == r2) {
        if(a[r1]) tree[node] = 1;
        else tree[node] = 0;
        return;
    }

    ll bam = node*2;
    ll dan = bam + 1;

    ll mid = (r1 + r2) / 2;

    build(bam, r1, mid);
    build(dan, mid+1, r2);

    tree[node] = tree[bam] + tree[dan];
}

void update(ll node, ll r1, ll r2, ll in, ll val) {
    if(r1 > in || r2 < in) return;
    if(r1 == in && r2 == in) {
        tree[node] = val;
        return;
    }

    ll bam = node*2;
    ll dan = bam + 1;

    ll mid = (r1 + r2) / 2;

    update(bam, r1, mid, in, val);
    update(dan, mid+1, r2, in, val);

    tree[node] = tree[bam] + tree[dan];
}

ll query(ll node, ll r1, ll r2, ll j) {
    if(r1 > j) return 0;
    if(r2 <= j) return tree[node];

    ll bam = node*2;
    ll dan = bam + 1;

    ll mid = (r1 + r2) / 2;

    ll p1 = query(bam, r1, mid, j);
    ll p2 = query(dan, mid+1, r2, j);

    return (p1+p2);
}

int main() {
    ll t = 0, n, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0;
    char ch;
    scl1(t);

    for1(i, t) {
        scl2(n, q);

        for1(j, n) scl1(a[j]);

        build(1, 1, SIZE);

        printcase;

        while(q--) {
            scanf(" %c", &ch);

            if(ch == 'a') {
                scl1(p);
                a[++n] = p;
                update(1, 1, SIZE, n, 1);
            }
            else {
                scl1(k);
                c = 0;
                ll st = 1, en = n, mid;

                while(st <= en) {
                    mid = (st + en) / 2;

                    sum = query(1, 1, SIZE, mid);

                    if(sum >= k) {
                        c = mid;
                        en = mid - 1;
                    }
                    else st = mid + 1;
                }

                if(!c) printf("none\n");
                else {
//                    printl(c);
                    printl(a[c]);
                    update(1, 1, SIZE, c, 0);
                }
            }
        }
    }

    return 0;
}

