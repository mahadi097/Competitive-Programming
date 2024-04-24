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
#define printcase       printf("Case %lld: ", i)
#define reversed(s)     reverse(s.begin(), s.end())
#define asorted(s)      sort(s.begin(), s.end())
#define dsorted(s)      sort(s.begin(), s.end(), cmp)
#define for0(i, n)      for (i = 0; i < n; i++)
#define for1(i, n)      for (i = 1; i <= n; i++)
#define pii             pair <ll, ll>
#define piii            pair <ll, pii>
#define SIZE            100005
#define INF             1000000005
#define F               first
#define S               second
#define FR              ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ms(arr, x)      memset(arr, x, sizeof arr)
#define bitcount(n)     __builtin_popcountll(n)

ll a[SIZE];
ll tree[SIZE*4];
string ans;

void build(ll node, ll r1, ll r2) {
    if(r1 == r2) {
        if(a[r1] > 0) tree[node] = 1;
        else if(a[r1] < 0) tree[node] = -1;
        else tree[node] = 0;
        return;
    }

    ll mid = (r1 + r2) / 2;

    ll bam = node*2;
    ll dan = bam + 1;

    build(bam, r1, mid);
    build(dan, mid+1, r2);

    tree[node] = tree[bam] * tree[dan];
}

void update(ll node, ll r1, ll r2, ll in, ll val) {
    if(r1 > in || r2 < in) return;
    if(r1 == in && r2 == in) {
        a[r1] = val;
        if(a[r1] > 0) tree[node] = 1;
        else if(a[r1] < 0) tree[node] = -1;
        else tree[node] = 0;
        return;
    }

    ll mid = (r1 + r2) / 2;

    ll bam = node*2;
    ll dan = bam + 1;

    update(bam, r1, mid, in, val);
    update(dan, mid+1, r2, in, val);

    tree[node] = tree[bam] * tree[dan];
}

ll query(ll node, ll r1, ll r2, ll i, ll j) {
    if(r1 > j || r2 < i) return 1;
    if(r1 >= i && r2 <= j) return tree[node];

    ll mid = (r1 + r2) / 2;

    ll bam = node*2;
    ll dan = bam + 1;

    ll p1 = query(bam, r1, mid, i, j);
    ll p2 = query(dan, mid+1, r2, i, j);

    return (p1*p2);
}

int main() {
    ll t = 0, n, x, y, z, i, j, k, g, p, q, sum = 0, c = 0;
    char ch;

    while(scl2(n, q) == 2) {
        for1(i, n) scl1(a[i]);
        ans.clear();

        build(1, 1, n);

        while(q--) {
            scanf(" %c", &ch);
            scl2(x, y);

            if(ch == 'C') update(1, 1, n, x, y);
            else {
                t = query(1, 1, n, x, y);
                if(t == 1) ans += '+';
                else if(t == -1) ans += '-';
                else ans += '0';
            }
        }
        cout << ans << "\n";
    }

    return 0;
}

