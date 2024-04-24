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
#define SIZE            1005

ll r, c, row;
ll grid[SIZE][SIZE];
ll row_num, total_bomb, bomb;
ll st_row, st_col, en_row, en_col;
ll total_time;
ll visited[SIZE][SIZE];
ll dis[SIZE][SIZE];

ll dr[5] = {0, 1, -1, 0, 0};
ll dc[5] = {0, 0, 0, 1, -1};

bool valid(ll i, ll j);
ll bfs();

int main() {
    ll t, n, i, j, k;

    while((cin >> r >> c) && r != 0 && c != 0) {
        for0(i, SIZE) {
            for0(j, SIZE) {
                visited[i][j] = 0;
                dis[i][j] = 0;
                grid[i][j] = 0;
            }
        }

        scand(row);

        for1(i, row) {
            scand(row_num);
            scand(total_bomb);

            for1(j, total_bomb) {
                scand(bomb);
                grid[row_num][bomb] = 1;
            }
        }

        scand(st_row), scand(st_col);
        scand(en_row), scand(en_col);

        total_time = bfs();
        printd(total_time);
    }

    return 0;
}

bool valid(ll i, ll j) {
    if(i >= 0 && i < r && j >= 0 && j < c) {
        return true;
    }
    else {
        return false;
    }
}

ll bfs() {
    visited[st_row][st_col] = true;
    dis[st_row][st_col] = 0;

    queue <paired> q;
    q.push(mp(st_row, st_col));

    paired p;

    ll row_in, col_in, i;

    while(!q.empty()) {
        p = q.front();
        q.pop();

        for1(i, 4) {
            row_in = p.first + dr[i];
            col_in = p.second + dc[i];

            if(valid(row_in, col_in)) {
                if(!grid[row_in][col_in] && !visited[row_in][col_in]) {
                    visited[row_in][col_in] = true;

                    dis[row_in][col_in] = dis[p.first][p.second] + 1;
                    q.push(mp(row_in, col_in));

                    if(row_in == en_row && col_in == en_col) {
                        return dis[row_in][col_in];
                    }
                }
            }
        }
    }
}
