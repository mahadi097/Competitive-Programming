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
#define SIZE            30005
#define INF             1000000005
#define F               first
#define S               second
#define FR              ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ms(arr, x)      memset(arr, x, sizeof arr)

ll a[SIZE];
struct info {
    ll sum, min_sum;
} tree[SIZE*4];

void build(ll node, ll r1, ll r2) {
    if(r1 == r2) {
        tree[node].sum = tree[node].min_sum = a[r1];
        return;
    }

    ll bam = node*2;
    ll dan = node*2 + 1;

    ll mid = (r1 + r2) / 2;

    build(bam, r1, mid);
    build(dan, mid+1, r2);

    tree[node].sum = tree[bam].sum + tree[dan].sum;
    tree[node].min_sum = min(tree[bam].min_sum, tree[bam].sum+tree[dan].min_sum);
}

void update(ll node, ll r1, ll r2, ll in) {
    if(r1 > in || r2 < in) return;
    if(r1 == in && r2 == in) {
        tree[node].sum *= (-1);
        tree[node].min_sum *= (-1);
        return;
    }

    ll bam = node*2;
    ll dan = node*2 + 1;

    ll mid = (r1 + r2) / 2;

    update(bam, r1, mid, in);
    update(dan, mid+1, r2, in);

    tree[node].sum = tree[bam].sum + tree[dan].sum;
    tree[node].min_sum = min(tree[bam].min_sum, tree[bam].sum+tree[dan].min_sum);
}

int main() {
    ll t = 0, n, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0;
    string s;

    while(scl1(n) == 1) {
        cin >> s;

        for0(i, n) {
            if(s[i] == '(') a[i+1] = 1;
            else a[i+1] = -1;
        }

        build(1, 1, n);

        scl1(q);

        printf("Test %lld:\n", ++t);

        while(q--) {
            scl1(k);

            if(!k) {
                if(!tree[1].sum && !tree[1].min_sum) cout << "YES\n";
                else cout << "NO\n";
            }
            else update(1, 1, n, k);
        }
    }

    return 0;
}

