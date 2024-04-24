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
#define SIZE            200005
#define INF             1000000005
#define F               first
#define S               second
#define FR              ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ms(arr, x)      memset(arr, x, sizeof arr)

ll ans;

void Merge(ll bam[], ll dan[], ll a[], ll nL, ll nR) {
    ll i = 1, j = 1, k = 1;

    while(i <= nL && j <= nR) {
        if(bam[i] <= dan[j]) a[k++] = bam[i++];
        else {
            ans += (nL - i + 1);
            a[k++] = dan[j++];
        }
    }

    while(i <= nL) a[k++] = bam[i++];
    while(j <= nR) a[k++] = dan[j++];
}

void MergeSort(ll a[], ll n) {
    if(n <= 1) return;

    ll mid = n / 2;

    ll nL = mid;
    ll nR = n - mid;

    ll bam[nL+1];
    ll dan[nR+1];

    ll i, j;

    for1(i, mid) bam[i] = a[i];

    for(i = mid+1, j = 1; i <= n; i++, j++) {
        dan[j] = a[i];
    }

    MergeSort(bam, nL);
    MergeSort(dan, nR);

    Merge(bam, dan, a, nL, nR);
}

int main() {
    ll t = 0, n, x, y, z, i, j, k, g, p, q, sum = 0, c = 0;
    scl1(t);

    while(t--) {
        scl1(n);

        ans = 0;

        ll a[n+1];
        for1(i, n) scl1(a[i]);

        MergeSort(a, n);

        printl(ans);
    }

    return 0;
}

