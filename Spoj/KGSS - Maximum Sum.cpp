#include <bits/stdc++.h>
using namespace std;


//TEMPLATE
#define pb              push_back
#define mp              make_pair
#define ll              long long
#define ld              long double
//#define pi              3.1415926536
#define pi              acos(-1)
//#define mod             1000000007
#define newline         printf("\n")
#define printminusone   printf("-1\n")
#define scl1(n)         scanf("%lld", &n)
#define scl2(a, b)      scanf("%lld %lld", &a, &b)
#define scl3(a, b, c)   scanf("%lld %lld %lld", &a, &b, &c)
#define printl(n)       printf("%lld\n", n)
#define ssl1(str)       scanf(" %[^\n]", str)
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


ll a[SIZE];
ll mx1[SIZE*4], mx2[SIZE*4]; ///CONTAIN INDEX OF MAXIMUM AND SECOND MAXIMUM

void build(ll node, ll r1, ll r2) {
    if(r1 == r2) {
        mx1[node] = r1;
        return;
    }

    ll bam = node*2;
    ll dan = bam + 1;

    ll mid = (r1 + r2) / 2;

    build(bam, r1, mid);
    build(dan, mid+1, r2);


    if(a[mx1[bam]] >= a[mx1[dan]]) {
        mx1[node] = mx1[bam];
        mx2[node] = mx1[dan];
        if(a[mx2[bam]] >= a[mx1[dan]]) mx2[node] = mx2[bam];
    }
    else {
        mx1[node] = mx1[dan];
        mx2[node] = mx1[bam];
        if(a[mx2[dan]] >= a[mx1[bam]]) mx2[node] = mx2[dan];
    }
}

void update(ll node, ll r1, ll r2, ll in, ll val) {
    ll bam = node*2;
    ll dan = bam + 1;

    if(r1 > in || r2 < in) return;
    if(r1 == in && r2 == in) {
        a[r1] = val;
        return;
    }

    ll mid = (r1 + r2) / 2;

    update(bam, r1, mid, in, val);
    update(dan, mid+1, r2, in, val);

    if(a[mx1[bam]] >= a[mx1[dan]]) {
        mx1[node] = mx1[bam];
        mx2[node] = mx1[dan];
        if(a[mx2[bam]] >= a[mx1[dan]]) mx2[node] = mx2[bam];
    }
    else {
        mx1[node] = mx1[dan];
        mx2[node] = mx1[bam];
        if(a[mx2[dan]] >= a[mx1[bam]]) mx2[node] = mx2[dan];
    }
}

pii query(ll node, ll r1, ll r2, ll i, ll j) {
    ll bam = node*2;
    ll dan = bam + 1;

    if(r1 > j || r2 < i) return mp(0, 0);
    if(r1 >= i && r2 <= j) return mp(mx1[node], mx2[node]);

    ll mid = (r1 + r2) / 2;

    pii res;
    pii p1 = query(bam, r1, mid, i, j);
    pii p2 = query(dan, mid+1, r2, i, j);

    if(a[p1.F] >= a[p2.F]) {
        res.F = p1.F;
        res.S = p2.F;
        if(a[p1.S] >= a[p2.F]) res.S = p1.S;
    }
    else {
        res.F = p2.F;
        res.S = p1.F;
        if(a[p2.S] >= a[p1.F]) res.S = p2.S;
    }

    return res;
}

int main() {
    ll t = 0, n, x, y, z, i, j, k, g, p, q, sum = 0, c = 0;
    char type;
    scl1(n);

    for1(i, n) scl1(a[i]);

    build(1, 1, n);

    scl1(q);

    while(q--) {
        cin >> type;
        scl2(x, y);

        if(type == 'U') update(1, 1, n, x, y);
        else {
            pii ans = query(1, 1, n, x, y);

//            cout << ans.F << " " << ans.S << endl;
            sum = a[ans.F] + a[ans.S];

            printl(sum);
        }
    }

    return 0;
}

