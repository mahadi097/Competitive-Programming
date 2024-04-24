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
#define SIZE            50
#define INF             1000000005

ll dr4[] = {0, 1, -1, 0, 0};
ll dc4[] = {0, 0, 0, 1, -1};

vector <char> road[SIZE];
map <char, bool> visited;

void clear_data();
string bfs(char c1, char c2);

int main() {
    ll t, n, m, a, b, x, y, z, i, j, k;
    scand(t);

    while(t--) {
        clear_data();

        scand(m), scand(n);

        string s1, s2, path;
        cin.ignore();

        while(m--) {
            cin >> s1 >> s2;

            road[s1[0]].pb(s2[0]);
            road[s2[0]].pb(s1[0]);
        }

        cin.ignore();
        while(n--) {
            visited.clear();

            cin >> s1 >> s2;

            path = bfs(s1[0], s2[0]);

            cout << path << endl;
        }

        if(t) {
            newline;
        }
    }

    return 0;
}

void clear_data() {
    char c;
    visited.clear();
    for(c = 'A'; c <= 'Z'; c++) {
        road[c].clear();
    }
}

string bfs(char c1, char c2) {
    queue <string> q;

    string u, temp;
    char v, c;
    ll i;

    u += c1;
    q.push(u);
    visited[c1] = true;

    while(!q.empty()) {
        u = q.front();
        q.pop();

        c = u[u.size()-1];

        for0(i, road[c].size()) {
            v = road[c][i];

            if(!visited[v]) {
                visited[v] = true;

                temp = u;
                temp += v;

                q.push(temp);

                if(v == c2) {
                    return temp;
                }
            }
        }
    }
}
