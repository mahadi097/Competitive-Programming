#include <bits/stdc++.h>
using namespace std;


//TEMPLATE
#define pb              push_back
#define mp              make_pair
#define ll              long long
#define ld              long double
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
#define printld(n)      printf("%Lf\n", n)
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

string st, en;
map <string, bool> fb, vis;
map <string, ll> dis;

ll bfs() {
    vis[st] = 1;
    dis[st] = 0;

    queue <string> q;
    q.push(st);

    while(!q.empty()) {
        string u = q.front();
        q.pop();

        ll i, j;
        for0(i, 3) {
            string s1, s2;
            char c = u[i], c1, c2;
            if(c == 'a') {
                c1 = 'z';
                c2 = 'b';
            }
            else if(c == 'z') {
                c1 = 'y';
                c2 = 'a';
            }
            else {
                c1 = --c;
                c2 = ++c;
                c2++;
//                cout << c1 << " " << c2 << endl;
            }

            for0(j, 3) {
                if(j == i) s1 += c1;
                else s1 += u[j];
            }
            for0(j, 3) {
                if(j == i) s2 += c2;
                else s2 += u[j];
            }

//            cout << s1 << " " << s2 << endl;

            if(!vis[s1] && !fb[s1]) {
                vis[s1] = 1;
                dis[s1] = dis[u] + 1;
                q.push(s1);
            }
            if(!vis[s2] && !fb[s2]) {
                vis[s2] = 1;
                dis[s2] = dis[u] + 1;
                q.push(s2);
            }
        }
    }

    if(vis[en]) return dis[en];
    return -1;
}

int main() {
    ll t = 0, n, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0;
    scl1(t);

    for1(i, t) {
        cin >> st >> en;

        scl1(n);

        fb.clear();
        vis.clear();

        string s, s1, s2, s3;

        for1(j, n) {
            cin >> s1 >> s2 >> s3;

            for0(x, s1.size()) {
                for0(y, s2.size()) {
                    for0(z, s3.size()) {
                        s = s1[x];
                        s += s2[y];
                        s += s3[z];
                        fb[s] = 1;
                    }
                }
            }
        }

        printcase;

        if(fb[st] || fb[en]) {
            printminusone;
            continue;
        }

        ans = bfs();
        printl(ans);
    }

    return 0;
}

