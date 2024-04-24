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
#define SIZE            10000
#define INF             1000000005

ll n1, n2;
bool status[SIZE];
ll dis[SIZE];
bool vis[SIZE];

void sieve();
ll bfs(ll n);

int main() {
    sieve();

    ll t, n, m, a, b, c, x, y, z, i, j, k;
    scand(t);

    while(t--) {
        scand(n1), scand(n2);

        bfs(n1);

        if(dis[n2] == 0 && n1 != n2) {
            cout << "Impossible\n";
        }
        else {
            printd(dis[n2]);
        }

        memset(dis, 0, sizeof dis);
        memset(vis, false, sizeof vis);
    }

    return 0;
}

void sieve() {
    ll i, j;

    status[0] = 1;
    status[1] = 1;
    status[2] = 0;

    for(i = 2; i <= sqrt(SIZE); i++) {
        if(!status[i]) {
            for(j = i*i; j < SIZE; j += i) {
                status[j] = 1;
            }
        }
    }
}

ll bfs(ll n) {
    queue <ll> q;

    dis[n] = 0;
    vis[n] = true;

    q.push(n);

    ll u, v, i, j;

    while(!q.empty()) {
        u = q.front();
        q.pop();

        ll d4 = u % 10;
        ll d3 = (u / 10) % 10;
        ll d2 = (u / 100) % 10;
        ll d1 = u / 1000;
        ll con_num;

        for(i = 0; i <= 9; i++) { /**REPLACING 4TH DIGIT**/
            con_num = (d1 * 1000) + (d2 * 100) + (d3 * 10) + i;

            if(!status[con_num] && !vis[con_num]) {
                vis[con_num] = true;
                dis[con_num] = dis[u] + 1;

                q.push(con_num);

                if(con_num == n2) {
                    return dis[con_num];
                }
            }
        }

        for(i = 0; i <= 9; i++) { /**REPLACING 3RD DIGIT**/
            con_num = (d1 * 1000) + (d2 * 100) + (i * 10) + d4;

            if(!status[con_num] && !vis[con_num]) {
                vis[con_num] = true;
                dis[con_num] = dis[u] + 1;

                q.push(con_num);

                if(con_num == n2) {
                    return dis[con_num];
                }
            }
        }

        for(i = 0; i <= 9; i++) { /**REPLACING 2ND   DIGIT**/
            con_num = (d1 * 1000) + (i * 100) + (d3 * 10) + d4;

            if(!status[con_num] && !vis[con_num]) {
                vis[con_num] = true;
                dis[con_num] = dis[u] + 1;

                q.push(con_num);

                if(con_num == n2) {
                    return dis[con_num];
                }
            }
        }

        for(i = 1; i <= 9; i++) { /**REPLACING 1ST   DIGIT, AS THE 1ST DIGIT CANNOT START WITH LEADING ZERO, WE START FROM 1**/
            con_num = (i * 1000) + (d2 * 100) + (d3 * 10) + d4;

            if(!status[con_num] && !vis[con_num]) {
                vis[con_num] = true;
                dis[con_num] = dis[u] + 1;

                q.push(con_num);

                if(con_num == n2) {
                    return dis[con_num];
                }
            }
        }
    }

}
