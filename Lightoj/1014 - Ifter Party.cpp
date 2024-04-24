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
#define SIZE            100005
#define INF             1000000005

int main() {
    ll t, n, m, a, b, c, x, y, z, i, j, k;
    scand(t);

    for1(i, t) {
        ll chilo, ache, khaise;
        vector <ll> v;

        scand(chilo), scand(ache);

        cout << "Case " << i << ":";

        khaise = chilo - ache;

        for(j = 1; j <= sqrt(khaise); j++) {
            if((j*j) == khaise && j > ache) {
                v.pb(j);
            }
            else if((khaise%j) == 0) {
                if(j > ache) {
                    v.pb(j);
                }
                if((khaise/j) > ache) {
                    v.pb(khaise/j);
                }
            }
        }
        asorted(v);

        if(v.empty()) {
            cout << " impossible\n";
            continue;
        }

        for0(j, v.size()) {
            cout << " " << v[j];
        }
        newline;
    }

    return 0;
}

