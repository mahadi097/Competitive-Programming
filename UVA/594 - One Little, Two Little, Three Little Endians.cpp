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
#define scan(n)        scanf("%d", &n)
#define print(n)       printf("%d\n", n)
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

ll dr4[] = {0, 1, -1, 0, 0};
ll dc4[] = {0, 0, 0, 1, -1};

ll gcd(ll x, ll y) {
    if(y == 0) {
        return x;
    }
    return gcd(y, x%y);
}

int get_reverse_bit(ll n) {
    int b, c, d, i, j, ans = 0;
    bool a;
    string s1, s2, s3, s4, s;

    for(i = 7; i >= 0; i--) {
        a = n & (1 << i);
        s1 += a + '0';
    }
    for(i = 15; i >= 8; i--) {
        a = n & (1 << i);
        s2 += a + '0';
    }
    for(i = 23; i >= 16; i--) {
        a = n & (1 << i);
        s3 += a + '0';
    }
    for(i = 31; i >= 24; i--) {
        a = n & (1 << i);
        s4 += a + '0';
    }
    s = s1 + s2 + s3 + s4;

    c = 30;
    for0(i, s.size()) {
        b = s[i] - '0';
        if(i == s.size()-1) {
            ans += b;
            continue;
        }
        ans += (b * (2 << c));
        c--;
//        cout << b << " " << (b * (2 << c)) << endl;
    }
    return ans;
}

int main() {
    int t, n, m, a, b, x, y, z, i, j, k;

    while(scan(n) == 1) {
        m = get_reverse_bit(n);

        printf("%d converts to %d\n", n, m);
    }

    return 0;
}

