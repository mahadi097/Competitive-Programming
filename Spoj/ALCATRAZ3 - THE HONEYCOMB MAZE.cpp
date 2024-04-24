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
#define SIZE            105

bool visited[SIZE][SIZE];
char ch[SIZE][SIZE];
ll r, c, k, num = -1;
ll st_row, st_col;
bool s;

void dfs(ll i, ll j);

int main() {
    ll t, n, i, j;
    scand(r), scand(c);
    scand(k);

    scand(st_row), scand(st_col);

    for1(i, r) {
        for1(j, c) {
            cin >> ch[i][j];
        }
    }

    dfs(st_row, st_col);

    printd(num);

    return 0;
}

void dfs(ll i, ll j) {
    if(i < 1 || i > r || j < 1 || j > c) {
        return;
    }
    else if(ch[i][j] != '.') {
        return;
    }
    else if(visited[i][j]) {
        if(i == st_row && j == st_col) {
            if(!s) {
                num++;
                s = true;
//                cout << i << " " << j << endl;
                return;
            }
            return;
        }
        return;
    }

    visited[i][j] = true;
    if(!s) {
        num++;
//        cout << i << " " << j << endl;
    }
//    num++;
//    cout << i << " " << j << endl;

    dfs(i+1, j);
    dfs(i, j+1);
    dfs(i-1, j);
//    dfs(i, j+1);
    dfs(i, j-1);
}
