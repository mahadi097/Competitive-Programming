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
#define SIZE            21
#define INF             1000000005

char maze[SIZE][SIZE];
ll sr, sc, er, ec;
ll r, c;
bool visited[SIZE][SIZE];
bool valid;

void dfs(ll i, ll j);
void clear_data();

int main() {
    ll t, n, m, a, b, x, y, z, i, j, k;
    scand(t);

    while(t--) {
        clear_data();

        scand(r), scand(c);

        n = 0;

        for1(i, r) {
            for1(j, c) {
                cin >> maze[i][j];

                if(maze[i][j] == '.' && (i == r || j == c || i == 1 || j == 1)) {
                    if(n == 0) {
                        sr = i, sc = j;
                    }
                    else if(n == 1) {
                        er = i, ec = j;
                    }
//                    cout << sr << " " << sc << " " << er << " " << ec << endl;
                    n++;
                }
            }
        }

        if(n == 2) {
            dfs(sr, sc);
//            cout << sr << " " << sc << " " << er << " " << ec << endl;

            if(valid) {
                cout << "valid\n";
            }
            else {
                cout << "invalid\n";
            }
        }
        else {
            cout << "invalid\n";
        }
    }

    return 0;
}

void clear_data() {
    valid = false;

    ll i, j;
    for1(i, SIZE-1) {
        for1(j, SIZE-1) {
            visited[i][j] = false;
        }
    }
}

void dfs(ll i, ll j) {
    if(i < 1 || i > r || j < 1 || j > c) {
        return;
    }
    if(maze[i][j] != '.' || visited[i][j]) {
        return;
    }

    visited[i][j] = true;

    if(i == er && j == ec) {
        valid = true;
        return;
    }

    dfs(i+1, j);
    dfs(i-1, j);
    dfs(i, j+1);
    dfs(i, j-1);
}
