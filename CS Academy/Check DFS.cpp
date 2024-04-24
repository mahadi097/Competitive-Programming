#include <bits/stdc++.h>
using namespace std;


//TEMPLATE
#define pb              push_back
#define mp              make_pair
#define ll              long long int
#define pi              3.1415926536
#define mod             1000000007
#define newline         printf("\n")
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
#define SIZE            100005

vector <ll> adj_list[SIZE];
bool visited[SIZE];
ll node, edge;
bool check = true;
vector<ll> p;
ll j = 1;

void dfs(ll n);

int main() {
    scand(node), scand(edge);

    ll n1, n2, i;

    for0(i, node) {
        scand(n1);
        p.pb(n1);
    }

    for0(i, edge) {
        scand(n1), scand(n2);

        adj_list[n1].pb(n2);
        adj_list[n2].pb(n1);
    }

    dfs(1);

    if(check) {
        cout << "1\n";
    }
    else {
        cout << "0\n";
    }

    return 0;
}

void dfs(ll n) {
    ll prev_node;

    if(visited[n]) {
        if(n != prev_node) {
            check = false;
            return;
        }
    }

    visited[n] = true;

    ll i, status = 0;

    for0(i, adj_list[n].size()) {

        if(adj_list[n][i] == p[j]) {
            if(j == node-1) {
                check = true;
                return;
            }
            cout << p[j] << "\n";
            prev_node = n;

            status = 1;
            j++;

            dfs(adj_list[n][i]);
        }
    }

    if(status == 0) {
        if(n == prev_node) {
            check = false;
        }
        else {
            dfs(prev_node);
        }
    }
}
