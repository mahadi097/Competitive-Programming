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
#define SIZE            25

char ch[SIZE][SIZE];
ll dr[] = {1, -1, 0, 0};
ll dc[] = {0, 0, 1, -1};
bool visited[SIZE][SIZE];
ll dis[SIZE][SIZE];
ll r, c, min_time;
ll r1, r2, r3, c1, c2, c3;

bool valid(ll i, ll j);
ll bfs(ll st_row, ll st_col);

int main() {
    ll t, n, i, j, k;
    scand(t);

    for1(k, t) {
        min_time = 0;

        memset(visited, false, sizeof(visited));
        memset(dis, 0, sizeof(dis));

        scand(r), scand(c);

        for0(i, r) {
            for0(j, c) {
                cin >> ch[i][j];
                if(ch[i][j] == 'a') {
                    r1 = i, c1 = j;
                }
                else if(ch[i][j] == 'b') {
                    r2 = i, c2 = j;
                }
                else if(ch[i][j] == 'c') {
                    r3 = i, c3 = j;
                }
            }
        }

        ll a_time = bfs(r1, c1);
        memset(visited, false, sizeof(visited));
        memset(dis, 0, sizeof(dis));
        min_time = max(min_time, a_time);

        ll b_time = bfs(r2, c2);
        memset(visited, false, sizeof(visited));
        memset(dis, 0, sizeof(dis));
        min_time = max(min_time, b_time);

        ll c_time = bfs(r3, c3);
        memset(visited, false, sizeof(visited));
        memset(dis, 0, sizeof(dis));
        min_time = max(min_time, c_time);

        cout << "Case " << k << ": " << min_time << "\n";
    }

    return 0;
}

bool valid(ll i, ll j) {
    return (i >= 0 && i < r && j >= 0 && j < c);
}

ll bfs(ll st_row, ll st_col) {
    visited[st_row][st_col] = true;
    dis[st_row][st_col] = 0;

    queue <paired> q;
    q.push(mp(st_row, st_col));

    paired p;
    ll i, j, row_in, col_in;

    while(!q.empty()) {
        p = q.front();
        q.pop();

        for0(i, 4) {
            row_in = p.first + dr[i];
            col_in = p.second + dc[i];

            if(valid(row_in, col_in)) {
                if(!visited[row_in][col_in] && ch[row_in][col_in] != '#' && ch[row_in][col_in] != 'm') {
                    visited[row_in][col_in] = true;

                    dis[row_in][col_in] = dis[p.first][p.second] + 1;
                    q.push(mp(row_in, col_in));

                    if(ch[row_in][col_in] == 'h') {
                        return dis[row_in][col_in];
                    }
                }
            }
        }
    }
}
