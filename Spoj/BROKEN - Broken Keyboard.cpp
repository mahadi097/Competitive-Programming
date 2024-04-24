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

ll dr4[] = {0, 1, -1, 0, 0};
ll dc4[] = {0, 0, 0, 1, -1};

ll gcd(ll x, ll y) {
    if(y == 0) {
        return x;
    }
    return gcd(y, x%y);
}

ll solve(ll diff, string line) {
    ll seg = 0;
    ll i = 0, j = 1, x;

    map <char, ll> m;

    m[line[i]]++;

    x = 1;
    while(x < diff && j < line.size()) {
        if(!m[line[j]]) {
            m[line[j]]++;
            x++;
        }
        else {
            m[line[j]]++;
        }
        j++;
    }

    seg = j - i;
//    cout << seg << " " << j << " " << i << endl;

    while(j < line.size()) {
        if(!m[line[j]]) {
            m[line[i]]--;

            if(!m[line[i]]) {
                m[line[j]]++;
                j++;
            }
            i++;
        }
        else {
            m[line[j]]++;
            j++;
        }

        seg = max(seg, j-i);
//        cout << j-i << " " << j << " " <<  i << endl;
    }
    return seg;
}

int main() {
    ll t, n, m, a, b, x, y, z, i, j, k;
    string line;

    while(scand(m) && m) {
        cin.ignore();

        getline(cin, line);

        n = solve(m, line);

        printd(n);
    }

    return 0;
}

