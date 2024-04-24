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
#define scl1(n)         scanf("%lld", &n)
#define scl2(a, b)      scanf("%lld %lld", &a, &b)
#define printl(n)       printf("%lld\n", n)
#define scd1(n)         scanf("%lf", &n)
#define scd2(a, b)      scanf("%lf %lf", &a, &b)
#define printd(n)       printf("%lf\n", n)
#define reversed(s)     reverse(s.begin(), s.end())
#define asorted(s)      sort(s.begin(), s.end())
#define dsorted(s)      sort(s.begin(), s.end(), descending_func)
#define for0(i, n)      for (i = 0; i < n; i++)
#define for1(i, n)      for (i = 1; i <= n; i++)
#define paired          pair <ll, ll>
#define pii             pair <ll, paired>
#define SIZE            100005
#define INF             1000000005

string str;
char ch[35];
ll r, len;
bool taken[35];

void backtrack(ll idx, ll pos) {
    if(idx == r) {
        ll i;
        for0(i, r) {
            printf("%c", ch[i]);
        }
        newline;
        return;
    }

    ll i;
    for(i = pos; i < len; i++) {
        if(!taken[i]) {
            taken[i] = 1;
            ch[idx] = str[i];

            backtrack(idx+1, i+1);
            taken[i] = 0;
        }
        while(str[i] == str[i+1]) i++;
    }
}

int main() {
    ll t = 0, n, x, y, z, i, j, k, g, q, ans = 0, sum = 0;

    while(cin >> str >> r) {

        asorted(str);

        len = str.size();
        backtrack(0, 0);
    }


    return 0;
}

