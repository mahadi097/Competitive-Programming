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
#define SIZE            30

vector <ll> adj_list[SIZE];
bool visited[SIZE];
ll total;

void dfs(ll starting_node);

int main() {
    ll t, n, i, j, k;
    char ch, c1, c2;
    string str;
    ll n1, n2;

    scand(t);

    for1(i, t) {
        memset(adj_list, 0, sizeof(adj_list));
        memset(visited, false, sizeof(visited));
        total = 0;

        cin >> ch;

        ll node = (ch - 'A') + 1;

        cin.ignore();

        while(getline(cin, str) && str != "") {

            n1 = (str[0] - 'A') + 1;
            n2 = (str[1] - 'A') + 1;

            adj_list[n1].pb(n2);
            adj_list[n2].pb(n1);
        }

        for1(j, node) {
            if(!visited[j]) {
                total++;
                dfs(j);
            }
        }
        printd(total);

        if(i != t) {
            newline;
        }
    }

    return 0;
}

void dfs(ll n) {
    if(visited[n]) {
        return;
    }

    visited[n] = true;

    ll i;

    for0(i, adj_list[n].size()) {
        dfs(adj_list[n][i]);
    }
}
