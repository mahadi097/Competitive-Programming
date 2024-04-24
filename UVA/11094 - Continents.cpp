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

string str[SIZE];
ll r, c, x, y;
bool visited[SIZE][SIZE];
ll biggest, num;
char land;

void dfs(ll i, ll j);

int main() {
    ll t, n, i, j, k;

    while((scanf("%lld %lld", &r, &c)) == 2) {
        scand(r), scand(c);
        for0(i, SIZE) {
            for0(j, SIZE) {
                visited[i][j] = false;
            }
        }

        for0(i, r) {
            cin >> str[i];
        }

        scand(x), scand(y);
        land = str[x][y];

        biggest = 0;

        dfs(x, y);

        for0(i, r) {
            for0(j, c) {
                num = 0;

                if(str[i][j] == land) {
                    dfs(i, j);
                }
                biggest = max(biggest, num);
            }
        }

        printd(biggest);

    }

    return 0;
}

void dfs(ll i, ll j) {
    if(j < 0) {
        j = c - 1;
    }
    if(j >= c) {
        j = 0;
    }
    if(i < 0 || i >= r) {
        return;
    }
    if(visited[i][j] || str[i][j] != land) {
        return;
    }

    visited[i][j] = true;
//    cout << i << " " << j << endl;
    num++;

    dfs(i+1, j);
    dfs(i-1, j);
    dfs(i, j+1);
    dfs(i, j-1);
}
